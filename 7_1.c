#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct t_list {
   char* name;
   long content[40];
   struct t_list *parent;
   struct t_list *child;
   struct t_list *next;
};

struct t_list* newnode(char* name)
{
    struct t_list* new = malloc(sizeof(struct t_list));
    if (!new)
        return (NULL);
    new->name = strdup(name);
    new->next = NULL;
    new->child = NULL;
    for (int i = 0; i < 40; i++)
        new->content[i] = 0;
    return (new);
}

struct t_list* lastel(struct t_list* elem)
{
    struct t_list* last;
    if (!elem)
        return (elem);
    last = elem;
    while (last->next != 0)
        last = last->next;
    return (last);
}

void add_child(struct t_list* parent, struct t_list* new) // вроде робит))
{
    struct t_list* last;

    new->parent = parent;
    if (parent->child == 0)
    {
        parent->child = new;
        return ;
    }
    last = lastel(parent->child);
    last->next = new;
}

long sizedir(struct t_list* node)                 // вроде оно робит!!
{
    long size = 0;
    struct t_list *inside;

    for (int i = 0; node->content[i] != 0; i++)
        size += node->content[i];
    inside = node->child;
    while (inside != 0)
    {
        size += sizedir(inside);
        inside = inside->next;
    }
    return (size);
}

struct t_list* find_child(struct t_list* parent, char *name)    // робит вроде
{
    struct t_list* out;
    struct t_list* child;

    child = parent->child;
    while(child != 0)
    {
        if (!strcmp(child->name, name))
            return (child);
        child = child->next;
    }
    return (NULL);
}

void add_content(struct t_list* node, long num)
{
    int i;
    for (i = 0; i < 40 && node->content[i] != 0; i++);
    node->content[i] = num;
}

long going_through(struct t_list* node)
{
    long size;
    if (node == 0)
        return 0;
    size = sizedir(node);
    if (size > 100000)
        size = 0;
    return (going_through(node->child) + going_through(node->next) + size);
}

int main()
{
    FILE* inp = fopen("7_inp", "r");
    char line[50] = {0};
    int i = 0;
    struct t_list *current = newnode("head");
    struct t_list *first = newnode("/");
    add_child(current, first);
    while (fgets(line, 50, inp))
    {
        printf("line[%04d]: %s", ++i, line);
        if (atoi(line) != 0)
        {
            add_content(current, atoi(line));
        }
        else if (!strncmp("$ cd ..", line, 7))
            current = current->parent;
        else if (!strncmp("$ cd ", line, 5))
        {
            char *name = strdup(&line[5]);
            name[strlen(name) - 1] = 0;
            current = find_child(current, name);
        }
        else if (!strncmp("dir ", line, 4))
        {
            char *name = strdup(&line[4]);
            name[strlen(name) - 1] = 0;
            struct t_list* new = newnode(name);
            add_child(current, new);
        }
    }
    //printf("/_s = %ld\n", sizedir(first));
    printf("go_thr = %ld\n", going_through(first));
    fclose(inp);
    return 0;
}
