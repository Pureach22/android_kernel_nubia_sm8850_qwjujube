void sub_11E2C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cscfg_create_device__alloc_tag;
  _kmalloc_cache_noprof(idr_remove, 3520, 1184);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x11D64);
}
