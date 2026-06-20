__int64 __fastcall ims_new_server(_QWORD *a1, __int64 a2)
{
  int v4; // w2
  int v5; // w3
  int v6; // w9
  int v7; // w10
  __int64 v8; // x0
  unsigned int v9; // w0
  __int64 v10; // x20
  unsigned int v11; // w0
  unsigned int v12; // w21
  const char *v13; // x19
  unsigned __int64 v20; // x9
  _DWORD v22[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 12);
  v5 = *(_DWORD *)(a2 + 16);
  v22[0] = 0;
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: IMS server arrive: node %u port %u\n", v4, v5);
  v6 = *(_DWORD *)(a2 + 12);
  v7 = *(_DWORD *)(a2 + 16);
  v8 = *a1;
  LOWORD(v22[0]) = 42;
  v22[1] = v6;
  v22[2] = v7;
  v9 = kernel_connect(v8, v22, 12, 0);
  if ( (v9 & 0x80000000) != 0 )
  {
    v12 = v9;
    printk("%sicnss2_qmi: Fail to connect to remote service port\n", byte_130B32);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sicnss2_qmi: Fail to connect to remote service port\n",
      (const char *)&unk_12DBF3);
    goto LABEL_17;
  }
  _X8 = a1 + 75;
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 | 0x80000, _X8) );
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: IMS Server Connected: 0x%lx\n", a1[75]);
  if ( a1 == qword_4D0 )
  {
    v12 = -19;
    goto LABEL_17;
  }
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending ASYNC ims subscribe for indication\n");
  v10 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
  if ( !v10 )
  {
    v12 = -12;
    goto LABEL_17;
  }
  *(_WORD *)(v10 + 2) = 257;
  v11 = qmi_txn_init(a1, a1 + 38, 0, 0);
  if ( (v11 & 0x80000000) != 0 )
  {
    v12 = v11;
    v13 = "%sicnss2_qmi: Fail to init txn for ims subscribe for indication resp %d\n";
    printk("%sicnss2_qmi: Fail to init txn for ims subscribe for indication resp %d\n", byte_130B32, v11);
LABEL_13:
    ipc_log_string(icnss_ipc_log_context, v13, &unk_12DBF3, v12);
    goto LABEL_8;
  }
  v12 = qmi_send_request(a1, 0, a1 + 38, 62, 8, &ims_private_service_subscribe_ind_req_msg_v01_ei, v10);
  if ( (v12 & 0x80000000) != 0 )
  {
    qmi_txn_cancel(a1 + 38);
    v13 = "%sicnss2_qmi: Fail to send ims subscribe for indication req %d\n";
    printk("%sicnss2_qmi: Fail to send ims subscribe for indication req %d\n", byte_130B32, v12);
    goto LABEL_13;
  }
  v12 = 0;
LABEL_8:
  kfree(v10);
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v12;
}
