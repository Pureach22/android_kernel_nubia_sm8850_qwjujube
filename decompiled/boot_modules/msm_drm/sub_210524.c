void sub_210524()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &nubia_dp_preference_init__alloc_tag_52;
  _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x21032C);
}
