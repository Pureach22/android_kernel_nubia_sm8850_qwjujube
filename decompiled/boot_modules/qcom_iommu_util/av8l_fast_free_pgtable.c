__int64 __fastcall av8l_fast_free_pgtable(__int64 a1)
{
  int v2; // w8
  __int64 i; // x22
  __int64 v4; // x21
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v12; // x0

  vunmap(*(_QWORD *)(a1 + 240));
  v2 = *(_DWORD *)(a1 + 256);
  if ( v2 >= 1 )
  {
    for ( i = 0; i < v2; ++i )
    {
      v4 = *(_QWORD *)(*(_QWORD *)(a1 + 248) + 8 * i);
      if ( v4 )
      {
        mod_node_page_state(&contig_page_data, 41, -1);
        v5 = *(_QWORD *)(v4 + 8);
        StatusReg = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        if ( (v5 & 1) != 0 )
          v12 = v5 - 1;
        else
          v12 = v4;
        _lruvec_stat_mod_folio(v12, 40, 0xFFFFFFFFLL);
        _WriteStatusReg(DAIF, StatusReg);
        _free_pages(v4, 0);
        v2 = *(_DWORD *)(a1 + 256);
      }
    }
  }
  kvfree(*(_QWORD *)(a1 + 248));
  return kfree(a1);
}
