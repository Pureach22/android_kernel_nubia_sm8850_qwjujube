__int64 __fastcall hdd_phymode_to_dot11_mode(
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

  if ( a1 <= 255 )
  {
    if ( a1 > 7 )
    {
      if ( a1 == 8 )
      {
        *a2 = 3;
        return 0;
      }
      if ( a1 == 16 )
      {
        *a2 = 4;
        return 0;
      }
    }
    else
    {
      if ( a1 == 2 )
      {
        *a2 = 10;
        return 0;
      }
      if ( a1 == 4 )
      {
        *a2 = 2;
        return 0;
      }
    }
    goto LABEL_20;
  }
  if ( a1 <= 2047 )
  {
    if ( a1 == 256 )
    {
      *a2 = 9;
      return 0;
    }
    if ( a1 != 1024 )
      goto LABEL_20;
LABEL_15:
    *a2 = 0;
    return 0;
  }
  if ( a1 == 2048 )
  {
    *a2 = 12;
    return 0;
  }
  if ( a1 == 0x2000 )
    goto LABEL_15;
LABEL_20:
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
    "hdd_phymode_to_dot11_mode",
    v10,
    v11);
  return 4294967274LL;
}
