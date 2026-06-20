_QWORD *__fastcall target_if_mgmt_rx_srng_register_rx_ops(
        _QWORD *result,
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

  if ( !result )
    return (_QWORD *)qdf_trace_msg(
                       0x49u,
                       2u,
                       "%s: mgmt_rx_srng rx_ops is null",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       "target_if_mgmt_rx_srng_register_rx_ops",
                       v9,
                       v10);
  *result = target_if_register_mgmt_rx_srng_reap_event;
  result[1] = target_if_unregister_mgmt_rx_srng_reap_event;
  return result;
}
