#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
double Unstack(double *stack,int *top);
int Stack(double *stack,int top,double x,int capacity);

int main(){
  int ArrSize;
  double *stack;
  int counter,top,order;
  double A,B,C;
  char operation;
  ArrSize=5;
  top=0;
  counter=0;

  stack=(double*)malloc(5*sizeof(double));   //Create 5 slots for queue

  do{
    printf("Type:\n1-To insert a value\n2-To declare the operation\n0-See result\n");   //User interaction
    scanf("%d",&order);
    counter++;
    if(counter==5){  //Control if more memory slots will be needed
      stack=(double*)realloc(stack,sizeof(double)*5);  //Allocate aditional memory 
      ArrSize+=5;  //Control the size of the queue
    }
    if(order==1){
      printf("Insert value\n");scanf("%lf",&A);
      top=Stack(stack,top,A,ArrSize);
    }
    if(order==2){
      printf("Insert the operation\n");
      fflush(stdin);
      scanf(" %c", &operation);
      A=Unstack(stack,&top);
      B=Unstack(stack,&top);
      if(operation=='+'){
        C=A+B;
      }else if(operation=='*'){
        C=A*B;
      }else if(operation=='/'){
        C=A/B;
      }else if(operation=='-'){
        C=A-B;
      }else if(operation=='^'){
        C=pow(A,B);
      }else{
        printf("Unknow operation, MB\n");
      }
      top=Stack(stack,top,C,ArrSize);
    }
  }while(order!=0);
  printf("Result=%.2lf",C);
  return 0;
}

int Stack(double *stack,int top,double x,int capacity){
  if(top < capacity){
    stack[top] = x;
    return top + 1;
  }else{
    printf("Unable to stack!\n");
    return top;
  }
}

double Unstack(double *stack,int *top){
  if(*top > 0){
    (*top)--;
    return stack[*top];
  }else{
    printf("Unable to unstack!\n");
    return 0;
  }
}