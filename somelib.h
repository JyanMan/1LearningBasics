#ifndef SOMELIB_H
#define SOMELIB_H

typedef struct Task
{
    int id;
    char *name;
    char *description;
    char *finished;
} Task;

typedef struct Node
{
    Task task;
    struct Node* next;
} Node;

Node* CreateTask(Task task);

void PrintTask(Task* task);

void PrintAllTasks(Node* node);

char* GetWordOf(char str[], int wordNum);

void AddTaskSuccess(Task* task);

void DeleteTask(Node *node, int id);

#endif