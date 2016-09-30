cmake_minimum_required(VERSION 3.6)
project(metadata)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Util.h Variable.cpp Variable.h ClassInfo.cpp ClassInfo.h CallableInfo.cpp CallableInfo.h MethodInfo.h CallbackInfo.h PropertyInfo.h ConstructInfo.h MetaType.cpp MetaType.h)
add_executable(metadata ${SOURCE_FILES})