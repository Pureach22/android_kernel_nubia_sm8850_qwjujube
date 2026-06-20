__int64 __fastcall lim_get_short_slot_from_phy_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11,
        _BYTE *a12)
{
  unsigned __int64 v13; // x9
  int v14; // w8
  int v15; // w20
  unsigned int v16; // w8
  __int64 result; // x0

  if ( a11 == 2 )
  {
    v13 = *(unsigned int *)(a10 + 7036);
    v14 = *(_DWORD *)(a10 + 72);
    if ( v13 >= 6 )
      LOBYTE(v15) = 0;
    else
      LOBYTE(v15) = 0x10001000100uLL >> (8 * (unsigned __int8)v13);
    if ( v14 == 11 )
    {
      v16 = *(unsigned __int16 *)(a10 + 234);
      goto LABEL_10;
    }
    if ( v14 == 2 )
    {
      v16 = *(unsigned __int16 *)(a10 + 176);
LABEL_10:
      v15 = (v16 >> 10) & 1;
    }
  }
  else
  {
    LOBYTE(v15) = 0;
  }
  result = qdf_trace_msg(
             0x35u,
             8u,
             "%s: phyMode: %u shortslotsupported: %u",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             "lim_get_short_slot_from_phy_mode",
             a11,
             (unsigned __int8)v15);
  *a12 = v15;
  return result;
}
