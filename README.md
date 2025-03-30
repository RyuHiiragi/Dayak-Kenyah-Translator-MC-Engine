# Dayak Kenyah Translator & MC Engine

## Project Description

**Dayak Kenyah Translator & MC Engine** is a web application running on an ESP32 that translates text between Indonesian and Dayak Kenyah. The project integrates two core features:

1. **Translator:**  
   It converts input text in real-time between Indonesian and Dayak Kenyah using a lightweight engine based on tokenization and partial matching. This approach supports multi-word phrases and is optimized for devices with limited resources.

2. **MC Engine (Multiple Choice Engine):**  
   It analyzes multiple-choice questions by extracting keywords from the question and matching them with provided answer options. The engine is capable of handling questions and options that contain multiple words.

The web interface is designed with a modern, responsive look—featuring a soft gradient background, card-based layouts, subtle transparency effects, and smooth micro-interactions. Unlike competitors that typically use heavy machine-learning–based search engines and extensive NLP models, our solution employs a streamlined partial matching algorithm tailored for ESP32's limited computing power, making it efficient and cost-effective for local implementations.

---

## README

### Introduction

The **Dayak Kenyah Translator & MC Engine** project is an innovative solution for translating between Indonesian and Dayak Kenyah while providing automatic multiple-choice answer selection. The system is designed to run on an ESP32 and leverages a custom vocabulary (over 500 words/phrases) with a user-friendly web interface.

### Key Features

- **Real-Time Translation:**  
  Translates text between Indonesian and Dayak Kenyah using tokenization and partial matching, ensuring multi-word phrases are handled efficiently.

- **Multiple Choice Engine:**  
  Processes multiple-choice questions by extracting and matching keywords from the question against a set of answer options, even when the options are composed of multiple words.

- **Modern Web Interface:**  
  Features a card-based layout with off-white backgrounds, soft shadows, gradient buttons, and interactive feedback (loading spinners and toast messages) for enhanced user experience.

### How to Use

1. **ESP32 Setup:**
   - Connect your ESP32 board to your WiFi network by updating the credentials in the source code.
   - Upload the code (written in C/C++ using the Arduino framework) to your ESP32 board.

2. **Accessing the Web Application:**
   - Open a modern web browser (e.g., Chrome, Firefox) and navigate to the IP address provided by the ESP32.
   - You will see two distinct panels: one for the Translator and one for the MC Engine.

3. **Using the Translator:**
   - In the Translator card, enter the text you want to translate into the input area.
   - The translation will update automatically in real-time.
   - Swap the source and target languages using the swap button.

4. **Using the MC Engine:**
   - In the Multiple Choice card, enter your question in the text input and type the answer options in the textarea (separate each option with a comma).
   - Click the "Process Answer" button to analyze the question and options.
   - The correct answer is then displayed below, with interactive feedback (loading indicator and toast messages).

### Required Hardware

- **ESP32 Development Board**  
- **USB Cable** for programming the ESP32  
- **Optional Components:**  
  Breadboard, jumper wires, and other prototyping accessories as needed for your project setup.

### Software & Libraries

- **Arduino IDE or PlatformIO:**  
  Used for coding and uploading the firmware to the ESP32.

- **WiFi.h:**  
  Manages the ESP32's WiFi connection.

- **WebServer.h:**  
  Implements a simple HTTP server running on the ESP32.

- **ArduinoJson.h:**  
  Handles parsing and deserialization of the JSON vocabulary.

- **Font Awesome (via CDN):**  
  Provides icons used in the web interface (e.g., language icons, paper-plane icon).

- **Google Fonts (Inter and Nunito):**  
  Used for modern, readable typography on the web interface.

### Competitor Comparison

- **Traditional Engines (Competitors):**  
  Many translation solutions rely on complex machine-learning models and extensive natural language processing (NLP) techniques. These systems typically involve large-scale indexing, high computational overhead, and require cloud-based infrastructure for real-time processing.

- **Dayak Kenyah Translator & MC Engine:**  
  - **Lightweight Approach:**  
    Uses tokenization and partial matching for phrase-level translation, which is highly optimized for devices like the ESP32.
  - **Responsiveness & Interactivity:**  
    The modern web interface offers real-time translation, interactive feedback (loading spinners, toast notifications), and smooth micro-interactions—all while running on a low-power device.
  - **Localized Focus:**  
    Specifically tailored for translating between Indonesian and Dayak Kenyah using a curated vocabulary, making it more specialized for local language needs.
  - **Cost & Infrastructure:**  
    Can be deployed on inexpensive hardware without the need for expensive cloud infrastructure, making it accessible in areas with limited connectivity.

### Conclusion

The **Dayak Kenyah Translator & MC Engine** project offers an efficient and interactive solution for translating between Indonesian and Dayak Kenyah. With its modern, responsive interface and lightweight translation engine, it provides a compelling alternative to traditional, resource-intensive translation systems. This makes it particularly suitable for local applications where computational resources and connectivity are limited.

---


