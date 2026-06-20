unsigned __int16 *__fastcall qmap_encapsulate_skb(unsigned __int16 *a1, unsigned __int64 *a2)
{
  unsigned __int16 *v3; // x19
  unsigned __int16 *v4; // x21
  unsigned __int64 *v5; // x0
  unsigned __int64 v6; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  if ( !a2 )
    return nullptr;
  v3 = a1;
  if ( ((*((_DWORD *)a1 + 56) - *((_DWORD *)a1 + 54)) & 0xFFFFFFF8) != 0 )
  {
    v4 = a1;
LABEL_4:
    v5 = (unsigned __int64 *)skb_push(v4, 8);
    v6 = *a2;
    *v5 = *a2;
    *v5 = bswap32(v4[56]) & 0xFFFF0000 | v6 & 0xFFFFFFFF0000FFFFLL;
    return v3;
  }
  v8 = skb_copy_expand(a1, 8, 0, 2080);
  if ( v8 )
  {
    v4 = (unsigned __int16 *)v8;
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d skb expanded. old %pK new %pK\n", "qmap_encapsulate_skb", 14277, v3, v4);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d skb expanded. old %pK new %pK\n", "qmap_encapsulate_skb", 14277, v3, v4);
    }
    dev_kfree_skb_any_reason(v3, 2);
    v3 = v4;
    goto LABEL_4;
  }
  printk(&unk_3FC1A7, "qmap_encapsulate_skb");
  v12 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d no memory for skb expand\n", "qmap_encapsulate_skb", 14274);
      v12 = ipa3_ctx;
    }
    v14 = *(_QWORD *)(v12 + 34160);
    if ( v14 )
      ipc_log_string(v14, "ipa %s:%d no memory for skb expand\n", "qmap_encapsulate_skb", 14274);
  }
  return v3;
}
