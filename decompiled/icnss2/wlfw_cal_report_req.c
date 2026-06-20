__int64 __fastcall wlfw_cal_report_req(__int64 a1)
{
  __int64 v1; // x2
  unsigned int v2; // w19
  __int64 v5; // x22
  _DWORD *v6; // x19
  unsigned __int16 *v7; // x20
  unsigned int v8; // w0
  unsigned int v9; // w0
  const char *v10; // x20
  _QWORD v11[10]; // [xsp+0h] [xbp-50h] BYREF

  v11[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v2 = -19;
    goto LABEL_5;
  }
  v1 = *(_QWORD *)(a1 + 1832);
  if ( (v1 & 0x2000) != 0 )
  {
    v2 = -22;
    goto LABEL_5;
  }
  memset(v11, 0, 72);
  printk("%sicnss2_qmi: Sending cal report request, state: 0x%lx\n", byte_13289B, v1);
  v5 = a1;
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2_qmi: Sending cal report request, state: 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(a1 + 1832));
  v6 = (_DWORD *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 40);
  if ( !v6 )
  {
    v2 = -12;
    goto LABEL_5;
  }
  v7 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v7 )
  {
    kfree(v6);
    v2 = -12;
    goto LABEL_5;
  }
  *v6 = 0;
  v8 = qmi_txn_init(v5 + 624, v11, &wlfw_cal_report_resp_msg_v01_ei, v7);
  if ( (v8 & 0x80000000) != 0 )
  {
    v10 = "%sicnss2_qmi: fatal: Fail to init txn for cal report req %d\n";
LABEL_16:
    v2 = v8;
    printk(v10, byte_130B32, v8);
    goto LABEL_17;
  }
  v9 = qmi_send_request(v5 + 624, 0, v11, 38, 43, &wlfw_cal_report_req_msg_v01_ei, v6);
  if ( (v9 & 0x80000000) != 0 )
  {
    v2 = v9;
    qmi_txn_cancel(v11);
    v10 = "%sicnss2_qmi: fatal: Fail to send cal report req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send cal report req %d\n", byte_130B32, v2);
LABEL_17:
    ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3, v2);
    goto LABEL_5;
  }
  v8 = qmi_txn_wait(v11, *(unsigned int *)(v5 + 336));
  if ( (v8 & 0x80000000) != 0 )
  {
    v10 = "%sicnss2_qmi: fatal: Cal report wait failed with ret %d\n";
    goto LABEL_16;
  }
  if ( *v7 )
  {
    printk("%sicnss2_qmi: fatal: QMI cal report request rejected, result:%d error:%d\n", byte_130B32, *v7, v7[1]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: fatal: QMI cal report request rejected, result:%d error:%d\n",
      (const char *)&unk_12DBF3,
      *v7,
      v7[1]);
    v2 = -*v7;
  }
  else
  {
    kfree(v7);
    kfree(v6);
    v2 = 0;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v2;
}
