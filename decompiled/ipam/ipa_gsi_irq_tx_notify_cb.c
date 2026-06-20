__int64 __fastcall ipa_gsi_irq_tx_notify_cb(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x19
  __int64 v3; // x21
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x19
  unsigned int v16; // w9
  unsigned __int64 v19; // x9
  unsigned int v25; // w9

  v1 = result;
  _ReadStatusReg(SP_EL0);
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(
                 result,
                 "ipa %s:%d event %d notified\n",
                 "ipa_gsi_irq_tx_notify_cb",
                 6499,
                 *(_DWORD *)(v1 + 16));
  }
  if ( *(_DWORD *)(v1 + 16) != 2 )
  {
    result = printk(&unk_3ACA94, "ipa_gsi_irq_tx_notify_cb");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(
          v11,
          "ipa %s:%d received unexpected event id %d\n",
          "ipa_gsi_irq_tx_notify_cb",
          6531,
          *(_DWORD *)(v1 + 16));
        v10 = ipa3_ctx;
      }
      result = *(_QWORD *)(v10 + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d received unexpected event id %d\n",
                   "ipa_gsi_irq_tx_notify_cb",
                   6531,
                   *(_DWORD *)(v1 + 16));
    }
    goto LABEL_40;
  }
  *(_DWORD *)(ipa3_ctx + 31972) = 1;
  v2 = *(_QWORD *)(v1 + 8);
  v3 = *(_QWORD *)(v2 + 72);
  *(_BYTE *)(v2 + 97) = 1;
  if ( *(_BYTE *)(v3 + 1584) != 1 )
  {
    if ( ipa_net_initialized != 1 || *(_BYTE *)(v3 + 1585) != 1 )
      goto LABEL_44;
    _X8 = (unsigned int *)(v3 + 1588);
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v25 = __ldxr(_X8);
      if ( v25 )
        break;
      if ( !__stlxr(1u, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    if ( v25 )
      goto LABEL_40;
    goto LABEL_38;
  }
  if ( *(_DWORD *)(v3 + 4) )
    goto LABEL_40;
  if ( !(unsigned int)ipa3_inc_client_enable_clks_no_block() )
  {
    gsi_config_channel_mode(*(_QWORD *)(*(_QWORD *)(v3 + 1624) + 8LL), 1);
    *(_DWORD *)(v3 + 4) = 1;
    v8 = *(_DWORD *)(*(_QWORD *)(v3 + 1624) + 4LL);
    if ( v8 > 94 )
    {
      if ( v8 == 95 )
      {
        v9 = 35;
      }
      else
      {
        if ( v8 != 127 )
          goto LABEL_38;
        v9 = 33;
      }
    }
    else if ( v8 == 33 )
    {
      v9 = 127;
    }
    else
    {
      if ( v8 != 35 )
        goto LABEL_38;
      v9 = 95;
    }
    result = ipa_get_ep_mapping(v9);
    if ( (_DWORD)result != -1 )
    {
      if ( (unsigned int)result < 0x24 )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 480LL * (unsigned int)result + 640);
        if ( v12 )
          *(_DWORD *)(v12 + 4) = 1;
        goto LABEL_38;
      }
      __break(0x5512u);
LABEL_44:
      _X8 = (unsigned int *)(v3 + 664);
      __asm { PRFM            #0x11, [X8] }
      do
        v16 = __ldxr(_X8);
      while ( __stxr(v16 + 1, _X8) );
      v5 = *(_QWORD *)(v2 + 72);
      _X10 = (unsigned __int64 *)(v5 + 680);
      __asm { PRFM            #0x11, [X10] }
      do
        v19 = __ldxr(_X10);
      while ( __stlxr(v19 | 1, _X10) );
      __dmb(0xBu);
      if ( (v19 & 1) == 0 )
        result = _tasklet_schedule(v5 + 672);
      goto LABEL_40;
    }
LABEL_38:
    v13 = *(_QWORD *)(v2 + 72);
    result = napi_schedule_prep(v13 + 720);
    if ( (result & 1) != 0 )
      result = _napi_schedule(v13 + 720);
    goto LABEL_40;
  }
  result = __ratelimit(&ipa_gsi_irq_tx_notify_cb__rs, "ipa_gsi_irq_tx_notify_cb");
  if ( (_DWORD)result )
  {
    result = printk(&unk_3E64F7, "ipa_gsi_irq_tx_notify_cb");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_40;
  }
  else
  {
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_40;
  }
  v7 = *(_QWORD *)(v6 + 34152);
  if ( v7 )
  {
    ipc_log_string(v7, "ipa %s:%d clk off, event likely handled in NAPI contxt", "ipa_gsi_irq_tx_notify_cb", 6512);
    v6 = ipa3_ctx;
  }
  result = *(_QWORD *)(v6 + 34160);
  if ( result )
    result = ipc_log_string(
               result,
               "ipa %s:%d clk off, event likely handled in NAPI contxt",
               "ipa_gsi_irq_tx_notify_cb",
               6512);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
