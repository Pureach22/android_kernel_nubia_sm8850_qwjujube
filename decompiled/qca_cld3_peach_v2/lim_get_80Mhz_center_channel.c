__int64 __fastcall lim_get_80Mhz_center_channel(unsigned __int8 a1)
{
  if ( (unsigned int)a1 - 36 < 0xD )
    return 42;
  if ( (unsigned int)a1 - 52 < 0xD )
    return 58;
  if ( (unsigned int)a1 - 100 < 0xD )
    return 106;
  if ( (unsigned int)a1 - 116 < 0xD )
    return 122;
  if ( (unsigned int)a1 - 132 < 0xD )
    return 138;
  if ( (unsigned int)a1 - 149 >= 0xD )
    return 0;
  return 4294967195LL;
}
