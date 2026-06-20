__int64 __fastcall icnss_send_wlan_enable_to_fw(__int64 a1, unsigned int *a2, int a3, const char *a4)
{
  unsigned int v8; // w23
  __int64 result; // x0
  __int64 v10; // x21
  size_t v11; // x0
  unsigned __int64 v12; // x2
  unsigned int v13; // w8
  unsigned __int64 v14; // x8
  _DWORD *v15; // x10
  _DWORD *v16; // x9
  int v17; // w11
  unsigned int v18; // w8
  unsigned __int64 v19; // x8
  _DWORD *v20; // x10
  _DWORD *v21; // x9
  int v22; // w11
  __int64 v23; // x23
  unsigned int v24; // w8
  const void *v25; // x1
  void *v26; // x0
  size_t v27; // x2
  unsigned int v28; // w8
  unsigned int v29; // w8
  const void *v30; // x1
  unsigned int v31; // w8
  __int64 v32; // x2
  unsigned __int16 *v33; // x22
  unsigned int v34; // w0
  unsigned int v35; // w0
  const char *v36; // x24
  unsigned __int64 StatusReg; // x24
  __int64 v38; // x26
  _QWORD v39[10]; // [xsp+0h] [xbp-50h] BYREF

  v39[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Mode: %d, config: %pK, host_version: %s\n", a3, a2, a4);
  if ( a3 == 3 || a3 == 5 )
    goto LABEL_3;
  if ( !a2 || !a4 )
  {
    printk("%sicnss2_qmi: Invalid cfg pointer, config: %pK, host_version: %pK\n", byte_130B32, a2, a4);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Invalid cfg pointer, config: %pK, host_version: %pK\n",
      (const char *)&unk_12DBF3,
      a2,
      a4);
    v8 = -22;
    goto LABEL_4;
  }
  v10 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 2360);
  if ( !v10 )
  {
LABEL_66:
    result = 4294967284LL;
    goto LABEL_7;
  }
  while ( 1 )
  {
    *(_BYTE *)v10 = 1;
    v11 = strnlen(a4, 0x11u);
    if ( v11 != -1 )
      break;
    _fortify_panic(2, -1, 0);
LABEL_65:
    _fortify_panic(7, 17, v12);
    StatusReg = _ReadStatusReg(SP_EL0);
    v38 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &icnss_send_wlan_enable_to_fw__alloc_tag;
    v10 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 2360);
    *(_QWORD *)(StatusReg + 80) = v38;
    if ( !v10 )
      goto LABEL_66;
  }
  if ( v11 == 17 )
    v12 = 17;
  else
    v12 = v11 + 1;
  if ( v12 >= 0x12 )
    goto LABEL_65;
  sized_strscpy(v10 + 1, a4);
  v13 = *a2;
  *(_BYTE *)(v10 + 18) = 1;
  if ( v13 >= 0xD )
  {
    *(_DWORD *)(v10 + 20) = 12;
LABEL_19:
    v14 = 0;
    v15 = (_DWORD *)(v10 + 40);
    v16 = (_DWORD *)(*((_QWORD *)a2 + 1) + 8LL);
    while ( v14 != 12 )
    {
      ++v14;
      *(v15 - 4) = *(v16 - 2);
      *(v15 - 3) = *(v16 - 1);
      *(v15 - 2) = *v16;
      *(v15 - 1) = v16[1];
      v17 = v16[2];
      v16 += 6;
      *v15 = v17;
      v15 += 5;
      if ( v14 >= *(unsigned int *)(v10 + 20) )
        goto LABEL_22;
    }
LABEL_63:
    __break(0x5512u);
  }
  *(_DWORD *)(v10 + 20) = v13;
  if ( v13 )
    goto LABEL_19;
LABEL_22:
  v18 = a2[4];
  *(_BYTE *)(v10 + 264) = 1;
  if ( v18 >= 0x19 )
  {
    *(_DWORD *)(v10 + 268) = 24;
    goto LABEL_25;
  }
  *(_DWORD *)(v10 + 268) = v18;
  if ( v18 )
  {
LABEL_25:
    v19 = 0;
    v20 = (_DWORD *)(v10 + 280);
    v21 = (_DWORD *)(*((_QWORD *)a2 + 3) + 4LL);
    while ( v19 != 24 )
    {
      ++v19;
      *(v20 - 2) = *(v21 - 1);
      *(v20 - 1) = *v21;
      v22 = v21[1];
      v21 += 3;
      *v20 = v22;
      v20 += 3;
      if ( v19 >= *(unsigned int *)(v10 + 268) )
        goto LABEL_28;
    }
    goto LABEL_63;
  }
LABEL_28:
  v23 = *(_QWORD *)(a1 + 304);
  if ( v23 > 30543 )
  {
    if ( v23 != 30544 )
    {
      if ( v23 != 43981 )
        goto LABEL_47;
      v28 = a2[8];
      v25 = *((const void **)a2 + 5);
      *(_BYTE *)(v10 + 560) = 1;
      v26 = (void *)(v10 + 568);
      if ( v28 >= 0x18 )
        v28 = 24;
      v27 = 4 * v28;
      *(_DWORD *)(v10 + 564) = v28;
      goto LABEL_46;
    }
LABEL_39:
    v29 = a2[16];
    v30 = *((const void **)a2 + 9);
    *(_BYTE *)(v10 + 884) = 1;
    if ( v29 >= 0x26 )
      v29 = 38;
    *(_DWORD *)(v10 + 888) = v29;
    memcpy((void *)(v10 + 892), v30, 4 * v29);
    if ( v23 != 25680 || (*(_BYTE *)(a1 + 6272) & 0x10) == 0 )
      goto LABEL_47;
    v31 = a2[23];
    v25 = *((const void **)a2 + 12);
    v26 = (void *)(v10 + 1140);
    *(_BYTE *)(v10 + 1132) = 1;
    if ( v31 >= 0x64 )
      v31 = 100;
    *(_DWORD *)(v10 + 1136) = v31;
    v27 = 12 * v31;
LABEL_46:
    memcpy(v26, v25, v27);
    goto LABEL_47;
  }
  if ( v23 == 25680 )
    goto LABEL_39;
  if ( v23 == 26448 )
  {
    v24 = a2[12];
    v25 = *((const void **)a2 + 7);
    *(_BYTE *)(v10 + 664) = 1;
    v26 = (void *)(v10 + 672);
    if ( v24 >= 0x24 )
      v24 = 36;
    v27 = 4 * v24;
    *(_DWORD *)(v10 + 668) = v24;
    goto LABEL_46;
  }
LABEL_47:
  if ( !a1 )
  {
    v8 = -19;
LABEL_68:
    kfree(v10);
    goto LABEL_4;
  }
  v32 = *(_QWORD *)(a1 + 1832);
  memset(v39, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending config request, state: 0x%lx\n", v32);
  v33 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v33 )
  {
    v8 = -12;
    goto LABEL_68;
  }
  ++*(_DWORD *)(a1 + 2620);
  v34 = qmi_txn_init(a1 + 624, v39, &wlfw_wlan_cfg_resp_msg_v01_ei, v33);
  if ( (v34 & 0x80000000) != 0 )
  {
    v8 = v34;
    v36 = "%sicnss2_qmi: fatal: Fail to init txn for Config resp %d\n";
    printk("%sicnss2_qmi: fatal: Fail to init txn for Config resp %d\n", byte_130B32, v34);
LABEL_59:
    ipc_log_string(icnss_ipc_log_context, v36, &unk_12DBF3, v8);
    goto LABEL_61;
  }
  v8 = qmi_send_request(a1 + 624, 0, v39, 35, 2333, &wlfw_wlan_cfg_req_msg_v01_ei, v10);
  if ( (v8 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v39);
    v36 = "%sicnss2_qmi: fatal: Fail to send Config req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send Config req %d\n", byte_130B32, v8);
    goto LABEL_59;
  }
  v35 = qmi_txn_wait(v39, *(unsigned int *)(a1 + 336));
  if ( (v35 & 0x80000000) != 0 )
  {
    v8 = v35;
    v36 = "%sicnss2_qmi: fatal: Config resp wait failed with ret %d\n";
    printk("%sicnss2_qmi: fatal: Config resp wait failed with ret %d\n", byte_130B32, v35);
    goto LABEL_59;
  }
  if ( !*v33 )
  {
    ++*(_DWORD *)(a1 + 2624);
    kfree(v33);
    kfree(v10);
    goto LABEL_3;
  }
  printk("%sicnss2_qmi: fatal: QMI Config request rejected, result:%d error:%d\n", byte_130B32, *v33, v33[1]);
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2_qmi: fatal: QMI Config request rejected, result:%d error:%d\n",
    (const char *)&unk_12DBF3,
    *v33,
    v33[1]);
  v8 = -*v33;
LABEL_61:
  kfree(v33);
  ++*(_DWORD *)(a1 + 2628);
  kfree(v10);
  if ( !v8 )
LABEL_3:
    v8 = wlfw_wlan_mode_send_sync_msg(a1, a3);
LABEL_4:
  if ( (*(_QWORD *)(a1 + 328) & 4LL) != 0 )
    result = 0;
  else
    result = v8;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
