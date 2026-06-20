void __usercall sub_70D0(unsigned int a1@<W8>)
{
  __int64 v1; // x25
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_hwmon_device_register__alloc_tag_181;
  if ( (a1 & 0x80000000) != 0 )
    v4 = 0;
  else
    v4 = _kmalloc_noprof(8LL * a1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v1 + 992) = v4;
  if ( !v4 )
    JUMPOUT(0x6FEC);
  JUMPOUT(0x6994);
}
