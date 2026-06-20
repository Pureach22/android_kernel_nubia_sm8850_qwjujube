__int64 __fastcall _ipa_gsi_irq_rx_scedule_poll(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x0
  unsigned int ep_mapping; // w0
  __int64 v5; // x1
  __int64 v6; // x8
  __int64 result; // x0
  __int64 v8; // x19
  int v9; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v11; // x0
  __int64 v12; // x8
  unsigned __int64 v19; // x8

  _ReadStatusReg(SP_EL0);
  *(_DWORD *)(a1 + 4) = 1;
  v2 = *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL);
  if ( v2 > 94 )
  {
    if ( v2 == 95 )
    {
      v3 = 35;
    }
    else
    {
      if ( v2 != 127 )
        goto LABEL_14;
      v3 = 33;
    }
  }
  else if ( v2 == 33 )
  {
    v3 = 127;
  }
  else
  {
    if ( v2 != 35 )
      goto LABEL_14;
    v3 = 95;
  }
  ep_mapping = ipa_get_ep_mapping(v3);
  if ( ep_mapping != -1 )
  {
    if ( ep_mapping >= 0x24 )
    {
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                       + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
          & 1) != 0 )
      {
        ++*(_DWORD *)(StatusReg + 16);
        v11 = _traceiter_ipa3_napi_schedule(0, v5);
        v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
        *(_DWORD *)(StatusReg + 16) = v12;
        if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
          preempt_schedule_notrace(v11);
      }
LABEL_22:
      v8 = *(_QWORD *)(a1 + 384);
      result = napi_schedule_prep(v8);
      if ( (result & 1) != 0 )
        result = _napi_schedule(v8);
      goto LABEL_19;
    }
    v6 = *(_QWORD *)(ipa3_ctx + 480LL * ep_mapping + 640);
    if ( v6 )
      *(_DWORD *)(v6 + 4) = 1;
  }
LABEL_14:
  ipa3_inc_acquire_wakelock();
  if ( (ipa_net_initialized != 1 || !*(_QWORD *)(a1 + 384))
    && (*(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL) | 0x10) != 0x79 )
  {
    goto LABEL_18;
  }
  result = ipa3_inc_client_enable_clks_no_block();
  if ( (_DWORD)result )
    goto LABEL_18;
  if ( ipa_net_initialized == 1 && *(_QWORD *)(a1 + 384) )
    goto LABEL_22;
  v9 = *(_DWORD *)(*(_QWORD *)(a1 + 1624) + 4LL);
  if ( v9 == 105 )
  {
    _X9 = (unsigned __int64 *)(a1 + 680);
    __asm { PRFM            #0x11, [X9] }
    do
      v19 = __ldxr(_X9);
    while ( __stlxr(v19 | 1, _X9) );
    __dmb(0xBu);
    if ( (v19 & 1) == 0 )
      result = _tasklet_schedule(a1 + 672);
  }
  else
  {
    if ( v9 != 121 )
    {
LABEL_18:
      result = queue_work_on(32, *(_QWORD *)(a1 + 1752), a1 + 192);
      goto LABEL_19;
    }
    result = napi_schedule_prep(a1 + 1152);
    if ( (result & 1) != 0 )
      result = _napi_schedule(a1 + 1152);
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
