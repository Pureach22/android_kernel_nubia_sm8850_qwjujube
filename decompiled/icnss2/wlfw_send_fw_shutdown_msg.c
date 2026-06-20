__int64 __fastcall wlfw_send_fw_shutdown_msg(__int64 a1)
{
  __int64 v1; // x2
  unsigned int v2; // w21
  __int64 v5; // x22
  _WORD *v6; // x19
  unsigned __int16 *v7; // x20
  unsigned int v8; // w0
  const char *v9; // x22
  _QWORD v10[10]; // [xsp+0h] [xbp-50h] BYREF

  v10[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v2 = -19;
    goto LABEL_5;
  }
  v1 = *(_QWORD *)(a1 + 1832);
  if ( (v1 & 0x2000) == 0 )
  {
    memset(v10, 0, 72);
    printk("%sicnss2_qmi: Sending FW shutdown request, state: 0x%lx\n", byte_13289B, v1);
    v5 = a1;
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Sending FW shutdown request, state: 0x%lx\n",
      (const char *)&unk_12DBF3,
      *(_QWORD *)(a1 + 1832));
    v6 = (_WORD *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
    if ( !v6 )
    {
      v2 = -12;
      goto LABEL_5;
    }
    v7 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
    if ( !v7 )
    {
      v2 = -12;
      goto LABEL_20;
    }
    *v6 = 257;
    v8 = qmi_txn_init(v5 + 624, v10, &wlfw_shutdown_resp_msg_v01_ei, v7);
    if ( (v8 & 0x80000000) != 0 )
    {
      v2 = v8;
      v9 = "%sicnss2_qmi: Fail to init txn for shutdown resp %d\n";
      printk("%sicnss2_qmi: Fail to init txn for shutdown resp %d\n", byte_130B32, v8);
    }
    else
    {
      v2 = qmi_send_request(v5 + 624, 0, v10, 67, 4, &wlfw_shutdown_req_msg_v01_ei, v6);
      if ( (v2 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v10);
        v9 = "%sicnss2_qmi: Fail to send Shutdown req %d\n";
        printk("%sicnss2_qmi: Fail to send Shutdown req %d\n", byte_130B32, v2);
      }
      else
      {
        v2 = qmi_txn_wait(v10, *(unsigned int *)(v5 + 336));
        if ( (v2 & 0x80000000) == 0 )
        {
          if ( *v7 )
          {
            printk("%sicnss2_qmi: QMI FW shutdown request rejected result:%d error:%d\n", byte_130B32, *v7, v7[1]);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2_qmi: QMI FW shutdown request rejected result:%d error:%d\n",
              (const char *)&unk_12DBF3,
              *v7,
              v7[1]);
            v2 = -*v7;
          }
          goto LABEL_13;
        }
        v9 = "%sicnss2_qmi: Shutdown resp wait failed with ret %d\n";
        printk("%sicnss2_qmi: Shutdown resp wait failed with ret %d\n", byte_130B32, v2);
      }
    }
    ipc_log_string(icnss_ipc_log_context, v9, &unk_12DBF3, v2);
LABEL_13:
    kfree(v7);
LABEL_20:
    kfree(v6);
    goto LABEL_5;
  }
  v2 = -22;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v2;
}
