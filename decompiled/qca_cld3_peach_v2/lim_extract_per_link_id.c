__int64 __fastcall lim_extract_per_link_id(
        __int64 a1,
        __int64 a2,
        __int64 a3,
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
  _BYTE *v13; // x8
  __int64 v14; // x4
  _BYTE *v15; // x8

  v13 = *(_BYTE **)(a1 + 16);
  v14 = (unsigned __int8)v13[168];
  if ( (v13[60] & 2) == 0 && (*(_WORD *)(a3 + 5344) & 0x10) != 0 )
    v15 = (_BYTE *)(a3 + 5353);
  else
    v15 = v13 + 93;
  *(_BYTE *)(a2 + 400) = *v15;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: vdev: %d, link id: %d",
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           "lim_extract_per_link_id",
           v14,
           v11,
           v12);
}
