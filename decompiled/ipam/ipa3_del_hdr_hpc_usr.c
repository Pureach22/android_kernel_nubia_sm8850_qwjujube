__int64 __fastcall ipa3_del_hdr_hpc_usr(_BYTE *a1, char a2)
{
  __int64 v4; // x0
  unsigned __int64 v5; // x22
  _BOOL4 v6; // w24
  unsigned int *v7; // x23
  int v8; // w8
  __int64 v9; // x25
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int v14; // w19
  unsigned int (__fastcall *v15)(_QWORD); // x8

  if ( a1 && a1[1] )
  {
    v4 = mutex_lock(ipa3_ctx + 29472);
    if ( a1[1] )
    {
      v5 = 0;
      v6 = 0;
      v7 = (unsigned int *)(a1 + 4);
      do
      {
        v4 = ipa3_id_find(*v7);
        if ( v4 )
        {
          v8 = *(_DWORD *)(v4 + 336);
          v9 = *(_QWORD *)(v4 + 320);
          *(_QWORD *)(v4 + 320) = 0;
          *(_DWORD *)(v4 + 336) = v8 - 1;
          v4 = _ipa3_del_hdr(*v7, a2 & 1);
          v6 = v4 != 0;
          if ( v9 )
          {
            v10 = *(unsigned int *)(v9 + 76);
            --*(_DWORD *)(v9 + 72);
            v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))_ipa3_del_hdr_proc_ctx)(v10, 0, 0);
            v6 = v4 != 0;
          }
        }
        v7[1] = v6;
        ++v5;
        v7 += 2;
      }
      while ( v5 < (unsigned __int8)a1[1] );
    }
    if ( !*a1 )
      goto LABEL_22;
    v15 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 128LL);
    if ( *((_DWORD *)v15 - 1) != 1874538549 )
      __break(0x8228u);
    if ( v15(v4) )
      v14 = -1;
    else
LABEL_22:
      v14 = 0;
    mutex_unlock(ipa3_ctx + 29472);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_del_hdr_hpc_usr__rs, "ipa3_del_hdr_hpc_usr") )
      printk(&unk_3FB3F2, "ipa3_del_hdr_hpc_usr");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d bad parm\n", "ipa3_del_hdr_hpc_usr", 972);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d bad parm\n", "ipa3_del_hdr_hpc_usr", 972);
    }
    return (unsigned int)-22;
  }
  return v14;
}
