__int64 __fastcall ipa_wdi_disable_pipes_per_inst(unsigned int a1)
{
  __int64 v1; // x8
  unsigned int v2; // w3
  __int64 v3; // x22
  unsigned int v4; // w20
  __int64 v5; // x0
  unsigned int ep_mapping; // w19
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x2
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  _UNKNOWN **v13; // x19
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0

  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_disable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_disable_pipes_per_inst", 2203, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_disable_pipes_per_inst", 2203, a1);
    }
    return 4294967282LL;
  }
  v1 = ipa_wdi_ctx_list[a1];
  if ( !v1 )
  {
    printk(&unk_3F0CD4, "ipa_wdi_disable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v20 = ipa3_get_ipc_logbuf();
      ipc_log_string(v20, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_disable_pipes_per_inst", 2208);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v21 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v21, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_disable_pipes_per_inst", 2208);
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v2 = *(_DWORD *)(v1 + 144);
  v3 = a1;
  if ( a1 == 1 && v2 <= 1 )
  {
    printk(&unk_3E2714, "ipa_wdi_disable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v22 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v22,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_disable_pipes_per_inst",
        2216,
        *(_DWORD *)(ipa_wdi_ctx_list[v3] + 144));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v23,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_disable_pipes_per_inst",
        2216,
        *(_DWORD *)(ipa_wdi_ctx_list[v3] + 144));
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  if ( v2 < 2 )
  {
    ep_mapping = ipa_get_ep_mapping(10);
    v7 = ipa_get_ep_mapping(11);
  }
  else
  {
    if ( (unsigned int)(*(_DWORD *)(v1 + 184) + 1) >= 2 )
    {
      v4 = 17;
      v5 = 14;
    }
    else
    {
      v4 = 13;
      v5 = 12;
    }
    ep_mapping = ipa_get_ep_mapping(v5);
    v7 = ipa_get_ep_mapping(v4);
    if ( *(_BYTE *)(ipa_wdi_ctx_list[v3] + 161) == 1 )
    {
      v8 = v7;
      v9 = (unsigned int)ipa_get_ep_mapping(119);
      v7 = v8;
      goto LABEL_13;
    }
  }
  v9 = 0xFFFFFFFFLL;
LABEL_13:
  v10 = ipa_wdi_ctx_list[v3];
  if ( *(_DWORD *)(v10 + 144) < 2u )
  {
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_suspend_wdi_pipe)(*(unsigned int *)(v10 + 152)) )
    {
      printk(&unk_3EB162, "ipa_wdi_disable_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v26 = ipa3_get_ipc_logbuf();
        ipc_log_string(v26, "ipa_wdi %s:%d fail to suspend wdi tx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2245);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v27 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v27, "ipa_wdi %s:%d fail to suspend wdi tx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2245);
      }
      return 4294967282LL;
    }
    if ( (unsigned int)ipa_disable_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 152)) )
    {
      printk(&unk_3E283A, "ipa_wdi_disable_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v28 = ipa3_get_ipc_logbuf();
        ipc_log_string(v28, "ipa_wdi %s:%d fail to disable wdi tx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2249);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v29, "ipa_wdi %s:%d fail to disable wdi tx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2249);
      }
      return 4294967282LL;
    }
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_suspend_wdi_pipe)(*(unsigned int *)(ipa_wdi_ctx_list[v3]
                                                                                              + 156)) )
    {
      printk(&unk_3B6C04, "ipa_wdi_disable_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v30 = ipa3_get_ipc_logbuf();
        ipc_log_string(v30, "ipa_wdi %s:%d fail to suspend wdi rx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2253);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v31 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v31, "ipa_wdi %s:%d fail to suspend wdi rx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2253);
      }
      return 4294967282LL;
    }
    if ( (unsigned int)ipa_disable_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 156)) )
    {
      printk(&unk_3E2867, "ipa_wdi_disable_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(v32, "ipa_wdi %s:%d fail to disable wdi rx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2257);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v33, "ipa_wdi %s:%d fail to disable wdi rx pipe\n", "ipa_wdi_disable_pipes_per_inst", 2257);
      }
      return 4294967282LL;
    }
LABEL_23:
    v13 = &opt_dpath_info + 17 * (unsigned int)v3;
    if ( *((_DWORD *)v13 + 18) )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_wdi_ctx_list[v3]
                                                                                                  + 180)) )
      {
        printk(&unk_3B9E31, "ipa_wdi_disable_pipes_per_inst");
        if ( ipa3_get_ipc_logbuf() )
        {
          v24 = ipa3_get_ipc_logbuf();
          ipc_log_string(v24, "ipa_wdi %s:%d fail to deactivate ipa pm ctrl\n", "ipa_wdi_disable_pipes_per_inst", 2266);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v25, "ipa_wdi %s:%d fail to deactivate ipa pm ctrl\n", "ipa_wdi_disable_pipes_per_inst", 2266);
        }
        return 4294967282LL;
      }
      *((_DWORD *)v13 + 27) = 0;
    }
    result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_wdi_ctx_list[v3] + 176));
    if ( !(_DWORD)result )
      return result;
    printk(&unk_3A5607, "ipa_wdi_disable_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      ipc_log_string(v15, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_disable_pipes_per_inst", 2274);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v16 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v16, "ipa_wdi %s:%d fail to deactivate ipa pm\n", "ipa_wdi_disable_pipes_per_inst", 2274);
    }
    return 4294967282LL;
  }
  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64))ipa3_disable_wdi3_pipes)(v7, ep_mapping, v9) )
    goto LABEL_23;
  printk(&unk_3B9E06, "ipa_wdi_disable_pipes_per_inst");
  if ( ipa3_get_ipc_logbuf() )
  {
    v11 = ipa3_get_ipc_logbuf();
    ipc_log_string(v11, "ipa_wdi %s:%d fail to disable wdi pipes\n", "ipa_wdi_disable_pipes_per_inst", 2240);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v12 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v12, "ipa_wdi %s:%d fail to disable wdi pipes\n", "ipa_wdi_disable_pipes_per_inst", 2240);
  }
  return 4294967282LL;
}
