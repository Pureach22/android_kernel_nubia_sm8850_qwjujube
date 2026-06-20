__int64 __fastcall util_get_bvmlie_msd_cap(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  unsigned int v14; // w8
  unsigned int v15; // w8
  int v17; // w9
  int v18; // w9
  unsigned __int8 *v19; // x0
  unsigned int v20; // t1

  v14 = 29;
  if ( !a1 || !a2 || !a3 || !a4 )
    return v14;
  *a4 = 0;
  *a3 = 0;
  if ( a2 < 5 )
    return 4;
  if ( *a1 != 255 )
    return 4;
  if ( a1[2] != 107 )
    return 4;
  v15 = *(unsigned __int16 *)(a1 + 3);
  if ( (v15 & 7) != 0 )
    return 4;
  if ( ((v15 >> 4) & 1) != 0 )
    v17 = 8;
  else
    v17 = 7;
  if ( ((v15 >> 4) & 4) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MSD caps not found in assoc rsp",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "util_get_bvmlie_msd_cap",
      v12,
      v13);
    return 0;
  }
  if ( a2 == 5 )
    return 27;
  v18 = v17 + ((v15 >> 5) & 1);
  v20 = a1[5];
  v19 = a1 + 5;
  v14 = 27;
  if ( v20 < (unsigned __int8)(v18 + 2) || (unsigned __int64)(unsigned __int8)v18 + 7 > a2 )
    return v14;
  *a3 = 1;
  *a4 = *(_WORD *)&v19[(unsigned __int8)v18];
  return 0;
}
