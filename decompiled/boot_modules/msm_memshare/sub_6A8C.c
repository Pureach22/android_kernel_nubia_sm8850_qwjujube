void sub_6A8C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = mutex_unlock;
  *(_QWORD *)(StatusReg + 80) = &memshare_init_worker__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 304);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x69E8);
}
