__int64 __fastcall wlfw_dynamic_feature_mask_send_sync_msg(__int64 a1, __int64 a2)
{
  __int64 v3; // x3
  unsigned int v4; // w22
  __int64 v6; // x19
  unsigned __int16 *v7; // x20
  unsigned int v8; // w0
  const char *v9; // x21
  _QWORD v11[10]; // [xsp+0h] [xbp-50h] BYREF

  v11[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v4 = -19;
    goto LABEL_22;
  }
  memset(v11, 0, 72);
  v3 = *(_QWORD *)(a1 + 1832);
  if ( (v3 & 1) == 0 )
  {
    printk("%sicnss2_qmi: Invalid state for dynamic feature: 0x%lx\n", byte_130B32, v3);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Invalid state for dynamic feature: 0x%lx\n",
      (const char *)&unk_12DBF3,
      *(_QWORD *)(a1 + 1832));
    v4 = -22;
    goto LABEL_22;
  }
  if ( (*(_QWORD *)(a1 + 328) & 0x40) != 0 )
  {
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2_qmi: Sending dynamic feature mask request, val 0x%llx, state: 0x%lx\n",
      a2,
      v3);
    v6 = _kmalloc_cache_noprof(_init_swait_queue_head, 3520, 16);
    if ( v6 )
    {
      v7 = (unsigned __int16 *)_kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 32);
      if ( v7 )
      {
        *(_BYTE *)v6 = 1;
        *(_QWORD *)(v6 + 8) = a2;
        v8 = qmi_txn_init(a1 + 624, v11, &wlfw_dynamic_feature_mask_resp_msg_v01_ei, v7);
        if ( (v8 & 0x80000000) != 0 )
        {
          v4 = v8;
          v9 = "%sicnss2_qmi: Fail to init txn for Dynamic Feature Mask resp %d\n";
          printk("%sicnss2_qmi: Fail to init txn for Dynamic Feature Mask resp %d\n", byte_130B32, v8);
        }
        else
        {
          v4 = qmi_send_request(a1 + 624, 0, v11, 59, 11, &wlfw_dynamic_feature_mask_req_msg_v01_ei, v6);
          if ( (v4 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v11);
            v9 = "%sicnss2_qmi: Fail to send Dynamic Feature Mask req %d\n";
            printk("%sicnss2_qmi: Fail to send Dynamic Feature Mask req %d\n", byte_130B32, v4);
          }
          else
          {
            v4 = qmi_txn_wait(v11, *(unsigned int *)(a1 + 336));
            if ( (v4 & 0x80000000) == 0 )
            {
              if ( *v7 )
              {
                printk(
                  "%sicnss2_qmi: QMI Dynamic Feature Mask request rejected, result:%d error:%d\n",
                  byte_130B32,
                  *v7,
                  v7[1]);
                ipc_log_string(
                  icnss_ipc_log_context,
                  "%sicnss2_qmi: QMI Dynamic Feature Mask request rejected, result:%d error:%d\n",
                  (const char *)&unk_12DBF3,
                  *v7,
                  v7[1]);
                v4 = -*v7;
              }
              else
              {
                ipc_log_string(
                  icnss_ipc_log_context,
                  "icnss2_qmi: prev_mask_valid %u, prev_mask 0x%llx, curr_maks_valid %u, curr_mask 0x%llx\n",
                  *((unsigned __int8 *)v7 + 4),
                  *((_QWORD *)v7 + 1),
                  *((unsigned __int8 *)v7 + 16),
                  *((_QWORD *)v7 + 3));
              }
              goto LABEL_13;
            }
            v9 = "%sicnss2_qmi: Dynamic Feature Mask resp wait failed with ret %d\n";
            printk("%sicnss2_qmi: Dynamic Feature Mask resp wait failed with ret %d\n", byte_130B32, v4);
          }
        }
        ipc_log_string(icnss_ipc_log_context, v9, &unk_12DBF3, v4);
LABEL_13:
        kfree(v7);
        kfree(v6);
        goto LABEL_22;
      }
      kfree(v6);
    }
    v4 = -12;
    goto LABEL_22;
  }
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: FW rejuvenate is disabled from quirks\n");
  v4 = 0;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v4;
}
