void sub_95FFC()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dp_connector_get_modes__alloc_tag;
  v2 = _kmalloc_cache_noprof(_wake_up, 3520, 800);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x95F60);
  JUMPOUT(0x95ECC);
}
