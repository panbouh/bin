#include "temp.h"

int	put_makefile(int fd, const char *name)
{
	if ((write(fd, FILE_M1, ft_strlen(FILE_M1))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_M2, ft_strlen(FILE_M2))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);


	if ((write(fd, FILE_M3, ft_strlen(FILE_M3))) == FAIL)
		return (FAIL);
	return (OK);
}

int	put_header(int fd, char *name)
{
	if ((write(fd, FILE_H1, ft_strlen(FILE_H1))) == FAIL)
		return (FAIL);

	if ((write(fd, ft_strupper(name), ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_H2, ft_strlen(FILE_H2))) == FAIL)
		return (FAIL);

	if ((write(fd, ft_strupper(name), ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_H3, ft_strlen(FILE_H3))) == FAIL)
		return (FAIL);

	if ((write(fd, ft_strlower(name), ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_H4, ft_strlen(FILE_H4))) == FAIL)
		return (FAIL);

	return (OK);
}

int	put_src(int fd, char *name)
{
	if ((write(fd, FILE_S1, ft_strlen(FILE_S1))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_S2, ft_strlen(FILE_S2))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, FILE_S3, ft_strlen(FILE_S3))) == FAIL)
		return (FAIL);
	return (OK);
}

int	put_main(int fd, char *name)
{
	if ((write(fd, MAIN1, ft_strlen(MAIN1))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, MAIN2, ft_strlen(MAIN2))) == FAIL)
		return (FAIL);

	if ((write(fd, name, ft_strlen(name))) == FAIL)
		return (FAIL);

	if ((write(fd, MAIN3, ft_strlen(MAIN3))) == FAIL)
		return (FAIL);
	return (OK);
}

int	main(int ac, char **av)
{
	int		fd_m;
	int		fd_h;
	int		fd_c;
	int		fd_main;
	char	*file_m;
	char	*file_h;
	char	*file_c;
	char	*file_main;

	if (ac != 2)
		return (ft_error(USE_TEMP, FAIL));

	if (!(file_m = ft_strdup("Makefile")))
		return (ft_error(strerror(errno), FAIL));
	if (!(file_h = ft_strjoin(av[1], ".h")))
		return (ft_error(strerror(errno), FAIL));
	if (!(file_c = ft_strjoin(av[1], ".c")))
		return (ft_error(strerror(errno), FAIL));
	if (!(file_main = ft_strdup("main.c")))
		return (ft_error(strerror(errno), FAIL));

	if ((fd_m = open(file_m, O_RDWR | O_CREAT | O_EXCL, 0644)) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((fd_h = open(file_h, O_RDWR | O_CREAT | O_EXCL, 0644)) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((fd_c = open(file_c, O_RDWR | O_CREAT | O_EXCL, 0644)) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((fd_main = open(file_main, O_RDWR | O_CREAT | O_EXCL, 0644)) == FAIL)
		return (ft_error(strerror(errno), FAIL));

	if ((put_makefile(fd_m, av[1])) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((put_header(fd_h, av[1])) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((put_src(fd_c, av[1])) == FAIL)
		return (ft_error(strerror(errno), FAIL));
	if ((put_main(fd_main, av[1])) == FAIL)
		return (ft_error(strerror(errno), FAIL));

	close(fd_m);
	close(fd_h);
	close(fd_c);
	close(fd_main);
	ft_strdel(&file_m);
	ft_strdel(&file_h);
	ft_strdel(&file_c);
	ft_strdel(&file_main);
	return (OK);
}