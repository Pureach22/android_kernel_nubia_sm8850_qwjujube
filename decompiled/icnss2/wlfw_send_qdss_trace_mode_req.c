__int64 __fastcall wlfw_send_qdss_trace_mode_req(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x19
  unsigned __int16 *v7; // x20
  __int64 v8; // x0
  int v9; // w9
  int v10; // w5
  unsigned int v11; // w0
  unsigned int v12; // w22
  const char *v13; // x21
  _QWORD v15[10]; // [xsp+0h] [xbp-50h] BYREF

  v15[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    memset(v15, 0, 72);
    v6 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 32);
    if ( v6 )
    {
      v7 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
      if ( !v7 )
      {
        v12 = -12;
        goto LABEL_20;
      }
      v8 = icnss_ipc_log_context;
      v9 = *(_DWORD *)(a1 + 5644) & ~(*(int *)(a1 + 5644) >> 31);
      *(_BYTE *)v6 = 1;
      if ( v9 >= 2 )
        v10 = 2;
      else
        v10 = v9;
      *(_DWORD *)(v6 + 4) = a2;
      *(_BYTE *)(v6 + 8) = 1;
      *(_QWORD *)(v6 + 16) = a3;
      *(_BYTE *)(v6 + 24) = 1;
      *(_DWORD *)(v6 + 28) = v10;
      ipc_log_string(
        v8,
        "icnss2_qmi: %s: mode %u, option %llu, hw_trc_disable_override: %u",
        "wlfw_send_qdss_trace_mode_req",
        a2,
        a3);
      v11 = qmi_txn_init(a1 + 624, v15, &wlfw_qdss_trace_mode_resp_msg_v01_ei, v7);
      if ( (v11 & 0x80000000) != 0 )
      {
        v12 = v11;
        v13 = "%sicnss2_qmi: fatal: Fail to init txn for QDSS Mode resp %d\n";
        printk("%sicnss2_qmi: fatal: Fail to init txn for QDSS Mode resp %d\n", byte_130B32, v11);
      }
      else
      {
        v12 = qmi_send_request(a1 + 624, 0, v15, 69, 25, &wlfw_qdss_trace_mode_req_msg_v01_ei, v6);
        if ( (v12 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v15);
          v13 = "%sicnss2_qmi: fatal: Fail to send QDSS Mode req %d\n";
          printk("%sicnss2_qmi: fatal: Fail to send QDSS Mode req %d\n", byte_130B32, v12);
        }
        else
        {
          v12 = qmi_txn_wait(v15, *(unsigned int *)(a1 + 336));
          if ( (v12 & 0x80000000) == 0 )
          {
            if ( *v7 )
            {
              printk(
                "%sicnss2_qmi: fatal: QMI QDSS Mode request rejected, result:%d error:%d\n",
                byte_130B32,
                *v7,
                v7[1]);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2_qmi: fatal: QMI QDSS Mode request rejected, result:%d error:%d\n",
                (const char *)&unk_12DBF3,
                *v7,
                v7[1]);
              v12 = -*v7;
            }
            goto LABEL_12;
          }
          v13 = "%sicnss2_qmi: fatal: QDSS Mode resp wait failed with rc %d\n";
          printk("%sicnss2_qmi: fatal: QDSS Mode resp wait failed with rc %d\n", byte_130B32, v12);
        }
      }
      ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3, v12);
LABEL_12:
      kfree(v7);
LABEL_20:
      kfree(v6);
      goto LABEL_21;
    }
    v12 = -12;
  }
  else
  {
    v12 = -19;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v12;
}
