__int64 __fastcall ipa_bridge_suspend(unsigned int a1)
{
  __int64 v2; // x0
  unsigned int v3; // w21
  __int64 v4; // x8
  __int64 v5; // x10
  __int64 v6; // x9
  __int64 v7; // x8
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  unsigned int v24; // w19
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  long double v28; // q0
  __int64 v29; // x0
  __int64 v30; // x0

  if ( !ipa_gsb_ctx )
  {
    printk(&unk_3C85BE, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_suspend", 1080);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_suspend", 1080);
      return 4294967282LL;
    }
    return 4294967282LL;
  }
  if ( a1 >= 5 )
  {
    printk(&unk_3E7C9B, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v17 = ipa3_get_ipc_logbuf();
      ipc_log_string(v17, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_suspend", 1085, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v18, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_suspend", 1085, a1);
    }
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v2 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v2, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_suspend", 1089, a1);
  }
  v3 = a1;
  mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
  v4 = ipa_gsb_ctx;
  v5 = ipa_gsb_ctx + 8LL * a1;
  *(_DWORD *)(ipa_gsb_ctx + 404) = 1;
  v6 = *(_QWORD *)(v5 + 96);
  if ( !v6 )
  {
    printk(&unk_3AB2AC, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_suspend", 1094, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_suspend", 1094, a1);
    }
    goto LABEL_36;
  }
  if ( (*(_BYTE *)(v6 + 104) & 1) == 0 )
  {
    printk(&unk_3CE2F3, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa_gsb %s:%d iface is not connected\n", "ipa_bridge_suspend", 1101);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_gsb %s:%d iface is not connected\n", "ipa_bridge_suspend", 1101);
    }
LABEL_36:
    v23 = ipa_gsb_ctx + 48LL * a1;
    *(_DWORD *)(ipa_gsb_ctx + 404) = 0;
    mutex_unlock(v23 + 136);
    return 4294967282LL;
  }
  if ( (*(_BYTE *)(v6 + 105) & 1) == 0 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v13 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v13, "ipa_gsb %s:%d iface was already suspended\n", "ipa_bridge_suspend", 1108);
    }
    v12 = ipa_gsb_ctx + 48LL * a1;
    *(_DWORD *)(ipa_gsb_ctx + 404) = 0;
    goto LABEL_18;
  }
  mutex_lock(v4 + 16);
  v7 = ipa_gsb_ctx;
  if ( *(_DWORD *)(ipa_gsb_ctx + 92) != 1 )
  {
LABEL_12:
    *(_BYTE *)(*(_QWORD *)(v7 + 8LL * a1 + 96) + 105LL) = 0;
    --*(_DWORD *)(v7 + 92);
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v10,
        "ipa_gsb %s:%d num resumed iface: %d\n",
        "ipa_bridge_suspend",
        1142,
        *(_DWORD *)(ipa_gsb_ctx + 92));
    }
    v11 = ipa_gsb_ctx + 16;
    *(_DWORD *)(ipa_gsb_ctx + 404) = 0;
    mutex_unlock(v11);
    v12 = ipa_gsb_ctx + 48LL * a1;
LABEL_18:
    mutex_unlock(v12 + 136);
    return 0;
  }
  v8 = ipa_stop_gsi_channel(*(_DWORD *)(ipa_gsb_ctx + 68));
  if ( v8 )
  {
    v24 = v8;
    printk(&unk_3E2319, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa_gsb %s:%d fail to stop cons ep %d\n", "ipa_bridge_suspend", 1121, v24);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_gsb %s:%d fail to stop cons ep %d\n", "ipa_bridge_suspend", 1121, v24);
    }
  }
  else
  {
    v9 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_gsb_ctx + 396));
    if ( !v9 )
    {
      v7 = ipa_gsb_ctx;
      goto LABEL_12;
    }
    v24 = v9;
    printk(&unk_3A8185, "ipa_bridge_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa_gsb %s:%d fail to deactivate ipa pm\n", "ipa_bridge_suspend", 1130);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      v28 = ipc_log_string(v29, "ipa_gsb %s:%d fail to deactivate ipa pm\n", "ipa_bridge_suspend", 1130);
    }
    ((void (__fastcall *)(_QWORD, long double))ipa3_start_gsi_channel)(*(unsigned int *)(ipa_gsb_ctx + 68), v28);
  }
  v30 = ipa_gsb_ctx + 16;
  *(_DWORD *)(ipa_gsb_ctx + 404) = 0;
  mutex_unlock(v30);
  mutex_unlock(ipa_gsb_ctx + 48LL * v3 + 136);
  return v24;
}
