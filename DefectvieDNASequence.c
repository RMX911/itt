#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This represents a node in the list 
 * Allocate a new node as follows
 * node * new_node = malloc(sizeof(node));
 */
typedef struct node_t
{
	char data[3];
	struct node_t *next;
} node;

/* Linked List holding references to head and tail of the list*/
typedef struct linked_list_t
{
	node *head,* tail;
} linked_list;


void fix_dna_sequence(linked_list * dna_sequence, linked_list *gene_sequence)
{node *temp1 = dna_sequence->head;
    node *temp2 = NULL;
    node *temp3 = gene_sequence->head;
    
  //Search for defective gene sequence in the dna_sequence
    while(temp1 != NULL){
        
        temp3 = gene_sequence->head;
        if(strcmp(temp1->data,temp3->data)==0){
            while(temp1!= NULL && temp3 != NULL){
                if(strcmp(temp1->data,temp3->data)==0){
                    temp1=temp1->next;
                    temp3=temp3->next;
                    continue;
                    
                }

                break;
            }
            
            if(temp3==NULL){
                temp2->next=temp1;
            }
            
        }
        else{
            temp2 = temp1;
            temp1 = temp1->next;
            
        }
        
    //     while(temp2->next != gene_sequence->tail){
    //         if(strcmp(temp1->data,temp2->data)!=0){}
    //     }
    // }
  //and remove the gene_sequence from the dna_sequence
  
}
}


void list_init(linked_list **list)
{
	*list = malloc(sizeof(linked_list));
	(*list)->head = NULL;
	(*list)->tail = NULL;
}

int add(linked_list *list, char *item)
{
	node *new_node= (node*)malloc(sizeof(node));	
	strcpy(new_node->data,item);
	new_node->next = NULL;

	if(list->head == NULL)
	{
		list->head=new_node;
		list->tail=new_node;
	}
	else
	{
		list->tail->next = new_node;
		list->tail = new_node;
	}

	return 0;
}


void list_display(linked_list *list)
{
	node *current=list->head;
	printf("List : ");
	while(current!=NULL)
	{
		printf("%s,",current->data);
		current = current->next;
	}
	printf("\n");
}




char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    
    char* data = malloc(alloc_length);
    
    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        
        if (!line) {
            break;
        }
        
        data_length += strlen(cursor);
        
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }
        
        alloc_length <<= 1;
        
        data = realloc(data, alloc_length);
        
        if (!data) {
            data = '\0';
            
            break;
        }
    }
    
    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        
        data = realloc(data, data_length);
        
        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);
        
        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }
    
    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }
    
    if (!*str) {
        return str;
    }
    
    while (*str != '\0' && isspace(*str)) {
        str++;
    }
    
    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }
    
    if (!*str) {
        return str;
    }
    
    char* end = str + strlen(str) - 1;
    
    while (end >= str && isspace(*end)) {
        end--;
    }
    
    *(end + 1) = '\0';
    
    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }
    
    return value;
}

long parse_long(char* str) {
    char* endptr;
    long value = strtol(str, &endptr, 10);
    
    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
   }
   return value;
}

int main(int argc, char * argv[])
{
    linked_list *dna_sequence;
    linked_list *gene_sequence;
    list_init(&dna_sequence);
    list_init(&gene_sequence);
  
    int l_dna_sequence= parse_int(ltrim(rtrim(readline())));
    for (int i = 0; i < l_dna_sequence; i++) {
        char * l_item = ltrim(rtrim(readline()));
        
        add(dna_sequence, l_item);
    }
    int l_gene_sequence= parse_int(ltrim(rtrim(readline())));
    for (int i = 0; i < l_gene_sequence; i++) {
        char * l_gene = ltrim(rtrim(readline()));
        
        add(gene_sequence, l_gene);
    }
    
    //printf("Input DNA Sequence ");list_display(dna_sequence);
    //printf("Input Gene Sequence ");list_display(gene_sequence);
    fix_dna_sequence(dna_sequence,gene_sequence);
    printf("Corrected DNA Sequence ");list_display(dna_sequence);
    
    return 0;
}
