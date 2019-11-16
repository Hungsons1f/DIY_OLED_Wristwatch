

static const unsigned char Zero [] = {
0x00, 0x00, 0x80, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x70, 0xF0, 0xE0, 0x80,
0x00, 0x00, 0xF0, 0xFF, 0xFF, 0x3F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x3F, 0xFF, 0xFF, 0xF0, 0x0F, 0x7F, 0xFF, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0xF8, 0xFF, 0x7F, 0x0F, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x1E, 0x1C, 0x1C, 0x1C,
0x1C, 0x1E, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 
};

static const unsigned char One [] = {
0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x38, 0x38, 0x38, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char Two [] = {
0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x78, 0x70, 0xF0, 0xE0, 0xC0,
0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF1,
0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x78, 0x3C, 0x1E, 0x0F,
0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E,
0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 
};

static const unsigned char Three [] = {
0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x70, 0xF0, 0xF0, 0xE0,
0x80, 0x00, 0x00, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xF8,
0x7F, 0x3F, 0x0F, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
0x03, 0x07, 0xFF, 0xFE, 0xFC, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x0E, 0x1C, 0x1C, 0x1C, 0x1C,
0x1C, 0x1C, 0x0E, 0x0F, 0x07, 0x07, 0x01, 0x00, 
};

static const unsigned char Four [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF8, 0xF8, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0x7C, 0x1E, 0x0F, 0x07, 0xFF, 0xFF,
0xFF, 0x00, 0x00, 0x00, 0x40, 0x60, 0x78, 0x7C, 0x7F, 0x77, 0x73, 0x70, 0x70, 0x70, 0x70, 0x70,
0xFF, 0xFF, 0xFF, 0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 
};

static const unsigned char Five [] = {
0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
0x10, 0x00, 0x00, 0x00, 0xE0, 0xFE, 0x7F, 0x3F, 0x31, 0x38, 0x38, 0x38, 0x38, 0x78, 0x70, 0xF0,
0xE0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x81, 0xFF, 0xFF, 0xFF, 0x3E, 0x00, 0x03, 0x07, 0x0F, 0x0E, 0x1E, 0x1C, 0x1C, 0x1C, 0x1C,
0x1C, 0x0E, 0x0E, 0x0F, 0x07, 0x03, 0x01, 0x00, 
};

static const unsigned char Six [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xF0, 0xF8, 0x38, 0x10, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xFC, 0xDF, 0xCF, 0xE3, 0xE1, 0xE0, 0xC0, 0xC0,
0x80, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x03, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0E, 0x1C, 0x1C, 0x1C, 0x1C,
0x1C, 0x1C, 0x0E, 0x0F, 0x07, 0x03, 0x01, 0x00, 
};

static const unsigned char Seven [] = {
0x00, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0xB8, 0xF8, 0xF8, 0x78,
0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFC, 0x7F, 0x1F, 0x07,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x7E, 0x1F, 0x07, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0E, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char Eight [] = {
0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x18, 0x18, 0x38, 0x38, 0x70, 0xF0, 0xE0, 0xC0,
0x00, 0x00, 0x00, 0x07, 0x1F, 0x3F, 0xFF, 0xF0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xF0, 0x7F,
0x3F, 0x1F, 0x07, 0x00, 0x00, 0xFC, 0xFE, 0xFF, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01,
0x03, 0x07, 0xFF, 0xFE, 0xFC, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0E, 0x1C, 0x1C, 0x1C, 0x1C,
0x1C, 0x1C, 0x0E, 0x0F, 0x0F, 0x07, 0x03, 0x00, 
};

static const unsigned char Nine [] = {
0x00, 0x00, 0xC0, 0xE0, 0xF0, 0x70, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x70, 0xF0, 0xE0, 0xC0,
0x80, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xE1, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0,
0xFF, 0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x87, 0xC7, 0xE3, 0xFB, 0x7F,
0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x1E, 0x0F, 0x07, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char Zeros [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x3C, 0x06, 0x03, 0x03, 0x03, 0x06,
0x3C, 0xF0, 0x03, 0x0F, 0x18, 0x10, 0x10, 0x10, 0x18, 0x0F, 0x03, 
};

static const unsigned char Ones [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x1F, 0x00, 0x00, 0x00, 
};

static const unsigned char Twos [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0E, 0x02, 0x03, 0x03, 0xC3, 0xE6,
0x3C, 0x00, 0x10, 0x18, 0x1C, 0x1E, 0x1B, 0x19, 0x18, 0x18, 0x00, 
};

static const unsigned char Threes [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0E, 0x02, 0x43, 0x43, 0x43, 0xE6,
0xBE, 0x00, 0x04, 0x1C, 0x18, 0x10, 0x10, 0x10, 0x18, 0x0F, 0x00, 
};

static const unsigned char Fours [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x60, 0x18, 0x0C, 0xFF,
0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x1F, 0x02, 0x02, 
};

static const unsigned char Fives [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x3F, 0x33, 0x33, 0x33, 0x63,
0xE3, 0x80, 0x08, 0x18, 0x18, 0x10, 0x10, 0x18, 0x1C, 0x0F, 0x03, 
};

static const unsigned char Sixs [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0x70, 0x58, 0x6C, 0x66, 0xC3,
0x80, 0x00, 0x07, 0x0F, 0x18, 0x10, 0x10, 0x10, 0x18, 0x0F, 0x00, 
};

static const unsigned char Sevens [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x83, 0xE3, 0x3B, 0x0F,
0x03, 0x00, 0x00, 0x18, 0x0E, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const unsigned char Eights [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0xBE, 0xE3, 0x61, 0x61, 0xE3, 0xBE,
0x1C, 0x00, 0x0F, 0x1F, 0x18, 0x10, 0x10, 0x18, 0x1F, 0x0F, 0x00, 
};

static const unsigned char Nines [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x7E, 0xC2, 0x83, 0x83, 0x83, 0xC6,
0x7C, 0x00, 0x00, 0x00, 0x10, 0x1C, 0x06, 0x03, 0x01, 0x00, 0x00, 
};

static const unsigned char Dots [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x3E, 0x3E, 0x0E, 0x00, 0x00,
0x00, 0x00, 0x70, 0x7C, 0x7C, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};