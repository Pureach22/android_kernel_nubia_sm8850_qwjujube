__int64 __fastcall cnss_wlfw_wlan_mac_req_send_sync(__int64 a1, __int64 a2, int a3)
{
  __int64 result; // x0
  unsigned int v6; // w0
  __int64 v7; // x7
  unsigned __int64 StatusReg; // x21
  __int64 v9; // x8
  int v10; // w9
  const char *v11; // x1
  __int64 v12; // x6
  const char *v13; // x1
  __int16 v14; // w9
  unsigned int v15; // w20
  __int64 v16; // x0
  const char *v17; // x1
  __int64 v18; // x0
  const char *v19; // x5
  _QWORD v20[9]; // [xsp+0h] [xbp-60h] BYREF
  int v21; // [xsp+4Ch] [xbp-14h]
  char v22; // [xsp+50h] [xbp-10h] BYREF
  int v23; // [xsp+51h] [xbp-Fh]
  __int16 v24; // [xsp+55h] [xbp-Bh]
  __int64 v25; // [xsp+58h] [xbp-8h]

  result = 4294967274LL;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( !a1 || !a2 || a3 != 6 )
    goto LABEL_39;
  memset(v20, 0, sizeof(v20));
  v6 = qmi_txn_init(a1 + 856, v20, &wlfw_mac_addr_resp_msg_v01_ei);
  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = cnss_ipc_log_context;
  v10 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( (v6 & 0x80000000) != 0 )
  {
    v12 = v6;
    if ( v10 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(StatusReg + 2320);
    }
    v19 = "Failed to initialize txn for mac req, err: %d\n";
    goto LABEL_37;
  }
  if ( v10 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_wlfw_wlan_mac_req_send_sync",
    7u,
    7u,
    "Sending WLAN mac req [%pM], state: 0x%lx\n",
    a2,
    *(_QWORD *)(a1 + 552),
    v20[0]);
  v14 = *(_WORD *)(a2 + 4);
  v23 = *(_DWORD *)a2;
  v24 = v14;
  v22 = 1;
  v15 = qmi_send_request(a1 + 856, 0, v20, 51, 9, &wlfw_mac_addr_req_msg_v01_ei, &v22);
  if ( (v15 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v20);
    v18 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(StatusReg + 2320);
    }
    v19 = "Failed to send mac req, err: %d\n";
    v12 = v15;
    goto LABEL_38;
  }
  v16 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
  result = qmi_txn_wait(v20, v16);
  if ( (result & 0x80000000) != 0 )
  {
    v9 = cnss_ipc_log_context;
    v12 = (unsigned int)result;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(StatusReg + 2320);
    }
    v19 = "Failed to wait for resp of mac req, err: %d\n";
LABEL_37:
    v18 = v9;
LABEL_38:
    cnss_debug_ipc_log_print(v18, v13, "cnss_wlfw_wlan_mac_req_send_sync", 3u, 3u, v19, v12, v7, v20[0]);
    result = 4294967291LL;
    goto LABEL_39;
  }
  if ( (_WORD)v21 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v17 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v17 = "soft_irq";
    }
    else
    {
      v17 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v17,
      "cnss_wlfw_wlan_mac_req_send_sync",
      3u,
      3u,
      "WLAN mac req failed, result: %d, err: %d\n",
      (unsigned __int16)v21,
      v7,
      v20[0]);
    result = (unsigned int)-(unsigned __int16)v21;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
