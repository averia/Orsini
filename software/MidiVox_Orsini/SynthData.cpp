#include "SynthData.h"

const prog_uint8_t sineTable[]  PROGMEM = {
  0x80, 0x83, 0x86, 0x89, 0x8C, 0x8F, 0x92, 0x95, 0x98, 0x9B, 0x9E, 0xA2, 
  0xA5, 0xA7, 0xAA, 0xAD, 0xB0, 0xB3, 0xB6, 0xB9, 0xBC, 0xBE, 0xC1, 0xC4, 
  0xC6, 0xC9, 0xCB, 0xCE, 0xD0, 0xD3, 0xD5, 0xD7, 0xDA, 0xDC, 0xDE, 0xE0, 
  0xE2, 0xE4, 0xE6, 0xE8, 0xEA, 0xEB, 0xED, 0xEE, 0xF0, 0xF1, 0xF3, 0xF4, 
  0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC, 0xFD, 0xFD, 0xFE, 0xFE, 
  0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD, 
  0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6, 0xF5, 0xF4, 0xF3, 0xF1, 
  0xF0, 0xEE, 0xED, 0xEB, 0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC, 
  0xDA, 0xD7, 0xD5, 0xD3, 0xD0, 0xCE, 0xCB, 0xC9, 0xC6, 0xC4, 0xC1, 0xBE, 
  0xBC, 0xB9, 0xB6, 0xB3, 0xB0, 0xAD, 0xAA, 0xA7, 0xA5, 0xA2, 0x9E, 0x9B, 
  0x98, 0x95, 0x92, 0x8F, 0x8C, 0x89, 0x86, 0x83, 0x80, 0x7D, 0x7A, 0x77, 
  0x74, 0x71, 0x6E, 0x6B, 0x68, 0x65, 0x62, 0x5E, 0x5B, 0x59, 0x56, 0x53, 
  0x50, 0x4D, 0x4A, 0x47, 0x44, 0x42, 0x3F, 0x3C, 0x3A, 0x37, 0x35, 0x32, 
  0x30, 0x2D, 0x2B, 0x29, 0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18, 
  0x16, 0x15, 0x13, 0x12, 0x10, 0x0F, 0x0D, 0x0C, 0x0B, 0x0A, 0x08, 0x07, 
  0x06, 0x06, 0x05, 0x04, 0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x05, 0x06, 
  0x06, 0x07, 0x08, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x12, 0x13, 0x15, 
  0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24, 0x26, 0x29, 0x2B, 0x2D, 
  0x30, 0x32, 0x35, 0x37, 0x3A, 0x3C, 0x3F, 0x42, 0x44, 0x47, 0x4A, 0x4D, 
  0x50, 0x53, 0x56, 0x59, 0x5B, 0x5E, 0x62, 0x65, 0x68, 0x6B, 0x6E, 0x71, 
  0x74, 0x77, 0x7A, 0x7D

};

const prog_uint8_t triTable[] PROGMEM = {
  0x80, 0x81, 0x83, 0x85, 0x87, 0x89, 0x8B, 0x8D, 0x8F, 0x91, 0x93, 0x95,
  0x97, 0x99, 0x9B, 0x9D, 0x9F, 0xA1, 0xA3, 0xA5, 0xA7, 0xA9, 0xAB, 0xAD, 
  0xAF, 0xB1, 0xB3, 0xB5, 0xB7, 0xB9, 0xBB, 0xBD, 0xBF, 0xC1, 0xC3, 0xC5, 
  0xC7, 0xC9, 0xCB, 0xCD, 0xCF, 0xD1, 0xD3, 0xD5, 0xD7, 0xD9, 0xDB, 0xDD, 
  0xDF, 0xE1, 0xE3, 0xE5, 0xE7, 0xE9, 0xEB, 0xED, 0xEF, 0xF1, 0xF3, 0xF5, 
  0xF7, 0xF9, 0xFB, 0xFD, 0xFF, 0xFD, 0xFB, 0xF9, 0xF7, 0xF5, 0xF3, 0xF1, 
  0xEF, 0xED, 0xEB, 0xE9, 0xE7, 0xE5, 0xE3, 0xE1, 0xDF, 0xDD, 0xDB, 0xD9, 
  0xD7, 0xD5, 0xD3, 0xD1, 0xCF, 0xCD, 0xCB, 0xC9, 0xC7, 0xC5, 0xC3, 0xC1, 
  0xBF, 0xBD, 0xBB, 0xB9, 0xB7, 0xB5, 0xB3, 0xB1, 0xAF, 0xAD, 0xAB, 0xA9, 
  0xA7, 0xA5, 0xA3, 0xA1, 0x9F, 0x9D, 0x9B, 0x99, 0x97, 0x95, 0x93, 0x91, 
  0x8F, 0x8D, 0x8B, 0x89, 0x87, 0x85, 0x83, 0x81, 0x7F, 0x7D, 0x7B, 0x79, 
  0x77, 0x75, 0x73, 0x71, 0x6F, 0x6D, 0x6B, 0x69, 0x67, 0x65, 0x63, 0x61, 
  0x5F, 0x5D, 0x5B, 0x59, 0x57, 0x55, 0x53, 0x51, 0x4F, 0x4D, 0x4B, 0x49, 
  0x47, 0x45, 0x43, 0x41, 0x3F, 0x3D, 0x3B, 0x39, 0x37, 0x35, 0x33, 0x31, 
  0x2F, 0x2D, 0x2B, 0x29, 0x27, 0x25, 0x23, 0x21, 0x1F, 0x1D, 0x1B, 0x19, 
  0x17, 0x15, 0x13, 0x11, 0x0F, 0x0D, 0x0B, 0x09, 0x07, 0x05, 0x03, 0x01, 
  0x03, 0x05, 0x07, 0x09, 0x0B, 0x0D, 0x0F, 0x11, 0x13, 0x15, 0x17, 0x19, 
  0x1B, 0x1D, 0x1F, 0x21, 0x23, 0x25, 0x27, 0x29, 0x2B, 0x2D, 0x2F, 0x31, 
  0x33, 0x35, 0x37, 0x39, 0x3B, 0x3D, 0x3F, 0x41, 0x43, 0x45, 0x47, 0x49, 
  0x4B, 0x4D, 0x4F, 0x51, 0x53, 0x55, 0x57, 0x59, 0x5B, 0x5D, 0x5F, 0x61, 
  0x63, 0x65, 0x67, 0x69, 0x6B, 0x6D, 0x6F, 0x71, 0x73, 0x75, 0x77, 0x79, 
  0x7B, 0x7D, 0x7F, 0x80
};

const prog_uint8_t sawTable[]  PROGMEM = {
  0x80, 0x7F, 0x7E, 0x7D, 0x7C, 0x7B, 0x7A, 0x79, 0x78, 0x77, 0x76, 0x75,
  0x74, 0x73, 0x72, 0x71, 0x70, 0x6F, 0x6E, 0x6D, 0x6C, 0x6B, 0x6A, 0x69, 
  0x68, 0x67, 0x66, 0x65, 0x64, 0x63, 0x62, 0x61, 0x60, 0x5F, 0x5E, 0x5D, 
  0x5C, 0x5B, 0x5A, 0x59, 0x58, 0x57, 0x56, 0x55, 0x54, 0x53, 0x52, 0x51, 
  0x50, 0x4F, 0x4E, 0x4D, 0x4C, 0x4B, 0x4A, 0x49, 0x48, 0x47, 0x46, 0x45, 
  0x44, 0x43, 0x42, 0x41, 0x40, 0x3F, 0x3E, 0x3D, 0x3C, 0x3B, 0x3A, 0x39, 
  0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30, 0x2F, 0x2E, 0x2D, 
  0x2C, 0x2B, 0x2A, 0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 
  0x20, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x19, 0x18, 0x17, 0x16, 0x15, 
  0x14, 0x13, 0x12, 0x11, 0x10, 0x0F, 0x0E, 0x0D, 0x0C, 0x0B, 0x0A, 0x09, 
  0x08, 0x07, 0x06, 0x05, 0x04, 0x03, 0x02, 0x01, 0x01, 0xFF, 0xFE, 0xFD, 
  0xFC, 0xFB, 0xFA, 0xF9, 0xF8, 0xF7, 0xF6, 0xF5, 0xF4, 0xF3, 0xF2, 0xF1, 
  0xF0, 0xEF, 0xEE, 0xED, 0xEC, 0xEB, 0xEA, 0xE9, 0xE8, 0xE7, 0xE6, 0xE5, 
  0xE4, 0xE3, 0xE2, 0xE1, 0xE0, 0xDF, 0xDE, 0xDD, 0xDC, 0xDB, 0xDA, 0xD9, 
  0xD8, 0xD7, 0xD6, 0xD5, 0xD4, 0xD3, 0xD2, 0xD1, 0xD0, 0xCF, 0xCE, 0xCD, 
  0xCC, 0xCB, 0xCA, 0xC9, 0xC8, 0xC7, 0xC6, 0xC5, 0xC4, 0xC3, 0xC2, 0xC1, 
  0xC0, 0xBF, 0xBE, 0xBD, 0xBC, 0xBB, 0xBA, 0xB9, 0xB8, 0xB7, 0xB6, 0xB5, 
  0xB4, 0xB3, 0xB2, 0xB1, 0xB0, 0xAF, 0xAE, 0xAD, 0xAC, 0xAB, 0xAA, 0xA9, 
  0xA8, 0xA7, 0xA6, 0xA5, 0xA4, 0xA3, 0xA2, 0xA1, 0xA0, 0x9F, 0x9E, 0x9D, 
  0x9C, 0x9B, 0x9A, 0x99, 0x98, 0x97, 0x96, 0x95, 0x94, 0x93, 0x92, 0x91, 
  0x90, 0x8F, 0x8E, 0x8D, 0x8C, 0x8B, 0x8A, 0x89, 0x88, 0x87, 0x86, 0x85, 
  0x84, 0x83, 0x82, 0x81 
};



/*
const prog_uint8_t sineDoubleTable[] PROGMEM = {
  0x80, 0x3C, 0x86, 0x42, 0x8C, 0x47, 0x92, 0x4D, 0x98, 0x53, 0x9E, 0x59, 
  0xA5, 0x5E, 0xAA, 0x65, 0xB0, 0x6B, 0xB6, 0x71, 0xBC, 0x77, 0xC1, 0x7D, 
  0xC6, 0x83, 0xCB, 0x89, 0xD0, 0x8F, 0xD5, 0x95, 0xDA, 0x9B, 0xDE, 0xA2, 
  0xE2, 0xA7, 0xE6, 0xAD, 0xEA, 0xB3, 0xED, 0xB9, 0xF0, 0xBE, 0xF3, 0xC4, 
  0xF5, 0xC9, 0xF8, 0xCE, 0xFA, 0xD3, 0xFB, 0xD7, 0xFD, 0xDC, 0xFE, 0xE0, 
  0xFE, 0xE4, 0xFF, 0xE8, 0xFF, 0xEB, 0xFF, 0xEE, 0xFE, 0xF1, 0xFE, 0xF4, 
  0xFD, 0xF6, 0xFB, 0xF9, 0xFA, 0xFA, 0xF8, 0xFC, 0xF5, 0xFD, 0xF3, 0xFE, 
  0xF0, 0xFF, 0xED, 0xFF, 0xEA, 0xFF, 0xE6, 0xFF, 0xE2, 0xFE, 0xDE, 0xFD, 
  0xDA, 0xFC, 0xD5, 0xFA, 0xD0, 0xF9, 0xCB, 0xF6, 0xC6, 0xF4, 0xC1, 0xF1, 
  0xBC, 0xEE, 0xB6, 0xEB, 0xB0, 0xE8, 0xAA, 0xE4, 0xA5, 0xE0, 0x9E, 0xDC, 
  0x98, 0xD7, 0x92, 0xD3, 0x8C, 0xCE, 0x86, 0xC9, 0x80, 0xC4, 0x7A, 0xBE, 
  0x74, 0xB9, 0x6E, 0xB3, 0x68, 0xAD, 0x62, 0xA7, 0x5B, 0xA2, 0x56, 0x9B, 
  0x50, 0x95, 0x4A, 0x8F, 0x44, 0x89, 0x3F, 0x83, 0x3A, 0x7D, 0x35, 0x77, 
  0x30, 0x71, 0x2B, 0x6B, 0x26, 0x65, 0x22, 0x5E, 0x1E, 0x59, 0x1A, 0x53, 
  0x16, 0x4D, 0x13, 0x47, 0x10, 0x42, 0x0D, 0x3C, 0x0B, 0x37, 0x08, 0x32, 
  0x06, 0x2D, 0x05, 0x29, 0x03, 0x24, 0x02, 0x20, 0x02, 0x1C, 0x01, 0x18, 
  0x01, 0x15, 0x01, 0x12, 0x02, 0x0F, 0x02, 0x0C, 0x03, 0x0A, 0x05, 0x07, 
  0x06, 0x06, 0x08, 0x04, 0x0B, 0x03, 0x0D, 0x02, 0x10, 0x01, 0x13, 0x01, 
  0x16, 0x01, 0x1A, 0x01, 0x1E, 0x02, 0x22, 0x03, 0x26, 0x04, 0x2B, 0x06, 
  0x30, 0x07, 0x35, 0x0A, 0x3A, 0x0C, 0x3F, 0x0F, 0x44, 0x12, 0x4A, 0x15, 
  0x50, 0x18, 0x56, 0x1C, 0x5B, 0x20, 0x62, 0x24, 0x68, 0x29, 0x6E, 0x2D, 
  0x74, 0x32, 0x7A, 0x37
};
*/

const prog_uint8_t squareTable[]  PROGMEM =  {
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00
};

const prog_uint8_t stairExpTable[] PROGMEM = {
  0x80, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 
  0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
  0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
  0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
  0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
  0xBF, 0xBF, 0xBF, 0xBF, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
  0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
  0x01, 0x00, 0x01, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80,
  
};

/*
const prog_uint8_t particularDoubleShallowTable[] PROGMEM = {
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 
  0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x26, 0x26, 0x26, 0x26, 
  0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 
  0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 
  0xB6, 0xB6, 0xB6, 0xB6, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 
  0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0xDA, 0xDA, 0xDA, 0xDA, 
  0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 
  0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 
  0x6E, 0x6E, 0x6E, 0x6E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80, 
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
  0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 
  0x92, 0x92, 0x92, 0x92, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 
  0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0x26, 0xB6, 0xB6, 0xB6, 0xB6, 
  0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 
  0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 0x4A, 
  0x4A, 0x4A, 0x4A, 0x4A, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 
  0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0x6E, 0x6E, 0x6E, 0x6E, 
  0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 0x6E, 
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
  0xFF, 0xFF, 0x80, 0x80
};
*/
const prog_uint8_t particularHardTable[] PROGMEM ={
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x00,
0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00,
0x01, 0x00, 0x01, 0x00, 0x01, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6,
0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6,
0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x34, 0x34,
0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34,
0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34,
0x34, 0x34, 0x34, 0x34, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA,
0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA,
0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0x5F, 0x5F, 0x5F,
0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F,
0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F,
0x5F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x80, 0x80, 0x80
};

const prog_uint8_t particularSoftTable[] PROGMEM = {
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x81, 0x82, 0x83, 0x84, 0x86, 0x88, 0x8D, 0x92, 0x92, 0x92, 0x92,
  0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
  0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
  0x92, 0x92, 0x92, 0x85, 0x78, 0x6B, 0x5F, 0x55, 0x4B, 0x3E, 0x32, 0x25,
  0x19, 0x0F, 0x05, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x02, 0x0B, 0x14, 0x23, 0x32, 0x3C, 0x46, 0x50, 0x5A, 0x69, 0x78, 0x97,
  0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6,
  0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6,
  0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0xB6, 0x97, 0x78, 0x6A, 0x5C, 0x4E,
  0x40, 0x3C, 0x38, 0x36, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34, 0x34,
  0x34, 0x34, 0x34, 0x34, 0x34, 0x37, 0x3A, 0x3F, 0x45, 0x53, 0x62, 0x6E,
  0x7A, 0x96, 0xB3, 0xC6, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA,
  0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA,
  0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xDA, 0xCC,
  0xBE, 0xB0, 0xA3, 0x94, 0x86, 0x7A, 0x6E, 0x69, 0x64, 0x61, 0x5F, 0x5F,
  0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x61, 0x64, 0x69, 0x6E, 0x77,
  0x81, 0x8B, 0x96, 0xA0, 0xAA, 0xBE, 0xD2, 0xE8, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xF0, 0xE2, 0xD5, 0xC9, 0xC0, 0xB8, 0xAD, 0xA3, 0x95, 0x88, 0x85,
  0x82, 0x81, 0x80, 0x80, 
};









