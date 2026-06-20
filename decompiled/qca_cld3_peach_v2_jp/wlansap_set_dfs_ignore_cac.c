__int64 __fastcall wlansap_set_dfs_ignore_cac(
        _QWORD *context,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8

  if ( context
    || (context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10)) != nullptr )
  {
    v19 = 0;
    *((_BYTE *)context + 14808) = a2 != 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid mac context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlansap_set_dfs_ignore_cac");
    return 5;
  }
  return v19;
}
