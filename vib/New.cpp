#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<iostream>
using namespace std;

class stock
{
	public:
	char name[20];
	float price[2], volume;
	int date;
}; 
int main()
{
        stock st1[7][20];
	fstream X;
	FILE *fp1;
	int i=0 ,j=1, idummy;
	float fdummy; 
	X.open("data.dat",ios::out|ios::binary);
        fp1=fopen("2019-08-20-NSE-EQ.txt","r");
	for (i=0;i<20;i++){
	fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
	}
	fclose(fp1);
	//fp1=fopen("test_out","w");
 	for(i=0;i<20;i++){
 	//fprintf(fp1,"%s, %d, %f, %f, %f\n",st1[0][i].name,st1[0][i].date,st1[0][i].price[0],st1[0][i].price[1],st1[0][i].volume);	
	X.write((char*)&st1[0][i],sizeof(st1[0][i]));
	}
        fp1=fopen("2019-08-30-NSE-EQ.txt","r");
	j++;
        for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
        fp1=fopen("2019-08-22-NSE-EQ.txt","r");
	j++;
        for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
        fp1=fopen("2019-08-23-NSE-EQ.txt","r");
	j++;
        for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
        fp1=fopen("2019-08-26-NSE-EQ.txt","r");
	j++;
        for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
        fp1=fopen("2019-08-27-NSE-EQ.txt","r");
	j++;
        for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
        fp1=fopen("2019-08-28-NSE-EQ.txt","r");
        j++;
	for (i=0;i<20;i++){
        fscanf(fp1,"%s %d %f %f %f %f %f",st1[0][i].name,&idummy,&st1[0][i].price[0],&fdummy,&fdummy,&st1[0][i].price[1],&st1[0][i].volume);
        st1[0][i].date=j;
        }
        fclose(fp1);
        for(i=0;i<20;i++){
        X.write((char*)&st1[0][i],sizeof(st1[0][i]));
        }
	X.close();
}
