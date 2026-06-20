__int64 __fastcall apps_rmnet_ctl_tx_complete_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x10
  __int64 v13; // x0
  unsigned int v19; // w11

  if ( a2 == 1 )
  {
    _X9 = (unsigned int *)rmnet_ctl_ipa3_ctx;
    __asm { PRFM            #0x11, [X9] }
    do
      v19 = __ldxr(_X9);
    while ( __stxr(v19 - 1, _X9) );
    if ( !*(_DWORD *)rmnet_ctl_ipa3_ctx )
      ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ctl_ipa3_ctx + 664));
  }
  else
  {
    printk(&unk_3D6B12, "apps_rmnet_ctl_tx_complete_notify");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d unsupported evt on Tx callback, Drop the packet\n",
          "apps_rmnet_ctl_tx_complete_notify",
          665);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d unsupported evt on Tx callback, Drop the packet\n",
          "apps_rmnet_ctl_tx_complete_notify",
          665);
    }
    v9 = raw_spin_lock_irqsave(rmnet_ctl_ipa3_ctx + 584);
    v10 = rmnet_ctl_ipa3_ctx;
    v11 = v9;
    v12 = *(_QWORD *)(rmnet_ctl_ipa3_ctx + 40);
    v13 = rmnet_ctl_ipa3_ctx + 584;
    ++*(_DWORD *)(rmnet_ctl_ipa3_ctx + 32);
    *(_QWORD *)(v10 + 40) = v12 + *(unsigned int *)(a3 + 112);
    raw_spin_unlock_irqrestore(v13, v11);
  }
  return sk_skb_reason_drop(0, a3, 2);
}
