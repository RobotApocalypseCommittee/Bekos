#[[add_executable(kernel kernel.cpp boot/boot.S mm.S
        peripherals/peripherals.cpp peripherals/gentimer.cpp peripherals/uart.cpp peripherals/mailbox.cpp peripherals/property_tags.cpp peripherals/emmc.cpp peripherals/system_timer.cpp peripherals/interrupt_controller.cpp
        library/liballoc.cpp library/stubs.cpp library/assert.cpp library/utility.cpp library/lock.cpp library/string.cpp library/kstring.cpp
        filesystem/mbr.cpp filesystem/fat.cpp filesystem/partition.cpp filesystem/filesystem.cpp filesystem/fatfs.cpp filesystem/entrycache.cpp filesystem/blockcache.cpp filesystem/cacheddevice.cpp filesystem/device.cpp
        printf.cpp utils.cpp page_mapping.cpp memory_manager.cpp
        interrupts/int_handle_utils.cpp interrupts/int_handle.S interrupts/int_ctrl.S
        process/process.cpp process/process_entry.S process/elf.cpp process/syscalls.cpp peripherals/framebuffer.cpp
        #usb/DWHost.cpp usb/DWRootPort.cpp usb/Device.cpp
        usbborrowed/rpi-usb.cpp ../include/mm/hw_ptr.h boot/boot.cpp)]]

add_executable(kernel boot/boot.S boot/boot.cpp peripherals/peripherals.cpp peripherals/gentimer.cpp peripherals/mailbox.cpp
        peripherals/property_tags.cpp peripherals/framebuffer.cpp peripherals/uart.cpp
        library/liballoc.cpp library/stubs.cpp library/assert.cpp library/kstring.cpp
        printf.cpp utils.cpp memory_manager.cpp ../include/mm/hw_ptr.h mm/page_table.cpp)


target_include_directories(kernel PRIVATE ../include)

target_compile_options(kernel PRIVATE -ffreestanding -fbuiltin
        -fno-asynchronous-unwind-tables -fno-exceptions -fno-rtti -fpie
        -nostdlib -nostartfiles -Waddress-of-packed-member
        -Wall -Wextra)
target_link_options(kernel PRIVATE -nodefaultlibs -nostdlib -nostartfiles -static-pie -fpie -T${CMAKE_SOURCE_DIR}/kernel-link.ld)
target_link_libraries(kernel gcc)

set_target_properties(kernel PROPERTIES
        LINK_DEPENDS "${CMAKE_SOURCE_DIR}/kernel-link.ld"
        SUFFIX ".elf")

add_custom_command(TARGET kernel POST_BUILD
        COMMAND "${objcopy_location}" "${CMAKE_CURRENT_BINARY_DIR}/kernel.elf" "-O" "binary" "${CMAKE_BINARY_DIR}/kernel8.img"
        VERBATIM)

