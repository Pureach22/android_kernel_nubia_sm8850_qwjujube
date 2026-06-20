__int64 __fastcall cnss_wlfw_respond_mem_send_sync(
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
  unsigned __int64 v9; // x26
  const char *v11; // x1
  _DWORD *v12; // x19
  __int64 v13; // x0
  __int64 v14; // x7
  __int64 v15; // x6
  unsigned __int16 *v16; // x20
  __int64 v17; // x0
  const char *v18; // x1
  __int64 v19; // x28
  unsigned __int64 v20; // x22
  unsigned int *v21; // x27
  __int64 v22; // x8
  const char *v23; // x1
  _DWORD *v24; // x8
  unsigned __int64 v25; // x9
  int v26; // t1
  unsigned int v27; // w0
  __int64 v28; // x7
  unsigned int v29; // w22
  __int64 v30; // x0
  unsigned int v31; // w0
  const char *v32; // x1
  __int64 v33; // x6
  int v34; // w8
  const char *v35; // x1
  const char *v36; // x5
  __int64 v37; // x0
  const char *v38; // x1
  const char *v39; // x5
  _DWORD *v40; // x0
  __int64 v41; // x20
  char v43; // [xsp+0h] [xbp-70h]
  char v44; // [xsp+0h] [xbp-70h]
  unsigned __int16 *v45; // [xsp+10h] [xbp-60h]
  _QWORD v46[10]; // [xsp+20h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v46[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v46, 0, 72);
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
    "cnss_wlfw_respond_mem_send_sync",
    7u,
    7u,
    "Sending respond memory message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v43);
  v12 = (_DWORD *)_kmalloc_cache_noprof(of_find_device_by_node, 3520, 1256);
  if ( v12 )
  {
LABEL_7:
    v13 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 208);
    if ( !v13 )
    {
      v29 = -12;
      v40 = v12;
      goto LABEL_76;
    }
    v15 = *(unsigned int *)(a1 + 1720);
    if ( (unsigned int)v15 < 0x35 )
    {
      v45 = (unsigned __int16 *)v13;
      *v12 = v15;
      if ( !(_DWORD)v15 )
      {
LABEL_23:
        v16 = v45;
        v27 = qmi_txn_init(a1 + 856, v46, &wlfw_respond_mem_resp_msg_v01_ei);
        if ( (v27 & 0x80000000) != 0 )
        {
          v29 = v27;
          v37 = cnss_ipc_log_context;
          if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
          {
            v38 = "irq";
          }
          else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
          {
            v38 = "soft_irq";
          }
          else
          {
            v38 = (const char *)(v9 + 2320);
          }
          v39 = "Failed to initialize txn for respond memory request, err: %d\n";
        }
        else
        {
          v29 = qmi_send_request(a1 + 856, 0, v46, 54, 888, &wlfw_respond_mem_req_msg_v01_ei, v12);
          if ( (v29 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v46);
            v37 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
            {
              v38 = "irq";
            }
            else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            {
              v38 = "soft_irq";
            }
            else
            {
              v38 = (const char *)(v9 + 2320);
            }
            v39 = "Failed to send respond memory request, err: %d\n";
          }
          else
          {
            v30 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
            v31 = qmi_txn_wait(v46, v30);
            if ( (v31 & 0x80000000) == 0 )
            {
              if ( *v45 )
              {
                if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
                {
                  v32 = "irq";
                }
                else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
                {
                  v32 = "soft_irq";
                }
                else
                {
                  v32 = (const char *)(v9 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v32,
                  "cnss_wlfw_respond_mem_send_sync",
                  3u,
                  3u,
                  "Respond memory request failed, result: %d, err: %d\n",
                  *v45,
                  v45[1],
                  v44);
                v29 = -*v45;
              }
              else
              {
                v29 = 0;
              }
              goto LABEL_71;
            }
            v29 = v31;
            v37 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
            {
              v38 = "irq";
            }
            else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            {
              v38 = "soft_irq";
            }
            else
            {
              v38 = (const char *)(v9 + 2320);
            }
            v39 = "Failed to wait for response of respond memory request, err: %d\n";
          }
        }
        cnss_debug_ipc_log_print(v37, v38, "cnss_wlfw_respond_mem_send_sync", 3u, 3u, v39, v29, v28, v44);
LABEL_71:
        kfree(v12);
        v40 = v16;
LABEL_76:
        kfree(v40);
        goto LABEL_77;
      }
      v19 = 0;
      v20 = 0;
      v21 = (unsigned int *)(a1 + 1756);
      while ( *(_QWORD *)(v21 - 3) )
      {
        v22 = *(_QWORD *)(v21 - 7);
        if ( !v22 )
          break;
        v23 = "irq";
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            v23 = "soft_irq";
          else
            v23 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v23,
          "cnss_wlfw_respond_mem_send_sync",
          7u,
          7u,
          "Memory for FW, va: 0x%pK, pa: %pa, size: 0x%zx, type: %u\n",
          *(_QWORD *)(v21 - 5),
          (__int64)(v21 - 3),
          v22);
        if ( v19 == 312 )
          goto LABEL_73;
        *(_QWORD *)&v12[v19 + 2] = *(_QWORD *)(v21 - 3);
        if ( (unsigned __int64)(v19 * 4 - 1240) < 0xFFFFFFFFFFFFFB18LL
          || (v24 = &v12[v19],
              v12[v19 + 4] = *(_QWORD *)(v21 - 7),
              (unsigned __int64)(v19 * 4 - 1237) < 0xFFFFFFFFFFFFFB17LL) )
        {
          __break(1u);
LABEL_73:
          __break(0x5512u);
          v41 = *(_QWORD *)(v9 + 80);
          *(_QWORD *)(v9 + 80) = &cnss_wlfw_respond_mem_send_sync__alloc_tag;
          v12 = (_DWORD *)_kmalloc_cache_noprof(of_find_device_by_node, 3520, 1256);
          *(_QWORD *)(v9 + 80) = v41;
          if ( v12 )
            goto LABEL_7;
          goto LABEL_74;
        }
        v25 = (unsigned int)*v12;
        v26 = *v21;
        v21 += 10;
        ++v20;
        v19 += 6;
        v24[5] = v26;
        if ( v20 >= v25 )
          goto LABEL_23;
      }
      v33 = *v21;
      v17 = cnss_ipc_log_context;
      v34 = *(_DWORD *)(v9 + 16) & 0xF0000;
      if ( (_DWORD)v33 )
      {
        v16 = v45;
        if ( v34 )
        {
          v35 = "irq";
        }
        else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
        {
          v35 = "soft_irq";
        }
        else
        {
          v35 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v35,
          "cnss_wlfw_respond_mem_send_sync",
          3u,
          3u,
          "Memory for FW is not available for type: %u\n",
          v33,
          v14,
          v44);
        v29 = -12;
        goto LABEL_71;
      }
      v16 = v45;
      if ( v34 )
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
      v36 = "Invalid memory for FW type, segment = %d\n";
      v15 = (unsigned int)v20;
    }
    else
    {
      v16 = (unsigned __int16 *)v13;
      v17 = cnss_ipc_log_context;
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
      v36 = "Invalid seg len %u\n";
    }
    cnss_debug_ipc_log_print(v17, v18, "cnss_wlfw_respond_mem_send_sync", 3u, 3u, v36, v15, v14, v44);
    v29 = -22;
    goto LABEL_71;
  }
LABEL_74:
  v29 = -12;
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return v29;
}
