# AccountingSystem

C++ project for an accounting system for THU-CS 2017 OOP

### BackGround

The topic of this project is a comprehensive accounting system, aiming to make an accounting system that meets our needs. Although there are various accounting systems on the market, there are very few softwares that can be used in personal computers, and the design of the function is not satisfactory. Therefore, our group build a software not only records personal expenses, but also records the unit price, merchants and other information, at the same time increases the International currency conversion function.

### Tasks

* Single accounting system

The user's daily expenditure record (date, place, purchase items, etc.), including the specific information of the products purchased by the user, such as purchase date, purchase place, purchase items, purchase amount, etc.Realize the capture and conversion of multi-currency account record and exchange rate for overseas travel

* Multiple condition screening system

It is no longer limited to the traditional accounting system to display bills for a certain period of time, but can display bills that meet the requirements under various screening conditions, such as unit price screening, total price screening, purchase date screening, and so on.

* Multi-people accounting system

Record the payment and payment of each person when sharing goods, and finally give the transfer plan.

* Database interface

Use database to record commodity information to make the system more stable.

* UI

Implement a complete set of console user interface, based on which to achieve a part of the single accounting system GUI function.

### Division of Labor of the Team

* Single accounting system

<u>Songrui Huang</u> (Class Commidity)

<u>Zi Qian</u> (Class List)

<u>Yifan Yin</u> (Class SingleMoney、Class ExchangeRate、Class Date、Class Unit)

<u>Jiankai Xing</u> (Class Shop)

* Multiple condition screening system

<u>Zi Qian</u> (Class Filter)

* Multi-people accounting system

<u>Zi Qian</u>(Class MuiltiList、Class PayingEntry)

* Database interface

<u>JianKai Xing</u> (Class Database Interface)

* UI

<u>Songrui Huang</u> (Console Version)

<u>Zi Qian</u> (Console Version, GUI Version)

<u>Yifan Yin</u> (GUI Version)

### Architecture Design

* Single accounting system

  <u>Observer Mode</u>

  Object: Commodity objects associated with the List.

  Observer: List, to ensure that all objects in the List still meet the Filter condition when the Commodity information is modified.

* Multiple condition screening system

<u>Chain of Responsibility Mode</u>

* UI

<u>Proxy Mode</u>
