__int64 __fastcall wlfw_athdiag_read_send_sync_msg(__int64 a1, int a2, unsigned int a3, unsigned int a4, void *a5)
{
  __int64 v9; // x2
  int *v11; // x19
  unsigned __int16 *v12; // x20
  unsigned int v13; // w0
  unsigned int v14; // w0
  unsigned int v15; // w3
  const char *v16; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v18; // x27
  __int64 (__fastcall *v19)(_QWORD, _QWORD, _QWORD); // x0
  _QWORD v21[10]; // [xsp+0h] [xbp-50h] BYREF

  v21[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 1832);
    memset(v21, 0, 72);
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2_qmi: Diag read: state 0x%lx, offset %x, mem_type %x, data_len %u\n",
      v9,
      a2,
      a3,
      a4);
    v11 = (int *)_kmalloc_cache_noprof(_init_swait_queue_head, 3520, 12);
    if ( v11 )
    {
      while ( 1 )
      {
        v12 = (unsigned __int16 *)_kmalloc_cache_noprof(icc_set_bw, 3520, 6156);
        if ( !v12 )
          break;
        *v11 = a2;
        v11[1] = a3;
        v11[2] = a4;
        v13 = qmi_txn_init(a1 + 624, v21, &wlfw_athdiag_read_resp_msg_v01_ei, v12);
        if ( (v13 & 0x80000000) != 0 )
        {
          a3 = v13;
          v16 = "%sicnss2_qmi: Fail to init txn for Athdiag Read resp %d\n";
          printk("%sicnss2_qmi: Fail to init txn for Athdiag Read resp %d\n", byte_130B32, v13);
LABEL_17:
          ipc_log_string(icnss_ipc_log_context, v16, &unk_12DBF3, a3);
          goto LABEL_12;
        }
        a3 = qmi_send_request(a1 + 624, 0, v21, 48, 21, &wlfw_athdiag_read_req_msg_v01_ei, v11);
        if ( (a3 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v21);
          v16 = "%sicnss2_qmi: Fail to send Athdiag Read req %d\n";
          printk("%sicnss2_qmi: Fail to send Athdiag Read req %d\n", byte_130B32, a3);
          goto LABEL_17;
        }
        v14 = qmi_txn_wait(v21, *(unsigned int *)(a1 + 336));
        if ( (v14 & 0x80000000) != 0 )
        {
          a3 = v14;
          v16 = "%sicnss2_qmi: Athdaig Read resp wait failed with ret %d\n";
          printk("%sicnss2_qmi: Athdaig Read resp wait failed with ret %d\n", byte_130B32, v14);
          goto LABEL_17;
        }
        if ( *v12 )
        {
          printk("%sicnss2_qmi: QMI Athdiag Read request rejected, result:%d error:%d\n", byte_130B32, *v12, v12[1]);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: QMI Athdiag Read request rejected, result:%d error:%d\n",
            (const char *)&unk_12DBF3,
            *v12,
            v12[1]);
          a3 = -*v12;
          goto LABEL_12;
        }
        v15 = *((_DWORD *)v12 + 2);
        if ( !*((_BYTE *)v12 + 4) || v15 < a4 )
        {
          printk(
            "%sicnss2_qmi: Athdiag read data is invalid, data_valid = %u, data_len = %u\n",
            byte_130B32,
            *((unsigned __int8 *)v12 + 4),
            v15);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: Athdiag read data is invalid, data_valid = %u, data_len = %u\n",
            (const char *)&unk_12DBF3,
            *((unsigned __int8 *)v12 + 4),
            *((_DWORD *)v12 + 2));
          a3 = -22;
          goto LABEL_12;
        }
        if ( v15 < 0x1801 )
        {
          memcpy(a5, v12 + 6, *((unsigned int *)v12 + 2));
          a3 = 0;
LABEL_12:
          kfree(v12);
          goto LABEL_23;
        }
        _fortify_panic(16, -1, *((unsigned int *)v12 + 2));
        StatusReg = _ReadStatusReg(SP_EL0);
        v18 = *(_QWORD *)(StatusReg + 80);
        v19 = _init_swait_queue_head;
        *(_QWORD *)(StatusReg + 80) = &wlfw_athdiag_read_send_sync_msg__alloc_tag;
        v11 = (int *)_kmalloc_cache_noprof(v19, 3520, 12);
        *(_QWORD *)(StatusReg + 80) = v18;
        if ( !v11 )
          goto LABEL_21;
      }
      a3 = -12;
LABEL_23:
      kfree(v11);
    }
    else
    {
LABEL_21:
      a3 = -12;
    }
  }
  else
  {
    a3 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
