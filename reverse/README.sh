
# Reverse Engineering
#
#======================================
#--------------------------------------
# Registers

edi: destination index
esi: source index

#--------------------------------------
# RFLAGS

Symbol 	Bit Name 			Set if...
CF 		0 	Carry 			Operation generated a carry or borrow
PF 		2 	Parity 			Last byte has even number of 1s, else 0
AF 		4 	Adjust 			Denotes Binary Coded Decimal in-byte carry
ZF 		6 	Zero 			Result was 0
SF 		7 	Sign 			Most significant bit of result is 1
OF 		11 	Overflow 		Overflow on signed operation  	  	 
DF 		10 	Direction 		Direction string instructions operate (inc or dec)
ID 		21 	Identification 	Changeability denotes presence of CPUID instruction


#--------------------------------------
# Hex value

18h (hex) ==> 1*16 + 8 = 24
32h (hex) ==> 

#--------------------------------------
# rep movs

rep movsd  ==> rep movs dword (4 byte)
rep movsw  ==> rep movs word  (2 byte)
rep movsb  ==> rep movs byte  (1 byte)

rep:   repeat
movsd: move double word (4 bytes)

rep repeate the string operation ECX times
# REP MOVS DWORD PTR ES:[EDI], DWORD PTR [ESI]

http://x86.renejeschke.de/html/file_module_x86_id_279.html

#--------------------------------------








