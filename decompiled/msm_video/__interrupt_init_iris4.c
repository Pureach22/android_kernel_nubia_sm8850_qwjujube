__int64 __fastcall _interrupt_init_iris4(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = _read_register(a1, 0xB0010u, &v3);
  if ( !(_DWORD)result )
  {
    v3 &= 0xFFFFFFF3;
    result = _write_register(a1, 0xB0010u, v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
