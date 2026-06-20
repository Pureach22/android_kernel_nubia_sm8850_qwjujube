__int64 __fastcall tgt_twt_send_unavailability_mode(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 tx_ops; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _DWORD *v23; // x8

  tx_ops = wlan_twt_get_tx_ops(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( tx_ops && (v23 = *(_DWORD **)(tx_ops + 64)) != nullptr )
  {
    if ( *(v23 - 1) != 1540374283 )
      __break(0x8228u);
    return ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v23)(a1, a2, a3 & 1);
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: unavailability_mode ops is null",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "tgt_twt_send_unavailability_mode");
    return 29;
  }
}
