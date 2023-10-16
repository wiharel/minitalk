SRCS = src/ft_arg_printf.c src/ft_atoi.c src/ft_bzero.c \
			 src/ft_calloc.c src/ft_hexa.c src/ft_isalnum.c \
			 src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c \
			 src/ft_isprint.c src/ft_itoa.c src/ft_itoa_unsigned.c \
			 src/ft_lstadd_back.c src/ft_lstadd_front.c src/ft_lstclear.c \
			 src/ft_lstdelone.c src/ft_lstiter.c src/ft_lstlast.c \
			 src/ft_lstmap.c src/ft_lstnew.c src/ft_lstsize.c src/ft_memchr.c \
			 src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c \
			 src/ft_printf.c src/ft_print_hexa_number.c src/ft_print_number.c \
			 src/ft_print_one_c.c src/ft_print_percent.c src/ft_print_string_c.c \
			 src/ft_print_unsigned_number.c src/ft_putchar_fd.c src/ft_putendl_fd.c \
			 src/ft_putnbr_fd.c src/ft_putstr.c src/ft_putstr_fd.c src/ft_split.c \
			 src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c \
			 src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c \
			 src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c \
			 src/ft_substr.c src/ft_tolower.c src/ft_toupper.c

SERVER = server.c \
	 ft_utils.c \

SERVER_BONUS = server_bonus.c \
	       ft_utils_bonus.c \

CLIENT = client.c \

CLIENT_BONUS = client_bonus.c \
	       ft_utils.c \

$(OBJS) : ./includes/libft.h

OBJS = $(SRCS:.c=.o)
OBJS_SERVER = $(SERVER:.c=.o)
OBJS_CLIENT = $(CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(CLIENT_BONUS:.c=.o)

CC = gcc
AR = ar crs
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

.c:.o
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(AR) $(NAME) $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(SERVER) $(NAME) -o ./server
	@$(CC) $(CFLAGS) $(CLIENT) $(NAME) -o ./client

all:	$(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
	@$(RM) $(NAME) ./server ./client

re: fclean all $(NAME)

bonus: $(OBJS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(AR) $(NAME) $(OBJS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(NAME) -o ./server
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(NAME) -o ./client


.PHONY : minitalk all clean fclean re bonus
