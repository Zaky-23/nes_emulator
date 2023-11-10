#pragma once

#include "bus.h"
#include "cpu.h"

class Machine
{
public:
	Machine();

private:
	Cpu cpu_;
	Bus bus_;
};