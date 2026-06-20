void sub_210554()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _mutex_init;
  *(_QWORD *)(StatusReg + 80) = &nubia_dp_preference_init__alloc_tag_56;
  _kmalloc_cache_noprof(v2, 3520, 8);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x210350);
}
