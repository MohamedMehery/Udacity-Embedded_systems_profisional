cmake_minimum_required(VERSION 3.20.5)
project(pay)

set(SRC "main.c;card.c;terminal.c;server.c")
set(Inc "main.h;card.h;terminal.h;server.h")

add_executable(pay ${SRC})
target_include_directories(pay PUBLIC ${Inc})

