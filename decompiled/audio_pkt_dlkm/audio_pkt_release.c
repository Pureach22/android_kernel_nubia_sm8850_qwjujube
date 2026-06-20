__int64 __fastcall audio_pkt_release(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  _QWORD *v4; // x20
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v9; // x0

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 16LL);
  if ( v2 )
  {
    if ( (audio_pkt_debug_mask & 1) != 0 )
      ipc_log_string(0, "[%s]: %s: for %s \n", "audio_pkt_release", "audio_pkt_release", (const char *)(v2 + 268));
    v4 = (_QWORD *)(v2 + 200);
    v5 = raw_spin_lock_irqsave(v2 + 192);
    while ( (_QWORD *)*v4 != v4 )
    {
      v9 = skb_dequeue(v4);
      if ( v9 )
        sk_skb_reason_drop(0, v9, 2);
    }
    _wake_up(v2 + 224, 1, 1, 0);
    v6 = raw_spin_unlock_irqrestore(v2 + 192, v5);
    *(_QWORD *)(a2 + 32) = 0;
    v7 = spf_core_apm_close_all(v6);
    msm_audio_ion_crash_handler(v7);
    return 0;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_release__rs, "audio_pkt_release") )
      printk(&unk_8597, "audio_pkt_release");
    ipc_log_string(0, "[%s]: invalid device handle\n", "audio_pkt_release");
    return 4294967274LL;
  }
}
