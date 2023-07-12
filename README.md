#Space Invaders
##**Video Demo:** https://www.youtube.com/watch?v=CXpm7179FjE&t=2&ab_channel=NickBelanger
#**Description:** This is a clone of the classic 1978 Taito / Atari Space Invaders. It was built in JavaScript and used HTML and CSS assets as well. This is a full one level clone of the original using modern sytax and modern JavaScript concepts. There are on screen bullet limiters, bullet controllers for both player and enemy charachters. The game will end if you destroy all enemies or if you are destroyed.

##**Movement:** Arrow keys (Left and Right for side to side movement), Spacebar to shoot. vertical movement is not allowed and both enemies and player will collide with the canvas walls.Each enemy will be a part of an array, and that array is completely customizeable. They all move as a single unit taking in the canvas as their limitation. Each enemy will have the same health (1 bullet per enemy)

###The player along with the enemies have their own unique look and sounds. Their is an on screen bullet limiter to maximize performance of the game.There is a seperate win screen for detroying all enemies and a game over screen displayed when the player is hit by an enemy bullet or enemy AI.

##**Purpose:**I made this game for my final project because space invaders was one of my favorite arcade games to play growing up and was the first sci-fi game I ever played. I'd like to add to this game by adding multiple levels, more difficult enemies, and various upgrades that drop along the way to increase fire rate and the spread of player bullets. This game was an excellent test of patience as I had to do a ton of de-bugging for various reasons, mostly syntax error and mispelling. With the basic framework of this game in mind I will definitely be creating more games, and hopefully I will find a career in the game development world. I'd love to work for Rockstar Games or Bethesda as those are my two favorite game production companies.


###FILE DESCRIPTIONS:
File: Images - contains the base images to be imported for enemies, and the player

File: Sounds - containes the base sounds for bullets, enemy death, player death

File: bullet.js - includes the properties and draw function for player and enemy bullets

File: BulletController.js - includes the bullet controller for enemies and player bullets along with the draw function and impact detection for destruction of player and enemies

File: Enemy.js - includes the draw function and basic setup details for the on screen enemies.

File: index.HTML - sets up the canvas and display for the game

File: index.js - includes primary functions along with all draw functions

File: MovingDirection.js - sets up movement for player and enemies including collision with canvas edge

File: Player.js - sets up player model