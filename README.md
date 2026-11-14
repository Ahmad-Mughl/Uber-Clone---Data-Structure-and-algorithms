# Uber-Clone---Data-Structure-and-algorithms
📌 Project Overview

Mini Uber is a console-based ride-booking application developed in C++ using Data Structures and Algorithms. The project simulates the basic functionality of a ride-hailing service, allowing customers to register, log in, select destinations, choose transportation types, and calculate ride fares.

The application uses a Graph-based representation of Lahore's road network to determine the shortest route between locations. A Min Heap is used during shortest-path processing, while a Binary Search Tree (BST) manages customer records and login operations.

The system also implements file handling to store customer information and road network data, along with a loyalty-based discount mechanism for returning customers.

🎯 Project Objectives

Develop a ride-booking application using C++.

Implement customer registration and login functionality.

Manage customer records using a Binary Search Tree.

Represent a city's road network using Graph data structures.

Calculate shortest routes between locations.

Implement Min Heap operations for route calculation.

Calculate ride fares based on travel distance.

Introduce a loyalty discount for frequent customers.

Use file handling for persistent data storage.

✨ Key Features

1. Customer Registration

Register new customers.

Collect customer name, CNIC, phone number, and address.

Validate CNIC length.

Prevent duplicate customer accounts.

Store customer information in a file.

2. Customer Login

Allow existing customers to log in using their CNIC.

Verify customer records using a Binary Search Tree.

Display customer account information after successful login.

Handle invalid login attempts.

3. Ride Booking

Allow customers to book rides after logging in.

Display available destinations across Lahore.

Allow users to select their desired destination.

Provide different transportation options:

AC Car

Without AC Car

Motorcycle

Rickshaw

4. Shortest Route Calculation

Represent locations and roads using a weighted Graph.

Calculate the shortest route from the starting location to the selected destination.

Use a Min Heap during shortest-path processing.

Display the calculated route with intermediate locations.

5. Fare Calculation

Calculate ride fares based on the total route distance.

Apply a base fare rate of Rs. 25 per distance unit.

Provide a 30% discount to customers after completing at least five services.

Maintain customer service counts.

6. Customer Data Management

Store customer records in text files.

Maintain customer information in a Binary Search Tree.

Track the number of completed services.

Update customer records after successful bookings.

7. About Us Section

Display application information through the About Us menu.

Read information from an external text file.

🧠 Data Structures and Algorithms Used

Data Structure / Algorithm

Application

Binary Search Tree (BST)

Customer registration and login

Graph

Representation of Lahore's road network

Min Heap

Selecting minimum-distance candidates during route calculation

Vector

Storing customer records and calculated routes

Dynamic Arrays

Managing shortest-path data

File Handling

Storing customer and road network information

Shortest Path Algorithm

The application uses a custom shortest-path implementation based on a weighted graph and Min Heap.

The algorithm:

Takes the starting location and destination as input.

Initializes distances to infinity.

Traverses connected locations.

Updates distances when a shorter route is found.

Uses a Min Heap to select the next minimum-distance candidate.

Maintains previous-node information to reconstruct the route.

Displays the shortest calculated path and total distance.

📍 Available Locations

The application includes 40 locations in Lahore, including:

Faisal Town

Johar Town

Kalma Chowk

Garden Town

Forman Christian College

Ferozpur Road

Barkat Market

Cavalry Ground

DHA

Gulberg

Lahore Cantt.

LUMS

Paragon City

Lahore Canal

Atchison College

Mall Road

Allama Iqbal Airport

Wagha

Emporium Mall

Model Town

Township

Additional locations are available in the application.

💰 Fare Calculation

The system calculates fares according to the total distance of the shortest route.

Standard Fare:

[
Fare = Distance \times 25
]

Returning Customer Discount:

Customers who have completed at least five services receive a 30% discount.

[
Discounted\ Fare = Distance \times 25 \times 0.70
]
