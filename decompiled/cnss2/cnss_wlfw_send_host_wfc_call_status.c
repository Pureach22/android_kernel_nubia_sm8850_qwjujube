__int64 __fastcall cnss_wlfw_send_host_wfc_call_status(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x8
  const char *v9; // x1
  __int64 v12; // x19
  __int64 v13; // x7
  unsigned __int16 *v14; // x20
  unsigned __int64 StatusReg; // x24
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  unsigned int v19; // w23
  unsigned int v20; // w0
  __int64 v21; // x7
  int v22; // w9
  const char *v23; // x1
  const char *v24; // x1
  __int64 v25; // x0
  unsigned int v26; // w0
  const char *v27; // x1
  __int64 v28; // x0
  const char *v29; // x5
  _QWORD v31[10]; // [xsp+0h] [xbp-50h] BYREF

  v31[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v31, 0, 72);
  if ( (*(_QWORD *)(a1 + 552) & 4) != 0 )
  {
    v12 = _kmalloc_cache_noprof(pm_relax, 3520, 296);
    if ( v12 )
    {
      v14 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( v14 )
      {
        *(_BYTE *)(v12 + 261) = a2;
        *(_BYTE *)(v12 + 260) = 1;
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v16 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v16 = "soft_irq";
        }
        else
        {
          v16 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v16,
          "cnss_wlfw_send_host_wfc_call_status",
          7u,
          7u,
          "CNSS->FW: WFC_CALL_REQ: state: 0x%lx\n",
          *(_QWORD *)(a1 + 552),
          v13,
          v31[0]);
        v20 = qmi_txn_init(a1 + 856, v31, &wlfw_wfc_call_status_resp_msg_v01_ei);
        v22 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
        if ( (v20 & 0x80000000) != 0 )
        {
          v19 = v20;
          if ( v22 )
          {
            v24 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v24 = "soft_irq";
          }
          else
          {
            v24 = (const char *)(StatusReg + 2320);
          }
          v29 = "CNSS->FW: WFC_CALL_REQ: QMI Txn Init: Err %d\n";
          v28 = cnss_ipc_log_context;
        }
        else
        {
          if ( v22 )
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
            "cnss_wlfw_send_host_wfc_call_status",
            7u,
            7u,
            "Send WFC Mode: %d\n",
            a2,
            v21,
            v31[0]);
          v19 = qmi_send_request(a1 + 856, 0, v31, 73, 296, &wlfw_wfc_call_status_req_msg_v01_ei, v12);
          if ( (v19 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v31);
            v28 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v24 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v24 = "soft_irq";
            }
            else
            {
              v24 = (const char *)(StatusReg + 2320);
            }
            v29 = "CNSS->FW: WFC_CALL_REQ: QMI Send Err: %d\n";
          }
          else
          {
            v25 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v26 = qmi_txn_wait(v31, v25);
            if ( (v26 & 0x80000000) == 0 )
            {
              if ( *v14 )
              {
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                {
                  v27 = "irq";
                }
                else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  v27 = "soft_irq";
                }
                else
                {
                  v27 = (const char *)(StatusReg + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v27,
                  "cnss_wlfw_send_host_wfc_call_status",
                  3u,
                  3u,
                  "FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n",
                  *v14,
                  v14[1],
                  v31[0]);
                v19 = -22;
              }
              else
              {
                v19 = 0;
              }
              goto LABEL_50;
            }
            v19 = v26;
            v28 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v24 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v24 = "soft_irq";
            }
            else
            {
              v24 = (const char *)(StatusReg + 2320);
            }
            v29 = "FW->CNSS: WFC_CALL_RSP: QMI Wait Err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v28, v24, "cnss_wlfw_send_host_wfc_call_status", 3u, 3u, v29, v19, v21, v31[0]);
LABEL_50:
        kfree(v12);
        kfree(v14);
        goto LABEL_53;
      }
      kfree(v12);
    }
    v19 = -12;
    goto LABEL_53;
  }
  v8 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v8 + 16) & 0xF0000) != 0 )
  {
    v9 = "irq";
  }
  else
  {
    v17 = *(_DWORD *)(v8 + 16);
    v18 = (const char *)(v8 + 2320);
    if ( (v17 & 0xFF00) != 0 )
      v9 = "soft_irq";
    else
      v9 = v18;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v9,
    "cnss_wlfw_send_host_wfc_call_status",
    3u,
    3u,
    "Drop host WFC indication as FW not initialized\n",
    a7,
    a8,
    v31[0]);
  v19 = -22;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v19;
}
