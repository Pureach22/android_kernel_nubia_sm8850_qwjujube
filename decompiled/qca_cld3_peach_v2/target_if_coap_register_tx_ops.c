__int64 __fastcall target_if_coap_register_tx_ops(
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
    a1[278] = target_if_coap_register_event_handler;
    a1[279] = target_if_coap_unregister_event_handler;
    a1[280] = target_if_coap_offload_reply_enable;
    a1[281] = target_if_coap_offload_reply_disable;
    a1[282] = target_if_coap_offload_periodic_tx_enable;
    a1[283] = target_if_coap_offload_periodic_tx_disable;
    a1[284] = target_if_coap_offload_cache_get;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x9Cu,
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
      "target_if_coap_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
