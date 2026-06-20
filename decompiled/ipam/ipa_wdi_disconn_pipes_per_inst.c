__int64 __fastcall ipa_wdi_disconn_pipes_per_inst(unsigned int a1)
{
  __int64 v2; // x8
  __int64 v3; // x22
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  _QWORD *v7; // x0
  __int64 v8; // x13
  unsigned int v9; // w20
  __int64 v10; // x0
  unsigned int ep_mapping; // w19
  __int64 v12; // x0
  unsigned int v13; // w20
  unsigned int v14; // w2
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  unsigned int v29; // w19
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0

  if ( a1 >= 2 )
  {
    printk(&unk_3F6766, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_disconn_pipes_per_inst", 2110, a1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_disconn_pipes_per_inst", 2110, a1);
    }
    return 4294967282LL;
  }
  v2 = ipa_wdi_ctx_list[a1];
  if ( !v2 )
  {
    printk(&unk_3F0CD4, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v23 = ipa3_get_ipc_logbuf();
      ipc_log_string(v23, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_disconn_pipes_per_inst", 2115);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v24, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_disconn_pipes_per_inst", 2115);
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  v3 = a1;
  if ( a1 == 1 && *(_DWORD *)(v2 + 144) <= 1u )
  {
    printk(&unk_3E2714, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v25,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_disconn_pipes_per_inst",
        2124,
        *(_DWORD *)(qword_204E60 + 144));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v26,
        "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
        "ipa_wdi_disconn_pipes_per_inst",
        2124,
        *(_DWORD *)(qword_204E60 + 144));
      return 0xFFFFFFFFLL;
    }
    return 0xFFFFFFFFLL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_wdi %s:%d Disconnect pipes for hdl %d\n", "ipa_wdi_disconn_pipes_per_inst", 2128, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v5 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v5, "ipa_wdi %s:%d Disconnect pipes for hdl %d\n", "ipa_wdi_disconn_pipes_per_inst", 2128, a1);
  }
  v6 = ipa_wdi_ctx_list[a1];
  if ( !*(_BYTE *)(v6 + 160) )
    goto LABEL_16;
  if ( (unsigned int)ipa_teardown_sys_pipe(*(_DWORD *)(v6 + 164)) )
  {
    v29 = 0;
LABEL_69:
    printk(&unk_3F9E84, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v34 = ipa3_get_ipc_logbuf();
      ipc_log_string(v34, "ipa_wdi %s:%d fail to tear down sys pipe %d\n", "ipa_wdi_disconn_pipes_per_inst", 2132, v29);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v35 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v35, "ipa_wdi %s:%d fail to tear down sys pipe %d\n", "ipa_wdi_disconn_pipes_per_inst", 2132, v29);
    }
    return 4294967282LL;
  }
  v6 = ipa_wdi_ctx_list[a1];
  if ( *(unsigned __int8 *)(v6 + 160) < 2u )
    goto LABEL_16;
  if ( (unsigned int)ipa_teardown_sys_pipe(*(_DWORD *)(v6 + 168)) )
  {
    v29 = 1;
    goto LABEL_69;
  }
  v6 = ipa_wdi_ctx_list[a1];
  if ( *(unsigned __int8 *)(v6 + 160) < 3u )
    goto LABEL_16;
  v7 = (_QWORD *)ipa_teardown_sys_pipe(*(_DWORD *)(v6 + 172));
  if ( (_DWORD)v7 )
  {
    v29 = 2;
    goto LABEL_69;
  }
  v6 = ipa_wdi_ctx_list[a1];
  if ( *(unsigned __int8 *)(v6 + 160) > 3u )
  {
    __break(0x5512u);
    *v7 = v8;
    return ipa_wdi_disable_pipes_per_inst((char *)v7 + 217);
  }
LABEL_16:
  if ( *(_DWORD *)(v6 + 144) < 2u )
  {
    ep_mapping = ipa_get_ep_mapping(10);
    v12 = ipa_get_ep_mapping(11);
  }
  else
  {
    if ( (unsigned int)(*(_DWORD *)(v6 + 184) + 1) >= 2 )
    {
      v9 = 17;
      v10 = 14;
    }
    else
    {
      v9 = 13;
      v10 = 12;
    }
    ep_mapping = ipa_get_ep_mapping(v10);
    v12 = ipa_get_ep_mapping(v9);
    if ( *(_BYTE *)(ipa_wdi_ctx_list[v3] + 161) == 1 )
    {
      v13 = v12;
      v14 = ipa_get_ep_mapping(119);
      v12 = v13;
      goto LABEL_24;
    }
  }
  v14 = -1;
LABEL_24:
  v15 = ipa_wdi_ctx_list[v3];
  if ( *(_DWORD *)(v15 + 144) < 2u )
  {
    if ( (unsigned int)ipa_disconnect_wdi_pipe((_QWORD *)*(unsigned int *)(v15 + 152)) )
    {
      printk(&unk_3B1212, "ipa_wdi_disconn_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v30 = ipa3_get_ipc_logbuf();
        ipc_log_string(v30, "ipa_wdi %s:%d fail to tear down wdi tx pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2162);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v31 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v31, "ipa_wdi %s:%d fail to tear down wdi tx pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2162);
      }
      return 4294967282LL;
    }
    if ( (unsigned int)ipa_disconnect_wdi_pipe((_QWORD *)*(unsigned int *)(ipa_wdi_ctx_list[v3] + 156)) )
    {
      printk(&unk_3EB132, "ipa_wdi_disconn_pipes_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(v32, "ipa_wdi %s:%d fail to tear down wdi rx pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2166);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v33, "ipa_wdi %s:%d fail to tear down wdi rx pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2166);
      }
      return 4294967282LL;
    }
  }
  else if ( (unsigned int)ipa3_disconn_wdi3_pipes(v12, ep_mapping, v14) )
  {
    printk(&unk_3CE677, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_wdi %s:%d fail to tear down wdi pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2157);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_wdi %s:%d fail to tear down wdi pipes\n", "ipa_wdi_disconn_pipes_per_inst", 2157);
    }
    return 4294967282LL;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_wdi_ctx_list[v3] + 176)) )
  {
    printk(&unk_3E8349, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa_wdi %s:%d fail to deregister ipa pm\n", "ipa_wdi_disconn_pipes_per_inst", 2172);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v28, "ipa_wdi %s:%d fail to deregister ipa pm\n", "ipa_wdi_disconn_pipes_per_inst", 2172);
    }
    return 4294967282LL;
  }
  if ( !*((_DWORD *)&opt_dpath_info + 34 * (unsigned int)v3 + 18) )
    return 0;
  result = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(ipa_wdi_ctx_list[v3] + 180));
  if ( (_DWORD)result )
  {
    printk(&unk_3B1242, "ipa_wdi_disconn_pipes_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v19 = ipa3_get_ipc_logbuf();
      ipc_log_string(v19, "ipa_wdi %s:%d fail to deregister ipa pm ctrl\n", "ipa_wdi_disconn_pipes_per_inst", 2178);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v20 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v20, "ipa_wdi %s:%d fail to deregister ipa pm ctrl\n", "ipa_wdi_disconn_pipes_per_inst", 2178);
    }
    return 4294967282LL;
  }
  return result;
}
