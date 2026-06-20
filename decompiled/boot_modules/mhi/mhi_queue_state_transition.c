__int64 __fastcall mhi_queue_state_transition(__int64 a1, int a2)
{
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x2
  __int64 *v7; // x1
  __int64 v8; // x9

  v4 = _kmalloc_cache_noprof(memcpy, &print_fmt_mhi_gen_tre[64], 24);
  if ( !v4 )
    return 4294967284LL;
  *(_DWORD *)(v4 + 16) = a2;
  v5 = raw_spin_lock_irqsave(a1 + 392);
  v6 = a1 + 376;
  v7 = *(__int64 **)(a1 + 384);
  v8 = v5;
  if ( v4 == a1 + 376 || v7 == (__int64 *)v4 || *v7 != v6 )
  {
    _list_add_valid_or_report(v4, v7);
  }
  else
  {
    *(_QWORD *)(a1 + 384) = v4;
    *(_QWORD *)v4 = v6;
    *(_QWORD *)(v4 + 8) = v7;
    *v7 = v4;
  }
  raw_spin_unlock_irqrestore(a1 + 392, v8);
  queue_work_on(32, *(_QWORD *)(a1 + 448), a1 + 416);
  return 0;
}
