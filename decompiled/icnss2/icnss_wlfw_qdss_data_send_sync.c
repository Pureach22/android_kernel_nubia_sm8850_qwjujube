__int64 __fastcall icnss_wlfw_qdss_data_send_sync(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int16 *v6; // x19
  unsigned __int16 *v7; // x20
  __int64 v8; // x0
  char *v9; // x27
  unsigned __int64 v10; // x21
  int v11; // w5
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w5
  int v15; // w6
  int v16; // w7
  size_t v17; // x2
  size_t v18; // x1
  __int64 v19; // x8
  int v20; // w4
  __int64 v21; // x24
  __int64 v22; // x23
  const char *v23; // x21
  __int64 v24; // x21
  __int64 v25; // x22
  unsigned __int64 StatusReg; // x20
  __int64 v27; // x21
  __int64 (__fastcall *v28)(_QWORD); // x0
  __int64 result; // x0
  const char *v30; // [xsp+20h] [xbp-60h]
  __int64 v31; // [xsp+28h] [xbp-58h]
  _QWORD v32[10]; // [xsp+30h] [xbp-50h] BYREF

  v32[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v32, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: %s", "icnss_wlfw_qdss_data_send_sync");
  v6 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v6 )
  {
LABEL_45:
    result = 4294967284LL;
    goto LABEL_50;
  }
LABEL_2:
  v7 = (unsigned __int16 *)_kmalloc_cache_noprof(icc_set_bw, 3520, 6176);
  if ( !v7 )
  {
    v22 = 4294967284LL;
    v7 = v6;
    goto LABEL_49;
  }
  v8 = _kmalloc_noprof(a3, 3520);
  if ( !v8 )
  {
    v22 = 12;
    goto LABEL_48;
  }
  v30 = (const char *)a2;
  v31 = v8;
  if ( !a3 )
  {
LABEL_23:
    v20 = *((unsigned __int8 *)v7 + 6172);
    v11 = *((unsigned __int8 *)v7 + 6173);
    if ( *((_BYTE *)v7 + 6172) )
    {
      v21 = v31;
      if ( *((_BYTE *)v7 + 6173) )
      {
        v22 = icnss_genl_send_msg(v31, 1u, v30, a3);
        if ( (v22 & 0x80000000) == 0 )
          goto LABEL_26;
        printk("%sicnss2_qmi: Fail to save QDSS trace data: %d\n", byte_130B32, v22);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: Fail to save QDSS trace data: %d\n",
          (const char *)&unk_12DBF3,
          v22);
        goto LABEL_35;
      }
      LODWORD(a2) = 0;
    }
    else
    {
      LODWORD(a2) = 0;
LABEL_33:
      v21 = v31;
    }
    printk(
      "%sicnss2_qmi: %s: QDSS trace file corrupted: remaining %u, end_valid %u, end %u",
      byte_130B32,
      "icnss_wlfw_qdss_data_send_sync",
      a2,
      v20,
      v11);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: %s: QDSS trace file corrupted: remaining %u, end_valid %u, end %u",
      (const char *)&unk_12DBF3,
      "icnss_wlfw_qdss_data_send_sync",
      a2,
      *((unsigned __int8 *)v7 + 6172),
      *((unsigned __int8 *)v7 + 6173));
LABEL_35:
    v22 = 4294967274LL;
    goto LABEL_26;
  }
  v9 = (char *)v8;
  v10 = 0;
  a2 = a3;
  while ( 1 )
  {
    v11 = *((unsigned __int8 *)v7 + 6173);
    if ( *((_BYTE *)v7 + 6173) )
    {
      v20 = *((unsigned __int8 *)v7 + 6172);
      goto LABEL_33;
    }
    v12 = qmi_txn_init(a1 + 624, v32, &wlfw_qdss_trace_data_resp_msg_v01_ei, v7);
    if ( (v12 & 0x80000000) != 0 )
    {
      v23 = "%sicnss2_qmi: Fail to init txn for QDSS trace resp %d\n";
LABEL_39:
      v25 = v12;
      printk(v23, byte_130B32, (unsigned int)v12);
      v22 = v25;
      ipc_log_string(icnss_ipc_log_context, v23, &unk_12DBF3, (unsigned int)v25);
      goto LABEL_40;
    }
    v13 = qmi_send_request(a1 + 624, 0, v32, 66, 7, &wlfw_qdss_trace_data_req_msg_v01_ei, v6);
    if ( (v13 & 0x80000000) != 0 )
    {
      v24 = v13;
      qmi_txn_cancel(v32);
      printk("%sicnss2_qmi: Fail to send QDSS trace data req %d\n", byte_130B32, v24);
      v22 = v24;
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Fail to send QDSS trace data req %d\n",
        &unk_12DBF3,
        (unsigned int)v24);
LABEL_40:
      v21 = v31;
      goto LABEL_26;
    }
    v12 = qmi_txn_wait(v32, *(unsigned int *)(a1 + 336));
    if ( (v12 & 0x80000000) != 0 )
    {
      v23 = "%sicnss2_qmi: QDSS trace resp wait failed with rc %d\n";
      goto LABEL_39;
    }
    if ( *v7 )
    {
      printk("%sicnss2_qmi: QMI QDSS trace request rejected, result:%d error:%d\n", byte_130B32, *v7, v7[1]);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: QMI QDSS trace request rejected, result:%d error:%d\n",
        (const char *)&unk_12DBF3,
        *v7,
        v7[1]);
      v21 = v31;
      v22 = (unsigned int)-*v7;
      goto LABEL_26;
    }
    ipc_log_string(
      icnss_ipc_log_context,
      "icnss2_qmi: %s: response total size  %d data len %d",
      "icnss_wlfw_qdss_data_send_sync",
      *((_DWORD *)v7 + 2),
      *((_DWORD *)v7 + 6));
    v14 = *((unsigned __int8 *)v7 + 4);
    v15 = *((_DWORD *)v7 + 2);
    if ( v14 != 1 )
    {
      v16 = *((unsigned __int8 *)v7 + 12);
      goto LABEL_43;
    }
    v16 = *((unsigned __int8 *)v7 + 12);
    if ( v15 != a3 || v16 != 1 )
      goto LABEL_43;
    if ( *((_DWORD *)v7 + 4) != *(_DWORD *)v6 || *((_BYTE *)v7 + 20) != 1 )
      break;
    v17 = *((unsigned int *)v7 + 6);
    v16 = 1;
    if ( (unsigned int)v17 > 0x1800 )
      goto LABEL_28;
    v14 = 1;
    if ( (unsigned int)v17 > (unsigned int)a2 )
      goto LABEL_43;
    if ( a3 >= v10 )
      v18 = a3 - v10;
    else
      v18 = 0;
    if ( v18 < v17 )
    {
      _fortify_panic(17, v18, v17);
      StatusReg = _ReadStatusReg(SP_EL0);
      v27 = *(_QWORD *)(StatusReg + 80);
      v28 = pm_stay_awake;
      *(_QWORD *)(StatusReg + 80) = &icnss_wlfw_qdss_data_send_sync__alloc_tag;
      v6 = (unsigned __int16 *)_kmalloc_cache_noprof(v28, 3520, 4);
      *(_QWORD *)(StatusReg + 80) = v27;
      if ( !v6 )
        goto LABEL_45;
      goto LABEL_2;
    }
    memcpy(v9, v7 + 14, v17);
    v19 = *((unsigned int *)v7 + 6);
    a2 = (unsigned int)(a2 - v19);
    v10 += v19;
    v9 += v19;
    ++*(_DWORD *)v6;
    if ( !(_DWORD)a2 )
      goto LABEL_23;
  }
  v16 = 1;
LABEL_28:
  v14 = 1;
LABEL_43:
  printk(
    "%sicnss2_qmi: %s: Unmatched qdss trace data, Expect total_size %u, seg_id %u, Recv total_size_valid %u, total_size %"
    "u, seg_id_valid %u, seg_id %u, data_len_valid %u, data_len %u",
    byte_130B32,
    "icnss_wlfw_qdss_data_send_sync",
    a3,
    *(_DWORD *)v6,
    v14,
    v15,
    v16,
    *((_DWORD *)v7 + 4),
    *((unsigned __int8 *)v7 + 20),
    *((_DWORD *)v7 + 6));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2_qmi: %s: Unmatched qdss trace data, Expect total_size %u, seg_id %u, Recv total_size_valid %u, total_size %"
    "u, seg_id_valid %u, seg_id %u, data_len_valid %u, data_len %u",
    (const char *)&unk_12DBF3,
    "icnss_wlfw_qdss_data_send_sync",
    a3,
    *(_DWORD *)v6,
    *((unsigned __int8 *)v7 + 4),
    *((_DWORD *)v7 + 2),
    *((unsigned __int8 *)v7 + 12),
    *((_DWORD *)v7 + 4),
    *((unsigned __int8 *)v7 + 20),
    *((_DWORD *)v7 + 6));
  v21 = v31;
  v22 = 4294967274LL;
LABEL_26:
  kfree(v21);
LABEL_48:
  kfree(v6);
LABEL_49:
  kfree(v7);
  result = v22;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
