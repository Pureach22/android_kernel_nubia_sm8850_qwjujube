__int64 __fastcall audio_pkt_platform_driver_remove(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x23
  _QWORD *v4; // x19
  __int64 v5; // x20
  __int64 result; // x0
  __int64 v7; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 168) + 16LL);
  gpr_driver_unregister(audio_pkt_driver);
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 168) + 16LL);
  if ( v3 )
  {
    if ( (audio_pkt_debug_mask & 1) != 0 )
      ipc_log_string(
        0,
        "[%s]: %s: for %s\n",
        "audio_pkt_internal_release",
        "audio_pkt_internal_release",
        (const char *)(v3 + 268));
    v4 = (_QWORD *)(v3 + 200);
    v5 = raw_spin_lock_irqsave(v3 + 192);
    while ( (_QWORD *)*v4 != v4 )
    {
      v7 = skb_dequeue(v4);
      if ( v7 )
        sk_skb_reason_drop(0, v7, 2);
    }
    raw_spin_unlock_irqrestore(v3 + 192, v5);
    _wake_up(v3 + 224, 1, 1, 0);
    if ( v2 )
    {
LABEL_6:
      cdev_del(v2 + 8);
      device_destroy(*(_QWORD *)(v2 + 296), *(unsigned int *)(v2 + 288));
      class_destroy(*(_QWORD *)(v2 + 296));
      unregister_chrdev_region(*(_DWORD *)(v2 + 288) >> 20, 1);
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_internal_release__rs, "audio_pkt_internal_release") )
      printk(&unk_8597, "audio_pkt_internal_release");
    ipc_log_string(0, "[%s]: invalid device handle\n", "audio_pkt_internal_release");
    if ( v2 )
      goto LABEL_6;
  }
  cancel_work_sync(&audio_pkt_skb_backup_work);
  result = skb_queue_purge_reason(&audio_pkt_backup_buffers, 85);
  if ( (audio_pkt_debug_mask & 1) != 0 )
    return ipc_log_string(0, "[%s]: Audio Packet Port Driver Removed\n", "audio_pkt_platform_driver_remove");
  return result;
}
