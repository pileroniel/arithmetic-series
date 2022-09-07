
#include <stdio.h>
#include <stdlib.h>


/*
Author: Ron George Pile
Implementing a program that interprets a valid arithmetic sequence provided by the user and outputs
the value of the nth sequence using recursion
*/

//Declaring function prototypes
int userSequence( int nums[] ); //this function allows the user to input the first 3 numbers of an arithmetic series
int checkValidity(int nums[]);//checks whether the series follows a certain order and if it does, it provides the common difference of the series
int nthTerm( int nth, int commonDiff, int nums[]); //finds the nth term in the arithmetic series


//It will be processed to establish if there exits a valid arithmetic sequence
int main()
{

   int numsArray[3], cd,nth,result;
   char askMore;
   //numsArray stores the input in array format
   //nth variable stores what term the user would like to find in the arithmetic series
   //cd stores the common difference int the number series
   //result stores the answer (nth term)
   printf("\n\t******ARITHMETIC SERIES MADE EASY!!******\n\nInput three numbers that follow a certain arithmetic sequence. \n");

     cd=userSequence(numsArray);//this variable stores the value from the function checkValidity() that is called inside the function userSequence.

     do
     {
         printf("\nInput a number n and find the nth term of your sequence: ");
         scanf("%d", &nth);
         switch(nth)
         {

            case 1:
                result=numsArray[0];
                break;
            case 2:
                result=numsArray[1];
                break;
            case 3:
                 result=numsArray[2];
                break;
            default:
                result= nthTerm(nth,cd,numsArray);
                break;
         }


         printf("\n\nIf n is the %d(st/nd/th/rd) term in the arithmetic series, then n = %d.\n\nWould you like to find any other term in the series? Reply with y for yes/n or any other value for no \n", nth,result );

         scanf(" %c",&askMore);

     }while(askMore =='y');

    printf("Thank you for using ASME. GoodBye!!!\n\n");


}

int userSequence( int nums[] ){
   for(int i=0;i<3;++i)
   {
       printf("\nChoice %d: ", i+1);
       scanf("%d",&nums[i]);
   }

    for(int j=0; j<3;++j)
    {
        if(j==0){
            printf("\nChecking series:  ");
        }
            printf("%d, ",nums[j]);
    }
    return checkValidity (nums);
}

int checkValidity(int nums[]){ //it takes an array of numbers from the previous function as an argument, and catches an error before the program crashes


    int d1,d2;//the common difference between two values

    d1=nums[1] - nums[0];
    d2=nums[2]-nums[1];


    if( d1 == d2 && nums[0]+ 2*d1== nums[2]) //find if if there's a common difference in the series
    {
        printf("\n...SUCCESS:\tIt is a valid arithmetic sequence with a common difference of: %d \n", d1);

            return d1; //return the common difference that will be used by the function nthTerm recursively
    }
    else{
        printf("\nERROR:\tplease input a valid arithmetic sequence!");

          userSequence(nums);//no value is being return here. The user is taken back to create another valid arithmetic sequence until the correct sequence is found

    }


}

int nthTerm( int nth, int commonDiff, int nums[]){ //arguments taken include: (the nth term provided by user, the common difference of function, and the array storing the number series)
    //int a= nums[3]; //
    /*
    since we have the three values already input, we can start adding the common difference d. The purpose of
    decreasing n up to 3(nth>2) is to ensure the function only runs (n-3)times because we already have the first 3 numbers provided by the user.

    hence the series will run recursively  without making more iterations than it should up to the nth value
     */
    if( nth>2 )
    {
        return commonDiff + nthTerm( nth-1, commonDiff, nums ); //calling the function recursively and adding the common difference to find consecutive terms of the series until the condition above is achieved
    }
    else{

        int lastIndex= sizeof(nums)/sizeof(int); //since the number of terms can change from time to time, we have to find the last digit in the array of series
        return nums[lastIndex]; //the nth term!!!

    }

}










