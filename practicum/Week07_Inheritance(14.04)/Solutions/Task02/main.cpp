#include <iostream>
#include <string.h>

#include "Surgeon.h"
#include "Dentist.h"

int main()
{
    Doctor doctor = Doctor("Doctor");
    Surgeon surgeon = Surgeon("Surgeon");
    Dentist dentist = Dentist("Dentist");

    doctor.operation();
    surgeon.operation();
    dentist.operation();

    Doctor *doctor2 = &surgeon;
    Doctor *doctor3 = &dentist;

    doctor2->operation();
    doctor3->operation();
}