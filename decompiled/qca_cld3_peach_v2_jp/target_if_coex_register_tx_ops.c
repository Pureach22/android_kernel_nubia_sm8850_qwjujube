__int64 __fastcall target_if_coex_register_tx_ops(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    a1[240] = target_if_coex_config_send;
    a1[241] = target_if_coex_multi_config_send;
    a1[242] = target_if_coex_get_multi_config_support;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x70u,
      2u,
      "%s: target if tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_coex_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
