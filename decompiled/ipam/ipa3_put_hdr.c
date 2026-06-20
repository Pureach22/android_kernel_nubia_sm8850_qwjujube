__int64 __fastcall ipa3_put_hdr(unsigned int a1)
{
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  mutex_lock(ipa3_ctx + 29472);
  v2 = ipa3_id_find(a1);
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_put_hdr__rs, "ipa3_put_hdr") )
    {
      printk(&unk_3DE445, "ipa3_put_hdr");
      v4 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_16;
    }
    else
    {
      v4 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_16;
    }
    v5 = *(_QWORD *)(v4 + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d lookup failed\n", "ipa3_put_hdr", 1693);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d lookup failed\n", "ipa3_put_hdr", 1693);
    goto LABEL_16;
  }
  if ( *(_DWORD *)(v2 + 16) != 1468208647 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_put_hdr__rs_71, "ipa3_put_hdr") )
    {
      printk(&unk_3B2439, "ipa3_put_hdr");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_12;
    }
    else
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_12:
        v8 = *(_QWORD *)(v7 + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d invalid header entry\n", "ipa3_put_hdr", 1699);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d invalid header entry\n", "ipa3_put_hdr", 1699);
      }
    }
LABEL_16:
    v3 = -22;
    goto LABEL_17;
  }
  v3 = 0;
LABEL_17:
  mutex_unlock(ipa3_ctx + 29472);
  return v3;
}
