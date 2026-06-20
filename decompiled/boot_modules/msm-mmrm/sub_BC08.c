void sub_BC08()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = mutex_unlock;
  *(_QWORD *)(StatusReg + 80) = &msm_mmrm_probe_init__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 120);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xB8B4);
}
