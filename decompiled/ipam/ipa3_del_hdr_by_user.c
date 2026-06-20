__int64 __fastcall ipa3_del_hdr_by_user(_BYTE *a1, char a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x21
  int *v6; // x27
  int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w19
  unsigned int (__fastcall *v14)(_QWORD); // x8

  if ( a1 && a1[1] )
  {
    v4 = mutex_lock(ipa3_ctx + 29472);
    if ( a1[1] )
    {
      v5 = 0;
      v6 = (int *)(a1 + 8);
      do
      {
        v4 = _ipa3_del_hdr((unsigned int)*(v6 - 1), a2 & 1);
        if ( !(_DWORD)v4 )
        {
          v7 = 0;
          goto LABEL_6;
        }
        v4 = __ratelimit(&ipa3_del_hdr_by_user__rs_45, "ipa3_del_hdr_by_user");
        if ( (_DWORD)v4 )
        {
          v4 = printk(&unk_3F53BA, "ipa3_del_hdr_by_user");
          v8 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_10:
            v9 = *(_QWORD *)(v8 + 34152);
            if ( v9 )
            {
              ipc_log_string(v9, "ipa %s:%d failed to del hdr %i\n", "ipa3_del_hdr_by_user", 1105, v5);
              v8 = ipa3_ctx;
            }
            v4 = *(_QWORD *)(v8 + 34160);
            if ( v4 )
              v4 = ipc_log_string(v4, "ipa %s:%d failed to del hdr %i\n", "ipa3_del_hdr_by_user", 1105, v5);
          }
        }
        else
        {
          v8 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_10;
        }
        v7 = -1;
LABEL_6:
        *v6 = v7;
        v6 += 2;
        ++v5;
      }
      while ( v5 < (unsigned __int8)a1[1] );
    }
    if ( !*a1 )
      goto LABEL_30;
    v14 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 128LL);
    if ( *((_DWORD *)v14 - 1) != 1874538549 )
      __break(0x8228u);
    if ( v14(v4) )
      v13 = -1;
    else
LABEL_30:
      v13 = 0;
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_del_hdr_by_user__rs, "ipa3_del_hdr_by_user") )
      printk(&unk_3FB3F2, "ipa3_del_hdr_by_user");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d bad parm\n", "ipa3_del_hdr_by_user", 1098);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d bad parm\n", "ipa3_del_hdr_by_user", 1098);
    }
    return (unsigned int)-22;
  }
  return v13;
}
