__int64 __fastcall cnss_wlfw_tme_patch_dnld_send_sync(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x23
  const char *v12; // x1
  __int64 v13; // x8
  __int64 v14; // x19
  __int64 v15; // x6
  __int64 v16; // x7
  unsigned __int16 *v17; // x20
  const char *v18; // x1
  unsigned int v19; // w22
  const char *v20; // x1
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w0
  __int64 v24; // x7
  __int64 v25; // x0
  unsigned int v26; // w0
  const char *v27; // x1
  __int64 v28; // x0
  const char *v29; // x1
  const char *v30; // x5
  char v32; // [xsp+0h] [xbp-60h]
  char v33; // [xsp+0h] [xbp-60h]
  char v34; // [xsp+0h] [xbp-60h]
  _QWORD v35[10]; // [xsp+10h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v35[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v35, 0, 72);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v12 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v12 = "soft_irq";
  }
  else
  {
    v12 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v12,
    "cnss_wlfw_tme_patch_dnld_send_sync",
    7u,
    7u,
    "Sending TME patch information message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v32);
  v13 = *(_QWORD *)(a1 + 528);
  if ( v13 == 4369 || v13 == 4366 )
  {
    v14 = _kmalloc_cache_noprof(of_find_node_opts_by_path, 3520, 24);
    if ( v14 )
    {
      v17 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v17 )
      {
        v19 = -12;
        v17 = (unsigned __int16 *)v14;
        goto LABEL_57;
      }
      if ( !*(_QWORD *)(a1 + 3904) || !*(_QWORD *)(a1 + 3888) )
      {
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v20 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v20 = "soft_irq";
        }
        else
        {
          v20 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v20,
          "cnss_wlfw_tme_patch_dnld_send_sync",
          3u,
          3u,
          "Memory for TME patch is not available\n",
          v15,
          v16,
          v33);
        v19 = -12;
        goto LABEL_54;
      }
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v18 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v18 = "soft_irq";
      }
      else
      {
        v18 = (const char *)(v9 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_wlfw_tme_patch_dnld_send_sync",
        7u,
        7u,
        "TME-L patch memory, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        *(_QWORD *)(a1 + 3896),
        a1 + 3904,
        *(_QWORD *)(a1 + 3888));
      v21 = *(_QWORD *)(a1 + 3904);
      v22 = *(_QWORD *)(a1 + 3888);
      *(_DWORD *)v14 = a2;
      *(_QWORD *)(v14 + 8) = v21;
      *(_DWORD *)(v14 + 16) = v22;
      v23 = qmi_txn_init(a1 + 856, v35, &wlfw_tme_lite_info_resp_msg_v01_ei);
      if ( (v23 & 0x80000000) != 0 )
      {
        v19 = v23;
        v28 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
        {
          v29 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v29 = "soft_irq";
        }
        else
        {
          v29 = (const char *)(v9 + 2320);
        }
        v30 = "Failed to initialize txn for TME patch information request, err: %d\n";
      }
      else
      {
        v19 = qmi_send_request(a1 + 856, 0, v35, 91, 25, &wlfw_tme_lite_info_req_msg_v01_ei, v14);
        if ( (v19 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v35);
          v28 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
          {
            v29 = "irq";
          }
          else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
          {
            v29 = "soft_irq";
          }
          else
          {
            v29 = (const char *)(v9 + 2320);
          }
          v30 = "Failed to send TME patch information request, err: %d\n";
        }
        else
        {
          v25 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
          v26 = qmi_txn_wait(v35, v25);
          if ( (v26 & 0x80000000) == 0 )
          {
            if ( *v17 )
            {
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
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v27,
                "cnss_wlfw_tme_patch_dnld_send_sync",
                3u,
                3u,
                "TME patch information request failed, result: %d, err: %d\n",
                *v17,
                v17[1],
                v34);
              v19 = -*v17;
            }
            else
            {
              v19 = 0;
            }
            goto LABEL_54;
          }
          v19 = v26;
          v28 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
          {
            v29 = "irq";
          }
          else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
          {
            v29 = "soft_irq";
          }
          else
          {
            v29 = (const char *)(v9 + 2320);
          }
          v30 = "Failed to wait for response of TME patch information request, err: %d\n";
        }
      }
      cnss_debug_ipc_log_print(v28, v29, "cnss_wlfw_tme_patch_dnld_send_sync", 3u, 3u, v30, v19, v24, v34);
LABEL_54:
      kfree(v14);
LABEL_57:
      kfree(v17);
      goto LABEL_58;
    }
    v19 = -12;
  }
  else
  {
    v19 = 0;
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v19;
}
