__int64 __fastcall coresight_qmi_remote_etm_disable(__int64 a1)
{
  __int64 v1; // x8
  _QWORD *v2; // x19
  int v3; // w0
  __int64 result; // x0
  int v5; // w2
  int v6; // w0
  __int64 v7; // x0
  _QWORD v8[9]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v9[2]; // [xsp+50h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  v9[0] = 0;
  v2 = *(_QWORD **)(v1 + 152);
  memset(v8, 0, sizeof(v8));
  mutex_lock(v2 + 2);
  if ( (*((_BYTE *)v2 + 372) & 1) != 0 )
  {
    HIDWORD(v9[0]) = 0;
    v3 = qmi_txn_init(v2 + 8, v8, &coresight_set_etm_resp_msg_v01_ei, v9);
    if ( v3 < 0 )
    {
      dev_err(*v2, "QMI tx init failed , ret:%d\n", v3);
    }
    else
    {
      v5 = qmi_send_request(v2 + 8, v2 + 47, v8, 44, 7, &coresight_set_etm_req_msg_v01_ei, (char *)v9 + 4);
      if ( v5 < 0 )
      {
        dev_err(*v2, "QMI send req failed, ret:%d\n", v5);
        qmi_txn_cancel(v8);
      }
      else
      {
        v6 = qmi_txn_wait(v8, 2500);
        if ( v6 < 0 )
        {
          dev_err(*v2, "QMI qmi txn wait failed, ret:%d\n", v6);
        }
        else
        {
          v7 = *v2;
          if ( LOWORD(v9[0]) )
            dev_err(v7, "QMI request failed 0x%x\n", WORD1(v9[0]));
          else
            dev_info(v7, "Remote ETM tracing disabled for instance %d\n", *((_DWORD *)v2 + 92));
        }
      }
    }
  }
  else
  {
    dev_err(*v2, "QMI service not connected!\n");
  }
  result = mutex_unlock(v2 + 2);
  _ReadStatusReg(SP_EL0);
  return result;
}
