unsigned __int64 ipa_pc_qmp_enable()
{
  __int64 v0; // x8
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned __int64 result; // x0
  int v6; // w19
  __int64 v7; // x8
  int v8; // w4
  __int64 v9; // x0
  int v10; // w0
  int v11; // w20
  __int64 v12; // x8
  int v13; // w4
  __int64 v14; // x0
  __int64 v15; // x0
  _DWORD v16[10]; // [xsp+18h] [xbp-68h] BYREF
  __int64 v17; // [xsp+40h] [xbp-40h]
  __int64 v18; // [xsp+48h] [xbp-38h]
  __int64 v19; // [xsp+50h] [xbp-30h]
  __int64 v20; // [xsp+58h] [xbp-28h]
  __int64 v21; // [xsp+60h] [xbp-20h]
  __int64 v22; // [xsp+68h] [xbp-18h]
  __int64 v23; // [xsp+70h] [xbp-10h]
  __int64 v24; // [xsp+78h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  strcpy((char *)v16, "{class: bcm, res: ipa_pc, val: 1}");
  v0 = ipa3_ctx;
  HIWORD(v16[8]) = 0;
  v16[9] = 0;
  v17 = 0;
  v1 = ipa3_ctx + 44960;
  v18 = 0;
  v19 = 0;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d Enter\n", "ipa_pc_qmp_enable", 12323);
      v0 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v0 + 34160);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Enter\n", "ipa_pc_qmp_enable", 12323);
      v0 = ipa3_ctx;
    }
  }
  v4 = *(_QWORD *)(v0 + 34208);
  *(_BYTE *)(v1 + 8) = 1;
  *(_QWORD *)(v1 + 16) = 100;
  *(_QWORD *)v1 = v4 + 16;
  *(_BYTE *)(v1 + 24) = 0;
  result = mbox_request_channel(v1, 0);
  *(_QWORD *)(v1 + 56) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v10 = mbox_send_message();
    if ( v10 < 0 )
    {
      v11 = v10;
      printk(&unk_3DA98E, "ipa_pc_qmp_enable");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = v11;
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d qmp message send failed, ret=%d\n", "ipa_pc_qmp_enable", 12347, v11);
          v12 = ipa3_ctx;
          v13 = v11;
        }
        v15 = *(_QWORD *)(v12 + 34160);
        if ( v15 )
          ipc_log_string(v15, "ipa %s:%d qmp message send failed, ret=%d\n", "ipa_pc_qmp_enable", 12347, v13);
      }
    }
    result = *(_QWORD *)(v1 + 56);
    if ( result )
    {
      result = mbox_free_channel();
      *(_QWORD *)(v1 + 56) = 0;
    }
  }
  else if ( (_DWORD)result != -517 )
  {
    v6 = result;
    result = printk(&unk_3F6FE8, "ipa_pc_qmp_enable");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = v6;
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d mailbox channel request failed, ret=%d\n", "ipa_pc_qmp_enable", 12335, v6);
        v7 = ipa3_ctx;
        v8 = v6;
      }
      result = *(_QWORD *)(v7 + 34160);
      if ( result )
        result = ipc_log_string(
                   result,
                   "ipa %s:%d mailbox channel request failed, ret=%d\n",
                   "ipa_pc_qmp_enable",
                   12335,
                   v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
