#include <cstddef>;

struct Played_Time {
    std::byte time[5];
    unsigned short hours;
    std::byte minutes;
    std::byte seconds;
    std::byte frames;
};

struct Trainer_ID {
    unsigned int trainer_id;
    unsigned short secret_id;
    unsigned short public_id;
};

struct Section_Data {
    unsigned short section_id;
    unsigned short checksum;
    unsigned int signature;
    unsigned int save_index;
};

struct Trainer_Data {
    Section_Data section_info;
    std::byte name[7];
    std::byte gender;
    Trainer_ID id;
    Played_Time time;
};