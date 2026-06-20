void sub_205B84()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  double (*v2)(_QWORD, _QWORD, _QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _drm_dev_dbg;
  *(_QWORD *)(StatusReg + 80) = &msm_atomic_state_alloc__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x205B60);
  JUMPOUT(0x205B50);
}
