__int64 __fastcall kgsl_free_pages(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x0
  unsigned int v12; // w8
  unsigned int v13; // w8
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x8

  if ( *(_DWORD *)(a1 + 104) )
  {
    v2 = 0;
    do
    {
      v3 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8LL * (int)v2);
      if ( v3 )
      {
        v4 = *(_QWORD *)(v3 + 8);
        v5 = (v4 & 1) != 0 ? v4 - 1 : *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8LL * (int)v2);
        _X9 = (unsigned int *)(v5 + 52);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v12 = __ldxr(_X9);
          v13 = v12 - 1;
        }
        while ( __stlxr(v13, _X9) );
        __dmb(0xBu);
        if ( !v13 )
          _folio_put();
      }
      ++v2;
    }
    while ( v2 < *(_DWORD *)(a1 + 104) );
  }
  v14 = *(_QWORD *)(a1 + 96);
  *(_DWORD *)(a1 + 104) = 0;
  result = kvfree(v14);
  v16 = *(_QWORD *)(a1 + 112);
  *(_QWORD *)(a1 + 96) = 0;
  if ( v16 )
  {
    if ( *(_QWORD *)(a1 + 192) != a1 + 192 )
    {
      _warn_printk("KGSL shmem page list is not empty\n");
      __break(0x800u);
      v16 = *(_QWORD *)(a1 + 112);
    }
    *(_QWORD *)(**(_QWORD **)(v16 + 24) + 704LL) = 0;
    return fput(*(_QWORD *)(a1 + 112));
  }
  return result;
}
