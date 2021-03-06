/*
 *   bekOS is a basic OS for the Raspberry Pi
 *
 *   Copyright (C) 2020  Bekos Inc Ltd
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <memory_locations.h>
#include <peripherals/gpio.h>
#include <peripherals/interrupt_controller.h>
#include <interrupts/int_ctrl.h>
#include "printf.h"

extern interrupt_controller interruptController;

extern "C"
void show_unknown_int_complaint(unsigned long esr, unsigned long elr) {
    printf("Unknown Interrupt: ESR = %X, ELR = %X\n", esr, elr);
}

extern "C"
void handle_interrupt(unsigned long esr, unsigned long elr) {
    //printf("Interrupt: ESR = %X, ELR = %X\n", esr, elr);
    // Try BCM
    if (interruptController.handle()) {
        // Success
        return;
    } else {
        // TODO: Disaster
        printf("Disaster");
        return;
    }
}