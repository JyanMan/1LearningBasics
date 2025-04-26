#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "somelib.h"

int main()
{
    Node* currNode = CreateTask((Task) { .name = "hello", .description = "try" });
    Node *node = currNode;

    char command[20];

    while (true)
    {
        printf("input your command: \n");
        fgets(command, sizeof(command), stdin);
        printf("\n");

        char* firstWord = GetWordOf(command, 1);
        char* secondWord = GetWordOf(command, 2);
        char* thirdWord = GetWordOf(command, 3);

        if (strcmp("list", firstWord) == 0)
        {
            if (strcmp("all", secondWord) == 0)
            {
                PrintAllTasks(node);
            }
            else
                printf("%s\n", "invalid input");
        }
        else if (strcmp("add", firstWord) == 0)
        {
            Task newTask = { .name = secondWord, .description = thirdWord };
            if (currNode == NULL)
            {
                currNode = CreateTask(newTask);
                AddTaskSuccess(&newTask);
                continue;
            }

            printf("currNode is -----> %s\n", currNode->task.name);

            currNode->next = CreateTask(newTask);
            AddTaskSuccess(&newTask);
            currNode = currNode->next;
        }
        else if (strcmp("del", firstWord) == 0)
        {
            if (strlen(secondWord) == 1)
            {
                int inputVal = secondWord[0] - '0';
                if (inputVal < 0 || sizeof(inputVal) != sizeof(int))
                {
                    printf("invalid input");
                    continue;
                }
                DeleteTask(&node, &currNode, inputVal);
                // printf("%lld %lld %lld\n", sizeof(value), sizeof(int), sizeof(char));
            }
            else
                printf("invalid input");
        }
        else
        {
            printf("invalid input");
        }
    }

    return 0;
}