__int64 __fastcall ipa3_send_macsec_info(char a1, __int64 a2)
{
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v11 = 0x400000;
    LOBYTE(v11) = a1;
    v3 = ipa_send_msg(&v11, a2, ipa3_general_free_cb);
    if ( v3 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_send_macsec_info__rs, "ipa3_send_macsec_info") )
        printk(&unk_3A28DF, "ipa3_send_macsec_info");
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(v5, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_macsec_info", 2821, v3);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
          ipc_log_string(v6, "ipa %s:%d ipa_send_msg failed: %d\n", "ipa3_send_macsec_info", 2821, v3);
      }
      kfree(a2);
    }
  }
  else
  {
    printk(&unk_3EE270, "ipa3_send_macsec_info");
    v8 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_17;
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Bad arg: info is NULL\n", "ipa3_send_macsec_info", 2803);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d Bad arg: info is NULL\n", "ipa3_send_macsec_info", 2803);
      v3 = -5;
    }
    else
    {
LABEL_17:
      v3 = -5;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
