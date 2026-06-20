__int64 __fastcall tgt_twt_ac_pdev_param_send(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 tx_ops; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8

  tx_ops = wlan_twt_get_tx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( tx_ops && (v21 = *(_DWORD **)(tx_ops + 56)) != nullptr )
  {
    if ( *(v21 - 1) != -1737196393 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v21)(a1, a2, 0);
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: set_ac_param is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_twt_ac_pdev_param_send");
    return 29;
  }
}
