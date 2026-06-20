__int64 __fastcall tgt_scan_register_ev_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2128)) != 0 )
  {
    v10 = *(__int64 (**)(void))(v9 + 96);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != -1796695762 )
        __break(0x8228u);
      return v10();
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x15u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_scan_txops");
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: NULL scan_ops",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tgt_scan_register_ev_handler");
    return 16;
  }
}
