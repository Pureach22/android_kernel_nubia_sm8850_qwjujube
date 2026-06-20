const char *__fastcall size_to_string(__int64 a1)
{
  if ( a1 >= 0x200000 )
  {
    if ( a1 <= 20971519 )
    {
      if ( a1 == 0x200000 )
        return (const char *)&unk_D4E7;
      if ( a1 == 12582912 )
        return "12M";
    }
    else
    {
      switch ( a1 )
      {
        case 0x1400000LL:
          return (const char *)&unk_D811;
        case 0x1800000LL:
          return (const char *)&unk_CCCB;
        case 0x2000000LL:
          return "32M";
      }
    }
  }
  else if ( a1 < 0x4000 )
  {
    if ( a1 == 4096 )
      return "4K";
    if ( a1 == 0x2000 )
      return "8K";
  }
  else
  {
    switch ( a1 )
    {
      case 0x4000LL:
        return "16K";
      case 0x10000LL:
        return (const char *)&unk_D68A;
      case 0x100000LL:
        return (const char *)&unk_D80E;
    }
  }
  printk(&unk_D4EA, "_size_to_string");
  return "unknown size";
}
