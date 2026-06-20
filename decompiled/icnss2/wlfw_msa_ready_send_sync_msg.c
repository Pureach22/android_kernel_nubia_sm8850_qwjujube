__int64 __fastcall wlfw_msa_ready_send_sync_msg(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x20
  unsigned __int16 *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w22
  unsigned int v7; // w0
  const char *v8; // x23
  _QWORD v10[10]; // [xsp+0h] [xbp-50h] BYREF

  v10[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v6 = -19;
    goto LABEL_18;
  }
  v2 = *(_QWORD *)(a1 + 1832);
  memset(v10, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending MSA ready request message, state: 0x%lx\n", v2);
  v3 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 1);
  if ( !v3 )
  {
LABEL_17:
    v6 = -12;
    goto LABEL_18;
  }
  v4 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v4 )
  {
    kfree(v3);
    goto LABEL_17;
  }
  ++*(_DWORD *)(a1 + 2588);
  v5 = qmi_txn_init(a1 + 624, v10, &wlfw_msa_ready_resp_msg_v01_ei, v4);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    v8 = "%sicnss2_qmi: fatal: Fail to init txn for MSA Mem Ready resp %d\n";
    printk("%sicnss2_qmi: fatal: Fail to init txn for MSA Mem Ready resp %d\n", byte_130B32, v5);
LABEL_13:
    ipc_log_string(icnss_ipc_log_context, v8, &unk_12DBF3, v6);
LABEL_15:
    kfree(v4);
    kfree(v3);
    ++*(_DWORD *)(a1 + 2596);
    goto LABEL_18;
  }
  v6 = qmi_send_request(a1 + 624, 0, v10, 46, 0, &wlfw_msa_ready_req_msg_v01_ei, v3);
  if ( (v6 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v10);
    v8 = "%sicnss2_qmi: fatal: Fail to send MSA Mem Ready req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send MSA Mem Ready req %d\n", byte_130B32, v6);
    goto LABEL_13;
  }
  v7 = qmi_txn_wait(v10, *(unsigned int *)(a1 + 336));
  if ( (v7 & 0x80000000) != 0 )
  {
    v6 = v7;
    v8 = "%sicnss2_qmi: fatal: MSA Mem Ready resp wait failed with ret %d\n";
    printk("%sicnss2_qmi: fatal: MSA Mem Ready resp wait failed with ret %d\n", byte_130B32, v7);
    goto LABEL_13;
  }
  if ( *v4 )
  {
    printk("%sicnss2_qmi: fatal: QMI MSA Mem Ready request rejected, result:%d error:%d\n", byte_130B32, *v4, v4[1]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: fatal: QMI MSA Mem Ready request rejected, result:%d error:%d\n",
      (const char *)&unk_12DBF3,
      *v4,
      v4[1]);
    v6 = -*v4;
    goto LABEL_15;
  }
  ++*(_DWORD *)(a1 + 2592);
  kfree(v4);
  kfree(v3);
  v6 = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v6;
}
