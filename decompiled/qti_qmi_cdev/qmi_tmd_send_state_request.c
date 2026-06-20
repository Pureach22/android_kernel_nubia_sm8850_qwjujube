__int64 __fastcall qmi_tmd_send_state_request(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x22
  size_t v5; // x0
  unsigned __int64 v6; // x2
  unsigned int v7; // w0
  unsigned int v8; // w21
  void *v9; // x0
  unsigned int v11; // w0
  _QWORD v12[9]; // [xsp+0h] [xbp-80h] BYREF
  int v13; // [xsp+4Ch] [xbp-34h] BYREF
  _QWORD v14[4]; // [xsp+50h] [xbp-30h] BYREF
  __int16 v15; // [xsp+70h] [xbp-10h]
  __int64 v16; // [xsp+78h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 112);
  memset(v12, 0, sizeof(v12));
  memset(v14, 0, sizeof(v14));
  v15 = 0;
  v13 = 0;
  v5 = strnlen((const char *)(a1 + 40), 0x20u);
  if ( v5 >= 0x21 )
  {
    _fortify_panic(2, 32, v5 + 1);
    goto LABEL_18;
  }
  if ( v5 == 32 )
    v6 = 32;
  else
    v6 = v5 + 1;
  if ( v6 >= 0x22 )
LABEL_18:
    _fortify_panic(7, 33, v6);
  sized_strscpy(v14, a1 + 40);
  HIBYTE(v15) = a2;
  mutex_lock(v4 + 312);
  v7 = qmi_txn_init(v4 + 8, v12, &tmd_set_mitigation_level_resp_msg_v01_ei, &v13);
  if ( (v7 & 0x80000000) != 0 )
  {
    v8 = v7;
    v9 = &unk_8074;
  }
  else
  {
    v8 = qmi_send_request(v4 + 8, 0, v12, 33, 40, &tmd_set_mitigation_level_req_msg_v01_ei, v14);
    if ( (v8 & 0x80000000) != 0 )
    {
      printk(&unk_80AC, "qti_qmi_cdev", "qmi_tmd_send_state_request", a2, a1 + 8);
      qmi_txn_cancel(v12);
      goto LABEL_11;
    }
    v11 = qmi_txn_wait(v12, 25);
    if ( (v11 & 0x80000000) != 0 )
    {
      v8 = v11;
      v9 = &unk_80E4;
    }
    else
    {
      v8 = (unsigned __int16)v13;
      if ( !(_WORD)v13 )
      {
        printk(&unk_8015, "qti_qmi_cdev", "qmi_tmd_send_state_request", a2, a1 + 8);
        goto LABEL_11;
      }
      v9 = &unk_7F33;
    }
  }
  printk(v9, "qti_qmi_cdev", "qmi_tmd_send_state_request", a2, a1 + 8);
LABEL_11:
  mutex_unlock(v4 + 312);
  _ReadStatusReg(SP_EL0);
  return v8;
}
