__int64 __fastcall cnss_wlfw_qdss_data_send_sync(
        __int64 a1,
        unsigned __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x26
  unsigned __int64 v10; // x23
  const char *v14; // x1
  _DWORD *v15; // x19
  unsigned __int16 *v16; // x20
  __int64 v17; // x9
  __int64 v18; // x0
  int v19; // w8
  const char *v20; // x1
  const char *v21; // x1
  char *v22; // x21
  unsigned int v23; // w0
  __int64 v24; // x6
  __int64 v25; // x7
  int v26; // w9
  const char *v27; // x1
  unsigned int v28; // w27
  unsigned int v29; // w0
  int v30; // w8
  const char *v31; // x1
  size_t v32; // x2
  size_t v33; // x1
  __int64 v34; // x8
  __int64 v35; // x21
  __int64 v36; // x7
  const char *v37; // x1
  const char *v38; // x1
  const char *v39; // x1
  const char *v40; // x1
  __int64 v41; // x0
  const char *v42; // x1
  const char *v43; // x5
  __int64 v44; // x20
  __int64 (__fastcall *v45)(_QWORD, _QWORD, _QWORD); // x0
  const char *v46; // x1
  const char *v47; // x1
  char v49; // [xsp+0h] [xbp-B0h]
  char v50; // [xsp+0h] [xbp-B0h]
  const char *v51; // [xsp+38h] [xbp-78h]
  __int64 v52; // [xsp+48h] [xbp-68h]
  _QWORD v53[11]; // [xsp+58h] [xbp-58h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = (unsigned __int64)&off_5B000;
  v10 = _ReadStatusReg(SP_EL0);
  v53[9] = *(_QWORD *)(StatusReg + 1808);
  memset(v53, 0, 72);
  if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
  {
    v14 = "irq";
  }
  else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    v14 = "soft_irq";
  }
  else
  {
    v14 = (const char *)(v10 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v14,
    "cnss_wlfw_qdss_data_send_sync",
    7u,
    7u,
    "%s\n",
    (__int64)"cnss_wlfw_qdss_data_send_sync",
    a8,
    v49);
  v15 = (_DWORD *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( !v15 )
    goto LABEL_97;
  while ( 1 )
  {
    v16 = (unsigned __int16 *)_kmalloc_cache_noprof(put_device, 3520, 6176);
    if ( !v16 )
      break;
    v17 = vzalloc_noprof(a3);
    v18 = *(_QWORD *)(v9 + 3920);
    v19 = *(_DWORD *)(v10 + 16) & 0xF0000;
    if ( !v17 )
    {
      if ( v19 )
      {
        v21 = "irq";
      }
      else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
      {
        v21 = "soft_irq";
      }
      else
      {
        v21 = (const char *)(v10 + 2320);
      }
      cnss_debug_ipc_log_print(
        v18,
        v21,
        "cnss_wlfw_qdss_data_send_sync",
        3u,
        3u,
        "%s: failed to allocate qdss trace data: %zu\n",
        (__int64)"cnss_wlfw_qdss_data_send_sync",
        a3,
        v50);
      v28 = 12;
LABEL_95:
      kfree(v15);
      kfree(v16);
      goto LABEL_110;
    }
    v51 = (const char *)a2;
    v52 = v17;
    if ( v19 )
    {
      v20 = "irq";
    }
    else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
    {
      v20 = "soft_irq";
    }
    else
    {
      v20 = (const char *)(v10 + 2320);
    }
    cnss_debug_ipc_log_print(
      v18,
      v20,
      "cnss_wlfw_qdss_data_send_sync",
      7u,
      7u,
      "qdss trace data of total size %u and response end at %u\n",
      a3,
      *((unsigned __int8 *)v16 + 6173),
      v50);
    if ( !a3 )
    {
LABEL_43:
      if ( *((_BYTE *)v16 + 6172) && *((_BYTE *)v16 + 6173) )
      {
        v35 = v52;
        v28 = cnss_genl_send_msg(v52, 1u, v51, a3);
        if ( (v28 & 0x80000000) != 0 )
        {
          if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
          {
            v37 = "irq";
          }
          else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          {
            v37 = "soft_irq";
          }
          else
          {
            v37 = (const char *)(v10 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v37,
            "cnss_wlfw_qdss_data_send_sync",
            3u,
            3u,
            "Fail to save QDSS trace data: %d\n",
            v28,
            v36,
            v50);
          v28 = -1;
        }
      }
      else
      {
        LODWORD(v9) = 0;
LABEL_51:
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v39 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v39 = "soft_irq";
        }
        else
        {
          v39 = (const char *)(v10 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v39,
          "cnss_wlfw_qdss_data_send_sync",
          3u,
          3u,
          "%s: QDSS trace file corrupted: remaining %u, end_valid %u, end %u",
          (__int64)"cnss_wlfw_qdss_data_send_sync",
          (unsigned int)v9,
          *((_BYTE *)v16 + 6172));
        v35 = v52;
        v28 = -1;
      }
LABEL_94:
      vfree(v35);
      goto LABEL_95;
    }
    v22 = (char *)v52;
    a2 = 0;
    v9 = a3;
    while ( 1 )
    {
      if ( *((_BYTE *)v16 + 6173) )
        goto LABEL_51;
      v23 = qmi_txn_init(a1 + 856, v53, &wlfw_qdss_trace_data_resp_msg_v01_ei);
      v26 = *(_DWORD *)(v10 + 16) & 0xF0000;
      if ( (v23 & 0x80000000) != 0 )
      {
        v28 = v23;
        if ( v26 )
        {
          v40 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v40 = "soft_irq";
        }
        else
        {
          v40 = (const char *)(v10 + 2320);
        }
        v35 = v52;
        v43 = "Fail to init txn for QDSS trace resp %d\n";
        v41 = cnss_ipc_log_context;
        goto LABEL_89;
      }
      v27 = "irq";
      if ( !v26 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          v27 = "soft_irq";
        else
          v27 = (const char *)(v10 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v27,
        "cnss_wlfw_qdss_data_send_sync",
        7u,
        7u,
        "sending qdss trace qmi data req\n",
        v24,
        v25,
        v50);
      v28 = qmi_send_request(a1 + 856, 0, v53, 66, 7, &wlfw_qdss_trace_data_req_msg_v01_ei, v15);
      if ( (v28 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v53);
        v41 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v40 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v40 = "soft_irq";
        }
        else
        {
          v40 = (const char *)(v10 + 2320);
        }
        v35 = v52;
        v43 = "Fail to send QDSS trace data req %d\n";
        goto LABEL_89;
      }
      v29 = qmi_txn_wait(v53, *(unsigned int *)(a1 + 6696));
      if ( (v29 & 0x80000000) != 0 )
      {
        v28 = v29;
        v41 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v40 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v40 = "soft_irq";
        }
        else
        {
          v40 = (const char *)(v10 + 2320);
        }
        v35 = v52;
        v43 = "QDSS trace resp wait failed with rc %d\n";
LABEL_89:
        cnss_debug_ipc_log_print(v41, v40, "cnss_wlfw_qdss_data_send_sync", 3u, 3u, v43, v28, v25, v50);
        goto LABEL_94;
      }
      v30 = *(_DWORD *)(v10 + 16) & 0xF0000;
      if ( *v16 )
      {
        if ( v30 )
        {
          v42 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v42 = "soft_irq";
        }
        else
        {
          v42 = (const char *)(v10 + 2320);
        }
        v35 = v52;
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v42,
          "cnss_wlfw_qdss_data_send_sync",
          3u,
          3u,
          "QMI QDSS trace request rejected, result:%d error:%d\n",
          *v16,
          v16[1],
          v50);
        v28 = -*v16;
        goto LABEL_94;
      }
      v31 = "irq";
      if ( !v30 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
          v31 = "soft_irq";
        else
          v31 = (const char *)(v10 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v31,
        "cnss_wlfw_qdss_data_send_sync",
        7u,
        7u,
        "%s: response total size  %d data len %d",
        (__int64)"cnss_wlfw_qdss_data_send_sync",
        *((unsigned int *)v16 + 2),
        *((_DWORD *)v16 + 6));
      if ( *((_BYTE *)v16 + 4) != 1
        || *((_DWORD *)v16 + 2) != a3
        || *((_BYTE *)v16 + 12) != 1
        || *((_DWORD *)v16 + 4) != *v15
        || *((_BYTE *)v16 + 20) != 1
        || (v32 = *((unsigned int *)v16 + 6), (unsigned int)v32 > 0x1800)
        || (unsigned int)v32 > (unsigned int)v9 )
      {
        if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
        {
          v38 = "irq";
        }
        else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
        {
          v38 = "soft_irq";
        }
        else
        {
          v38 = (const char *)(v10 + 2320);
        }
        v35 = v52;
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v38,
          "cnss_wlfw_qdss_data_send_sync",
          3u,
          3u,
          "%s: Unmatched qdss trace data, Expect total_size %u, seg_id %u, Recv total_size_valid %u, total_size %u, seg_i"
          "d_valid %u, seg_id %u, data_len_valid %u, data_len %u",
          (__int64)"cnss_wlfw_qdss_data_send_sync",
          a3,
          *v15);
        v28 = -1;
        goto LABEL_94;
      }
      v33 = a3 >= a2 ? a3 - a2 : 0LL;
      if ( v33 < v32 )
        break;
      memcpy(v22, v16 + 14, v32);
      v34 = *((unsigned int *)v16 + 6);
      v9 = (unsigned int)(v9 - v34);
      a2 += v34;
      v22 += v34;
      ++*v15;
      if ( !(_DWORD)v9 )
        goto LABEL_43;
    }
    _fortify_panic(17, v33, v32);
    v44 = *(_QWORD *)(v10 + 80);
    v45 = of_find_compatible_node;
    *(_QWORD *)(v10 + 80) = &cnss_wlfw_qdss_data_send_sync__alloc_tag;
    v15 = (_DWORD *)_kmalloc_cache_noprof(v45, 3520, 4);
    *(_QWORD *)(v10 + 80) = v44;
    if ( !v15 )
    {
LABEL_97:
      if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
      {
        v46 = "irq";
      }
      else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
      {
        v46 = "soft_irq";
      }
      else
      {
        v46 = (const char *)(v10 + 2320);
      }
      cnss_debug_ipc_log_print(
        *(_QWORD *)(v9 + 3920),
        v46,
        "cnss_wlfw_qdss_data_send_sync",
        3u,
        3u,
        "%s: failed to allocate req mem: %zu\n",
        (__int64)"cnss_wlfw_qdss_data_send_sync",
        4,
        v50);
      goto LABEL_109;
    }
  }
  if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
  {
    v47 = "irq";
  }
  else if ( (*(_DWORD *)(v10 + 16) & 0xFF00) != 0 )
  {
    v47 = "soft_irq";
  }
  else
  {
    v47 = (const char *)(v10 + 2320);
  }
  cnss_debug_ipc_log_print(
    *(_QWORD *)(v9 + 3920),
    v47,
    "cnss_wlfw_qdss_data_send_sync",
    3u,
    3u,
    "%s: failed to allocate resp mem: %zu\n",
    (__int64)"cnss_wlfw_qdss_data_send_sync",
    6176,
    v50);
  kfree(v15);
LABEL_109:
  v28 = -12;
LABEL_110:
  _ReadStatusReg(SP_EL0);
  return v28;
}
