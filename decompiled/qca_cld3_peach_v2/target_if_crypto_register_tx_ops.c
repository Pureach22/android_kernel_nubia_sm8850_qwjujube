__int64 __fastcall target_if_crypto_register_tx_ops(
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
    a1[92] = target_if_crypto_set_key;
    a1[94] = target_if_crypto_set_ltf_keyseed;
    a1[95] = target_if_crypto_vdev_set_param;
    a1[96] = target_if_crypto_register_events;
    a1[97] = target_if_crypto_deregister_events;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: txops NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_crypto_register_tx_ops",
      v9,
      v10);
    return 16;
  }
}
