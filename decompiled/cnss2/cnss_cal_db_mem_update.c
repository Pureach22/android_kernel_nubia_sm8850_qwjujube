__int64 __fastcall cnss_cal_db_mem_update(__int64 a1, int a2, _DWORD *a3)
{
  int qmi_timeout; // w0
  __int64 v7; // x6
  __int64 v8; // x7
  unsigned __int64 v9; // x22
  int v10; // w25
  char *v11; // x1
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  __int64 v15; // x0
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  __int64 result; // x0
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x5
  __int64 v23; // x0
  unsigned __int64 v24; // x8
  int v25; // w9
  const char *v26; // x1
  unsigned __int64 v27; // x8
  const char *v28; // x1
  const char *v29; // x1
  __int16 v30; // w9
  const char *v31; // x8
  __int16 v32; // w9
  const char *v33; // x8
  int v34; // w0
  __int16 v35; // w9
  const char *v36; // x8
  unsigned __int64 v37; // x9
  int v38; // w10
  const char *v39; // x1
  __int16 v40; // w8
  const char *v41; // x9
  const char *v42; // x7
  const char *v43; // x5
  unsigned int v44; // w3
  unsigned int v45; // w4
  __int16 v46; // w8
  const char *v47; // x9
  __int64 v48; // x7
  const char *v49; // x1
  char v50; // [xsp+0h] [xbp-10h]
  char v51; // [xsp+0h] [xbp-10h]
  char v52; // [xsp+0h] [xbp-10h]

  qmi_timeout = cnss_get_qmi_timeout(a1);
  if ( (*(_BYTE *)(a1 + 4104) & 1) == 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v18;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v13,
             "cnss_cal_db_mem_update",
             6u,
             6u,
             "CAL DB file not required as per BDF\n",
             v7,
             v8,
             v50);
  }
  if ( !*a3 )
  {
    v14 = _ReadStatusReg(SP_EL0);
    v15 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(v14 + 16);
      v21 = (const char *)(v14 + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v21;
    }
    v22 = "Invalid cal file size\n";
    return cnss_debug_ipc_log_print(v15, v16, "cnss_cal_db_mem_update", 3u, 3u, v22, v7, v8, v50);
  }
  if ( (*(_QWORD *)(a1 + 552) & 0x200000) == 0 )
  {
    v9 = _ReadStatusReg(SP_EL0);
    v10 = qmi_timeout;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      v11 = "irq";
    else
      v11 = (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 ? "soft_irq" : (char *)(v9 + 2320);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_cal_db_mem_update",
      6u,
      6u,
      "Waiting for CNSS Daemon connection\n",
      v7,
      v8,
      v50);
    v23 = _msecs_to_jiffies((unsigned int)(v10 + 30000));
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 4112, v23) )
    {
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
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v29,
        "cnss_cal_db_mem_update",
        3u,
        3u,
        "Daemon not yet connected\n",
        v7,
        v8,
        v50);
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v49 = "irq";
      }
      else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
      {
        v49 = "soft_irq";
      }
      else
      {
        v49 = (const char *)(v9 + 2320);
      }
      result = cnss_debug_ipc_log_print(
                 cnss_ipc_log_context,
                 v49,
                 "cnss_cal_db_mem_update",
                 3u,
                 3u,
                 "ASSERT at line %d\n",
                 1351,
                 v48,
                 v52);
      __break(0x800u);
      return result;
    }
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 4048) + 8LL) )
  {
    v27 = _ReadStatusReg(SP_EL0);
    v15 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v27 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else
    {
      v30 = *(_DWORD *)(v27 + 16);
      v31 = (const char *)(v27 + 2320);
      if ( (v30 & 0xFF00) != 0 )
        v16 = "soft_irq";
      else
        v16 = v31;
    }
    v22 = "CAL DB Memory not setup for FW\n";
    return cnss_debug_ipc_log_print(v15, v16, "cnss_cal_db_mem_update", 3u, 3u, v22, v7, v8, v50);
  }
  v24 = _ReadStatusReg(SP_EL0);
  v25 = *(_DWORD *)(v24 + 16) & 0xF0000;
  if ( a2 == 1 )
  {
    if ( v25 )
    {
      v26 = "irq";
    }
    else
    {
      v32 = *(_DWORD *)(v24 + 16);
      v33 = (const char *)(v24 + 2320);
      if ( (v32 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v33;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v26,
      "cnss_cal_db_mem_update",
      7u,
      7u,
      "Initiating Calibration file download to mem\n",
      v7,
      v8,
      v50);
    v34 = cnss_plat_ipc_qmi_file_download(1, "wlfw_cal_db.bin", *(_QWORD *)(*(_QWORD *)(a1 + 4048) + 8LL), a3);
  }
  else
  {
    if ( v25 )
    {
      v28 = "irq";
    }
    else
    {
      v35 = *(_DWORD *)(v24 + 16);
      v36 = (const char *)(v24 + 2320);
      if ( (v35 & 0xFF00) != 0 )
        v28 = "soft_irq";
      else
        v28 = v36;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v28,
      "cnss_cal_db_mem_update",
      7u,
      7u,
      "Initiating Calibration mem upload to file\n",
      v7,
      v8,
      v50);
    v34 = cnss_plat_ipc_qmi_file_upload(
            1,
            "wlfw_cal_db.bin",
            *(_QWORD *)(*(_QWORD *)(a1 + 4048) + 8LL),
            (unsigned int)*a3);
  }
  v37 = _ReadStatusReg(SP_EL0);
  v38 = *(_DWORD *)(v37 + 16) & 0xF0000;
  if ( v34 )
  {
    if ( v38 )
    {
      v39 = "irq";
    }
    else
    {
      v40 = *(_DWORD *)(v37 + 16);
      v41 = (const char *)(v37 + 2320);
      if ( (v40 & 0xFF00) != 0 )
        v39 = "soft_irq";
      else
        v39 = v41;
    }
    if ( a2 == 1 )
      v42 = "download";
    else
      v42 = "upload";
    v43 = "Cal DB file %s %s failure\n";
    v44 = 3;
    v45 = 3;
  }
  else
  {
    if ( v38 )
    {
      v39 = "irq";
    }
    else
    {
      v46 = *(_DWORD *)(v37 + 16);
      v47 = (const char *)(v37 + 2320);
      if ( (v46 & 0xFF00) != 0 )
        v39 = "soft_irq";
      else
        v39 = v47;
    }
    if ( a2 == 1 )
      v42 = "download";
    else
      v42 = "upload";
    v43 = "Cal DB file %s %s size %d done\n";
    v44 = 7;
    v45 = 7;
    v51 = *a3;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v39,
           "cnss_cal_db_mem_update",
           v44,
           v45,
           v43,
           (__int64)"wlfw_cal_db.bin",
           (__int64)v42,
           v51);
}
