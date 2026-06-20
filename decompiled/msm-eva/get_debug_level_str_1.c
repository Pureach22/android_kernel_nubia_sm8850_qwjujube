const char *__fastcall get_debug_level_str_1(int a1)
{
  if ( a1 <= 255 )
  {
    if ( a1 > 15 )
    {
      if ( a1 > 63 )
      {
        if ( a1 == 64 )
          return (const char *)&unk_84256;
        if ( a1 == 128 )
          return "synx";
      }
      else
      {
        if ( a1 == 16 )
          return "prof";
        if ( a1 == 32 )
          return (const char *)&unk_96215;
      }
    }
    else if ( a1 > 3 )
    {
      if ( a1 == 4 )
        return "info";
      if ( a1 == 8 )
        return "cmd";
    }
    else
    {
      if ( a1 == 1 )
        return (const char *)&unk_8E7CE;
      if ( a1 == 2 )
        return "warn";
    }
  }
  else if ( a1 <= 4095 )
  {
    if ( a1 > 1023 )
    {
      if ( a1 == 1024 )
        return (const char *)&unk_8DA84;
      if ( a1 == 2048 )
        return "dsp";
    }
    else
    {
      if ( a1 == 256 )
        return "core";
      if ( a1 == 512 )
        return (const char *)&unk_8425A;
    }
  }
  else if ( a1 < 0x4000 )
  {
    if ( a1 == 4096 )
      return "fw";
    if ( a1 == 0x2000 )
      return "sess";
  }
  else
  {
    switch ( a1 )
    {
      case 16384:
        return "hfi";
      case 32768:
        return (const char *)&unk_85102;
      case 61416:
        return (const char *)&unk_94624;
    }
  }
  return (const char *)&unk_8E085;
}
