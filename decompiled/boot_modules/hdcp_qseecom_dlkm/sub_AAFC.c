void sub_AAFC()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hdcp2_app_start_smcinvoke__alloc_tag;
  v3 = _kmalloc_cache_noprof(get_client_env_object, 3264, 534);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 8) = v3;
  if ( !v3 )
    JUMPOUT(0xAA7C);
  JUMPOUT(0xA9C0);
}
