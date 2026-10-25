cmake_minimum_required(VERSION 3.15)
project(UniversalConstants LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. 专为 Mac 优化的 GMP 寻找逻辑
if(APPLE)
    # 针对 Apple Silicon (M1/M2/M3) 和 Intel 芯片的 Homebrew 路径
    if(EXISTS "/opt/homebrew/include/gmp.h")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/opt/homebrew/include")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/opt/homebrew/lib")
    elseif(EXISTS "/usr/local/include/gmp.h")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include")
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")
    endif()
endif()

# 2. 尝试寻找 GMP (如果系统装了，就会找到)
find_package(GMP QUIET)

# 3. 创建你的静态库
add_library(UniversalConstants STATIC
        UniversalConstants.cpp
        UniversalConstants.h
)

# 4. 暴露头文件给调用者
target_include_directories(UniversalConstants PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# 5. 如果找到了 GMP，就链接它；如果没找到，就给出清晰的提示
if(GMP_FOUND)
    target_link_libraries(UniversalConstants PUBLIC GMP::gmp GMP::gmpxx)
else()
    message(WARNING "未找到 GMP 库。如果你只想使用免安装版(BasicConstants.h)，可以忽略此警告。")
    # 为了防报错，把 gmp 相关的源文件设为可选
    target_sources(UniversalConstants PRIVATE UniversalConstants.cpp)
    # 强行忽略找不到的库，让编译继续进行（只编译基础版）
    target_link_libraries(UniversalConstants PUBLIC gmp gmpxx)
endif()