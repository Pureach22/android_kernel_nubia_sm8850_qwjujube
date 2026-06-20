__int64 __fastcall wlan_get_elem_fragseq_requirements(
        unsigned __int8 a1,
        unsigned __int64 a2,
        _BYTE *a3,
        _QWORD *a4,
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
  bool v14; // zf
  __int64 result; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x8

  if ( !a3 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "Pointer to indication of whether fragmentation is required or not is NULL",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      v12,
      v13);
    return 29;
  }
  if ( a1 != 0xFF )
  {
    if ( a2 > 0xFF )
      goto LABEL_4;
LABEL_17:
    *a3 = 0;
    return 0;
  }
  if ( a2 <= 0xFE )
    goto LABEL_17;
LABEL_4:
  *a3 = 1;
  if ( !a4 )
    return 0;
  v14 = a1 == 255;
  result = 0;
  if ( v14 )
    v16 = a2 + 1;
  else
    v16 = a2;
  v17 = (v16 * (unsigned __int128)0x8080808080808081LL) >> 64;
  v18 = a2 - 254;
  if ( !v14 )
    v18 = a2;
  v19 = 0xFEFEFEFEFEFEFEFFLL * v18;
  v20 = 2;
  v21 = (((v17 >> 6) & 0x1FFFFFFFELL) + 0x1FFFFFFFELL) & 0x1FFFFFFFELL;
  if ( v14 )
    v20 = 3;
  if ( v19 >= 0x101010101010102LL )
    v21 += 2;
  *a4 = v20 + a2 + v21;
  return result;
}
