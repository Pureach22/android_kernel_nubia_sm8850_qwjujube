__int64 __fastcall target_if_twt_register_tx_ops(
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
  unsigned int v9; // w19
  const char *v10; // x2

  if ( !a1 )
  {
    v9 = 16;
    v10 = "%s: txops is NULL";
    goto LABEL_5;
  }
  a1[263] = target_if_twt_enable_req;
  a1[264] = target_if_twt_disable_req;
  a1[272] = target_if_twt_register_events;
  a1[273] = target_if_twt_deregister_events;
  v9 = target_if_twt_register_ext_tx_ops(a1 + 263);
  if ( v9 )
  {
    v10 = "%s: Failed to register twt ext tx ops";
LABEL_5:
    qdf_trace_msg(0x49u, 2u, v10, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_twt_register_tx_ops");
  }
  return v9;
}
