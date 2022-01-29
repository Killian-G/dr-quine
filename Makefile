NAME := ft_nm

ifdef COUNT
T := $(shell $(MAKE) $(NAME) --no-print-directory -nrR PROGRESS="COUNTTHIS" | grep -c "COUNTTHIS")
N := x
C = $(words $N)$(eval N := x $N)
PROGRESS = [`expr $C '*' 100 / $T`%%]
endif

PWD = $(shell pwd)
OS = $(shell uname)

# Sources

SRCS =	quine-1.c	\
		quine-2.c	\
		Colleen.c	\
		Grace.c		\
		Sully.c

# Display

HIDE_CURSOR := \e[?25l
SHOW_CURSOR := \e[?25h
CURSOR_LEFT := \e[1000D
ERASE_ENDLINE := \e[K
ERASE_FULLLINE := \e[2K

# Global variable (compiler / shell)

CC = clang
RAN = ar rcs
RM = /bin/rm -rf
PRINT = printf
CFLAGS = -Wall -Wextra -Werror

# Flags

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

# -fsanitize=address -fsanitize=undefined

ifeq ($(FS), 1)
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
endif

ifneq ($(OPTI), 0)
	CFLAGS += -O3
endif

# Rules

all: $(SRCS)

$(SRCS):
	$(CC) $@ -o $(subst .c,,$@)

.PHONY: all clean clean2 fclean re libmake libclean libfclean sdl2_brew sdl2_prebuild sdl2_postbuild sdl2_build debug show_cursor test $(SRCS)

#asd