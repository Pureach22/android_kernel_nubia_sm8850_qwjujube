__int64 __fastcall hdd_vendor_mode_to_phymode(
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

  if ( a1 <= 4 )
  {
    if ( (unsigned int)a1 < 3 )
    {
      *a2 = 1024;
      return 0;
    }
    if ( a1 == 3 )
    {
      *a2 = 2;
      return 0;
    }
    if ( a1 == 4 )
    {
      *a2 = 4;
      return 0;
    }
  }
  else
  {
    if ( (unsigned int)a1 <= 0x1C )
    {
      if ( ((1 << a1) & 0x7FC0) != 0 )
      {
        *a2 = 16;
        return 0;
      }
      if ( ((1 << a1) & 0x3F8000) != 0 )
      {
        *a2 = 256;
        return 0;
      }
      if ( ((1 << a1) & 0x1FC00000) != 0 )
      {
        *a2 = 2048;
        return 0;
      }
    }
    if ( a1 == 5 )
    {
      *a2 = 8;
      return 0;
    }
  }
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
    "hdd_vendor_mode_to_phymode",
    v10,
    v11);
  return 4294967274LL;
}
