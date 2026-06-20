void sub_26DFC()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ipa_register_notifier;
  *(_QWORD *)(StatusReg + 80) = &_qmi_rmnet_bearer_get__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 200);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x26DD0);
  JUMPOUT(0x26D3C);
}
