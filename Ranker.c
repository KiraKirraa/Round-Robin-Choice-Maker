// Ranker.c
// Kira Kowaltschuk
// 4/28/2026
// Simple command line round-robin program

// Includes
#include <stdio.h>
#include <stdlib.h>

// Defines
#define max_teams 200
#define max_name_length 60

// Entry point
int main(int argc, char* argv[]){
    // Input check
    if (argc < 2){
        printf("\nNo file specified\n");
        return -1;
    }
    printf("\nInput check passed\n");

    // File open attempt
    FILE* fptr = fopen(argv[1], "r");
    if (fptr == NULL){
        printf("\nCouldn't open file\n");
        return -1;
    }
    printf("\nOpened file\n");
    
    // Count teams
    int num_teams = 0;
    char buff[max_teams * max_name_length];
    while(fgets(buff + (num_teams * max_name_length), max_name_length, fptr) != NULL && num_teams < max_teams){
        num_teams++;
    }
    printf("\nRead %d teams\n", num_teams);

    // Print all teams
    printf("\nTeam list:\n");
    for(int i = 0; i < num_teams; i++){
        printf("Team %d: %s", i, buff + (i * max_name_length));
    }
    printf("\nPrinted all teams\n");
    
    // Setup array
    int* win_counts = calloc(num_teams, sizeof(int));
    printf("\nCreated blank array\n");

    // Run the round robin
    for(int i = 0; i < num_teams; i++){
        for(int j = i+1; j < num_teams; j++){
        make_choice:
            // Print choices
            printf("\nChoose 1 or 2:\n1: %s2: %s", buff + (i * max_name_length), buff + (j * max_name_length));

            // Get Input
            int input = 0;
            scanf("%d", &input);

            // Check input
            if(input == 1){
                win_counts[i]++;
            } 
            else if(input == 2){
                win_counts[j]++;
            } 
            else {
                printf("Invalid input\n");
                goto make_choice;
            }
        }
    }
    printf("\nChoice portion done\n");

    // Create auxillary array and find largest indexes
    int largest_indexes[num_teams];
    for(int i = 0; i < num_teams; i++){
        int largest_index = 0;
        int largest_value = win_counts[0];
        for(int j = 0; j < num_teams; j++){
            if(win_counts[j] > largest_value){
                largest_index = j;
                largest_value = win_counts[j];
            }
        }
        largest_indexes[i] = largest_index;
        // Invert index value so it can still be retreived without interfering in future searches
        win_counts[largest_index] = -1 * largest_value;
    }
    printf("\nSorted array created\n");

    // Print winners
    printf("\nWinners:\n");
    for(int i = 0; i < num_teams; i++){
        printf("%d: with %d wins, %s", i+1, (-1*win_counts[largest_indexes[i]]), buff + (largest_indexes[i] * max_name_length));
    }
    printf("\nWinners printed\n");

    // Cleanup
    free(win_counts);
    fclose(fptr);
    return 1;
}