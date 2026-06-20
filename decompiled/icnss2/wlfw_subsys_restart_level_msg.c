__int64 __fastcall wlfw_subsys_restart_level_msg(__int64 a1, unsigned __int8 a2)
{
  _BYTE *v4; // x20
  unsigned __int16 *v5; // x21
  int v6; // w9
  unsigned int v7; // w0
  unsigned int v8; // w22
  unsigned int v9; // w0
  const char *v10; // x23
  _QWORD v12[10]; // [xsp+0h] [xbp-50h] BYREF

  v12[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v8 = -19;
    goto LABEL_20;
  }
  if ( (*(_QWORD *)(a1 + 1832) & 0x2000) != 0 )
  {
    v8 = -22;
    goto LABEL_20;
  }
  memset(v12, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending subsystem restart level: 0x%x\n", a2);
  v4 = (_BYTE *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
  if ( !v4 )
  {
LABEL_19:
    v8 = -12;
    goto LABEL_20;
  }
  v5 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v5 )
  {
    kfree(v4);
    goto LABEL_19;
  }
  v6 = *(_DWORD *)(a1 + 2720);
  *v4 = 1;
  v4[1] = a2;
  *(_DWORD *)(a1 + 2720) = v6 + 1;
  v7 = qmi_txn_init(a1 + 624, v12, &wlfw_subsys_restart_level_resp_msg_v01_ei, v5);
  if ( (v7 & 0x80000000) != 0 )
  {
    v8 = v7;
    v10 = "%sicnss2_qmi: Fail to init txn for subsystem restart level, resp %d\n";
    printk("%sicnss2_qmi: Fail to init txn for subsystem restart level, resp %d\n", byte_130B32, v7);
LABEL_15:
    ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3, v8);
LABEL_17:
    kfree(v4);
    kfree(v5);
    ++*(_DWORD *)(a1 + 2728);
    goto LABEL_20;
  }
  v8 = qmi_send_request(a1 + 624, 0, v12, 85, 4, &wlfw_subsys_restart_level_req_msg_v01_ei, v4);
  if ( (v8 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(v12);
    v10 = "%sicnss2_qmi: Fail to send subsystem restart level %d\n";
    printk("%sicnss2_qmi: Fail to send subsystem restart level %d\n", byte_130B32, v8);
    goto LABEL_15;
  }
  v9 = qmi_txn_wait(v12, *(unsigned int *)(a1 + 336));
  if ( (v9 & 0x80000000) != 0 )
  {
    v8 = v9;
    v10 = "%sicnss2_qmi: Subsystem restart level timed out with ret %d\n";
    printk("%sicnss2_qmi: Subsystem restart level timed out with ret %d\n", byte_130B32, v9);
    goto LABEL_15;
  }
  if ( *v5 )
  {
    printk("%sicnss2_qmi: Subsystem restart level request rejected,result:%d error:%d\n", byte_130B32, *v5, v5[1]);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Subsystem restart level request rejected,result:%d error:%d\n",
      (const char *)&unk_12DBF3,
      *v5,
      v5[1]);
    v8 = -*v5;
    goto LABEL_17;
  }
  ++*(_DWORD *)(a1 + 2724);
  kfree(v5);
  kfree(v4);
  v8 = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v8;
}
