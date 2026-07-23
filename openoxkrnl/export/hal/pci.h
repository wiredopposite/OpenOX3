#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define NV2A_MMIO_BASE   0xfef00000UL
#define APIC_MMIO_BASE   0xFEE00000UL
#define IOAPIC_MMIO_BASE 0xFEC00000UL

 // CMOS I/O ports
#define CMOS_PORT_CMD 0x70
#define CMOS_PORT_DATA 0x71

 // PIC i/o ports
#define PIC_MASTER_CMD          0x20
#define PIC_MASTER_DATA         0x21
#define PIC_MASTER_ELCR         0x4D0
#define PIC_SLAVE_CMD           0xA0
#define PIC_SLAVE_DATA          0xA1
#define PIC_SLAVE_ELCR          0x4D1

// Bus 0, device 0, function 0.
#define PCI_HOSTBRIDGE_DEVICE_ID   0
#define PCI_HOSTBRIDGE_FUNCTION_ID 0

// Bus 0, device 1, function 0.
#define PCI_LPCBRIDGE_DEVICE_ID          1
#define PCI_LPCBRIDGE_FUNCTION_ID        0
#define PCI_LPCBRIDGE_IO_REGISTER_BASE_0 0x8000

// Bus 0, device 1, function 1.
#define PCI_SMBUS_DEVICE_ID          1
#define PCI_SMBUS_FUNCTION_ID        1
#define PCI_SMBUS_IO_REGISTER_BASE_1 0xC000
#define PCI_SMBUS_IO_REGISTER_BASE_2 0xC200

// Bus 0, device 2, function 0.
#define PCI_USB0_DEVICE_ID   2
#define PCI_USB0_FUNCTION_ID 0

#define PCI_USB0_MEMORY_REGISTER_BASE_0 0xFED00000

// Bus 0, device 3, function 0.
#define PCI_USB1_DEVICE_ID              3
#define PCI_USB1_FUNCTION_ID            0
#define PCI_USB1_MEMORY_REGISTER_BASE_0 0xFED08000

// Bus 0, device 4, function 0.
#define PCI_NIC_DEVICE_ID              4
#define PCI_NIC_FUNCTION_ID            0
#define PCI_NIC_MEMORY_REGISTER_BASE_0 0xFEF00000
#define PCI_NIC_IO_REGISTER_BASE_1     0xE000

// Bus 0, device 5, function 0.
#define PCI_APU_DEVICE_ID              5
#define PCI_APU_FUNCTION_ID            0
#define PCI_APU_MEMORY_REGISTER_BASE_0 0xFE800000

// Bus 0, device 6, function 0.
#define PCI_ACI_DEVICE_ID              6
#define PCI_ACI_FUNCTION_ID            0
#define PCI_ACI_IO_REGISTER_BASE_0     0xD000
#define PCI_ACI_IO_REGISTER_BASE_1     0xD200
#define PCI_ACI_MEMORY_REGISTER_BASE_2 0xFEC00000

// Bus 0, device 9, function 0.
#define PCI_IDE_DEVICE_ID          9
#define PCI_IDE_FUNCTION_ID        0
#define PCI_IDE_IO_REGISTER_BASE_4 0xFF60

// Bus 0, device 30, function 0.
#define PCI_AGPBRIDGE_DEVICE_ID   30
#define PCI_AGPBRIDGE_FUNCTION_ID 0

// Bus 1, device 0, device 0.
#define PCI_GPU_DEVICE_ID              0
#define PCI_GPU_FUNCTION_ID            0
#define PCI_GPU_MEMORY_REGISTER_BASE_0 0xFD000000

// PIC icw1 command bytes
#define ICW1_ICW4_NEEDED        0x01
#define ICW1_CASCADE            0x00
#define ICW1_INTERVAL8          0x00
#define ICW1_EDGE               0x00
#define ICW1_INIT               0x10

// PIC icw4 command bytes
#define ICW4_8086               0x01
#define ICW4_NORNAL_EOI         0x00
#define ICW4_NON_BUFFERED       0x00
#define ICW4_NOT_FULLY_NESTED   0x00

// PIC ocw2 command bytes
#define OCW2_EOI_IRQ            0x60

// PIC ocw3 command bytes
#define OCW3_READ_ISR           0x0B

// PIC irq base (icw2)
#define PIC_MASTER_VECTOR_BASE  IDT_INT_VECTOR_BASE
#define PIC_SLAVE_VECTOR_BASE   (IDT_INT_VECTOR_BASE + 8)

// PCI ports
#define PCI_CONFIG_ADDRESS 0xCF8
#define PCI_CONFIG_DATA 0xCFC

// SMBUS ports
#define SMBUS_STATUS 0xC000
#define SMBUS_CONTROL 0xC002
#define SMBUS_ADDRESS 0xC004
#define SMBUS_DATA 0xC006
#define SMBUS_COMMAND 0xC008
#define SMBUS_FIFO 0xC009

// SMBUS constants
#define GS_PRERR_STS (1 << 2) // cycle failed
#define GS_HCYC_STS (1 << 4) // cycle succeeded
#define GE_RW_BYTE 2
#define GE_RW_WORD 3
#define GE_RW_BLOCK 5
#define GE_HOST_STC (1 << 3) // set to start a cycle
#define GE_HCYC_EN (1 << 4) // set to enable interrupts
#define HA_RC (1 << 0) // set to specify a read/receive cycle

// SMBUS sw addresses
#define EEPROM_WRITE_ADDR 0xA8
#define EEPROM_READ_ADDR 0xA9
#define SMC_WRITE_ADDR 0x20
#define SMC_READ_ADDR 0x21
#define CONEXANT_WRITE_ADDR 0x8A
#define CONEXANT_READ_ADDR 0x8B

// SMC video mode values
#define SMC_VIDEO_MODE_COMMAND   0x04
#define SMC_VIDEO_MODE_SCART     0x00
#define SMC_VIDEO_MODE_HDTV      0x01
#define SMC_VIDEO_MODE_VGA       0x02
#define SMC_VIDEO_MODE_RFU       0x03
#define SMC_VIDEO_MODE_SVIDEO    0x04
#define SMC_VIDEO_MODE_STANDARD  0x06
#define SMC_VIDEO_MODE_NONE      0x07

// SMC disc tray command
#define SMC_DISC_TRAY_COMMAND 0x03

#define SMC_SCRATCH_REGISTER_COMMAND 0x1b

#ifdef __cplusplus
}
#endif
