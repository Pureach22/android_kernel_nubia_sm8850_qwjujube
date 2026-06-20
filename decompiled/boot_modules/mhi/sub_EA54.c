void sub_EA54()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &mhi_alloc_controller__alloc_tag;
  _kmalloc_cache_noprof(release_firmware, 3520, 632);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xEA44);
}
