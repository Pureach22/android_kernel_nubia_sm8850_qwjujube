__int64 __fastcall pdr_notifier_work(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *i; // x27
  __int64 v4; // x2
  void (__fastcall *v5)(__int64, char *, __int64); // x8
  __int64 v6; // x0
  size_t v7; // x0
  unsigned __int64 v8; // x2
  unsigned int v9; // w0
  __int64 v10; // x3
  __int64 v11; // x2
  void *v12; // x0
  __int64 result; // x0
  _QWORD v14[9]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v15; // [xsp+50h] [xbp-60h] BYREF
  int v16; // [xsp+58h] [xbp-58h]
  char v17; // [xsp+5Ch] [xbp-54h] BYREF
  _BYTE v18[67]; // [xsp+5Dh] [xbp-53h] BYREF
  __int64 v19; // [xsp+A0h] [xbp-10h]

  v1 = a1 - 184;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(a1 - 184);
  for ( i = *(_QWORD **)(a1 - 216); i != (_QWORD *)(a1 - 216); i = (_QWORD *)*i )
  {
    if ( *((_BYTE *)i - 1) == 1 )
    {
      if ( *((_BYTE *)i - 4) == 1 )
      {
        *((_BYTE *)i - 4) = 0;
        v16 = 0;
        v15 = 0;
        memset(v18, 0, 65);
        memset(v14, 0, sizeof(v14));
        if ( (qmi_txn_init(a1 - 536, v14, &servreg_register_listener_resp_ei, &v15) & 0x80000000) != 0 )
          goto LABEL_4;
        v17 = 1;
        v7 = strnlen((const char *)i - 103, 0x41u);
        if ( v7 >= 0x42 )
        {
          _fortify_panic(2, 65, v7 + 1);
LABEL_28:
          _fortify_panic(7, 65, v8);
        }
        if ( v7 == 65 )
          v8 = 65;
        else
          v8 = v7 + 1;
        if ( v8 >= 0x42 )
          goto LABEL_28;
        sized_strscpy(v18, (char *)i - 103);
        if ( (qmi_send_request(a1 - 536, (char *)i - 36, v14, 32, 71, &servreg_register_listener_req_ei, &v17)
            & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v14);
          goto LABEL_4;
        }
        v9 = qmi_txn_wait(v14, 1250);
        if ( (v9 & 0x80000000) != 0 )
        {
          v11 = v9;
          v12 = &unk_7754;
        }
        else
        {
          if ( !(_WORD)v15 )
          {
            *((_DWORD *)i - 2) = v16;
            goto LABEL_5;
          }
          v11 = WORD1(v15);
          v12 = &unk_78E7;
        }
        printk(v12, (char *)i - 103, v11, v10);
LABEL_4:
        *((_DWORD *)i - 2) = 0xFFFFFFF;
LABEL_5:
        mutex_lock(a1 - 136);
        v5 = *(void (__fastcall **)(__int64, char *, __int64))(a1 + 80);
        v4 = *(_QWORD *)(a1 + 88);
        v6 = *((unsigned int *)i - 2);
        if ( *((_DWORD *)v5 - 1) != -1320911916 )
          __break(0x8228u);
        v5(v6, (char *)i - 103, v4);
        mutex_unlock(a1 - 136);
      }
    }
    else if ( *((_BYTE *)i - 3) == 1 )
    {
      *((_BYTE *)i - 3) = 0;
      goto LABEL_4;
    }
  }
  result = mutex_unlock(v1);
  _ReadStatusReg(SP_EL0);
  return result;
}
