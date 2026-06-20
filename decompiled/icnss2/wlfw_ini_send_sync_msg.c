__int64 __fastcall wlfw_ini_send_sync_msg(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x2
  _BYTE *v5; // x20
  unsigned __int16 *v6; // x21
  int v7; // w9
  unsigned int v8; // w0
  unsigned int v9; // w22
  unsigned int v10; // w0
  const char *v11; // x23
  _QWORD v13[10]; // [xsp+0h] [xbp-50h] BYREF

  v13[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v9 = -19;
    goto LABEL_18;
  }
  v4 = *(_QWORD *)(a1 + 1832);
  memset(v13, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending ini sync request, state: 0x%lx, fw_log_mode: %d\n", v4, a2);
  v5 = (_BYTE *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
  if ( !v5 )
  {
LABEL_17:
    v9 = -12;
    goto LABEL_18;
  }
  v6 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v6 )
  {
    kfree(v5);
    goto LABEL_17;
  }
  v7 = *(_DWORD *)(a1 + 2644);
  *v5 = 1;
  v5[1] = a2;
  *(_DWORD *)(a1 + 2644) = v7 + 1;
  v8 = qmi_txn_init(a1 + 624, v13, &wlfw_ini_resp_msg_v01_ei, v6);
  if ( (v8 & 0x80000000) != 0 )
  {
    v9 = v8;
    v11 = "%sicnss2_qmi: fatal: Fail to init txn for INI resp %d\n";
    printk("%sicnss2_qmi: fatal: Fail to init txn for INI resp %d\n", byte_130B32, v8);
LABEL_13:
    ipc_log_string(icnss_ipc_log_context, v11, &unk_12DBF3, v9);
LABEL_15:
    kfree(v6);
    kfree(v5);
    ++*(_DWORD *)(a1 + 2652);
    goto LABEL_18;
  }
  v9 = qmi_send_request(a1 + 624, 0, v13, 47, 4, &wlfw_ini_req_msg_v01_ei, v5);
  if ( (v9 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v13);
    v11 = "%sicnss2_qmi: fatal: Fail to send INI req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send INI req %d\n", byte_130B32, v9);
    goto LABEL_13;
  }
  v10 = qmi_txn_wait(v13, *(unsigned int *)(a1 + 336));
  if ( (v10 & 0x80000000) != 0 )
  {
    v9 = v10;
    v11 = "%sicnss2_qmi: fatal: INI resp wait failed with ret %d\n";
    printk("%sicnss2_qmi: fatal: INI resp wait failed with ret %d\n", byte_130B32, v10);
    goto LABEL_13;
  }
  if ( *v6 )
  {
    printk("%sicnss2_qmi: fatal: QMI INI request rejected, result:%d error:%d\n", byte_130B32, *v6, v6[1]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: fatal: QMI INI request rejected, result:%d error:%d\n",
      (const char *)&unk_12DBF3,
      *v6,
      v6[1]);
    v9 = -*v6;
    goto LABEL_15;
  }
  ++*(_DWORD *)(a1 + 2648);
  kfree(v6);
  kfree(v5);
  v9 = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v9;
}
