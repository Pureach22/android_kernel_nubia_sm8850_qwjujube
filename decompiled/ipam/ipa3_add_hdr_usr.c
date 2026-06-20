__int64 __fastcall ipa3_add_hdr_usr(_BYTE *a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 v7; // x21
  int *v8; // x27
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int (__fastcall *v18)(_QWORD); // x8

  if ( a1 && a1[1] )
  {
    v4 = mutex_lock(ipa3_ctx + 29472);
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d adding %d headers to IPA driver internal data struct\n",
          "ipa3_add_hdr_usr",
          1059,
          (unsigned __int8)a1[1]);
        v5 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v5 + 34160);
      if ( v4 )
        v4 = ipc_log_string(
               v4,
               "ipa %s:%d adding %d headers to IPA driver internal data struct\n",
               "ipa3_add_hdr_usr",
               1059,
               (unsigned __int8)a1[1]);
    }
    if ( a1[1] )
    {
      v7 = 0;
      v8 = (int *)(a1 + 304);
      do
      {
        v4 = _ipa_add_hdr(v8 - 75, a2 & 1, 0);
        if ( !(_DWORD)v4 )
        {
          v9 = 0;
          goto LABEL_11;
        }
        v4 = __ratelimit(&ipa3_add_hdr_usr__rs_42, "ipa3_add_hdr_usr");
        if ( (_DWORD)v4 )
        {
          v4 = printk(&unk_3EC507, "ipa3_add_hdr_usr");
          v10 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_15:
            v11 = *(_QWORD *)(v10 + 34152);
            if ( v11 )
            {
              ipc_log_string(v11, "ipa %s:%d failed to add hdr %d\n", "ipa3_add_hdr_usr", 1062, v7);
              v10 = ipa3_ctx;
            }
            v4 = *(_QWORD *)(v10 + 34160);
            if ( v4 )
              v4 = ipc_log_string(v4, "ipa %s:%d failed to add hdr %d\n", "ipa3_add_hdr_usr", 1062, v7);
          }
        }
        else
        {
          v10 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_15;
        }
        v9 = -1;
LABEL_11:
        *v8 = v9;
        ++v7;
        v8 += 77;
      }
      while ( v7 < (unsigned __int8)a1[1] );
    }
    if ( !*a1 )
      goto LABEL_40;
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d committing all headers to IPA core", "ipa3_add_hdr_usr", 1070);
        v16 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v16 + 34160);
      if ( v4 )
      {
        v4 = ipc_log_string(v4, "ipa %s:%d committing all headers to IPA core", "ipa3_add_hdr_usr", 1070);
        v16 = ipa3_ctx;
      }
    }
    v18 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v16 + 34176) + 128LL);
    if ( *((_DWORD *)v18 - 1) != 1874538549 )
      __break(0x8228u);
    if ( v18(v4) )
      v15 = -1;
    else
LABEL_40:
      v15 = 0;
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_hdr_usr__rs, "ipa3_add_hdr_usr") )
      printk(&unk_3FB3F2, "ipa3_add_hdr_usr");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d bad parm\n", "ipa3_add_hdr_usr", 1053);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d bad parm\n", "ipa3_add_hdr_usr", 1053);
    }
    return (unsigned int)-22;
  }
  return v15;
}
