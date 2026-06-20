__int64 __fastcall regulatory_hint(__int64 a1, _WORD *a2)
{
  __int64 v4; // x21
  int v5; // w0

  if ( a1 && a2 )
  {
    *(_DWORD *)(a1 + 104) &= ~1u;
    v4 = _kmalloc_cache_noprof(timer_delete, 3520, 64);
    if ( v4 )
    {
      v5 = ((__int64 (__fastcall *)(__int64))get_wiphy_idx)(a1);
      *(_WORD *)(v4 + 28) = *a2;
      *(_DWORD *)(v4 + 16) = v5;
      *(_DWORD *)(v4 + 20) = 2;
      queue_regulatory_request(v4);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
