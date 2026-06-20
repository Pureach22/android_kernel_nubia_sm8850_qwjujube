__int64 __fastcall cnss_wlfw_cal_report_req_send_sync(__int64 a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x21
  const char *v6; // x1
  unsigned int v7; // w0
  __int64 v8; // x7
  unsigned int v9; // w19
  __int64 v10; // x0
  const char *v11; // x1
  __int64 v12; // x0
  const char *v13; // x1
  const char *v14; // x5
  _QWORD v16[9]; // [xsp+0h] [xbp-80h] BYREF
  int v17; // [xsp+4Ch] [xbp-34h]
  _QWORD v18[3]; // [xsp+50h] [xbp-30h] BYREF
  __int64 v19; // [xsp+68h] [xbp-18h]
  __int64 v20; // [xsp+70h] [xbp-10h]
  __int64 v21; // [xsp+78h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v21 = *(_QWORD *)(StatusReg + 1808);
  v19 = 0;
  memset(v18, 0, sizeof(v18));
  v17 = 0;
  memset(v16, 0, sizeof(v16));
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v6 = "soft_irq";
  }
  else
  {
    v6 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "cnss_wlfw_cal_report_req_send_sync",
    7u,
    7u,
    "Sending cal file report request. File size: %d, state: 0x%lx\n",
    a2,
    *(_QWORD *)(a1 + 552),
    v16[0]);
  BYTE4(v19) = 1;
  v20 = a2;
  v7 = qmi_txn_init(a1 + 856, v16, &wlfw_cal_report_resp_msg_v01_ei);
  if ( (v7 & 0x80000000) != 0 )
  {
    v9 = v7;
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v3 + 2320);
    }
    v14 = "Failed to initialize txn for Cal Report request, err: %d\n";
    goto LABEL_34;
  }
  v9 = qmi_send_request(a1 + 856, 0, v16, 38, 43, &wlfw_cal_report_req_msg_v01_ei, v18);
  if ( (v9 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v16);
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v3 + 2320);
    }
    v14 = "Failed to send Cal Report request, err: %d\n";
    goto LABEL_34;
  }
  v10 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
  v9 = qmi_txn_wait(v16, v10);
  if ( (v9 & 0x80000000) != 0 )
  {
    v12 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v3 + 2320);
    }
    v14 = "Failed to wait for response of Cal Report request, err: %d\n";
LABEL_34:
    cnss_debug_ipc_log_print(v12, v13, "cnss_wlfw_cal_report_req_send_sync", 3u, 3u, v14, v9, v8, v16[0]);
    goto LABEL_35;
  }
  if ( (_WORD)v17 )
  {
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(v3 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_wlfw_cal_report_req_send_sync",
      3u,
      3u,
      "Cal Report request failed, result: %d, err: %d\n",
      (unsigned __int16)v17,
      HIWORD(v17),
      v16[0]);
    v9 = -(unsigned __int16)v17;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return v9;
}
