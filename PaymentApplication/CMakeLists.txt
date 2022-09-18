cmake_minimum_required(VERSION 3.20.5)
project(pay)

set(SRC "main.c;Card/card.c;Terminal/terminal.c;Server/server.c;Application/app.c")
# set(Inc "Card/;Terminal/;Server/;Application/")

add_executable(pay ${SRC})
target_include_directories(pay PUBLIC 
                            Card/
                            Terminal/
                            Server/
                            Application/
)

