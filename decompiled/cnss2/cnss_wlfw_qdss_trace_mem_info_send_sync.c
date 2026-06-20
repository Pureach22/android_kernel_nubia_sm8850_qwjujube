__int64 __fastcall cnss_wlfw_qdss_trace_mem_info_send_sync(
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
  unsigned __int64 v9; // x25
  const char *v10; // x22
  const char *v11; // x1
  _DWORD *v12; // x19
  __int64 v13; // x0
  __int64 v14; // x7
  _DWORD *v15; // x21
  __int64 v16; // x6
  const char *v17; // x1
  __int64 v18; // x27
  unsigned __int64 v19; // x28
  int *v20; // x21
  const char *v21; // x1
  unsigned __int64 v22; // x8
  int v23; // t1
  _DWORD *v24; // x10
  unsigned int v25; // w0
  __int64 v26; // x7
  unsigned int v27; // w22
  __int64 v28; // x0
  unsigned int v29; // w0
  const char *v30; // x1
  __int64 v31; // x0
  const char *v32; // x1
  const char *v33; // x5
  __int64 v34; // x20
  char v36; // [xsp+0h] [xbp-70h]
  char v37; // [xsp+0h] [xbp-70h]
  unsigned __int16 *v38; // [xsp+10h] [xbp-60h]
  const char *v39; // [xsp+18h] [xbp-58h]
  _QWORD v40[10]; // [xsp+20h] [xbp-50h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v10 = (const char *)a1;
  v40[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v40, 0, 72);
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
    "cnss_wlfw_qdss_trace_mem_info_send_sync",
    7u,
    7u,
    "Sending QDSS trace mem info, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v36);
  v12 = (_DWORD *)_kmalloc_cache_noprof(of_find_device_by_node, 3520, 1264);
  if ( v12 )
  {
    while ( 1 )
    {
      v13 = _kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
      v15 = (_DWORD *)v13;
      if ( !v13 )
        break;
      v16 = *((unsigned int *)v10 + 1036);
      if ( (unsigned int)v16 >= 0x35 )
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
          "cnss_wlfw_qdss_trace_mem_info_send_sync",
          3u,
          3u,
          "Invalid seg len %u\n",
          v16,
          v14,
          v37);
        v27 = -22;
        goto LABEL_55;
      }
      v38 = (unsigned __int16 *)v13;
      v39 = v10;
      *v12 = v16;
      if ( !(_DWORD)v16 )
      {
LABEL_21:
        v15 = v38;
        v25 = qmi_txn_init(v39 + 856, v40, &wlfw_qdss_trace_mem_info_resp_msg_v01_ei);
        if ( (v25 & 0x80000000) != 0 )
        {
          v27 = v25;
          v31 = cnss_ipc_log_context;
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
          v33 = "Fail to initialize txn for QDSS trace mem request: err %d\n";
        }
        else
        {
          v27 = qmi_send_request(v39 + 856, 0, v40, 64, 892, &wlfw_qdss_trace_mem_info_req_msg_v01_ei, v12);
          if ( (v27 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v40);
            v31 = cnss_ipc_log_context;
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
            v33 = "Fail to send QDSS trace mem info request: err %d\n";
          }
          else
          {
            v28 = _msecs_to_jiffies(*((unsigned int *)v39 + 1674));
            v29 = qmi_txn_wait(v40, v28);
            if ( (v29 & 0x80000000) == 0 )
            {
              if ( *v38 )
              {
                if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
                {
                  v30 = "irq";
                }
                else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
                {
                  v30 = "soft_irq";
                }
                else
                {
                  v30 = (const char *)(v9 + 2320);
                }
                cnss_debug_ipc_log_print(
                  cnss_ipc_log_context,
                  v30,
                  "cnss_wlfw_qdss_trace_mem_info_send_sync",
                  3u,
                  3u,
                  "QDSS trace mem info request failed, result: %d, err: %d\n",
                  *v38,
                  v38[1],
                  v37);
                v27 = -*v38;
              }
              else
              {
                v27 = 0;
              }
              goto LABEL_55;
            }
            v27 = v29;
            v31 = cnss_ipc_log_context;
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
            v33 = "Fail to wait for response of QDSS trace mem info request, err %d\n";
          }
        }
        cnss_debug_ipc_log_print(v31, v32, "cnss_wlfw_qdss_trace_mem_info_send_sync", 3u, 3u, v33, v27, v26, v37);
LABEL_55:
        kfree(v12);
        goto LABEL_60;
      }
      v18 = 0;
      v19 = 0;
      v10 = "cnss_wlfw_qdss_trace_mem_info_send_sync";
      v20 = (int *)(v39 + 4180);
      while ( 1 )
      {
        v21 = "irq";
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            v21 = "soft_irq";
          else
            v21 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v21,
          "cnss_wlfw_qdss_trace_mem_info_send_sync",
          7u,
          7u,
          "Memory for FW, va: 0x%pK, pa: %pa, size: 0x%zx, type: %u\n",
          *(_QWORD *)(v20 - 5),
          (__int64)(v20 - 3),
          *(_QWORD *)(v20 - 7));
        if ( v18 == 312 )
          break;
        *(_QWORD *)&v12[v18 + 2] = *(_QWORD *)(v20 - 3);
        v12[v18 + 4] = *(_QWORD *)(v20 - 7);
        if ( (unsigned __int64)(v18 * 4 - 1245) < 0xFFFFFFFFFFFFFB0FLL )
        {
          __break(1u);
          break;
        }
        v22 = (unsigned int)*v12;
        v23 = *v20;
        v20 += 10;
        ++v19;
        v24 = &v12[v18];
        v18 += 6;
        v24[5] = v23;
        if ( v19 >= v22 )
          goto LABEL_21;
      }
      __break(0x5512u);
      v34 = *(_QWORD *)(v9 + 80);
      *(_QWORD *)(v9 + 80) = &cnss_wlfw_qdss_trace_mem_info_send_sync__alloc_tag;
      v12 = (_DWORD *)_kmalloc_cache_noprof(of_find_device_by_node, 3520, 1264);
      *(_QWORD *)(v9 + 80) = v34;
      if ( !v12 )
        goto LABEL_58;
    }
    v27 = -12;
    v15 = v12;
LABEL_60:
    kfree(v15);
  }
  else
  {
LABEL_58:
    v27 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v27;
}
