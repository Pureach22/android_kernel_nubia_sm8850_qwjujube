__int64 __fastcall cnss_wlfw_ini_send_sync(__int64 a1, unsigned __int8 a2)
{
  unsigned __int64 StatusReg; // x24
  const char *v5; // x1
  unsigned int v6; // w22
  unsigned __int16 *v7; // x20
  unsigned __int16 *v8; // x21
  unsigned int v9; // w0
  __int64 v10; // x0
  unsigned int v11; // w0
  const char *v12; // x1
  __int64 v13; // x0
  const char *v14; // x1
  const char *v15; // x5
  char v17; // [xsp+0h] [xbp-60h]
  char v18; // [xsp+0h] [xbp-60h]
  _QWORD v19[10]; // [xsp+10h] [xbp-50h] BYREF

  v19[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v19, 0, 72);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v5 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v5 = "soft_irq";
    }
    else
    {
      v5 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v5,
      "cnss_wlfw_ini_send_sync",
      7u,
      7u,
      "Sending ini sync request, state: 0x%lx, fw_log_mode: %d\n",
      *(_QWORD *)(a1 + 552),
      a2,
      v17);
    v7 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 2);
    if ( v7 )
    {
      v8 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v8 )
      {
        v6 = -12;
        v8 = v7;
        goto LABEL_43;
      }
      *(_BYTE *)v7 = 1;
      *((_BYTE *)v7 + 1) = a2;
      v9 = qmi_txn_init(a1 + 856, v19, &wlfw_ini_resp_msg_v01_ei);
      if ( (v9 & 0x80000000) != 0 )
      {
        v6 = v9;
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
        v15 = "Failed to initialize txn for ini request, fw_log_mode: %d, err: %d\n";
      }
      else
      {
        v6 = qmi_send_request(a1 + 856, 0, v19, 47, 4, &wlfw_ini_req_msg_v01_ei, v7);
        if ( (v6 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v19);
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
          v15 = "Failed to send ini request, fw_log_mode: %d, err: %d\n";
        }
        else
        {
          v10 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v11 = qmi_txn_wait(v19, v10);
          if ( (v11 & 0x80000000) == 0 )
          {
            if ( *v8 )
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
                "cnss_wlfw_ini_send_sync",
                3u,
                3u,
                "Ini request failed, fw_log_mode: %d, result: %d, err: %d\n",
                a2,
                *v8,
                v8[1]);
              v6 = -*v8;
            }
            else
            {
              v6 = 0;
            }
            goto LABEL_40;
          }
          v6 = v11;
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
          v15 = "Failed to wait for response of ini request, fw_log_mode: %d, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v13, v14, "cnss_wlfw_ini_send_sync", 3u, 3u, v15, a2, v6, v18);
LABEL_40:
      kfree(v7);
LABEL_43:
      kfree(v8);
      goto LABEL_44;
    }
    v6 = -12;
  }
  else
  {
    v6 = -19;
  }
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return v6;
}
