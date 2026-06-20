void __usercall sub_405EC(int a1@<W2>, int a2@<W8>)
{
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x23
  __int64 v6; // x0

  v2 = 1;
  if ( (a1 & 0x10) == 0 )
    v2 = 2;
  if ( (a1 & a2) != 0 )
    v3 = v2;
  else
    v3 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cfg80211_stop_iface__alloc_tag;
  v6 = _kmalloc_cache_noprof(kmalloc_caches[14 * v3 + 10], a1 | 0x100u, 616);
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v6 )
    JUMPOUT(0x40558);
  JUMPOUT(0x404F4);
}
