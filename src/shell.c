#include "../include/shell.h"
void launch_shell(int n)
{
	string ch = (string) malloc(200); // util.h
	int counter = 0;
	do
	{
			print("NIDOS (");
			print(int_to_string(n));
			print(")> ");
		    ch = readStr(); //memory_copy(readStr(), ch,100);
		    if(strEql(ch,"cmd"))
		    {
		            print("\nYou are allready in cmd. A new recursive shell is opened\n");
					launch_shell(n+1);
		    }
		    else if(strEql(ch,"clear"))
		    {
		            clearScreen();
		    }
		    else if(strEql(ch,"sum"))
		    {
		    	sum();
		    }
		    else if(strEql(ch,"exit"))
		    {
		    	print("\nGood Bye!\n");
		    }
		    else if(strEql(ch,"echo"))
		    {
		    	echo();
		    }
		    else if(strEql(ch,"sort"))
		    {
		    	sort();
		    }
		    else if(strEql(ch,"fibonaci"))
		    {
		    	fibonaci();
		    }
		    else if(strEql(ch,"gcd"))
		    {
		    	gcd();
		    }
		    else if(strEql(ch,"help"))
		    {
		    	help();
		    }
		    else if(strEql(ch,"color"))
		    {
		    	set_background_color();
		    }
		    else if(strEql(ch,"multiply"))
		    {
		    	multiply();
		    }
		    
		    
		    else
		    {
		            print("\nBad command!\n");
		            print("NIDOS> ");
		    } 
	} while (!strEql(ch,"exit"));
}



void sum()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	fill_array(arr,n);
	int s = sum_array(arr,n);
	print("Result: ");
	print(int_to_string(s));
	print("\n");
}
void echo()
{
	print("\n");
	string str = readStr();
	print("\n");
	print(str);
	print("\n");
}
void sort()
{
	int arr[100];
	print("\nArray size: ");
	int n = str_to_int(readStr());
	print("\n");
	fill_array(arr,n);
	print("Before sorting:\n");
	print_array(arr,n);
	print("\nOrdre: (1 for increassing/ 0 for decreassing): ");
	int ordre = str_to_int(readStr());
	insertion_sort(arr,n,ordre);
	print("\nAfter sorting:\n");
	print_array(arr,n);
}

void fill_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		print("ARR[");
		print(int_to_string(i));
		print("]: ");
		arr[i] = str_to_int(readStr());
		print("\n");
	}
}
void print_array(int arr[],int n)
{
	int i = 0;
	for (i = 0;i<n;i++)
	{
		/*print("ARR[");
		print(int_to_string(i));
		print("]: ");*/
		print(int_to_string(arr[i]));
		print("   ");
	}
	print("\n");
}
void insertion_sort(int arr[],int n,int ordre) //1 is increassing, 0 is descreassing
{
	int i = 0;
	for (i = 1;i<n;i++)
	{
		int aux = arr[i];
		int j = i;
		while((j > 0) && ((aux < arr[j-1]) && ordre ))
		{
			arr[j] = arr[j-1];
			j = j -1;
		}
		arr[j] = aux;
	}
}
int sum_array(int arr[],int n)
{
	int i = 0;
	int s = 0;
	for (i = 0;i<n;i++)
	{
		s += arr[i];
	}
	return s;
}
void fibonaci()
{
	print("\nHow many Elements: ");
	int n = str_to_int(readStr()); 
	print("\n");
	int i = 0;
	for(i =0;i<n;i++)
	{
		print("Fibo ");
		print(int_to_string(i));
		print(" : ");
		print(int_to_string(fibo(i)));
		print("\n");
	}
	
}
int fibo(int n)
{
	if(n <2)
		return 1;
	else 
		return fibo(n-1) + fibo(n-2);
}
int gcd_couple(int a,int b)
{
	if(b == 0)
		return 1;
	if(a % b ==0) 
		return b;
	else 
		return gcd_couple(b,a % b);
}
void gcd()
{
	print("\nHow many numbers: ");
	int n = str_to_int(readStr());
	int i =0;
	print("\n");
	int arr[n];
	int matrix[n][n];
	fill_array(arr,n);
	for (i = 0;i<n;i++)
	{
		matrix[0][i] = arr[i];
	}
	int j = 0;
	for (i =1;i<n;i++)
	{
		for (j=0;j<n-1;j++)
		{
			matrix[i][j] = gcd_couple(matrix[i-1][j] , matrix[i-1][j+1]);
		}
	}
	print("Result: ");
	print(int_to_string(matrix[n-1][0]));
	print("\n");
}
void print_matrix(int matrix[][100],int rows,int cols)
{
	int i =0;
	int j = 0;
	for (i = 0;i<rows;i++)
	{
		for(j =0;j<cols;j++)
		{
			print(int_to_string(matrix[i][j]));
			print("   ");
		}
		print("\n");
	}
}
void set_background_color()
{
	print("\nColor codes : ");
	print("\n0 : black");
	print_colored("\n1 : blue",1,0);   // screen.h
	print_colored("\n2 : green",2,0);
	print_colored("\n3 : cyan",3,0);
	print_colored("\n4 : red",4,0);
	print_colored("\n5 : purple",5,0);
	print_colored("\n6 : orange",6,0);
	print_colored("\n7 : grey",7,0);
	print_colored("\n8 : dark grey",8,0);
	print_colored("\n9 : blue light",9,0);
	print_colored("\n10 : green light",10,0);
	print_colored("\n11 : blue lighter",11,0);
	print_colored("\n12 : red light",12,0);
	print_colored("\n13 : rose",13,0);
	print_colored("\n14 : yellow",14,0);
	print_colored("\n15 : white",15,0);
	
	print("\n\n Text color ? : ");
	int text_color = str_to_int(readStr());
	print("\n\n Background color ? : ");
	int bg_color = str_to_int(readStr());
	set_screen_color(text_color,bg_color);
	clearScreen();
}

void multiply()
{
	print("\nNum 1 :");
	int num1 = str_to_int(readStr());
	print("\nNum 2 :");
	int num2 = str_to_int(readStr());
	print("\nResult : ");
	print(int_to_string(num1*num2)); // util.h
	print("\n");
}

void help()
{
	print("\ncmd       : Launch a new recursive Shell");
	print("\nclear     : Clears the screen");
	print("\nsum       : Computes the sum of n numbers");
	print("\necho      : Reprint a given text");
	print("\nsort      : Sorts a given n numbers");
	print("\nfibonaci  : Prints the first n numbers of fibonaci");
	print("\ngcd       : Computes the grand common divider of n given numbers");
	print("\nexit      : Quits the current shell");
	print("\ncolor     : Changes the colors of the terminal");
	
	print("\n\n");
}

