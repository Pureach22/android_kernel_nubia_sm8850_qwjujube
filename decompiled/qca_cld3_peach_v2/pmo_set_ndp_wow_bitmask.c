__int64 __fastcall pmo_set_ndp_wow_bitmask(
        __int64 result,
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
  __int64 v10; // x29
  __int64 v11; // x30
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( result && a2 > 3 )
  {
    *(_DWORD *)(result + 4LL * (0x1D / (8 * a2))) |= 1 << (0x1D % (8 * a2));
    *(_DWORD *)(result + 4LL * (9 / (8 * a2))) |= 1 << (9 % (8 * a2));
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: wow bitmask length shorter than %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pmo_set_wow_event_bitmap",
      4,
      v10,
      v11);
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: wow bitmask length shorter than %d",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             "pmo_set_wow_event_bitmap",
             4);
  }
  return result;
}
