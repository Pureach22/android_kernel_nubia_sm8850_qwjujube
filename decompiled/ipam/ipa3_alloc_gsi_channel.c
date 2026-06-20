__int64 ipa3_alloc_gsi_channel()
{
  unsigned int v0; // w20
  int v1; // w24
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  unsigned int v12; // w20
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  if ( !*(_DWORD *)(ipa3_ctx + 34308) )
  {
LABEL_16:
    result = 0;
    goto LABEL_17;
  }
  v0 = 0;
  while ( 1 )
  {
    v1 = ((__int64 (__fastcall *)(_QWORD))ipa3_get_client_by_pipe)(v0);
    v2 = ((__int64 (*)(void))ipa_get_gsi_ep_info)();
    v3 = ipa3_ctx;
    v4 = v2;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d for ep %d client is %d\n", "ipa3_alloc_gsi_channel", 7775, v0, v1);
        v3 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v3 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d for ep %d client is %d\n", "ipa3_alloc_gsi_channel", 7775, v0, v1);
    }
    if ( !v4 )
      goto LABEL_3;
    v7 = gsi_alloc_channel_ee(*(unsigned int *)(v4 + 4), *(unsigned int *)(v4 + 16), &v16);
    if ( v7 )
      break;
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(
          v9,
          "ipa %s:%d alloc gsi ch %d ee %d with code %d\n",
          "ipa3_alloc_gsi_channel",
          7785,
          *(_DWORD *)(v4 + 4),
          *(_DWORD *)(v4 + 16),
          v16);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(
          v10,
          "ipa %s:%d alloc gsi ch %d ee %d with code %d\n",
          "ipa3_alloc_gsi_channel",
          7785,
          *(_DWORD *)(v4 + 4),
          *(_DWORD *)(v4 + 16),
          v16);
    }
LABEL_3:
    if ( ++v0 >= *(_DWORD *)(ipa3_ctx + 34308) )
      goto LABEL_16;
  }
  v12 = v7;
  printk(&unk_3B1A28, "ipa3_alloc_gsi_channel");
  v13 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d failed to alloc ch %d ee %d code %d\n",
        "ipa3_alloc_gsi_channel",
        7790,
        *(_DWORD *)(v4 + 4),
        *(_DWORD *)(v4 + 16),
        v16);
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
      ipc_log_string(
        v15,
        "ipa %s:%d failed to alloc ch %d ee %d code %d\n",
        "ipa3_alloc_gsi_channel",
        7790,
        *(_DWORD *)(v4 + 4),
        *(_DWORD *)(v4 + 16),
        v16);
  }
  result = v12;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
