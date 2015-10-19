#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000
const int co_index[10]={20,8,8,8,16,8,8,8,8,3};
char line[LENGTH]={0};
void output_data(FILE *output);
void output_data(FILE *output)
{
    int i,j,location=0;  
    for(i=0;i<10;i++)
    {
      for(j=0;j<co_index[i];j++)
      {
        if(line[location]==' ')
          fprintf(output,"");
        else if(line[location]!=' ') 
          fprintf(output,"%c",line[location]);
        location++;
      }
      if(i<9)
        fprintf(output,",");
     }
    if(strlen(line)>location+3)
      fprintf(output,",");
    for(i=location;i<strlen(line);i++)
    {
     if(line[i]==' ')
      continue;
     else 
     {
       fprintf(output,"%c",line[i]);
       if(line[i+1]==' ')
       fprintf(output,",");
      }     
    }
}
int main()
{
    FILE *input = fopen("o20140102_020.ftm","r");
    FILE *input2 = fopen("f20140102_020.ftm","r");
    FILE *output = fopen("o20140102_020.csv","w");
    FILE *output2 = fopen("f20140102_020.csv","w");
    if(!input||!output||!input2||!output2)
    {
        printf("File not opened");
        exit(1);
    }
    while(fgets(line,LENGTH,input)!=NULL)
    {
      output_data(output);
    }
    while(fgets(line,LENGTH,input2)!=NULL)
    {
      output_data(output2);
    }
    fclose(input);
    fclose(input2);
    fclose(output);
    fclose(output2);
    return 0;
}
