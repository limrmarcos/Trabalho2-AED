#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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
    int stackTop = 0, unableEat = 0, test = 0;
    Sentinel* nStudent = ( Sentinel* ) malloc ( sizeof( Sentinel ) );
    nStudent->first = NULL;
    nStudent->last = NULL;

    for( int i = 0; i < studentsSize; i++  ) {
        push( nStudent, students[i] );
    }
    while( nStudent->first != NULL && test < sandwichesSize ) {
        if( sandwiches[stackTop] == nStudent->first->info ) {
            stackTop++;
            pop( nStudent );
            test = 0;
        } else {
            int value = pop( nStudent );
            push( nStudent, value );
            test++;
        }
    }
    while( nStudent->first != NULL) {
        pop( nStudent );
        unableEat++;
    }

    free( nStudent );
    return unableEat;
}

int main() {
    int studentsSize = 0;
    int students[MAX], sandwiches[MAX];

    scanf( "%d", &studentsSize );

    int sandwichesSize = studentsSize;
    for( int i = 0; i < studentsSize; i++ ) {
        scanf( "%d", &students[i] );
    }
    for( int i = 0; i < sandwichesSize; i++ ) {
        scanf( "%d", &sandwiches[i] );
    }
    
    int result = countStudents(students, studentsSize, sandwiches, sandwichesSize);
    printf("%d\n", result);
    return 0;
}