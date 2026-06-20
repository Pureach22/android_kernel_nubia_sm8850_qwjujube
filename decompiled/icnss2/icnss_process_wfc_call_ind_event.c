__int64 __fastcall icnss_process_wfc_call_ind_event(__int64 a1, char *a2)
{
  __int64 v4; // x20
  unsigned __int16 *v5; // x21
  char v6; // w9
  __int64 v7; // x11
  char v8; // w8
  __int64 v9; // x0
  __int64 v10; // x2
  int v11; // w9
  char v12; // w8
  int v13; // w10
  char v14; // w8
  unsigned int v15; // w0
  unsigned int v16; // w23
  unsigned int v17; // w0
  const char *v18; // x22
  _QWORD v20[10]; // [xsp+0h] [xbp-50h] BYREF

  v20[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v20, 0, 72);
  if ( (*(_QWORD *)(a1 + 1832) & 4) == 0 || (*(_QWORD *)(a1 + 1832) & 0x10000) == 0 )
  {
    printk("%sicnss2_qmi: Drop IMS WFC indication as FW not initialized\n", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Drop IMS WFC indication as FW not initialized\n",
      (const char *)&unk_12DBF3);
    v16 = -22;
    goto LABEL_19;
  }
  v4 = _kmalloc_cache_noprof(wait_for_completion, 3520, 296);
  if ( !v4 )
  {
LABEL_18:
    v16 = -12;
    goto LABEL_19;
  }
  v5 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v5 )
  {
    kfree(v4);
    goto LABEL_18;
  }
  v6 = *a2;
  *(_DWORD *)v4 = 1;
  v7 = *((_QWORD *)a2 + 1);
  *(_BYTE *)(v4 + 260) = 1;
  v8 = a2[1];
  v9 = icnss_ipc_log_context;
  *(_BYTE *)(v4 + 4) = v6;
  v10 = *(_QWORD *)(a1 + 1832);
  *(_BYTE *)(v4 + 261) = v6;
  v11 = *(_DWORD *)(a2 + 2);
  *(_BYTE *)(v4 + 262) = v8;
  v12 = a2[16];
  *(_DWORD *)(v4 + 263) = v11;
  LOWORD(v11) = *((_WORD *)a2 + 9);
  v13 = *((_DWORD *)a2 + 6);
  *(_BYTE *)(v4 + 280) = v12;
  v14 = a2[20];
  *(_QWORD *)(v4 + 272) = v7;
  *(_WORD *)(v4 + 282) = v11;
  *(_BYTE *)(v4 + 284) = v14;
  *(_DWORD *)(v4 + 288) = v13;
  ipc_log_string(v9, "icnss2_qmi: CNSS->FW: WFC_CALL_REQ: state: 0x%lx\n", v10);
  v15 = qmi_txn_init(a1 + 624, v20, &wlfw_wfc_call_status_resp_msg_v01_ei, v5);
  if ( (v15 & 0x80000000) != 0 )
  {
    v16 = v15;
    v18 = "%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Txn Init: Err %d\n";
    printk("%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Txn Init: Err %d\n", byte_130B32, v15);
  }
  else
  {
    v16 = qmi_send_request(a1 + 624, 0, v20, 73, 296, &wlfw_wfc_call_status_req_msg_v01_ei, v4);
    if ( (v16 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v20);
      v18 = "%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Send Err: %d\n";
      printk("%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Send Err: %d\n", byte_130B32, v16);
    }
    else
    {
      v17 = qmi_txn_wait(v20, *(unsigned int *)(a1 + 336));
      if ( (v17 & 0x80000000) == 0 )
      {
        if ( *v5 )
        {
          printk("%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n", byte_130B32, *v5, v5[1]);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n",
            (const char *)&unk_12DBF3,
            *v5,
            v5[1]);
          v16 = -*v5;
        }
        else
        {
          v16 = 0;
        }
        goto LABEL_10;
      }
      v16 = v17;
      v18 = "%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: QMI Wait Err: %d\n";
      printk("%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: QMI Wait Err: %d\n", byte_130B32, v17);
    }
  }
  ipc_log_string(icnss_ipc_log_context, v18, &unk_12DBF3, v16);
LABEL_10:
  kfree(v4);
  kfree(v5);
LABEL_19:
  kfree(a2);
  _ReadStatusReg(SP_EL0);
  return v16;
}
