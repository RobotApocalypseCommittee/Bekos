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

#include <memory_manager.h>
#include <peripherals/peripherals.h>
#include <utils.h>

extern "C" {

int liballoc_lock() { // TODO
    return 0;
}

int liballoc_unlock() { // TODO
    return 0;
}

void* liballoc_alloc(uSize pages) {
    return reinterpret_cast<void*>(mapped_address(memoryManager.reserve_region(pages, PAGE_KERNEL)));
}

int liballoc_free(void* ptr, uSize pages) {
    return !memoryManager.free_region(bus_address(reinterpret_cast<unsigned long>(ptr)), pages);
}
}