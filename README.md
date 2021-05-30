T10_G11

GROUP MEMBERS:
- student_1 Gonçalo Pinto
- student_2 Guilherme Magalhães
- student_3 Pedro Cerejeira

ADDITIONAL SPECIFICATIONS:
- In the Leaderboard option from the menu, the player can input 0 to return to the menu (like in game)
- We use default constructors, that just create the objects and fill the atributes with irrelevant values.
This is done so we can declare game and leaderboard objects before the main flow of the program and use only
one object of each.
- We added an id atribute to robots as said in specifications but never used it

PROGRAM DEVELOPMENT STATE: Completed
- Create a simple menu (Get the input from the user) [DONE]
- Create some validation functions to make sure the input is valid every time the program needs an input [DONE]
- Create a function that outptus rules [DONE]
- Create simple classes for each char in the maze [DONE]
- Create a game class that:
	- reads and interprets the contents of the maze file [DONE]
	- updates the game loop until player wins, quits or loses(player movement, etc) [DONE]
	- gives a score when a player that wins [DONE]	 
- Create a leaderboard that both prints and updates the winners list [DONE]
- Make sure every time the user enter "Ctrl+Z" he exits the game [DONE]
MAIN DIFFICULTIES:
- dealing with objects with the same names (we ended up only using one game and one leaderboard object)
- making default constructors look presentable
- keeping our "code choices" consistent
