__int64 __fastcall wifi_pos_send_pasn_peer_deauth(
        __int64 a1,
        __int64 a2,
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
  __int64 (__fastcall *v21)(__int64, __int64); // x8
  const char *v23; // x4

  tx_ops = wifi_pos_get_tx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !tx_ops )
  {
    v23 = "send_pasn deauth cb";
LABEL_8:
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: %s is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wifi_pos_send_pasn_peer_deauth",
      v23);
    return 16;
  }
  v21 = *(__int64 (__fastcall **)(__int64, __int64))(tx_ops + 64);
  if ( !v21 )
  {
    v23 = "Tx_ops";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v21 - 1) != 402272470 )
    __break(0x8228u);
  return v21(a1, a2);
}
