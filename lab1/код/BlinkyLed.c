

int main(){
	int i;
	unsigned long j;
	
	i = 0;
	j = 0;
	
	*(unsigned long*) (0x40023830) |= 0x80;  //  01000000  Enable prot H clocking
	
	*(unsigned long*) (0x40023830) |= 0x40;  //  01000000  Enable prot G clocking
	
	*(unsigned long*) (0x40023830) |= 0x100;  //  01000000  Enable prot I clocking
	
	
	for(i = 0; i < 4; ++i){}
		

		// 01000000000000  12th -> 1
		
		*(unsigned long*) (0x40022000) = (*(unsigned long*) (0x40022000) & (~0x200000)) | (0x100000); // set PI10 as General purpose output
		
		*(unsigned long*) (0x40021C00) = (*(unsigned long*) (0x40021C00) & (~0x00008000)) | (0x00004000); // set PH7 as General purpose output
		
		*(unsigned long*) (0x40021C00) = (*(unsigned long*) (0x40021C00) & (~0x00002000)) | (0x00001000); // set PH6 as General purpose output
		
		*(unsigned long*) (0x40021C00) = (*(unsigned long*) (0x40021C00) & (~0x80)) | (0x40); // set PH3 as General purpose output
		
		*(unsigned long*) (0x40021C00) = (*(unsigned long*) (0x40021C00) & (~0x20)) | (0x10); // set PH2 as General purpose output
		
		*(unsigned long*) (0x40021800) = (*(unsigned long*) (0x40021800) & (~0x00020000)) | (0x00010000); // set PG8 as General purpose output
		
		*(unsigned long*) (0x40021800) = (*(unsigned long*) (0x40021800) & (~0x00008000)) | (0x00004000); // set PG7 as General purpose output
		
		*(unsigned long*) (0x40021800) = (*(unsigned long*) (0x40021800) & (~0x00002000)) | (0x00001000); // set PG6 as General purpose output
		
		
		
		while(1){
			
			*(unsigned long*)(0x40022014) &= ~0x400;  // Turn LED OFF PI10
			
			*(unsigned long*)(0x40021C14) |= 0x80;  // Turn LED ON PH7 *
			
			*(unsigned long*)(0x40021C14) &= ~0x40;  // TURN LED OFF PH6
			
			*(unsigned long*)(0x40021C14) |= 0x8;  // Turn LED ON PH3 *
			
			*(unsigned long*)(0x40021C14) &= ~0x4;  // TURN LED OFF PH2
			
			*(unsigned long*)(0x40021814) |= 0x100;  // Turn LED ON PG8 *
			
			*(unsigned long*)(0x40021814) &= ~0x80;  // TURN LED OFF PG7
			
			*(unsigned long*)(0x40021814) |= 0x40;  // Turn LED ON PG6 *
			
		
			
			
			for(j = 0; j < 2000000; ++j){}
				
				*(unsigned long*)(0x40022014) |= 0x400;  // Turn LED ON PI10
				
				*(unsigned long*)(0x40021C14) &= ~0x80;  // TURN LED OFF PH7
				
				*(unsigned long*)(0x40021C14) |= 0x40;  // Turn LED ON PH6
				
				*(unsigned long*)(0x40021C14) &= ~0x8;  // TURN LED OFF PH3
				
				*(unsigned long*)(0x40021C14) |= 0x4;  // Turn LED ON PH2
				
				*(unsigned long*)(0x40021814) &= ~0x100;  // Turn LED OFF PG8
				
				*(unsigned long*)(0x40021814) |= 0x80;  // Turn LED ON PG7
				
				*(unsigned long*)(0x40021814) &= ~0x40;  // TURN LED OFF PG6
				
				
			for(j = 0; j < 2000000; ++j) {}
		}
	
}

// 010000000000000000
