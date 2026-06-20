__int64 __fastcall pdr_indack_work(__int64 result)
{
  _QWORD *v1; // x22
  __int64 v2; // x28
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x24
  _QWORD *v7; // x23
  __int64 v8; // x25
  __int64 v9; // x2
  void (__fastcall *v10)(__int64, __int64, __int64); // x8
  __int64 v11; // x0
  __int16 v12; // w26
  size_t v13; // x0
  unsigned __int64 v14; // x2
  _QWORD *v15; // x8
  __int64 v16; // x9
  _QWORD v17[9]; // [xsp+0h] [xbp-A0h] BYREF
  int v18; // [xsp+4Ch] [xbp-54h] BYREF
  _QWORD v19[8]; // [xsp+50h] [xbp-50h] BYREF
  __int16 v20; // [xsp+90h] [xbp-10h]
  __int16 v21; // [xsp+92h] [xbp-Eh]
  __int64 v22; // [xsp+98h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = result - 232;
  v1 = *(_QWORD **)(result - 232);
  if ( v1 != (_QWORD *)(result - 232) )
  {
    v3 = result;
    v4 = result - 168;
    v5 = result - 568;
    v6 = result - 216;
    do
    {
      v8 = *(v1 - 1);
      v7 = (_QWORD *)*v1;
      mutex_lock(v4);
      *(_DWORD *)(v8 + 160) = *((_DWORD *)v1 - 4);
      mod_timer(v1 + 2, jiffies + 2250LL);
      v10 = *(void (__fastcall **)(__int64, __int64, __int64))(v3 + 48);
      v9 = *(_QWORD *)(v3 + 56);
      v11 = *(unsigned int *)(v8 + 160);
      if ( *((_DWORD *)v10 - 1) != -1320911916 )
        __break(0x8228u);
      v10(v11, v8 + 65, v9);
      timer_delete_sync(v1 + 2);
      mutex_unlock(v4);
      v12 = *((_WORD *)v1 - 6);
      v18 = 0;
      v20 = 0;
      memset(v19, 0, sizeof(v19));
      memset(v17, 0, sizeof(v17));
      if ( (qmi_txn_init(v5, v17, &servreg_set_ack_resp_ei, &v18) & 0x80000000) == 0 )
      {
        v21 = v12;
        v13 = strnlen((const char *)(v8 + 65), 0x41u);
        if ( v13 >= 0x42 )
        {
          _fortify_panic(2, 65, v13 + 1);
LABEL_20:
          _fortify_panic(7, 65, v14);
        }
        if ( v13 == 65 )
          v14 = 65;
        else
          v14 = v13 + 1;
        if ( v14 >= 0x42 )
          goto LABEL_20;
        sized_strscpy(v19, v8 + 65);
        qmi_send_request(v5, v8 + 132, v17, 35, 72, &servreg_set_ack_req_ei, v19);
        qmi_txn_cancel(v17);
      }
      printk(&unk_7717, v8 + 65, *(unsigned int *)(v8 + 160), *((unsigned __int16 *)v1 - 6));
      mutex_lock(v6);
      v15 = (_QWORD *)v1[1];
      if ( (_QWORD *)*v15 == v1 && (v16 = *v1, *(_QWORD **)(*v1 + 8LL) == v1) )
      {
        *(_QWORD *)(v16 + 8) = v15;
        *v15 = v16;
      }
      else
      {
        _list_del_entry_valid_or_report(v1);
      }
      *v1 = 0xDEAD000000000100LL;
      v1[1] = 0xDEAD000000000122LL;
      mutex_unlock(v6);
      result = kfree(v1 - 2);
      v1 = v7;
    }
    while ( v7 != (_QWORD *)v2 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
