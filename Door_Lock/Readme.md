Door Locker Security System consists of two ECU’s. The first ECU called HMI responsible for interfacing with the user and the second ECU called control ECU which is responsible for the system operations and control.
Implement the Door Locker Security System to unlock a door using a password.
2 ATMEGA32 First Connected To LCD and KeyPad and Send Data to Seond ATMEGA32 USING UART
AND Seond ATMEGA32 Send Data To EEPROM USING I2C And Then Read it And Check First The Two Password If it is Right Will Open Door For 5 Seconds and If Entered Password Wrong for 3 TIMES The Alram Will ON.
with the specifications listed below:
1) Use two ATmega32 Microcontrollers with frequency 8Mhz.
2) The project should be design and implemented based on the layered architecture
model as follow:
ℳc1 → HMI_ECU (Human Machine Interface) with 2x16 LCD and 4x4 keypad.
Implement the Door Locker Security System to unlock a door using a password.
with the specifications listed below:
1) Use two ATmega32 Microcontrollers with frequency 8Mhz.
2) The project should be design and implemented based on the layered architecture
model as follow:
ℳc1 → HMI_ECU (Human Machine Interface) with 2x16 LCD and 4x4 keypad.
Enter a password consists of 5 numbers, Display * in the screen for each number.

![1](https://user-images.githubusercontent.com/73604557/232876922-ebaa7ea1-e9db-4dc7-bcce-98bfb69d35e0.png)
Re-enter the Password:
the two passwords are sending to EEPROM using I2C.

![2](https://user-images.githubusercontent.com/73604557/232876937-56055fe8-3f62-475d-9b53-b73b05378cf4.png)
If two Passwords are matched .Then you can open the Door and enter the password OR Change Password.

![3](https://user-images.githubusercontent.com/73604557/232876943-77d13bd4-7f73-49ba-9c47-6a5af04a2172.png)
Here!If Pressed '-' Will Open Door and Ener Password.

![4](https://user-images.githubusercontent.com/73604557/232876953-73c3408d-21f8-45eb-b41a-132d74874dcb.png)
If matche will open the door by Phase Correct PWM.
=========OPEN===========

![5](https://user-images.githubusercontent.com/73604557/232876960-4576b256-85eb-492d-850e-1a2beb44a2a4.png)
=========OPEN===========
	// Rotate the servo to -90 degrees to open
	//rotate_servo(-90);
	//Duty cycle = (Compare value * 100) / 256 = (155 * 100) / 256 = 60.55%
![pwm1](https://user-images.githubusercontent.com/73604557/232876996-52e866f3-9e1e-4c21-8903-54d128445300.png)
=========CLOSE===========
![6](https://user-images.githubusercontent.com/73604557/232876967-2a14d4fc-c786-4cd0-bac6-330a29479ad5.png)

=========CLOSE===========
	// Rotate the servo to +90 degrees to close
	//  rotate_servo(90);
	//Compare value = (Duty cycle * 256) / 100
	//duty cycle of 30%, the compare value can be calculated as follows:
	//Compare value = (30 * 256) / 100 = 76.8
![pwm2](https://user-images.githubusercontent.com/73604557/232877000-4a99ba77-59dd-4b41-a154-49c9f0ba1975.png)

=====OLD=====
Here!If Pressed '-' Will Change Password By Entering OLD and NEW Password.
![7](https://user-images.githubusercontent.com/73604557/232876973-7a77c75e-f73c-4176-8641-3874d427dcad.png)

=====NEW=====
![8](https://user-images.githubusercontent.com/73604557/232876978-edae5c5e-c73f-404f-a2aa-b09ae336a74a.png)
IF: Matched Then New Password is Changed.

![9](https://user-images.githubusercontent.com/73604557/232876985-d8cd1a6c-00fc-4384-9ba7-1b7fa8cdbb15.png)
====WRONG PASSWORD======
IF USER Enter Password Wrong At first OR While Changing Password OR when Open Door

![10](https://user-images.githubusercontent.com/73604557/232876992-9b0aef78-38cd-49c1-9c89-f1e387c30747.png)
And IF Entered Password 3 Twimes Wrong The Buzeer will ON for 40 Seconds
![11](https://user-images.githubusercontent.com/73604557/232876994-387464de-8bd8-4f54-8d89-aa96ae906373.png)


=====Can See The Vedio At The Link Below=========
Drive:https://drive.google.com/file/d/1_jMS6gV9vJ1Hy1h0TN0Zv2ZDuqDcMcc-/view?usp=share_link

