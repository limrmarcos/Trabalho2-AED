#include <stdio.h>
#include <stdlib.h>

//Adicionar struct para facilitar? Ou vai dificultar?

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize);
int Pop( int* type, int size );
void Push( int* type, int size, int value );

int main( void ) {
    int unableEat = 0;
    int* students = ( int* ) malloc ( sizeof( int ) );
    //Pedir a quantidade de alunos e a informação ou dar Push de estudante em estudante?


    //unableEat = countStudents( students, studentsSize, sandwiches, sandwichesSize );
    printf( "%d students weren't able to eat!", unableEat );
    return 0;
}

int countStudents( int* students, int studentsSize, int* sandwiches, int sandwichesSize ) {
    int counter = 0;

    if( students[0] != sandwiches[0] ) {
        int student = Pop( students[0], studentsSize );
        Push( students, student, studentsSize );
    } else if( students[0] == sandwiches[0] ) {
        Pop( students[0], studentsSize );
        Pop( sandwiches[0], sandwichesSize );
        //Com a struct ficaria mais fácil o controle do tamanho
    } 

    if( sandwichesSize == 0 ) {
        return studentsSize;
        //parece muito exagerado usar esse return
    }
}

void Push( int* type, int size, int value ) {
    //type[size] = value;
}

int Pop( int* type, int size ) {
    
}