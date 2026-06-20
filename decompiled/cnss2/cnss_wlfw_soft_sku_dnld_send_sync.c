__int64 __fastcall cnss_wlfw_soft_sku_dnld_send_sync(
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
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 v14; // x6
  __int64 v15; // x7
  unsigned __int16 *v16; // x20
  const char *v17; // x1
  unsigned int v18; // w22
  const char *v19; // x1
  __int64 v20; // x9
  unsigned int v21; // w0
  __int64 v22; // x7
  __int64 v23; // x0
  unsigned int v24; // w0
  const char *v25; // x1
  __int64 v26; // x0
  const char *v27; // x1
  const char *v28; // x5
  char v30; // [xsp+0h] [xbp-60h]
  char v31; // [xsp+0h] [xbp-60h]
  char v32; // [xsp+0h] [xbp-60h]
  _QWORD v33[10]; // [xsp+10h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v33[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v33, 0, 72);
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
    "cnss_wlfw_soft_sku_dnld_send_sync",
    7u,
    7u,
    "Sending Soft SKU information message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v30);
  v12 = *(_QWORD *)(a1 + 528);
  if ( v12 == 4369 || v12 == 4366 )
  {
    v13 = _kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
    if ( v13 )
    {
      v16 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v16 )
      {
        v18 = -12;
        v16 = (unsigned __int16 *)v13;
        goto LABEL_57;
      }
      if ( !*(_QWORD *)(a1 + 3864) || !*(_QWORD *)(a1 + 3848) )
      {
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v19 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v19 = "soft_irq";
        }
        else
        {
          v19 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v19,
          "cnss_wlfw_soft_sku_dnld_send_sync",
          3u,
          3u,
          "Memory for Soft SKU is not available\n",
          v14,
          v15,
          v31);
        v18 = -12;
        goto LABEL_54;
      }
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
        "cnss_wlfw_soft_sku_dnld_send_sync",
        7u,
        7u,
        "Soft SKU memory, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        *(_QWORD *)(a1 + 3856),
        a1 + 3864,
        *(_QWORD *)(a1 + 3848));
      v20 = *(_QWORD *)(a1 + 3848);
      *(_QWORD *)v13 = *(_QWORD *)(a1 + 3864);
      *(_DWORD *)(v13 + 8) = v20;
      v21 = qmi_txn_init(a1 + 856, v33, &wlfw_soft_sku_info_resp_msg_v01_ei);
      if ( (v21 & 0x80000000) != 0 )
      {
        v18 = v21;
        v26 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v27 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v27 = "soft_irq";
        }
        else
        {
          v27 = (const char *)(v9 + 2320);
        }
        v28 = "Failed to initialize txn for Soft SKU information request, err: %d\n";
      }
      else
      {
        v18 = qmi_send_request(a1 + 856, 0, v33, 96, 18, &wlfw_soft_sku_info_req_msg_v01_ei, v13);
        if ( (v18 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v33);
          v26 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
          {
            v27 = "irq";
          }
          else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
          {
            v27 = "soft_irq";
          }
          else
          {
            v27 = (const char *)(v9 + 2320);
          }
          v28 = "Failed to send Soft SKU information request, err: %d\n";
        }
        else
        {
          v23 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v24 = qmi_txn_wait(v33, v23);
          if ( (v24 & 0x80000000) == 0 )
          {
            if ( *v16 )
            {
              if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
              {
                v25 = "irq";
              }
              else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
              {
                v25 = "soft_irq";
              }
              else
              {
                v25 = (const char *)(v9 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v25,
                "cnss_wlfw_soft_sku_dnld_send_sync",
                3u,
                3u,
                "Soft SKU information request failed, result: %d, err: %d\n",
                *v16,
                v16[1],
                v32);
              v18 = -*v16;
            }
            else
            {
              v18 = 0;
            }
            goto LABEL_54;
          }
          v18 = v24;
          v26 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
          {
            v27 = "irq";
          }
          else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
          {
            v27 = "soft_irq";
          }
          else
          {
            v27 = (const char *)(v9 + 2320);
          }
          v28 = "Failed to wait for response of Soft SKU information request, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v26, v27, "cnss_wlfw_soft_sku_dnld_send_sync", 3u, 3u, v28, v18, v22, v32);
LABEL_54:
      kfree(v13);
LABEL_57:
      kfree(v16);
      goto LABEL_58;
    }
    v18 = -12;
  }
  else
  {
    v18 = 0;
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v18;
}
