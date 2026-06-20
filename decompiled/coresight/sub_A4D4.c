void sub_A4D4()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = put_device;
  *(_QWORD *)(StatusReg + 80) = &coresight_build_path__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA370);
  JUMPOUT(0xA400);
}
