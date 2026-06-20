__int64 __fastcall wlfw_send_qdss_trace_mode_req(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v6; // x19
  unsigned __int16 *v7; // x20
  int v8; // w9
  unsigned __int64 StatusReg; // x24
  int v10; // w9
  __int64 v11; // x0
  int v12; // w8
  const char *v13; // x1
  unsigned int v14; // w22
  unsigned int v15; // w0
  __int64 v16; // x7
  const char *v17; // x1
  __int64 v18; // x0
  const char *v19; // x1
  const char *v20; // x5
  char v22; // [xsp+0h] [xbp-60h]
  _QWORD v23[10]; // [xsp+10h] [xbp-50h] BYREF

  v23[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    memset(v23, 0, 72);
    v6 = _kmalloc_cache_noprof(of_find_node_opts_by_path, 3520, 32);
    if ( v6 )
    {
      v7 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v7 )
      {
        v14 = -12;
        goto LABEL_45;
      }
      v8 = *(_DWORD *)(a1 + 7572);
      *(_BYTE *)v6 = 1;
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = v8 & ~(v8 >> 31);
      *(_BYTE *)(v6 + 8) = 1;
      v11 = cnss_ipc_log_context;
      *(_BYTE *)(v6 + 24) = 1;
      *(_DWORD *)(v6 + 4) = a2;
      if ( v10 >= 2 )
        v12 = 2;
      else
        v12 = v10;
      *(_QWORD *)(v6 + 16) = a3;
      *(_DWORD *)(v6 + 28) = v12;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v13 = "soft_irq";
      }
      else
      {
        v13 = (const char *)(StatusReg + 2320);
      }
      cnss_debug_ipc_log_print(
        v11,
        v13,
        "wlfw_send_qdss_trace_mode_req",
        7u,
        7u,
        "%s: mode %u, option %llu, hw_trc_disable_override: %u",
        (__int64)"wlfw_send_qdss_trace_mode_req",
        a2,
        a3);
      v15 = qmi_txn_init(a1 + 856, v23, &wlfw_qdss_trace_mode_resp_msg_v01_ei);
      if ( (v15 & 0x80000000) != 0 )
      {
        v14 = v15;
        v18 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v19 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v19 = "soft_irq";
        }
        else
        {
          v19 = (const char *)(StatusReg + 2320);
        }
        v20 = "Fail to init txn for QDSS Mode resp %d\n";
      }
      else
      {
        v14 = qmi_send_request(a1 + 856, 0, v23, 69, 25, &wlfw_qdss_trace_mode_req_msg_v01_ei, v6);
        if ( (v14 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v23);
          v18 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v19 = "soft_irq";
          }
          else
          {
            v19 = (const char *)(StatusReg + 2320);
          }
          v20 = "Fail to send QDSS Mode req %d\n";
        }
        else
        {
          v14 = qmi_txn_wait(v23, *(unsigned int *)(a1 + 6696));
          if ( (v14 & 0x80000000) == 0 )
          {
            if ( *v7 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v17 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v17 = "soft_irq";
              }
              else
              {
                v17 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v17,
                "wlfw_send_qdss_trace_mode_req",
                3u,
                3u,
                "QMI QDSS Mode request rejected, result:%d error:%d\n",
                *v7,
                v7[1],
                v22);
              v14 = -*v7;
            }
            goto LABEL_42;
          }
          v18 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v19 = "soft_irq";
          }
          else
          {
            v19 = (const char *)(StatusReg + 2320);
          }
          v20 = "QDSS Mode resp wait failed with rc %d\n";
        }
      }
      cnss_debug_ipc_log_print(v18, v19, "wlfw_send_qdss_trace_mode_req", 3u, 3u, v20, v14, v16, v22);
LABEL_42:
      kfree(v7);
LABEL_45:
      kfree(v6);
      goto LABEL_46;
    }
    v14 = -12;
  }
  else
  {
    v14 = -19;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v14;
}
