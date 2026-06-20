void sub_11EF8()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = class_for_each_device;
  *(_QWORD *)(StatusReg + 80) = &dup_gh_sgl_desc_to_sgt__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x11E60);
  JUMPOUT(0x11E44);
}
