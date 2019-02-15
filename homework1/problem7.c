#include <stdio.h>

int main()
{
    char inputName[20]; 
    int inputAge;
    char inputClassName[9];
    int inputHeight;
    int inputWeight;
    char inputBloodType[2];
    printf("Input your name: \n");
    scanf("%s", inputName);
    printf("Input your age: \n");
    scanf("%d", &inputAge);
    printf("Input your class year: \n");
    scanf("%s", inputClassName);
    printf("Input your height in inches: \n");
    scanf("%d", &inputHeight);
    printf("Input your weight in pounds: \n");
    scanf("%d", &inputWeight);
    printf("Input your blood type: \n");
    scanf("%s", inputBloodType);
    
    printf(" Name: %s \n Age: %d \n Class Year: %s \n Height: %d inches \n Weight: %d pounds\n BloodType: %s \n ", 
            inputName, inputAge, inputClassName, inputHeight, inputWeight, inputBloodType);
    
    return 0;
}
