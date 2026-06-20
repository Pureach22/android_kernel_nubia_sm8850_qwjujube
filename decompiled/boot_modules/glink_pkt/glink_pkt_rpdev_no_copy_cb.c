__int64 __fastcall glink_pkt_rpdev_no_copy_cb(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  __int64 v6; // x0
  int v7; // w8
  int v8; // w9
  int v9; // w8
  __int64 v10; // x20
  __int64 v11; // x21
  unsigned int v12; // w20

  v3 = *(_QWORD *)(a1 + 152);
  if ( v3 )
  {
    ipc_log_string(
      glink_pkt_ilctxt,
      "[%s]: Data received on:%s len:%d\n",
      "glink_pkt_rpdev_no_copy_cb",
      *(const char **)(v3 + 1512),
      a3);
    v6 = _alloc_skb(0, 2080, 0, 0xFFFFFFFFLL);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v6 + 216);
      v8 = *(_DWORD *)(v6 + 112);
      *(_QWORD *)(v6 + 224) = a2;
      v9 = a2 - v7;
      v10 = v6;
      *(_DWORD *)(v6 + 208) = v9;
      *(_DWORD *)(v6 + 112) = v8 + a3;
      v11 = raw_spin_lock_irqsave(v3 + 1148);
      skb_queue_tail(v3 + 1152, v10);
      raw_spin_unlock_irqrestore(v3 + 1148, v11);
      v12 = 1;
      _wake_up(v3 + 1200, 1, 1, 0);
      ipc_log_string(
        glink_pkt_ilctxt,
        "[%s]: Data queued on:%s len:%d\n",
        "glink_pkt_rpdev_no_copy_cb",
        *(const char **)(v3 + 1512),
        a3);
    }
    else
    {
      if ( (unsigned int)__ratelimit(&glink_pkt_rpdev_no_copy_cb__rs_76, "glink_pkt_rpdev_no_copy_cb") )
        printk("%s[%s]: Failed to allocate skb\n", byte_9300, "glink_pkt_rpdev_no_copy_cb");
      ipc_log_string(
        glink_pkt_ilctxt,
        "%s[%s]: Failed to allocate skb\n",
        (const char *)&unk_90F5,
        "glink_pkt_rpdev_no_copy_cb");
      return (unsigned int)-12;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&glink_pkt_rpdev_no_copy_cb__rs, "glink_pkt_rpdev_no_copy_cb") )
      printk("%s[%s]: channel is in reset\n", byte_9300, "glink_pkt_rpdev_no_copy_cb");
    ipc_log_string(
      glink_pkt_ilctxt,
      "%s[%s]: channel is in reset\n",
      (const char *)&unk_90F5,
      "glink_pkt_rpdev_no_copy_cb");
    return (unsigned int)-102;
  }
  return v12;
}
