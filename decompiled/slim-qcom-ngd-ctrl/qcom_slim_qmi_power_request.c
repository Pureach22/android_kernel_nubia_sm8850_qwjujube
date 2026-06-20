__int64 __fastcall qcom_slim_qmi_power_request(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  int v4; // w8
  __int64 v5; // x0
  unsigned int v6; // w20
  unsigned int v7; // w0
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8
  int v13; // [xsp+Ch] [xbp-64h] BYREF
  __int64 v14; // [xsp+10h] [xbp-60h]
  _QWORD v15[9]; // [xsp+18h] [xbp-58h] BYREF
  int v16; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+68h] [xbp-8h]

  v3 = a1 + 5296;
  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v4 = 2;
  else
    v4 = 1;
  v14 = 0;
  memset(v15, 0, sizeof(v15));
  v13 = v4;
  v16 = 0;
  mutex_lock(v3, a2);
  v5 = *(_QWORD *)(a1 + 1920);
  if ( !v5 )
  {
    mutex_unlock(a1 + 5296);
    v6 = -22;
    goto LABEL_25;
  }
  qmi_txn_init(v5, v15, &slimbus_power_resp_msg_v01_ei, &v16);
  v6 = qmi_send_request(*(_QWORD *)(a1 + 1920), 0, v15, 33, 14, &slimbus_power_req_msg_v01_ei, &v13);
  if ( (v6 & 0x80000000) != 0 )
  {
    _slimbus_dbg();
    v9 = *(_DWORD *)(a1 + 5476);
    if ( v9 >= 1 )
    {
      printk(&unk_CC90, v6);
      ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI send req fail %d\n", v6);
      *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
    }
    else if ( v9 )
    {
LABEL_16:
      mutex_unlock(a1 + 5296);
      qmi_txn_cancel(v15);
      goto LABEL_25;
    }
    ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI send req fail %d\n", v6);
    goto LABEL_16;
  }
  mutex_unlock(a1 + 5296);
  v7 = qmi_txn_wait(v15, 1000);
  if ( (v7 & 0x80000000) != 0 )
  {
    v6 = v7;
    _slimbus_dbg();
    v10 = *(_DWORD *)(a1 + 5476);
    if ( v10 >= 1 )
    {
      printk(&unk_CA0D, v6);
      ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI TXN wait fail: %d\n", v6);
      *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
    }
    else if ( v10 )
    {
      goto LABEL_25;
    }
    ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI TXN wait fail: %d\n", v6);
    goto LABEL_25;
  }
  if ( (_WORD)v16 )
  {
    _slimbus_dbg();
    v8 = *(_DWORD *)(a1 + 5476);
    if ( v8 >= 1 )
    {
      printk(&unk_C900, (unsigned __int16)v16);
      ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI request failed 0x%x\n", (unsigned __int16)v16);
      *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
    }
    else if ( v8 )
    {
LABEL_11:
      v6 = -121;
      goto LABEL_25;
    }
    ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI request failed 0x%x\n", (unsigned __int16)v16);
    goto LABEL_11;
  }
  _slimbus_dbg();
  v11 = *(_DWORD *)(a1 + 5476);
  if ( v11 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "%s end %d\n", "qcom_slim_qmi_send_power_request", v13);
    v11 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v11 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "%s end %d\n", "qcom_slim_qmi_send_power_request", v13);
  v6 = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v6;
}
