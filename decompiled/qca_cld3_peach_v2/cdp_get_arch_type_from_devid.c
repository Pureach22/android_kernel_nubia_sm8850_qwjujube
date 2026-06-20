__int64 __fastcall cdp_get_arch_type_from_devid(unsigned __int16 a1)
{
  int v1; // w8
  __int64 result; // x0
  unsigned int v3; // w8

  v1 = a1;
  result = 0;
  if ( v1 <= 43967 )
  {
    if ( (unsigned int)(v1 - 4352) > 0x12 )
      goto LABEL_15;
    if ( ((1 << v1) & 0x74680) != 0 )
      return 1;
    if ( ((1 << v1) & 0x3B) == 0 )
    {
LABEL_15:
      if ( (unsigned int)(v1 - 43536) >= 2 && v1 != 264 )
        return 0xFFFFFFFFLL;
    }
  }
  else
  {
    if ( v1 > 65525 )
    {
      v3 = v1 - 65526;
      if ( v3 <= 9 )
      {
        if ( ((1 << v3) & 0x3F4) != 0 )
          return result;
        return 1;
      }
      return 0xFFFFFFFFLL;
    }
    if ( (unsigned int)(v1 - 43968) >= 4 )
    {
      if ( v1 == 45054 )
        return 1;
      if ( v1 == 49136 )
        return 2;
      return 0xFFFFFFFFLL;
    }
  }
  return result;
}
