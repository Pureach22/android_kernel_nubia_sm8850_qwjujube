__int64 __fastcall cnss_process_wfc_call_ind_event(
        __int64 a1,
        char *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v9; // x8
  const char *v10; // x1
  __int64 v12; // x20
  __int64 v13; // x7
  unsigned __int16 *v14; // x21
  char v15; // w9
  __int64 v16; // x11
  char v17; // w8
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x0
  int v20; // w9
  char v21; // w8
  int v22; // w10
  char v23; // w8
  const char *v24; // x1
  __int16 v25; // w9
  const char *v26; // x8
  unsigned int v27; // w23
  unsigned int v28; // w0
  __int64 v29; // x7
  __int64 v30; // x0
  unsigned int v31; // w0
  const char *v32; // x1
  __int64 v33; // x0
  const char *v34; // x1
  const char *v35; // x5
  _QWORD v37[10]; // [xsp+0h] [xbp-50h] BYREF

  v37[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v37, 0, 72);
  if ( (*(_QWORD *)(a1 + 552) & 4) != 0 )
  {
    v12 = _kmalloc_cache_noprof(pm_relax, 3520, 296);
    if ( v12 )
    {
      v14 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( v14 )
      {
        v15 = *a2;
        *(_DWORD *)v12 = 1;
        v16 = *((_QWORD *)a2 + 1);
        *(_BYTE *)(v12 + 260) = 1;
        v17 = a2[1];
        StatusReg = _ReadStatusReg(SP_EL0);
        *(_BYTE *)(v12 + 4) = v15;
        v19 = cnss_ipc_log_context;
        *(_BYTE *)(v12 + 261) = v15;
        v20 = *(_DWORD *)(a2 + 2);
        *(_BYTE *)(v12 + 262) = v17;
        v21 = a2[16];
        *(_DWORD *)(v12 + 263) = v20;
        LOWORD(v20) = *((_WORD *)a2 + 9);
        v22 = *((_DWORD *)a2 + 6);
        *(_BYTE *)(v12 + 280) = v21;
        v23 = a2[20];
        *(_QWORD *)(v12 + 272) = v16;
        *(_WORD *)(v12 + 282) = v20;
        *(_BYTE *)(v12 + 284) = v23;
        *(_DWORD *)(v12 + 288) = v22;
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
        cnss_debug_ipc_log_print(
          v19,
          v24,
          "cnss_wlfw_wfc_call_status_send_sync",
          7u,
          7u,
          "CNSS->FW: WFC_CALL_REQ: state: 0x%lx\n",
          *(_QWORD *)(a1 + 552),
          v13,
          v37[0]);
        v28 = qmi_txn_init(a1 + 856, v37, &wlfw_wfc_call_status_resp_msg_v01_ei);
        if ( (v28 & 0x80000000) != 0 )
        {
          v27 = v28;
          v33 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v34 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v34 = "soft_irq";
          }
          else
          {
            v34 = (const char *)(StatusReg + 2320);
          }
          v35 = "CNSS->FW: WFC_CALL_REQ: QMI Txn Init: Err %d\n";
        }
        else
        {
          v27 = qmi_send_request(a1 + 856, 0, v37, 73, 296, &wlfw_wfc_call_status_req_msg_v01_ei, v12);
          if ( (v27 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v37);
            v33 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v34 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v34 = "soft_irq";
            }
            else
            {
              v34 = (const char *)(StatusReg + 2320);
            }
            v35 = "CNSS->FW: WFC_CALL_REQ: QMI Send Err: %d\n";
          }
          else
          {
            v30 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v31 = qmi_txn_wait(v37, v30);
            if ( (v31 & 0x80000000) == 0 )
            {
              if ( *v14 )
              {
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                {
                  v32 = "irq";
                }
                else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  v32 = "soft_irq";
                }
                else
                {
                  v32 = (const char *)(StatusReg + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v32,
                  "cnss_wlfw_wfc_call_status_send_sync",
                  3u,
                  3u,
                  "FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n",
                  *v14,
                  v14[1],
                  v37[0]);
                v27 = -*v14;
              }
              else
              {
                v27 = 0;
              }
              goto LABEL_45;
            }
            v27 = v31;
            v33 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v34 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v34 = "soft_irq";
            }
            else
            {
              v34 = (const char *)(StatusReg + 2320);
            }
            v35 = "FW->CNSS: WFC_CALL_RSP: QMI Wait Err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v33, v34, "cnss_wlfw_wfc_call_status_send_sync", 3u, 3u, v35, v27, v29, v37[0]);
LABEL_45:
        kfree(v12);
        kfree(v14);
        goto LABEL_48;
      }
      kfree(v12);
    }
    v27 = -12;
    goto LABEL_48;
  }
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v25 = *(_DWORD *)(v9 + 16);
    v26 = (const char *)(v9 + 2320);
    if ( (v25 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v26;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_wlfw_wfc_call_status_send_sync",
    3u,
    3u,
    "Drop IMS WFC indication as FW not initialized\n",
    a7,
    a8,
    v37[0]);
  v27 = -22;
LABEL_48:
  kfree(a2);
  _ReadStatusReg(SP_EL0);
  return v27;
}
