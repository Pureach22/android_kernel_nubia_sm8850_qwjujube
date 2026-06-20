__int64 __fastcall btfmcodec_enqueue_transport(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x21

  mutex_lock(a1 + 192);
  v4 = _alloc_skb(1, 2080, 0, 0xFFFFFFFFLL);
  if ( v4 )
  {
    v5 = v4;
    *(_BYTE *)skb_put(v4, 1) = a2;
    skb_queue_tail(a1 + 344, v5);
    mutex_unlock(a1 + 192);
    _wake_up(a1 + 624, 1, 1, 0);
    return 0;
  }
  else
  {
    printk(&unk_CD85, "btfmcodec_enqueue_transport");
    mutex_unlock(a1 + 192);
    return 4294967284LL;
  }
}
