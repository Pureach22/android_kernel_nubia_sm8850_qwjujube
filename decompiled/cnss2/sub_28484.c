void sub_28484()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = of_find_compatible_node;
  *(_QWORD *)(StatusReg + 80) = &cnss_wlan_reg_driver_work__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 4);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x2846C);
  JUMPOUT(0x283D4);
}
