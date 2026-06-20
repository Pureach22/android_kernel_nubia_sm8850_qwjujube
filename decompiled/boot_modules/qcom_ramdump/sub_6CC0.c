void sub_6CC0()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = device_create;
  *(_QWORD *)(StatusReg + 80) = &qcom_create_ramdump_device__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 400);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6BE8);
  JUMPOUT(0x6B3C);
}
