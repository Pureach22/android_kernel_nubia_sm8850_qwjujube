__int64 __fastcall mhi_read_reg_field(__int64 a1, __int64 a2, __int64 a3, __int64 a4, _DWORD *a5)
{
  __int64 (*v6)(void); // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v6 = *(__int64 (**)(void))(a1 + 568);
  if ( *((_DWORD *)v6 - 1) != -748163823 )
    __break(0x8228u);
  result = v6();
  if ( !(_DWORD)result )
    *a5 = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}
