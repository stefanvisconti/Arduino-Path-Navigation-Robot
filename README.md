# SIngle-Actuator-Arduino-Path-Navigation-Robot
Wheeled Mobile Robot controlled with an Arduino UNO to navigate through pre-determined paths, and around obstacles. A figure of the robot design can be seen below.

<img width="734" alt="Screenshot 2024-01-02 at 16 14 15" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/846b26cf-8a3e-43ab-bb20-d7abeca982d1">

The goal of this project is to gain hands-on experience with microcontrollers, sensors, actuators and the programming required to interface with them. The robot is designed to complete four distinct tasks wherein it must: navigate through HMI, navigate autonomously and avoid objects. The solution created was a single actuator design that is able to turn and move forward/backward using one motor on a pivoting ratchet. The robot is able to determine  position using ultrasonic sensors and using these will navigate the tasks accordingly. There are many constraints on this project such as: time, funds and resources which increased the difficulty in creating a solution. In this experiment the design process including: problem definition, solution formulation, modelling, prototyping and implementation will be explored in order to gain in-depth hands-on experience with mechatronics topics.

A video of the system performing in it's manual control option is shown below.

https://drive.google.com/file/d/11_2gsuO4MDafjLckb3ffVChpPL_l2O8q/view?usp=drive_link

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

## CAD Models and Technical Design Details of Mechanics

The physical design of this system is quite intricate given the single actuator used to drive the system. Due to this stipulation, certain design considerations must be taken in order to achieve this goal. Additionally, the car was to be constructed using only available materials, and no parts were to be purchased, implying that the cost of the car would be $0. This resulted in almost all of the parts of the device being 3D printed.

The main form of the device is a car with 3 wheels. The two wheels at the back of the car are idler wheels, and are simply there to provide support to the vehicle while it drives. The wheel in the front is the driving wheel, which is fitted with a gearbox and a motor. The front wheel will be able to drive the car forward, as well as rotate to act like a pivot. This is how the car will be able to steer.
The entire mechanism assembly can be seen below, modelled using the online CAD software, Onshape.

<img width="480" alt="Screenshot 2024-01-02 at 17 24 40" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/0f2aa1ae-c903-4c8c-8beb-6f0c43526c0a">

The assembly consists of a number of parts. These include the motor, Elegoo UNO R3 board, spring, ultrasonic sensors, o-rings, and all of the 3D printed parts. The 3D printed parts make up the large majority of the assembly. These include, the main body, back deck, back wheel, back wheel axle, ring gear plate, main pivot, motor frame, main wheel gear, idler gear, spur gear, motor gear, bevel gear, bevel spur gear, idler, pivot cap, brush mount, brush mount clamp, ultrasonic sensor mount, and ultrasonic sensor mount mount.

To start, the main body is the largest part of the assembly, all other parts connect to this. It features two cutouts on the side with a threaded hole for the back wheel axle to screw into. It also has the back of the body hollowed out with slots for the back deck to slide into. It also has a circular cutout on the front with screw holes for the ring gear plate with screw holes to screw into. A screenshot of the CAD model of this is shown below.

<img width="317" alt="Screenshot 2024-01-02 at 17 24 45" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/c0eff850-d51b-49b5-899f-b28a27ced71e">


Sliding into the main body is the back deck. This features a plate for the Elegoo UNO R3 board to screw into. Underneath the back deck is where the L298N motor driver is housed. A screenshot of the CAD model of this is shown below.

<img width="287" alt="Screenshot 2024-01-02 at 17 24 50" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/4169491e-7bac-4c59-bd7d-b5e2343dbc0f">

Again, attaching to the main body are the back wheel axles. There are two of these and they are fitted with threaded rods that will allow them to screw into the main body. A screenshot of the CAD model of this is shown below.

<img width="270" alt="Screenshot 2024-01-02 at 17 24 55" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/273f4a99-2215-48e2-b1c4-856d46a4e5a4">

Accompanying the back wheel axle is the back wheel. This is what provides stability to the rear of the car. They have grooves along the circumference of the wheel in which a plumbing o-ring is able to fit around. This provides the friction needed to be able to spin on the floor. A screenshot of the CAD model of this is shown below.

<img width="228" alt="Screenshot 2024-01-02 at 17 24 59" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/fafcf073-d32c-4a4b-ae59-49e98a4907f1">

Another large part of the assembly is the ring gear plate. This screws into the front of the main body and features a large ring gear which will allow the front wheel to pivot around. A screenshot of the CAD model of this is shown below.

<img width="318" alt="Screenshot 2024-01-02 at 17 25 04" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/00cc38b3-40f4-4d82-90ca-c48897d8604a">

The Elegoo UNO R3 board is the main brains of the device. This controls the motor speed and direction and reads and processes values from the sensors. A screenshot of the CAD model of this is shown below.

<img width="372" alt="Screenshot 2024-01-02 at 17 25 09" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/2cfbc950-9783-4d2f-873c-7e24e035402f">

Sliding through the top of the ring gear plate is the main pivot. This part will be rotating with the main wheel. It is fastened to the ring gear using a set of nuts. The main pivot will also have a hole cut through the middle of it to allow the wires from the motor to be snaked through to be accessible by the arduino. Additionally, with the wires, the pivot will support two pieces of brass tubing which will be used as commutator wings. The wires will be soldered to these and have brushes (paperclips) which will allow power to be supplied to the motor without having the wires get tangled as it rotates. A screenshot of the CAD model of this is shown below.

<img width="125" alt="Screenshot 2024-01-02 at 17 25 13" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/3e844369-e4ed-4490-bf0e-bad0aba363bd">

The brushes, which in this case are paper clips, will be fastened to the device using the brush mounts. These will be screwed into the ring gear plate, and will act as a clamp on the paper clips. One end of the paper clip will be brushing the commutator rings, and the other end will be soldered to a wire which is connected to the L298N motor driver. A screenshot of the CAD model of these are shown below.

<img width="473" alt="Screenshot 2024-01-02 at 17 25 21" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/597400f5-6811-4363-a033-38a6d765369a">

Attached to the main pivot is the motor frame. This is quite the complex part as it will the motor and all of the gears which will allow the single actuator steering mechanism to work. A screenshot of the CAD model of this is shown below.

<img width="229" alt="Screenshot 2024-01-02 at 17 25 26" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/4a8af0e6-157d-491a-8091-e79831ffde49">

The main wheel of the car features a 38 tooth gear which will be driven by the gearbox on the motor frame. Similarly to the back wheel, it will also have two plumbing o-rings around it which will provide the friction needed for it to drive on the floor. A screenshot of the CAD model of this is shown below.

<img width="242" alt="Screenshot 2024-01-02 at 17 25 30" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/e46109cb-91fd-4eb2-95ab-796502b6c214">

Next are the rest of the gears. The majority of these look quite similar. A screenshot of the CAD model of all of these are shown below.

<img width="558" alt="Screenshot 2024-01-02 at 17 25 59" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/afbefd74-a562-4f4f-99db-197628665862">

Accompanying the gears is the idler. This is the main part that will allow for the single actuator steering mechanism to work. It allows the idler gear to switch between meshing with the main wheel gear and meshing with the pivot mechanism. When the motor changes direction, a spring pushing on the idler allows the idler to switch between driving mechanisms. However, it applies just enough force to allow the idler to move but not enough for the motor gear to be prevented from turning. A screenshot of the CAD model of this is shown below.

<img width="221" alt="Screenshot 2024-01-02 at 17 26 09" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/282cc036-8b1d-4c8e-86e5-54e1ff489acc">

A screenshot of the overall driving mechanism can be seen below.

<img width="513" alt="Screenshot 2024-01-02 at 17 26 21" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/6be36de3-a8f6-4395-b072-834487c204af">

The sensing of the device is done using ultrasonic sensors which are mounted to the front of the car. This sensor mount comes in two pieces. One large piece which will attach onto the ring gear plate, and another which will hold the ultrasonic sensor. These two pieces will screw into each other. It was decided that the necessary distance between each sensor would be 3 inches. A screenshot of the CAD model of these are shown below.

<img width="595" alt="Screenshot 2024-01-02 at 17 26 31" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/770edef7-67f1-4d67-851b-dc178aab72ee">

## Controller Design and Block Diagram of Control System

The control system of this project is designed based on the mathematical modelling and simulation previously done. This was the result of the inverse kinematics problem, and the Simulink simulation of the system. From the equations developed in that section, the block diagram for the control system can be created. The controller itself will be described by a transfer function which will be created from the equations previously obtained.
The control system for this project can be described using the following block diagram shown below.

<img width="548" alt="Screenshot 2024-01-02 at 17 31 45" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/a1cfe668-58c9-4d1f-b22d-4ac60e41d553">

The Ts block represents the transfer function developed in the Mathematical Modelling section. The vRs block represents the desired robot velocity, s represents the wheel angular velocities, t represents the current angle of the robot. The controller takes in the desired velocity of the robot, and outputs the corresponding wheel angular velocities that will achieve that velocity.

## Flowchart and Description of the Software Program

The flowcharts that describe the Arduino scripts can be found in the following figures. All scripts begin by including the necessary libraries, assigning respective pins for sensors and motor, defining all required variables and setting the pin modes. For manual control, the void loop() consists of reading the joystick data and mapping the joystick position to motor speed. That is, for the joystick range of 0 to 1023, the motor speed is mapped from -255 to 255. If the joystick is in the forward position (i.e, positive motor speed), then the motor drives the robot forward. Simularily, if the joystick is in the backward direction (i.e., negative motor speed), then the motor is reversed resulting in the rotation of the steering shaft. If neither statement is true, then the motor stops and the robot does not move. The flowchart for manual control can be seen below. 

<img width="486" alt="Screenshot 2024-01-02 at 17 33 21" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/6205050c-e688-47ed-a2db-e16110b43bff">

For autonomous path navigation, the void loop() begins by reading the ultrasonic and MPU data. The ultrasonic is used to detect the distance of objects ahead, while the MPU measures the rotation of the steering shaft such that the exact direction is known. If the robot is not close to an object, then the robot continues moving forward. If the robot is close to the first object, then the robot turn right 90-degrees. If the robot is close to the second object, then the robot turns left 90-degrees. If the robot senses an object, but it is neither the first or the second, then the robot is at the final object and motion is stopped. The flowchart for autonomous path navigation can be seen below. 

<img width="606" alt="Screenshot 2024-01-02 at 17 33 27" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/855611e5-99e2-4049-b678-a36187f12afb">

For obstacle avoidance, the void loop() begins by reading the ultrasonic and MPU data. If the robot is not close to an object, then the robot continues moving forward. If the robot is close to the object, then an avoidance deviation sequence is initiated. That is, the robot turns right and travels forward for X seconds until the object is clear. Then the robot turns left and goes forward for X seconds to get past the object. The robot then turns left again and goes forward for X seconds to reach the original path. Another right turn is executed to face the robot towards the finish line. The robot then travels forward for X seconds until the robot reaches the finish line. The flowchart for obstacle avoidance can be seen below. 

<img width="368" alt="Screenshot 2024-01-02 at 17 33 36" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/0508dffb-8305-4da8-a3fa-0479f77a761c">

Simularily, for the accuracy test, the void loop() begins by reading the ultrasonic and MPU data. If the robot is not close to an object, then the robot continues moving forward. Each time the robot get close to an object it turns right and continues forward. If the senses object is the forth object, then the script ends. The flowchart for the accuracy test can be seen in the figure below. 

<img width="602" alt="Screenshot 2024-01-02 at 17 33 43" src="https://github.com/stefanvisconti/Singlle-Actuator-Arduino-Path-Navigation-Robot/assets/72313435/176304f2-0326-40e5-b398-1d39442ad051">

## Conclusions and Recommendations

Overall the robotic system that was created was able to be both mechanically innovative and realistically feasible with its execution of the tasks as detailed by the project addendum. Fundamental design formulas were followed during the conceptualization of the solution put forth in this project. These involved strong project initialization exercises such as mind maps, clearly defined functional, constraints and characteristics, and black box diagrams to be used when coming to the formulation of the design. This came to fruition as a one actuated geared robotic drive system that would be able to drive and pivot with two degrees of freedom. The design was easy to drive and provided comparatively little error as opposed to robots with more actuators. To begin the design process of this both mathematical and simulated models were created to test the feasibility of the design. Afterwards, detailed CADs were created to make a model that was almost completely 3D printed. This had the added benefit of keeping the cost of the robots to 0$ which was another one of the ancillary goals of the project detail. 

To control the robot, Arduino along with an ultrasonic sensor, and MPU 6050 was used to both determine any obstacles or the position of the robot. The MPU was especially important for the bearing of the pivot along with the rotation of the body of the drone. In addition, the motion of the robot was mathematically modelled using inverse kinematics. A transfer function was developed such that the controller takes in the desired velocity of the robot, and outputs the corresponding wheel angular velocities that will achieve that velocity.
