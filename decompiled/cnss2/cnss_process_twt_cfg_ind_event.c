__int64 __fastcall cnss_process_twt_cfg_ind_event(
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
  char v15; // w8
  __int64 v16; // x9
  char v17; // w10
  unsigned __int64 StatusReg; // x24
  __int64 v19; // x0
  __int16 v20; // w8
  __int16 v21; // w8
  __int16 v22; // w8
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  unsigned int v26; // w23
  unsigned int v27; // w0
  __int64 v28; // x7
  __int64 v29; // x0
  unsigned int v30; // w0
  const char *v31; // x1
  __int64 v32; // x0
  const char *v33; // x1
  const char *v34; // x5
  _QWORD v36[10]; // [xsp+0h] [xbp-50h] BYREF

  v36[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v36, 0, 72);
  if ( (*(_QWORD *)(a1 + 552) & 0x4000) != 0 )
  {
    v12 = _kmalloc_cache_noprof(of_get_property, 3520, 40);
    if ( v12 )
    {
      v14 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( v14 )
      {
        v15 = *a2;
        v16 = *((_QWORD *)a2 + 1);
        v17 = a2[16];
        StatusReg = _ReadStatusReg(SP_EL0);
        v19 = cnss_ipc_log_context;
        *(_BYTE *)v12 = v15;
        v20 = *((_WORD *)a2 + 9);
        *(_QWORD *)(v12 + 8) = v16;
        LOBYTE(v16) = a2[20];
        *(_WORD *)(v12 + 18) = v20;
        v21 = *((_WORD *)a2 + 11);
        *(_BYTE *)(v12 + 20) = v16;
        LOBYTE(v16) = a2[24];
        *(_WORD *)(v12 + 22) = v21;
        v22 = *((_WORD *)a2 + 13);
        *(_BYTE *)(v12 + 24) = v16;
        LOBYTE(v16) = a2[32];
        *(_WORD *)(v12 + 26) = v22;
        LOBYTE(v22) = a2[33];
        *(_BYTE *)(v12 + 16) = v17;
        *(_BYTE *)(v12 + 32) = v16;
        *(_BYTE *)(v12 + 33) = v22;
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
          v19,
          v23,
          "cnss_ims_wfc_call_twt_cfg_send_sync",
          7u,
          7u,
          "CNSS->IMS: TWT_CFG_REQ: state: 0x%lx\n",
          *(_QWORD *)(a1 + 552),
          v13,
          v36[0]);
        v27 = qmi_txn_init(a1 + 7064, v36, &ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei);
        if ( (v27 & 0x80000000) != 0 )
        {
          v26 = v27;
          v32 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v33 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v33 = "soft_irq";
          }
          else
          {
            v33 = (const char *)(StatusReg + 2320);
          }
          v34 = "CNSS->IMS: TWT_CFG_REQ: QMI Txn Init Err: %d\n";
        }
        else
        {
          v26 = qmi_send_request(
                  a1 + 7064,
                  0,
                  v36,
                  65,
                  35,
                  &ims_private_service_wfc_call_twt_config_req_msg_v01_ei,
                  v12);
          if ( (v26 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v36);
            v32 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v33 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v33 = "soft_irq";
            }
            else
            {
              v33 = (const char *)(StatusReg + 2320);
            }
            v34 = "CNSS->IMS: TWT_CFG_REQ: QMI Send Err: %d\n";
          }
          else
          {
            v29 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v30 = qmi_txn_wait(v36, v29);
            if ( (v30 & 0x80000000) == 0 )
            {
              if ( *v14 )
              {
                if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
                {
                  v31 = "irq";
                }
                else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  v31 = "soft_irq";
                }
                else
                {
                  v31 = (const char *)(StatusReg + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v31,
                  "cnss_ims_wfc_call_twt_cfg_send_sync",
                  3u,
                  3u,
                  "IMS->CNSS: TWT_CFG_RSP: Result: %d Err: %d\n",
                  *v14,
                  v14[1],
                  v36[0]);
                v26 = -*v14;
              }
              else
              {
                v26 = 0;
              }
              goto LABEL_45;
            }
            v26 = v30;
            v32 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v33 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v33 = "soft_irq";
            }
            else
            {
              v33 = (const char *)(StatusReg + 2320);
            }
            v34 = "IMS->CNSS: TWT_CFG_RSP: QMI Wait Err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v32, v33, "cnss_ims_wfc_call_twt_cfg_send_sync", 3u, 3u, v34, v26, v28, v36[0]);
LABEL_45:
        kfree(v12);
        kfree(v14);
        goto LABEL_48;
      }
      kfree(v12);
    }
    v26 = -12;
    goto LABEL_48;
  }
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v24 = *(_DWORD *)(v9 + 16);
    v25 = (const char *)(v9 + 2320);
    if ( (v24 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v25;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_ims_wfc_call_twt_cfg_send_sync",
    3u,
    3u,
    "Drop FW WFC indication as IMS QMI not connected\n",
    a7,
    a8,
    v36[0]);
  v26 = -22;
LABEL_48:
  kfree(a2);
  _ReadStatusReg(SP_EL0);
  return v26;
}
