__int64 __fastcall wlan_ipa_uc_op_event_handler(
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
  __int64 v10; // x19
  __int64 v11; // x8

  if ( a2 )
  {
    if ( *(unsigned __int16 *)(a1 + 2) < 0x10u )
    {
      v11 = a2 + 88LL * *(unsigned __int16 *)(a1 + 2);
      if ( !*(_QWORD *)(v11 + 1600) )
      {
        *(_QWORD *)(v11 + 1600) = a1;
        return queue_work_on(32, system_wq, v11 + 1552);
      }
    }
    else
    {
      v10 = a1;
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: Invalid OP Code (%d)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_ipa_uc_op_event_handler");
      a1 = v10;
    }
  }
  return _qdf_mem_free(a1);
}
