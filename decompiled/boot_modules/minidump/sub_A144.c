void sub_A144()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = per_cpu_ptr_to_phys;
  *(_QWORD *)(StatusReg + 80) = &msm_minidump_add_region__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 64);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA0FC);
  JUMPOUT(0xA084);
}
