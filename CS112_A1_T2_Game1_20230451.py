#File:CS112_A1_T2-Game1_20230451
#Purpose:The "100 Game" is a basic game for two players. They input numbers from 1 to 10 to reach a total score of 100. The game ends when a player hits 100 points.
#Author:Noran Mohamed Mokhtar
#ID:20230451
def game1():
    # Initial setup
    print("100 Game")
    print("Initial score = 0")
    score = 0

    # Main game loop
    while True:
        # Iterate over players (1 and 2)
        for player in [1, 2]:
            # Get input from the current player
            input_number = input(f"Player {player}, enter a number (1-10): ")

            # Validate input to ensure it is a digit and within the allowed range
            while not input_number.isdigit() or not 1 <= int(input_number) <= 10:
                print("Invalid input. Please enter a valid number (1-10).")
                input_number = input(f"Player {player}, enter a number (1-10): ")

            # Update the score based on the player's input
            score += int(input_number)

            # Check if the current player wins
            if score == 100:
                print("Score reached 100.")
                print(f"Player {player} wins. Congrats!")
                return
            # Check if the score exceeds 100
            elif score > 100:
                print(f"Score exceeds 100. Player {player}, try again to ensure that the score doesn't exceed 100.")

                # Adjust the score to be less than or equal to 100
                while score > 100:
                    # Subtract the last input to correct the score
                    score -= int(input_number)
                    # Get a new input from the player
                    input_number = input(f"Player {player}, enter a number (1-10): ")

                    # Validate the new input
                    while not input_number.isdigit() or not 1 <= int(input_number) <= 10:
                        print("Invalid input. Please enter a valid number (1-10).")
                        input_number = input(f"Player {player}, enter a number (1-10): ")

                    # Add the adjusted input to the score
                    score += int(input_number)

                # Check if the player wins after adjustment
                if score == 100:
                    print("Score reached 100.")
                    print(f"Player {player} wins. Congrats!")
                    return
            else:
                # Print the score if it doesn't exceed 100
                print("Score:", score)

# Run the game
game1()
