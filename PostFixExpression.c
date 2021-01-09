#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stack[1000];
int top = -1;


void push(int ele){

    top+=1;
    stack[top]  = ele;


}

void pop(){

     if(top<0){
         printf("%d",0);
         exit(0);
     }
   --top;
   
}


void eval(char* postfix){
  
  int ans=0,left,right;
  
  int temp = 0;
  while(*postfix!='\0')
  {
      if( (int)(*postfix) >=48 && (int)(*postfix)<=57 )
      {
          temp = 0;
          while(*postfix!=' '){
              temp = (temp*10) + (int)*postfix-48;
              
              postfix++;

          }
          
         
         push(temp);
      }
      else if (*postfix == '+' || *postfix == '-' || *postfix == '*' || *postfix == '/') {

      left = stack[top];
      pop();
      right = stack[top];
      pop();

      
      if(*postfix == '*'){ans = right * left;}
      else if(*postfix == '/'){ans = right / left;}
      else if(*postfix == '+'){ans = right + left;}
      else if(*postfix == '-'){ans = right - left;}

      push(ans);
  }

      
    
      postfix ++;
  }
  
 
  if(top == 0){
      printf("%d",stack[top]);}
  else{
      printf("%d",0);
  }
  
  


}

int main()
{
    int i =0;
    char arr[100];
    for(i=0;i<100;i++){
        scanf("%c",&arr[i]);
    }
    
    //a = arr;


    eval(arr);
    // printf("%s",postfix);

    return 0;
}