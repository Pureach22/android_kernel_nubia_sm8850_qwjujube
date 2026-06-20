void sub_76C38()
{
  int v0; // w20
  int v1; // w22
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v4; // x23
  __int64 v5; // x0

  v2 = 1;
  if ( (v0 & 0x10) == 0 )
    v2 = 2;
  if ( (v0 & v1) == 0 )
    v2 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &regulatory_hint_found_beacon__alloc_tag;
  v5 = _kmalloc_cache_noprof(kmalloc_caches[14 * v2 + 1], v0 | 0x100u, 80);
  *(_QWORD *)(StatusReg + 80) = v4;
  if ( !v5 )
    JUMPOUT(0x76C0C);
  JUMPOUT(0x76B94);
}
