__int64 __fastcall activate_work_func(__int64 a1)
{
  const char *v2; // x19
  __int64 v3; // x22
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  int v7; // w3
  _DWORD *v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 ipc_logbuf; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0

  v2 = (const char *)(a1 - 104);
  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(a1 - 20) & 1) == 0 )
  {
    ipa3_inc_client_enable_clks();
    if ( *(_DWORD *)(a1 - 16) == 1 )
      _pm_stay_awake(*(_QWORD *)(a1 + 168));
  }
  v3 = raw_spin_lock_irqsave(a1 - 4);
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(v3);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    v6 = *(unsigned int *)(a1 - 24);
    if ( (unsigned int)v6 >= 7 )
      goto LABEL_30;
    ipc_log_string(
      v5,
      "ipa_pm %s:%d Client[%d] %s: %s\n",
      "activate_work_func",
      420,
      *(_DWORD *)(a1 - 12),
      v2,
      client_state_to_str[v6]);
  }
  v7 = *(_DWORD *)(a1 - 24);
  if ( v7 != 1 )
  {
    if ( v7 == 2 )
    {
      *(_DWORD *)(a1 - 24) = 3;
    }
    else
    {
      v18 = printk(&unk_3D5E39, "activate_work_func");
      ipc_logbuf = ipa3_get_ipc_logbuf(v18);
      if ( ipc_logbuf )
      {
        v20 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v20,
                       "ipa_pm %s:%d unexpected state %d\n",
                       "activate_work_func",
                       427,
                       *(_DWORD *)(a1 - 24));
      }
      v21 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v21 )
      {
        v22 = ipa3_get_ipc_logbuf_low(v21);
        ipc_log_string(v22, "ipa_pm %s:%d unexpected state %d\n", "activate_work_func", 427, *(_DWORD *)(a1 - 24));
      }
      __break(0x800u);
    }
    raw_spin_unlock_irqrestore(a1 - 4, v3);
    complete_all(a1 + 136);
    ((void (__fastcall *)(_QWORD))activate_client)(*(unsigned int *)(a1 - 12));
    mutex_lock(ipa_pm_ctx + 1152);
    v8 = *(_DWORD **)(a1 - 40);
    if ( v8 )
    {
      v9 = *(_QWORD *)(a1 - 32);
      if ( *(v8 - 1) != -629992140 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v8)(v9, 0);
    }
    v10 = mutex_unlock(ipa_pm_ctx + 1152);
    v11 = ipa3_get_ipc_logbuf_low(v10);
    if ( !v11 )
      goto LABEL_17;
    v12 = ipa3_get_ipc_logbuf_low(v11);
    v13 = *(unsigned int *)(a1 - 24);
    if ( (unsigned int)v13 <= 6 )
    {
      v11 = ipc_log_string(
              v12,
              "ipa_pm %s:%d Client[%d] %s: %s\n",
              "activate_work_func",
              454,
              *(_DWORD *)(a1 - 12),
              v2,
              client_state_to_str[v13]);
LABEL_17:
      result = do_clk_scaling(v11);
      goto LABEL_24;
    }
LABEL_30:
    __break(0x5512u);
  }
  *(_DWORD *)(a1 - 24) = 0;
  raw_spin_unlock_irqrestore(a1 - 4, v3);
  v15 = complete_all(a1 + 136);
  if ( (*(_BYTE *)(a1 - 20) & 1) == 0 )
  {
    v15 = ipa3_dec_client_disable_clks();
    if ( *(_DWORD *)(a1 - 16) == 1 )
      v15 = _pm_relax(*(_QWORD *)(a1 + 168));
  }
  result = ipa3_get_ipc_logbuf_low(v15);
  if ( result )
  {
    v16 = ipa3_get_ipc_logbuf_low(result);
    v17 = *(unsigned int *)(a1 - 24);
    if ( (unsigned int)v17 <= 6 )
    {
      result = ipc_log_string(
                 v16,
                 "ipa_pm %s:%d Client[%d] %s: %s\n",
                 "activate_work_func",
                 441,
                 *(_DWORD *)(a1 - 12),
                 v2,
                 client_state_to_str[v17]);
      goto LABEL_24;
    }
    goto LABEL_30;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
