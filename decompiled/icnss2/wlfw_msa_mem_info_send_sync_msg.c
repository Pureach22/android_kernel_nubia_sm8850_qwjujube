__int64 __fastcall wlfw_msa_mem_info_send_sync_msg(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x20
  unsigned __int16 *v4; // x21
  int v5; // w10
  int v6; // w9
  unsigned int v7; // w0
  unsigned int v8; // w22
  unsigned int v9; // w0
  unsigned int v10; // w2
  int v11; // w8
  unsigned __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x4
  unsigned __int64 *v15; // x8
  unsigned __int64 v16; // x3
  unsigned __int64 v17; // x23
  size_t v18; // x22
  int v19; // w5
  __int64 v20; // x0
  unsigned __int64 v21; // x3
  int v22; // w5
  const char *v23; // x23
  unsigned __int64 StatusReg; // x21
  __int64 v25; // x22
  __int64 (__fastcall *v26)(_QWORD, _QWORD, _QWORD); // x0
  _QWORD v28[10]; // [xsp+0h] [xbp-50h] BYREF

  v28[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1832);
    memset(v28, 0, 72);
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending MSA mem info, state: 0x%lx\n", v2);
    v3 = _kmalloc_cache_noprof(_init_swait_queue_head, 3520, 16);
    if ( v3 )
    {
      while ( 1 )
      {
        v4 = (unsigned __int16 *)_kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 40);
        if ( !v4 )
          break;
        v5 = *(_DWORD *)(a1 + 2576);
        v6 = *(_DWORD *)(a1 + 1816);
        *(_QWORD *)v3 = *(_QWORD *)(a1 + 1792);
        *(_DWORD *)(v3 + 8) = v6;
        *(_DWORD *)(a1 + 2576) = v5 + 1;
        v7 = qmi_txn_init(a1 + 624, v28, &wlfw_msa_info_resp_msg_v01_ei, v4);
        if ( (v7 & 0x80000000) != 0 )
        {
          v8 = v7;
          v23 = "%sicnss2_qmi: fatal: Fail to init txn for MSA Mem info resp %d\n";
          printk("%sicnss2_qmi: fatal: Fail to init txn for MSA Mem info resp %d\n", byte_130B32, v7);
LABEL_28:
          ipc_log_string(icnss_ipc_log_context, v23, &unk_12DBF3, v8);
          goto LABEL_30;
        }
        v8 = qmi_send_request(a1 + 624, 0, v28, 45, 18, &wlfw_msa_info_req_msg_v01_ei, v3);
        if ( (v8 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v28);
          v23 = "%sicnss2_qmi: fatal: Fail to send MSA Mem info req %d\n";
          printk("%sicnss2_qmi: fatal: Fail to send MSA Mem info req %d\n", byte_130B32, v8);
          goto LABEL_28;
        }
        v9 = qmi_txn_wait(v28, *(unsigned int *)(a1 + 336));
        if ( (v9 & 0x80000000) != 0 )
        {
          v8 = v9;
          v23 = "%sicnss2_qmi: fatal: MSA Mem info resp wait failed ret %d\n";
          printk("%sicnss2_qmi: fatal: MSA Mem info resp wait failed ret %d\n", byte_130B32, v9);
          goto LABEL_28;
        }
        if ( *v4 )
        {
          printk(
            "%sicnss2_qmi: fatal: QMI MSA Mem info request rejected, result:%d error:%d\n",
            byte_130B32,
            *v4,
            v4[1]);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: fatal: QMI MSA Mem info request rejected, result:%d error:%d\n",
            (const char *)&unk_12DBF3,
            *v4,
            v4[1]);
          v8 = -*v4;
          goto LABEL_30;
        }
        ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Receive mem_region_info_len: %d\n", *((_DWORD *)v4 + 1));
        v10 = *((_DWORD *)v4 + 1);
        if ( v10 >= 3 )
        {
          printk("%sicnss2_qmi: fatal: Invalid memory region length received: %d\n", byte_130B32, v10);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: fatal: Invalid memory region length received: %d\n",
            (const char *)&unk_12DBF3,
            *((_DWORD *)v4 + 1));
          goto LABEL_24;
        }
        v11 = *(_DWORD *)(a1 + 2580);
        v12 = *(_QWORD *)(a1 + 1792);
        v13 = *(unsigned int *)(a1 + 1816);
        *(_DWORD *)(a1 + 2040) = v10;
        *(_DWORD *)(a1 + 2580) = v11 + 1;
        if ( !v10 )
          goto LABEL_20;
        v14 = *((unsigned int *)v4 + 4);
        v15 = (unsigned __int64 *)(v4 + 4);
        if ( (unsigned int)v14 > (unsigned int)v13 || (v16 = *v15, v17 = v12 + v13, *v15 >= v12 + v13) )
        {
          v18 = 0;
          goto LABEL_23;
        }
        v18 = 0;
        if ( v16 < v12 || v16 + v14 > v17 )
          goto LABEL_23;
        v19 = *((unsigned __int8 *)v4 + 20);
        v20 = icnss_ipc_log_context;
        *(_QWORD *)(a1 + 2048) = v16;
        *(_DWORD *)(a1 + 2056) = v14;
        *(_BYTE *)(a1 + 2060) = v19;
        ipc_log_string(v20, "icnss2_qmi: Memory Region: %d Addr: 0x%llx Size: 0x%x Flag: 0x%08x\n", 0, v16, v14, v19);
        if ( *((_DWORD *)v4 + 1) < 2u )
          goto LABEL_20;
        v14 = *((unsigned int *)v4 + 8);
        v15 = (unsigned __int64 *)(v4 + 12);
        if ( (unsigned int)v14 > *(_DWORD *)(a1 + 1816) || (v21 = *v15, *v15 >= v17) )
        {
          v18 = 16;
LABEL_23:
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2_qmi: Received out of range Addr: 0x%llx Size: 0x%x\n",
            *v15,
            v14);
          memset((void *)(a1 + 2048), 0, v18);
LABEL_24:
          v8 = -22;
LABEL_30:
          kfree(v4);
          kfree(v3);
          ++*(_DWORD *)(a1 + 2584);
          goto LABEL_38;
        }
        v18 = 16;
        if ( v21 < *(_QWORD *)(a1 + 1792) || v21 + v14 > v17 )
          goto LABEL_23;
        v22 = *((unsigned __int8 *)v4 + 36);
        *(_QWORD *)(a1 + 2064) = v21;
        *(_DWORD *)(a1 + 2072) = v14;
        *(_BYTE *)(a1 + 2076) = v22;
        ipc_log_string(
          icnss_ipc_log_context,
          "icnss2_qmi: Memory Region: %d Addr: 0x%llx Size: 0x%x Flag: 0x%08x\n",
          1,
          v21,
          v14,
          v22);
        if ( *((_DWORD *)v4 + 1) <= 2u )
        {
LABEL_20:
          kfree(v4);
          kfree(v3);
          v8 = 0;
          goto LABEL_38;
        }
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v25 = *(_QWORD *)(StatusReg + 80);
        v26 = _init_swait_queue_head;
        *(_QWORD *)(StatusReg + 80) = &wlfw_msa_mem_info_send_sync_msg__alloc_tag;
        v3 = _kmalloc_cache_noprof(v26, 3520, 16);
        *(_QWORD *)(StatusReg + 80) = v25;
        if ( !v3 )
          goto LABEL_37;
      }
      kfree(v3);
    }
LABEL_37:
    v8 = -12;
  }
  else
  {
    v8 = -19;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v8;
}
