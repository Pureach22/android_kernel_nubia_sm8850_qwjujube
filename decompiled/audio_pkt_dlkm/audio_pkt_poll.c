__int64 __fastcall audio_pkt_poll(__int64 a1, void (**a2)(void))
{
  __int64 v2; // x20
  void (*v3)(void); // x8
  __int64 v4; // x1
  unsigned int v5; // w19

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 16LL);
  if ( v2 )
  {
    if ( a2 )
    {
      v3 = *a2;
      if ( *a2 )
      {
        if ( *((_DWORD *)v3 - 1) != -442429149 )
          __break(0x8228u);
        v3();
        __dmb(0xBu);
      }
    }
    mutex_lock(v2 + 144);
    v4 = raw_spin_lock_irqsave(v2 + 192);
    if ( *(_QWORD *)(v2 + 200) == v2 + 200 )
      v5 = 0;
    else
      v5 = 65;
    raw_spin_unlock_irqrestore(v2 + 192, v4);
    mutex_unlock(v2 + 144);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&audio_pkt_poll__rs, "audio_pkt_poll") )
      printk(&unk_8597, "audio_pkt_poll");
    ipc_log_string(0, "[%s]: invalid device handle\n", "audio_pkt_poll");
    return 8;
  }
  return v5;
}
