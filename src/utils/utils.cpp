#include "utils.h"

unsigned short little_endian_u8_to_u16(std::byte *bytes) {
    unsigned short result = static_cast<unsigned short>(bytes[1]) << 8;
    result |= static_cast<unsigned short>(bytes[0]);

    return result;
}


unsigned int little_endian_u8_to_u32(std::byte *bytes) {
    unsigned int result = static_cast<unsigned short>(bytes[3]) << 24;
    result |= static_cast<unsigned short>(bytes[2]) << 16;
    result |= static_cast<unsigned short>(bytes[1]) << 8;
    result |= static_cast<unsigned short>(bytes[0]);

    return result;
}