__int64 __fastcall rndis_ipa_pipe_disconnect_notify(_QWORD *a1)
{
  __int64 v2; // x20
  int state; // w21
  long double v4; // q0
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x21
  const char *v8; // x0
  size_t v9; // x0
  unsigned __int64 v10; // x2
  long double v11; // q0
  __int64 v12; // x8
  __int64 v13; // x20
  __int64 v14; // x0
  __int64 v15; // x21
  int v16; // w0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x8
  const char *v20; // x4
  unsigned __int64 StatusReg; // x21
  __int64 v22; // x23
  long double (*v23)(_QWORD, const char *, ...); // x0
  unsigned __int64 v30; // x9
  int v31; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d begin\n", "rndis_ipa_pipe_disconnect_notify", 1372);
  if ( !a1 )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3E01BA, "rndis_ipa_pipe_disconnect_notify");
    if ( ipa_rndis_logbuf )
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d null pointer #ptr\n", "rndis_ipa_pipe_disconnect_notify", 1375);
    result = 4294967274LL;
    goto LABEL_54;
  }
  if ( ipa_rndis_logbuf )
    ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d private=0x%pK\n", "rndis_ipa_pipe_disconnect_notify", 1378, a1);
  v2 = raw_spin_lock_irqsave(a1 + 25);
  state = rndis_ipa_next_state(*((_DWORD *)a1 + 18), 4);
  raw_spin_unlock_irqrestore(a1 + 25, v2);
  if ( state == 5 )
  {
    if ( (unsigned int)__ratelimit(&rndis_ipa_pipe_disconnect_notify__rs, "rndis_ipa_pipe_disconnect_notify") )
    {
      _ReadStatusReg(SP_EL0);
      printk(&unk_3CEECA, "rndis_ipa_pipe_disconnect_notify");
      v5 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_46;
    }
    else
    {
      v5 = ipa_rndis_logbuf;
      if ( !ipa_rndis_logbuf )
        goto LABEL_46;
    }
    ipc_log_string(v5, "RNDIS_IPA %s:%d can't disconnect before connect\n", "rndis_ipa_pipe_disconnect_notify", 1387);
    goto LABEL_32;
  }
  if ( *((_BYTE *)a1 + 27) == 1 )
  {
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d canceling xmit-error delayed work\n",
        "rndis_ipa_pipe_disconnect_notify",
        1393);
    cancel_delayed_work_sync(a1 + 12);
    *((_BYTE *)a1 + 27) = 0;
  }
  netif_carrier_off(*a1, v4);
  if ( ipa_rndis_logbuf )
    ipc_log_string(
      ipa_rndis_logbuf,
      "RNDIS_IPA %s:%d carrier_off notification was sent\n",
      "rndis_ipa_pipe_disconnect_notify",
      1400);
  v6 = _kmalloc_cache_noprof(ipc_log_string, 3520, 36);
  if ( !v6 )
  {
LABEL_53:
    result = 4294967284LL;
    goto LABEL_54;
  }
  while ( 1 )
  {
    v7 = *a1;
    v8 = (const char *)(*a1 + 296LL);
    v31 = 2359316;
    v9 = strnlen(v8, 0x10u);
    if ( v9 < 0x10 || v9 == 32 )
      break;
    _fortify_panic(2, 16, v9 + 1);
LABEL_52:
    _fortify_panic(7, 32, v10);
    StatusReg = _ReadStatusReg(SP_EL0);
    v22 = *(_QWORD *)(StatusReg + 80);
    v23 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &rndis_ipa_pipe_disconnect_notify__alloc_tag;
    v6 = _kmalloc_cache_noprof(v23, 3520, 36);
    *(_QWORD *)(StatusReg + 80) = v22;
    if ( !v6 )
      goto LABEL_53;
  }
  if ( v9 == 32 )
    v10 = 32;
  else
    v10 = v9 + 1;
  if ( v10 >= 0x21 )
    goto LABEL_52;
  sized_strscpy(v6, v7 + 296);
  *(_DWORD *)(v6 + 32) = *(_DWORD *)(*a1 + 224LL);
  if ( (unsigned int)ipa_send_msg((unsigned __int8 *)&v31, (_WORD *)v6, rndis_ipa_msg_free_cb) )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3EE1A3, "rndis_ipa_pipe_disconnect_notify");
    if ( ipa_rndis_logbuf )
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d fail to send ECM_DISCONNECT for rndis\n",
        "rndis_ipa_pipe_disconnect_notify",
        1415);
    kfree(v6);
    result = 0xFFFFFFFFLL;
    goto LABEL_54;
  }
  v12 = *(_QWORD *)(*a1 + 24LL);
  *(_QWORD *)(v12 + 328) = jiffies;
  __dmb(0xBu);
  _X8 = (unsigned __int64 *)(v12 + 336);
  __asm { PRFM            #0x11, [X8] }
  do
    v30 = __ldxr(_X8);
  while ( __stxr(v30 | 1, _X8) );
  if ( ipa_rndis_logbuf )
    v11 = ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d queue stopped\n", "rndis_ipa_pipe_disconnect_notify", 1421);
  v13 = *((int *)a1 + 14);
  *(_QWORD *)(*a1 + 608LL) += v13;
  *((_DWORD *)a1 + 14) = 0;
  ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(*((unsigned int *)a1 + 51), v11);
  ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*((unsigned int *)a1 + 51));
  v14 = ipa_rndis_logbuf;
  *((_DWORD *)a1 + 51) = -1;
  if ( v14 )
    ipc_log_string(v14, "RNDIS_IPA %s:%d PM was successfully deregistered\n", "rndis_ipa_pipe_disconnect_notify", 1434);
  v15 = raw_spin_lock_irqsave(a1 + 25);
  v16 = rndis_ipa_next_state(*((_DWORD *)a1 + 18), 4);
  if ( v16 != 5 )
  {
    *((_DWORD *)a1 + 18) = v16;
    raw_spin_unlock_irqrestore(a1 + 25, v15);
    if ( ipa_rndis_logbuf )
    {
      v19 = *((unsigned int *)a1 + 18);
      if ( (unsigned int)v19 > 4 )
        v20 = "Not supported";
      else
        v20 = off_1F6620[v19];
      ipc_log_string(
        ipa_rndis_logbuf,
        "RNDIS_IPA %s:%d Driver state: %s\n",
        "rndis_ipa_pipe_disconnect_notify",
        1447,
        v20);
    }
    printk(&unk_3F45D3, (unsigned int)v13);
    result = ipa_rndis_logbuf;
    if ( ipa_rndis_logbuf )
    {
      ipc_log_string(ipa_rndis_logbuf, "RNDIS_IPA %s:%d end\n", "rndis_ipa_pipe_disconnect_notify", 1452);
      result = 0;
    }
    goto LABEL_54;
  }
  raw_spin_unlock_irqrestore(a1 + 25, v15);
  if ( (unsigned int)__ratelimit(&rndis_ipa_pipe_disconnect_notify__rs_86, "rndis_ipa_pipe_disconnect_notify") )
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_3CEECA, "rndis_ipa_pipe_disconnect_notify");
    v17 = ipa_rndis_logbuf;
    if ( !ipa_rndis_logbuf )
      goto LABEL_46;
LABEL_31:
    ipc_log_string(v17, "RNDIS_IPA %s:%d can't disconnect before connect\n", "rndis_ipa_pipe_disconnect_notify", 1441);
LABEL_32:
    result = 0xFFFFFFFFLL;
    goto LABEL_54;
  }
  v17 = ipa_rndis_logbuf;
  if ( ipa_rndis_logbuf )
    goto LABEL_31;
LABEL_46:
  result = 0xFFFFFFFFLL;
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
