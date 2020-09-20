cmake_minimum_required(VERSION 3.10)

project(weldq6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find_package(weld)
find_package( ZLIB REQUIRED)
# Search OpenSSL
#find_package(OpenSSL REQUIRED)
set(CURSES_NEED_NCURSES "TRUE")
set(CURSES_NEED_WIDE "TRUE")

find_package(Curses REQUIRED)



#  export LDFLAGS="-L/usr/local/opt/openssl@1.1/lib"
#  export CPPFLAGS="-I/usr/local/opt/openssl@1.1/include"
#set(OPENSSL_INCLUDE_DIR /usr/local/opt/openssl@1.1/include)
#set(OPENSSL_LIBRARIES /usr/local/opt/openssl@1.1/lib/libssl.a)
set(CMAKE_EXE_LINKER_FLAGS "-framework Security")
set(WELD_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/../../../../target/release/libweld.a)
add_executable(weldq6 main.cc)
target_link_libraries(weldq6 ${WELD_LIBRARY} /usr/local/opt/ncurses/lib/libncurses.a ${ZLIB_LIBRARIES})