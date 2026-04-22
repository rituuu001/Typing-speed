
# Typing Speed Test

A fast and interactive typing speed test game built with C and Raylib. Test your typing skills, track your Words Per Minute (WPM), measure accuracy, and compete on the leaderboard.

## Demo

![Typing Speed Test Demo](.assets/demo.gif)


## Features

- **Real-time WPM Calculation** - See your typing speed update as you type
- **Accuracy Tracking** - Monitor your typing accuracy percentage
- **Live Feedback** - Instant visual feedback for correct/incorrect characters
- **Leaderboard System** - Track high scores and compete with yourself
- **Clean UI** - Simple, distraction-free interface built with Raylib
- **Cross-platform** - Works on Windows, Linux, and macOS

## Getting Started

### Prerequisites

- C compiler (GCC, Clang, or MSVC)
- Raylib library

### Installing Raylib

Download the pre-compiled binaries from [Raylib Releases](https://github.com/raysan5/raylib/releases)

### Building the Project

1. **Clone the repository**
```bash
git clone https://github.com/rituuu001/Typing-speed.git
cd Typing-speed
```

2. **Compile the project**
```bash
# Basic compilation
gcc src/*.c -o typing_speed -lraylib -lm

# Or with include path specified
gcc -I./include src/*.c -o typing_speed -lraylib -lm
```

3. **Run the game**
```bash
./typing_speed
```

## How to Play

1. Launch the application
2. Press any key to start the typing test
3. Type the displayed text as quickly and accurately as possible
4. See your WPM and accuracy update in real-time
5. Complete the test to see your final score
6. Check the leaderboard to see how you rank

## Project Structure

```
Typing-speed/
├── assets/          # Game assets (fonts, txt files, etc.)
├── include/         # Header files
├── src/             # Source code files
├── LICENSE          # MIT License
└── README.md        # Project documentation
```

## Technologies Used

- **Language**: C
- **Graphics Library**: [Raylib](https://www.raylib.com/) - Simple and easy-to-use library for game development
- **Build System**: GCC/Make

## Features in Detail

### WPM Calculation
The Words Per Minute (WPM) is calculated using the standard formula:
```
WPM = (Characters Typed / 5) / (Time in Minutes)
```

### Accuracy Measurement
Accuracy is calculated as:
```
Accuracy = (Correct Characters / Total Characters) × 100
``

## Acknowledgments

- [Raylib](https://www.raylib.com/) for the graphics library
- Inspired by typing test platforms like MonkeyType and TypeRacer

## License

This project is open-source and available under the MIT License.


