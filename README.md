# 🦯 Smart Cane for the Visually Impaired

A real-time assistive navigation system for visually impaired users that combines deep learning and distance sensing to detect and alert users of nearby obstacles.

---

## 📘 Project Summary

This project involves the development of a smart cane designed to improve mobility for visually impaired individuals. The system is built on a **Raspberry Pi 5**, utilizing **YOLO-based object detection** and **ultrasonic distance sensing** through **ROS2** to identify obstacles and measure their proximity in real time.

The system uses **sensor fusion** to combine camera input and distance measurements, triggering an automated feedback system that delivers **audio announcements** and **haptic vibration patterns** based on the confidence of the object classification and its distance.

---

## 🧠 Key Features

- Real-time **object detection** using YOLO
- **Ultrasonic distance sensing** for obstacle proximity
- **Sensor fusion** using ROS2
- **Dual-mode feedback**: audio and haptic
- **Rule-based decision pipeline** for intelligent alerts
- Embedded deployment on **Raspberry Pi 5**

---

## 🛠️ Technologies

- Raspberry Pi 5
- ROS2 (Robot Operating System)
- YOLO (You Only Look Once) for object detection
- Ultrasonic sensor (e.g., HC-SR04)
- Python
- Text-to-Speech and Vibration feedback modules

---

## 💻 System Flow

```plaintext
Camera + Ultrasonic Sensor → ROS2 Nodes → YOLO Detection + Distance → Rule-based Decision → Audio & Haptic Feedback
