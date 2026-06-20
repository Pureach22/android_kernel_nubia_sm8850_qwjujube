void sub_117BA0()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = mutex_unlock;
  *(_QWORD *)(StatusReg + 80) = &kgsl_device_snapshot_atomic__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 256);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( v3 )
    JUMPOUT(0x117908);
  JUMPOUT(0x117A24);
}
