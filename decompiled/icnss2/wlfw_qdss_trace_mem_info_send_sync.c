__int64 __fastcall wlfw_qdss_trace_mem_info_send_sync(__int64 a1)
{
  __int64 v1; // x2
  unsigned __int16 *v3; // x19
  unsigned __int16 *v4; // x20
  unsigned int v5; // w2
  __int64 v6; // x25
  unsigned __int64 v7; // x26
  _DWORD *v8; // x27
  unsigned __int64 v9; // x8
  int v10; // t1
  unsigned __int16 *v11; // x10
  unsigned int v12; // w0
  unsigned int v13; // w22
  unsigned int v14; // w0
  const char *v15; // x21
  unsigned __int64 StatusReg; // x20
  __int64 v17; // x22
  _QWORD v19[10]; // [xsp+0h] [xbp-50h] BYREF

  v19[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 1832);
  if ( (v1 & 0x2000) != 0 )
  {
    v13 = -22;
  }
  else
  {
    memset(v19, 0, 72);
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending QDSS trace mem info, state: 0x%lx\n", v1);
    v3 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_relax, 3520, 1264);
    if ( v3 )
    {
      while ( 1 )
      {
        v4 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
        if ( !v4 )
          break;
        v5 = *(_DWORD *)(a1 + 3280);
        *(_DWORD *)v3 = v5;
        if ( v5 > 0x34 )
        {
          printk("%sicnss2_qmi: Invalid seg len %u\n", byte_130B32, v5);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: Invalid seg len %u\n",
            (const char *)&unk_12DBF3,
            *(_DWORD *)(a1 + 3280));
          v13 = -22;
          goto LABEL_16;
        }
        if ( !v5 )
        {
LABEL_11:
          v12 = qmi_txn_init(a1 + 624, v19, &wlfw_qdss_trace_mem_info_resp_msg_v01_ei, v4);
          if ( (v12 & 0x80000000) != 0 )
          {
            v13 = v12;
            v15 = "%sicnss2_qmi: Fail to initialize txn for QDSS trace mem request: err %d\n";
            printk("%sicnss2_qmi: Fail to initialize txn for QDSS trace mem request: err %d\n", byte_130B32, v12);
          }
          else
          {
            v13 = qmi_send_request(a1 + 624, 0, v19, 64, 892, &wlfw_qdss_trace_mem_info_req_msg_v01_ei, v3);
            if ( (v13 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v19);
              v15 = "%sicnss2_qmi: Fail to send QDSS trace mem info request: err %d\n";
              printk("%sicnss2_qmi: Fail to send QDSS trace mem info request: err %d\n", byte_130B32, v13);
            }
            else
            {
              v14 = qmi_txn_wait(v19, *(unsigned int *)(a1 + 336));
              if ( (v14 & 0x80000000) == 0 )
              {
                if ( *v4 )
                {
                  printk(
                    "%sicnss2_qmi: QDSS trace mem info request failed, result: %d, err: %d\n",
                    byte_130B32,
                    *v4,
                    v4[1]);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: QDSS trace mem info request failed, result: %d, err: %d\n",
                    (const char *)&unk_12DBF3,
                    *v4,
                    v4[1]);
                  v13 = -*v4;
                }
                else
                {
                  v13 = 0;
                }
                goto LABEL_16;
              }
              v13 = v14;
              v15 = "%sicnss2_qmi: Fail to wait for response of QDSS trace mem info request, err %d\n";
              printk(
                "%sicnss2_qmi: Fail to wait for response of QDSS trace mem info request, err %d\n",
                byte_130B32,
                v14);
            }
          }
          ipc_log_string(icnss_ipc_log_context, v15, &unk_12DBF3, v13);
LABEL_16:
          kfree(v3);
          goto LABEL_28;
        }
        v6 = 0;
        v7 = 0;
        v8 = (_DWORD *)(a1 + 3316);
        while ( 1 )
        {
          ipc_log_string(
            icnss_ipc_log_context,
            "icnss2_qmi: Memory for FW, va: 0x%pK, pa: %pa, size: 0x%zx, type: %u\n",
            *(const void **)(v8 - 5),
            v8 - 3,
            *(_QWORD *)(v8 - 7),
            *v8);
          if ( v6 == 624 )
            break;
          *(_QWORD *)&v3[v6 + 4] = *(_QWORD *)(v8 - 3);
          *(_DWORD *)&v3[v6 + 8] = *(_QWORD *)(v8 - 7);
          if ( (unsigned __int64)(v6 * 2 - 1245) < 0xFFFFFFFFFFFFFB0FLL )
          {
            __break(1u);
            break;
          }
          v9 = *(unsigned int *)v3;
          v10 = *v8;
          v8 += 10;
          ++v7;
          v11 = &v3[v6];
          v6 += 12;
          *((_DWORD *)v11 + 5) = v10;
          if ( v7 >= v9 )
            goto LABEL_11;
        }
        __break(0x5512u);
        StatusReg = _ReadStatusReg(SP_EL0);
        v17 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &wlfw_qdss_trace_mem_info_send_sync__alloc_tag;
        v3 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_relax, 3520, 1264);
        *(_QWORD *)(StatusReg + 80) = v17;
        if ( !v3 )
          goto LABEL_26;
      }
      v13 = -12;
      v4 = v3;
LABEL_28:
      kfree(v4);
    }
    else
    {
LABEL_26:
      v13 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
