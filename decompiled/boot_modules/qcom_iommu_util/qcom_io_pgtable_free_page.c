__int64 __fastcall qcom_io_pgtable_free_page(__int64 a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x20
  __int64 v4; // x0
  _QWORD *v5; // x2
  _QWORD *v6; // x23
  __int64 v7; // x22
  unsigned __int64 v15; // x9

  v2 = (_QWORD *)(a1 + 8);
  v3 = xa_load(&page_pool_xa, *(unsigned int *)(a1 + 40));
  clear_page(((a1 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL);
  v4 = raw_spin_lock_irqsave(v3 + 8);
  v6 = (_QWORD *)(v3 + 16);
  v5 = *(_QWORD **)(v3 + 16);
  v7 = v4;
  if ( v5[1] != v3 + 16 || v2 == v6 || v5 == v2 )
  {
    _list_add_valid_or_report(v2, v6);
  }
  else
  {
    v5[1] = v2;
    *(_QWORD *)(a1 + 8) = v5;
    *(_QWORD *)(a1 + 16) = v6;
    *v6 = v2;
  }
  _X8 = &page_pool_count;
  __asm { PRFM            #0x11, [X8] }
  do
    v15 = __ldxr((unsigned __int64 *)&page_pool_count);
  while ( __stxr(v15 + 1, (unsigned __int64 *)&page_pool_count) );
  inc_node_page_state(a1, 34);
  return raw_spin_unlock_irqrestore(v3 + 8, v7);
}
