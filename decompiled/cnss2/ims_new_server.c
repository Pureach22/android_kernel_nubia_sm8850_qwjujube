__int64 __fastcall ims_new_server(__int64 *a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x22
  const char *v6; // x1
  int v7; // w9
  int v8; // w10
  __int64 v9; // x0
  unsigned int v10; // w0
  __int64 v11; // x6
  __int64 v12; // x7
  const char *v14; // x1
  unsigned int v15; // w20
  const char *v16; // x1
  __int64 v17; // x6
  __int64 v18; // x7
  const char *v19; // x1
  __int64 v20; // x21
  unsigned int v21; // w0
  __int64 v22; // x7
  __int64 v23; // x0
  const char *v24; // x1
  const char *v25; // x5
  unsigned __int64 v31; // x10
  char v33; // [xsp+0h] [xbp-20h]
  char v34; // [xsp+0h] [xbp-20h]
  char v35; // [xsp+0h] [xbp-20h]
  char v36; // [xsp+0h] [xbp-20h]
  _DWORD v37[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v38; // [xsp+18h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v38 = *(_QWORD *)(StatusReg + 1808);
  v37[0] = 0;
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v6 = "soft_irq";
  }
  else
  {
    v6 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "ims_new_server",
    7u,
    7u,
    "IMS server arrive: node %u port %u\n",
    *(unsigned int *)(a2 + 12),
    *(unsigned int *)(a2 + 16),
    v33);
  v7 = *(_DWORD *)(a2 + 12);
  v8 = *(_DWORD *)(a2 + 16);
  v9 = *a1;
  LOWORD(v37[0]) = 42;
  v37[1] = v7;
  v37[2] = v8;
  v10 = kernel_connect(v9, v37, 12, 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    v15 = v10;
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v3 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "ims_new_server",
      3u,
      3u,
      "Fail to connect to remote service port\n",
      v11,
      v12,
      v34);
  }
  else
  {
    _X8 = (unsigned __int64 *)(a1 - 814);
    __asm { PRFM            #0x11, [X8] }
    do
      v31 = __ldxr(_X8);
    while ( __stxr(v31 | 0x4000, _X8) );
    if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
    {
      v14 = "soft_irq";
    }
    else
    {
      v14 = (const char *)(v3 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "ims_new_server",
      7u,
      7u,
      "IMS Server Connected: 0x%lx\n",
      *_X8,
      v12,
      v34);
    if ( a1 != qword_1B98 )
    {
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v19 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v19 = "soft_irq";
      }
      else
      {
        v19 = (const char *)(v3 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v19,
        "ims_subscribe_for_indication_send_async",
        7u,
        7u,
        "Sending ASYNC ims subscribe for indication\n",
        v17,
        v18,
        v35);
      v20 = _kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v20 )
      {
        v15 = -12;
        goto LABEL_47;
      }
      *(_WORD *)(v20 + 2) = 257;
      v21 = qmi_txn_init(a1, a1 + 38, 0);
      if ( (v21 & 0x80000000) != 0 )
      {
        v15 = v21;
        v23 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(v3 + 2320);
        }
        v25 = "Fail to init txn for ims subscribe for indication resp %d\n";
      }
      else
      {
        v15 = qmi_send_request(a1, 0, a1 + 38, 62, 8, &ims_private_service_subscribe_ind_req_msg_v01_ei, v20);
        if ( (v15 & 0x80000000) == 0 )
        {
          v15 = 0;
LABEL_43:
          kfree(v20);
          goto LABEL_47;
        }
        qmi_txn_cancel(a1 + 38);
        v23 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
        {
          v24 = "irq";
        }
        else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
        {
          v24 = "soft_irq";
        }
        else
        {
          v24 = (const char *)(v3 + 2320);
        }
        v25 = "Fail to send ims subscribe for indication req %d\n";
      }
      cnss_debug_ipc_log_print(v23, v24, "ims_subscribe_for_indication_send_async", 3u, 3u, v25, v15, v22, v36);
      goto LABEL_43;
    }
    v15 = -19;
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return v15;
}
