# ubisoftNXT-GameTest
Playing with the API for the Ubisoft Toronto NXT Showcase (http://toronto.ubisoft.com/nxtshowcase/).
(built in Visual Studio Community 2017)
<hr>

Changes to the default API:

-> New "Box", "Player", and "Goal" classes with initialization (x & y positions + length & width) & render methods. Boxes are 30 x 30 by default if no values are specified.

-> Player can be moved using W, S, A, D.

-> Collision detection: player object cannot pass through boxes.

-> Gamification: player can now win the game by reaching the defined goal zone of the level
