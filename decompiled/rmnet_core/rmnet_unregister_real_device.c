__int64 __fastcall rmnet_unregister_real_device(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x9
  unsigned int *v6; // x9
  unsigned int v7; // w12
  __int64 v8; // x9

  if ( !*(_BYTE *)(a2 + 12) )
  {
    v3 = result;
    netdev_rx_handler_unregister(result, a2);
    rmnet_map_cmd_exit(a2);
    rmnet_map_tx_aggregate_exit(a2);
    rmnet_descriptor_deinit(a2);
    result = kfree(a2);
    if ( v3 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v5 = *(_QWORD *)(v3 + 1320);
      v6 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v5);
      do
        v7 = __ldxr(v6);
      while ( __stxr(v7 - 1, v6) );
      v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v8;
      if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
  }
  return result;
}
