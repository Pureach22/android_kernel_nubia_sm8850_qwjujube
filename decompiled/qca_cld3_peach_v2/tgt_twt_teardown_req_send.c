__int64 __fastcall tgt_twt_teardown_req_send(
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
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s: psoc is null";
LABEL_11:
    qdf_trace_msg(0x96u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_twt_teardown_req_send");
    return 4;
  }
  if ( !a2 )
  {
    v23 = "%s: Invalid input";
    goto LABEL_11;
  }
  tx_ops = wlan_twt_get_tx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( tx_ops && (v21 = *(__int64 (__fastcall **)(__int64, __int64))(tx_ops + 24)) != nullptr )
  {
    if ( *((_DWORD *)v21 - 1) != -994559746 )
      __break(0x8228u);
    return v21(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: teardown_req tx_ops is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_twt_teardown_req_send");
    return 29;
  }
}
