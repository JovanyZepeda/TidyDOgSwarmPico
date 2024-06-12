# Raspberry Pico Project
This repository contains an empty 'initial' project for Pi Pico using 
- VS Code dev containers
- openOCD and GDB-Multiarch for step-through debugging
- tio for serial print statement reading from pricoprobe

---
## Debugging Options
- **Using CMake Build**: Ensure that the ```ms-vscode.cmake-tools``` extension is installed and run the ```CMake:build``` task from the command palette (```ctrl+shift+b```).

- **List to Print Statement**: To listen to the picoprobe serial print statements, run the task ```Attach to Picoprobe Serial``` when the picoprobe is connected with USB to the dev container. 

