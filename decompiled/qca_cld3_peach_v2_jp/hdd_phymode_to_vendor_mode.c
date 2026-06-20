__int64 __fastcall hdd_phymode_to_vendor_mode(
        int a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 > 255 )
  {
    if ( a1 <= 2047 )
    {
      if ( a1 == 256 || a1 == 512 )
      {
        *a2 = 21;
        return 0;
      }
      if ( a1 != 1024 )
        goto LABEL_29;
    }
    else
    {
      if ( a1 < 0x2000 )
      {
        if ( a1 == 2048 || a1 == 4096 )
        {
          *a2 = 28;
          return 0;
        }
        goto LABEL_29;
      }
      if ( a1 != 0x4000 && a1 != 0x2000 )
        goto LABEL_29;
    }
    *a2 = 0;
    return 0;
  }
  if ( a1 <= 15 )
  {
    switch ( a1 )
    {
      case 2:
        *a2 = 3;
        return 0;
      case 4:
        goto LABEL_22;
      case 8:
        goto LABEL_15;
    }
  }
  else
  {
    if ( a1 <= 63 )
    {
      if ( a1 != 16 )
      {
        if ( a1 != 32 )
          goto LABEL_29;
LABEL_15:
        *a2 = 5;
        return 0;
      }
LABEL_26:
      *a2 = 6;
      return 0;
    }
    if ( a1 == 64 )
      goto LABEL_26;
    if ( a1 == 128 )
    {
LABEL_22:
      *a2 = 4;
      return 0;
    }
  }
LABEL_29:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Not supported mode %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_phymode_to_vendor_mode",
    v10,
    v11);
  return 4294967274LL;
}
