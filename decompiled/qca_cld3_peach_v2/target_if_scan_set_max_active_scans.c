__int64 __fastcall target_if_scan_set_max_active_scans(
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

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2136)) != 0 )
  {
    v10 = *(__int64 (**)(void))(v9 + 64);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 787953853 )
        __break(0x8228u);
      return v10();
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: scan_set_max_active_scans uninitialized",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_scan_set_max_active_scans");
      return 5;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_scan_get_rx_ops");
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: scan_rx_ops is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_scan_set_max_active_scans");
    return 16;
  }
}
