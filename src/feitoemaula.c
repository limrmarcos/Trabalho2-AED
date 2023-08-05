#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};
typedef struct node Node;

struct sentinel {
    Node* first;
    Node* last;
};
typedef struct sentinel Sentinel;

void push( Sentinel* p, int value ) {
    Node* newNode = ( Node* ) malloc ( sizeof( Node ) );
    newNode->info = value;
    newNode->next = NULL;

    if( p->first == NULL ) {
        p->first = newNode;
        p->last = newNode;
    } else {
        p->last->next = newNode;
        p->last = newNode;
    }
}

int pop( Sentinel* p ) {
    Node* temp = p->first;
    int info = temp->info;
    p->first = p->first->next;
    free(temp);
    return info;
}

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSize ) {
    int stackTop = 0, unableEat = 0;
    Sentinel* nStudent = ( Sentinel* ) malloc ( sizeof( Sentinel ) );
    nStudent->first = NULL;
    nStudent->last = NULL;

    for( int i = 0; i < studentsSize; i++  ) {
        push( nStudent, students[i] );
    }

    while( nStudent->first != NULL ) {
        if( sandwiches[stackTop] == nStudent->first->info ) {
            stackTop++;
            pop( nStudent );
        } else {
            int value;
            value = pop( nStudent );
            push( nStudent, value );
        }
    }
    return unableEat;
}

int main() {
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int studentsSize = 4;
    int sandwichesSize = 4;
    int result = countStudents(students, studentsSize, sandwiches, sandwichesSize);
    printf("%d\n", result);
    return 0;
}