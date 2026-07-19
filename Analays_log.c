#include <stdio.h>

#include <string.h>

double Max_sc(double *s , int count ) {
    if (s == NULL ||count <= 0 ) {return 0.0;}


    double num = *s;
    static int high_index = 0;
    for (int i = 1; i < count; i++) {

        if (s[i] > num) {

            num = s[i];

            high_index = i;
        }

    }

    return num;
}

double low_sc(double *s , int count) {
    
    if (s == NULL || count <= 0) {return 0.0;}

    double num = *s;
    static int index_low = 0;
    for (int i = 1;i < count; i++ ) {

        if (s[i] < num) {

            num = s[i];

            index_low = i;

            

        }

    }

    return num;
}

int  index_low(double *s , int count) {
    
    if (s == NULL || count <= 0) {return 0.0;}

    double num = *s;
     int index_low = 0;
    for (int i = 1;i < count; i++ ) {

        if (s[i] < num) {

            num = s[i];

            index_low = i;

            

        }

    }

    return index_low;
}


int  index_hight(double *s , int count) {
    
    if (s == NULL || count <= 0) {return 0.0;}

    double num = *s;
     int index_hight = 0;
    for (int i = 1;i < count; i++ ) {

        if (s[i] > num) {

            num = s[i];

            index_hight = i;

            

        }

    }

    return index_hight;
}
int main() {

    FILE *file = fopen("students.txt","r");

    if (file == NULL) {

        printf("the file not found \n");

        return 1;
    }


    int ch = fgetc(file);

    if (ch == EOF) {

        printf("the file is empty \n");
        fclose(file);
        return 1;
    }

    else {

        rewind(file);
    }
    char Max_Students[100][50];

    double Max_Score[100];

    char name[100][60];
    int count = 0;

    int score[100];
   
    while(fscanf(file,"%s %d",name[count] , &score[count]) == 2) {

        // انشاء لكل طالب منفصل
        
        strcpy(Max_Students[count] , name[count]);

        Max_Score[count] = score[count];


        count++;
            

    }
    fclose(file);

    
    double Highest_score =Max_sc(Max_Score , count);
    
    double Lowest_score = low_sc(Max_Score , count);
    double sum = 0.0;

    int index_high = index_hight(Max_Score , count );

    int index_lowes = index_low(Max_Score , count);

    for (int i  = 0; i < count;i++ ) {

        sum +=Max_Score[i];
    }


    double Avarage = sum / count;

    printf("%s = %.2f \n %s = %.2f \n Avarage = %.2f \n",Max_Students[index_high] , Highest_score ,Max_Students[index_lowes], Lowest_score , Avarage);


    

    return 0;
}
