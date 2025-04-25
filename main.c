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

            currNode->next = CreateTask(newTask);
            AddTaskSuccess(&newTask);
            currNode = currNode->next;
        }
        else if (strcmp("del", firstWord) == 0)
        {
            if (strlen(secondWord) == 1)
            {
                int value = firstWord - '0';
                printf("%s %d\n" "workin", value);
            }
        }
        else
        {
            printf("invalid input");
        }
    }

    return 0;
}