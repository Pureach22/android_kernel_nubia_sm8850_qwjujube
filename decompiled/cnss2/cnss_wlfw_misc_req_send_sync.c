__int64 __fastcall cnss_wlfw_misc_req_send_sync(__int64 a1, unsigned int a2)
{
  __int64 v4; // x7
  unsigned int *v5; // x20
  __int64 v6; // x7
  unsigned __int16 *v7; // x21
  unsigned int v8; // w0
  unsigned int v9; // w22
  unsigned int v10; // w0
  unsigned __int64 v11; // x8
  __int64 v12; // x7
  int v13; // w9
  const char *v14; // x1
  unsigned __int64 v15; // x8
  __int64 v16; // x0
  const char *v17; // x1
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x5
  const char *v23; // x1
  __int16 v24; // w9
  const char *v25; // x8
  __int16 v26; // w9
  const char *v27; // x8
  __int16 v28; // w9
  const char *v29; // x8
  __int16 v30; // w9
  const char *v31; // x8
  unsigned __int64 StatusReg; // x8
  const char *v33; // x1
  __int16 v34; // w9
  const char *v35; // x8
  unsigned __int64 v36; // x8
  const char *v37; // x1
  __int16 v38; // w9
  const char *v39; // x8
  char v41; // [xsp+0h] [xbp-60h]
  _QWORD v42[10]; // [xsp+10h] [xbp-50h] BYREF

  v42[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v42, 0, 72);
  v5 = (unsigned int *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( !v5 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v33 = "irq";
    }
    else
    {
      v34 = *(_DWORD *)(StatusReg + 16);
      v35 = (const char *)(StatusReg + 2320);
      if ( (v34 & 0xFF00) != 0 )
        v33 = "soft_irq";
      else
        v33 = v35;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v33,
      "cnss_wlfw_misc_req_send_sync",
      3u,
      3u,
      "Failed to allocate req for MISC_REQ[%d]\n",
      a2,
      v4,
      v41);
    goto LABEL_51;
  }
  v7 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( !v7 )
  {
    v36 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v36 + 16) & 0xF0000) != 0 )
    {
      v37 = "irq";
    }
    else
    {
      v38 = *(_DWORD *)(v36 + 16);
      v39 = (const char *)(v36 + 2320);
      if ( (v38 & 0xFF00) != 0 )
        v37 = "soft_irq";
      else
        v37 = v39;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v37,
      "cnss_wlfw_misc_req_send_sync",
      3u,
      3u,
      "Failed to allocate resp for MISC_REQ[%d]\n",
      a2,
      v6,
      v41);
    kfree(v5);
LABEL_51:
    v9 = -12;
    goto LABEL_52;
  }
  v8 = qmi_txn_init(a1 + 856, v42, &wlfw_misc_resp_msg_v01_ei);
  if ( (v8 & 0x80000000) != 0 )
  {
    v9 = v8;
    v15 = _ReadStatusReg(SP_EL0);
    v16 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v17 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(v15 + 16);
      v21 = (const char *)(v15 + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v17 = "soft_irq";
      else
        v17 = v21;
    }
    v22 = "Fail to init txn for MISC_REQ[%d]: %d\n";
  }
  else
  {
    *v5 = a2;
    v9 = qmi_send_request(a1 + 856, 0, v42, 99, 7, &wlfw_misc_req_msg_v01_ei, v5);
    if ( (v9 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v42);
      v18 = _ReadStatusReg(SP_EL0);
      v16 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else
      {
        v24 = *(_DWORD *)(v18 + 16);
        v25 = (const char *)(v18 + 2320);
        if ( (v24 & 0xFF00) != 0 )
          v17 = "soft_irq";
        else
          v17 = v25;
      }
      v22 = "Fail to send MISC_REQ[%d]: %d\n";
    }
    else
    {
      v10 = qmi_txn_wait(v42, *(unsigned int *)(a1 + 6696));
      if ( (v10 & 0x80000000) == 0 )
      {
        v11 = _ReadStatusReg(SP_EL0);
        v12 = *v7;
        v13 = *(_DWORD *)(v11 + 16) & 0xF0000;
        if ( *v7 )
        {
          if ( v13 )
          {
            v14 = "irq";
          }
          else
          {
            v26 = *(_DWORD *)(v11 + 16);
            v27 = (const char *)(v11 + 2320);
            if ( (v26 & 0xFF00) != 0 )
              v14 = "soft_irq";
            else
              v14 = v27;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v14,
            "cnss_wlfw_misc_req_send_sync",
            3u,
            3u,
            "MISC_REQ[%d] failed, result:%d error:%d\n",
            a2,
            v12,
            v7[1]);
          v9 = -*v7;
        }
        else
        {
          if ( v13 )
          {
            v23 = "irq";
          }
          else
          {
            v30 = *(_DWORD *)(v11 + 16);
            v31 = (const char *)(v11 + 2320);
            if ( (v30 & 0xFF00) != 0 )
              v23 = "soft_irq";
            else
              v23 = v31;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v23,
            "cnss_wlfw_misc_req_send_sync",
            7u,
            7u,
            "Sent MISC_REQ[%d] successfully\n",
            a2,
            v12,
            v41);
          v9 = 0;
        }
        goto LABEL_34;
      }
      v9 = v10;
      v19 = _ReadStatusReg(SP_EL0);
      v16 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v19 + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else
      {
        v28 = *(_DWORD *)(v19 + 16);
        v29 = (const char *)(v19 + 2320);
        if ( (v28 & 0xFF00) != 0 )
          v17 = "soft_irq";
        else
          v17 = v29;
      }
      v22 = "Failed to wait for resp of MISC_REQ[%d]: %d\n";
    }
  }
  cnss_debug_ipc_log_print(v16, v17, "cnss_wlfw_misc_req_send_sync", 3u, 3u, v22, a2, v9, v41);
LABEL_34:
  kfree(v5);
  kfree(v7);
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return v9;
}
