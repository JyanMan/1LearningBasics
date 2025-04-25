#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define varlen(x) sizeof(typeof(x))

typedef struct Task
{
    char *name;
    char *description;
} Task;

typedef struct Node
{
    Task task;
    struct Node* next;
} Node;

Node* CreateTask(Task task)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->task = task;
    // printf("%s\n", task.description);
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
        // free(temp);
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

int main()
{
    Node* currNode = CreateTask((Task) { .name = "hello", .description = "try" });
    Node *node = currNode;
    // currNode->next = CreateTask((Task) { .name = "again", .description = "noman" });

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
        }
        else if (strcmp("add", firstWord) == 0)
        {
            Task newTask = { .name = secondWord, .description = thirdWord };
            if (currNode == NULL)
            {
                currNode = CreateTask(newTask);
                AddTaskSuccess(&newTask);
                return;
            }

            currNode->next = CreateTask(newTask);
            AddTaskSuccess(&newTask);
            currNode = currNode->next;
        }
        else
        {
            printf("invalid input");
        }
    }

    return 0;
}