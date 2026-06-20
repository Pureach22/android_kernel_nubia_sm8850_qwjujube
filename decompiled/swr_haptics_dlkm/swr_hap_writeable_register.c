__int64 __fastcall swr_hap_writeable_register(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  if ( a2 <= 0x3000 )
    return 0;
  result = 0;
  if ( a2 - 12296 >= 6 && a2 != 12416 )
    return 1;
  return result;
}
