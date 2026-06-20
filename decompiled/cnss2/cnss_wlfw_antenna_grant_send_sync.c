__int64 __fastcall cnss_wlfw_antenna_grant_send_sync(__int64 a1)
{
  unsigned __int64 StatusReg; // x23
  const char *v3; // x1
  unsigned int v4; // w22
  __int64 v5; // x19
  unsigned __int16 *v6; // x20
  __int64 v7; // x9
  unsigned int v8; // w0
  __int64 v9; // x7
  __int64 v10; // x0
  unsigned int v11; // w0
  const char *v12; // x1
  __int64 v13; // x0
  const char *v14; // x1
  const char *v15; // x5
  _QWORD v17[10]; // [xsp+0h] [xbp-50h] BYREF

  v17[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v17, 0, 72);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v3 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v3 = "soft_irq";
    }
    else
    {
      v3 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v3,
      "cnss_wlfw_antenna_grant_send_sync",
      7u,
      7u,
      "Sending antenna grant sync request, state: 0x%lx, grant 0x%llx\n",
      *(_QWORD *)(a1 + 552),
      *(_QWORD *)(a1 + 6752),
      v17[0]);
    v5 = _kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
    if ( v5 )
    {
      v6 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v6 )
      {
        v4 = -12;
        v6 = (unsigned __int16 *)v5;
        goto LABEL_43;
      }
      v7 = *(_QWORD *)(a1 + 6752);
      *(_BYTE *)v5 = 1;
      *(_QWORD *)(v5 + 8) = v7;
      v8 = qmi_txn_init(a1 + 856, v17, &wlfw_antenna_grant_resp_msg_v01_ei);
      if ( (v8 & 0x80000000) != 0 )
      {
        v4 = v8;
        v13 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v14 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v14 = "soft_irq";
        }
        else
        {
          v14 = (const char *)(StatusReg + 2320);
        }
        v15 = "Failed to initialize txn for antenna grant request, err: %d\n";
      }
      else
      {
        v4 = qmi_send_request(a1 + 856, 0, v17, 72, 11, &wlfw_antenna_grant_req_msg_v01_ei, v5);
        if ( (v4 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v17);
          v13 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v14 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v14 = "soft_irq";
          }
          else
          {
            v14 = (const char *)(StatusReg + 2320);
          }
          v15 = "Failed to send antenna grant request, err: %d\n";
        }
        else
        {
          v10 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v11 = qmi_txn_wait(v17, v10);
          if ( (v11 & 0x80000000) == 0 )
          {
            if ( *v6 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
              {
                v12 = "irq";
              }
              else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
              {
                v12 = "soft_irq";
              }
              else
              {
                v12 = (const char *)(StatusReg + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v12,
                "cnss_wlfw_antenna_grant_send_sync",
                3u,
                3u,
                "Antenna grant request failed, result: %d, err: %d\n",
                *v6,
                v6[1],
                v17[0]);
              v4 = -*v6;
            }
            else
            {
              v4 = 0;
            }
            goto LABEL_40;
          }
          v4 = v11;
          v13 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v14 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v14 = "soft_irq";
          }
          else
          {
            v14 = (const char *)(StatusReg + 2320);
          }
          v15 = "Failed to wait for response of antenna grant request, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v13, v14, "cnss_wlfw_antenna_grant_send_sync", 3u, 3u, v15, v4, v9, v17[0]);
LABEL_40:
      kfree(v5);
LABEL_43:
      kfree(v6);
      goto LABEL_44;
    }
    v4 = -12;
  }
  else
  {
    v4 = -19;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v4;
}
