__int64 ipa3_inject_dma_task_for_gsi()
{
  __int64 v0; // x8
  _WORD *v1; // x9
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // [xsp+0h] [xbp-70h] BYREF
  _WORD *v9; // [xsp+8h] [xbp-68h]
  __int64 v10; // [xsp+10h] [xbp-60h]
  __int64 v11; // [xsp+18h] [xbp-58h]
  __int64 v12; // [xsp+20h] [xbp-50h]
  __int64 v13; // [xsp+28h] [xbp-48h]
  __int64 v14; // [xsp+30h] [xbp-40h]
  __int64 v15; // [xsp+38h] [xbp-38h]
  __int64 v16; // [xsp+40h] [xbp-30h]
  __int64 v17; // [xsp+48h] [xbp-28h]
  __int64 v18; // [xsp+50h] [xbp-20h]
  __int64 v19; // [xsp+58h] [xbp-18h]
  __int64 v20; // [xsp+60h] [xbp-10h]
  __int64 v21; // [xsp+68h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v1 = *(_WORD **)(ipa3_ctx + 43792);
  v8 = 0;
  v9 = nullptr;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v20 = 0;
  WORD2(v12) = v1[1];
  v9 = v1 + 2;
  WORD1(v12) = *v1;
  LODWORD(v8) = 3;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d sending 1B packet to IPA\n", "ipa3_inject_dma_task_for_gsi", 13169);
      v0 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v0 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d sending 1B packet to IPA\n", "ipa3_inject_dma_task_for_gsi", 13169);
  }
  result = ipa3_send_cmd_timeout(1u, (__int64)&v8, 0xFu);
  if ( (_DWORD)result )
  {
    printk(&unk_3F5EE8, "ipa3_inject_dma_task_for_gsi");
    v5 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d ipa3_send_cmd failed\n", "ipa3_inject_dma_task_for_gsi", 13172);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d ipa3_send_cmd failed\n", "ipa3_inject_dma_task_for_gsi", 13172);
    }
    result = 4294967282LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
