#pragma once

#include <cstdint>

#include "bus.h"

class Cpu
{
public:
	Cpu();
	~Cpu();

public:
	void ConnectBus(const Bus *bus);

public:
	enum class Flags : uint8_t
	{	
		// Carry Bit
		kC = (1 << 0),
		// Zero Bit
		kZ = (1 << 1),
		// Integral Mode Bit
		kI = (1 << 2),
		// Decimal Mode Bit (unused)
		kD = (1 << 3),
		// Break Bit
		kB = (1 << 4),
		// Unused Bit
		kU = (1 << 5),
		// Overflow Bit
		kV = (1 << 6),
		// Negative Bit
		kN = (1 << 7),
	};

private:
	void Write(uint16_t addr, uint8_t data);
	uint8_t Read(uint16_t addr);
	bool GetFlag(Flags flag);
	void SetFlag(Flags flag, bool value);
	// Addressing Modes
	uint8_t IMP(void);
	uint8_t IMM(void);
	uint8_t ZP0(void);
	uint8_t ZPX(void);
	uint8_t ZPY(void);
	uint8_t REL(void);
	uint8_t ABS(void);
	uint8_t ABX(void);
	uint8_t ABY(void);
	uint8_t IND(void);
	uint8_t IZX(void);
	uint8_t IZY(void);

private:
	uint8_t register_a_;
	uint8_t register_x_;
	uint8_t register_y_;
	uint8_t register_s_;
	uint8_t stack_pointer_;
	uint16_t program_counter_;
	Bus *bus_;
};