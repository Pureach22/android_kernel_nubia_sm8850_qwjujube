__int64 __fastcall target_if_interop_issues_ap_unregister_tx_ops(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _QWORD *a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a10 )
  {
    *a10 = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: tx ops is NULL!",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "target_if_interop_issues_ap_unregister_tx_ops",
      v10,
      v11);
    return 4;
  }
}
