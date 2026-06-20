__int64 __fastcall twt_psoc_enable(
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
  unsigned int v11; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v29; // x4

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x96u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_get_tx_ops");
    v29 = "tx_ops";
LABEL_10:
    qdf_trace_msg(0x96u, 2u, "%s: %s is null", a2, a3, a4, a5, a6, a7, a8, a9, "twt_psoc_enable", v29);
    return 29;
  }
  v10 = *(__int64 (**)(void))(v9 + 2072);
  if ( !v10 )
  {
    v29 = "register_events";
    goto LABEL_10;
  }
  if ( *((_DWORD *)v10 - 1) != -770124015 )
    __break(0x8228u);
  v11 = v10();
  if ( v11 )
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: twt_register_events failed (status=%d)",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "twt_psoc_enable",
      v11);
  pmo_register_suspend_handler(0x2Cu, (__int64)wlan_twt_suspend_handler, 0, v12, v13, v14, v15, v16, v17, v18, v19);
  pmo_register_resume_handler(0x2Cu, (__int64)wlan_twt_resume_handler, 0, v20, v21, v22, v23, v24, v25, v26, v27);
  return v11;
}
