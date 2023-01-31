
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

using std::cout; using std::endl;

int main() {
    pid_t c_pid = fork();
	char *ptr = new char(2);
	char stack = 'x';
	ptr[0] = 'a';

    if (c_pid == 0) 
	{
		std::cout <<  &ptr << std::endl;
        cout << "printed from parent process " << getpid() << endl;
		ptr[0] = 'c';
		stack = 'y';
	}
	else {
		waitpid(-1, NULL, 0);
	}	
	if (c_pid == 0)
	{
		printf("enfant adresse pointe par le pointeur: %p\n",ptr);
		printf("enfant adresse pointer: %p\n",&ptr);
		std::cout << "enfant heap: " << ptr << std::endl;
		std::cout << "enfant stack: " << stack << std::endl;
	}
	if (c_pid != 0)
	{
		printf("parent adresse pointe par le pointeur: %p\n",ptr);
		printf("parent adresse pointeur: %p\n",&ptr);
		std::cout << "parent heap: " <<  ptr << std::endl;
		std::cout << "parent stack: " << stack << std::endl;
	}
	delete ptr;
   }
