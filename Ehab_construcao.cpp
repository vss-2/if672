#include <iostream>

using namespace std;

int main(){
	int input = 0;
	scanf("%i", &input);
	
	int saidaA, saidaB;

	if(input == 1 || input == 0){
		printf("-1");
	} else {
		for(int a = 1; a <= input; a++){
			for(int b = 1; b <= input; b++){
				if (saidaA*saidaB > input && saidaA/saidaB < input && saidaA%saidaB == 0){
					printf("%i %i", &saidaA, &saidaB);
					break;
				}
			}
			if (saidaA*saidaB > input && saidaA/saidaB < input && saidaA%saidaB == 0){
			    printf("%i %i", &saidaA, &saidaB);
			    break;
			}
		}
	}
  return 0;
}
