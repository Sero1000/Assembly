#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstdint>
#include <vector>
#include <string>

using BYTE  = std::uint8_t;
using CHAR  = unsigned char;
using WORD  = std::uint16_t;
using DWORD = std::uint32_t;
using QWORD = std::uint64_t;

using StringVector = std::vector<std::string>;
using ByteVector = std::vector<BYTE>;
using CharVector = std::vector<CHAR>;

#endif
