bool __fastcall access_ok(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 StatusReg; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (*(_QWORD *)StatusReg & 0x4000000) != 0 )
    a1 &= (__int64)(a1 << 8) >> 8;
  return 0x8000000000LL - a2 >= a1;
}
