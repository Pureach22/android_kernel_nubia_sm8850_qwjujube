__int64 __fastcall lim_is_valid_frame(
        unsigned __int16 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7

  if ( a2 )
  {
    v10 = *(_QWORD *)(a2 + 16);
    if ( (*(_WORD *)v10 & 0x800) == 0 )
      return 1;
    v11 = *(unsigned __int16 *)(v10 + 22) >> 4;
    if ( a1[3] != v11 || (unsigned int)qdf_mem_cmp(a1, (const void *)(v10 + 10), 6u) )
      return 1;
    if ( v10 == -10 )
    {
      v23 = 0;
      v21 = 0;
      v22 = 0;
      v24 = 0;
    }
    else
    {
      v21 = *(unsigned __int8 *)(v10 + 10);
      v22 = *(unsigned __int8 *)(v10 + 11);
      v23 = *(unsigned __int8 *)(v10 + 12);
      v24 = *(unsigned __int8 *)(v10 + 15);
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Duplicate frame from %02x:%02x:%02x:**:**:%02x Seq Number %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "lim_is_valid_frame",
      v21,
      v22,
      v23,
      v24,
      v11);
  }
  else
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid RX frame", a3, a4, a5, a6, a7, a8, a9, a10, "lim_is_valid_frame");
  }
  return 0;
}
