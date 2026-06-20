void sub_7878()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = panic;
  *(_QWORD *)(StatusReg + 80) = &init_transfer_rings__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 64);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7658);
}
