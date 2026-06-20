__int64 __fastcall wlfw_device_info_send_msg(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x20
  unsigned __int16 *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w22
  unsigned int v7; // w0
  int v8; // w9
  unsigned int v9; // w2
  int v10; // w3
  int v11; // w4
  __int64 v12; // x2
  __int64 v13; // x0
  int v14; // w3
  int v15; // w4
  __int64 v16; // x2
  int v17; // w3
  int v18; // w4
  __int64 v19; // x2
  int v20; // w3
  int v21; // w4
  __int64 v22; // x2
  int v23; // w3
  int v24; // w4
  __int64 v25; // x2
  const char *v26; // x23
  _QWORD v28[10]; // [xsp+0h] [xbp-50h] BYREF

  v28[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_27;
  v2 = *(_QWORD *)(a1 + 1832);
  memset(v28, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending Device Info request message, state: 0x%lx\n", v2);
  v3 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 1);
  if ( !v3 )
  {
LABEL_40:
    v6 = -12;
    goto LABEL_41;
  }
  v4 = (unsigned __int16 *)_kmalloc_cache_noprof(alt_cb_patch_nops, 3520, 136);
  if ( !v4 )
  {
    kfree(v3);
    goto LABEL_40;
  }
  ++*(_DWORD *)(a1 + 2672);
  v5 = qmi_txn_init(a1 + 624, v28, &wlfw_device_info_resp_msg_v01_ei, v4);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    v26 = "%sicnss2_qmi: fatal: Fail to init txn for Device Info resp %d\n";
    printk("%sicnss2_qmi: fatal: Fail to init txn for Device Info resp %d\n", byte_130B32, v5);
LABEL_31:
    ipc_log_string(icnss_ipc_log_context, v26, &unk_12DBF3, v6);
LABEL_36:
    kfree(v4);
    kfree(v3);
    ++*(_DWORD *)(a1 + 2680);
    goto LABEL_41;
  }
  v6 = qmi_send_request(a1 + 624, 0, v28, 76, 0, &wlfw_device_info_req_msg_v01_ei, v3);
  if ( (v6 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v28);
    v26 = "%sicnss2_qmi: fatal: Fail to send device info req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send device info req %d\n", byte_130B32, v6);
    goto LABEL_31;
  }
  v7 = qmi_txn_wait(v28, *(unsigned int *)(a1 + 336));
  if ( (v7 & 0x80000000) != 0 )
  {
    v6 = v7;
    v26 = "%sicnss2_qmi: fatal: Device Info resp wait failed with ret %d\n";
    printk("%sicnss2_qmi: fatal: Device Info resp wait failed with ret %d\n", byte_130B32, v7);
    goto LABEL_31;
  }
  if ( *v4 )
  {
    printk("%sicnss2_qmi: fatal: QMI Device info request rejected, result:%d error:%d\n", byte_130B32, *v4, v4[1]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: fatal: QMI Device info request rejected, result:%d error:%d\n",
      (const char *)&unk_12DBF3,
      *v4,
      v4[1]);
    v6 = -*v4;
    goto LABEL_36;
  }
  v8 = *((unsigned __int8 *)v4 + 4);
  ++*(_DWORD *)(a1 + 2676);
  if ( v8 )
    *(_QWORD *)(a1 + 528) = *((_QWORD *)v4 + 1);
  if ( *((_BYTE *)v4 + 16) )
    *(_DWORD *)(a1 + 544) = *((_DWORD *)v4 + 5);
  if ( !*(_QWORD *)(a1 + 528) )
  {
    printk("%sicnss2_qmi: fatal: Fail to get bar address\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: fatal: Fail to get bar address\n", (const char *)&unk_12DBF3);
LABEL_35:
    v6 = -22;
    goto LABEL_36;
  }
  v9 = *(_DWORD *)(a1 + 544);
  if ( !(v9 >> 21) )
  {
    printk("%sicnss2_qmi: fatal: Bar size is not proper 0x%x\n", byte_130B32, v9);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: fatal: Bar size is not proper 0x%x\n",
      (const char *)&unk_12DBF3,
      *(_DWORD *)(a1 + 544));
    goto LABEL_35;
  }
  if ( *((_BYTE *)v4 + 24) )
    *(_QWORD *)(a1 + 552) = *((_QWORD *)v4 + 4);
  if ( *((_BYTE *)v4 + 40) )
    *(_DWORD *)(a1 + 568) = *((_DWORD *)v4 + 11);
  if ( !*(_QWORD *)(a1 + 552) )
  {
    printk("%sicnss2_qmi: Fail to get MHI info address\n", byte_130B32);
    ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Fail to get MHI info address\n", (const char *)&unk_12DBF3);
    if ( *((_BYTE *)v4 + 48) )
      goto LABEL_20;
LABEL_38:
    kfree(v4);
    kfree(v3);
    v6 = 0;
    goto LABEL_41;
  }
  if ( !*((_BYTE *)v4 + 48) )
    goto LABEL_38;
LABEL_20:
  if ( !*((_DWORD *)v4 + 13) )
    goto LABEL_38;
  v10 = *((_DWORD *)v4 + 16);
  v11 = *((_DWORD *)v4 + 17);
  v12 = *((_QWORD *)v4 + 7);
  v13 = icnss_ipc_log_context;
  *(_QWORD *)(a1 + 6192) = v12;
  *(_DWORD *)(a1 + 6200) = v10;
  *(_DWORD *)(a1 + 6204) = v11;
  ipc_log_string(v13, "icnss2_qmi: wlan fw shared mem info: pa_addr:0x%llx, mem_client_id:%d, size:%d", v12, v10, v11);
  if ( *((_DWORD *)v4 + 13) <= 1u )
    goto LABEL_38;
  v14 = *((_DWORD *)v4 + 20);
  v15 = *((_DWORD *)v4 + 21);
  v16 = *((_QWORD *)v4 + 9);
  *(_QWORD *)(a1 + 6208) = v16;
  *(_DWORD *)(a1 + 6216) = v14;
  *(_DWORD *)(a1 + 6220) = v15;
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: wlan fw shared mem info: pa_addr:0x%llx, mem_client_id:%d, size:%d",
    v16,
    v14,
    v15);
  if ( *((_DWORD *)v4 + 13) < 3u )
    goto LABEL_38;
  v17 = *((_DWORD *)v4 + 24);
  v18 = *((_DWORD *)v4 + 25);
  v19 = *((_QWORD *)v4 + 11);
  *(_QWORD *)(a1 + 6224) = v19;
  *(_DWORD *)(a1 + 6232) = v17;
  *(_DWORD *)(a1 + 6236) = v18;
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: wlan fw shared mem info: pa_addr:0x%llx, mem_client_id:%d, size:%d",
    v19,
    v17,
    v18);
  if ( *((_DWORD *)v4 + 13) < 4u )
    goto LABEL_38;
  v20 = *((_DWORD *)v4 + 28);
  v21 = *((_DWORD *)v4 + 29);
  v22 = *((_QWORD *)v4 + 13);
  *(_QWORD *)(a1 + 6240) = v22;
  *(_DWORD *)(a1 + 6248) = v20;
  *(_DWORD *)(a1 + 6252) = v21;
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: wlan fw shared mem info: pa_addr:0x%llx, mem_client_id:%d, size:%d",
    v22,
    v20,
    v21);
  if ( *((_DWORD *)v4 + 13) < 5u )
    goto LABEL_38;
  v23 = *((_DWORD *)v4 + 32);
  v24 = *((_DWORD *)v4 + 33);
  v25 = *((_QWORD *)v4 + 15);
  *(_QWORD *)(a1 + 6256) = v25;
  *(_DWORD *)(a1 + 6264) = v23;
  *(_DWORD *)(a1 + 6268) = v24;
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: wlan fw shared mem info: pa_addr:0x%llx, mem_client_id:%d, size:%d",
    v25,
    v23,
    v24);
  if ( *((_DWORD *)v4 + 13) <= 5u )
    goto LABEL_38;
  __break(0x5512u);
LABEL_27:
  v6 = -19;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v6;
}
