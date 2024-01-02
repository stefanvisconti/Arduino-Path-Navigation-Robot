# Arduino-Path-Navigation-Robot
Wheeled Mobile Robot controlled with an Arduino UNO to navigate through pre-determined paths, and around obstacles. A figure of the robot design can be seen below.

<img width="734" alt="Screenshot 2024-01-02 at 16 14 15" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/846b26cf-8a3e-43ab-bb20-d7abeca982d1">

The goal of this project is to gain hands-on experience with microcontrollers, sensors, actuators and the programming required to interface with them. The robot is designed to complete four distinct tasks wherein it must: navigate through HMI, navigate autonomously and avoid objects. The solution created was a single actuator design that is able to turn and move forward/backward using one motor on a pivoting ratchet. The robot is able to determine  position using ultrasonic sensors and using these will navigate the tasks accordingly. There are many constraints on this project such as: time, funds and resources which increased the difficulty in creating a solution. In this experiment the design process including: problem definition, solution formulation, modelling, prototyping and implementation will be explored in order to gain in-depth hands-on experience with mechatronics topics.

## List of Materials

In order to construct the physical mechanism to be used for this project, mostly 3D printed parts were used for structural elements. The single actuator used is the N20 Motor which was already owned by a group member. The paper clips, copper tubing, and o-rings were scrap materials found at home. All of the remaining electrical parts have been taken from the Elegoo Starter Kit. However, a complete list of the costs were considered if each component needed to be purchased. A comprehensive list of all of the hardware that has been used in this project is given in the table below.

<table>
  <tr>
    <th>Name</th>
    <th>Description</th>
    <th>Quantity</th>
    <th>Unit Cost</th>
    <th>Cost</th>
  </tr>
  <tr>
    <td>Main Body Back</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Back Deck</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Back Wheel</td>
    <td>3D Printed</td>
    <td>2</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Back Wheel Axle</td>
    <td>3D Printed</td>
    <td>2</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Ring Gear Plate</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Main Pivot</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Motor Frame</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Main Wheel Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Idler Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Spur Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Motor Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Bevel Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Bevel Spur Gear</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Idler</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Pivot Cap</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Brush Mount</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Brush Mount Clamp</td>
    <td>3D Printed</td>
    <td>1</td>
    <td>$0</td>
    <td>$0</td>
  </tr>
  <tr>
    <td>Elegoo UNO R3</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$23.99</td>
    <td>$23.99</td>
  </tr>
  <tr>
    <td>L298N Motor Driver</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$3.95</td>
    <td>$3.95</td>
  </tr>
  <tr>
    <td>MPU6050 IMU Sensor</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$7.50</td>
    <td>$7.50</td>
  </tr>
  <tr>
    <td>HC-SR04 Ultrasonic Sensor</td>
    <td>Elegoo Starter Kit</td>
    <td>2</td>
    <td>$4.50</td>
    <td>$9.00</td>
  </tr>
  <tr>
    <td>N20 DC Motor</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$7.99</td>
    <td>$7.99</td>
  </tr>
  <tr>
    <td>Copper Tubing</td>
    <td>Scrap Material</td>
    <td>1</td>
    <td>$1.20</td>
    <td>$1.20</td>
  </tr>
  <tr>
    <td>Paper Clip</td>
    <td>Scrap Material</td>
    <td>2</td>
    <td>$0.10</td>
    <td>$0.20</td>
  </tr>
  <tr>
    <td>O-Ring</td>
    <td>Scrap Material</td>
    <td>4</td>
    <td>$1.36</td>
    <td>$5.44</td>
  </tr>
  <tr>
    <td>9V Battery</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$4.50</td>
    <td>$4.50</td>
  </tr>
  <tr>
    <td>Spring</td>
    <td>Scrap Material</td>
    <td>1</td>
    <td>$1.20</td>
    <td>$1.20</td>
  </tr>
  <tr>
    <td>4x3/4 Countersink Screw</td>
    <td>Scrap Material</td>
    <td>6</td>
    <td>$0.67</td>
    <td>$4.00</td>
  </tr>
  <tr>
    <td>M3 Screw</td>
    <td>Scrap Material</td>
    <td>4</td>
    <td>$0.60</td>
    <td>$2.40</td>
  </tr>
  <tr>
    <td>Wire</td>
    <td>Elegoo Starter Kit</td>
    <td>23</td>
    <td>$0.56</td>
    <td>$12.99</td>
  </tr>
  <tr>
    <td>PKCELL 9V Battery Connector</td>
    <td>Elegoo Starter Kit</td>
    <td>1</td>
    <td>$5.33</td>
    <td>$5.33</td>
  </tr>
  <tr>
    <td>Total Cost</td>
    <td></td>
    <td></td>
    <td></td>
    <td>$89.69</td>
  </tr>
</table>

## Schematic and Technical Design Details of Electronics

A circuit diagram of this hardware setup can be seen below. This is created digitally using the TinkerCAD software offered by Autodesk. The diagram is a simplified representation of the wiring setup, where the components are shown graphically. 

<img width="560" alt="Screenshot 2024-01-02 at 16 46 06" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/7f23c0b4-8b52-42ba-9b4d-d17a860873b9">

However, if a more accurate-to-real-life circuit diagram is desired, an alternative modelling software must be used. The electrical wiring schematic developed using KiCAD can be seen in the figure below. This circuit provides more accuracy, allowing the circuit to be modelled more accurately to the real life thing.

<img width="624" alt="Screenshot 2024-01-02 at 16 46 19" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/13c5b881-6178-4c5a-8735-bd526f4e6109">


In the figure above, the MPU-6050 symbol is the MPU6050 IMU Sensor board, and the L298N symbol is the L298N Motor Driver board. The Motor_DC symbol is the DC motor being used to drive the gearbox. The two HC-SR04 symbols are the two ultrasonic sensors used for obstacle avoidance in task 3. Finally, the AnalogJoystick1 symbol is the joystick module used to manually control the device. Additionally, the Arduino_UNO_R3 module represents the Elegoo UNO R3 board.
