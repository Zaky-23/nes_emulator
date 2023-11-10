#include "cpu.h"

#include <cstdint>

#include "bus.h"

Cpu::Cpu()
{
	bus_ = nullptr;
}

Cpu::~Cpu()
{
	bus_ = nullptr;
}

void Cpu::ConnectBus(const Bus *bus)
{
	bus_ = const_cast<Bus *>(bus);
}

void Cpu::Write(uint16_t addr, uint8_t data)
{
	bus_->Write(addr, data);
}

uint8_t Cpu::Read(uint16_t addr)
{
	return bus_->Read(addr);
}

bool Cpu::GetFlag(Flags flag)
{
	return register_s_ & static_cast<uint8_t>(flag);
}

void Cpu::SetFlag(Flags flag, bool value)
{
	switch (value)
	{
	case true:
		register_s_ |= static_cast<uint8_t>(flag);
		break;
	case false:
		register_s_ &= ~static_cast<uint8_t>(flag);
		break;
	}
}

uint8_t Cpu::IMP(void)
{
	return 0;
}

uint8_t Cpu::IMM(void)
{
	return 0;
}

uint8_t Cpu::ZP0(void)
{
	return 0;
}

uint8_t Cpu::ZPX(void)
{
	return 0;
}

uint8_t Cpu::ZPY(void)
{
	return 0;
}

uint8_t Cpu::REL(void)
{
	return 0;
}

uint8_t Cpu::ABS(void)
{
	return 0;
}

uint8_t Cpu::ABX(void)
{
	return 0;
}

uint8_t Cpu::ABY(void)
{
	return 0;
}

uint8_t Cpu::IND(void)
{
	return 0;
}

uint8_t Cpu::IZX(void)
{
	return 0;
}

uint8_t Cpu::IZY(void)
{
	return 0;
}
