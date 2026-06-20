__int64 __fastcall apps_rmnet_ll_tx_complete_notify(__int64 a1, int a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 v5; // x19
  _DWORD *v6; // x8
  int v7; // w5
  unsigned int v8; // w9
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x0
  __int64 v12; // x0
  _DWORD *v13; // x8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // x10
  __int64 v22; // x0
  unsigned int v28; // w10

  if ( a2 == 1 )
  {
    dev_kfree_skb_any_reason(a3, 2);
    v3 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
    _X8 = (unsigned int *)rmnet_ll_ipa3_ctx;
    v5 = v3;
    __asm { PRFM            #0x11, [X8] }
    do
      v28 = __ldxr(_X8);
    while ( __stxr(v28 - 1, _X8) );
    v6 = (_DWORD *)rmnet_ll_ipa3_ctx;
    if ( *(_DWORD *)rmnet_ll_ipa3_ctx )
    {
      if ( !*(_DWORD *)(rmnet_ll_ipa3_ctx + 640) )
        return raw_spin_unlock_irqrestore(v6 + 146, v5);
    }
    else
    {
      ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ll_ipa3_ctx + 672));
      v6 = (_DWORD *)rmnet_ll_ipa3_ctx;
      if ( !*(_DWORD *)(rmnet_ll_ipa3_ctx + 640) )
        return raw_spin_unlock_irqrestore(v6 + 146, v5);
    }
    v7 = v6[166];
    v8 = v7 + *v6;
    if ( v8 > 0x1FE || 510 - v8 < v6[161] )
      return raw_spin_unlock_irqrestore(v6 + 146, v5);
    v6[160] = 0;
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d IPA LL flow control lifted, %d + %d, %d\n",
          "apps_rmnet_ll_tx_complete_notify",
          893,
          *v6,
          v7,
          v6[160]);
        v10 = ipa3_ctx;
        v6 = (_DWORD *)rmnet_ll_ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d IPA LL flow control lifted, %d + %d, %d\n",
          "apps_rmnet_ll_tx_complete_notify",
          893,
          *v6,
          v6[166],
          v6[160]);
        v6 = (_DWORD *)rmnet_ll_ipa3_ctx;
      }
    }
    result = raw_spin_unlock_irqrestore(v6 + 146, v5);
    v13 = *(_DWORD **)(rmnet_ll_ipa3_ctx + 608);
    if ( v13 )
    {
      if ( *(v13 - 1) != -72220 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, _QWORD))v13)(2, 0);
    }
  }
  else
  {
    printk(&unk_3D6B12, "apps_rmnet_ll_tx_complete_notify");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d unsupported evt on Tx callback, Drop the packet\n",
          "apps_rmnet_ll_tx_complete_notify",
          856);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(
          v17,
          "ipa %s:%d unsupported evt on Tx callback, Drop the packet\n",
          "apps_rmnet_ll_tx_complete_notify",
          856);
    }
    v18 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
    v19 = rmnet_ll_ipa3_ctx;
    v20 = v18;
    v21 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 40);
    v22 = rmnet_ll_ipa3_ctx + 584;
    ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 32);
    *(_QWORD *)(v19 + 40) = v21 + *(unsigned int *)(a3 + 112);
    raw_spin_unlock_irqrestore(v22, v20);
    return dev_kfree_skb_any_reason(a3, 2);
  }
  return result;
}
