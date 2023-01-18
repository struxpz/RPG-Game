OOP C++ console RPG Game.

Basic features:
1)You can create a hero of one of four available classes : warior, mage, thief, berserker
2)You can save or load the game or create a new game
3)Once you create a new game and pick the class of the hero, you've got a few points to boost the statistics of your hero
4)The game data is saved to a file
5)You can go fighting with a monster of a chosen level
6)If you win a battle you earn a random amount of money, and experience depending on the difference of levels betveen the hero and monster
7)After you earn enough experience your hero will level up, and you will get 2 points to boost the stats of your hero
8)After winning a battle you have a chance of dropping an item

Apart from the basic features:
1) There is a shop with plenty of items, each giving unique bonus. At one time you can buy as much items as you want (if you have enough coins) 
2) During battle you can choose 1 of 2 attacking method, each attacking method requires a sufficient amount of energy
    if you do not have sufficient energy, you miss your turn. You restore 20 energy points each round.
3) If you are low on HP, or energy you can always use health or energy potions if you have previously dropped them or bought at the shop
    during one round you can use as many potions as you have.
4) I introduced Beer as a potion of luck :) It means you will have a better chance of dropping items, but at the cost of decreasing your stats
5) Monsters also have 2 attacking methods, they use them randomly, but be careful sometimes they hit realy hard
6) Also I tried to implement saving items which you wear (armour etc.) in a separate double linked list, so that you can take off what you wear
    but for some reason when I created a second double linked list object, the program didn't differetiate them.
    So when an item was to be saved in a list object handling inventory, it was also saved in the other list object- very strange.

 I hope you'll be having fun while trying the various features
