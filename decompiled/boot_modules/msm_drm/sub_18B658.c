void __usercall sub_18B658(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x26
  __int64 v2; // x27
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sspp_offset__alloc_tag;
  v3 = kmemdup_noprof(a1, 72, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x18AE50);
  JUMPOUT(0x18ADEC);
}
