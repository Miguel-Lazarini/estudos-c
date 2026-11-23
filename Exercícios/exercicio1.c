#include <stdio.h> //This first exercice is to test my skills with variables floats and ints.

int main(void)
{
    int initial_position = 9;
    float velocity = 4.0;
    float time = 5.4;

    float position = initial_position + velocity * time;

    printf("The final position is %f\n", position);
    return 0;
}

// The goal is calculate a final position (S) like a cinematics in pysichs.