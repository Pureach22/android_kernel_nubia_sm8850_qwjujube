__int64 __fastcall tgt_twt_disable_req_send(
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
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19

  tx_ops = wlan_twt_get_tx_ops(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( tx_ops && (v21 = *(__int64 (__fastcall **)(__int64, __int64))(tx_ops + 8)) != nullptr )
  {
    if ( *((_DWORD *)v21 - 1) != -2125431364 )
      __break(0x8228u);
    result = v21(a1, a2);
    if ( (_DWORD)result )
    {
      v31 = result;
      qdf_trace_msg(
        0x96u,
        2u,
        "%s: tx_ops disable_req failed (status=%d)",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "tgt_twt_disable_req_send",
        (unsigned int)result);
      return v31;
    }
  }
  else
  {
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: twt disable_req tx_ops is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_twt_disable_req_send");
    return 29;
  }
  return result;
}
