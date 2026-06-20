void sub_A33C()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = msleep;
  *(_QWORD *)(StatusReg + 80) = &hdcp1_key_set__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 8);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA2E0);
  JUMPOUT(0xA220);
}
