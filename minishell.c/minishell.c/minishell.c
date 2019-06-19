#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
	while (1) {
		printf("[san@localhost]$ ");
		fflush(stdout);

		char tmp[1024] = { 0 };
		scanf("%[^\n]%*c", tmp);
		printf("[%s]\n", tmp);

		//需要将整体字符串解析出：程序名称+参数
		//"   ls -a -l" -> "ls"  "-a" "-l"
		char *ptr = tmp;
		int argc = 0;
		char *argv[32] = { NULL };
		while (*ptr != '\0') {
			if (!isspace(*ptr)) {
				//指针走到非空白字符处
				argv[argc] = ptr;
				argc++;
				while (!isspace(*ptr) && *ptr != '\0') ptr++;
				*ptr = '\0';
				ptr++;
				continue;
			}
			ptr++;
		}
		argv[argc] = NULL;
		//argv[0]=ls  argv[1] = -l argv[2] = -a

		//判断当前命令是否是内建命令
		if (!strcmp(argv[0], "cd")) {
			//改变当前工作路径
			chdir(argv[1]);
			continue;
		}

		int pid = fork();
		if (pid == 0) {
			execvp(argv[0], argv);
			//若子进程程序替换失败，则直接退出,因为终端不需要多个shell
			exit(0);
		}
		//等待子进程退出，避免僵尸进程
		wait(NULL);
	}
	return 0;
}
