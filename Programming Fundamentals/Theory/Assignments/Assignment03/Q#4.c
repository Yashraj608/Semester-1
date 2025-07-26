#include<stdio.h>
#include<stdlib.h>

struct Employee {
	int *ratings;
	int totalScore;
};

void inputRatings(int **ratings, int NumEmployees, int numPeriods) {
	int i, j;
	for(i = 0; i < NumEmployees; i++) {
		printf("\nEnter the ratings for Employee %d", i + 1);
		for(j = 0; j < numPeriods; j++) {
			printf("\nEnter the rating for period %d (1-10): ", j + 1);
		retry:
			scanf("%d", &ratings[i][j]);
			if(ratings[i][j] < 1 || ratings[i][j] > 10) {
				printf("\nInvalid input. Enter a valid rating: ");
				goto retry;
			}
		}
	}
}

void showPerformance(int **ratings, int NumEmployees, int numPeriods) {
	int i, j;
	printf("\nEmployee Performance Ratings:\n");
	for(i = 0; i < NumEmployees; i++) {
		printf("Employee %d: ", i + 1);
		for(j = 0; j < numPeriods; j++) {
			printf("%d ", ratings[i][j]);
		}
		printf("\n");
	}
}

int bestEmployee(int **ratings, int NumEmployees, int numPeriods) {
	int bestEmp = 0, i, j;
	float highestAvg = 0.0;
	for(i = 0; i < NumEmployees; i++) {
		int total = 0;
		for(j = 0; j < numPeriods; j++) {
			total += ratings[i][j];
		}
		float avg = (float)total / numPeriods;
		if(avg > highestAvg) {
			highestAvg = avg;
			bestEmp = i;
		}
	}
	return bestEmp;
}

int topRatedPeriod(int **ratings, int NumEmployees, int numPeriods) {
	int topPeriod = 0, i, j;
	float highestAvg = 0.0;
	for(j = 0; j < numPeriods; j++) {
		int total = 0;
		for(i = 0; i < NumEmployees; i++) {
			total += ratings[i][j];
		}
		float avg = (float)total / NumEmployees;
		if(avg > highestAvg) {
			highestAvg = avg;
			topPeriod = j;
		}
	}
	return topPeriod;
}

int worstEmployee(int **ratings, int NumEmployees, int numPeriods) {
	int worstEmp = 0, i, j;
	float lowestAvg = 11.0;
	for(i = 0; i < NumEmployees; i++) {
		int total = 0;
		for(j = 0; j < numPeriods; j++) {
			total += ratings[i][j];
		}
		float avg = (float)total / numPeriods;
		if(avg < lowestAvg) {
			lowestAvg = avg;
			worstEmp = i;
		}
	}
	return worstEmp;
}

int main() {
	int NumEmployees, numPeriods, i;
	printf("Enter Number of Employees: ");
	scanf("%d", &NumEmployees);
	printf("Enter Number of Periods: ");
	scanf("%d", &numPeriods);

	struct Employee emp[1];
	int **ratings = (int**)malloc(NumEmployees * sizeof(int*));
	for(i = 0; i < NumEmployees; i++) {
		ratings[i] = (int*)malloc(numPeriods * sizeof(int));
		if(ratings[i] == NULL) {
			printf("Memory allocation failed\n");
		}
	}

	inputRatings(ratings, NumEmployees, numPeriods);
	showPerformance(ratings, NumEmployees, numPeriods);

	printf("\nEmployee of the Year is %d", bestEmployee(ratings, NumEmployees, numPeriods) + 1);
	printf("\nThe Period with the highest average rating is %d", topRatedPeriod(ratings, NumEmployees, numPeriods) + 1);
	printf("\nThe Worst Employee of the Year is %d", worstEmployee(ratings, NumEmployees, numPeriods) + 1);

	for(i = 0; i < NumEmployees; i++) {
		free(ratings[i]);
	}
	free(ratings);

	return 0;
}

