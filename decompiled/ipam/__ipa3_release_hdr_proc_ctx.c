__int64 __fastcall _ipa3_release_hdr_proc_ctx(__int64 a1)
{
  int v1; // w19
  int v2; // w0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  __int64 (*v7)(void); // x8
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  v1 = a1;
  v2 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))_ipa3_del_hdr_proc_ctx)(a1, 1, 0);
  v3 = ipa3_ctx;
  if ( v2 )
  {
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d fail to del hdr %x\n", "__ipa3_release_hdr_proc_ctx", 1660, v1);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d fail to del hdr %x\n", "__ipa3_release_hdr_proc_ctx", 1660, v1);
    }
    return 4294967282LL;
  }
  v7 = *(__int64 (**)(void))(*(_QWORD *)(ipa3_ctx + 34176) + 128LL);
  if ( *((_DWORD *)v7 - 1) != 1874538549 )
    __break(0x8228u);
  result = v7();
  if ( (_DWORD)result )
  {
    printk(&unk_3B501F, "__ipa3_release_hdr_proc_ctx");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d fail to commit hdr\n", "__ipa3_release_hdr_proc_ctx", 1667);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d fail to commit hdr\n", "__ipa3_release_hdr_proc_ctx", 1667);
    }
    return 4294967282LL;
  }
  return result;
}
