__int64 __fastcall hdd_alloc_chan_cache(__int64 a1, int a2)
{
  _DWORD *v4; // x0
  __int64 v5; // x8

  v4 = (_DWORD *)_qdf_mem_malloc(0x10u, "hdd_alloc_chan_cache", 6756);
  *(_QWORD *)(a1 + 3616) = v4;
  if ( v4 )
  {
    *v4 = a2;
    *(_QWORD *)(*(_QWORD *)(a1 + 3616) + 8LL) = _qdf_mem_malloc(12LL * a2, "hdd_alloc_chan_cache", 6763);
    v5 = *(_QWORD *)(a1 + 3616);
    if ( *(_QWORD *)(v5 + 8) )
      return 0;
    *(_DWORD *)v5 = 0;
    _qdf_mem_free(*(_QWORD *)(a1 + 3616));
    *(_QWORD *)(a1 + 3616) = 0;
  }
  return 4294967284LL;
}
