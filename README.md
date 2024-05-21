---
# Triangle Drawing Application

This C++ Forms application allows users to draw triangles on a form using three points. Users can select a color for each triangle, create an array of triangles, store them, and display all the triangles at once. The application consists of two main files: `Triangle.h` and `MyForm.h`.

## Overview

### `Triangle.h`

- **Points Class**: Represents a point with `x` and `y` coordinates.
- **Triangle Class**: Represents a triangle using three `Points` objects and a `Color`.

### `MyForm.h`

This file contains the main form logic for the application, including UI components and event handlers.

## Key Functions

### Initialization

- **MyForm Constructor**: Initializes the form, the array for storing triangles, and sets up UI components.

### Event Handlers

- **btnCreateArray_Click**: Creates an array for storing triangle objects. Initializes the points array and sets the creation flag.
- **btnColorPicker_Click**: Opens a color dialog for the user to select a color for the next triangle.
- **btnAddToArray_Click**: Adds a completed triangle to the array if three points are defined and the array is not full.
- **btnDrawAll_Click**: Draws all triangles stored in the array on the form.
- **btnExit_Click**: Closes the application.
- **FormMouseDown**: Captures the coordinates of a mouse click on the form. When three points are collected, it draws a triangle using the selected color.

### Drawing

- **DrawTriangle**: Draws a triangle on the form using the provided `Triangle` object.

## Usage

1. **Create Triangle Array**: Click the "Создать массив объектов" button to initialize the triangle array.
2. **Select Color**: Click the "Выбор цвета" button to choose a color for the triangles.
3. **Draw Triangles**: Click on the form to select three points for a triangle. After three points are selected, the triangle is drawn with the chosen color.
4. **Add to Array**: Click the "Занести в массив" button to add the current triangle to the array.
5. **Draw All Triangles**: Click the "Нарисовать все" button to draw all the triangles stored in the array.
6. **Exit**: Click the "Выход" button to close the application.

## UI Components

- **TextBox `txtNumElements`**: Input for the number of triangles.
- **Button `btnCreateArray`**: Creates the array of triangles.
- **Button `btnColorPicker`**: Opens the color picker dialog.
- **Button `btnAddToArray`**: Adds the current triangle to the array.
- **Button `btnDrawAll`**: Draws all triangles in the array.
- **Button `btnExit`**: Exits the application.
- **ColorDialog `colorDialog`**: Dialog for selecting triangle color.

## Notes

- Ensure to input a valid number for the triangle array size.
- The application checks for array overflow and incomplete triangles before adding to the array.
- The application provides visual feedback by drawing triangles directly on the form.

---

This README provides an overview of the application's functionality, key functions, and usage instructions.
