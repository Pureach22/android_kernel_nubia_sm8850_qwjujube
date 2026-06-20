__int64 __fastcall mhi_get_exec_env(__int64 a1)
{
  __int64 (*v1)(void); // x9
  int v2; // w0

  _ReadStatusReg(SP_EL0);
  v1 = *(__int64 (**)(void))(a1 + 568);
  if ( *((_DWORD *)v1 - 1) != -748163823 )
    __break(0x8229u);
  v2 = v1();
  _ReadStatusReg(SP_EL0);
  if ( v2 )
    return 10;
  else
    return 0;
}
