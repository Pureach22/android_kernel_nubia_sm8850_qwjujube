__int64 __fastcall wlfw_cap_send_sync_msg(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x20
  unsigned __int16 *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w22
  __int64 v7; // x22
  __int64 v8; // x0
  unsigned int v9; // w0
  int v10; // w2
  int v11; // w9
  int v12; // w9
  int v13; // w8
  int v14; // w9
  size_t v15; // x0
  unsigned __int64 v16; // x2
  int v17; // w2
  __int64 v18; // x0
  size_t v19; // x0
  unsigned __int64 v20; // x2
  int v21; // w8
  char v22; // w8
  bool v23; // zf
  const char *v24; // x2
  const char *v25; // x23
  int v26; // w3
  __int64 v27; // x3
  __int64 v28; // x4
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x3
  __int64 v34; // x4
  __int64 v35; // x2
  unsigned __int64 StatusReg; // x21
  __int64 v37; // x22
  __int64 (__fastcall *v38)(_QWORD); // x0
  _QWORD v40[10]; // [xsp+0h] [xbp-50h] BYREF

  v40[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v6 = -19;
    goto LABEL_74;
  }
  v2 = *(_QWORD *)(a1 + 1832);
  memset(v40, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending target capability message, state: 0x%lx\n", v2);
  v3 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 1);
  if ( !v3 )
    goto LABEL_73;
  while ( 1 )
  {
    v4 = (unsigned __int16 *)_kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 2344);
    if ( !v4 )
      break;
    ++*(_DWORD *)(a1 + 2604);
    v5 = qmi_txn_init(a1 + 624, v40, &wlfw_cap_resp_msg_v01_ei, v4);
    if ( (v5 & 0x80000000) != 0 )
    {
      v6 = v5;
      v25 = "%sicnss2_qmi: fatal: Fail to init txn for Capability resp %d\n";
      printk("%sicnss2_qmi: fatal: Fail to init txn for Capability resp %d\n", byte_130B32, v5);
LABEL_58:
      ipc_log_string(icnss_ipc_log_context, v25, &unk_12DBF3, v6);
LABEL_59:
      kfree(v4);
      kfree(v3);
      ++*(_DWORD *)(a1 + 2612);
      goto LABEL_74;
    }
    v6 = qmi_send_request(a1 + 624, 0, v40, 36, 0, &wlfw_cap_req_msg_v01_ei, v3);
    if ( (v6 & 0x80000000) != 0 )
    {
      qmi_txn_cancel(v40);
      v25 = "%sicnss2_qmi: fatal: Fail to send Capability req %d\n";
      printk("%sicnss2_qmi: fatal: Fail to send Capability req %d\n", byte_130B32, v6);
      goto LABEL_58;
    }
    v7 = *(unsigned int *)(a1 + 336);
    v8 = _msecs_to_jiffies(*(unsigned int *)(a1 + 5780));
    v9 = qmi_txn_wait(v40, v8 + v7);
    if ( (v9 & 0x80000000) != 0 )
    {
      v6 = v9;
      v25 = "%sicnss2_qmi: fatal: Capability resp wait failed with ret %d\n";
      printk("%sicnss2_qmi: fatal: Capability resp wait failed with ret %d\n", byte_130B32, v9);
      goto LABEL_58;
    }
    v10 = *v4;
    if ( *v4 )
    {
      v26 = v4[1];
      v6 = -v10;
      if ( v26 == 119 )
      {
        printk("%sicnss2_qmi: RF card not present\n", byte_130B32);
        ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: RF card not present\n", (const char *)&unk_12DBF3);
      }
      else
      {
        printk("%sicnss2_qmi: fatal: QMI Capability request rejected, result:%d error:%d\n", byte_130B32, v10, v26);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: fatal: QMI Capability request rejected, result:%d error:%d\n",
          (const char *)&unk_12DBF3,
          *v4,
          v4[1]);
      }
      goto LABEL_59;
    }
    v11 = *((unsigned __int8 *)v4 + 4);
    ++*(_DWORD *)(a1 + 2608);
    if ( v11 )
    {
      v12 = *((_DWORD *)v4 + 3);
      *(_DWORD *)(a1 + 1840) = *((_DWORD *)v4 + 2);
      *(_DWORD *)(a1 + 1844) = v12;
    }
    if ( *((_BYTE *)v4 + 16) )
      v13 = *((_DWORD *)v4 + 5);
    else
      v13 = 255;
    v14 = *((unsigned __int8 *)v4 + 24);
    *(_DWORD *)(a1 + 1848) = v13;
    if ( v14 )
      *(_DWORD *)(a1 + 1852) = *((_DWORD *)v4 + 7);
    if ( *((_BYTE *)v4 + 32) )
    {
      *(_DWORD *)(a1 + 1856) = *((_DWORD *)v4 + 9);
      v15 = strnlen((const char *)v4 + 40, 0x21u);
      if ( v15 >= 0x22 )
      {
        _fortify_panic(2, 33, v15 + 1);
LABEL_68:
        v19 = _fortify_panic(7, 33, v16);
LABEL_69:
        _fortify_panic(2, 129, v19 + 1);
        goto LABEL_70;
      }
      if ( v15 == 33 )
        v16 = 33;
      else
        v16 = v15 + 1;
      if ( v16 >= 0x22 )
        goto LABEL_68;
      sized_strscpy(a1 + 1860, v4 + 20);
    }
    if ( !*((_BYTE *)v4 + 264) )
    {
      if ( !*((_BYTE *)v4 + 208) )
        goto LABEL_26;
LABEL_25:
      v17 = *((_DWORD *)v4 + 53);
      v18 = icnss_ipc_log_context;
      *(_DWORD *)(a1 + 296) = v17;
      ipc_log_string(v18, "icnss2_qmi: Voltage for CPR: %dmV\n", v17);
      icnss_update_cpr_info(a1);
      goto LABEL_26;
    }
    v27 = *((_QWORD *)v4 + 34);
    v28 = *((_QWORD *)v4 + 35);
    *(_QWORD *)(a1 + 2080) = v27;
    *(_QWORD *)(a1 + 2088) = v28;
    printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n", byte_13289B, 0, v27, v28);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      (const char *)&unk_12DBF3,
      0,
      *(_QWORD *)(a1 + 2080),
      *(_QWORD *)(a1 + 2088));
    v29 = *((_QWORD *)v4 + 36);
    v30 = *((_QWORD *)v4 + 37);
    *(_QWORD *)(a1 + 2096) = v29;
    *(_QWORD *)(a1 + 2104) = v30;
    printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n", byte_13289B, 1, v29, v30);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      (const char *)&unk_12DBF3,
      1,
      *(_QWORD *)(a1 + 2096),
      *(_QWORD *)(a1 + 2104));
    v31 = *((_QWORD *)v4 + 38);
    v32 = *((_QWORD *)v4 + 39);
    *(_QWORD *)(a1 + 2112) = v31;
    *(_QWORD *)(a1 + 2120) = v32;
    printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n", byte_13289B, 2, v31, v32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      (const char *)&unk_12DBF3,
      2,
      *(_QWORD *)(a1 + 2112),
      *(_QWORD *)(a1 + 2120));
    v33 = *((_QWORD *)v4 + 40);
    v34 = *((_QWORD *)v4 + 41);
    *(_QWORD *)(a1 + 2128) = v33;
    *(_QWORD *)(a1 + 2136) = v34;
    printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n", byte_13289B, 3, v33, v34);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
      (const char *)&unk_12DBF3,
      3,
      *(_QWORD *)(a1 + 2128),
      *(_QWORD *)(a1 + 2136));
    if ( *((_BYTE *)v4 + 208) )
      goto LABEL_25;
LABEL_26:
    if ( !*((_BYTE *)v4 + 76) )
      goto LABEL_33;
    v19 = strnlen((const char *)v4 + 77, 0x81u);
    if ( v19 >= 0x82 )
      goto LABEL_69;
    if ( v19 == 129 )
      v20 = 129;
    else
      v20 = v19 + 1;
    if ( v20 < 0x82 )
    {
      sized_strscpy(a1 + 1896, (char *)v4 + 77);
LABEL_33:
      if ( *((_BYTE *)v4 + 256) )
      {
        v21 = *((_DWORD *)v4 + 65);
        *(_DWORD *)(a1 + 6100) = v21;
        if ( v21 == 1 )
          *(_BYTE *)(a1 + 5640) = 0;
      }
      if ( *((_BYTE *)v4 + 336) )
      {
        v22 = *((_BYTE *)v4 + 337);
        goto LABEL_38;
      }
      if ( *((_BYTE *)v4 + 4) && *(_DWORD *)(a1 + 1840) == 17184 )
      {
        v22 = 117;
LABEL_38:
        *(_BYTE *)(a1 + 5844) = v22;
      }
      if ( *((_BYTE *)v4 + 1154) )
        *(_DWORD *)(a1 + 6104) = *((_DWORD *)v4 + 289);
      if ( *((_BYTE *)v4 + 1160) )
        *(_DWORD *)(a1 + 6108) = *((_DWORD *)v4 + 291);
      if ( *((_BYTE *)v4 + 240) )
      {
        *(_BYTE *)(a1 + 5448) = (v4[124] & 4) != 0;
        ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: FW supports aux uc support capability");
        v23 = (*((_QWORD *)v4 + 31) & 2LL) == 0;
        *(_BYTE *)(a1 + 6152) = (*((_QWORD *)v4 + 31) & 2uLL) >> 1;
        if ( v23 )
          v24 = "does not support";
        else
          v24 = "supports";
        ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: FW %s direct link", v24);
      }
      if ( *((_BYTE *)v4 + 1168) )
      {
        v35 = *(_QWORD *)(v4 + 586);
        *(_QWORD *)(a1 + 6128) = v35;
        printk("%sicnss2_qmi: serial id  0x%x 0x%x\n", byte_13289B, v35, HIDWORD(v35));
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: serial id  0x%x 0x%x\n",
          (const char *)&unk_12DBF3,
          *((_DWORD *)v4 + 293),
          *((_DWORD *)v4 + 294));
        if ( *((_BYTE *)v4 + 240) )
LABEL_50:
          *(_QWORD *)(a1 + 6272) = *((_QWORD *)v4 + 31);
      }
      else if ( *((_BYTE *)v4 + 240) )
      {
        goto LABEL_50;
      }
      ipc_log_string(
        icnss_ipc_log_context,
        "icnss2_qmi: Capability, chip_id: 0x%x, chip_family: 0x%x, board_id: 0x%x, soc_id: 0x%x",
        *(_DWORD *)(a1 + 1840),
        *(_DWORD *)(a1 + 1844),
        *(_DWORD *)(a1 + 1848),
        *(_DWORD *)(a1 + 1852));
      ipc_log_string(
        icnss_ipc_log_context,
        "icnss2_qmi: fw_version: 0x%x, fw_build_timestamp: %s,\t\t     fw_build_id: %s, fw_caps: 0x%llx",
        *(_DWORD *)(a1 + 1856),
        (const char *)(a1 + 1860),
        (const char *)(a1 + 1896),
        *(_QWORD *)(a1 + 6272));
      ipc_log_string(
        icnss_ipc_log_context,
        "icnss2_qmi: RD card chain cap: %d, PHY HE channel width cap: %d, PHY QAM cap: %d",
        *(_DWORD *)(a1 + 6100),
        *(_DWORD *)(a1 + 6104),
        *(_DWORD *)(a1 + 6108));
      kfree(v4);
      kfree(v3);
      v6 = 0;
      goto LABEL_74;
    }
LABEL_70:
    _fortify_panic(7, 129, v20);
    StatusReg = _ReadStatusReg(SP_EL0);
    v37 = *(_QWORD *)(StatusReg + 80);
    v38 = pm_stay_awake;
    *(_QWORD *)(StatusReg + 80) = &wlfw_cap_send_sync_msg__alloc_tag;
    v3 = _kmalloc_cache_noprof(v38, 3520, 1);
    *(_QWORD *)(StatusReg + 80) = v37;
    if ( !v3 )
      goto LABEL_73;
  }
  kfree(v3);
LABEL_73:
  v6 = -12;
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return v6;
}
