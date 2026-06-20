const char *__fastcall get_debug_level_str_0(int a1)
{
  if ( a1 > 511 )
  {
    if ( a1 < 0x2000 )
    {
      if ( a1 > 2047 )
      {
        if ( a1 == 2048 )
          return "dsp";
        if ( a1 == 4096 )
          return "fw";
      }
      else
      {
        if ( a1 == 512 )
          return (const char *)&unk_8425A;
        if ( a1 == 1024 )
          return (const char *)&unk_8DA84;
      }
    }
    else if ( a1 < 0x8000 )
    {
      if ( a1 == 0x2000 )
        return "sess";
      if ( a1 == 0x4000 )
        return "hfi";
    }
    else
    {
      switch ( a1 )
      {
        case 0x8000:
          return (const char *)&unk_85102;
        case 0xEFE8:
          return (const char *)&unk_94624;
        case 0x20000:
          return "perf";
      }
    }
  }
  else if ( a1 <= 15 )
  {
    if ( a1 > 3 )
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
  else if ( a1 <= 63 )
  {
    if ( a1 == 16 )
      return "prof";
    if ( a1 == 32 )
      return (const char *)&unk_96215;
  }
  else
  {
    switch ( a1 )
    {
      case 64:
        return (const char *)&unk_84256;
      case 128:
        return "synx";
      case 256:
        return "core";
    }
  }
  return (const char *)&unk_8E085;
}
