__int64 __fastcall cnss_wlfw_dynamic_feature_mask_send_sync(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v2; // x23
  const char *v4; // x1
  __int64 v5; // x19
  unsigned __int16 *v6; // x20
  __int64 v7; // x9
  unsigned int v8; // w0
  __int64 v9; // x7
  unsigned int v10; // w21
  __int64 v11; // x0
  const char *v12; // x1
  __int64 v13; // x0
  const char *v14; // x1
  const char *v15; // x5
  _QWORD v17[10]; // [xsp+0h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = _ReadStatusReg(SP_EL0);
  v17[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v17, 0, 72);
  if ( (*(_DWORD *)(v2 + 16) & 0xF0000) != 0 )
  {
    v4 = "irq";
  }
  else if ( (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
  {
    v4 = "soft_irq";
  }
  else
  {
    v4 = (const char *)(v2 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v4,
    "cnss_wlfw_dynamic_feature_mask_send_sync",
    7u,
    7u,
    "Sending dynamic feature mask 0x%llx, state: 0x%lx\n",
    *(_QWORD *)(a1 + 7448),
    *(_QWORD *)(a1 + 552),
    v17[0]);
  v5 = _kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
  if ( v5 )
  {
    v6 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_node_opts_by_path, 3520, 32);
    if ( !v6 )
    {
      v10 = -12;
      v6 = (unsigned __int16 *)v5;
      goto LABEL_40;
    }
    v7 = *(_QWORD *)(a1 + 7448);
    *(_BYTE *)v5 = 1;
    *(_QWORD *)(v5 + 8) = v7;
    v8 = qmi_txn_init(a1 + 856, v17, &wlfw_dynamic_feature_mask_resp_msg_v01_ei);
    if ( (v8 & 0x80000000) != 0 )
    {
      v10 = v8;
      v13 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v2 + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else if ( (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
      {
        v14 = "soft_irq";
      }
      else
      {
        v14 = (const char *)(v2 + 2320);
      }
      v15 = "Fail to initialize txn for dynamic feature mask request: err %d\n";
    }
    else
    {
      v10 = qmi_send_request(a1 + 856, 0, v17, 59, 11, &wlfw_dynamic_feature_mask_req_msg_v01_ei, v5);
      if ( (v10 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v17);
        v13 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v2 + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else if ( (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
        {
          v14 = "soft_irq";
        }
        else
        {
          v14 = (const char *)(v2 + 2320);
        }
        v15 = "Fail to send dynamic feature mask request: err %d\n";
      }
      else
      {
        v11 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
        v10 = qmi_txn_wait(v17, v11);
        if ( (v10 & 0x80000000) == 0 )
        {
          if ( *v6 )
          {
            if ( (*(_DWORD *)(v2 + 16) & 0xF0000) != 0 )
            {
              v12 = "irq";
            }
            else if ( (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
            {
              v12 = "soft_irq";
            }
            else
            {
              v12 = (const char *)(v2 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v12,
              "cnss_wlfw_dynamic_feature_mask_send_sync",
              3u,
              3u,
              "Dynamic feature mask request failed, result: %d, err: %d\n",
              *v6,
              v6[1],
              v17[0]);
            v10 = -*v6;
          }
          goto LABEL_37;
        }
        v13 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v2 + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else if ( (*(_DWORD *)(v2 + 16) & 0xFF00) != 0 )
        {
          v14 = "soft_irq";
        }
        else
        {
          v14 = (const char *)(v2 + 2320);
        }
        v15 = "Fail to wait for response of dynamic feature mask request, err %d\n";
      }
    }
    cnss_debug_ipc_log_print(v13, v14, "cnss_wlfw_dynamic_feature_mask_send_sync", 3u, 3u, v15, v10, v9, v17[0]);
LABEL_37:
    kfree(v5);
LABEL_40:
    kfree(v6);
    goto LABEL_41;
  }
  v10 = -12;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v10;
}
