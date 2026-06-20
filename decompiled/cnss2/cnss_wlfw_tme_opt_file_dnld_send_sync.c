__int64 __fastcall cnss_wlfw_tme_opt_file_dnld_send_sync(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x8
  bool v9; // cc
  __int64 v10; // x8
  unsigned __int64 StatusReg; // x23
  const char *v15; // x1
  __int64 v16; // x19
  char *v17; // x6
  __int64 v18; // x7
  unsigned __int16 *v19; // x20
  __int64 *v20; // x25
  unsigned int v21; // w22
  const char *v22; // x1
  const char *v23; // x1
  __int64 v24; // x8
  __int64 v25; // x9
  unsigned int v26; // w0
  __int64 v27; // x7
  __int64 v28; // x0
  unsigned int v29; // w0
  __int64 v30; // x6
  __int64 v31; // x7
  int v32; // w8
  const char *v33; // x1
  __int64 v34; // x0
  const char *v35; // x1
  const char *v36; // x5
  const char *v37; // x1
  const char *v38; // x5
  char v40; // [xsp+0h] [xbp-60h]
  char v41; // [xsp+0h] [xbp-60h]
  char v42; // [xsp+0h] [xbp-60h]
  _QWORD v43[10]; // [xsp+10h] [xbp-50h] BYREF

  v43[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 528) - 4366LL;
  v9 = v8 > 4;
  v10 = (1LL << v8) & 0x19;
  if ( v9 || v10 == 0 )
  {
    v21 = 0;
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    memset(v43, 0, 72);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v15 = "soft_irq";
    }
    else
    {
      v15 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_wlfw_tme_opt_file_dnld_send_sync",
      7u,
      7u,
      "Sending TME opt file information message, state: 0x%lx\n",
      *(_QWORD *)(a1 + 552),
      a8,
      v40);
    v16 = _kmalloc_cache_noprof(of_find_node_opts_by_path, 3520, 24);
    if ( v16 )
    {
      v19 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      if ( !v19 )
      {
        v21 = -12;
        v19 = (unsigned __int16 *)v16;
        goto LABEL_85;
      }
      switch ( a2 )
      {
        case 3:
          v20 = (__int64 *)(a1 + 4008);
          v17 = "peach_dpr.bin";
          if ( a1 == -4008 )
            goto LABEL_28;
          break;
        case 2:
          v20 = (__int64 *)(a1 + 3968);
          v17 = "peach_rpr.bin";
          if ( a1 == -3968 )
            goto LABEL_28;
          break;
        case 1:
          v20 = (__int64 *)(a1 + 3928);
          v17 = *(_QWORD *)(a1 + 528) == 4370 ? "cologne_sec.dat" : "peach_sec.dat";
          if ( a1 == -3928 )
            goto LABEL_28;
          break;
        default:
          goto LABEL_28;
      }
      if ( v20[2] && *v20 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v22 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v22 = "soft_irq";
        }
        else
        {
          v22 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v22,
          "cnss_wlfw_tme_opt_file_dnld_send_sync",
          7u,
          7u,
          "TME opt file %s memory, va: 0x%pK, pa: %pa, size: 0x%zx\n",
          (__int64)v17,
          v20[1],
          (_BYTE)v20 + 16);
        v24 = v20[2];
        v25 = *v20;
        *(_DWORD *)v16 = a2;
        *(_QWORD *)(v16 + 8) = v24;
        *(_DWORD *)(v16 + 16) = v25;
        v26 = qmi_txn_init(a1 + 856, v43, &wlfw_tme_lite_info_resp_msg_v01_ei);
        if ( (v26 & 0x80000000) != 0 )
        {
          v21 = v26;
          v34 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v35 = "irq";
          }
          else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            v35 = "soft_irq";
          }
          else
          {
            v35 = (const char *)(StatusReg + 2320);
          }
          v36 = "Failed to initialize txn for TME opt file information request, err: %d\n";
        }
        else
        {
          v21 = qmi_send_request(a1 + 856, 0, v43, 91, 25, &wlfw_tme_lite_info_req_msg_v01_ei, v16);
          if ( (v21 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v43);
            v34 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v35 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v35 = "soft_irq";
            }
            else
            {
              v35 = (const char *)(StatusReg + 2320);
            }
            v36 = "Failed to send TME opt file information request, err: %d\n";
          }
          else
          {
            v28 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v29 = qmi_txn_wait(v43, v28);
            if ( (v29 & 0x80000000) == 0 )
            {
              v30 = *v19;
              if ( *v19 )
              {
                v31 = v19[1];
                v21 = -(int)v30;
                v32 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
                if ( (_DWORD)v31 == 2 )
                {
                  if ( v32 )
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
                  v38 = "malloc SRAM failed\n";
                }
                else
                {
                  if ( (_DWORD)v31 != 83 )
                  {
                    if ( v32 )
                    {
                      v37 = "irq";
                    }
                    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                    {
                      v37 = "soft_irq";
                    }
                    else
                    {
                      v37 = (const char *)(StatusReg + 2320);
                    }
                    cnss_debug_ipc_log_print(
                      cnss_ipc_log_context,
                      v37,
                      "cnss_wlfw_tme_opt_file_dnld_send_sync",
                      3u,
                      3u,
                      "TME opt file information request failed, result: %d, err: %d\n",
                      v30,
                      v31,
                      v42);
                    goto LABEL_34;
                  }
                  if ( v32 )
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
                  v38 = "TME Power On failed\n";
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v33,
                  "cnss_wlfw_tme_opt_file_dnld_send_sync",
                  3u,
                  3u,
                  v38,
                  v30,
                  v31,
                  v42);
              }
              else
              {
                v21 = 0;
              }
LABEL_34:
              kfree(v16);
LABEL_85:
              kfree(v19);
              goto LABEL_86;
            }
            v21 = v29;
            v34 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v35 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v35 = "soft_irq";
            }
            else
            {
              v35 = (const char *)(StatusReg + 2320);
            }
            v36 = "Failed to wait for response of TME opt file information request, err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v34, v35, "cnss_wlfw_tme_opt_file_dnld_send_sync", 3u, 3u, v36, v21, v27, v42);
        goto LABEL_34;
      }
LABEL_28:
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
        cnss_ipc_log_context,
        v23,
        "cnss_wlfw_tme_opt_file_dnld_send_sync",
        3u,
        3u,
        "Memory for TME opt file is not available\n",
        (__int64)v17,
        v18,
        v41);
      v21 = -12;
      goto LABEL_34;
    }
    v21 = -12;
  }
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return v21;
}
