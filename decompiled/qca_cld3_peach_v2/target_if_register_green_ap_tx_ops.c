__int64 __fastcall target_if_register_green_ap_tx_ops(
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
    a1[230] = target_if_green_ap_enable_egap;
    a1[231] = target_if_green_ap_set_ps_on_off;
    a1[232] = 0;
    a1[233] = 0;
    a1[234] = 0;
    a1[235] = 0;
    a1[236] = target_if_green_ap_ll_ps_cmd;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid tx_ops",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_register_green_ap_tx_ops",
      v9,
      v10);
    return 16;
  }
}
