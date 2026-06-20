void __usercall sub_BAC4(int a1@<W8>)
{
  int v1; // w20
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x22
  __int64 v6; // x0

  v2 = 1;
  if ( (v1 & 0x10) == 0 )
    v2 = 2;
  if ( (v1 & a1) != 0 )
    v3 = v2;
  else
    v3 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gsi_ctrl_pkt_alloc__alloc_tag;
  v6 = _kmalloc_cache_noprof(kmalloc_caches[14 * v3 + 5], v1 | 0x100u, 32);
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v6 )
    JUMPOUT(0xBAA8);
  JUMPOUT(0xBA78);
}
