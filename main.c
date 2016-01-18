#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int key_position = -1;
node empty = {0, BLACK, NULL, NULL, NULL};
node *nil = &empty;
node *root = NULL;
int main()
{
	node *finded = NULL; 
	int data; /* Here will register a new key */
	while(1)
	{
		interface();
		scanf("%d", &data);
		switch(data)
		{
			case 1:
				printf("Please, enter new key\n");
				scanf("%d", &data);
				root = add_to_tree(root, data);
				break;
			case 2:
				print_all(root);
				break;
			case 3:
				delete_all(root);
				exit(1);
				break;
			case 4:
				printf("Please, enter finded element\n");
				scanf("%d",&data);
				finded = find_element(root, data);
				if(!finded)
					printf("You don't have element with key %d", data);
				else
					printf("Element with key %d\n", data);
				break;
/*			case 5:
				printf("Please, enter deleted element\n");
				scanf("%d",&data);
				delete_element(root, data);
				balance(root);
				break;*/
			default:
				printf("Incorrect number. Please, enter valid numbers\n");
				break;
		}
	}
}