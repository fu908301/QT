#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000
#define COL_LENGTH_S 10
#define COL_LENGTH_B 27
const int co_index_s[COL_LENGTH_S]={20,8,8,8,16,8,8,8,8,3};
const int co_index_b[COL_LENGTH_B]={20,8,8,16,10,16,10,16,10,16,10,16,10,16,10,16,10,16,10,16,10,16,10,15,10,15,10};
char line[LENGTH]={0};
void output_data_s(FILE *output);
void output_data_b(FILE *output);
void output_data_s(FILE *output)
{
    int i,j,location=0;  
    for(i=0;i<COL_LENGTH_S;i++)
    {
      for(j=0;j<co_index_s[i];j++)
      {
        if(line[location]==' ')
          fprintf(output,"");
        else if(line[location]!=' ') 
          fprintf(output,"%c",line[location]);
        location++;
      }
      if(i<COL_LENGTH_S-1)
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
void output_data_b(FILE *output)
{
  int i,j,location=0;
  for(i=0;i<COL_LENGTH_B;i++)
  {
    for(j=0;j<co_index_b[i];j++)
    {
      if(line[location]==' ')
        fprintf(output,"");
      else if(line[location]!=' ')
        fprintf(output,"%c",line[location]);
      location++;
    }
    if(i<COL_LENGTH_B-1)
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
    FILE *input3 = fopen("o20140102_080.ftm","r");
    FILE *input4 = fopen("f20140102_080.ftm","r");
    FILE *output = fopen("o20140102_020.csv","w");
    FILE *output2 = fopen("f20140102_020.csv","w");
    FILE *output3 = fopen("o20140102_080.csv","w");
    FILE *output4 = fopen("f20140102_080.csv","w");
    if(!input||!output||!input2||!output2||!input3||!output3||!input4||!output4)
    {
        printf("File not opened");
        exit(1);
    }
    printf("Changing o20140102_020.ftm......\n");
    while(fgets(line,LENGTH,input)!=NULL)
    {
      output_data_s(output);
    }
    printf("Successfully changed to o20140102_020.csv\n");
    printf("Changing f20140102_020.ftm......\n");
    while(fgets(line,LENGTH,input2)!=NULL)
    {
      output_data_s(output2);
    }
    printf("Successfully changed to f20140102_020.csv\n");
    printf("Changing o20140102_080.ftm......\n");
    while(fgets(line,LENGTH,input3)!=NULL)
    {
      output_data_b(output3);
    }
    printf("Successfully changed to o20140102_080.csv\n");
    printf("Changing f20140102_080.ftm......\n");
    while(fgets(line,LENGTH,input4)!=NULL)
    {
      output_data_b(output4);
    }
    printf("Successfully changed to f20140102_080.csv\n");
    fclose(input);
    fclose(input2);
    fclose(input3);
    fclose(input4);
    fclose(output);
    fclose(output2);
    fclose(output3);
    fclose(output4);
    return 0;
}
