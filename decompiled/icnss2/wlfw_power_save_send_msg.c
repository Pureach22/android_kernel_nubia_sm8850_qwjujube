__int64 __fastcall wlfw_power_save_send_msg(__int64 a1, int a2)
{
  __int64 v2; // x3
  unsigned int v3; // w20
  __int64 v7; // x19
  __int64 v8; // x10
  int v9; // w11
  unsigned int v10; // w0
  __int64 v11; // x8
  const char *v12; // x21
  _QWORD v13[10]; // [xsp+0h] [xbp-50h] BYREF

  v13[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v3 = -19;
    goto LABEL_8;
  }
  if ( (*(_QWORD *)(a1 + 1832) & 0x2000) != 0 )
  {
    v3 = -22;
    goto LABEL_8;
  }
  if ( (*(_QWORD *)(a1 + 1832) & 0x200) != 0 || (v2 = *(_QWORD *)(a1 + 1832), (v2 & 0x10000) == 0) )
  {
    v3 = 0;
    goto LABEL_8;
  }
  memset(v13, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending power save mode: %d, state: 0x%lx\n", a2, v2);
  v7 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 8);
  if ( !v7 )
  {
    v3 = -12;
    goto LABEL_8;
  }
  v8 = 2696;
  if ( a2 == 1 )
    v8 = 2684;
  v9 = *(_DWORD *)(a1 + v8);
  *(_BYTE *)v7 = 1;
  *(_DWORD *)(v7 + 4) = a2;
  *(_DWORD *)(a1 + v8) = v9 + 1;
  v10 = qmi_txn_init(a1 + 624, v13, 0, 0);
  if ( (v10 & 0x80000000) != 0 )
  {
    v3 = v10;
    v12 = "%sicnss2_qmi: fatal: Fail to init txn for exit power save%d\n";
    printk("%sicnss2_qmi: fatal: Fail to init txn for exit power save%d\n", byte_130B32, v10);
    goto LABEL_19;
  }
  v3 = qmi_send_request(a1 + 624, 0, v13, 80, 7, &wlfw_power_save_req_msg_v01_ei, v7);
  qmi_txn_cancel(v13);
  if ( (v3 & 0x80000000) != 0 )
  {
    v12 = "%sicnss2_qmi: fatal: Fail to send exit power save req %d\n";
    printk("%sicnss2_qmi: fatal: Fail to send exit power save req %d\n", byte_130B32, v3);
LABEL_19:
    ipc_log_string(icnss_ipc_log_context, v12, &unk_12DBF3, v3);
    kfree(v7);
    if ( a2 == 1 )
      ++*(_DWORD *)(a1 + 2692);
    else
      ++*(_DWORD *)(a1 + 2704);
    goto LABEL_8;
  }
  v11 = 2700;
  if ( a2 == 1 )
    v11 = 2688;
  ++*(_DWORD *)(a1 + v11);
  kfree(v7);
  v3 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v3;
}
