__int64 __fastcall ipa_pm_deactivate_all_deferred(__int64 a1)
{
  char v1; // w26
  __int64 i; // x28
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  bool v12; // zf
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 result; // x0
  __int64 v17; // x0
  __int64 ipc_logbuf; // x0
  __int64 v19; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v21; // x0

  _ReadStatusReg(SP_EL0);
  if ( !ipa_pm_ctx )
  {
    v17 = printk(&unk_3F575E, "ipa_pm_deactivate_all_deferred");
    ipc_logbuf = ipa3_get_ipc_logbuf(v17);
    if ( ipc_logbuf )
    {
      v19 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v19, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_deactivate_all_deferred", 1139);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v21 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v21, "ipa_pm %s:%d PM_ctx is null\n", "ipa_pm_deactivate_all_deferred", 1139);
    }
    result = 4294967274LL;
    goto LABEL_29;
  }
  v1 = 0;
  for ( i = 1; i != 36; ++i )
  {
    while ( 1 )
    {
      v3 = *(_QWORD *)(ipa_pm_ctx + 8 * i);
      if ( !v3 )
        goto LABEL_4;
      cancel_delayed_work_sync(v3 + 136);
      if ( (unsigned int)(*(_DWORD *)(v3 + 80) - 1) <= 1 )
      {
        a1 = wait_for_completion(v3 + 240);
        goto LABEL_4;
      }
      v4 = raw_spin_lock_irqsave(v3 + 100);
      v5 = ipa3_get_ipc_logbuf_low(v4);
      if ( v5 )
      {
        v6 = ipa3_get_ipc_logbuf_low(v5);
        v7 = *(unsigned int *)(v3 + 80);
        if ( (unsigned int)v7 > 6 )
          goto LABEL_35;
        v5 = ipc_log_string(
               v6,
               "ipa_pm %s:%d Client[%d] %s: %s\n",
               "ipa_pm_deactivate_all_deferred",
               1157,
               *(_DWORD *)(v3 + 92),
               (const char *)v3,
               client_state_to_str[v7]);
      }
      v8 = *(_DWORD *)(v3 + 80);
      if ( v8 == 5 )
      {
        *(_DWORD *)(v3 + 80) = 3;
        v13 = ipa3_get_ipc_logbuf_low(v5);
        if ( v13 )
        {
          v14 = ipa3_get_ipc_logbuf_low(v13);
          v15 = *(unsigned int *)(v3 + 80);
          if ( (unsigned int)v15 > 6 )
LABEL_35:
            __break(0x5512u);
          ipc_log_string(
            v14,
            "ipa_pm %s:%d Client[%d] %s: %s\n",
            "ipa_pm_deactivate_all_deferred",
            1162,
            *(_DWORD *)(v3 + 92),
            (const char *)v3,
            client_state_to_str[v15]);
        }
        break;
      }
      if ( v8 != 4 && v8 != 6 )
        break;
      *(_DWORD *)(v3 + 80) = 0;
      v9 = ipa3_get_ipc_logbuf_low(v5);
      if ( v9 )
      {
        v10 = ipa3_get_ipc_logbuf_low(v9);
        v11 = *(unsigned int *)(v3 + 80);
        if ( (unsigned int)v11 > 6 )
          goto LABEL_35;
        ipc_log_string(
          v10,
          "ipa_pm %s:%d Client[%d] %s: %s\n",
          "ipa_pm_deactivate_all_deferred",
          1171,
          *(_DWORD *)(v3 + 92),
          (const char *)v3,
          client_state_to_str[v11]);
      }
      raw_spin_unlock_irqrestore(v3 + 100, v4);
      if ( (*(_BYTE *)(v3 + 84) & 1) == 0 )
      {
        ipa3_dec_client_disable_clks();
        if ( *(_DWORD *)(v3 + 88) == 1 )
          _pm_relax(*(_QWORD *)(v3 + 272));
      }
      a1 = deactivate_client(*(unsigned int *)(v3 + 92));
      v12 = i++ == 35;
      v1 = 1;
      if ( v12 )
        goto LABEL_27;
    }
    a1 = raw_spin_unlock_irqrestore(v3 + 100, v4);
LABEL_4:
    ;
  }
  if ( (v1 & 1) == 0 )
    goto LABEL_28;
LABEL_27:
  do_clk_scaling(a1);
LABEL_28:
  result = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
