# ESP32 FreeRTOS – Five LED Multitasking System

project link: https://wokwi.com/projects/471791257082515457

## 📌 Project Overview

This project demonstrates multitasking using **FreeRTOS on an ESP32**.

Five independent FreeRTOS tasks are created to control five LEDs. Each LED operates at a different timing interval, demonstrating how FreeRTOS can schedule multiple tasks independently on a microcontroller.

## 🎯 Objectives

* Understand FreeRTOS task creation
* Implement multiple independent tasks
* Demonstrate multitasking on ESP32
* Use `xTaskCreate()` to create tasks
* Use `vTaskDelay()` for non-blocking task delays
* Control multiple GPIO outputs independently
* Understand the role of the FreeRTOS scheduler

## 🔧 Hardware

* ESP32 development board
* Red LED
* Green LED
* Blue LED
* Yellow LED
* Purple LED
* 220Ω/330Ω resistors
* Jumper wires
* Breadboard

## 💡 LED Task Configuration

| Task   | LED    |    GPIO | Toggle Interval |
| ------ | ------ | ------: | --------------: |
| Task 1 | Red    |  GPIO 5 |         5000 ms |
| Task 2 | Green  |  GPIO 2 |         4000 ms |
| Task 3 | Blue   |  GPIO 4 |         3000 ms |
| Task 4 | Yellow | GPIO 18 |         2000 ms |
| Task 5 | Purple | GPIO 19 |         1000 ms |

## ⚙️ Working Principle

Each LED is controlled by an independent FreeRTOS task.

The task changes the LED state and then calls:

```c
vTaskDelay(pdMS_TO_TICKS(interval));
```

During this delay, the current task enters the blocked state and the FreeRTOS scheduler can execute other tasks.

Therefore, all five LEDs can operate independently without one LED task blocking the others.

## 🧠 FreeRTOS Concepts Demonstrated

### 1. Task Creation

The project uses:

```c
xTaskCreate()
```

to create five independent tasks.

### 2. Task Parameters

Each task receives a configuration structure containing:

* GPIO number
* Timing interval
* Task name

### 3. Task Delay

The project uses:

```c
vTaskDelay()
```

instead of a conventional blocking delay.

### 4. Multitasking

Five LED tasks execute under the control of the FreeRTOS scheduler.

## 📊 Expected Behaviour

The red LED changes state every 5 seconds.

The green LED changes state every 4 seconds.

The blue LED changes state every 3 seconds.

The yellow LED changes state every 2 seconds.

The purple LED changes state every 1 second.

The different timing patterns demonstrate independent task execution.

## 🚀 Future Improvements

Possible extensions include:

* Different task priorities
* Push-button controlled LED tasks
* Task status monitoring
* UART task monitoring
* FreeRTOS queues
* Semaphores
* Software timers
* OLED display showing task status

## 👨‍💻 Technologies

* ESP32
* FreeRTOS
* ESP-IDF
* C
* GPIO
* Wokwi (optional simulation)

## 📚 Learning Outcome

This project provides practical experience with RTOS-based embedded programming and demonstrates how multiple independent tasks can be scheduled efficiently on an ESP32.
