__int64 __fastcall ipa3_uc_register_handlers(unsigned int a1, void **a2)
{
  __int64 v4; // x1
  void **v5; // x9
  void *v6; // x8
  void *v7; // x11
  void *v8; // x12
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0

  if ( a1 >= 8 )
  {
    result = printk(&unk_3FE86A, "ipa3_uc_register_handlers");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(
          v14,
          "ipa %s:%d Feature %u is invalid, not registering hdlrs\n",
          "ipa3_uc_register_handlers",
          1281,
          a1);
        v13 = ipa3_ctx;
      }
      result = *(_QWORD *)(v13 + 34160);
      if ( result )
        return ipc_log_string(
                 result,
                 "ipa %s:%d Feature %u is invalid, not registering hdlrs\n",
                 "ipa3_uc_register_handlers",
                 1281,
                 a1);
    }
  }
  else
  {
    if ( *(_BYTE *)(ipa3_ctx + 43308) == 1 )
    {
      v4 = raw_spin_lock_irqsave(ipa3_ctx + 34712);
    }
    else
    {
      mutex_lock(ipa3_ctx + 34664);
      v4 = 0;
    }
    v5 = (void **)(&ipa3_uc_hdlrs + 5 * a1);
    *v5 = *a2;
    v6 = a2[4];
    v7 = a2[1];
    v8 = a2[2];
    v5[3] = a2[3];
    v5[4] = v6;
    v9 = ipa3_ctx;
    v5[1] = v7;
    v5[2] = v8;
    if ( *(_BYTE *)(v9 + 43308) == 1 )
    {
      result = raw_spin_unlock_irqrestore(v9 + 34712, v4);
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        return result;
    }
    else
    {
      result = mutex_unlock(v9 + 34664);
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        return result;
    }
    v12 = *(_QWORD *)(v11 + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d uC handlers registered for feature %u\n", "ipa3_uc_register_handlers", 1289, a1);
      v11 = ipa3_ctx;
    }
    result = *(_QWORD *)(v11 + 34160);
    if ( result )
      return ipc_log_string(
               result,
               "ipa %s:%d uC handlers registered for feature %u\n",
               "ipa3_uc_register_handlers",
               1289,
               a1);
  }
  return result;
}
