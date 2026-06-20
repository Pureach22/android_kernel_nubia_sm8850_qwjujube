void sub_8870()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &aw22xxx_alloc_name_array__alloc_tag;
  _kmalloc_cache_noprof(v2, 3264, 88);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x866C);
}
