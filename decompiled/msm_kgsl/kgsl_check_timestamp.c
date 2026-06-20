bool __fastcall kgsl_check_timestamp(__int64 a1, __int64 a2, int a3)
{
  void (*v4)(void); // x8
  _BOOL8 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    v4 = *(void (**)(void))(*(_QWORD *)(a1 + 8752) + 64LL);
    if ( *((_DWORD *)v4 - 1) != -362688460 )
      __break(0x8228u);
    v4();
    if ( !a3 )
      goto LABEL_8;
  }
  else if ( !a3 )
  {
LABEL_8:
    result = 1;
    goto LABEL_15;
  }
  result = (a3 ^ 0x80000000) < 0x80000000 && 0x80000000 - (a3 ^ 0x80000000) < 0x80000001;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
