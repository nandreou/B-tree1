#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>

typedef struct node
{
  int number;
  struct node *left;
  struct node *right;
}
node;

void display(node *p, int space);
void *find(node *root);
void rem(node *root);
void *rem_search(node *root, int *i);

int main(void)
{
  node *root = NULL;
  node *n = NULL;
  node *current = NULL;
  int *key = malloc(sizeof(int)*3);
  int k[13] = {8,3,6,2,7,5,12,15,45,1,14,9,4};

  for(int i=0; i<13; i++)
{
  n = malloc(sizeof(node));
  n->number = k[i];
  n->right = NULL;
  n->left = NULL;

  if(root==NULL)
  {
  root = n;
  current = root;
  }
  else
  {
    while(true)
    {
      if(n->number > current->number && current->right != NULL)
      {
        current = current->right;
      }
      else if(n->number <= current->number && current->left != NULL)
      {
        current = current->left;
      }
      else if(n->number > current->number && current->right == NULL)
      {
      current->right = n;
      break;
    }
      else if(n->number <= current->number && current->left == NULL)
      {
        current->left = n;
        break;
      }
  }
current = root;
}
}

display(root, 0);

key = find(root);

if(key != NULL && key[2] == 0)
{
printf("number: %i\n", key[0]);
printf("depth :%i\n", key[1]);
}
else if(key != NULL && key[2]>0)
printf("found: %i times\n", key[2]);
else
printf("not found\n");


rem(root);
}

void display(node *p, int space)
{
      // Base case
      if (p == NULL)
          return;

      // Increase distance between levels
      space += 10;

      // Process right child first
     display(p->right, space);

      // Print current node after space
      // count
      printf("\n");
      for (int i = 10; i < space; i++)
          printf(" ");
      printf("%i\n", p->number);

      // Process left child
      display(p->left, space);

}

void *find(node *root)
{
  //else tree traversal
  int *k = malloc(sizeof(int)*3);
  char *c = malloc(sizeof(char));
  node *current = root;
  k[0] = 0;
  k[1] = 0;
  int counter = 0;
  int counter2 = 0;
  printf("give key value\n");
  scanf("%i", &k[0]);

while(true)
{
  printf("is the value that you are searching only one time inside the tree? (If you don't know or it is not pess n or no, if you do know press y or yes)\n");
  scanf("%s", c);
  if((strcasecmp(c, "y") != 0 && strcasecmp(c, "yes") != 0 && strcasecmp(c, "n") != 0 && strcasecmp(c, "no") != 0))
  printf("wrong input\n");
  else
  break;
  }

// the reason of this condition is because we dont want to keep serching if the value exists only one time
if(strcasecmp(c, "y") == 0 || strcasecmp(c, "yes") == 0)
{
  if(root == NULL)
  {
    printf("error\n");
  return NULL;
  }

while(true)
{
  if(k[0] == current->number)
  {
    k[1] = counter;
    k[2] = counter2;
    return k;
  }
  else if(k[0] > current->number)
  {
    current = current->right;
    counter++;
  }
  else if(k[0] < current->number)
  {
    current = current->left;
    counter++;
  }

  if(current == NULL)
  {
    k = NULL;
    return k;
  }
}
}
else
{
  if(root == NULL)
  {
    printf("error\n");
  return NULL;
  }

while(true)
{
  if(k[0] == current->number)
  {
    k[1] = counter;
    counter2++;
    k[2] = counter2;
    printf("Time %i\n", counter2);
    printf("Number: %i\n", k[0]);
    printf("Depth: %i\n", k[1]);
    printf("\n");
    current = current->left;
  }
  else if(k[0] > current->number)
  {
    current = current->right;
    counter++;
  }
  else if(k[0] < current->number)
  {
    current = current->left;
    counter++;
  }

  if(current == NULL && k[2] == 0)
  {
    k = NULL;
    return k;
  }
  else if(current == NULL && k[2]>0)
  return k;
}
}
}

void rem(node *root)
{
  int *r = malloc(sizeof(int));
  node *current = root;
  node *parent = root;
  int counter = 0;

  if(root == NULL)
  printf("error");

  printf("Type the value that you need to remove\n");
  scanf("%i", r);

  while(true)
  {
    if(*r == current->number)
    {
    break;
    }
    else if(*r>current->number)
    {
    parent = current;
    current = current->right;
    }
    else if(*r < current->number)
    {
    parent = current;
    current = current->left;
    }

    if(current == NULL)
    {
    printf("Not found\n");
    return;
    }
}

  printf("%i, %i", parent->number, current->number);

  if(current->left == NULL && current->right == NULL)
  {
  if(current==parent->left)
  parent->left = NULL;
  else if(current==parent->right)
  parent->right = NULL;
  free(current);
  display(root, 0);
  }
  else if(current->left == NULL && current->right != NULL)
  {
    parent->right = current->right;
    free(current);
    display(root, 0);
  }
  else if(current->left != NULL && current->right == NULL)
  {
    parent->left = current->left;
    free(current);
    display(root, 0);
  }
  else if(current->left != NULL && current->right != NULL)
  {
    if(parent->number < current->number)
    {
      current->left->right = current->right;
      parent->right = current->left;
      free(current);
      display(root, 0);
    }
    else if(parent->number > current->number)
    {
      current->right->left = current->left;
      parent->left = current->right;
      free(current);
      display(root, 0);
    }
  }
}
