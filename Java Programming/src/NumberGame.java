import java.util.Scanner;
import java.util.Random;

public class NumberGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        int minRange = 1;
        int maxRange = 100;
        int maxAttempts = 7; 
        int rounds = 0;
        int totalScore = 0;

        System.out.println("Welcome to the Unique Number Challenge!");

        boolean playAgain = true;

        while (playAgain) {
            int secretNumber = random.nextInt(maxRange - minRange + 1) + minRange;
            int attempts = 0;
            int roundScore = maxAttempts;

            System.out.println("\nRound " + (rounds + 1));
            System.out.println("I've picked a secret number between " + minRange + " and " + maxRange);

            while (attempts < maxAttempts) {
                System.out.print("Take a guess: ");
                int userGuess = scanner.nextInt();
                attempts++;

                if (userGuess < minRange || userGuess > maxRange) {
                    System.out.println("Please guess a number between " + minRange + " and " + maxRange);
                } else if (userGuess < secretNumber) {
                    System.out.println("Try a higher number.");
                } else if (userGuess > secretNumber) {
                    System.out.println("Try a lower number.");
                } else {
                    System.out.println("Congratulations! You guessed the number in " + attempts + " attempts.");
                    totalScore += roundScore; // Update the total score
                    break;
                }

                if (attempts == maxAttempts) {
                    System.out.println("Sorry, you've reached the maximum number of attempts. The correct number was " + secretNumber);
                }

                roundScore--; // Deduct a point from the round score for each guess
            }

            rounds++;

            System.out.print("Want to try another round? (yes/no): ");
            String playAgainResponse = scanner.next().toLowerCase();
            playAgain = playAgainResponse.equals("yes");
        }

        System.out.println("Thank you for playing! Your total score is: " + totalScore);
        scanner.close();
    }
}
