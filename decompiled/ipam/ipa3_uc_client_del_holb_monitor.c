__int64 __fastcall ipa3_uc_client_del_holb_monitor(unsigned __int16 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x3
  __int64 v7; // x24
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x22
  __int64 v12; // x9
  _DWORD *v14; // x19
  __int64 v15; // x8
  unsigned __int8 v16; // w1
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  unsigned int v22; // w21
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0

  if ( *(_BYTE *)(ipa3_ctx + 34904) != 1 )
    return 0;
  v4 = mutex_lock(ipa3_ctx + 43096);
  v7 = ipa3_ctx;
  v8 = *(unsigned int *)(ipa3_ctx + 34912);
  if ( (int)v8 < 1 )
  {
LABEL_31:
    printk(&unk_3E4374, "ipa3_uc_client_del_holb_monitor");
    v23 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967274LL;
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d Invalid client with GSI chan %d\n", "ipa3_uc_client_del_holb_monitor", 188, a1);
      v23 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v23 + 34160);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d Invalid client with GSI chan %d\n", "ipa3_uc_client_del_holb_monitor", 188, a1);
      return 4294967274LL;
    }
    else
    {
      return 4294967274LL;
    }
  }
  else
  {
    v9 = 0;
    v10 = 0;
    v11 = ipa3_ctx + 34932;
    v12 = 272 * v8;
    while ( 1 )
    {
      if ( v9 == -31 )
        goto LABEL_37;
      if ( *(unsigned __int16 *)(v11 + v10) == a1 )
        break;
      v10 += 272;
      --v9;
      if ( v12 == v10 )
        goto LABEL_31;
    }
    if ( (_DWORD)v9 == 22 )
      goto LABEL_31;
    if ( (unsigned int)-(int)v9 < 0x1F )
    {
      if ( (unsigned int)ipa3_uc_holb_enabled_check() && (v14 = (_DWORD *)(v7 + v10 + 34948), *v14 == 2) )
      {
        v15 = ipa3_ctx;
        v16 = a2;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(
              v17,
              "ipa %s:%d GSI chan %d going from ADD to DEL state\n",
              "ipa3_uc_client_del_holb_monitor",
              196,
              *(unsigned __int16 *)(v11 + v10));
            v15 = ipa3_ctx;
            v16 = a2;
          }
          v18 = *(_QWORD *)(v15 + 34160);
          if ( v18 )
          {
            ipc_log_string(
              v18,
              "ipa %s:%d GSI chan %d going from ADD to DEL state\n",
              "ipa3_uc_client_del_holb_monitor",
              196,
              *(unsigned __int16 *)(v11 + v10));
            v16 = a2;
          }
        }
        LODWORD(v19) = ipa3_uc_del_holb_monitor(*(_WORD *)(v11 + v10), v16);
      }
      else
      {
        if ( (unsigned int)ipa3_uc_holb_enabled_check() || (v14 = (_DWORD *)(v7 + v10 + 34948), *v14 != 1) )
        {
          v22 = 0;
          goto LABEL_29;
        }
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v21 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v21 )
          {
            ipc_log_string(
              v21,
              "ipa %s:%d GSI chan %d going from ADD_PENDING to DEL state\n",
              "ipa3_uc_client_del_holb_monitor",
              203,
              *(unsigned __int16 *)(v11 + v10));
            v20 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v20 + 34160);
          if ( !v19 )
            goto LABEL_27;
          ipc_log_string(
            v19,
            "ipa %s:%d GSI chan %d going from ADD_PENDING to DEL state\n",
            "ipa3_uc_client_del_holb_monitor",
            203,
            *(unsigned __int16 *)(v11 + v10));
        }
        LODWORD(v19) = 0;
      }
LABEL_27:
      v22 = v19;
      *v14 = 3;
LABEL_29:
      mutex_unlock(ipa3_ctx + 43096);
      return v22;
    }
LABEL_37:
    __break(0x5512u);
    return ipa3_uc_holb_event_log(v4, v5, -1284083712, v6);
  }
}
