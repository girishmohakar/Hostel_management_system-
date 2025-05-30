# Hostel Mess Management System (C Language)

A simple console-based system to help manage daily hostel mess operations. This project is built purely in C using only basic headers (stdio.h and string.h), making it ideal for beginners learning about structures, arrays, functions, and menu-driven programs.


---

# 📋 Features

👤 User Login

🔑 Role-based access using phone numbers

Separate menu for owners and students


🍽️ Food Menu Management

📅 Add or update weekly food menu (Breakfast, Lunch, Dinner for 7 days)

🧾 Both owners and students can view daily menu


⭐ Student Feedback System

🌟 Rate each meal (1–5 stars)

💬 Add suggestions or complaints

🗂 Stores feedback for up to 100 entries


📊 Weekly Report Generation (Owner)

🏆 Finds most liked & least liked food items (based on ratings)

📃 Lists all student suggestions by day



---

# 🔧 How It Works

1. Structs Used

User: for owner & student login

Menu: to store breakfast/lunch/dinner for each day

Feedback: to hold ratings and complaints


2. Functions Implemented

updateMenu(): Owners update food items

viewMenu(): Both roles can check the menu

submitFeedback(): Students submit ratings & suggestions

generateReport(): Owners view food ratings summary & suggestions

isOwner() / isStudent(): Validate login using phone number


3. Menu System

Repeats using do-while loop

Accepts inputs, performs actions, then loops until user exits



---

# Challenges Faced

The feedback and reporting logic was the toughest part:

Mapping feedback to correct day's food

Grouping identical food items across days

Calculating average ratings and determining most/least liked items


It took several attempts to get the logic right, but it was also the most rewarding part!

---

# 🧑‍💻 How to Run

1. Clone this repo or download the .c file


2. Compile using any C compiler:

gcc mess_management.c -o mess


3. Run the program:

./mess


4. Use these sample phone numbers to log in:

Owner: 9999999999, 8888888888

Student: 7777777777, 6666666666





---

# 🙌 Acknowledgment

This project was built as part of my learning journey in C programming.
Special thanks to those who supported me through the logic-heavy parts!


---

# Author 

Girish Mohakar 
