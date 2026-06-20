__int64 __fastcall ipa3_wan_msg_free_cb(const void *a1, __int64 a2, int a3)
{
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v8; // x8
  __int64 v9; // x0

  if ( a1 )
  {
    if ( (unsigned int)(a3 - 18) <= 0xFFFFFFFC )
    {
      result = printk(&unk_3B76CF, "ipa3_wan_msg_free_cb");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d Wrong type given. buff %pK type %d\n", "ipa3_wan_msg_free_cb", 1017, a1, a3);
          v8 = ipa3_ctx;
        }
        result = *(_QWORD *)(v8 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d Wrong type given. buff %pK type %d\n",
                   "ipa3_wan_msg_free_cb",
                   1017,
                   a1,
                   a3);
      }
    }
    else
    {
      return kfree(a1);
    }
  }
  else
  {
    result = printk(&unk_3B18C1, "ipa3_wan_msg_free_cb");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d Null buffer\n", "ipa3_wan_msg_free_cb", 1010);
        v4 = ipa3_ctx;
      }
      result = *(_QWORD *)(v4 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d Null buffer\n", "ipa3_wan_msg_free_cb", 1010);
    }
  }
  return result;
}
