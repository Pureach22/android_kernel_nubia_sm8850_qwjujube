__int64 __fastcall rmnet_register_real_device(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20
  int v4; // w0
  unsigned int v5; // w19
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x9
  unsigned int *v9; // x9
  unsigned int v10; // w12
  __int64 v11; // x9

  if ( !(unsigned int)rtnl_is_locked() && (rmnet_register_real_device___already_done & 1) == 0 )
  {
    rmnet_register_real_device___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../vendor/qcom/opensource/datarmnet/core/rmnet_config.c", 126);
    __break(0x800u);
  }
  if ( *(__int64 (__fastcall **)())(a1 + 264) == rmnet_rx_handler )
    return 0;
  v2 = _kmalloc_cache_noprof(preempt_schedule_notrace, 2336, 2816);
  v3 = v2;
  if ( v2 )
  {
    *(_QWORD *)v2 = a1;
    *(_DWORD *)(v2 + 2784) = 16711687;
    *(_WORD *)(v2 + 2788) = 200;
    rmnet_map_tx_aggregate_init(v2);
    rmnet_map_cmd_init(v3);
    if ( (ipa_register_notifier(rmnet_ipa_notify_cb) & 0x80000000) != 0 )
    {
      v4 = -12;
      goto LABEL_11;
    }
    memset((void *)(v3 + 16), 0, 0x7F8u);
    v4 = rmnet_descriptor_init(v3);
    if ( v4 )
    {
LABEL_11:
      v5 = v4;
      rmnet_descriptor_deinit(v3);
      kfree(v3);
      return v5;
    }
    if ( (unsigned int)netdev_rx_handler_register(a1, rmnet_rx_handler, v3) )
    {
      v4 = -16;
      goto LABEL_11;
    }
    if ( a1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      ++*(_DWORD *)(StatusReg + 16);
      v8 = *(_QWORD *)(a1 + 1320);
      v9 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v8);
      do
        v10 = __ldxr(v9);
      while ( __stxr(v10 + 1, v9) );
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace();
    }
    return 0;
  }
  return 4294967284LL;
}
