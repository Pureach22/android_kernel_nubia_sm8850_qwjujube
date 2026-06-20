__int64 __fastcall coresight_qmi_assign_atid(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  _QWORD *v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w19
  unsigned int v8; // w0
  _QWORD v9[9]; // [xsp+8h] [xbp-58h] BYREF
  int v10; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+58h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v4 = *(_QWORD **)(v3 + 152);
  memset(v9, 0, sizeof(v9));
  mutex_lock(v4 + 2);
  if ( (*((_BYTE *)v4 + 372) & 1) == 0 )
  {
    dev_err(*v4, "QMI service not connected!\n");
    v6 = -22;
LABEL_6:
    mutex_unlock(v4 + 2);
    goto LABEL_7;
  }
  v5 = qmi_txn_init(v4 + 8, v9, &coresight_atid_assign_resp_msg_v01_ei, &v10);
  if ( (v5 & 0x80000000) != 0 )
  {
    v6 = v5;
    dev_err(*v4, "QMI tx init failed , ret:%d\n", v5);
    goto LABEL_6;
  }
  v6 = qmi_send_request(v4 + 8, v4 + 47, v9, 68, 34, &coresight_atid_assign_req_msg_v01_ei, a2);
  if ( (v6 & 0x80000000) != 0 )
  {
    dev_err(*v4, "QMI send ACK failed, ret:%d\n", v6);
    qmi_txn_cancel(v9);
    goto LABEL_6;
  }
  v8 = qmi_txn_wait(v9, 2500);
  if ( (v8 & 0x80000000) != 0 )
  {
    v6 = v8;
    dev_err(*v4, "QMI qmi txn wait failed, ret:%d\n", v8);
    goto LABEL_6;
  }
  if ( (_WORD)v10 )
    dev_err(*v4, "QMI request failed 0x%x\n", HIWORD(v10));
  mutex_unlock(v4 + 2);
  dev_info(*v4, "ATID assign for instance %d\n", *((_DWORD *)v4 + 92));
  v6 = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v6;
}
