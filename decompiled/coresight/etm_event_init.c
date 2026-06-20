__int64 __fastcall etm_event_init(__int64 a1)
{
  __int64 v2; // x2
  void *v3; // x0
  void *v4; // x20
  __int64 v5; // x8

  if ( *(_DWORD *)(a1 + 216) != dword_11998 )
    return 4294967294LL;
  if ( *(_DWORD *)(a1 + 668) == -1 )
    v2 = 0xFFFFFFFFLL;
  else
    v2 = 0;
  v3 = (void *)_kmalloc_cache_node_noprof(hashlen_string, 3520, v2, 200);
  v4 = v3;
  if ( !v3 )
    return 4294967284LL;
  v5 = *(_QWORD *)(a1 + 656);
  if ( v5 )
    memcpy(v3, *(const void **)(v5 + 464), 0xC8u);
  *(_QWORD *)(a1 + 464) = v4;
  *(_QWORD *)(a1 + 984) = etm_event_destroy;
  return 0;
}
