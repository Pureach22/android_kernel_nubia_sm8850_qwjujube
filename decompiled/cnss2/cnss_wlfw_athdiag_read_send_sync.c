__int64 __fastcall cnss_wlfw_athdiag_read_send_sync(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        void *a5)
{
  unsigned __int64 StatusReg; // x26
  int v9; // w8
  const char *v12; // x1
  unsigned int v13; // w24
  const char *v14; // x1
  unsigned int *v15; // x19
  unsigned __int16 *v16; // x20
  unsigned int v17; // w0
  __int64 v18; // x7
  __int64 v19; // x0
  unsigned int v20; // w0
  const char *v21; // x1
  __int64 v22; // x0
  const char *v23; // x1
  const char *v24; // x5
  const char *v25; // x1
  char v27; // [xsp+0h] [xbp-60h]
  char v28; // [xsp+0h] [xbp-60h]
  _QWORD v29[10]; // [xsp+10h] [xbp-50h] BYREF

  v29[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v13 = -19;
    goto LABEL_59;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  memset(v29, 0, 72);
  v9 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( !a5 || a4 - 6145 <= 0xFFFFE7FF )
  {
    if ( v9 )
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
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_wlfw_athdiag_read_send_sync",
      3u,
      3u,
      "Invalid parameters for athdiag read: data %pK, data_len %u\n",
      (__int64)a5,
      a4,
      v27);
    v13 = -22;
    goto LABEL_59;
  }
  if ( v9 )
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
    "cnss_wlfw_athdiag_read_send_sync",
    7u,
    7u,
    "athdiag read: state 0x%lx, offset %x, mem_type %x, data_len %u\n",
    *(_QWORD *)(a1 + 552),
    a2,
    a3);
  v15 = (unsigned int *)_kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 12);
  if ( !v15 )
  {
LABEL_58:
    v13 = -12;
    goto LABEL_59;
  }
  v16 = (unsigned __int16 *)_kmalloc_cache_noprof(put_device, 3520, 6156);
  if ( !v16 )
  {
    kfree(v15);
    goto LABEL_58;
  }
  *v15 = a2;
  v15[1] = a3;
  v15[2] = a4;
  v17 = qmi_txn_init(a1 + 856, v29, &wlfw_athdiag_read_resp_msg_v01_ei);
  if ( (v17 & 0x80000000) != 0 )
  {
    v13 = v17;
    v22 = cnss_ipc_log_context;
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
    v24 = "Failed to initialize txn for athdiag read request, err: %d\n";
    goto LABEL_51;
  }
  v13 = qmi_send_request(a1 + 856, 0, v29, 48, 21, &wlfw_athdiag_read_req_msg_v01_ei, v15);
  if ( (v13 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v29);
    v22 = cnss_ipc_log_context;
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
    v24 = "Failed to send athdiag read request, err: %d\n";
    goto LABEL_51;
  }
  v19 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
  v20 = qmi_txn_wait(v29, v19);
  if ( (v20 & 0x80000000) != 0 )
  {
    v13 = v20;
    v22 = cnss_ipc_log_context;
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
    v24 = "Failed to wait for response of athdiag read request, err: %d\n";
LABEL_51:
    cnss_debug_ipc_log_print(v22, v23, "cnss_wlfw_athdiag_read_send_sync", 3u, 3u, v24, v13, v18, v28);
LABEL_52:
    kfree(v15);
    kfree(v16);
    goto LABEL_59;
  }
  if ( *v16 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_wlfw_athdiag_read_send_sync",
      3u,
      3u,
      "Athdiag read request failed, result: %d, err: %d\n",
      *v16,
      v16[1],
      v28);
    v13 = -*v16;
    goto LABEL_52;
  }
  if ( !*((_BYTE *)v16 + 4) || *((_DWORD *)v16 + 2) != a4 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v25 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v25 = "soft_irq";
    }
    else
    {
      v25 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v25,
      "cnss_wlfw_athdiag_read_send_sync",
      3u,
      3u,
      "athdiag read data is invalid, data_valid = %u, data_len = %u\n",
      *((unsigned __int8 *)v16 + 4),
      *((unsigned int *)v16 + 2),
      v28);
    v13 = -22;
    goto LABEL_52;
  }
  memcpy(a5, v16 + 6, a4);
  kfree(v15);
  kfree(v16);
  v13 = 0;
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return v13;
}
