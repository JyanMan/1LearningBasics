#include "somelib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Node* CreateTask(Task task)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->task.finished = "in-progress";
    newNode->next = NULL;

    return newNode;
}

void PrintTask(Task* task)
{
    printf("%s", task->name);
    printf(" -> %s\n", task->description);
}

void PrintAllTasks(Node* node)
{
    Node *temp = node;

    if (temp == NULL)
    {
        printf("you have no tasks\n");
        return;
    }
    while (temp)
    {
        PrintTask(&temp->task);
        temp = temp->next;
    };
}

char* GetWordOf(char str[], int wordNum)
{
    int wordCount = 0;
    int spaceIndex = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
        {
            continue;
        }

        if (wordCount < wordNum - 1)
        {
            wordCount++;
            spaceIndex = i+1;
            continue;
        }

        int wordLength = i - spaceIndex;
        char* word = (char*)malloc(wordLength);

        for (int j = 0; j < wordLength; j++)
        {
            // printf("%c\n", str[spaceIndex + j]);
            word[j] = str[spaceIndex+j];
        }
        word[wordLength] = '\0';
        return word;
    }
    // printf("not reached");
    return NULL;
}

void AddTaskSuccess(Task* task)
{
    printf("successfully added new task:\n");
    printf("name: %s\n", task->name);
    printf("description: %s\n", task->description);
    printf("\n");
}