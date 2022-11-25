/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2019 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#if !defined(__EDID_PARSER_H__)
#define __EDID_PARSER_H__

#include <stddef.h>
#include <stdint.h>

namespace edid_parser {

enum edid_status_e {
    EDID_STATUS_OK,
    EDID_STATUS_INVALID_PARAMETER,
    EDID_STATUS_NOT_SUPPORTED,
    EDID_STATUS_INVALID_HEADER,
    EDID_STATUS_INVALID_CHECKSUM
};

enum edid_native_e {
    EDID_NATIVE,
    EDID_NOT_NATIVE
};

enum edid_progressive_e {
    EDID_PROGRESSIVE,
    EDID_INTERLACED
};

enum HDR_standard_t {
    HDR_standard_NONE = 0x0,
    HDR_standard_HDR10 = 0x01, // SMPTE ST 2084
    HDR_standard_HLG = 0x02, // Hybrid Log-Gamma
    HDR_standard_DolbyVersion = 0x04, // ?
    HDR_standard_SDR = 0x08, // Traditional gamma - SDR Luminance Range
    HDR_standard_Traditional_HDR = 0x10 // Traditional gamma - HDR Luminance Range
};

struct edid_res_t {
    int width;
    int height;
    int refresh;
    edid_progressive_e progressive;
    edid_native_e native;
};

enum colorimetry_info_t {
    COLORIMETRY_INFO_NONE = 0x0,
    COLORIMETRY_INFO_XVYCC601 = 0x01,
    COLORIMETRY_INFO_XVYCC709 = 0x02,
    COLORIMETRY_INFO_SYCC601 = 0x04,
    COLORIMETRY_INFO_ADOBEYCC601 = 0x08,
    COLORIMETRY_INFO_ADOBERGB = 0x10,
    COLORIMETRY_INFO_BT2020CL = 0x20,
    COLORIMETRY_INFO_BT2020NCL = 0x40,
    COLORIMETRY_INFO_BT2020RGB = 0x80,
    COLORIMETRY_INFO_DCI_P3 = 0x100
};

struct edid_data_t {
    edid_res_t res;
    // bitmask of HDR_standard_t values
    uint8_t hdr_capabilities;
    char manufacturer_name[4];      /* Manufacturer name of the display device.*/
    int32_t product_code;          /* Product code of the display device. */
    int32_t serial_number;          /* Serial number of the display device. */
    int32_t manufacture_week;       /* Manufacturing week of the display device. */
    int32_t manufacture_year;       /* Manufacturing year of the display device. */
    uint8_t edid_version[2];         /* EDID version. */
    uint8_t physical_address_a;     /* Physical Address for HDMI node A */
    uint8_t physical_address_b;     /* Physical Address for HDMI node B */
    uint8_t physical_address_c;     /* Physical Address for HDMI node C */
    uint8_t physical_address_d;     /* Physical Address for HDMI node D */
    char monitor_name[14];          /* Connected display monitor name. */
    uint32_t colorimetry_info;      /* bitmask of enum colorimetry_info_t */
};

edid_status_e EDID_Parse(unsigned char* bytes, size_t count, edid_data_t* data_ptr);
edid_status_e EDID_Verify(unsigned char* bytes, size_t count);
}
#endif /* __EDID_PARSER_H__ */
