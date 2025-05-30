#include <stdio.h>

struct Question {
    char question[256];
    char options[4][100];
    char answer;
};

int main() {
    struct Question quiz[] = {
        {
            "What is the capital of France?",
            {"A) Berlin", "B) Madrid", "C) Paris", "D) London"},
            'C'
        },
        {
            "Which planet is known as the Red Planet?",
            {"A) Earth", "B) Mars", "C) Jupiter", "D) Venus"},
            'B'
        },
        {
            "Who wrote 'Romeo and Juliet'?",
            {"A) Charles Dickens", "B) Mark Twain", "C) William Shakespeare", "D) Jane Austen"},
            'C'
        }
    };

    int totalQuestions = sizeof(quiz) / sizeof(quiz[0]);
    char userAnswer;
    int score = 0;
    char userName[50];

    printf("=== Welcome to the Quiz Game ===\n\n");

    printf("Enter your name: ");
    fgets(userName, sizeof(userName), stdin);

    // Remove newline character from fgets input if present
    size_t len = 0;
    while (userName[len] != '\0') len++;
    if (len > 0 && userName[len - 1] == '\n') {
        userName[len - 1] = '\0';
    }

    for (int i = 0; i < totalQuestions; i++) {
        printf("Q%d: %s\n", i + 1, quiz[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", quiz[i].options[j]);
        }

        printf("Your answer (A, B, C, D): ");
        scanf(" %c", &userAnswer);

        if (userAnswer >= 'a' && userAnswer <= 'z') {
            userAnswer -= 32;
        }

        if (userAnswer == quiz[i].answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %c\n\n", quiz[i].answer);
        }
    }

    printf("Quiz Completed!\n");
    printf("Your final score: %d out of %d\n", score, totalQuestions);

    // Save result to file
    FILE *file = fopen("results.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file, "Name: %s, Score: %d out of %d\n", userName, score, totalQuestions);
    fclose(file);

    printf("Your result has been saved to results.txt\n");

    return 0;
}
