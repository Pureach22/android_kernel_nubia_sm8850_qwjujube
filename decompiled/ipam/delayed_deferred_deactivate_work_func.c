__int64 __fastcall delayed_deferred_deactivate_work_func(__int64 a1)
{
  const char *v1; // x20
  __int64 v2; // x21
  __int64 v4; // x22
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w3
  int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x23
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 ipc_logbuf; // x0
  __int64 v28; // x0
  __int64 ipc_logbuf_low; // x0

  v1 = (const char *)(a1 - 136);
  _ReadStatusReg(SP_EL0);
  if ( a1 == 136 )
  {
    v26 = printk(&unk_3D31B2, "delayed_deferred_deactivate_work_func");
    ipc_logbuf = ipa3_get_ipc_logbuf(v26);
    if ( ipc_logbuf )
    {
      v28 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v28,
                     "ipa_pm %s:%d Client already deregistered\n",
                     "delayed_deferred_deactivate_work_func",
                     472);
    }
    result = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 ipc_logbuf_low,
                 "ipa_pm %s:%d Client already deregistered\n",
                 "delayed_deferred_deactivate_work_func",
                 472);
    }
  }
  else
  {
    v2 = a1 - 36;
    v4 = raw_spin_lock_irqsave(a1 - 36);
    v5 = ipa3_get_ipc_logbuf_low(v4);
    if ( v5 )
    {
      v6 = ipa3_get_ipc_logbuf_low(v5);
      v7 = *(unsigned int *)(a1 - 56);
      if ( (unsigned int)v7 >= 7 )
        goto LABEL_35;
      v5 = ipc_log_string(
             v6,
             "ipa_pm %s:%d Client[%d] %s: %s\n",
             "delayed_deferred_deactivate_work_func",
             477,
             *(_DWORD *)(a1 - 44),
             v1,
             client_state_to_str[v7]);
    }
    v8 = *(_DWORD *)(a1 - 56);
    if ( v8 != 4 )
    {
      if ( v8 == 6 )
      {
        v15 = *(_QWORD *)(ipa_pm_ctx + 576);
        if ( ((*(_DWORD *)(ipa3_ctx + 32248) - 1) & 0xFFFFFFFD) != 0 )
          v16 = 100;
        else
          v16 = 500;
        v17 = _msecs_to_jiffies(v16);
        v5 = queue_delayed_work_on(32, v15, a1, v17);
        v9 = 4;
      }
      else
      {
        if ( v8 != 5 )
        {
          v21 = printk(&unk_3D5E39, "delayed_deferred_deactivate_work_func");
          v22 = ipa3_get_ipc_logbuf(v21);
          if ( v22 )
          {
            v23 = ipa3_get_ipc_logbuf(v22);
            v22 = ipc_log_string(
                    v23,
                    "ipa_pm %s:%d unexpected state %d\n",
                    "delayed_deferred_deactivate_work_func",
                    506,
                    *(_DWORD *)(a1 - 56));
          }
          v24 = ipa3_get_ipc_logbuf_low(v22);
          if ( v24 )
          {
            v25 = ipa3_get_ipc_logbuf_low(v24);
            v24 = ipc_log_string(
                    v25,
                    "ipa_pm %s:%d unexpected state %d\n",
                    "delayed_deferred_deactivate_work_func",
                    506,
                    *(_DWORD *)(a1 - 56));
          }
          __break(0x800u);
          v18 = ipa3_get_ipc_logbuf_low(v24);
          if ( !v18 )
            goto LABEL_23;
LABEL_21:
          v19 = ipa3_get_ipc_logbuf_low(v18);
          v20 = *(unsigned int *)(a1 - 56);
          if ( (unsigned int)v20 <= 6 )
          {
            ipc_log_string(
              v19,
              "ipa_pm %s:%d Client[%d] %s: %s\n",
              "delayed_deferred_deactivate_work_func",
              512,
              *(_DWORD *)(a1 - 44),
              v1,
              client_state_to_str[v20]);
            goto LABEL_23;
          }
LABEL_35:
          __break(0x5512u);
        }
        v9 = 3;
      }
      *(_DWORD *)(a1 - 56) = v9;
      v18 = ipa3_get_ipc_logbuf_low(v5);
      if ( !v18 )
      {
LABEL_23:
        result = raw_spin_unlock_irqrestore(v2, v4);
        goto LABEL_24;
      }
      goto LABEL_21;
    }
    *(_DWORD *)(a1 - 56) = 0;
    v10 = ipa3_get_ipc_logbuf_low(v5);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf_low(v10);
      v12 = *(unsigned int *)(a1 - 56);
      if ( (unsigned int)v12 > 6 )
        goto LABEL_35;
      ipc_log_string(
        v11,
        "ipa_pm %s:%d Client[%d] %s: %s\n",
        "delayed_deferred_deactivate_work_func",
        494,
        *(_DWORD *)(a1 - 44),
        v1,
        client_state_to_str[v12]);
    }
    raw_spin_unlock_irqrestore(v2, v4);
    if ( (*(_BYTE *)(a1 - 52) & 1) == 0 )
    {
      ipa3_dec_client_disable_clks();
      if ( *(_DWORD *)(a1 - 48) == 1 )
        _pm_relax(*(_QWORD *)(a1 + 136));
    }
    v13 = deactivate_client(*(unsigned int *)(a1 - 44));
    result = do_clk_scaling(v13);
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
