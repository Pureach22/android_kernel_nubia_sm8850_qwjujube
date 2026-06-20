__int64 __fastcall tgt_tdls_send_mgmt_tx_completion(
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
  unsigned __int8 *v10; // x0

  if ( a1 )
  {
    v10 = *(unsigned __int8 **)(a1 + 8);
    if ( v10 )
      return tdls_send_mgmt_tx_completion(v10);
  }
  qdf_trace_msg(0, 2u, "%s: msg: 0x%pK", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_tdls_send_mgmt_tx_completion", a1);
  return 29;
}
