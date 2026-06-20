__int64 rmnet_ll_wakeup_ipa()
{
  int v0; // w0
  __int64 v1; // x24
  __int64 v2; // x0
  __int64 v3; // x22
  __int64 v4; // x25
  int v5; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x10
  unsigned int v21; // w9
  __int64 result; // x0
  int v23; // w19
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x19

  v0 = ipa_pm_activate_sync(*(_DWORD *)(rmnet_ll_ipa3_ctx + 672));
  if ( v0 )
  {
    v23 = v0;
    printk(&unk_3E1D87, "rmnet_ll_wakeup_ipa");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(
          v25,
          "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
          "rmnet_ll_wakeup_ipa",
          779,
          "rmnet_ll_wakeup_ipa",
          v23);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(
          v26,
          "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
          "rmnet_ll_wakeup_ipa",
          779,
          "rmnet_ll_wakeup_ipa",
          v23);
    }
    return queue_delayed_work_on(32, *(_QWORD *)(rmnet_ll_ipa3_ctx + 736), &rmnet_ll_wakeup_work, 1);
  }
  v1 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        if ( !*(_DWORD *)(rmnet_ll_ipa3_ctx + 664) )
        {
          result = raw_spin_unlock_irqrestore(rmnet_ll_ipa3_ctx + 584, v1);
          goto LABEL_20;
        }
        v2 = skb_dequeue(rmnet_ll_ipa3_ctx + 648);
      }
      while ( !v2 );
      v3 = *(int *)(v2 + 112);
      v4 = v2;
      raw_spin_unlock_irqrestore(rmnet_ll_ipa3_ctx + 584, v1);
      v5 = ipa_tx_dp(0x78u, v4, nullptr);
      if ( v5 )
        break;
      _X8 = (unsigned int *)rmnet_ll_ipa3_ctx;
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 + 1, _X8) );
      v13 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
      v14 = rmnet_ll_ipa3_ctx;
      v1 = v13;
      v15 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 16) + v3;
      ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 4);
      *(_QWORD *)(v14 + 16) = v15;
    }
    if ( v5 != -32 )
      break;
    if ( (unsigned int)__ratelimit(&rmnet_ll_wakeup_ipa__rs, "rmnet_ll_wakeup_ipa") )
    {
      printk(&unk_3B0D33, "rmnet_ll_wakeup_ipa");
      v6 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_13;
    }
    else
    {
      v6 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_13;
    }
    v7 = *(_QWORD *)(v6 + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Low lat data fatal: pipe is not valid\n", "rmnet_ll_wakeup_ipa", 802);
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d Low lat data fatal: pipe is not valid\n", "rmnet_ll_wakeup_ipa", 802);
LABEL_13:
    v9 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
    v10 = rmnet_ll_ipa3_ctx;
    v1 = v9;
    v11 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 40);
    ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 32);
    *(_QWORD *)(v10 + 40) = v11 + *(unsigned int *)(v4 + 112);
    sk_skb_reason_drop(0, v4, 2);
  }
  v27 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
  skb_queue_head(rmnet_ll_ipa3_ctx + 648, v4);
  raw_spin_unlock_irqrestore(rmnet_ll_ipa3_ctx + 584, v27);
  result = queue_delayed_work_on(32, *(_QWORD *)(rmnet_ll_ipa3_ctx + 736), &rmnet_ll_wakeup_work, 1);
LABEL_20:
  if ( !*(_DWORD *)rmnet_ll_ipa3_ctx )
    return ((__int64 (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ll_ipa3_ctx + 672));
  return result;
}
