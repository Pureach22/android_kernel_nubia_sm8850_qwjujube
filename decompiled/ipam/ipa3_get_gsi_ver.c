__int64 __fastcall ipa3_get_gsi_ver(int a1)
{
  unsigned int v1; // w19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( (unsigned int)(a1 - 10) < 0xF )
  {
    v1 = dword_1B1E70[a1 - 10];
    v2 = ipa3_ctx;
    if ( !ipa3_ctx )
      return v1;
    goto LABEL_3;
  }
  printk(&unk_3CBDAD, "ipa3_get_gsi_ver");
  v7 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d No GSI version for ipa type %d\n", "ipa3_get_gsi_ver", 7738, a1);
      v7 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v7 + 34160);
    if ( v9 )
      ipc_log_string(v9, "ipa %s:%d No GSI version for ipa type %d\n", "ipa3_get_gsi_ver", 7738, a1);
  }
  v1 = 0;
  __break(0x800u);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
LABEL_3:
    v3 = *(_QWORD *)(v2 + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d GSI version %d\n", "ipa3_get_gsi_ver", 7743, v1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d GSI version %d\n", "ipa3_get_gsi_ver", 7743, v1);
  }
  return v1;
}
