void sub_2104F4()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &nubia_dp_preference_init__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 72);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x210308);
}
