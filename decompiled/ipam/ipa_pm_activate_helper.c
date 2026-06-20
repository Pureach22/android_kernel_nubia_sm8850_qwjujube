__int64 __fastcall ipa_pm_activate_helper(__int64 a1, char a2)
{
  __int64 v4; // x20
  __int64 ipc_logbuf_low; // x0
  _QWORD *v6; // x0
  __int64 v7; // x13
  __int64 v8; // x8
  int v9; // w8
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  int v16; // w8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 ipc_logbuf; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0

  _ReadStatusReg(SP_EL0);
  v4 = raw_spin_lock_irqsave(a1 + 100);
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(v4);
  if ( ipc_logbuf_low )
  {
    v6 = (_QWORD *)ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    v8 = *(unsigned int *)(a1 + 80);
    if ( (unsigned int)v8 >= 7 )
      goto LABEL_42;
    ipc_logbuf_low = ipc_log_string(
                       v6,
                       "ipa_pm %s:%d Client[%d] %s: %s\n",
                       "ipa_pm_activate_helper",
                       940,
                       *(_DWORD *)(a1 + 92),
                       (const char *)a1,
                       client_state_to_str[v8]);
  }
  v9 = *(_DWORD *)(a1 + 80);
  if ( (unsigned int)(v9 - 1) <= 1 )
  {
    if ( (a2 & 1) == 0 )
    {
      *(_DWORD *)(a1 + 80) = 2;
      raw_spin_unlock_irqrestore(a1 + 100, v4);
      goto LABEL_17;
    }
    raw_spin_unlock_irqrestore(a1 + 100, v4);
    wait_for_completion(a1 + 240);
    ipc_logbuf_low = raw_spin_lock_irqsave(a1 + 100);
    v9 = *(_DWORD *)(a1 + 80);
    v4 = ipc_logbuf_low;
  }
  if ( v9 > 3 )
  {
    switch ( v9 )
    {
      case 6:
        goto LABEL_11;
      case 5:
LABEL_14:
        raw_spin_unlock_irqrestore(a1 + 100, v4);
LABEL_15:
        result = 0;
LABEL_18:
        _ReadStatusReg(SP_EL0);
        return result;
      case 4:
LABEL_11:
        *(_DWORD *)(a1 + 80) = 5;
        goto LABEL_14;
    }
LABEL_37:
    v21 = printk(&unk_3FB855, "ipa_pm_activate_helper");
    ipc_logbuf = ipa3_get_ipc_logbuf(v21);
    if ( ipc_logbuf )
    {
      v23 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v23, "ipa_pm %s:%d Invalid State\n", "ipa_pm_activate_helper", 968);
    }
    v24 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( v24 )
    {
      v25 = ipa3_get_ipc_logbuf_low(v24);
      ipc_log_string(v25, "ipa_pm %s:%d Invalid State\n", "ipa_pm_activate_helper", 968);
    }
    raw_spin_unlock_irqrestore(a1 + 100, v4);
    result = 0xFFFFFFFFLL;
    goto LABEL_18;
  }
  if ( v9 )
  {
    if ( v9 == 3 )
      goto LABEL_14;
    goto LABEL_37;
  }
  v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
  if ( v11 )
  {
    v6 = (_QWORD *)ipa3_get_ipc_logbuf_low(v11);
    v12 = *(unsigned int *)(a1 + 80);
    if ( (unsigned int)v12 > 6 )
      goto LABEL_42;
    ipc_log_string(
      v6,
      "ipa_pm %s:%d Client[%d] %s: %s\n",
      "ipa_pm_activate_helper",
      972,
      *(_DWORD *)(a1 + 92),
      (const char *)a1,
      client_state_to_str[v12]);
  }
  if ( (*(_BYTE *)(a1 + 84) & 1) != 0 )
    goto LABEL_29;
  if ( (a2 & 1) != 0 )
  {
    *(_DWORD *)(a1 + 80) = 2;
    raw_spin_unlock_irqrestore(a1 + 100, v4);
    ipa3_inc_client_enable_clks();
    v4 = raw_spin_lock_irqsave(a1 + 100);
    goto LABEL_29;
  }
  if ( (unsigned int)ipa3_inc_client_enable_clks_no_block() )
  {
    *(_DWORD *)(a1 + 240) = 0;
    *(_DWORD *)(a1 + 80) = 2;
    queue_work_on(32, *(_QWORD *)(ipa_pm_ctx + 576), a1 + 104);
    v13 = raw_spin_unlock_irqrestore(a1 + 100, v4);
    v14 = ipa3_get_ipc_logbuf_low(v13);
    if ( v14 )
    {
      v6 = (_QWORD *)ipa3_get_ipc_logbuf_low(v14);
      v15 = *(unsigned int *)(a1 + 80);
      if ( (unsigned int)v15 > 6 )
        goto LABEL_42;
      ipc_log_string(
        v6,
        "ipa_pm %s:%d Client[%d] %s: %s\n",
        "ipa_pm_activate_helper",
        1006,
        *(_DWORD *)(a1 + 92),
        (const char *)a1,
        client_state_to_str[v15]);
    }
LABEL_17:
    result = 4294967181LL;
    goto LABEL_18;
  }
LABEL_29:
  v16 = *(_DWORD *)(a1 + 88);
  *(_DWORD *)(a1 + 80) = 3;
  if ( v16 == 1 )
    _pm_stay_awake(*(_QWORD *)(a1 + 272));
  raw_spin_unlock_irqrestore(a1 + 100, v4);
  v17 = ((__int64 (__fastcall *)(_QWORD))activate_client)(*(unsigned int *)(a1 + 92));
  if ( (a2 & 1) != 0 )
  {
    v18 = do_clk_scaling(v17);
    result = ipa3_get_ipc_logbuf_low(v18);
    if ( !result )
      goto LABEL_18;
  }
  else
  {
    v19 = queue_work_on(32, *(_QWORD *)(ipa_pm_ctx + 576), ipa_pm_ctx + 1072);
    result = ipa3_get_ipc_logbuf_low(v19);
    if ( !result )
      goto LABEL_18;
  }
  v6 = (_QWORD *)ipa3_get_ipc_logbuf_low(result);
  v20 = *(unsigned int *)(a1 + 80);
  if ( (unsigned int)v20 <= 6 )
  {
    ipc_log_string(
      v6,
      "ipa_pm %s:%d Client[%d] %s: %s\n",
      "ipa_pm_activate_helper",
      998,
      *(_DWORD *)(a1 + 92),
      (const char *)a1,
      client_state_to_str[v20]);
    goto LABEL_15;
  }
LABEL_42:
  __break(0x5512u);
  *v6 = v7;
  return ipa_pm_activate_sync((char *)v6 + 217);
}
