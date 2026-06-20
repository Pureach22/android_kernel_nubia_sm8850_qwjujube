__int64 __fastcall cnss_wlfw_qdss_dnld_send_sync(
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
  unsigned __int64 v9; // x27
  const char *v11; // x1
  __int64 v12; // x19
  unsigned __int16 *v13; // x20
  const char *v14; // x4
  __int64 v15; // x7
  const char *v16; // x1
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  unsigned int v22; // w0
  char *v23; // x1
  int v24; // w8
  char *v25; // x4
  __int64 v26; // x7
  char *v27; // x1
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x5
  __int64 v31; // x6
  __int64 v32; // x7
  unsigned int v33; // w0
  unsigned int v34; // w22
  const char *v35; // x1
  char *v36; // x23
  unsigned int v37; // w24
  const char *v38; // x1
  unsigned int v39; // w8
  unsigned int v40; // w0
  __int64 v41; // x7
  unsigned int v42; // w0
  __int64 v43; // x8
  __int64 v44; // x0
  const char *v45; // x1
  const char *v46; // x1
  const char *v47; // x5
  __int64 v49; // [xsp+0h] [xbp-B0h] BYREF
  _QWORD v50[9]; // [xsp+8h] [xbp-A8h] BYREF
  _QWORD v51[5]; // [xsp+50h] [xbp-60h] BYREF
  char s[8]; // [xsp+78h] [xbp-38h] BYREF
  __int64 v53; // [xsp+80h] [xbp-30h]
  __int64 v54; // [xsp+88h] [xbp-28h]
  __int64 v55; // [xsp+90h] [xbp-20h]
  __int64 v56; // [xsp+98h] [xbp-18h]
  __int64 v57; // [xsp+A0h] [xbp-10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v57 = *(_QWORD *)(StatusReg + 1808);
  v49 = 0;
  memset(v50, 0, sizeof(v50));
  memset(v51, 0, sizeof(v51));
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
    "cnss_wlfw_qdss_dnld_send_sync",
    7u,
    7u,
    "Sending QDSS config download message, state: 0x%lx\n",
    *(_QWORD *)(a1 + 552),
    a8,
    v49);
  v12 = _kmalloc_cache_noprof(put_device, 3520, 6172);
  if ( !v12 )
  {
    v34 = -12;
    goto LABEL_82;
  }
  v13 = (unsigned __int16 *)_kmalloc_cache_noprof(of_find_compatible_node, 3520, 4);
  if ( !v13 )
  {
    v34 = -12;
    v13 = (unsigned __int16 *)v12;
    goto LABEL_81;
  }
  if ( *(_DWORD *)(a1 + 512) == 2 )
    v14 = "v2";
  else
    v14 = "v1";
  v55 = 0;
  v56 = 0;
  v53 = 0;
  v54 = 0;
  *(_QWORD *)s = 0;
  snprintf(s, 0x28u, "qdss_trace_config_%s%s.cfg", "perf_", v14);
  cnss_bus_add_fw_prefix_name(a1);
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
    "cnss_wlfw_qdss_dnld_send_sync",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v51,
    v15,
    v49);
  v22 = cnss_request_firmware_direct((_QWORD *)a1, (__int64)&v49, (__int64)v51, v17, v18, v19, v20, v21);
  if ( v22 )
  {
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      v23 = "irq";
    else
      v23 = (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v9 + 2320);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_wlfw_qdss_dnld_send_sync",
      7u,
      7u,
      "Unable to load %s ret %d, try default file\n",
      (__int64)v51,
      v22,
      v49);
    v24 = *(_DWORD *)(a1 + 512);
    v55 = 0;
    v56 = 0;
    v25 = v24 == 2 ? "v2" : "v1";
    v53 = 0;
    v54 = 0;
    *(_QWORD *)s = 0;
    snprintf(s, 0x28u, "qdss_trace_config_%s%s.cfg", &unk_4DEF5, v25);
    cnss_bus_add_fw_prefix_name(a1);
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      v27 = "irq";
    else
      v27 = (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v9 + 2320);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v27,
      "cnss_wlfw_qdss_dnld_send_sync",
      7u,
      7u,
      "Invoke firmware_request_nowarn for %s\n",
      (__int64)v51,
      v26,
      v49);
    v33 = cnss_request_firmware_direct((_QWORD *)a1, (__int64)&v49, (__int64)v51, v28, v29, v30, v31, v32);
    if ( v33 )
    {
      v34 = v33;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
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
        "cnss_wlfw_qdss_dnld_send_sync",
        3u,
        3u,
        "Unable to load %s ret %d\n",
        (__int64)v51,
        v33,
        v49);
      goto LABEL_78;
    }
  }
  v36 = *(char **)(v49 + 8);
  v37 = *(_DWORD *)v49;
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
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v38,
    "cnss_wlfw_qdss_dnld_send_sync",
    7u,
    7u,
    "Downloading QDSS: %s, size: %u\n",
    (__int64)v51,
    v37,
    v49);
  if ( !v37 )
  {
LABEL_47:
    release_firmware(v49);
    v34 = 0;
    goto LABEL_78;
  }
  while ( 1 )
  {
    *(_BYTE *)v12 = 1;
    *(_DWORD *)(v12 + 4) = v37;
    *(_BYTE *)(v12 + 8) = 1;
    *(_BYTE *)(v12 + 16) = 1;
    *(_BYTE *)(v12 + 6168) = 1;
    if ( v37 < 0x1801 )
    {
      v39 = v37;
      *(_DWORD *)(v12 + 20) = v37;
      *(_BYTE *)(v12 + 6169) = 1;
    }
    else
    {
      v39 = 6144;
      *(_DWORD *)(v12 + 20) = 6144;
    }
    memcpy((void *)(v12 + 24), v36, v39);
    v40 = qmi_txn_init(a1 + 856, v50, &wlfw_qdss_trace_config_download_resp_msg_v01_ei);
    if ( (v40 & 0x80000000) != 0 )
    {
      v34 = v40;
      v44 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v45 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v45 = "soft_irq";
      }
      else
      {
        v45 = (const char *)(v9 + 2320);
      }
      v47 = "Failed to initialize txn for QDSS download request, err: %d\n";
      goto LABEL_72;
    }
    v34 = qmi_send_request(a1 + 856, 0, v50, 68, 6167, &wlfw_qdss_trace_config_download_req_msg_v01_ei, v12);
    if ( (v34 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v50);
      v44 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v45 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v45 = "soft_irq";
      }
      else
      {
        v45 = (const char *)(v9 + 2320);
      }
      v47 = "Failed to send respond QDSS download request, err: %d\n";
      goto LABEL_72;
    }
    v42 = qmi_txn_wait(v50, *(unsigned int *)(a1 + 6696));
    if ( (v42 & 0x80000000) != 0 )
    {
      v34 = v42;
      v44 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v45 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v45 = "soft_irq";
      }
      else
      {
        v45 = (const char *)(v9 + 2320);
      }
      v47 = "Failed to wait for response of QDSS download request, err: %d\n";
LABEL_72:
      cnss_debug_ipc_log_print(v44, v45, "cnss_wlfw_qdss_dnld_send_sync", 3u, 3u, v47, v34, v41, v49);
      goto LABEL_77;
    }
    if ( *v13 )
      break;
    v43 = *(unsigned int *)(v12 + 20);
    v37 -= v43;
    v36 += v43;
    ++*(_DWORD *)(v12 + 12);
    if ( !v37 )
      goto LABEL_47;
  }
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v46 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v46 = "soft_irq";
  }
  else
  {
    v46 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v46,
    "cnss_wlfw_qdss_dnld_send_sync",
    3u,
    3u,
    "QDSS download request failed, result: %d, err: %d\n",
    *v13,
    v13[1],
    v49);
  v34 = -*v13;
LABEL_77:
  release_firmware(v49);
LABEL_78:
  kfree(v12);
LABEL_81:
  kfree(v13);
LABEL_82:
  _ReadStatusReg(SP_EL0);
  return v34;
}
