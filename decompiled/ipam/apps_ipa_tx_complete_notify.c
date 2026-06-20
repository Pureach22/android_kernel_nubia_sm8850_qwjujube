__int64 __fastcall apps_ipa_tx_complete_notify(__int64 a1, int a2, __int64 a3)
{
  _QWORD *v5; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x22
  long double v9; // q0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 result; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v21; // w10

  v5 = (_QWORD *)rmnet_ipa3_ctx;
  if ( rmnet_ipa3_ctx )
  {
    v5 = *(_QWORD **)rmnet_ipa3_ctx;
    if ( *(_QWORD *)rmnet_ipa3_ctx )
      v5 = (_QWORD *)*v5;
  }
  if ( v5 != (_QWORD *)a1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d Received pre-SSR packet completion\n",
        "apps_ipa_tx_complete_notify",
        1363);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d Received pre-SSR packet completion\n",
        "apps_ipa_tx_complete_notify",
        1363);
    }
    return dev_kfree_skb_any_reason(a3, 2);
  }
  if ( a2 == 1 )
  {
    _X8 = (unsigned int *)(a1 + 2880);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 - 1, _X8) );
    v8 = *(_QWORD *)(a1 + 24);
    raw_spin_lock_bh(v8 + 320);
    *(_DWORD *)(v8 + 324) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
    if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1056)
      && (*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2688) + 24LL) + 336LL) & 1) != 0
      && *(_DWORD *)(a1 + 2880) < *(_DWORD *)(rmnet_ipa3_ctx + 1944) )
    {
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        v9 = ipc_log_string(
               v10,
               "ipa-wan %s:%d Outstanding low (%d) - waking up queue\n",
               "apps_ipa_tx_complete_notify",
               1383,
               *(_DWORD *)(rmnet_ipa3_ctx + 1944));
      }
      netif_tx_wake_queue(*(_QWORD *)(*(_QWORD *)(a1 + 2688) + 24LL), v9);
    }
    if ( !*(_DWORD *)(a1 + 2880) )
    {
      ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ipa3_ctx + 1184));
      ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(rmnet_ipa3_ctx + 1188));
    }
    v11 = *(_QWORD *)(a1 + 24);
    *(_DWORD *)(v11 + 324) = -1;
    raw_spin_unlock_bh(v11 + 320);
    return dev_kfree_skb_any_reason(a3, 2);
  }
  printk(&unk_3CABCF, "apps_ipa_tx_complete_notify");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v13,
      "ipa-wan %s:%d unsupported evt on Tx callback, Drop the packet\n",
      "apps_ipa_tx_complete_notify",
      1369);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v14,
      "ipa-wan %s:%d unsupported evt on Tx callback, Drop the packet\n",
      "apps_ipa_tx_complete_notify",
      1369);
  }
  result = dev_kfree_skb_any_reason(a3, 2);
  ++*(_QWORD *)(a1 + 608);
  return result;
}
