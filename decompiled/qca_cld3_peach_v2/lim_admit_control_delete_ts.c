__int64 __fastcall lim_admit_control_delete_ts(
        __int64 a1,
        unsigned __int16 a2,
        __int64 a3,
        _BYTE *a4,
        _BYTE *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  int v15; // w22
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v15 = a2;
  if ( a4 )
    *a4 = 0;
  v16 = a1 + 8920;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Trying to find tspec entry for assocId: %d pTsInfo->traffic.direction: %d pTsInfo->traffic.tsid: %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "lim_find_tspec",
    a2,
    (*(unsigned __int16 *)(a3 + 1) >> 5) & 3,
    (*(unsigned __int16 *)(a3 + 1) >> 1) & 0xF);
  v25 = 15;
  while ( !*(_BYTE *)v16
       || *(unsigned __int16 *)(v16 + 8) != v15
       || ((*(_WORD *)(v16 + 13) ^ *(_WORD *)(a3 + 1)) & 0x7E) != 0 )
  {
    --v25;
    v16 += 163;
    if ( !v25 )
      return 16;
  }
  if ( v16 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Tspec entry: %d found",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_admit_control_delete_ts",
      *(unsigned __int8 *)(v16 + 1));
    *a5 = *(_BYTE *)(v16 + 1);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: tspec entry: %d delete tspec: %pK",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "lim_tspec_delete");
    *(_BYTE *)v16 = 0;
    return 0;
  }
  return 16;
}
