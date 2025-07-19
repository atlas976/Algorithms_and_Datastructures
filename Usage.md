# Usage



- [Git skills](#git-skills)
- [Folder Structure](#folder-structure)
- [Clone/Download the repository](#clonedownload-the-repository)
- [Building in VSCode](#building-in-vscode)
- [To README](README.md)
---

### Git skills

If you are familiar with Git, you can skip this and jump [here](#folder-structure).  
If you do not know what git/github is or how to work with it, I can highly recommend the git-guide by Beeji. 
In order to properly use the repo and practice simple git workflows/operations, you'll have to at least learn the basics and then come back here.  
(You can also proceed without git knowledge, by just [cloning](#clonedownload-the-repository) the repository and using it only on your local machine, but i wouldn't recommend it.)   

The Guide can be found and downloaded on his website: https://beej.us/guide/ / https://beej.us/guide/bggit/

---

### Folder Structure

There are three different main folders in this repo. exercise_files(to_work_on), exercise_sheets(task_descriptions) and exercise_solutions.  

The way it is intended to work with them is as the following:    
Look in the exercise sheets in the ***exercise_sheets*** folder and solve the problems there. To do the programming parts use the already pre-made exercise folders and the included testing framework in the ***exercise_files*** folder. You will work on them in exercises/blatt{}.cpp file, but I recommend also taking a look into include/blatt1.h and main.cpp.  
If you are finished or have tried your best look in the ***exercise_solutions*** folder and check/rework/enhance/correct your own solutions.  
<br>

In the different exercises in the exercise_solutions folder there are three separate folders again: src_exercise{}, explanations/annotations, exercise{}_solution(tum).  

In the last one there are the official solutions from TUM for the sheets and the blatt{}.cpp file. These are the only solutions I can guarantee that they are right and so you should in general just use them for checking your exercises. Nevertheless I also included my explanations/annotations and my complete solution files in the src_exercise{} folder, they might help you somehow. 

---

### Clone/Download the repository

The exercises folders can be downloaded and easily worked on by opening them with VSCode/CLion, or any similar compiler you like or prefer. If you want to do simple git operations/workflows then fork the repo and push/pull to it and edit it yourself.  

**To download them and clone the repo:**
>enter in your terminal

```sh
git clone https://github.com/atlas976/Algorithms_and_Datastructures.git
cd Algorithms_and_Datastructures
# Open in your favorite IDE
```
---

### Building in VSCode

If you know what you are doing with your IDE, then this is absolutely natural to you and this is superfluous.  

I expect that you are from TUM (and study Electrical Engineering and Information Technology) and that you are unfamiliar with Programming IDEs and got not a clue of how to work with them. Well unfortunately I am also not going to explain you how to use one properly, but I at least can tell you what not to do.  

In VSCode do **NOT** use the small green build triangle in top right corner of the screen. It will only build the file you are currently working on and won't include your linked files. Install the CMake extension and build your program like below.  

CMake Tab:



Terminal:
>enter in VSCode terminal
```sh
#(In VS-Code use Cmake for building and run 
#TestMate C++ for faster experience) e.g.
mkdir -p build
cd build
cmake ..
make
./TestSuite #or(./Programmieraufgaben)
```
<br>

[TO THE TOP](#usage)