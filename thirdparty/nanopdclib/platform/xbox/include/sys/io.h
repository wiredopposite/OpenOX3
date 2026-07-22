#pragma once

static inline void outl(unsigned short Port, unsigned long Value)
{
	__asm {
		mov eax, Value
		mov dx, Port
		out dx, eax
	}
}

static inline void outw(unsigned short Port, unsigned short Value)
{
	__asm {
		mov ax, Value
		mov dx, Port
		out dx, ax
	}
}

static inline void outb(unsigned short Port, unsigned char Value)
{
	__asm {
		mov al, Value
		mov dx, Port
		out dx, al
	}
}

static inline unsigned long inl(unsigned short Port)
{
	__asm {
		mov dx, Port
		in eax, dx
	}
}

static inline unsigned short inw(unsigned short Port)
{
	__asm {
		mov dx, Port
		in ax, dx
	}
}

static inline unsigned char inb(unsigned short Port)
{
	__asm {
		mov dx, Port
		in al, dx
	}
}
