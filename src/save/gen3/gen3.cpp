#include <algorithm>
#include "gen3_data.h"
#include "../../utils/utils.h"

Trainer_Data parse_trainer_data_from_byte_array(std::byte *section_bytes) {
    Trainer_Data result;
    Section_Data sectionData;
    Trainer_ID id;
    Played_Time time;

    std::copy(section_bytes, &section_bytes[6], result.name);
    result.gender = section_bytes[0x0008];

    id.trainer_id = little_endian_u8_to_u32(&section_bytes[0x000A]);
    id.secret_id = little_endian_u8_to_u16(&section_bytes[0x000A]);
    id.public_id = little_endian_u8_to_u16(&section_bytes[0x000A+2]);
    result.id = id;

    std::copy(&section_bytes[0x000E], &section_bytes[0x000E +5], time.time);
    time.hours = little_endian_u8_to_u16(&section_bytes[0x000E]);
    time.minutes = section_bytes[0x000E +2];
    time.seconds = section_bytes[0x000E +3];
    time.frames = section_bytes[0x000E +4];
    result.time = time;

    sectionData.section_id = little_endian_u8_to_u16(&section_bytes[0x0FF4]);
    sectionData.checksum = little_endian_u8_to_u16(&section_bytes[0x0FF6]);
    sectionData.signature = little_endian_u8_to_u32(&section_bytes[0x0FF8]);
    sectionData.save_index = little_endian_u8_to_u32(&section_bytes[0x0FFC]);
    result.section_info = sectionData;

    return result;
}