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

#ifndef BEKOS_USB_DEVICE_H
#define BEKOS_USB_DEVICE_H

#include "descriptors.h"
#include "library/vector.h"
#include "usb/transfers.h"

namespace usb {

/// A Device does a lot of things, and relies a lot on state - careful
class Device {
public:

private:
    /// Address assigned to device
    int m_address;

    /// Index assigned by driver
    int m_id;

    int m_max_packet_size;

    bek::own_ptr<DeviceDescriptor> descriptors;

    enum Status {  // USB 2.0 Spec 9.1
        Attached,
        Powered,
        Default,
        Address,
        Configured,
        Suspended
    } status;
};
}
#endif  // BEKOS_USB_DEVICE_H
