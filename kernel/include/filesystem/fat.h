/*
 *   bekOS is a basic OS for the Raspberry Pi
 *
 *   Copyright (C) 2019  Bekos Inc Ltd
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
#ifndef BEKOS_FAT_H
#define BEKOS_FAT_H

#include <stddef.h>
#include "hdevice.h"
#include "partition.h"

class FAT_Entry {
    char name[8];
    char ext[3];
    uint8_t attrib;
    unsigned int size;
    unsigned int start_cluster;

};

class file_allocation_table {
public:
    file_allocation_table(partition* mPartition);

    void init();

private:
    unsigned int get_next_cluster(unsigned int current_cluster);
    void* fetch_sector(unsigned int cluster, unsigned int sector);


    void init_from_bpb(void* buf, size_t size);
    unsigned long fat_begin_lba;
    unsigned long cluster_begin_lba;
    unsigned long sectors_per_cluster;
    unsigned long root_dir_first_cluster;
    uint8_t m_buffer[512];
    hdevice* m_partition;
};

#endif //BEKOS_FAT_H
