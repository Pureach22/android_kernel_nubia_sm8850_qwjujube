__int64 __fastcall cnss_wlfw_antenna_switch_send_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x23
  const char *v10; // x1
  unsigned int v11; // w22
  __int64 v12; // x19
  unsigned __int16 *v13; // x20
  unsigned int v14; // w0
  __int64 v15; // x7
  __int64 v16; // x0
  unsigned int v17; // w0
  const char *v18; // x1
  __int64 v19; // x0
  const char *v20; // x1
  const char *v21; // x5
  __int64 v22; // x6
  const char *v23; // x1
  _QWORD v25[10]; // [xsp+0h] [xbp-50h] BYREF

  v25[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v25, 0, 72);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v10 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v10 = "soft_irq";
    }
    else
    {
      v10 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_wlfw_antenna_switch_send_sync",
      7u,
      7u,
      "Sending antenna switch sync request, state: 0x%lx\n",
      *(_QWORD *)(a1 + 552),
      a8,
      v25[0]);
    v12 = _kmalloc_cache_noprof(of_find_compatible_node, 3520, 1);
    if ( v12 )
    {
      v13 = (unsigned __int16 *)_kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
      if ( !v13 )
      {
        v11 = -12;
        v13 = (unsigned __int16 *)v12;
        goto LABEL_50;
      }
      v14 = qmi_txn_init(a1 + 856, v25, &wlfw_antenna_switch_resp_msg_v01_ei);
      if ( (v14 & 0x80000000) != 0 )
      {
        v11 = v14;
        v19 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v20 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v20 = "soft_irq";
        }
        else
        {
          v20 = (const char *)(StatusReg + 2320);
        }
        v21 = "Failed to initialize txn for antenna switch request, err: %d\n";
      }
      else
      {
        v11 = qmi_send_request(a1 + 856, 0, v25, 71, 0, &wlfw_antenna_switch_req_msg_v01_ei, v12);
        if ( (v11 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v25);
          v19 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v20 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v20 = "soft_irq";
          }
          else
          {
            v20 = (const char *)(StatusReg + 2320);
          }
          v21 = "Failed to send antenna switch request, err: %d\n";
        }
        else
        {
          v16 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v17 = qmi_txn_wait(v25, v16);
          if ( (v17 & 0x80000000) == 0 )
          {
            if ( *v13 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v18 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v18 = "soft_irq";
              }
              else
              {
                v18 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v18,
                "cnss_wlfw_antenna_switch_send_sync",
                7u,
                7u,
                "Antenna switch request failed, result: %d, err: %d\n",
                *v13,
                v13[1],
                v25[0]);
              v11 = -*v13;
            }
            else
            {
              v22 = *((unsigned __int8 *)v13 + 4);
              if ( *((_BYTE *)v13 + 4) )
                *(_QWORD *)(a1 + 6744) = *((_QWORD *)v13 + 1);
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v23 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v23 = "soft_irq";
              }
              else
              {
                v23 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v23,
                "cnss_wlfw_antenna_switch_send_sync",
                7u,
                7u,
                "Antenna valid: %u, antenna 0x%llx\n",
                v22,
                *((_QWORD *)v13 + 1),
                v25[0]);
              v11 = 0;
            }
            goto LABEL_43;
          }
          v11 = v17;
          v19 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v20 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v20 = "soft_irq";
          }
          else
          {
            v20 = (const char *)(StatusReg + 2320);
          }
          v21 = "Failed to wait for response of antenna switch request, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v19, v20, "cnss_wlfw_antenna_switch_send_sync", 3u, 3u, v21, v11, v15, v25[0]);
LABEL_43:
      kfree(v12);
LABEL_50:
      kfree(v13);
      goto LABEL_51;
    }
    v11 = -12;
  }
  else
  {
    v11 = -19;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v11;
}
