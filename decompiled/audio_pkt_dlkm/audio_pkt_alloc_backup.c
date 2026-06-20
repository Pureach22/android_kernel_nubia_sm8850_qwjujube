void audio_pkt_alloc_backup()
{
  __int64 v0; // x0

  if ( (audio_pkt_debug_mask & 1) != 0 )
    ipc_log_string(
      0,
      "[%s]: %s: size of backup buffers queue %d\n",
      "audio_pkt_alloc_backup",
      "audio_pkt_alloc_backup",
      qword_7DB8);
  if ( (unsigned int)qword_7DB8 <= 9 )
  {
    while ( 1 )
    {
      v0 = _alloc_skb(4096, 2080, 0, 0xFFFFFFFFLL);
      if ( !v0 )
        break;
      skb_queue_tail(&audio_pkt_backup_buffers, v0);
      if ( (unsigned int)qword_7DB8 >= 0xA )
        return;
    }
    if ( (unsigned int)__ratelimit(&audio_pkt_alloc_backup__rs, "audio_pkt_alloc_backup") )
      printk(&unk_7F73, "audio_pkt_alloc_backup");
    ipc_log_string(
      0,
      "[%s]: %s: failed, size of bkp buffers queue %d\n",
      "audio_pkt_alloc_backup",
      "audio_pkt_alloc_backup",
      qword_7DB8);
  }
}
