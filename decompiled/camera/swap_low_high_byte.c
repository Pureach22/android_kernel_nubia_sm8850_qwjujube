unsigned int *__fastcall swap_low_high_byte(unsigned int *result)
{
  *result = bswap32(*(unsigned __int16 *)result) >> 16;
  return result;
}
