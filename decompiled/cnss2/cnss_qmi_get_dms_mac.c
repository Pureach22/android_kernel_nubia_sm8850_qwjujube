__int64 __fastcall cnss_qmi_get_dms_mac(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x8
  unsigned __int64 StatusReg; // x21
  int v11; // w8
  const char *v12; // x1
  const char *v13; // x1
  unsigned int v14; // w20
  unsigned int v15; // w0
  __int64 v16; // x7
  __int64 v17; // x0
  const char *v18; // x1
  __int64 v19; // x0
  const char *v20; // x1
  const char *v21; // x5
  int v22; // w9
  __int16 v23; // w10
  __int64 v24; // x0
  const char *v25; // x1
  const char *v27; // x1
  _QWORD v28[9]; // [xsp+0h] [xbp-70h] BYREF
  int v29; // [xsp+4Ch] [xbp-24h] BYREF
  __int64 v30; // [xsp+50h] [xbp-20h]
  __int64 v31; // [xsp+58h] [xbp-18h]
  int v32; // [xsp+60h] [xbp-10h]
  __int64 v33; // [xsp+68h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  StatusReg = _ReadStatusReg(SP_EL0);
  v33 = v9;
  memset(v28, 0, sizeof(v28));
  v11 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( (*(_QWORD *)(a1 + 552) & 0x100000) == 0 )
  {
    if ( v11 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_qmi_get_dms_mac",
      3u,
      3u,
      "DMS QMI connection not established\n",
      a7,
      a8,
      v28[0]);
    v14 = -22;
    goto LABEL_46;
  }
  if ( v11 )
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
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "cnss_qmi_get_dms_mac",
    7u,
    7u,
    "Requesting DMS MAC address",
    a7,
    a8,
    v28[0]);
  v32 = 0;
  v30 = 0;
  v31 = 0;
  v15 = qmi_txn_init(a1 + 1160, v28, &dms_get_mac_address_resp_msg_v01_ei);
  if ( (v15 & 0x80000000) != 0 )
  {
    v14 = v15;
    v19 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(StatusReg + 2320);
    }
    v21 = "Failed to initialize txn for dms, err: %d\n";
    goto LABEL_45;
  }
  v29 = 0;
  v14 = qmi_send_request(a1 + 1160, 0, v28, 92, 7, &dms_get_mac_address_req_msg_v01_ei, &v29);
  if ( (v14 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v28);
    v19 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(StatusReg + 2320);
    }
    v21 = "Failed to send QMI_DMS_GET_MAC_ADDRESS_REQ_V01, err: %d\n";
    goto LABEL_45;
  }
  v17 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
  v14 = qmi_txn_wait(v28, v17);
  if ( (v14 & 0x80000000) != 0 )
  {
    v19 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(StatusReg + 2320);
    }
    v21 = "Failed to wait for QMI_DMS_GET_MAC_ADDRESS_RESP_V01, err: %d\n";
LABEL_45:
    cnss_debug_ipc_log_print(v19, v20, "cnss_qmi_get_dms_mac", 3u, 3u, v21, v14, v16, v28[0]);
    goto LABEL_46;
  }
  if ( (_WORD)v30 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v18 = "soft_irq";
    }
    else
    {
      v18 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_qmi_get_dms_mac",
      3u,
      3u,
      "QMI_DMS_GET_MAC_ADDRESS_REQ_V01 failed, result: %d, err: %d\n",
      (unsigned __int16)v30,
      WORD1(v30),
      v28[0]);
    v14 = -(unsigned __int16)v30;
  }
  else if ( BYTE4(v30) && (_DWORD)v31 == 6 )
  {
    v22 = HIDWORD(v31);
    v23 = v32;
    *(_DWORD *)(a1 + 7556) = 1;
    v24 = cnss_ipc_log_context;
    *(_DWORD *)(a1 + 7560) = v22;
    *(_WORD *)(a1 + 7564) = v23;
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
      v24,
      v25,
      "cnss_qmi_get_dms_mac",
      6u,
      6u,
      "Received DMS MAC: [%pM]\n",
      a1 + 7560,
      v16,
      v28[0]);
    v14 = 0;
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v27 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v27 = "soft_irq";
    }
    else
    {
      v27 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v27,
      "cnss_qmi_get_dms_mac",
      3u,
      3u,
      "Invalid MAC address received from DMS\n",
      (unsigned __int16)v30,
      v16,
      v28[0]);
    *(_DWORD *)(a1 + 7556) = 0;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v14;
}
