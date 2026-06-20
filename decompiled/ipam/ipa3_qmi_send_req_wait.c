__int64 __fastcall ipa3_qmi_send_req_wait(
        __int64 a1,
        unsigned __int16 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        unsigned int a6)
{
  unsigned int v12; // w0
  unsigned int v13; // w19
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v19; // x0
  __int64 ipc_logbuf; // x0
  __int64 v21; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v23; // x0
  _QWORD v24[10]; // [xsp+0h] [xbp-50h] BYREF

  v24[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 72);
  mutex_lock(&ipa3_qmi_lock);
  if ( a1 && ipa_q6_clnt == a1 )
  {
    v12 = qmi_txn_init(a1, v24, *(_QWORD *)(a4 + 8), a5);
    if ( (v12 & 0x80000000) != 0 )
    {
      v13 = v12;
      v19 = printk(&unk_3CCFF3, "ipa3_qmi_send_req_wait");
      ipc_logbuf = ipa3_get_ipc_logbuf(v19);
      if ( ipc_logbuf )
      {
        v21 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v21,
                       "ipa-wan %s:%d QMI txn init failed, ret= %d\n",
                       "ipa3_qmi_send_req_wait",
                       567,
                       v13);
      }
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( ipc_logbuf_low )
      {
        v23 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
        ipc_log_string(v23, "ipa-wan %s:%d QMI txn init failed, ret= %d\n", "ipa3_qmi_send_req_wait", 567, v13);
      }
    }
    else
    {
      v13 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *, _QWORD, _QWORD, _QWORD, __int64))qmi_send_request)(
              a1,
              ipa3_qmi_ctx + 28876,
              v24,
              *a2,
              *((int *)a2 + 1),
              *((_QWORD *)a2 + 1),
              a3);
      if ( (v13 & 0x80000000) != 0 )
      {
        qmi_txn_cancel(v24);
      }
      else
      {
        v14 = _msecs_to_jiffies(a6);
        v13 = qmi_txn_wait(v24, v14);
      }
    }
  }
  else
  {
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Q6 QMI client pointer already freed\n", "ipa3_qmi_send_req_wait", 559);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d Q6 QMI client pointer already freed\n", "ipa3_qmi_send_req_wait", 559);
    }
    v13 = -22;
  }
  mutex_unlock(&ipa3_qmi_lock);
  _ReadStatusReg(SP_EL0);
  return v13;
}
