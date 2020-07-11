//
//  main.c
//  Chapter 2: Review of Standard Pointer and Array Operations
//
//  Created by Jose on 7/4/20.
//  Copyright © 2020 Jose Lopez. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define getName(var) #var
struct point{
       int x;
       int y;
   };
   
struct foo{
    int i;
    char string[10];
};

int main(int argc, const char * argv[]) {
    
    
    int strlength(char *string);
    int sumints1(int *pi);
    int sumints2(int pi[]);
    int sumints3(int *pi, int num_elements);
    void swapstruct(struct point *foo, struct point *foo2);
    
    // insert code here...
    printf("Hello, World!\n");
    
    char c[]="hello";
    printf("%d\n",strlength(c));
    
    
    
    int d[] = {5,3,5,4,2,0};
    int num_elements = 5;
    printf("Summing ints with pointers = %d\n",sumints1(d));
    printf("Summing ints through Indexing =  %d\n",sumints2(d));
    printf("Summing array with pointer arithmetic = %d\n",sumints3(d, num_elements));
    
   
    struct point point1 = {25,53};
    struct point point2 = {43,11};
    
    
    printf("The position of point %s (%d,%d)\n",getName(point1),point1.x,point1.y);
    
    printf("The positon of point %s (%d,%d)\n",getName(point2),point2.x,point2.y);
    
    
    swapstruct(&point1, &point2);
    
    printf("The position of point %s (%d,%d)\n",getName(point1),point1.x,point1.y);
    
    printf("The positon of point %s (%d,%d)\n",getName(point2),point2.x,point2.y);
    
    
    
    struct foo sfoo, *fooptr;
    
    
    
   // strcpy(sfoo.string, "Hello");
    
    
    //2.3 Assigning and Initializing One-Dimensional Arrays
    
    char s1[80]= "Hello",s2[80];
    
    printf("The value of the first string is: %s\n",s1);
    
    
    
    printf("We will try to set the second string to the first string\n");
    
    //We use strcpy in order to do so.
    
    fooptr = (struct foo *)malloc(sizeof(struct foo));
    
    fooptr->i = 5;
    strcpy(fooptr->string, "Hey there");
    printf("%s\n",sfoo.string);
    
   
    
    return 0;
}






 

//Example 2.1 The insides of the ANSI C Strlen Function
/*
    Characters are guarantted to occupy one byte of memeory in the ANSI C standard. Therefore the addres held in ptr will be strlen(string) higher than the address held in string.
 */
int strlength(char *string){
    char *ptr = string;
    
    while(*ptr!='\0')
    {
        ptr++;
    }
    
    return ptr-string;
}

/*
Examples 2.3 Typical Traversal of a Non-Char Array with a Pointer
 */
int sumints1(int *pi){
    
    int sum = 0;
    printf("Numbers in the array will now be printed \n");
    while(*pi!='\0')
    {
        printf("%d\n",*pi);
        sum += *pi++;
        
    }
    
    return sum;
}
/*Example 2.4 Traversin an Array by Indexing
    (Not Recommendeded)
 */
int sumints2(int i[])
{
    
    int sum = 0,j = 0;
    
    while(i[j]!=0)
    {
        sum += i[j++];
    }
    return sum;
}


/*Example 2.6 A generalized Array Sum Function with Pointer Arithmetic*/

int sumints3(int *pi, int num_elements)
{
    
    int sum = 0;
    
    while(num_elements-- >0)
    {
        sum+=*pi++;

    }
    return sum;
}



/*Example 2.10 Correct Way to Swap Structs in a Function*/

void swapstruct(struct point *p1, struct point *p2)
{
    struct point temp;
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int sumstruct(struct point *sfp, int num_elements)
{
    
    
    int sum = 0;
    
    while(num_elements-- >0)
    {
        sum+=sfp->x;
        sfp++;
    }
    return 0;
}
