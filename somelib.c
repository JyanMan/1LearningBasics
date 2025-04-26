#include "somelib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int uniqueId = 0;

Node* CreateTask(Task task)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    newNode->task.finished = "in-progress";
    newNode->next = NULL;
    
    // make id unique
    newNode->task.id = uniqueId;
    uniqueId++;

    return newNode;
}

void PrintTask(Task* task)
{
    printf("%d %s -> %s\n", task->id, task->name, task->description);
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
    }
    printf("ended\n");
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
    return NULL;
}

void AddTaskSuccess(Task* task)
{
    printf("successfully added new task:\n");
    printf("name: %s\n", task->name);
    printf("description: %s\n", task->description);
    printf("\n");
}

void DeleteTask(Node **node, Node **head, int id)
{
    Node **mainNode = node;
    Node *currNode = *node;
    Node *prevNode = NULL;
    Node *delNode = NULL;

    if (currNode == NULL)
    {
        return;
    }
    while (currNode)
    {
        //you have a node in advance
        //it checks if it is nul
        //once prevnode finds it
        //free the deleted node
        if ((currNode)->task.id != id)
        {
            prevNode = currNode;
            currNode = currNode->next;
            continue;
            // prevNode->next = currNode->next;
        }
        printf("found with id %d -> %s\n", id, currNode->task.name);
        if ((currNode)->next == NULL)
        {
            printf("%s\n", prevNode->task.name);
            prevNode->next = NULL;
            *head = prevNode;
            free(prevNode->next);
            free(currNode);
            break;
        }
        if (prevNode == NULL)
        {
            *node = (*node)->next;
            free(*mainNode);
            break;
        }

        //basically skip the currnode so it no longer is included;
        delNode = currNode;
        currNode = currNode->next;
        prevNode->next = currNode;
        free(delNode);

        break;
        // currNode = currNode->next;
        // if (currNode->task.id == id)
        //     prevNode->next = currNode->next;
        
        // delNode = currNode;
        // free(delNode);
    };
}