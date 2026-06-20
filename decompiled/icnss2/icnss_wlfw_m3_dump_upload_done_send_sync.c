__int64 __fastcall icnss_wlfw_m3_dump_upload_done_send_sync(__int64 a1, int a2, int a3)
{
  unsigned __int16 *v6; // x19
  unsigned __int16 *v7; // x20
  unsigned int v8; // w0
  unsigned int v9; // w22
  const char *v10; // x21
  _QWORD v12[10]; // [xsp+0h] [xbp-50h] BYREF

  v12[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 72);
  v6 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 8);
  if ( v6 )
  {
    v7 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
    if ( !v7 )
    {
      v9 = -12;
      v7 = v6;
      goto LABEL_15;
    }
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending M3 Upload done req, pdev %d, status %d\n", a2, a3);
    *(_DWORD *)v6 = a2;
    *((_DWORD *)v6 + 1) = a3;
    v8 = qmi_txn_init(a1 + 624, v12, &wlfw_m3_dump_upload_done_resp_msg_v01_ei, v7);
    if ( (v8 & 0x80000000) != 0 )
    {
      v9 = v8;
      v10 = "%sicnss2_qmi: Fail to initialize txn for M3 dump upload done req: err %d\n";
      printk("%sicnss2_qmi: Fail to initialize txn for M3 dump upload done req: err %d\n", byte_130B32, v8);
    }
    else
    {
      v9 = qmi_send_request(a1 + 624, 0, v12, 78, 14, &wlfw_m3_dump_upload_done_req_msg_v01_ei, v6);
      if ( (v9 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v12);
        v10 = "%sicnss2_qmi: Fail to send M3 dump upload done request: err %d\n";
        printk("%sicnss2_qmi: Fail to send M3 dump upload done request: err %d\n", byte_130B32, v9);
      }
      else
      {
        v9 = qmi_txn_wait(v12, *(unsigned int *)(a1 + 336));
        if ( (v9 & 0x80000000) == 0 )
        {
          if ( *v7 )
          {
            printk("%sicnss2_qmi: M3 Dump Upload Done Req failed, result: %d, err: 0x%X\n", byte_130B32, *v7, v7[1]);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2_qmi: M3 Dump Upload Done Req failed, result: %d, err: 0x%X\n",
              (const char *)&unk_12DBF3,
              *v7,
              v7[1]);
            v9 = -*v7;
          }
          goto LABEL_8;
        }
        v10 = "%sicnss2_qmi: Fail to wait for response of M3 dump upload done request, err %d\n";
        printk("%sicnss2_qmi: Fail to wait for response of M3 dump upload done request, err %d\n", byte_130B32, v9);
      }
    }
    ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3, v9);
LABEL_8:
    kfree(v6);
LABEL_15:
    kfree(v7);
    goto LABEL_16;
  }
  v9 = -12;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v9;
}
