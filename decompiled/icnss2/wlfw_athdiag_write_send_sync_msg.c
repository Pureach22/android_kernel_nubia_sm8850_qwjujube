__int64 __fastcall wlfw_athdiag_write_send_sync_msg(__int64 a1, int a2, int a3, unsigned int a4, const void *a5)
{
  __int64 v10; // x2
  int *v11; // x19
  unsigned __int16 *v12; // x20
  unsigned int v13; // w0
  unsigned int v14; // w22
  unsigned int v15; // w0
  const char *v16; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v18; // x27
  _QWORD v20[10]; // [xsp+0h] [xbp-50h] BYREF

  v20[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 1832);
    memset(v20, 0, 72);
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2_qmi: Diag write: state 0x%lx, offset %x, mem_type %x, data_len %u, data %pK\n",
      v10,
      a2,
      a3,
      a4,
      a5);
    v11 = (int *)_kmalloc_cache_noprof(icc_set_bw, 3520, 6156);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
        if ( !v12 )
          break;
        *v11 = a2;
        v11[1] = a3;
        v11[2] = a4;
        if ( a4 < 0x1801 )
        {
          memcpy(v11 + 3, a5, a4);
          v13 = qmi_txn_init(a1 + 624, v20, &wlfw_athdiag_write_resp_msg_v01_ei, v12);
          if ( (v13 & 0x80000000) != 0 )
          {
            v14 = v13;
            v16 = "%sicnss2_qmi: Fail to init txn for Athdiag Write resp %d\n";
            printk("%sicnss2_qmi: Fail to init txn for Athdiag Write resp %d\n", byte_130B32, v13);
          }
          else
          {
            v14 = qmi_send_request(a1 + 624, 0, v20, 49, 6163, &wlfw_athdiag_write_req_msg_v01_ei, v11);
            if ( (v14 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v20);
              v16 = "%sicnss2_qmi: Fail to send Athdiag Write req %d\n";
              printk("%sicnss2_qmi: Fail to send Athdiag Write req %d\n", byte_130B32, v14);
            }
            else
            {
              v15 = qmi_txn_wait(v20, *(unsigned int *)(a1 + 336));
              if ( (v15 & 0x80000000) == 0 )
              {
                if ( *v12 )
                {
                  printk(
                    "%sicnss2_qmi: QMI Athdiag Write request rejected, result:%d error:%d\n",
                    byte_130B32,
                    *v12,
                    v12[1]);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: QMI Athdiag Write request rejected, result:%d error:%d\n",
                    (const char *)&unk_12DBF3,
                    *v12,
                    v12[1]);
                  v14 = -*v12;
                }
                else
                {
                  v14 = 0;
                }
                goto LABEL_10;
              }
              v14 = v15;
              v16 = "%sicnss2_qmi: Athdiag Write resp wait failed with ret %d\n";
              printk("%sicnss2_qmi: Athdiag Write resp wait failed with ret %d\n", byte_130B32, v15);
            }
          }
          ipc_log_string(icnss_ipc_log_context, v16, &unk_12DBF3, v14);
LABEL_10:
          kfree(v12);
          goto LABEL_20;
        }
        _fortify_panic(17, 6144, a4);
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &wlfw_athdiag_write_send_sync_msg__alloc_tag;
        v11 = (int *)_kmalloc_cache_noprof(icc_set_bw, 3520, 6156);
        *(_QWORD *)(StatusReg + 80) = v18;
        if ( !v11 )
          goto LABEL_18;
      }
      v14 = -12;
LABEL_20:
      kfree(v11);
    }
    else
    {
LABEL_18:
      v14 = -12;
    }
  }
  else
  {
    v14 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
