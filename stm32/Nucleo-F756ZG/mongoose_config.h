#pragma once

// See https://mongoose.ws/documentation/#build-options
#define MG_ARCH MG_ARCH_NEWLIB
#define MG_TLS MG_TLS_BUILTIN

#define MG_ENABLE_TCPIP 1
#define MG_ENABLE_CUSTOM_MILLIS 1
#define MG_ENABLE_CUSTOM_RANDOM 1
#define MG_ENABLE_PACKED_FS 1
#define MG_ENABLE_DRIVER_STM32F 1

// #define MG_DRIVER_MDC_CR 4   // RMII MDC clock divider, from 0 to 4
// #define MG_TCPIP_PHY_ADDR 0  // PHY address

// For static IP configuration, define MG_TCPIP_{IP,MASK,GW}
// By default, those are set to zero, meaning that DHCP is used
//
// #define MG_TCPIP_IP MG_IPV4(192, 168, 0, 10)
// #define MG_TCPIP_GW MG_IPV4(192, 168, 0, 1)
// #define MG_TCPIP_MASK MG_IPV4(255, 255, 255, 0)

// Construct MAC address from the MCU unique ID. It is defined in the
// ST CMSIS header as UID_BASE
#define UUID ((uint8_t *) 0x1ff0f420)  // Unique 96-bit chip ID
#define MG_SET_MAC_ADDRESS(mac)        \
  do {                                 \
    uint8_t buf_[6] = {                \
        2,                             \
        UUID[0] ^ UUID[1],             \
        UUID[2] ^ UUID[3],             \
        UUID[4] ^ UUID[5],             \
        UUID[6] ^ UUID[7] ^ UUID[8],   \
        UUID[9] ^ UUID[10] ^ UUID[11], \
    };                                 \
    memcpy(mac, buf_, sizeof(buf_));   \
  } while (0)
