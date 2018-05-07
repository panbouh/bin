TEMP_N		=	temp
TEMP_S		=	$(WAY)temp.c
TEMP_O		=	$(TEMP_S:.c=.o)

WAY	=	src/

HEADPATH	=	./includes/

LIBFT		=	libft
LIBFTPATH	=	./libft/
HEADLIBFTPATH	=	$(LIBFTPATH)includes/

CFLAGS	=	-I $(HEADLIBFTPATH) -I $(HEADPATH) -Wall -Wextra -Werror
CCLIBFT		=	-L libft/ -lft

$(TEMP_N)	: $(LIBFT) $(TEMP_O)
		gcc $(CFLAGS) -o $(TEMP_N) $(TEMP_O) $(CCLIBFT)
		mv temp ..

clean	:
		rm -rf $(TEMP_O)

fclean	: clean
		rm -rf ../$(TEMP_N)

re		:	fclean $(TEMP_N)