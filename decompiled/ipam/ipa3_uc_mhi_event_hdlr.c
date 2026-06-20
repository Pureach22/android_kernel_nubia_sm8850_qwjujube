__int64 __fastcall ipa3_uc_mhi_event_hdlr(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  int v3; // w10
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w22
  unsigned int v8; // w20
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  unsigned int v13; // w20
  __int64 v14; // x0
  unsigned int v15; // w19
  __int64 v16; // x0
  __int64 (*v17)(void); // x8

  v1 = result;
  v2 = ipa3_ctx;
  v3 = *(unsigned __int8 *)(*(_QWORD *)(ipa3_ctx + 34752) + 20LL);
  if ( v3 == 33 )
  {
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d WakeUp channel request\n", "ipa3_uc_mhi_event_hdlr", 516);
        v2 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v2 + 34160);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d WakeUp channel request\n", "ipa3_uc_mhi_event_hdlr", 516);
        v2 = ipa3_ctx;
      }
      if ( v2 )
      {
        v13 = *(_DWORD *)(v1 + 24);
        v14 = *(_QWORD *)(v2 + 34152);
        v15 = v13 >> 8;
        if ( v14 )
        {
          ipc_log_string(
            v14,
            "ipa %s:%d channelHandle=%d reserved=%d\n",
            "ipa3_uc_mhi_event_hdlr",
            519,
            (unsigned __int8)v13,
            v15);
          v2 = ipa3_ctx;
        }
        v16 = *(_QWORD *)(v2 + 34160);
        if ( v16 )
          ipc_log_string(
            v16,
            "ipa %s:%d channelHandle=%d reserved=%d\n",
            "ipa3_uc_mhi_event_hdlr",
            519,
            (unsigned __int8)v13,
            v15);
      }
    }
    v17 = *(__int64 (**)(void))(ipa3_uc_mhi_ctx + 16);
    if ( *((_DWORD *)v17 - 1) != -440107680 )
      __break(0x8228u);
    return v17();
  }
  else if ( v3 == 32 )
  {
    printk(&unk_3C7A44, "ipa3_uc_mhi_event_hdlr");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d Channel error\n", "ipa3_uc_mhi_event_hdlr", 507);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d Channel error\n", "ipa3_uc_mhi_event_hdlr", 507);
    }
    v7 = *(_DWORD *)(v1 + 24);
    v8 = HIWORD(v7);
    result = printk(&unk_3E171B, "ipa3_uc_mhi_event_hdlr");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(
          v10,
          "ipa %s:%d errorType=%d channelHandle=%d reserved=%d\n",
          "ipa3_uc_mhi_event_hdlr",
          511,
          (unsigned __int8)v7,
          BYTE1(v7),
          v8);
        v9 = ipa3_ctx;
      }
      result = *(_QWORD *)(v9 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d errorType=%d channelHandle=%d reserved=%d\n",
                 "ipa3_uc_mhi_event_hdlr",
                 511,
                 (unsigned __int8)v7,
                 BYTE1(v7),
                 v8);
    }
  }
  return result;
}
