__int64 __fastcall sde_irq(__int64 a1)
{
  __int64 v1; // x0
  __int64 v2; // x8
  void (*v3)(void); // x8
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(a1 + 1896);
  v2 = *(unsigned int *)(v1 + 28);
  if ( (unsigned int)v2 >= 3 )
    __break(0x5512u);
  v3 = *(void (**)(void))(v1 + 8 * v2 + 272);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != 1122617396 )
      __break(0x8228u);
    v3();
    g_sde_irq_status = 0;
    result = 1;
  }
  else
  {
    result = 1;
    g_sde_irq_status = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
