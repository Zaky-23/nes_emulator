#include "machine.h"

Machine::Machine()
{
	cpu_.ConnectBus(&bus_);
}