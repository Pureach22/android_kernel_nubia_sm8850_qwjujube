__int64 __fastcall cnss_wlfw_get_info_send_sync(__int64 a1, unsigned int a2, const void *a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x25
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
  __int64 v22; // x20
  char v24; // [xsp+0h] [xbp-60h]
  _QWORD v25[10]; // [xsp+10h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = _ReadStatusReg(SP_EL0);
  v25[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v25, 0, 72);
  if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
  {
    v10 = "soft_irq";
  }
  else
  {
    v10 = (const char *)(v5 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v10,
    "cnss_wlfw_get_info_send_sync",
    8u,
    7u,
    "Sending get info message, type: %d, cmd length: %d, state: 0x%lx\n",
    a2,
    a4,
    *(_QWORD *)(a1 + 552));
  if ( (int)a4 <= 6144 )
  {
    v12 = _kmalloc_cache_noprof(put_device, 3520, 6152);
    if ( v12 )
    {
      while ( 1 )
      {
        v13 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
        if ( !v13 )
          break;
        *(_BYTE *)v12 = a2;
        *(_DWORD *)(v12 + 4) = a4;
        if ( a4 < 0x1801 )
        {
          memcpy((void *)(v12 + 8), a3, a4);
          v14 = qmi_txn_init(a1 + 856, v25, &wlfw_get_info_resp_msg_v01_ei);
          if ( (v14 & 0x80000000) != 0 )
          {
            v11 = v14;
            v19 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
            {
              v20 = "irq";
            }
            else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
            {
              v20 = "soft_irq";
            }
            else
            {
              v20 = (const char *)(v5 + 2320);
            }
            v21 = "Failed to initialize txn for get info request, err: %d\n";
          }
          else
          {
            v11 = qmi_send_request(a1 + 856, 0, v25, 74, 6153, &wlfw_get_info_req_msg_v01_ei, v12);
            if ( (v11 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v25);
              v19 = cnss_ipc_log_context;
              if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
              {
                v20 = "irq";
              }
              else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
              {
                v20 = "soft_irq";
              }
              else
              {
                v20 = (const char *)(v5 + 2320);
              }
              v21 = "Failed to send get info request, err: %d\n";
            }
            else
            {
              v16 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
              v17 = qmi_txn_wait(v25, v16);
              if ( (v17 & 0x80000000) == 0 )
              {
                if ( *v13 )
                {
                  if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
                  {
                    v18 = "irq";
                  }
                  else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
                  {
                    v18 = "soft_irq";
                  }
                  else
                  {
                    v18 = (const char *)(v5 + 2320);
                  }
                  cnss_debug_ipc_log_print(
                    cnss_ipc_log_context,
                    v18,
                    "cnss_wlfw_get_info_send_sync",
                    3u,
                    3u,
                    "Get info request failed, result: %d, err: %d\n",
                    *v13,
                    v13[1],
                    v24);
                  v11 = -*v13;
                }
                else
                {
                  v11 = 0;
                }
                goto LABEL_41;
              }
              v11 = v17;
              v19 = cnss_ipc_log_context;
              if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
              {
                v20 = "irq";
              }
              else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
              {
                v20 = "soft_irq";
              }
              else
              {
                v20 = (const char *)(v5 + 2320);
              }
              v21 = "Failed to wait for response of get info request, err: %d\n";
            }
          }
          cnss_debug_ipc_log_print(v19, v20, "cnss_wlfw_get_info_send_sync", 3u, 3u, v21, v11, v15, v24);
LABEL_41:
          kfree(v12);
          goto LABEL_45;
        }
        _fortify_panic(17, 6144, a4);
        v22 = *(_QWORD *)(v5 + 80);
        *(_QWORD *)(v5 + 80) = &cnss_wlfw_get_info_send_sync__alloc_tag;
        v12 = _kmalloc_cache_noprof(put_device, 3520, 6152);
        *(_QWORD *)(v5 + 80) = v22;
        if ( !v12 )
          goto LABEL_43;
      }
      v11 = -12;
      v13 = (unsigned __int16 *)v12;
LABEL_45:
      kfree(v13);
    }
    else
    {
LABEL_43:
      v11 = -12;
    }
  }
  else
  {
    v11 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
