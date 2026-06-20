const char *__fastcall csr_phy_mode_str(int a1)
{
  if ( a1 > 127 )
  {
    if ( a1 > 2047 )
    {
      if ( a1 >= 0x2000 )
      {
        if ( a1 == 0x2000 )
          return "11be";
        if ( a1 == 0x4000 )
          return "11be_only";
      }
      else
      {
        if ( a1 == 2048 )
          return "11ax";
        if ( a1 == 4096 )
          return "11ax_only";
      }
    }
    else if ( a1 > 511 )
    {
      if ( a1 == 512 )
        return "11ac_only";
      if ( a1 == 1024 )
        return "auto";
    }
    else
    {
      if ( a1 == 128 )
        return "11b_only";
      if ( a1 == 256 )
        return "11ac";
    }
    return "unknown";
  }
  if ( a1 > 7 )
  {
    if ( a1 > 31 )
    {
      if ( a1 == 32 )
        return "11g_only";
      if ( a1 == 64 )
        return "11n_only";
    }
    else
    {
      if ( a1 == 8 )
        return "11g";
      if ( a1 == 16 )
        return "11n";
    }
    return "unknown";
  }
  if ( a1 != 1 )
  {
    if ( a1 == 2 )
      return "11a";
    if ( a1 == 4 )
      return "11b";
    return "unknown";
  }
  return "abg";
}
