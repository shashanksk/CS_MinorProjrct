#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <algorithm>

int main()
{
    printf("\n\nWelcome to Hailstone, by Sean Staz\n");

    std::string k;
    int flag = 0, i = 0;
    pid_t pid;

    do
    {

        try
        {
            printf("Please enter a number greater than 0 to run the Collatz Conjecture ::");
            std::cin >> k;

            // to check if the input is a valid number
            bool digits = all_of(k.begin(), k.end(), isdigit);

            if (digits && (stoi(k) > 0))
            {
                std::cout << "valid input  \n";
                flag = 1;
            }
            else
            {
                throw(k);
            }
        }
        catch (...)
        {
            std::cout << "\n\nERR :: Please check your input :: ";
            for (auto i : k)
            {
                std::cout << i;
            }
            std::cout << std::endl;
        }

    } while (flag == 0);

    int h = stoi(k); // convert string to an integer

    pid = fork();
    // child process continues from line 55
    //  std::cout << "this is pid " << pid << std::endl;
    if (pid == 0)
    {
        // std::cout << "this is pid debug 2 ::" << pid << std::endl;
        // std::cout << std::endl
        //           << "this is i " << i << std::endl; //debug statement
        printf("Child is working...\n");
        printf("%d\n", h);

        i++;

        while (h != 1)
        {
            if (h % 2 == 0)
            {
                h = h / 2;
            }
            else if (h % 2 == 1)
            {
                h = 3 * (h) + 1;
            }

            printf("%d\n", h);
        }

        printf("Child process is done.\n");
    }
    else
    {
        printf("\n\nParents is waiting on child process...\n");
        wait(NULL);
        printf("Parent process is done.\n");
    }
    return 0;
}