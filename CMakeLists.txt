cmake_minimum_required(VERSION 3.0)
project(blink)

set(SOURCES
    blink.cpp
    motor.cpp
    WiringPi/wiringPi/wiringPi.c 
    WiringPi/wiringPi/softPwm.c
    WiringPi/wiringPi/softTone.c
    WiringPi/wiringPi/piHiPri.c
    steppermotor/src/StepperMotor.cpp
)

add_executable(blink ${SOURCES})

target_link_libraries(blink PUBLIC
    pthread
)