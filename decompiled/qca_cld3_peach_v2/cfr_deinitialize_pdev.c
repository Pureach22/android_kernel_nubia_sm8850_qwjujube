__int64 __fastcall cfr_deinitialize_pdev(
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
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19

  if ( !a1 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: PDEV is NULL!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_is_feature_disabled");
    goto LABEL_6;
  }
  if ( (*(_BYTE *)(a1 + 16) & 1) == 0 )
  {
LABEL_6:
    qdf_trace_msg(0x6Au, 2u, "%s: cfr is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "cfr_deinitialize_pdev");
    return 39;
  }
  result = tgt_cfr_deinit_pdev(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( (_DWORD)result )
  {
    v18 = result;
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: cfr_deinitialize_pdev status=%d\n",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cfr_deinitialize_pdev",
      (unsigned int)result);
    return v18;
  }
  return result;
}
