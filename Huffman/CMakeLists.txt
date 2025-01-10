cmake_minimum_required(VERSION 3.0)

project(dev)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory(src SRC_LIST)

include_directories(include)
set(SRC_LIST src/main.cpp
             src/Config.cpp
             src/Node.cpp
             src/Huffman.cpp
             src/File.cpp
             src/HuffmanCode.cpp)
add_executable(main ${SRC_LIST})