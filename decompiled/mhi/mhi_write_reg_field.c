__int64 __fastcall mhi_write_reg_field(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x20
  __int64 (*v5)(void); // x8
  __int64 result; // x0
  void (__fastcall *v7)(__int64, __int64); // x8

  v3 = a2 + a3;
  _ReadStatusReg(SP_EL0);
  v5 = *(__int64 (**)(void))(a1 + 568);
  if ( *((_DWORD *)v5 - 1) != -748163823 )
    __break(0x8228u);
  result = v5();
  if ( !(_DWORD)result )
  {
    v7 = *(void (__fastcall **)(__int64, __int64))(a1 + 576);
    if ( *((_DWORD *)v7 - 1) != -242010890 )
      __break(0x8228u);
    v7(a1, v3);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
