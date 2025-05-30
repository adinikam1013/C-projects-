# 🎉 Quiz Game in C with Score Saving

A simple console-based **Quiz Game** written in C that tests your knowledge with multiple-choice questions and saves your score to a file.

---

## Features

- Multiple-choice questions
- User inputs answers via keyboard (A, B, C, or D)
- Immediate feedback for each question (Correct/Wrong)
- Final score displayed at the end
- User’s name is recorded
- Scores saved/appended to `results.txt` file

---

## How to Run

### Requirements
- C compiler (e.g., GCC)

### Compile and Run

```bash
gcc quiz.c -o quiz
./quiz

How it Works
The program asks for your name.

It presents a series of multiple-choice questions.

You enter your answer for each question.

It tracks your score and shows if you were correct or wrong after each question.

After the quiz ends, your name and score are saved to results.txt.

You can view past scores by opening the results.txt file.

File Structure
bash
Copy
Edit
quiz.c          # Source code for the quiz game
results.txt     # Text file where user scores are saved (created automatically)
Future Improvements
Load questions from an external file

Add categories and difficulty levels

Implement timed questions

Show leaderboard from results.txt

Author
Aditya — Created as a beginner-friendly C programming project involving file handling.

