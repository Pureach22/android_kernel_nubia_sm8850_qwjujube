__int64 __fastcall ucfg_green_ap_enable_egap(
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
  __int64 v19; // x20
  __int64 (__fastcall **green_ap_tx_ops)(__int64, __int64); // x0
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  const char *v23; // x2

  if ( !a1 )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_green_ap_enable_egap");
    return 4;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v23 = "%s: green ap context obtained is NULL";
LABEL_12:
    qdf_trace_msg(0x5Du, 2u, v23, v11, v12, v13, v14, v15, v16, v17, v18, "ucfg_green_ap_enable_egap");
    return 16;
  }
  v19 = comp_private_obj;
  green_ap_tx_ops = (__int64 (__fastcall **)(__int64, __int64))wlan_psoc_get_green_ap_tx_ops(
                                                                 comp_private_obj,
                                                                 v11,
                                                                 v12,
                                                                 v13,
                                                                 v14,
                                                                 v15,
                                                                 v16,
                                                                 v17,
                                                                 v18);
  if ( !green_ap_tx_ops )
  {
    v23 = "%s: green ap tx ops obtained are NULL";
    goto LABEL_12;
  }
  v21 = *green_ap_tx_ops;
  if ( !*green_ap_tx_ops )
  {
    v23 = "%s: tx op for sending enable/disable green ap is NULL";
    goto LABEL_12;
  }
  if ( *((_DWORD *)v21 - 1) != 36786723 )
    __break(0x8228u);
  return v21(a1, v19 + 136);
}
