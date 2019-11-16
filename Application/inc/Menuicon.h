static const unsigned char AlarmMenu [] = {
	0x00, 0xf0, 0xf8, 0x9c, 0x8e, 0xc6, 0xe6, 0x7e, 0x3e, 0x9c, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0x60, 
	0x60, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x9c, 0x3e, 0x7e, 0xe6, 0xc6, 0x8e, 0x9c, 0xf8, 0xf0, 0x00, 
	0x00, 0x01, 0x03, 0x03, 0x83, 0xf1, 0xfc, 0x1e, 0x07, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0xfc, 
	0xfc, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x1e, 0xfc, 0xf1, 0x83, 0x03, 0x03, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x07, 0x3f, 0xfc, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x30, 0x38, 0x1e, 0x0f, 
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xfc, 0x3f, 0x07, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x20, 0x70, 0x38, 0x1f, 0x07, 0x07, 0x06, 0x0c, 0x0c, 0x1c, 0x18, 0x18, 
	0x18, 0x18, 0x1c, 0x0c, 0x0c, 0x06, 0x07, 0x07, 0x1f, 0x38, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char CounterMenu [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x40, 0x60, 0x67, 0x27, 0x3f, 0x3f,
	0x3f, 0x3f, 0x27, 0x67, 0x60, 0x40, 0xc0, 0x80, 0x30, 0x38, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x00,
	0x00, 0x00, 0x80, 0xe0, 0x38, 0x0e, 0x87, 0xe3, 0xf1, 0xf8, 0xfc, 0xfe, 0xfe, 0xfe, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x38, 0xe3, 0x03, 0x01, 0x00,
	0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x1f, 0x7f, 0x7f, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x1f, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x0c, 0x18, 0x30, 0x20, 0x60, 0x40, 0xc0, 0xc0, 0xc0, 0xc0,
	0x80, 0xc0, 0xc0, 0xc0, 0x40, 0x60, 0x20, 0x30, 0x18, 0x0c, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char FlashMenu [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x80, 0x80, 0x38, 0x78, 0xf8, 0xf0, 0xe6, 0xc7, 0x86, 0x00, 0x10, 0x38, 0x1c, 0x88, 0x80, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xcc,
	0x9f, 0x3f, 0x7f, 0xfe, 0xfc, 0xf9, 0xf3, 0xe7, 0xcf, 0x1f, 0x3e, 0x7c, 0x38, 0x03, 0x03, 0x01,
	0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xfa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f,
	0x1f, 0x0f, 0x06, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x1e, 0x3f, 0x7f, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char SettingMenu [] = {
	0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x78, 0x38, 0x78, 0x70, 0xf0, 0x70, 0x7e, 0x3f, 0x1f, 0x07,
	0x07, 0x3f, 0x3f, 0x7e, 0x70, 0xe0, 0x70, 0x78, 0x38, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00,
	0xe0, 0xf0, 0xf0, 0x71, 0x7b, 0x3f, 0x1f, 0x04, 0x00, 0xe0, 0xf8, 0x7c, 0x1c, 0x0e, 0x0e, 0x06,
	0x06, 0x0e, 0x0e, 0x1c, 0x7c, 0xf8, 0xe0, 0x00, 0x04, 0x1f, 0x3f, 0x7f, 0x71, 0xf0, 0xf0, 0xf0,
	0x07, 0x0f, 0x0f, 0x8e, 0xfe, 0xfc, 0x78, 0x00, 0x00, 0x07, 0x1f, 0x3e, 0x38, 0x70, 0x70, 0x60,
	0x60, 0x70, 0x70, 0x38, 0x3e, 0x1f, 0x07, 0x00, 0x00, 0x78, 0xfc, 0xde, 0x8e, 0x0f, 0x0f, 0x0f,
	0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1e, 0x1c, 0x1e, 0x0e, 0x0e, 0x0e, 0x7c, 0xfc, 0xf8, 0xe0,
	0xe0, 0xf8, 0xfc, 0x7c, 0x0e, 0x0e, 0x0e, 0x1e, 0x1c, 0x1e, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00
};

static const unsigned char CreditMenu [] = {
	0x00, 0x00, 0xff, 0xff, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
	0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63,
	0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6,
	0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0xc6, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
	0x00, 0x00, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0xff, 0x00, 0x00
};

static const unsigned char BackMenu [] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0x1e, 0x1e, 0x1e,
	0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0x1e, 0xfe, 0xfe, 0xfe, 0xfe,
	0x00, 0x00, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf3, 0xfb, 0xfb, 0xc3, 0xc0, 0xc0, 0xc0,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0x03, 0x03, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x1f, 0x3f, 0xbf, 0xff, 0xff, 0x87, 0x07, 0x07, 0x07,
	0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf8, 0xf8, 0xf8,
	0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0xff, 0xff
};

static const unsigned char TimeSettings []  = {
	0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x8f, 0xc7, 0xe3, 0xf3, 0xf1, 0xf9, 0xf9, 0xfc, 0xfc, 0xfc, 0xfc, 
	0x8c, 0xcc, 0xfc, 0xfc, 0xf9, 0xf9, 0xf1, 0xf3, 0xe3, 0xc7, 0x8f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 
	0x07, 0x01, 0xf0, 0x7c, 0x7f, 0x7f, 0xff, 0xff, 0xf3, 0xf3, 0xe7, 0xcf, 0x8f, 0x9f, 0x3f, 0x3f, 
	0x3f, 0x1f, 0x8f, 0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0xff, 0xff, 0x7f, 0x7f, 0x7e, 0xf0, 0x01, 0x07, 
	0xe0, 0x80, 0x0f, 0x3e, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 
	0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0x7e, 0x1f, 0x80, 0xe0, 
	0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf1, 0xe3, 0xc7, 0xcf, 0x8f, 0x9f, 0x9f, 0x3f, 0x3f, 0x3f, 0x3f, 
	0x21, 0x33, 0x3f, 0x3f, 0x9f, 0x9f, 0x8f, 0xcf, 0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0xfe, 0xff, 0xff
};

static const unsigned char SoundSettings []  = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 
	0x01, 0x01, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0x07, 0x03, 0x03, 0x03, 0x03, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0x9f, 0x3f, 0xfb, 0xf7, 0x8f, 0x3e, 0xfc, 0xf1, 0x07, 0x3f, 0xff, 
	0xff, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0xff, 0xff, 0xf9, 0xfc, 0xdf, 0xef, 0xf1, 0x7c, 0x3f, 0x8f, 0xe1, 0xfc, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf0, 0xe0, 0xc0, 
	0x80, 0x80, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const unsigned char SleepSettings []  = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0x2f, 0x4f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xf8, 0xfb, 0xff, 0xef, 0xef, 0x6f, 0x8f, 0xcf, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x39, 0x38, 0x3a, 0x3b, 0x3b, 0x3f, 0x1f, 
	0x0f, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
