__int64 __fastcall tgt_cfr_subscribe_ppdu_desc(
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
  __int64 v10; // x8
  __int64 v11; // x8

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: Invalid psoc\n", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_cfr_subscribe_ppdu_desc");
    return 4;
  }
  v10 = *(_QWORD *)(v9 + 2128);
  if ( v10 )
  {
    v11 = *(_QWORD *)(v10 + 480);
    if ( !v11 )
      return 0;
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_psoc_get_cfr_txops");
    v11 = 0x16341C00162D60LL;
  }
  if ( *(_DWORD *)(v11 - 4) != 1845289881 )
    __break(0x8228u);
  return ((__int64 (*)(void))v11)();
}
