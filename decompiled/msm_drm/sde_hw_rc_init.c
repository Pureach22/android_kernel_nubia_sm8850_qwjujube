__int64 __fastcall sde_hw_rc_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0

  v2 = _kvmalloc_node_noprof(72, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 1488) = v2;
  if ( !v2 )
    return 4294967284LL;
  v3 = _kvmalloc_node_noprof(21856, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(a1 + 1480) = v3;
  if ( v3 )
    return 0;
  else
    return 4294967284LL;
}
