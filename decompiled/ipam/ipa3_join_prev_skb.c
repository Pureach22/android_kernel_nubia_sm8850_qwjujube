__int64 __fastcall ipa3_join_prev_skb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w22
  __int64 v6; // x0
  __int64 v7; // x20
  void *v8; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  v4 = a3;
  v6 = skb_copy_expand(a1, 0, a3, 3264);
  v7 = v6;
  if ( v6 )
  {
    v8 = (void *)skb_put(v6, v4);
    memcpy(v8, *(const void **)(a2 + 224), v4);
  }
  else
  {
    printk(&unk_3FDD91, "ipa3_join_prev_skb");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d copy expand failed\n", "ipa3_join_prev_skb", 4263);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d copy expand failed\n", "ipa3_join_prev_skb", 4263);
    }
  }
  dev_kfree_skb_any_reason(a1, 2);
  return v7;
}
