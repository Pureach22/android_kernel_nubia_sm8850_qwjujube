__int64 __fastcall fastrpc_queue_pd_status(__int64 a1, int a2, int a3, int a4)
{
  __int64 v8; // x23
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 *v11; // x1
  __int64 v12; // x20
  unsigned int v20; // w9

  v8 = _kmalloc_cache_noprof(ida_alloc_range, 2336, 32);
  if ( !v8 )
    return dev_err(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL), "Allocation failed for notif\n");
  *(_DWORD *)(v8 + 20) = a4;
  *(_DWORD *)(v8 + 24) = a3;
  *(_DWORD *)(v8 + 16) = a2;
  v9 = raw_spin_lock_irqsave(a1 + 576);
  v10 = a1 + 584;
  v11 = *(__int64 **)(a1 + 592);
  v12 = v9;
  if ( v8 == a1 + 584 || (__int64 *)v8 == v11 || *v11 != v10 )
  {
    _list_add_valid_or_report(v8, v11, v10);
  }
  else
  {
    *(_QWORD *)(a1 + 592) = v8;
    *(_QWORD *)v8 = v10;
    *(_QWORD *)(v8 + 8) = v11;
    *v11 = v8;
  }
  _X8 = (unsigned int *)(a1 + 544);
  __asm { PRFM            #0x11, [X8] }
  do
    v20 = __ldxr(_X8);
  while ( __stxr(v20 + 1, _X8) );
  _wake_up(a1 + 552, 1, 1, 0);
  return raw_spin_unlock_irqrestore(a1 + 576, v12);
}
