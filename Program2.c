/*
 * Cprogram2.c
 *
 *  Created on: Feb 8, 2023
 *      Author: n063a207
 */

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int a = 0;
int occurences[50];

void combinations(int arr[],int score, int index){
	if(score < 0){
		return;
	}

	int count[5] = {0,0,0,0,0};
	char s1[20];
	char s2[20];
	char s3[20];
	char s4[20];
	char s5[20];



	if(score == 0){

		for (int i = 0; i < index; i++){
			if (arr[i] == 8){
				count[0]++;
			}
			if (arr[i] == 7){
				count[1]++;
			}
			if (arr[i] == 6){
				count[2]++;
			}
			if (arr[i] == 3){
				count[3]++;
			}
			if (arr[i] == 2){
				count[4]++;
			}
		}






		for (int i = 0; i < 5; i++){
					if (i == 0){
						sprintf(s1, "%d", count[0]);
					}
					if (i == 1){
						sprintf(s2, "%d", count[1]);
					}
					if (i == 2){
						sprintf(s3, "%d", count[2]);
					}
					if (i == 3){
						sprintf(s4, "%d", count[3]);
					}
					if (i == 4){
						sprintf(s5, "%d", count[4]);
					}

				}

		strcat(s1, s2);
		strcat(s1, s3);
		strcat(s1, s4);
		strcat(s1, s5);

		int num = atoi(s1);


		for(int i = 0; i < sizeof(occurences); i++){
			if (occurences[i] == num){
				return;
			}
		}

		printf("\n");

		occurences[a] = num;
		a++;

		for (int i =0; i < 5; i++){
			if(i == 0){
				printf("%d TD + 2pt,", count[i]);
			}
			if(i == 1){
				printf(" %d TD + FG,", count[i]);
			}
			if(i == 2){
				printf(" %d TD,", count[i]);
			}
			if(i == 3){
				printf(" %d 3pt FG,", count[i]);
			}
			if(i == 4){
				printf(" %d Safety", count[i]);
			}

		}










		return;
	}


	for(int i = 0; i < 5; i++){
		if (i == 0){
			arr[index] = 8;
			combinations(arr, score - 8, index + 1);
		}
		if (i == 1){
					arr[index] = 7;
					combinations(arr, score - 7, index + 1);
				}
		if (i == 2){
					arr[index] = 6;
					combinations(arr, score - 6, index + 1);
				}
		if (i == 3){
					arr[index] = 3;
					combinations(arr, score - 3, index + 1);
				}
		if (i == 4){
					arr[index] = 2;
					combinations(arr, score - 2, index + 1);
				}
	}

}


int main(){
	//int scores[5] = {8,7,6,3,2};
	int user  = 1;
	int combos[100];



	while (user != 0){
		printf("\n\nEnter 0 to STOP");
		printf("\n\nEnter the NFL score: ");
		scanf("%d", &user);
		combinations(combos, user, 0);


	}




	return 0;
}
