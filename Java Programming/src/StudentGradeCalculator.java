import java.util.Scanner;

public class StudentGradeCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of subjects: ");
        int numSubjects = scanner.nextInt();


        int totalMarks = 0;


        for (int i = 1; i <= numSubjects; i++) {
            System.out.print("Enter the marks for subject " + i + " (out of 100): ");
            int marks = scanner.nextInt();


            if (marks < 0 || marks > 100) {
                System.out.println("Invalid marks entered. Please enter marks between 0 and 100.");
                return;
            }

            totalMarks += marks;
        }


        double averagePercentage = (double) totalMarks / (numSubjects * 100) * 100;


        char letterGrade;
        if (averagePercentage >= 90) {
            letterGrade = 'A';
        } else if (averagePercentage >= 80) {
            letterGrade = 'B';
        } else if (averagePercentage >= 70) {
            letterGrade = 'C';
        } else if (averagePercentage >= 60) {
            letterGrade = 'D';
        } else {
            letterGrade = 'F';
        }

        // Displaying results
        System.out.println("Total Marks Obtained: " + totalMarks);
        System.out.println("Average Percentage: " + averagePercentage + "%");
        System.out.println("Grade: " + letterGrade);

        scanner.close();
    }
}

