__int64 __fastcall audio_pkt_srvc_callback(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x23
  unsigned int v5; // w21
  __int64 v6; // x22
  void *v7; // x0
  __int64 v8; // x19

  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 16LL);
  v5 = (unsigned __int16)(*a2 >> 8);
  if ( (audio_pkt_debug_mask & 1) != 0 )
    ipc_log_string(
      0,
      "[%s]: %s: header %d packet %d\n",
      "audio_pkt_srvc_callback",
      "audio_pkt_srvc_callback",
      (*a2 >> 2) & 0x3C,
      (unsigned __int16)(*a2 >> 8));
  v6 = _alloc_skb(v5, 2080, 0, 0xFFFFFFFFLL);
  if ( v6
    || (dev_err(a1, "%s: alloc_skb failed pkt_size %d\n", "audio_pkt_srvc_callback", v5),
        v6 = skb_dequeue(&audio_pkt_backup_buffers),
        queue_work_on(32, system_unbound_wq),
        v6) )
  {
    v7 = (void *)skb_put(v6, v5);
    memcpy(v7, a2, v5);
    v8 = raw_spin_lock_irqsave(v4 + 192);
    skb_queue_tail(v4 + 200, v6);
    raw_spin_unlock_irqrestore(v4 + 192, v8);
    _wake_up(v4 + 224, 1, 1, 0);
    return 0;
  }
  else
  {
    dev_err(a1, "%s: get backup skb buffers failed\n", "audio_pkt_srvc_callback");
    return 4294967284LL;
  }
}
