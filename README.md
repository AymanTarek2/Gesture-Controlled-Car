# Gesture-Controlled Car

## Overview

The Gesture-Controlled Car project involves developing a car that can be controlled using hand gestures. The system uses Arduino, with a gyroscope sensor in the master Arduino and wireless communication to translate gestures into motor commands.

## Features

- **Gesture Detection**: Gyroscope sensor in the master Arduino detects hand gestures.
- **Wireless Communication**: Communication between master and slave Arduino modules.
- **Motor Control**: Gesture data is translated into motor commands. Motors are connected to the slave Arduino through an H-bridge.

## Setup and Installation

1. **Hardware Assembly**:
   - **Master Arduino**: Connect the gyroscope sensor to the master Arduino.
   - **Slave Arduino**: Connect the motor drivers (via an H-bridge) to the slave Arduino.
   - **Wireless Modules**: Set up wireless communication between the master and slave Arduino modules.

2. **Upload Code**:
   - Open the Arduino IDE.
   - Load and upload the provided code to both the master and slave Arduino boards.

3. **Calibration and Testing**:
   - Power on the system and ensure all connections are correct.
   - Test gesture controls and adjust sensitivity if needed.

## Video Demonstration

Watch the gesture-controlled car in action here:

https://github.com/AymanTarek2/Gesture-Controlled-Car/assets/173570689/eaed9355-79d3-4852-9b09-2f29747c0b1e


