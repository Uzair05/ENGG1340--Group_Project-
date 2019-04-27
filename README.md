# ENGG1340--Group_Project-
ENGG1340-(Group_Project) By @Uzair05 and @tridib13

## Introduction
Our project is the group project assigned to us by the University of Hong Kong course code ENGG1340.
For this project we chose to create a **Table Management System** and tried to work out solutions for an actual restaurant.

We tried to model our project based on what we perceived would be the main issues faced by real life restaurants.
The goal of this project is to automate as many functions as possible to reduce the pressure on restaurant staff and create a sense of efficiency.

## Problem Statement
The restaurant in question currently runs its business as a family-owned Deli. They receive customers as well as allow for booking of tables for customers.
The restaurant operates by normally allowing customer/s to book a table in their restaurant as well as allowing walk-in customers.
The management often complain of the cumbersome need to manage bookings via the traditional phone booking system as the required effort in having to cancel certain bookings and manage the billings of each table.
The management also complain of the extra effort required to sort through and suggest tables of appropriate sizes to different groups. This job of allocating tables can become more difficult due to the seasonal changes in table sizes and placements.
Other issues may include the mundane tasks such as having to keep a record of the time a certain group spends on any table to prevent them from overstaying their reservation.

## Problem Setting
Certain assumptions must be made before creating the program.
1. We need to assume that the restaurant ***has the necessary computer system and OS to run the program***.
***Our Program will run on Linux Ubuntu based system.***
2. We'll also be assuming that the ***waiters and staff react and respond to prompts and notifications from the program*** and take any necessary measures and update their input to the program.
3. It will be assumed that the restaurant is an ***average sized family-owned Deli***.
4. We assume that the deli ***has a satisfactory customer base*** at present.
5. We assume that the deli ***has the sufficient manpower to operate the program***.

The program is a table allocation program with enabled features such allocation, reservation and cancelling. It is intended to remove the unnecessary effort in finding appropriate tables for various groups of different sizes.

The program will allow staff to easily allocate tables and reservations as they themselves will no longer be required to sort and suggest available tables.
The staff will also have the comfort of relying on the program to handle the billing of each table and will no longer have to keep a manual paper-back version of each tables receipt.
Staff can exploit the benefit of do-and-forget feature of the program as they will no longer be required to keep tabs on the cancellation of reservations or the sitting durations of each group of customers.

## Features
The features of program are listed as such:
- Sort through the available tables and ***find the most suitable table amongst the available tables within the suggested timeframe***.
- ***Allocate a status tag to the tables i.e. booked, occupied, clear***. The status can be viewed and changed both manually and automatically.
- ***The time duration a specific group occupies a table can be measured*** by notifying staff in case of overstay of registration.
- ***Placement and cancellation of booking*** will be handled by program.
- ***Bills of each table can be noted*** and continuously appended.
- Extra features such as ***measuring the number of groups that frequently occur each season so that it can suggest a table layout for each season***.
  - The ***table and seats allocation can be updated manually*** in the program.
- Some extra features include:
  - The ***cancellation of a groups booking if they are late*** beyond a specific period.
  - Allowing the option of ***split tables i.e. offering more than one table to large groups***. The tables are preferably close to one another within the restaurant.
  - measure the ***sales of certain dishes and calculate its success rate*** varying with season.


## Things We Could Have Done Better
- Made a Proper GUI
- Used MySql or some database software to enhance features of the Software. for example **finding a table with a window seat**
- Had properly drawn out a map/Pert chart to help coordinate with teammates.

##Division of Functions
The functions have been divided into individual files.
- Billing.cpp handles the management of billing and menu ordering.
- RestaurantTables.cpp handles the functions
- 

##Instructions To Run
- To construct code
`make FamilyDeli`
- To run
`./FamilyDeli`
