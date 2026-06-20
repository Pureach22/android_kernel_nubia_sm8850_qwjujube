__int64 __fastcall cnss_wlfw_bdf_dnld_send_sync(__int64 a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v3; // x27
  const char *v6; // x1
  const char *v7; // x7
  __int64 v8; // x21
  __int64 v9; // x7
  unsigned __int16 *v10; // x22
  unsigned int v11; // w3
  const char *v12; // x9
  int v13; // w8
  const char *v14; // x1
  unsigned int v15; // w3
  __int64 v16; // x9
  unsigned int updated; // w23
  const char *v18; // x9
  int v19; // w8
  __int64 v20; // x7
  const char *v21; // x1
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  const char *v27; // x1
  char *v28; // x24
  unsigned int v29; // w28
  const char *v30; // x1
  int v31; // w8
  unsigned int v32; // w8
  unsigned int v33; // w0
  __int64 v34; // x0
  unsigned int v35; // w0
  __int64 v36; // x8
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x3
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  __int64 v44; // x8
  const char *v45; // x1
  __int64 v46; // x0
  const char *v47; // x1
  const char *v48; // x1
  char *v49; // x6
  const char *v50; // x5
  char v52; // [xsp+0h] [xbp-C0h]
  char v53; // [xsp+0h] [xbp-C0h]
  __int64 v54; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v55[9]; // [xsp+18h] [xbp-A8h] BYREF
  _QWORD v56[5]; // [xsp+60h] [xbp-60h] BYREF
  __int128 s; // [xsp+88h] [xbp-38h] BYREF
  __int64 v58; // [xsp+98h] [xbp-28h]
  __int64 v59; // [xsp+A0h] [xbp-20h]
  __int64 v60; // [xsp+A8h] [xbp-18h]
  __int64 v61; // [xsp+B0h] [xbp-10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = _ReadStatusReg(SP_EL0);
  v61 = *(_QWORD *)(StatusReg + 1808);
  v54 = 0;
  memset(v55, 0, sizeof(v55));
  memset(v56, 0, sizeof(v56));
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
    if ( a2 <= 6 )
    {
LABEL_3:
      v7 = (&off_5BED8)[a2];
      goto LABEL_9;
    }
  }
  else
  {
    if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      v6 = "soft_irq";
    else
      v6 = (const char *)(v3 + 2320);
    if ( a2 <= 6 )
      goto LABEL_3;
  }
  v7 = "UNKNOWN";
LABEL_9:
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "cnss_wlfw_bdf_dnld_send_sync",
    7u,
    7u,
    "Sending QMI_WLFW_BDF_DOWNLOAD_REQ_V01 message for bdf_type: %d (%s), state: 0x%lx\n",
    a2,
    (__int64)v7,
    *(_QWORD *)(a1 + 552));
  v8 = _kmalloc_cache_noprof(put_device, 3520, 6180);
  if ( !v8 )
  {
    updated = -12;
    goto LABEL_113;
  }
  v10 = (unsigned __int16 *)_kmalloc_cache_noprof(_of_parse_phandle_with_args, 3520, 16);
  if ( !v10 )
  {
    updated = -12;
    v10 = (unsigned __int16 *)v8;
    goto LABEL_112;
  }
  v59 = 0;
  v60 = 0;
  v58 = 0;
  s = 0u;
  if ( (int)a2 > 3 )
  {
    if ( a2 == 4 )
    {
      v16 = *(_QWORD *)"regdb.bin";
      WORD4(s) = 110;
      goto LABEL_41;
    }
    if ( a2 == 6 )
    {
      strcpy((char *)&s, "hds.bin");
      goto LABEL_42;
    }
    goto LABEL_20;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v11 = *(_DWORD *)(a1 + 1472);
      if ( v11 == 255 )
      {
        if ( (*(_BYTE *)(a1 + 1464) & 0x10) == 0 )
        {
          v12 = "bdwlan.elf";
          v13 = 6712421;
LABEL_25:
          v16 = *(_QWORD *)v12;
          *(_DWORD *)((char *)&s + 7) = v13;
LABEL_41:
          *(_QWORD *)&s = v16;
          goto LABEL_42;
        }
        v18 = "bdwlang.elf";
        v19 = 6712421;
        goto LABEL_40;
      }
      if ( v11 > 0xFE )
      {
        snprintf(
          (char *)&s,
          0x28u,
          "bdwlan%02x.e%02x",
          (unsigned __int8)BYTE1(*(_DWORD *)(a1 + 1472)),
          (unsigned __int8)*(_DWORD *)(a1 + 1472));
      }
      else if ( (*(_BYTE *)(a1 + 1464) & 0x10) != 0 )
      {
        snprintf((char *)&s, 0x28u, "bdwlang.e%02x");
      }
      else
      {
        snprintf((char *)&s, 0x28u, "bdwlan.e%02x");
      }
      goto LABEL_42;
    }
LABEL_20:
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
      "cnss_get_bdf_file_name",
      3u,
      3u,
      "Invalid BDF type: %d\n",
      *(unsigned int *)(a1 + 6700),
      v9,
      v52);
    updated = -22;
    goto LABEL_109;
  }
  v15 = *(_DWORD *)(a1 + 1472);
  if ( v15 == 255 )
  {
    if ( (*(_BYTE *)(a1 + 1464) & 0x10) == 0 )
    {
      v12 = "bdwlan.bin";
      v13 = 7235938;
      goto LABEL_25;
    }
    v18 = "bdwlang.bin";
    v19 = 7235938;
LABEL_40:
    v16 = *(_QWORD *)v18;
    DWORD2(s) = v19;
    goto LABEL_41;
  }
  if ( v15 > 0xFE )
  {
    snprintf(
      (char *)&s,
      0x28u,
      "bdwlan%02x.b%02x",
      (unsigned __int8)BYTE1(*(_DWORD *)(a1 + 1472)),
      (unsigned __int8)*(_DWORD *)(a1 + 1472));
  }
  else if ( (*(_BYTE *)(a1 + 1464) & 0x10) != 0 )
  {
    snprintf((char *)&s, 0x28u, "bdwlang.b%02x");
  }
  else
  {
    snprintf((char *)&s, 0x28u, "bdwlan.b%02x");
  }
LABEL_42:
  cnss_bus_add_fw_prefix_name(a1);
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v21 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v21 = "soft_irq";
  }
  else
  {
    v21 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v21,
    "cnss_wlfw_bdf_dnld_send_sync",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v56,
    v20,
    v52);
  if ( a2 == 4 )
  {
    updated = cnss_request_firmware_direct((_QWORD *)a1, (__int64)&v54, (__int64)v56, v22, v23, v24, v25, v26);
    if ( updated )
    {
LABEL_49:
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v27 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v27 = "soft_irq";
      }
      else
      {
        v27 = (const char *)(v3 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v27,
        "cnss_wlfw_bdf_dnld_send_sync",
        3u,
        3u,
        "Failed to load %s: %s, ret: %d\n",
        (__int64)(&off_5BED8)[a2],
        (__int64)v56,
        updated);
      goto LABEL_109;
    }
  }
  else
  {
    updated = cnss_request_firmware_update_timer((_QWORD *)a1, (__int64)&v54, (__int64)v56);
    if ( updated )
      goto LABEL_49;
  }
  v28 = *(char **)(v54 + 8);
  v29 = *(_DWORD *)v54;
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v30 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v30 = "soft_irq";
  }
  else
  {
    v30 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v30,
    "cnss_wlfw_bdf_dnld_send_sync",
    7u,
    7u,
    "Downloading %s: %s, size: %u\n",
    (__int64)(&off_5BED8)[a2],
    (__int64)v56,
    v29);
  if ( !v29 )
  {
LABEL_70:
    release_firmware(v54);
    if ( *((_BYTE *)v10 + 4) )
    {
      v44 = *((_QWORD *)v10 + 1);
      if ( (v44 & 1) == 0 )
      {
        cnss_enable_int_pow_amp_vreg((__int64 *)a1, v37, v38, v39, v40, v41, v42, v43);
        v44 = *((_QWORD *)v10 + 1);
      }
      *(_BYTE *)(a1 + 4104) = (v44 & 2) != 0;
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v45 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v45 = "soft_irq";
      }
      else
      {
        v45 = (const char *)(v3 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v45,
        "cnss_wlfw_bdf_dnld_send_sync",
        6u,
        6u,
        "Host BDF config: HW_XPA: %d CalDB: %d\n",
        v44 & 1,
        ((unsigned int)v44 >> 1) & 1,
        v53);
    }
    updated = 0;
    goto LABEL_109;
  }
  while ( 1 )
  {
    *(_BYTE *)(v8 + 8) = 1;
    *(_WORD *)v8 = 257;
    v31 = *(_DWORD *)(a1 + 1472);
    *(_DWORD *)(v8 + 12) = v29;
    *(_DWORD *)(v8 + 4) = v31;
    *(_BYTE *)(v8 + 16) = 1;
    *(_BYTE *)(v8 + 24) = 1;
    *(_BYTE *)(v8 + 6176) = 1;
    *(_BYTE *)(v8 + 6178) = 1;
    *(_BYTE *)(v8 + 6179) = a2;
    if ( v29 < 0x1801 )
    {
      v32 = v29;
      *(_DWORD *)(v8 + 28) = v29;
      *(_BYTE *)(v8 + 6177) = 1;
    }
    else
    {
      v32 = 6144;
      *(_DWORD *)(v8 + 28) = 6144;
    }
    memcpy((void *)(v8 + 32), v28, v32);
    v33 = qmi_txn_init(a1 + 856, v55, &wlfw_bdf_download_resp_msg_v01_ei);
    if ( (v33 & 0x80000000) != 0 )
    {
      updated = v33;
      v46 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v47 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v47 = "soft_irq";
      }
      else
      {
        v47 = (const char *)(v3 + 2320);
      }
      v49 = (&off_5BED8)[a2];
      v50 = "Failed to initialize txn for QMI_WLFW_BDF_DOWNLOAD_REQ_V01 request for %s, error: %d\n";
      goto LABEL_103;
    }
    updated = qmi_send_request(a1 + 856, 0, v55, 37, 6182, &wlfw_bdf_download_req_msg_v01_ei, v8);
    if ( (updated & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v55);
      v46 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v47 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v47 = "soft_irq";
      }
      else
      {
        v47 = (const char *)(v3 + 2320);
      }
      v49 = (&off_5BED8)[a2];
      v50 = "Failed to send QMI_WLFW_BDF_DOWNLOAD_REQ_V01 request for %s, error: %d\n";
      goto LABEL_103;
    }
    v34 = _msecs_to_jiffies(*(unsigned int *)(a1 + 6696));
    v35 = qmi_txn_wait(v55, v34);
    if ( (v35 & 0x80000000) != 0 )
    {
      updated = v35;
      v46 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
      {
        v47 = "irq";
      }
      else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
      {
        v47 = "soft_irq";
      }
      else
      {
        v47 = (const char *)(v3 + 2320);
      }
      v49 = (&off_5BED8)[a2];
      v50 = "Timeout while waiting for FW response for QMI_WLFW_BDF_DOWNLOAD_REQ_V01 request for %s, err: %d\n";
LABEL_103:
      cnss_debug_ipc_log_print(v46, v47, "cnss_wlfw_bdf_dnld_send_sync", 3u, 3u, v50, (__int64)v49, updated, v53);
      goto LABEL_108;
    }
    if ( *v10 )
      break;
    v36 = *(unsigned int *)(v8 + 28);
    v29 -= v36;
    v28 += v36;
    ++*(_DWORD *)(v8 + 20);
    if ( !v29 )
      goto LABEL_70;
  }
  if ( (*(_DWORD *)(v3 + 16) & 0xF0000) != 0 )
  {
    v48 = "irq";
  }
  else if ( (*(_DWORD *)(v3 + 16) & 0xFF00) != 0 )
  {
    v48 = "soft_irq";
  }
  else
  {
    v48 = (const char *)(v3 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v48,
    "cnss_wlfw_bdf_dnld_send_sync",
    3u,
    3u,
    "FW response for QMI_WLFW_BDF_DOWNLOAD_REQ_V01 request for %s failed, result: %d, err: %d\n",
    (__int64)(&off_5BED8)[a2],
    *v10,
    v10[1]);
  updated = -*v10;
LABEL_108:
  release_firmware(v54);
LABEL_109:
  kfree(v8);
LABEL_112:
  kfree(v10);
LABEL_113:
  _ReadStatusReg(SP_EL0);
  return updated;
}
