#ifndef		TEMP_H
# define	TEMP_H

#include "libft.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

# define	USE_TEMP	"temp use :\n\ttemp [NameProject]\n"
# define	FILE_M1		"NAME	=	"
# define	FILE_M2		"\n\nSRC		=	$(WAY)main.c		\\\n			$(WAY)"
# define	FILE_M3		".c\n\nOBJ		=	$(SRC:.c=.o)\n\nWAY		=	src/\n\nHEADPATH	=	./includes/\n\nLIBFT			=	libft\nLIBFTPATH		=	./libft/\nHEADLIBFTPATH	=	$(LIBFTPATH)includes/\n\nCFLAGS		=	-I $(HEADLIBFTPATH) -I $(HEADPATH) -Wall -Wextra -Werror\nCCLIBFT		=	-L libft/ -lft\n\nRM		=	rm -rf\n\nall	:	$(NAME)\n\n$(NAME)		: $(LIBFT) $(OBJ)\n				@echo \"Binary < $(NAME) > Creation\"\n				gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CCLIBFT)\n\nlibft		:\n				@echo \"Library < $(LIBFT).a > Creation\"\n				@$(MAKE) -C $(LIBFTPATH) all\n\ndellibft	:\n				$(MAKE) -C $(LIBFTPATH) fclean\n\nclean		:\n				$(RM) $(OBJ)\n\nfclean		:	clean\n				$(RM) $(NAME)\n\nrelibft		:\n				$(MAKE) -C $(LIBFTPATH) re\n\nre			:	fclean $(NAME)\n\n.PHONY		:	all re clean fclean libft dellibft all relibft\n\n"

# define	FILE_H1		"#ifndef		"
# define	FILE_H2		"_H\n# define	"
# define	FILE_H3		"_H\n\n#include \"libft.h\"\n\nint	"
# define	FILE_H4		"();\n\n#endif\n"

# define	FILE_S1		"#include \""
# define	FILE_S2		".h\"\n\nint	"
# define	FILE_S3		"()\n{\n	return (OK);\n}\n"

# define	MAIN1		"#include \""
# define	MAIN2		".h\"\n\nint	main(/*int ac, char **av*/)\n{\n//	if (ac != 2)\n//		return (ft_error(USE, FAIL));\n\n	"
# define	MAIN3		"();\n\n	return (OK);\n}\n"

#endif