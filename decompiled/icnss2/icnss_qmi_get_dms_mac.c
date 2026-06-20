__int64 __fastcall icnss_qmi_get_dms_mac(__int64 a1)
{
  unsigned int v1; // w19
  unsigned int v3; // w0
  const char *v4; // x20
  __int64 v6; // x21
  __int16 v7; // w9
  int v8; // w10
  _DWORD *v9; // x20
  _QWORD v10[9]; // [xsp+0h] [xbp-70h] BYREF
  int v11; // [xsp+4Ch] [xbp-24h] BYREF
  __int64 v12; // [xsp+50h] [xbp-20h] BYREF
  __int64 v13; // [xsp+58h] [xbp-18h]
  int v14; // [xsp+60h] [xbp-10h]
  __int64 v15; // [xsp+68h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v10, 0, sizeof(v10));
  if ( (*(_QWORD *)(a1 + 1832) & 0x400000) == 0 )
  {
    printk("%sicnss2_qmi: DMS QMI connection not established\n", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: DMS QMI connection not established\n",
      (const char *)&unk_12DBF3);
    v1 = -11;
    goto LABEL_10;
  }
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Requesting DMS MAC address");
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v3 = qmi_txn_init(a1 + 928, v10, &dms_get_mac_address_resp_msg_v01_ei, &v12);
  if ( (v3 & 0x80000000) != 0 )
  {
    v1 = v3;
    v4 = "%sicnss2_qmi: Failed to initialize txn for dms, err: %d\n";
    printk("%sicnss2_qmi: Failed to initialize txn for dms, err: %d\n", byte_130B32, v3);
LABEL_9:
    ipc_log_string(icnss_ipc_log_context, v4, &unk_12DBF3, v1);
    goto LABEL_10;
  }
  v11 = 0;
  v1 = qmi_send_request(a1 + 928, 0, v10, 92, 7, &dms_get_mac_address_req_msg_v01_ei, &v11);
  if ( (v1 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v10);
    v4 = "%sicnss2_qmi: Failed to send QMI_DMS_GET_MAC_ADDRESS_REQ_V01, err: %d\n";
    printk("%sicnss2_qmi: Failed to send QMI_DMS_GET_MAC_ADDRESS_REQ_V01, err: %d\n", byte_130B32, v1);
    goto LABEL_9;
  }
  v1 = qmi_txn_wait(v10, *(unsigned int *)(a1 + 336));
  if ( (v1 & 0x80000000) != 0 )
  {
    v4 = "%sicnss2_qmi: Failed to wait for QMI_DMS_GET_MAC_ADDRESS_RESP_V01, err: %d\n";
    printk("%sicnss2_qmi: Failed to wait for QMI_DMS_GET_MAC_ADDRESS_RESP_V01, err: %d\n", byte_130B32, v1);
    goto LABEL_9;
  }
  v6 = a1 + 4096;
  if ( (_WORD)v12 )
  {
    if ( WORD1(v12) == 16 )
    {
      printk("%sicnss2_qmi: NV MAC address is not provisioned", byte_130B32);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: NV MAC address is not provisioned",
        (const char *)&unk_12DBF3);
      *(_BYTE *)(a1 + 5649) = 1;
    }
    else
    {
      printk(
        "%sicnss2_qmi: QMI_DMS_GET_MAC_ADDRESS_REQ_V01 failed, result: %d, err: %d\n",
        byte_130B32,
        (unsigned __int16)v12,
        WORD1(v12));
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: QMI_DMS_GET_MAC_ADDRESS_REQ_V01 failed, result: %d, err: %d\n",
        (const char *)&unk_12DBF3,
        (unsigned __int16)v12,
        WORD1(v12));
    }
    v1 = -(unsigned __int16)v12;
  }
  else if ( BYTE4(v12) && (_DWORD)v13 == 6 )
  {
    v7 = v14;
    v8 = HIDWORD(v13);
    *(_BYTE *)(a1 + 5648) = 1;
    v9 = (_DWORD *)(a1 + 5650);
    *(_WORD *)(v6 + 1558) = v7;
    *v9 = v8;
    printk("%sicnss2_qmi: Received DMS MAC: [%pM]\n", byte_13289B, v9);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Received DMS MAC: [%pM]\n", (const char *)&unk_12DBF3, v9);
  }
  else
  {
    printk("%sicnss2_qmi: Invalid MAC address received from DMS\n", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Invalid MAC address received from DMS\n",
      (const char *)&unk_12DBF3);
    *(_BYTE *)(a1 + 5648) = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return v1;
}
