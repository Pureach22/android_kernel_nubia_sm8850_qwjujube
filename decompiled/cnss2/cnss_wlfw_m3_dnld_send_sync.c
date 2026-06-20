__int64 __fastcall cnss_wlfw_m3_dnld_send_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x23
  const char *v11; // x1
  __int64 v12; // x19
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned __int16 *v15; // x20
  const char *v16; // x1
  const char *v17; // x1
  unsigned int v18; // w22
  __int64 v19; // x9
  unsigned int v20; // w0
  __int64 v21; // x7
  __int64 v22; // x0
  unsigned int v23; // w0
  const char *v24; // x1
  __int64 v25; // x0
  const char *v26; // x1
  const char *v27; // x5
  char v29; // [xsp+0h] [xbp-60h]
  char v30; // [xsp+0h] [xbp-60h]
  char v31; // [xsp+0h] [xbp-60h]
  _QWORD v32[10]; // [xsp+10h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v32[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v32, 0, 72);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_wlfw_m3_dnld_send_sync",
    7u,
    7u,
    "Sending M3 information message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v29);
  v12 = _kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
  if ( v12 )
  {
    v15 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
    if ( !v15 )
    {
      v18 = -12;
      v15 = (unsigned __int16 *)v12;
      goto LABEL_54;
    }
    if ( !*(_QWORD *)(a1 + 3824) || !*(_QWORD *)(a1 + 3808) )
    {
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v17 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v17 = "soft_irq";
      }
      else
      {
        v17 = (const char *)(v9 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v17,
        "cnss_wlfw_m3_dnld_send_sync",
        3u,
        3u,
        "Memory for M3 is not available\n",
        v13,
        v14,
        v30);
      v18 = -12;
      goto LABEL_51;
    }
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_wlfw_m3_dnld_send_sync",
      7u,
      7u,
      "M3 memory, va: 0x%pK, pa: %pa, size: 0x%zx\n",
      *(_QWORD *)(a1 + 3816),
      a1 + 3824,
      *(_QWORD *)(a1 + 3808));
    v19 = *(_QWORD *)(a1 + 3808);
    *(_QWORD *)v12 = *(_QWORD *)(a1 + 3824);
    *(_DWORD *)(v12 + 8) = v19;
    v20 = qmi_txn_init(a1 + 856, v32, &wlfw_m3_info_resp_msg_v01_ei);
    if ( (v20 & 0x80000000) != 0 )
    {
      v18 = v20;
      v25 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v26 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v26 = "soft_irq";
      }
      else
      {
        v26 = (const char *)(v9 + 2320);
      }
      v27 = "Failed to initialize txn for M3 information request, err: %d\n";
    }
    else
    {
      v18 = qmi_send_request(a1 + 856, 0, v32, 60, 18, &wlfw_m3_info_req_msg_v01_ei, v12);
      if ( (v18 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v32);
        v25 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v26 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v26 = "soft_irq";
        }
        else
        {
          v26 = (const char *)(v9 + 2320);
        }
        v27 = "Failed to send M3 information request, err: %d\n";
      }
      else
      {
        v22 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
        v23 = qmi_txn_wait(v32, v22);
        if ( (v23 & 0x80000000) == 0 )
        {
          if ( *v15 )
          {
            if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
            {
              v24 = "irq";
            }
            else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            {
              v24 = "soft_irq";
            }
            else
            {
              v24 = (const char *)(v9 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v24,
              "cnss_wlfw_m3_dnld_send_sync",
              3u,
              3u,
              "M3 information request failed, result: %d, err: %d\n",
              *v15,
              v15[1],
              v31);
            v18 = -*v15;
          }
          else
          {
            v18 = 0;
          }
          goto LABEL_51;
        }
        v18 = v23;
        v25 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v26 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v26 = "soft_irq";
        }
        else
        {
          v26 = (const char *)(v9 + 2320);
        }
        v27 = "Failed to wait for response of M3 information request, err: %d\n";
      }
    }
    cnss_debug_ipc_log_print(v25, v26, "cnss_wlfw_m3_dnld_send_sync", 3u, 3u, v27, v18, v21, v31);
LABEL_51:
    kfree(v12);
LABEL_54:
    kfree(v15);
    goto LABEL_55;
  }
  v18 = -12;
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return v18;
}
