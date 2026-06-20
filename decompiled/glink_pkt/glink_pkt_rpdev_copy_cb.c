__int64 __fastcall glink_pkt_rpdev_copy_cb(__int64 a1, const void *a2, unsigned int a3)
{
  __int64 v3; // x23
  __int64 v6; // x0
  __int64 v7; // x21
  void *v8; // x0
  __int64 v9; // x20

  v3 = *(_QWORD *)(a1 + 152);
  ipc_log_string(
    glink_pkt_ilctxt,
    "[%s]: Data received on:%s len:%d\n",
    "glink_pkt_rpdev_copy_cb",
    *(const char **)(v3 + 1512),
    a3);
  if ( v3 )
  {
    v6 = _alloc_skb(a3, 2080, 0, 0xFFFFFFFFLL);
    if ( v6 )
    {
      v7 = v6;
      v8 = (void *)skb_put(v6, a3);
      memcpy(v8, a2, a3);
      v9 = raw_spin_lock_irqsave(v3 + 1148);
      skb_queue_tail(v3 + 1152, v7);
      raw_spin_unlock_irqrestore(v3 + 1148, v9);
      _wake_up(v3 + 1200, 1, 1, 0);
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: Data queued on:%s len:%d\n",
        "glink_pkt_rpdev_copy_cb",
        *(const char **)(v3 + 1512),
        a3);
      return 0;
    }
    else
    {
      if ( (unsigned int)__ratelimit(&glink_pkt_rpdev_copy_cb__rs_79, "glink_pkt_rpdev_copy_cb") )
        printk("%s[%s]: Failed to allocate skb\n", byte_9300, "glink_pkt_rpdev_copy_cb");
      ipc_log_string(
        glink_pkt_ilctxt,
        "%s[%s]: Failed to allocate skb\n",
        (const char *)&unk_90F5,
        "glink_pkt_rpdev_copy_cb");
      return 4294967284LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_rpdev_copy_cb__rs, "glink_pkt_rpdev_copy_cb") )
      printk("%s[%s]: channel is in reset\n", byte_9300, "glink_pkt_rpdev_copy_cb");
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: channel is in reset\n",
      (const char *)&unk_90F5,
      "glink_pkt_rpdev_copy_cb");
    return 4294967194LL;
  }
}
