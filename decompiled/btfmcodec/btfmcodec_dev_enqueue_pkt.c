__int64 __fastcall btfmcodec_dev_enqueue_pkt(__int64 a1, const void *a2, unsigned int a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x23
  void *v9; // x0

  if ( (unsigned __int8)log_lvl >= 4u )
    printk(&unk_C70A, "btfmcodec_dev_enqueue_pkt");
  v6 = raw_spin_lock_irqsave(a1 + 520);
  if ( *(_DWORD *)(a1 + 136) == 1 )
  {
    printk(&unk_C453, "btfmcodec_dev_enqueue_pkt");
    raw_spin_unlock_irqrestore(a1 + 520, v6);
    return 4294967274LL;
  }
  else
  {
    v7 = _alloc_skb(a3, 2080, 0, 0xFFFFFFFFLL);
    if ( v7 )
    {
      v8 = v7;
      v9 = (void *)skb_put(v7, a3);
      memcpy(v9, a2, a3);
      skb_queue_tail(a1 + 528, v8);
      _wake_up(a1 + 496, 1, 1, 0);
      raw_spin_unlock_irqrestore(a1 + 520, v6);
      if ( (unsigned __int8)log_lvl >= 4u )
        printk(&unk_D168, "btfmcodec_dev_enqueue_pkt");
      return 0;
    }
    else
    {
      printk(&unk_CD85, "btfmcodec_dev_enqueue_pkt");
      raw_spin_unlock_irqrestore(a1 + 520, v6);
      return 4294967284LL;
    }
  }
}
