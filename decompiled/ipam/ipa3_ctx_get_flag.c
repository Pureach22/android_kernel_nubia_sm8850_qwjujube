__int64 __fastcall ipa3_ctx_get_flag(int a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 v4; // x0
  __int64 v5; // x0

  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      v2 = 32260;
    }
    else
    {
      if ( a1 != 3 )
        goto LABEL_13;
      v2 = 32270;
    }
LABEL_11:
    LOBYTE(v1) = *(_BYTE *)(ipa3_ctx + v2);
    return v1 & 1;
  }
  if ( !a1 )
  {
    v2 = 32268;
    goto LABEL_11;
  }
  if ( a1 == 1 )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 43800);
    if ( v1 )
      LOBYTE(v1) = *(_BYTE *)v1;
    return v1 & 1;
  }
LABEL_13:
  printk(&unk_3D91BA, "ipa3_ctx_get_flag");
  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d cannot read ipa3_ctx flags\n", "ipa3_ctx_get_flag", 13929);
      v1 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v1 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d cannot read ipa3_ctx flags\n", "ipa3_ctx_get_flag", 13929);
    LOBYTE(v1) = 0;
  }
  return v1 & 1;
}
