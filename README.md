# pizza-eating-competition-predictor

Overview:

This project involves creating a Windows-based console C++ object-oriented program named "Pizza Eating Winner (PEW) Predictor." The task, set by SuperProgram Pte Ltd, where I am a part of the AI programming team, aims to generate interest and awareness for a National Pizza Eating Competition. The PEW Predictor, a menu-driven application, predicts the outcomes of the competition in various rounds, from quarterfinalists to the ultimate winner. Incorporating an admin feature for management purposes to simulate and manage a competitive event dynamically.

Approach: 

The approach involved designing a modular, object-oriented structure in C++ for efficient management and simulation of the pizza eating competition. Each class and function was meticulously crafted to encapsulate specific functionalities and data, enabling easy maintenance and scalability.



Initial Designs:

![image](https://github.com/yashwantvadapalli/pizza-eating-competition-predictor/assets/65916909/722f0c95-b956-489e-88c6-8b0c2ac53234)
 
The initial planning to structure the pewPredictor program was a bit of a challenge. At the center of my design is the pewPredictor class, which is like the brain of the operation. It's holding onto a list of all the teams that are competing in this pizza eating contest and it's also keeping track of which round of the competition we're in.

Then there's this Admin part that I'm putting together, which is going to make sure that only someone who's supposed to make changes can actually do it. They'll need the right username and password to get anywhere. Once they're in, they can use the admin menu to do things like changing team details or looking at logs, which is pretty important for keeping everything in check.

I'm also setting up a Menu class that's taking care of showing the user what options they have and letting them pick what they want to do. It's the part of the program that people will see and interact with, like choosing to make a new team or see who's already in the running.

The Team class is where I'm storing all the info about each team, like who's on the team and how they're doing in the competition. I'm adding functions to this class so I can update results and change team members if I need to.

Lastly, I'm working on the FileHandling class, which is all about saving stuff to a file and then being able to get it back when I start the program up again. It's important because I don't want to lose all the information about the teams and the competition results just because I turn off the program. Putting all these pieces together, I'm building a program that can predict who's going to win the pizza eating contest by letting an admin enter details and then doing some number crunching to figure out the winners. It's all about keeping things organized and making sure that everything runs smoothly from start to finish. 



Final Design:



![image](https://github.com/yashwantvadapalli/pizza-eating-competition-predictor/assets/65916909/e596dd95-be8c-4bd8-a623-fbb7f6363003)

In the final design above, I have changed the design in such a way that the relationships are indicated as follows:
•	Menu contains an instance of teamManager.
•	Menu uses pewPredictor.
•	adminMenu manages teamManager.

The evolution of the class diagram from the initial design to the final one, some key changes that I've made to streamline the structure of my PEW Predictor application. In the beginning, I had a FileHandling class, but now I'm seeing that its functionality has been absorbed by the teamManager class. This makes sense, as it's the teamManager that's directly dealing with the list of teams, so it's also handling the reading from and writing to the "Teams.txt" file.

Similarly, the PredictionAlgo class that was once separate is now part of the pewPredictor class. By integrating this, I'm keeping the prediction logic closely tied with the main class that runs the prediction process. The pewPredictor class is using the team list that the teamManager reads from the file to make its predictions, which I'm guessing involves predicting the quarterfinalists, semifinalists, and ultimately the winner of the contest.

Now, about the adminMenu, it's clearly the interface for the administrative side of things. It's relying on teamManager to manipulate the team data. I'm giving it methods like createTeam, deleteTeam, and others, so the admin has full control over the teams in the competition. And it looks like the adminMenu can also write changes back to the file, which I'm thinking is important to keep the team data consistent and up-to-date.
The Menu class is something I'm using for user interaction. It's holding a reference to both the teamManager and pewPredictor. So, when I'm navigating the menu, I'm actually interfacing with both the team management and the prediction functionalities. I'm noticing that the Menu class contains methods for displaying different menus and handling the choices that I as a user make.

In all, these changes are making my application more cohesive and better organized. The final design is cleaner, with each class having a distinct role. teamManager is a central hub for team data, pewPredictor is the core for prediction logic, adminMenu manages administrative tasks, and Menu provides a user interface for interaction. By merging related functionalities, I'm reducing complexity and potentially making the code easier to maintain.


Code Description:

•	adminMenu Class: Administers team management functionalities. It includes methods for creating, reading, updating, and deleting teams. The adminMenu::adminMenu() constructor initializes with a reference to a teamManager object, ensuring synchronized team data management.
•	teamManager Class: Manages the list of teams. teamManager::readTeamsFromFile() reads teams from a file, and teamManager::displayTeams() displays them in a formatted table.
•	pewPredictor Class: Handles the prediction logic for the competition. It uses randomization to predict quarterfinalists, semifinalists, finalists, and the winner.
•	Menu Class: Serves as the user interface, facilitating interaction with the predictor and admin functions. Key methods include displaying menus and invoking prediction and admin functionalities.


Summary:

Initially, the design featured several distinct components, including the pewPredictor for data handling and competition tracking, and an admin section for secure data modification. A user-friendly Menu class allows for various interactions, such as adding teams or viewing competitors. There was also a Team class for storing team details and managing updates to team rosters, and a FileHandling class for data persistence.
As the project progressed, it was refined by combining related functionalities, such as merging FileHandling into the teamManager class, which simplified data management.
Now, the adminMenu manages team data with CRUD capabilities and updates the team list in a "Teams.txt" file, while the Menu class integrates user interaction with team management and prediction operations.
In short, the PEW Predictor is an efficient and user-centric application for event simulation and management, reflective of solid programming principles and careful planning.


