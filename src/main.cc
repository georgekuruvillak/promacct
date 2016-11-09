// Copyright (c) 2016 Kumina, https://kumina.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#include <iostream>

#include "ipv4_ranges.h"
#include "packet_parser.h"
#include "parsed_packet_counter.h"
#include "parsed_packet_processor.h"
#include "pcap.h"

int main() {
  Pcap p;
  p.Activate("enp3s0", PacketParser::BytesNeededIPv4, 16 * 1024 * 1024);

  IPv4Ranges ir;
  ir.AddRange(0x0a000000, 0x0affffff);
  ParsedPacketCounter pc(&ir);
  PacketParser pa(&pc);

  for (;;)
    p.Dispatch(&pa);
}
