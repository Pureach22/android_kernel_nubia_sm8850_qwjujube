__int64 __fastcall icnss_process_twt_cfg_ind_event(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  unsigned __int16 *v5; // x21
  __int64 v6; // x9
  char v7; // w10
  __int64 v8; // x0
  __int16 v9; // w8
  __int64 v10; // x2
  __int16 v11; // w8
  __int16 v12; // w8
  unsigned int v13; // w0
  unsigned int v14; // w23
  unsigned int v15; // w0
  const char *v16; // x22
  _QWORD v18[10]; // [xsp+0h] [xbp-50h] BYREF

  v18[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 72);
  if ( (*(_QWORD *)(a1 + 1832) & 0x80000) == 0 )
  {
    printk("%sicnss2_qmi: Drop FW WFC indication as IMS QMI not connected\n", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Drop FW WFC indication as IMS QMI not connected\n",
      (const char *)&unk_12DBF3);
    v14 = -22;
    goto LABEL_18;
  }
  v4 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 40);
  if ( !v4 )
  {
LABEL_17:
    v14 = -12;
    goto LABEL_18;
  }
  v5 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v5 )
  {
    kfree(v4);
    goto LABEL_17;
  }
  v6 = *(_QWORD *)(a2 + 8);
  v7 = *(_BYTE *)(a2 + 16);
  v8 = icnss_ipc_log_context;
  *(_BYTE *)v4 = *(_BYTE *)a2;
  v9 = *(_WORD *)(a2 + 18);
  *(_QWORD *)(v4 + 8) = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 20);
  v10 = *(_QWORD *)(a1 + 1832);
  *(_WORD *)(v4 + 18) = v9;
  v11 = *(_WORD *)(a2 + 22);
  *(_BYTE *)(v4 + 20) = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 24);
  *(_WORD *)(v4 + 22) = v11;
  v12 = *(_WORD *)(a2 + 26);
  *(_BYTE *)(v4 + 24) = v6;
  LOBYTE(v6) = *(_BYTE *)(a2 + 32);
  *(_WORD *)(v4 + 26) = v12;
  LOBYTE(v12) = *(_BYTE *)(a2 + 33);
  *(_BYTE *)(v4 + 16) = v7;
  *(_BYTE *)(v4 + 32) = v6;
  *(_BYTE *)(v4 + 33) = v12;
  ipc_log_string(v8, "icnss2_qmi: CNSS->IMS: TWT_CFG_REQ: state: 0x%lx\n", v10);
  v13 = qmi_txn_init(a1 + 1232, v18, &ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei, v5);
  if ( (v13 & 0x80000000) != 0 )
  {
    v14 = v13;
    v16 = "%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Txn Init Err: %d\n";
    printk("%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Txn Init Err: %d\n", byte_130B32, v13);
  }
  else
  {
    v14 = qmi_send_request(a1 + 1232, 0, v18, 65, 35, &ims_private_service_wfc_call_twt_config_req_msg_v01_ei, v4);
    if ( (v14 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v18);
      v16 = "%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Send Err: %d\n";
      printk("%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Send Err: %d\n", byte_130B32, v14);
    }
    else
    {
      v15 = qmi_txn_wait(v18, *(unsigned int *)(a1 + 336));
      if ( (v15 & 0x80000000) == 0 )
      {
        if ( *v5 )
        {
          printk("%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: Result: %d Err: %d\n", byte_130B32, *v5, v5[1]);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: Result: %d Err: %d\n",
            (const char *)&unk_12DBF3,
            *v5,
            v5[1]);
          v14 = -*v5;
        }
        else
        {
          v14 = 0;
        }
        goto LABEL_9;
      }
      v14 = v15;
      v16 = "%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: QMI Wait Err: %d\n";
      printk("%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: QMI Wait Err: %d\n", byte_130B32, v15);
    }
  }
  ipc_log_string(icnss_ipc_log_context, v16, &unk_12DBF3, v14);
LABEL_9:
  kfree(v4);
  kfree(v5);
LABEL_18:
  kfree(a2);
  _ReadStatusReg(SP_EL0);
  return v14;
}
