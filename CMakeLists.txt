cmake_minimum_required(VERSION 3.15)
project(lab_2_OOP LANGUAGES CXX)

add_library(lab_2_lib
    src/point.cpp
    src/figure.cpp
    src/array.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
    src/pentagon.cpp
)

# Публичные заголовки
target_include_directories(lab_2_lib PUBLIC include)

target_compile_features(lab_2_lib PUBLIC cxx_std_17)

add_executable(lab_2 src/main.cpp)
target_link_libraries(lab_2 PRIVATE lab_2_lib)
target_compile_features(lab_2 PRIVATE cxx_std_17)

# Для Windows/MSVC отключим предупреждения про небезопасные CRT-функции
if (MSVC)
    target_compile_definitions(lab_2_lib PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_compile_definitions(lab_2 PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# ---------------- Tests (GoogleTest) ----------------
include(CTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
# Для MSVC отключим предупреждения в GTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(lab_2_tests
    tests/test_trapezoid.cpp
    tests/test_rhombus.cpp
    tests/test_pentagon.cpp
    tests/test_array.cpp
)
target_link_libraries(lab_2_tests PRIVATE lab_2_lib GTest::gtest_main)
target_compile_features(lab_2_tests PRIVATE cxx_std_17)
target_include_directories(lab_2_tests PRIVATE include)

if (MSVC)
    target_compile_definitions(lab_2_tests PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()

# Регистрируем каждый GoogleTest-кейс как отдельный CTest-тест
include(GoogleTest)
gtest_discover_tests(lab_2_tests
    DISCOVERY_TIMEOUT 60
)
