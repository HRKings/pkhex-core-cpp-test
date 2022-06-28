#include <iostream>
#include <cstddef>

#include "utils/utils.h"
#include "save/gen3/gen3_utils.h"

int main() {
    std::byte file_bytes[132000];

    FILE* ptr = fopen("../assets/test.sav","rb");  // r for read, b for binary

    fread(file_bytes,sizeof(file_bytes),1,ptr);

//    byte* saveA = &file_bytes[0x0];
    std::byte* saveB = &file_bytes[0x00E000];

    Trainer_Data data;

    for (short i = 0; i < 14; i += 1) {
        std::byte* current_section = &saveB[4096*i];

        int section_id = little_endian_u8_to_u16(&current_section[0x0FF4]);

        if(section_id == 0) {
            for( short j = 0; j < 8; j += 1) {
                printf("0x%X ", current_section[j]);
            }
            printf("\n");

            data = parse_trainer_data_from_byte_array(&current_section[0]);
            break;
        }
    }

    printf("Section ID: %d; ", data.section_info.section_id);
    printf("Save Index: %d; ", data.section_info.save_index);
    printf("Checksum: %u; ", data.section_info.checksum);
    printf("Signature: %u \n", data.section_info.signature);

    printf("Trainer name: %X %X %X %X %X %X %X; Gender: 0x%X \n", data.name[0], data.name[1], data.name[2], data.name[3], data.name[4], data.name[5], data.name[6], data.gender);
    printf("Player time is: %d hours, %d minutes, %d seconds, %d frames \n", data.time.hours, data.time.minutes, data.time.seconds, data.time.frames);
    printf("Their public ID is: %d and the secret one is: %d", data.id.public_id, data.id.secret_id);

    return 0;
}
