////////////////////////////////////////////////////////////////////////////////
///                                 bitmap.c                                 ///
////////////////////////////////////////////////////////////////////////////////
#define BITMAP_SIZE 5

static int bitmap[BITMAP_SIZE];

void init_bitmap(void)
{
	for(int i = 0; i < BITMAP_SIZE; i++) {
		bitmap[i] = 0x00000000;
	}
}

int alloc_bits(int numBits)
{
	/*
 	 * Allocate the first 'numBits' contiguous free bits (set to zero) 
 	 * available in the bitmap, starting from the first integer in the 
 	 * bitmap, and within a given integer, starting from the least 
 	 * significant bit. This is but a simple extension of the allocation
 	 * function defined in lecture. Note that the main difficulty here is
 	 * that the allocated block of bits may span more than one integer in
 	 * the bitmap. Return the bit index for the start of the allocation
 	 * block on success. Return -1 otherwise. Assume that 'numBits' is a
 	 * positive integer.
 	 */
		  int start = -1;
		  int flag1 = 0;
		  int start1;
	      for(int z = 0; z < BITMAP_SIZE; z++)
		  {
			  unsigned int mask1 = 0x1;
			  for(int k = 0; k <32; k++)
			  {
				  int first_zero = bitmap[z] & (mask1 << k);
				  if(first_zero == 0)
				  {
					  start1 = k;
					  if(numBits == 1)
					  {
						  start = start1;
						  flag1 = 1;
					  }
					  for(int w = 1; w <numBits;w++)
					  {
						  k++;
						  first_zero = bitmap[z] & (mask1 << k);
						  if(first_zero != 0)
						  {
							  break;
						  }
						  else if(w == numBits - 1)
						  {
							  start = start1;
							  flag1 = 1;
						  }
					  }
					  
				  }
				  if(flag1 == 1)
				  {
					  break;
				  }
			  }
			  if(flag1 == 1)
			  {
				  break;
			  }

		  }
		  unsigned int mask = 0x1;
		  int i = 0;
		  int x = -1;
		  int flag = 0;
		  if(start == -1 )
		  {
			  return -1;
		  }
		  for(int j = start; j < ((start+numBits) -(i*32)); j++)
		  {
			  if( j > 31)
			  {
				  i++;
				  j = 0;
			  }
			  int res = bitmap[i] & mask << j;

			  if(res == 0)
			  {
				  bitmap[i] = bitmap[i] | mask << j;
				  if(flag == 0)
				  {
				  	x =  (i * 32) + j;
					flag = 1;
				  }
			  }
		  }

		  return x;
	  
}
void free_bit(int index)
{
	/*
 	 * Free the bit that corresponds to 'index' by setting it equal to zero,
 	 * even if it is already equal to zero. Assume 'index' is valid.
 	 */
	  int i = index /(8*sizeof(int));
	  int j = index - (i *(8*sizeof(int)));

	  unsigned mask = 0x1;
	  bitmap[i] = bitmap[i] & ~(mask << (j)); 

	  return;

}
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
