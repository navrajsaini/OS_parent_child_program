/*******************************************
 BY: Navraj Saini
 Class: OS, fall 2017
 purpose:
   1.
    print out A to Z in the parent process
    and print a to z in the child process
   2.
    in the child process: print out the
     current process id and the parent
     process id
    in the parent process: print out the
     current process id and the parent
     process id
*******************************************/

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
   string parent = "ABCDEFghijkLMNOPqrstuvWXYZ";
   
   pid_t child = fork();
   
   if (child == 0)
   {
      transform(parent.begin(), parent.end(), parent.begin(), ::tolower);
      std::cout << "in the child process: " << endl << parent << std::endl;
      pid_t ppid = getppid(); // the parent process id
      pid_t pid = getpid(); // the current process id
      cout << "the current process id is: " << pid << endl;
      if(ppid < 0)
	 cout << "there is no parent for this process." <<endl;
      else
	  cout << "the parent process id is: " << ppid << endl;
   }
   if (child > 0)
   {
      transform(parent.begin(), parent.end(), parent.begin(), ::toupper);
      std::cout << "in the parent process: " << endl << parent << std::endl;
      pid_t ppid = getppid();
      pid_t pid = getpid();
      cout << "the current process id is: " << pid << endl;
      if (ppid < 0)
	 cout << "no parent for this process" << endl;
      else
	 cout << "the parent process id is: " << ppid << endl;
   }
   else if (child < 0)
      cout << "no child created" << endl;
}
