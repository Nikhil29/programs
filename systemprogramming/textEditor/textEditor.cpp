#include<bits/stdc++.h>
using namespace std;

// display the contens of a file
// returns -1 if doesnot exist
int displayFile(char filename[]){
	FILE *myFile=fopen(filename, "r");
	if(myFile==NULL)
		return -1;
	char c;
	while((c=fgetc(myFile))!=EOF){
		printf("%c",c);
	}
	fclose(myFile);
	return 0;
}

// create the file
// returns -1 if creation failed
int createFile(char filename[]){
	FILE *myFile=fopen(filename, "w");
	if(myFile==NULL)
		return -1;
	fclose(myFile);
	return 0;
}

// append the contents in file
int appendDataToFile(char filename[], char data[]){
	FILE *myFile=fopen(filename, "a");
	if(myFile==NULL)
		return -1;
	for(int i=0;data[i]!='\0';i++){
		fputc(data[i], myFile);
	}
	fclose(myFile);
	return 0;
}

// delete the contents in file
int deleteFile(char filename[]){
	int x=remove(filename);
	return x;
}

// get data to append
// stops the input data once :q is received
void inputDataToAppend(char data[]){
	printf("Enter the data.\nPress :q to stop entering data.\n");
	int flag1=0, flag2=0, top=0;
	char buffer;
	// for redundant new line character that gets received.
	scanf("%c",&buffer);
	while(top<1000){
		scanf("%c",&buffer);
		if(buffer==':'){
			flag1=1;
		}
		else if(buffer=='q'){
			flag2=1;
		}
		else{
			flag1=0;
			flag2=0;
		}
		if(flag1==1&&flag2==1){
			data[top-1]='\0';
			break;
		}
		data[top]=buffer;
		top++;
	}
	if(top==1000){
		printf("Buffer Overflow\n");
	}
}
int main(int argc, char const *argv[])
{
	char filename[100],data[1000];
	int operation,err;
	while(1){
		system("sleep 2");
		system("clear");
		printf("1 -> Create File\n2 -> Display File\n3 -> Append Data to File\n4 -> Delete File\n5 -> Exit\n");
		printf("Choose any operation: ");
		scanf("%d",&operation);
		switch(operation){
			case 1:
				printf("Enter the File Name: ");
				scanf("%s",filename);
				err=createFile(filename);
				if(err==-1)
					printf("File cannot be created\n");
				else
					printf("File created successfully\n");
				break;
			case 2:
				printf("Enter the File Name: ");
				scanf("%s",filename);
				err=displayFile(filename);
				if(err==-1)
					printf("File cannot be displayed\n");
				break;
			case 3:
				printf("Enter the File Name: ");
				scanf("%s",filename);
				inputDataToAppend(data);
				appendDataToFile(filename, data);
				printf("\nData appended to File: %s\n",filename);
				break;
			case 4:
				printf("Enter the File Name: ");
				scanf("%s",filename);
				err=deleteFile(filename);
				if(err==-1)
					printf("File cannot be deleted\n");
				else
					printf("File deleted successfully\n");
				break;
			case 5:
				printf("Exiting.....\n");
				exit(0);
				break;
			default:
				printf("Enter a Valid Option\n");
		}
	}

	return 0;
}