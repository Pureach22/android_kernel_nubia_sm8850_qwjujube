__int64 __fastcall ipa3_enable_ipc_low(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v4 = kstrtos8_from_user(a2, a3, 0, v11);
  if ( v4 )
  {
    v3 = v4;
  }
  else
  {
    mutex_lock(ipa3_ctx + 29472);
    if ( v11[0] )
    {
      if ( !ipa_ipc_low_buff )
      {
        ipa_ipc_low_buff = ipc_log_context_create(50, "ipa_low", 0x10000);
        if ( !ipa_ipc_low_buff )
        {
          v8 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v9 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v9 )
            {
              ipc_log_string(v9, "ipa %s:%d failed to get logbuf_low\n", "ipa3_enable_ipc_low", 3171);
              v8 = ipa3_ctx;
            }
            v10 = *(_QWORD *)(v8 + 34160);
            if ( v10 )
              ipc_log_string(v10, "ipa %s:%d failed to get logbuf_low\n", "ipa3_enable_ipc_low", 3171);
          }
        }
      }
      v5 = ipa_ipc_low_buff;
    }
    else
    {
      v5 = 0;
    }
    v6 = ipa3_ctx;
    *(_QWORD *)(ipa3_ctx + 34160) = v5;
    mutex_unlock(v6 + 29472);
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
