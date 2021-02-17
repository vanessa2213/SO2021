#include <stdio.h>


/*int main (int numarg, char **argv){
	printf("Hello world %s\n", argv[1]);
	
	return 0;
}*/

int main (int numarg, char **argv){
	
	for(int i = 1; i<numarg; i++){
		printf("Hello world %s\n", argv[i]);
	}
}