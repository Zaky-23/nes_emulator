#include "bus.h"

#include <cstdint>

#include "config.h"

Bus::Bus()
{
	ram_ = new uint8_t[config::kRamSize];
}

Bus::~Bus()
{
	delete[] ram_;
}

void Bus::Write(uint16_t addr, uint8_t data)
{
	if (addr > config::kMaxAddressableMemory) return;
	ram_[addr] = data;
}

uint8_t Bus::Read(uint16_t addr, bool read_only)
{
	if (addr > config::kMaxAddressableMemory) return 0;
	return ram_[addr];
}
