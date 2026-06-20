__int64 __fastcall coresight_qmi_etr_assign(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x21
  unsigned int v4; // w19
  unsigned int v7; // w0
  __int64 v8; // x0
  _QWORD v9[9]; // [xsp+8h] [xbp-58h] BYREF
  int v10; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+58h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  v3 = *(_QWORD **)(v2 + 152);
  if ( v3 )
  {
    memset(v9, 0, sizeof(v9));
    mutex_lock(v3 + 2);
    if ( (*((_BYTE *)v3 + 372) & 1) != 0 )
    {
      v7 = qmi_txn_init(v3 + 8, v9, &coresight_etr_assign_resp_msg_v01_ei, &v10);
      if ( (v7 & 0x80000000) != 0 )
      {
        v4 = v7;
        dev_err(*v3, "QMI tx init failed , ret:%d\n", v7);
      }
      else
      {
        v4 = qmi_send_request(v3 + 8, v3 + 47, v9, 66, 36, &coresight_etr_assign_req_msg_v01_ei, a2);
        if ( (v4 & 0x80000000) != 0 )
        {
          dev_err(*v3, "QMI send req failed, ret:%d\n", v4);
          qmi_txn_cancel(v9);
        }
        else
        {
          v4 = qmi_txn_wait(v9, 2500);
          if ( (v4 & 0x80000000) != 0 )
          {
            dev_err(*v3, "QMI qmi txn wait failed, ret:%d\n", v4);
          }
          else
          {
            v8 = *v3;
            if ( (_WORD)v10 )
            {
              dev_err(v8, "QMI request failed 0x%x\n", HIWORD(v10));
            }
            else
            {
              dev_info(v8, "Assign etr success\n");
              v4 = 0;
            }
          }
        }
      }
    }
    else
    {
      dev_err(*v3, "QMI service not connected!\n");
      v4 = -22;
    }
    mutex_unlock(v3 + 2);
  }
  else
  {
    v4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
