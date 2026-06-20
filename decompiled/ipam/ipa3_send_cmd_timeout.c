__int64 __fastcall ipa3_send_cmd_timeout(unsigned __int16 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x8
  unsigned __int16 *v7; // x26
  __int64 v8; // x28
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int ep_mapping; // w0
  unsigned int v13; // w24
  _DWORD *v14; // x19
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 result; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w20
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v33; // x26
  __int64 (*v34)(_QWORD, const char *, ...); // x0
  unsigned int v41; // w8
  unsigned int v42; // w8
  unsigned int v43; // [xsp+Ch] [xbp-4h]

  v43 = a1;
  if ( a1 )
  {
    v6 = ipa3_ctx;
    v7 = (unsigned __int16 *)(a2 + 36);
    v8 = a1;
    v9 = ipa3_ctx;
    do
    {
      if ( v9 )
      {
        v10 = *(_QWORD *)(v9 + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d sending imm cmd %d\n", "ipa3_send_cmd_timeout", 1016, *v7);
          v6 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v6 + 34160);
        v9 = v6;
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d sending imm cmd %d\n", "ipa3_send_cmd_timeout", 1016, *v7);
          v6 = ipa3_ctx;
          v9 = ipa3_ctx;
        }
      }
      --v8;
      v7 += 52;
    }
    while ( v8 );
  }
  ep_mapping = ipa_get_ep_mapping(36);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3DA941, "ipa3_send_cmd_timeout");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d Client %u is not mapped\n", "ipa3_send_cmd_timeout", 1021, 36);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d Client %u is not mapped\n", "ipa3_send_cmd_timeout", 1021, 36);
    }
    return 4294967282LL;
  }
  v13 = ep_mapping;
  v14 = (_DWORD *)_kmalloc_cache_noprof(ipc_log_string, 2336, 40);
  if ( !v14 )
    return 4294967284LL;
  while ( 1 )
  {
    *v14 = 0;
    _init_swait_queue_head(v14 + 2, "&x->wait", &init_completion___key_1);
    v14[8] = 2;
    if ( v13 < 0x24 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v33 = *(_QWORD *)(StatusReg + 80);
    v34 = ipc_log_string;
    *(_QWORD *)(StatusReg + 80) = &ipa3_send_cmd_timeout__alloc_tag;
    v14 = (_DWORD *)_kmalloc_cache_noprof(v34, 2336, 40);
    *(_QWORD *)(StatusReg + 80) = v33;
    if ( !v14 )
      return 4294967284LL;
  }
  v15 = *(_QWORD *)(ipa3_ctx + 480LL * v13 + 640);
  if ( a1 == 1 )
  {
    if ( *(_QWORD *)(a2 + 40) || *(_QWORD *)(a2 + 48) )
      __break(0x800u);
    *(_QWORD *)(a2 + 40) = ipa3_transport_irq_cmd_ack_free;
    *(_QWORD *)(a2 + 48) = v14;
    if ( (unsigned int)ipa3_send(v15, 1u, a2) )
    {
      printk(&unk_3CB958, "ipa3_send_cmd_timeout");
      v16 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v17 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v17 )
        {
          ipc_log_string(v17, "ipa %s:%d fail to send immediate command\n", "ipa3_send_cmd_timeout", 1043);
          v16 = ipa3_ctx;
        }
        v18 = *(_QWORD *)(v16 + 34160);
        if ( v18 )
          ipc_log_string(v18, "ipa %s:%d fail to send immediate command\n", "ipa3_send_cmd_timeout", 1043);
      }
LABEL_44:
      kfree(v14);
      return 4294967282LL;
    }
  }
  else
  {
    v19 = a2 + 104LL * a1;
    if ( *(_QWORD *)(v19 - 64) || *(_QWORD *)(v19 - 56) )
      __break(0x800u);
    *(_QWORD *)(v19 - 64) = ipa3_transport_irq_cmd_ack_free;
    *(_QWORD *)(v19 - 56) = v14;
    if ( (unsigned int)ipa3_send(v15, v43, a2) )
    {
      printk(&unk_3C9923, "ipa3_send_cmd_timeout");
      v29 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v30 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v30 )
        {
          ipc_log_string(v30, "ipa %s:%d fail to send multiple immediate command set\n", "ipa3_send_cmd_timeout", 1057);
          v29 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v29 + 34160);
        if ( v31 )
          ipc_log_string(v31, "ipa %s:%d fail to send multiple immediate command set\n", "ipa3_send_cmd_timeout", 1057);
      }
      goto LABEL_44;
    }
  }
  v20 = _msecs_to_jiffies(a3);
  if ( (unsigned int)wait_for_completion_timeout(v14, v20) )
  {
    result = 0;
  }
  else
  {
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d timeout waiting for imm-cmd ACK\n", "ipa3_send_cmd_timeout", 1067);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d timeout waiting for imm-cmd ACK\n", "ipa3_send_cmd_timeout", 1067);
    }
    result = 4294967280LL;
  }
  _X9 = v14 + 8;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v41 = __ldxr(_X9);
    v42 = v41 - 1;
  }
  while ( __stlxr(v42, _X9) );
  __dmb(0xBu);
  if ( !v42 )
  {
    v25 = result;
    kfree(v14);
    return v25;
  }
  return result;
}
