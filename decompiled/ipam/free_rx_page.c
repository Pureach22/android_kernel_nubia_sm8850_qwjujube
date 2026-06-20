__int64 __fastcall free_rx_page(__int64 a1, __int64 *a2)
{
  __int64 **v4; // x8
  __int64 *v5; // x9
  __int64 *v6; // x1
  __int64 *v7; // x2
  unsigned int v14; // w10

  if ( (a2[4] & 1) != 0 )
  {
    dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), a2[3], *((unsigned int *)a2 + 10), 2, 0);
    _free_pages(a2[2], *((unsigned int *)a2 + 9));
    return kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), a2);
  }
  else
  {
    raw_spin_lock_bh(*(_QWORD *)(a2[10] + 1944) + 1684LL);
    v4 = (__int64 **)a2[1];
    if ( *v4 == a2 && (v5 = (__int64 *)*a2, *(__int64 **)(*a2 + 8) == a2) )
    {
      v5[1] = (__int64)v4;
      *v4 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(a2);
    }
    *a2 = (__int64)a2;
    a2[1] = (__int64)a2;
    _X8 = (unsigned int *)(a2[2] + 52);
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 - 1, _X8) );
    v6 = *(__int64 **)(a2[10] + 1784);
    v7 = (__int64 *)*v6;
    if ( *(__int64 **)(*v6 + 8) != v6 || v6 == a2 || v7 == a2 )
    {
      _list_add_valid_or_report(a2, v6);
    }
    else
    {
      v7[1] = (__int64)a2;
      *a2 = (__int64)v7;
      a2[1] = (__int64)v6;
      *v6 = (__int64)a2;
    }
    return raw_spin_unlock_bh(*(_QWORD *)(a2[10] + 1944) + 1684LL);
  }
}
