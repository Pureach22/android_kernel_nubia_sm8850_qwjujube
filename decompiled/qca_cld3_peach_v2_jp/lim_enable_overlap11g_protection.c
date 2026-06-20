__int64 __fastcall lim_enable_overlap11g_protection(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  result = lim_update_overlap_sta_param(a1, (const void *)(a3 + 16), (char *)(a4 + 1224));
  if ( *(_BYTE *)(a4 + 1224) )
  {
    if ( !*(_BYTE *)(a4 + 1225) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: OLBC happens!!!",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "lim_enable_overlap11g_protection");
      return lim_enable11g_protection(a1, 1, 1, a2, a4, v16, v17, v18, v19, v20, v21, v22, v23);
    }
  }
  return result;
}
