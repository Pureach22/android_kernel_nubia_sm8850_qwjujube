void __fastcall rndis_ipa_xmit_error(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 v4; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x10
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v15[0] = 0;
  if ( ipa_rndis_logbuf )
  {
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_xmit_error", 1576);
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d starting Tx-queue backoff\n", "rndis_ipa_xmit_error", 1578);
  }
  v3 = *(_QWORD *)(*(_QWORD *)(v2 + 2688) + 24LL);
  *(_QWORD *)(v3 + 328) = jiffies;
  __dmb(0xBu);
  _X8 = (unsigned __int64 *)(v3 + 336);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 1, _X8) );
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d netif_stop_queue was called\n", "rndis_ipa_xmit_error", 1581);
  skb_pull(a1, 44);
  ++*(_QWORD *)(*(_QWORD *)(v2 + 2688) + 592LL);
  get_random_bytes(v15, 1);
  v4 = _msecs_to_jiffies(*(_DWORD *)(v2 + 2756) + (unsigned int)v15[0]);
  if ( (queue_delayed_work_on(32, system_wq, v2 + 2784, v4) & 1) != 0 )
  {
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d work scheduled to start Tx-queue in %d msec\n",
        "rndis_ipa_xmit_error",
        1599,
        *(_DWORD *)(v2 + 2756) + v15[0]);
    *(_BYTE *)(v2 + 2715) = 1;
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3C637B, "rndis_ipa_xmit_error");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d fail to schedule delayed work\n", "rndis_ipa_xmit_error", 1593);
    _X8 = (unsigned __int64 *)(*(_QWORD *)(*(_QWORD *)(v2 + 2688) + 24LL) + 336LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFELL, _X8) );
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_xmit_error", 1603);
  _ReadStatusReg(SP_EL0);
}
