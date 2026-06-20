__int64 __fastcall synx_fence_enable_signaling(__int64 a1)
{
  _QWORD *v2; // x0
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x8
  _QWORD *v7; // x20

  v2 = (_QWORD *)_kmalloc_cache_noprof(raw_spin_lock_bh, 2336, 40);
  if ( v2 && (unsigned __int64)v2 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 8) != 0 )
    {
      v7 = v2;
      printk(&unk_2520A, &unk_2A972, "synx_fence_enable_signaling", 132, a1, v4);
      v2 = v7;
    }
    *v2 = a1;
    v2[1] = 0xFFFFFFFE00000LL;
    v2[2] = v2 + 2;
    v2[3] = v2 + 2;
    v5 = synx_dev;
    v2[4] = synx_fence_enable_handler;
    queue_work_on(32, *(_QWORD *)(v5 + 160), v2 + 1);
  }
  else if ( (synx_debug & 1) != 0 )
  {
    printk(&unk_26B98, &unk_29207, "synx_fence_enable_signaling", 129, v3, v4);
  }
  return 1;
}
