__int64 __fastcall hdd_vendor_mode_to_band(
        int a1,
        _BYTE *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30

  if ( a1 > 10 )
  {
    if ( (unsigned int)a1 <= 0x1C )
    {
      if ( ((1 << a1) & 0x3F8000) != 0 )
      {
LABEL_7:
        *a2 = 3;
        return 0;
      }
      if ( ((1 << a1) & 0x1FC00000) != 0 )
      {
LABEL_5:
        if ( (a3 & 1) != 0 )
        {
          *a2 = 7;
          return 0;
        }
        goto LABEL_7;
      }
      if ( ((1 << a1) & 0x7800) != 0 )
        goto LABEL_17;
    }
    goto LABEL_19;
  }
  if ( a1 > 3 )
  {
    if ( (unsigned int)(a1 - 7) >= 4 && (unsigned int)(a1 - 4) >= 2 )
      goto LABEL_5;
    goto LABEL_15;
  }
  if ( (unsigned int)(a1 - 2) < 2 )
  {
LABEL_17:
    *a2 = 2;
    return 0;
  }
  if ( !a1 )
    goto LABEL_5;
  if ( a1 == 1 )
  {
LABEL_15:
    *a2 = 1;
    return 0;
  }
LABEL_19:
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Not supported mode %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_vendor_mode_to_band",
    v11,
    v12);
  return 4294967274LL;
}
