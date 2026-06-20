__int64 __fastcall icnss_wlfw_wlan_mac_req_send_sync(__int64 a1, _WORD *a2, int a3)
{
  __int64 result; // x0
  int v6; // w0
  __int16 v7; // w9
  unsigned int v8; // w0
  const char *v9; // x19
  unsigned int v10; // w20
  __int64 v11; // x0
  unsigned int v12; // w19
  _QWORD v13[9]; // [xsp+0h] [xbp-60h] BYREF
  int v14; // [xsp+4Ch] [xbp-14h] BYREF
  char v15; // [xsp+50h] [xbp-10h] BYREF
  int v16; // [xsp+51h] [xbp-Fh]
  __int16 v17; // [xsp+55h] [xbp-Bh]
  __int64 v18; // [xsp+58h] [xbp-8h]

  result = 4294967274LL;
  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  if ( !a1 || !a2 || a3 != 6 )
    goto LABEL_9;
  memset(v13, 0, sizeof(v13));
  v6 = qmi_txn_init(a1 + 624, v13, &wlfw_mac_addr_resp_msg_v01_ei, &v14);
  if ( v6 < 0 )
  {
    v9 = "%sicnss2_qmi: Failed to initialize txn for mac req, err: %d\n";
    v10 = v6;
    printk("%sicnss2_qmi: Failed to initialize txn for mac req, err: %d\n", byte_130B32, v6);
    v11 = icnss_ipc_log_context;
LABEL_13:
    ipc_log_string(v11, v9, &unk_12DBF3, v10);
    goto LABEL_14;
  }
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: Sending WLAN mac req [%pM], state: 0x%lx\n",
    a2,
    *(_QWORD *)(a1 + 1832));
  v7 = a2[2];
  v16 = *(_DWORD *)a2;
  v17 = v7;
  v15 = 1;
  v8 = qmi_send_request(a1 + 624, 0, v13, 51, 9, &wlfw_mac_addr_req_msg_v01_ei, &v15);
  if ( (v8 & 0x80000000) != 0 )
  {
    v12 = v8;
    qmi_txn_cancel(v13);
    printk("%sicnss2_qmi: Failed to send mac req, err: %d\n", byte_130B32, v12);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Failed to send mac req, err: %d\n", &unk_12DBF3, v12);
LABEL_14:
    result = 4294967291LL;
    goto LABEL_9;
  }
  result = qmi_txn_wait(v13, *(unsigned int *)(a1 + 336));
  if ( (result & 0x80000000) != 0 )
  {
    v9 = "%sicnss2_qmi: Failed to wait for resp of mac req, err: %d\n";
    v10 = result;
    printk("%sicnss2_qmi: Failed to wait for resp of mac req, err: %d\n", byte_130B32, result);
    v11 = icnss_ipc_log_context;
    goto LABEL_13;
  }
  if ( (_WORD)v14 )
  {
    printk("%sicnss2_qmi: WLAN mac req failed, result: %d\n", byte_130B32, (unsigned __int16)v14);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: WLAN mac req failed, result: %d\n",
      (const char *)&unk_12DBF3,
      (unsigned __int16)v14);
    result = (unsigned int)-(unsigned __int16)v14;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
