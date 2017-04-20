// Copyright (c) 2016 Kumina, https://kumina.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#ifndef RAW_PACKET_PROCESSOR_H
#define RAW_PACKET_PROCESSOR_H

#include <cstddef>
#include <experimental/string_view>

// Interface for handling raw network packets.
class RawPacketProcessor {
 public:
  virtual void ProcessPacket(
      std::experimental::basic_string_view<unsigned char> bytes,
      std::size_t original_length) = 0;
};

#endif
