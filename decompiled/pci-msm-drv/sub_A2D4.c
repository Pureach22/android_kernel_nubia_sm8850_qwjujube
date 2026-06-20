void sub_A2D4()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = dev_info;
  *(_QWORD *)(StatusReg + 80) = &msm_msi_domain_prepare__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 48);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA2A8);
  JUMPOUT(0xA208);
}
