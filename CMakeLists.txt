cmake_minimum_required(VERSION 3.11)

project(Sorts-v1 CXX)

set(CMAKE_CXX_STANDARD 23)

# Специфичные настройки для компилятора Visual Studio
if(MSVC)
    # Генерируем статическую заглушку для динамических библиотек
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    # Включаем высокий уровень предупреждений
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()


# Объявляем библиотеку
add_library(Sorts-v1 SHARED "include/bubble_sort.cpp" "include/comb_sort.cpp" "include/shell_sort" "include/generates.cpp")
target_include_directories(Sorts-v1 PUBLIC "include")

add_executable(Sorts-v1-main  "app/main.cpp" )
target_link_libraries(Sorts-v1-main Sorts-v1)