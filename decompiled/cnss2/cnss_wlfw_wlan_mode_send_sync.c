__int64 __fastcall cnss_wlfw_wlan_mode_send_sync(__int64 a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x24
  const char *v5; // x1
  const char *v6; // x6
  unsigned int v7; // w23
  __int64 v8; // x6
  __int64 v9; // x7
  int v10; // w26
  __int64 v11; // x20
  _WORD *v12; // x21
  unsigned int v13; // w0
  __int64 v14; // x0
  unsigned int v15; // w0
  const char *v16; // x1
  const char *v17; // x6
  __int64 v18; // x0
  const char *v19; // x1
  const char *v20; // x6
  const char *v21; // x1
  const char *v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  const char *v25; // x1
  char v27; // [xsp+0h] [xbp-60h]
  char v28; // [xsp+0h] [xbp-60h]
  _QWORD v29[10]; // [xsp+10h] [xbp-50h] BYREF

  v29[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v7 = -19;
    goto LABEL_88;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  memset(v29, 0, 72);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v5 = "irq";
    if ( (int)a2 <= 3 )
      goto LABEL_4;
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      v5 = "soft_irq";
    else
      v5 = (const char *)(StatusReg + 2320);
    if ( (int)a2 <= 3 )
    {
LABEL_4:
      if ( (int)a2 > 1 )
      {
        if ( a2 == 2 )
          v6 = "EPPING";
        else
          v6 = "WALTEST";
        goto LABEL_27;
      }
      if ( !a2 )
      {
        v6 = "MISSION";
        goto LABEL_27;
      }
      if ( a2 == 1 )
      {
        v6 = "FTM";
LABEL_27:
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v5,
          "cnss_wlfw_wlan_mode_send_sync",
          7u,
          7u,
          "Sending mode message, mode: %s(%d), state: 0x%lx\n",
          (__int64)v6,
          a2,
          *(_QWORD *)(a1 + 552));
        v10 = 0;
        goto LABEL_28;
      }
LABEL_26:
      v6 = "UNKNOWN";
      goto LABEL_27;
    }
  }
  if ( (int)a2 > 5 )
  {
    if ( a2 == 6 )
    {
      v6 = "QVIT";
      goto LABEL_27;
    }
    if ( a2 == 7 )
    {
      v6 = "CALIBRATION";
      goto LABEL_27;
    }
    goto LABEL_26;
  }
  if ( a2 != 4 )
  {
    v6 = "CCPM";
    goto LABEL_27;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v5,
    "cnss_wlfw_wlan_mode_send_sync",
    7u,
    7u,
    "Sending mode message, mode: %s(%d), state: 0x%lx\n",
    (__int64)"OFF",
    4,
    *(_QWORD *)(a1 + 552));
  if ( (*(_QWORD *)(a1 + 552) & 0x200) != 0 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_wlfw_wlan_mode_send_sync",
      7u,
      7u,
      "Recovery is in progress, ignore mode off request\n",
      v8,
      v9,
      v27);
    v7 = 0;
    goto LABEL_88;
  }
  v10 = 1;
LABEL_28:
  v11 = _kmalloc_cache_noprof(of_find_node_opts_by_path, 3520, 20);
  if ( !v11 )
  {
LABEL_87:
    v7 = -12;
    goto LABEL_88;
  }
  v12 = (_WORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( !v12 )
  {
    kfree(v11);
    goto LABEL_87;
  }
  *(_DWORD *)v11 = a2;
  *(_WORD *)(v11 + 4) = 1;
  v13 = qmi_txn_init(a1 + 856, v29, &wlfw_wlan_mode_resp_msg_v01_ei);
  if ( (v13 & 0x80000000) != 0 )
  {
    v7 = v13;
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
      if ( a2 <= 7 )
      {
LABEL_39:
        v20 = (&off_5BF10)[a2];
LABEL_53:
        v22 = "Failed to initialize txn for mode request, mode: %s(%d), err: %d\n";
LABEL_77:
        cnss_debug_ipc_log_print(v18, v19, "cnss_wlfw_wlan_mode_send_sync", 3u, 3u, v22, (__int64)v20, a2, v7);
        goto LABEL_78;
      }
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = (const char *)(StatusReg + 2320);
      if ( a2 <= 7 )
        goto LABEL_39;
    }
    v20 = "UNKNOWN";
    goto LABEL_53;
  }
  v7 = qmi_send_request(a1 + 856, 0, v29, 34, 26, &wlfw_wlan_mode_req_msg_v01_ei, v11);
  if ( (v7 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v29);
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
      if ( a2 <= 7 )
      {
LABEL_42:
        v20 = (&off_5BF10)[a2];
LABEL_60:
        v22 = "Failed to send mode request, mode: %s(%d), err: %d\n";
        goto LABEL_77;
      }
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = (const char *)(StatusReg + 2320);
      if ( a2 <= 7 )
        goto LABEL_42;
    }
    v20 = "UNKNOWN";
    goto LABEL_60;
  }
  v14 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
  v15 = qmi_txn_wait(v29, v14);
  if ( (v15 & 0x80000000) != 0 )
  {
    v7 = v15;
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
      if ( a2 <= 7 )
      {
LABEL_47:
        v20 = (&off_5BF10)[a2];
LABEL_76:
        v22 = "Failed to wait for response of mode request, mode: %s(%d), err: %d\n";
        goto LABEL_77;
      }
    }
    else
    {
      if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        v19 = "soft_irq";
      else
        v19 = (const char *)(StatusReg + 2320);
      if ( a2 <= 7 )
        goto LABEL_47;
    }
    v20 = "UNKNOWN";
    goto LABEL_76;
  }
  if ( !*v12 )
  {
    kfree(v11);
    kfree(v12);
    v7 = 0;
    goto LABEL_88;
  }
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      v16 = "soft_irq";
    else
      v16 = (const char *)(StatusReg + 2320);
    if ( a2 <= 7 )
      goto LABEL_36;
LABEL_65:
    v17 = "UNKNOWN";
    goto LABEL_66;
  }
  v16 = "irq";
  if ( a2 > 7 )
    goto LABEL_65;
LABEL_36:
  v17 = (&off_5BF10)[a2];
LABEL_66:
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v16,
    "cnss_wlfw_wlan_mode_send_sync",
    3u,
    3u,
    "Mode request failed, mode: %s(%d), result: %d, err: %d\n",
    (__int64)v17,
    a2,
    *v12);
  v7 = -(unsigned __int16)*v12;
LABEL_78:
  if ( v10 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v25 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v25 = "soft_irq";
    }
    else
    {
      v25 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v25,
      "cnss_wlfw_wlan_mode_send_sync",
      7u,
      7u,
      "WLFW service is disconnected while sending mode off request\n",
      v23,
      v24,
      v28);
    v7 = 0;
  }
  kfree(v11);
  kfree(v12);
LABEL_88:
  _ReadStatusReg(SP_EL0);
  return v7;
}
