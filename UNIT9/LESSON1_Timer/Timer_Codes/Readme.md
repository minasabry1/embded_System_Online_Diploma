Timer
1.Watch_Dog
The Led Turns ON Every time the clk reach to Overflow
![WDG](https://user-images.githubusercontent.com/73604557/229183911-fe7ce32e-aef1-44e4-abe3-79f2570ff2f7.gif)
-----------------------------------------------------------------------------------------------------------
2.CTC
when counter reach the Compare at OCR0 the interrupt ON and Toggle LED and Increment Numver of Compare's Interrupt
![CTC](https://user-images.githubusercontent.com/73604557/229183920-d7bc314b-eb03-4ac1-b8d4-651ebb81de13.gif)
------------------------------------------------------------------------------------------------------------
3.Fast_PWM_Inverting
Set OC0 on compare match, clear OC0 at BOTTOM,
(inverting mode)
Here when counter reach to overflow and compare Numver of Compare's Interrupt and Numver of OverFlow's Interrupt And the Two LED
One for Compare And One for OverFlow will ON
![Fast_PWM_INVERTING(1)](https://user-images.githubusercontent.com/73604557/229183974-1ee5a12d-a92c-4a17-89aa-6919082f229f.gif)
3.Fast_PWM_Non_Inverting
Clear OC0 on compare match, set OC0 at BOTTOM,
(nin-inverting mode)
Here when counter reach to overflow and compare Numver of Compare's Interrupt and Numver of OverFlow's Interrupt And the Two LED
One for Compare And One for OverFlow will ON
![Invering_FAST_PWM](https://user-images.githubusercontent.com/73604557/229184035-bd39a9c6-1c24-43d3-ad3b-73da833835bd.png)
-----------------------------------------------------------------------------------------------------------

GIF --> Running
-----------------------------------------------------------------------------------------------------------
![Not_Invering_PWM](https://user-images.githubusercontent.com/73604557/229184045-85bcfed7-1150-45ce-b508-fe40c4b3e2ed.png)


