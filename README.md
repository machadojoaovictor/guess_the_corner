# GuessTheCorner (2D Square Animation with GLUT)

**GuessTheCorner** is a 2D simulation in C and OpenGL/GLUT that recreates the classic DVD logo screensaver. A square moves across the screen, and upon colliding with the edges, it changes color, direction, and slightly increases in size.

This project was developed as an assignment for the Basic Software Programming in C discipline, part of the Computer engineering at Estacio de Sá University.

---

## Table of Contents

- [Features](#features)
- [Technologies Used](#technologies-used)
- [How to Compile and Run](#how-to-compile-and-run)
- [Collaborators](#collaborators)
- [License](#license)

---

## Features

The project meets all the requirements specified in the assignment:

- **Continuous Movement**: The square moves in a constant linear trajectory, updated by the `update()` function.  
- **Collision and Bouncing**: The `checkCollision()` function detects collisions with all four window borders and appropriately inverts the velocity vector (`g_velocityX` or `g_velocityY`).  
- **Dynamic Color**: The `changeColor()` function is called on each collision, generating a new random RGB color for the square.  
- **Size Increase**: On each collision, the `g_currentSize` increases by 1% (`getIncrementAmount()`) of its original size.  
- **Size Limit**: The square stops growing when it reaches 120% (`getMaxSize()`) of its original size.  
- **GLUT Interface**: The application is rendered in a graphics window using the GLUT library.  
- **C Language**: The code is written entirely in C.  
- **Window Resizing**: Includes a `resize()` function that adjusts the projection (`gluOrtho2D`) to maintain the scene's aspect ratio, even if the window is resized.  

---

## Technologies Used

- **Language:** C  
- **Graphics Library:** OpenGL  
- **Windowing Toolkit:** GLUT (OpenGL Utility Toolkit)  

---

## How to Compile and Run

### Prerequisites

To compile this project, you will need:

- A C compiler (like GCC or MinGW for Windows).  
- The GLUT (or freeglut) library installed and configured in your environment.  

#### Windows (MinGW/MSYS2):

```bash
pacman -S mingw-w64-x86_64-freeglut
```

#### Linux (Debian/Ubuntu):
```bash
sudo apt-get install freeglut3-dev
```

### Compilation

Navigate to the project directory and run the following command (replace main.c with your .c file name):

#### Linux:
```bash
gcc main.c -o GuessTheCorner -lglut -lGLU -lGL
```

#### Windows (with MinGW):
```bash
gcc main.c -o GuessTheCorner.exe -lfreeglut -lopengl32 -lglu32
```

### Execution

After a successful compilation, an executable file will be generated.

#### Linux:
```bash
./GuessTheCorner
```

#### Windows:
```bash
./GuessTheCorner.exe
```

## Collaborators

A special thanks to everyone who contributed to this project.

<p>
  <a href="https://github.com/machadojoaovictor">
    <img src="https://github.com/machadojoaovictor.png" width="100" alt="João Victor Machado Profile Picture"/><br>
    <sub><b>João Victor Machado</b></sub>
  </a>
</p>


## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.











