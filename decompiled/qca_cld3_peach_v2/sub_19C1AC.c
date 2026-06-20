void __usercall sub_19C1AC(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x1
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_qdf_talloc_fl__alloc_tag;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
  {
    v3 = 2336;
  }
  else
  {
    v3 = 2336;
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
    {
      if ( *(_DWORD *)(StatusReg + 16) )
        v3 = 2336;
      else
        v3 = 3520;
    }
  }
  v4 = _kmalloc_noprof(a1 + 32, v3);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v4 )
    JUMPOUT(0x19C194);
  JUMPOUT(0x19C174);
}
