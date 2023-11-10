#pragma once

#include <cstdint>

class Bus
{
public:
	Bus();
	~Bus();

public:
	void Write(uint16_t addr, uint8_t data);
	uint8_t Read(uint16_t addr, bool read_only = false);

private:
	uint8_t *ram_;
};
