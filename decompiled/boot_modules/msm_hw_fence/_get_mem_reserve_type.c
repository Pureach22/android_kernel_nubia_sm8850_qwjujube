const char *__fastcall get_mem_reserve_type(unsigned int a1)
{
  if ( a1 > 4 )
    return "Unknown";
  else
    return off_2C400[a1];
}
