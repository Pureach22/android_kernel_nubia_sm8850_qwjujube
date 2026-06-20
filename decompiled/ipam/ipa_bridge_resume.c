__int64 __fastcall ipa_bridge_resume(unsigned int a1)
{
  __int64 v2; // x0
  unsigned int v3; // w21
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned int v7; // w0
  unsigned int v8; // w0
  __int64 v9; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w19
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0

  if ( !ipa_gsb_ctx )
  {
    printk(&unk_3C85BE, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_resume", 1012);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_resume", 1012);
      return 4294967282LL;
    }
    return 4294967282LL;
  }
  if ( a1 >= 5 )
  {
    printk(&unk_3E7C9B, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_resume", 1017, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_resume", 1017, a1);
    }
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v2 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v2, "ipa_gsb %s:%d client hdl: %d\n", "ipa_bridge_resume", 1021, a1);
  }
  v3 = a1;
  mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
  v4 = *(_QWORD *)(ipa_gsb_ctx + 8LL * a1 + 96);
  if ( !v4 )
  {
    printk(&unk_3AB2AC, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_resume", 1025, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_gsb %s:%d fail to find interface, hdl: %d\n", "ipa_bridge_resume", 1025, a1);
    }
    goto LABEL_35;
  }
  if ( (*(_BYTE *)(v4 + 104) & 1) == 0 )
  {
    printk(&unk_3CE2F3, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      v17 = ipa3_get_ipc_logbuf();
      ipc_log_string(v17, "ipa_gsb %s:%d iface is not connected\n", "ipa_bridge_resume", 1031);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v18 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v18, "ipa_gsb %s:%d iface is not connected\n", "ipa_bridge_resume", 1031);
    }
LABEL_35:
    mutex_unlock(ipa_gsb_ctx + 48LL * a1 + 136);
    return 4294967282LL;
  }
  if ( *(_BYTE *)(v4 + 105) == 1 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v5, "ipa_gsb %s:%d iface was already resumed\n", "ipa_bridge_resume", 1037);
    }
LABEL_17:
    mutex_unlock(ipa_gsb_ctx + 48LL * a1 + 136);
    return 0;
  }
  mutex_lock(ipa_gsb_ctx + 16);
  v6 = ipa_gsb_ctx;
  if ( *(_DWORD *)(ipa_gsb_ctx + 92) )
  {
LABEL_14:
    *(_BYTE *)(*(_QWORD *)(v6 + 8LL * a1 + 96) + 105LL) = 1;
    ++*(_DWORD *)(v6 + 92);
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v9,
        "ipa_gsb %s:%d num resumed iface: %d\n",
        "ipa_bridge_resume",
        1067,
        *(_DWORD *)(ipa_gsb_ctx + 92));
    }
    mutex_unlock(ipa_gsb_ctx + 16);
    goto LABEL_17;
  }
  v7 = ipa_pm_activate_sync(*(_DWORD *)(ipa_gsb_ctx + 396));
  if ( v7 )
  {
    v19 = v7;
    printk(&unk_3D9AF8, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa_gsb %s:%d fail to activate ipa pm\n", "ipa_bridge_resume", 1046);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v21, "ipa_gsb %s:%d fail to activate ipa pm\n", "ipa_bridge_resume", 1046);
    }
  }
  else
  {
    v8 = ((__int64 (__fastcall *)(_QWORD))ipa3_start_gsi_channel)(*(unsigned int *)(ipa_gsb_ctx + 68));
    if ( !v8 )
    {
      v6 = ipa_gsb_ctx;
      goto LABEL_14;
    }
    v19 = v8;
    printk(&unk_3F97F1, "ipa_bridge_resume");
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(v22, "ipa_gsb %s:%d fail to start con ep %d\n", "ipa_bridge_resume", 1057, v19);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v23, "ipa_gsb %s:%d fail to start con ep %d\n", "ipa_bridge_resume", 1057, v19);
    }
  }
  mutex_unlock(ipa_gsb_ctx + 16);
  mutex_unlock(ipa_gsb_ctx + 48LL * v3 + 136);
  return v19;
}
