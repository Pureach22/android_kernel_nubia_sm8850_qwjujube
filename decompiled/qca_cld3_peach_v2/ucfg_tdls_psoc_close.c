__int64 __fastcall ucfg_tdls_psoc_close(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19

  qdf_trace_msg(0, 8u, "%s: tdls psoc close", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_psoc_close");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xAu);
  if ( comp_private_obj )
  {
    if ( (*(_BYTE *)(comp_private_obj + 369) & 1) == 0 )
    {
      v19 = comp_private_obj;
      qdf_runtime_lock_deinit((__int64 *)(comp_private_obj + 576));
      _qdf_wake_lock_destroy(v19 + 376);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: Failed to get tdls psoc component",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "ucfg_tdls_psoc_close");
    return 16;
  }
}
