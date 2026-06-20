void sub_78A8()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = complete;
  *(_QWORD *)(StatusReg + 80) = &init_event_rings__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7774);
}
