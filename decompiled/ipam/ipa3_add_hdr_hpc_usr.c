__int64 __fastcall ipa3_add_hdr_hpc_usr(_BYTE *a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned __int64 v7; // x21
  int *v8; // x23
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  int v15; // w8
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int v22; // w19
  __int64 v23; // x8
  __int64 v24; // x0
  unsigned int (__fastcall *v25)(_QWORD); // x8
  _DWORD v27[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v28; // [xsp+8h] [xbp-38h]
  __int64 v29; // [xsp+10h] [xbp-30h]
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  _QWORD v33[2]; // [xsp+30h] [xbp-10h] BYREF

  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a1[1] )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_hdr_hpc_usr__rs, "ipa3_add_hdr_hpc_usr") )
    {
      printk(&unk_3FB3F2, "ipa3_add_hdr_hpc_usr");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_36;
    }
    else
    {
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_36:
        v20 = *(_QWORD *)(v19 + 34152);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d bad parm\n", "ipa3_add_hdr_hpc_usr", 924);
          v19 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v19 + 34160);
        if ( v21 )
          ipc_log_string(v21, "ipa %s:%d bad parm\n", "ipa3_add_hdr_hpc_usr", 924);
      }
    }
    v22 = -22;
    goto LABEL_53;
  }
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
        "ipa3_add_hdr_hpc_usr",
        930,
        (unsigned __int8)a1[1]);
      v5 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v5 + 34160);
    if ( v4 )
      v4 = ipc_log_string(
             v4,
             "ipa %s:%d adding %d headers to IPA driver internal data struct\n",
             "ipa3_add_hdr_hpc_usr",
             930,
             (unsigned __int8)a1[1]);
  }
  if ( a1[1] )
  {
    v7 = 0;
    v8 = (int *)(a1 + 304);
    do
    {
      v33[0] = 0;
      *v8 = 11738;
      if ( !(unsigned int)_ipa_add_hdr(v8 - 75, a2 & 1, v33) )
      {
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(
              v13,
              "ipa %s:%d adding processing context for header %s\n",
              "__ipa_add_hpc_hdr_insertion",
              813,
              (const char *)v8 - 300);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(
              v14,
              "ipa %s:%d adding processing context for header %s\n",
              "__ipa_add_hpc_hdr_insertion",
              813,
              (const char *)v8 - 300);
        }
        v15 = *(v8 - 1);
        v31 = 0;
        v32 = 0;
        v29 = 0;
        v30 = 0;
        v28 = 0;
        v27[0] = 0;
        v27[1] = v15;
        if ( !(unsigned int)_ipa_add_hdr_proc_ctx(v27, a2 & 1) )
        {
          v4 = ipa3_id_find((unsigned int)v28);
          v9 = 0;
          *(_QWORD *)((char *)&unk_140 + v33[0]) = v4;
          ++*(_DWORD *)(v4 + 72);
          goto LABEL_11;
        }
        printk(&unk_3DE5B5, "__ipa_add_hpc_hdr_insertion");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d failed to add hdr proc ctx\n", "__ipa_add_hpc_hdr_insertion", 817);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d failed to add hdr proc ctx\n", "__ipa_add_hpc_hdr_insertion", 817);
        }
        _ipa3_del_hdr((unsigned int)*(v8 - 1), a2 & 1);
      }
      v4 = __ratelimit(&ipa3_add_hdr_hpc_usr__rs_38, "ipa3_add_hdr_hpc_usr");
      if ( (_DWORD)v4 )
      {
        v4 = printk(&unk_3B239B, "ipa3_add_hdr_hpc_usr");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_15:
          v11 = *(_QWORD *)(v10 + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d failed to add hdr hpc %d\n", "ipa3_add_hdr_hpc_usr", 933, v7);
            v10 = ipa3_ctx;
          }
          v4 = *(_QWORD *)(v10 + 34160);
          if ( v4 )
            v4 = ipc_log_string(v4, "ipa %s:%d failed to add hdr hpc %d\n", "ipa3_add_hdr_hpc_usr", 933, v7);
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
    goto LABEL_51;
  v23 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v24 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v24 )
    {
      ipc_log_string(v24, "ipa %s:%d committing all headers to IPA core", "ipa3_add_hdr_hpc_usr", 942);
      v23 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v23 + 34160);
    if ( v4 )
    {
      v4 = ipc_log_string(v4, "ipa %s:%d committing all headers to IPA core", "ipa3_add_hdr_hpc_usr", 942);
      v23 = ipa3_ctx;
    }
  }
  v25 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(v23 + 34176) + 128LL);
  if ( *((_DWORD *)v25 - 1) != 1874538549 )
    __break(0x8228u);
  if ( v25(v4) )
    v22 = -1;
  else
LABEL_51:
    v22 = 0;
  mutex_unlock(ipa3_ctx + 29472);
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v22;
}
