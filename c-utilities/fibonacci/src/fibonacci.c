/*
*****************************************************************************************
*
*Copyright (c) 2023, Jeferson Souza (thejefecomp) - thejefecomp@neartword.com
*All rights reserved.
*
*Filename: fibonacci.c
*
*
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions are met:
*
** Redistributions of source code must retain the above copyright notice, this
*  list of conditions and the following disclaimer.
*
** Redistributions in binary form must reproduce the above copyright notice,
*  this list of conditions and the following disclaimer in the documentation
*  and/or other materials provided with the distribution.
*
** Neither the name of my-courses nor the names of its
*  contributors may be used to endorse or promote products derived from
*  this software without specific prior written permission.

*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************************
*/

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

long fibonacci_it(int n)
{
	long result[3] = {1L,1L,1L};
	
	for(int i = n; i >= 2; --i)
	{
	  result[2] = result[0] + result[1];
	  result[0] = result[1];
	  result[1] = result[2];
	}	

	return result[2];
}

long fibonacci_rec(int n)
{
	if(n <= 1)
		return 1L;

	return fibonacci_rec(n-1) + fibonacci_rec(n-2);
}

char * generate_str_ordinal(char**argv,int position, int str_number_pos)
{
	char *str_ordinal = "th\0";
	
	int ordinal_number = position > 100 ? atoi(argv[str_number_pos]+(strlen(argv[str_number_pos])-2)) : position;
	
	if(ordinal_number < 10 || ordinal_number > 20)
		switch(ordinal_number%10)
		{		
			case 1:
				str_ordinal = "st\0";
				break;
			case 2: 
				str_ordinal = "nd\0";
				break;
			case 3:
				str_ordinal = "rd\0";
				break;
			default:
				str_ordinal = "th\0";
		}
	
	return str_ordinal;	
}

void calculate_and_print_fibonacci(bool is_it, char **argv)
{	
	int n = 0;
	long result = 0;
	int str_number_pos = is_it ? 2 : 1;
	
	n = atoi(argv[str_number_pos]);

	if(n < 0)
		printf("The informed position the user wants the value of on the Fibonacci's sequence must be greater than or equal to zero (0).\n");
	else
	{
		result = is_it ? fibonacci_it(n) : fibonacci_rec(n);

		printf("The %d%s position of the Fibonacci's sequence is: %ld\n",n,generate_str_ordinal(argv,n,str_number_pos),result);
	}
}

bool check_it_option(int argc, char **argv)
{
	char it_opt[4] = "-it\0";

	if(argc == 3 && strcmp(argv[1],it_opt) == 0)
		return true;
	
	return false;	
}

bool print_usage(int argc)
{
	if(argc < 2 || argc > 3) 
	{

		const int nr_messages = 5;

		char *usage_messages[nr_messages] = {"USAGE: fibonacci [-it] N\n\n",\
					 	      "OPTIONS:\n\n-it indicates the use of an iterative Fibonacci's implementation to perform the calculation.\n\n",\
					 	      "N represents the nth position of the Fibonacci's sequence that a user wants to obtain the value of.\n\n",\
					 	      "If the -it option is not provided, a recursive Fibonacci's implementation will be used to perform the calculation instead.\n\n",\
					 	      "Copyright (c) 2023, Jeferson Souza (thejefecomp) - thejefecomp@neartword.com\nAll rights reserved.\n\n"};		
		
		for(int i = 0; i < nr_messages; i++)
			printf("%s",usage_messages[i]);

		return true;
	}

	return false;	
}

int main(int argc, char** argv)
{	
	if(print_usage(argc))
		return -1;
	
	calculate_and_print_fibonacci(check_it_option(argc,argv),argv);
	
	return 0;
}
