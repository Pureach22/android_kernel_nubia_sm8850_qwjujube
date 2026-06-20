void sub_A9BC()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_spin_lock_bh;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v2, 2336, 40);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xA8F0);
}
