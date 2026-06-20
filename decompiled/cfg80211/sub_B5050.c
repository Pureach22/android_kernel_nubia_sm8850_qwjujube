void __usercall sub_B5050(int a1@<W1>, int a2@<W8>)
{
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v5; // x21

  v2 = 1;
  if ( (a1 & 0x10) == 0 )
    v2 = 2;
  if ( (a1 & a2) != 0 )
    v3 = v2;
  else
    v3 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cfg80211_sinfo_alloc_tid_stats__alloc_tag;
  _kmalloc_cache_noprof(kmalloc_caches[14 * v3 + 11], a1 | 0x100u, 1496);
  *(_QWORD *)(StatusReg + 80) = v5;
  JUMPOUT(0xB502C);
}
