__int64 __fastcall sap_search_mac_list(
        __int64 a1,
        unsigned __int16 a2,
        const void *a3,
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
  int v15; // w22
  int v16; // w23
  int v17; // w24
  int v18; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  if ( !a1 || a2 > 0x20u )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: either buffer is NULL or size = %d is more",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sap_search_mac_list",
      a2);
    return 0;
  }
  if ( !a2 )
  {
LABEL_10:
    qdf_trace_msg(0x39u, 8u, "%s: search not succ", a5, a6, a7, a8, a9, a10, a11, a12, "sap_search_mac_list");
    return 0;
  }
  v15 = 0;
  v16 = a2 - 1;
  while ( 1 )
  {
    v17 = (v16 + v15) / 2;
    v18 = qdf_mem_cmp((const void *)(a1 + 6LL * v17), a3, 6u);
    if ( !v18 )
      break;
    if ( v18 >= 0 )
      v16 = v17 - 1;
    else
      v15 = v17 + 1;
    if ( v15 > v16 )
      goto LABEL_10;
  }
  qdf_trace_msg(0x39u, 8u, "%s: search SUCC", a5, a6, a7, a8, a9, a10, a11, a12, "sap_search_mac_list");
  if ( a4 )
  {
    *a4 = v17;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: index %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "sap_search_mac_list",
      (unsigned __int16)v17);
  }
  return 1;
}
