__int64 __fastcall ipa3_socksv5_msg_free_cb(const void *a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  const void *v6; // x19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  if ( a1 )
  {
    if ( (unsigned int)(a3 - 48) <= 0xFFFFFFFD )
    {
      v6 = a1;
      printk(&unk_3B76CF, "ipa3_socksv5_msg_free_cb");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d Wrong type given. buff %pK type %d\n",
            "ipa3_socksv5_msg_free_cb",
            14569,
            v6,
            a3);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(
            v10,
            "ipa %s:%d Wrong type given. buff %pK type %d\n",
            "ipa3_socksv5_msg_free_cb",
            14569,
            v6,
            a3);
      }
      a1 = v6;
    }
    return kfree(a1);
  }
  else
  {
    result = printk(&unk_3B18C1, "ipa3_socksv5_msg_free_cb");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d Null buffer\n", "ipa3_socksv5_msg_free_cb", 14563);
        v4 = ipa3_ctx;
      }
      result = *(_QWORD *)(v4 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d Null buffer\n", "ipa3_socksv5_msg_free_cb", 14563);
    }
  }
  return result;
}
