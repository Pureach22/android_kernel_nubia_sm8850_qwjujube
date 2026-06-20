unsigned __int64 __fastcall synx_timer_cb(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x4
  __int64 v4; // x5
  int v5; // w10
  __int64 v6; // x8

  result = _kmalloc_cache_noprof(raw_spin_lock_bh, 2336, 56);
  if ( result && result < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *(_DWORD *)(a1 - 12);
    *(_QWORD *)result = *(_QWORD *)(a1 - 24);
    *(_QWORD *)(result + 8) = a1 - 24;
    *(_QWORD *)(result + 24) = 0xFFFFFFFE00000LL;
    *(_DWORD *)(result + 16) = v5;
    *(_QWORD *)(result + 32) = result + 32;
    *(_QWORD *)(result + 40) = result + 32;
    v6 = synx_dev;
    *(_QWORD *)(result + 48) = synx_timer_handler;
    return queue_work_on(32, *(_QWORD *)(v6 + 160), result + 24);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return printk(&unk_26B98, &unk_29207, "synx_timer_cb", 1057, v3, v4);
  }
  return result;
}
