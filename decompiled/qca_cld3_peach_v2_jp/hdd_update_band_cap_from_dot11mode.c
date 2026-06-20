__int64 __fastcall hdd_update_band_cap_from_dot11mode(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w19
  unsigned int v11; // w8
  unsigned int v12; // w9
  bool v13; // zf
  unsigned int v14; // w8

  v10 = a2;
  v11 = **(_DWORD **)(a1 + 104);
  if ( v11 <= 7 )
  {
    if ( ((1 << v11) & 0xAC) != 0 )
    {
      v10 = a2 & 0xFFFFFFFD;
    }
    else if ( !v11 )
    {
      return v10;
    }
  }
  v12 = v10 & 0xFFFFFFFE;
  v13 = v11 == 10;
  v14 = v11 - 11;
  if ( !v13 )
    v12 = v10;
  if ( v14 >= 2 )
    v10 = v12 & 0xFFFFFFFB;
  else
    v10 = v12;
  qdf_trace_msg(
    0x38u,
    8u,
    "%s: Update band capability %x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_update_band_cap_from_dot11mode",
    v10);
  return v10;
}
