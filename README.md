# ENGG1340--Group_Project-
ENGG1340-(Group_Project) By @Uzair05 and @tridib13

## Introduction
Our project is the group project assigned to us by the University of Hong Kong course code ENGG1340.
For this project we chose to create a **Table Management System** and try to work out solutions for an actual restaurant.

We tried to model our project based on what we perceived would be the main issues faced by real life restaurants.
The goal of this project is to automate as many functions as possible to reduce the pressure on restaurant staff and create a sense of efficiency.

## Problem Statement
The restaurant in question currently runs its business as a family-owned Deli. They receive customers as well as allow for booking of tables for customers. 
The restaurant operates by normally allowing customer/s to book a table in their restaurant as well as allowing walk-in customers.
The management often complain of the laborious need to manage booking via the traditional phone booking as the number of customers grow. They also must manage the cancellation of bookings as well as the billing of the individual tables.
There are also complaints that the management must put in extra effort in sorting and suggesting tables to groups of odd numbers of customers.
Another issue found is that the management must actively keep track of the time a certain group has been occupying their table. They must also stay aware of the seasonal trends and behavior of customers during such seasons, as such they regularly need to update their database on the number seats of each rearranged table.
They must also make room for errors such two members of the same group making overlapping bookings etc. And they need to improve their efficiency in their ability to keep track of the orders of each table so that their bill doesn't get mixed up or miscounted.

## Problem Setting
Certain assumptions must be made before creating the program.
1. We need to assume that the restaurant has the necessary computer system and OS to run the program.
2. We'll also be assuming that the waiters and staff react and respond to prompts and notifications from the program and take any necessary measures and update their input to the program.
3. It will be assumed that the restaurant is an average sized family-owned Deli.

The program when applied will be able to remove the need of manually writing table bookings on a paperback register. It will also be able to suggest suitable tables for different sizes of groups according to table vacancies. If no vacancies are available at the requested time it suggests its own time for the customer to arrive.
The program will also allow easy cancellation of booking as well as be able to keep track of customers who are late beyond a certain period and opens the table for new booking.
It makes sure that no group overstay their reservation by tracking the time the group arrives and separately keeps track of each tables orders so that it can effectively process the billing of each table.
The program can be enabled to keep track of certain group patterns with calendar date and be able to make suggestions on the seating arrangement of table in future. This would make seat allocation more efficient as the program will be able to change over time.
The program might also be able to solve the issue of overlapping booking. 

## Features
the features of program are listed as such:
1. The program will be able to sort through the available tables and find the most suitable table amongst the available tables within the suggested timeframe.
2. The program will be able to allocate a status tag to the tables i.e. booked, occupied, clear. The status can be viewed and changed both manually and automatically.
3. The time duration a specific group occupies a table can be measured. This will allow the waiters to be notified in case any group overstays their registration.
4. Placement of booking as well as cancellation of booking will be handled by the program, this frees up the necessary effort required to keep tabs on the booking arrangements.
5. The bills of each table can be noted and continuously appended making room for more orders. This also allows safety from the error of having orders mixed up or miscounted.
6. There are extra features such as measuring the number of groups that frequently occur each season so that it can suggest a table layout for each season.
   - The table and seats allocation can be updated manually in the program.
7. Extra features include: 
   - The cancellation of a groups booking if they are late beyond a specific period.
   - Allowing the option of split tables i.e. offering more than one table to large groups. The tables are preferably close to one another within the restaurant.
   - measure the sales of certain dishes and calculate its success rate varying with season.