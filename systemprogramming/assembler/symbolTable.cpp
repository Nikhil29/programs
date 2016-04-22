// symbol table functions like insert, update, delete, display
// symbol table format label, value, location, length

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define SYMBOLTABLESIZE 1000

typedef struct symbol{
	char label;
	int value;
	unsigned int location, length;
}symbol;

// inserts the symbol in the symbol table
// returns 0 on success and -1 on faailure
int insertSymbol(symbol symbolTable[], int *top, char label, int value, unsigned int location, unsigned int length){
	if(*top+1==SYMBOLTABLESIZE)
		return -1;
	*top=(*top)+1;
	symbolTable[*top].label=label;
	symbolTable[*top].value=value;
	symbolTable[*top].location=location;
	symbolTable[*top].length=length;
	return 0;
}

// displays the symbol properties
// returns -1 if symbol is not present in the table
int displaySymbol(symbol symbolTable[], int *top, char label){
	for(int i=0;i<=*top;i++){
		if(symbolTable[i].label==label){
			printf("Symbol: %c %d %u %u\n", symbolTable[i].label, symbolTable[i].value, symbolTable[i].location, symbolTable[i].length);
			return 0;
		}
	}
	return -1;
}

// delete the symbol
// returns -1 if symbol is not present in the table
int deleteSymbol(symbol symbolTable[], int *top, char label){
	for(int i=0;i<=*top;i++){
		if(symbolTable[i].label==label){
			for(int j=i+1;j<=*top;j++){
				symbolTable[j-1].label=symbolTable[j].label;
				symbolTable[j-1].value=symbolTable[j].value;
				symbolTable[j-1].location=symbolTable[j].location;
				symbolTable[j-1].length=symbolTable[j].length;
			}
			*top=(*top)-1;
			return 0;
		}
	}
	return -1;
}

// updates the location of a symbol
// returns -1 if symbol not found in the table
int updateLocation(symbol symbolTable[], int *top, char label, unsigned int newLocation){
	for(int i=0;i<=*top;i++){
		if(symbolTable[i].label==label){
			symbolTable[i].location=newLocation;
			return 0;
		}
	}
	return -1;
} 

// updates the value of a symbol
// returns -1 if symbol not found in the table
int updateValue(symbol symbolTable[], int *top, char label, int newValue){
	for(int i=0;i<=*top;i++){
		if(symbolTable[i].label==label){
			symbolTable[i].value=newValue;
			return 0;
		}
	}
	return -1;
}

// updates the value and location of a symbol
// returns -1 if symbol not found in the table
int updateValueAndLocation(symbol symbolTable[], int *top, char label, int newValue, int newLocation){
	for(int i=0;i<=*top;i++){
		if(symbolTable[i].label==label){
			symbolTable[i].value=newValue;
			symbolTable[i].location=newLocation;
			return 0;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	symbol symbolTable[SYMBOLTABLESIZE];
	int top=-1, op, value, temp;
	unsigned int location, length;
	char label;

	while(1){
		// system("clear");
		printf("\nChoose an operation for Symbol Table from the below listed menu:\n");
		printf("1. Insert\n");
		printf("2. Display\n");
		printf("3. Update Value\n");
		printf("4. Update Location\n");
		printf("5. Update Value and Location\n");
		printf("6. Delete Symbol\n");
		cin>>op;
		switch(op){
			case 1:
				printf("Enter the label, value, location, length\n");
				cin>>label>>value>>location>>length;
				temp=insertSymbol(symbolTable, &top, label, value, location, length);
				break;
			case 2:
				printf("Enter the label: ");
				cin>>label;
				displaySymbol(symbolTable, &top, label);
				break;
			case 3:
				printf("Enter the label and value\n");
				cin>>label>>value;
				updateValue(symbolTable, &top, label, value);
				break;
			case 4:
				printf("Enter the label and location\n");
				cin>>label>>location;
				updateLocation(symbolTable, &top, label, location);
				break;
			case 5:
				cout<<"Enter the label and value and location\n";
				cin>>label>>value>>location;
				updateValueAndLocation(symbolTable, &top, label, value, location);
				break;
			case 6:
				cout<<"Enter the label to delete: ";
				cin>>label;
				deleteSymbol(symbolTable, &top, label);
				break;
			default:
				cout<<"Enter a valid option.\n";
		}
		// sleep(2);
	}
	return 0;
}