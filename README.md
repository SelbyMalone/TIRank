# TIRank WIP
A ranking system made for my overcompetitve Twilight Imperium board game group to rank everyone using a modified Elo system (explained in depth later).  Written in CLion, a C++ Compiler is needed to run
# requirements
TIRank requires Jsoncpp to run
https://github.com/open-source-parsers/jsoncpp

## Work Done
  Currently, the system is able to rank a game of any number of players (input validation not present) from a score between 1-14 (not enforced, but hard coded around this number, entering numbers higher would give strange results).  Whilst not explicitly mentioned in the program, do note that the winner should always be entered first as the system gives a "winners bonus" to whoever is entered first.  This will be refined at a later date.  To run the program, user must enter the player count and then for each player they must enter:
- Player Name
- Player Race (In game faction)
- Player Rank
- Race Rank
- Game Score
  The program will then compare all players to eachother using the modified Elo system and display their old -> new rank and the adjustment aswell as the rank adjustment for the race they play (this feature wasn't added for competitveness, more for fun as it's cool to see how different races perform on average through your group)   
  ![image](https://user-images.githubusercontent.com/31752555/214205536-d4b039e6-134e-4b22-8411-8c56e438128a.png)
## Future Plans
- Input Validation and more intuitive UI is planned, even if it is still terminal based.  Also allowing users to adjust the score for a game (score from 1-10 points as per default Twilight Imperium rules rather then the optional 1-14 points rule that our group exclusively plays with)
- Automatic Rank updating, currently users must manually input the rank and race rank requires manually keeping track of scores on a spreadsheet or similar.  This process is time consuming and tedious so I plan to automate this process by adding another constructor to the Player class which only requires a name, race and score.  It will use the name to find the rank associated with that player/race from a file, if no name for that player is present in the file, add the player with a default rank of 1,000.  After the calculations are complete it will update the file for each players rank.  I would also like the file to display statistics for each player such as average score and number of games played. 
- Further refinement of rank calculations
# Elo
Elo is a system used for ranking two players in a 1v1 game.  Both players have a rank number, and when they play a game against eachother, the difference in their rank is used to determine an expected score for a game, which is a number between 0 and 1.  This is compared to the actual results of a game where a victory is 1, a loss is 0 and a draw is 0.5, depending on how much this number varies from the expected score, each player will have their rank increased/decreased.
## My Variation
The first variation I needed to make to my system was accounting for upto 8 players, the way I did this was by making each player compare their rank differenec to all other players to determine their "expected score", and then comparing that to the actual score difference between two players.  
![image](https://user-images.githubusercontent.com/31752555/214208073-219786d6-8407-407e-b51e-a237f9200fa3.png)  
This method was chosen as it scales with player count, scoring 14 points is harder in an 8 player game then a 4 player game, this method means the system performs a rank adjustment with the winner scoring higher then 7 other players in an 8 player game (and therefore increasing their rank by a larger amount)  
  
  The standard for Elo systems is a win(1)/draw(0.5)/loss(0) scoring system, my initial version of my Elo ranking system followed this by treating scoring above someone as a win (1), having the same score as them is a draw (0.5) and scoring below them is a loss(0) for each player.  However in one game a player won by a significant margin, and this was treated no differently then in most games where a player wins by 1 or 2 points.  The player group decided the system needed to not only take into account positions on the leaderboard, but score differences aswell.  Therefore instead of only using a win/draw/loss system, the system now takes into account the difference in score when comparing two players.  It does this by turning the score difference between two players onto a scale between 0 and 14.  For this, if Player A has 14 less points then player B, the score used for Elo will be 0.  If Player A has the same amount of points as player B, the score will be 0.5, and 14 more points will be a score of 1.
  
  With the system taking into account score differences a new issue arose.  The difference between 13 points and 14 points to win the game was much larger in difficulty then what the system considers a 1 point difference, to acccount for this, a winners bonus was added, when the player who wins the game is compared to everyone else, an extra comparison is made where the Elo score difference for the winner is always treated as if it was 1 (that is to say the system acts as if the winner beat everyone by 14 points for the winners bonus).  This comparison has an extremely small K-factor (multiplier on how much of an adjustment a result makes) but serves to be a small bonus ontop of the standard adjustments made for the winner. (as per usual with Elo calculations, each increase the winner gets from this result is decreased from the other players)
