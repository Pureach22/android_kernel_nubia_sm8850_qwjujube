__int64 __fastcall coresight_qmi_remote_etm_enable(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v2; // x20
  unsigned int v3; // w0
  unsigned int v4; // w19
  unsigned int v6; // w0
  _QWORD v7[9]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v8[2]; // [xsp+50h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v8[0] = 0;
  v2 = *(_QWORD **)(v1 + 152);
  memset(v7, 0, sizeof(v7));
  mutex_lock(v2 + 2);
  if ( (*((_BYTE *)v2 + 372) & 1) == 0 )
  {
    dev_err(*v2, "QMI service not connected!\n");
    v4 = -22;
LABEL_6:
    mutex_unlock(v2 + 2);
    goto LABEL_7;
  }
  HIDWORD(v8[0]) = 1;
  v3 = qmi_txn_init(v2 + 8, v7, &coresight_set_etm_resp_msg_v01_ei, v8);
  if ( (v3 & 0x80000000) != 0 )
  {
    v4 = v3;
    dev_err(*v2, "QMI tx init failed , ret:%d\n", v3);
    goto LABEL_6;
  }
  v4 = qmi_send_request(v2 + 8, v2 + 47, v7, 44, 7, &coresight_set_etm_req_msg_v01_ei, (char *)v8 + 4);
  if ( (v4 & 0x80000000) != 0 )
  {
    dev_err(*v2, "QMI send ACK failed, ret:%d\n", v4);
    qmi_txn_cancel(v7);
    goto LABEL_6;
  }
  v6 = qmi_txn_wait(v7, 2500);
  if ( (v6 & 0x80000000) != 0 )
  {
    v4 = v6;
    dev_err(*v2, "QMI qmi txn wait failed, ret:%d\n", v6);
    goto LABEL_6;
  }
  if ( LOWORD(v8[0]) )
    dev_err(*v2, "QMI request failed 0x%x\n", WORD1(v8[0]));
  mutex_unlock(v2 + 2);
  dev_info(*v2, "Remote ETM tracing enabled for instance %d\n", *((_DWORD *)v2 + 92));
  v4 = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return v4;
}
