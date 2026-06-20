void __usercall sub_BECC(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &rtc6226_i2c_probe__alloc_tag_48;
  _kmalloc_noprof(*(unsigned int *)(a1 + 3120), 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xBAEC);
}
