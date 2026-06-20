__int64 __fastcall dynamic_page_pool_add(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  _QWORD *v5; // x8
  __int64 v6; // x2
  _QWORD *v7; // x1
  __int64 v8; // x20
  unsigned int v16; // w9

  v4 = raw_spin_lock_irqsave(a1 + 64);
  v5 = (_QWORD *)(a2 + 8);
  v6 = a1 + 32;
  v7 = *(_QWORD **)(a1 + 40);
  v8 = v4;
  if ( a2 + 8 == a1 + 32 || v7 == v5 || *v7 != v6 )
  {
    _list_add_valid_or_report(a2 + 8);
  }
  else
  {
    *(_QWORD *)(a1 + 40) = v5;
    *(_QWORD *)(a2 + 8) = v6;
    *(_QWORD *)(a2 + 16) = v7;
    *v7 = v5;
  }
  ++*(_DWORD *)(a1 + 4);
  _X8 = (unsigned int *)(a1 + 8);
  __asm { PRFM            #0x11, [X8] }
  do
    v16 = __ldxr(_X8);
  while ( __stxr(v16 + 1, _X8) );
  mod_node_page_state(&contig_page_data, 34, 1 << *(_DWORD *)(a1 + 72));
  return raw_spin_unlock_irqrestore(a1 + 64, v8);
}
