__int64 __fastcall a6xx_gmu_disable_gdsc(__int64 a1)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a1 + 9024) && (*(_BYTE *)(a1 + 20657) & 2) != 0 )
  {
    __break(0x800u);
    if ( !*(_QWORD *)(a1 + 9000) )
      goto LABEL_6;
  }
  else if ( !*(_QWORD *)(a1 + 9000) )
  {
    goto LABEL_6;
  }
  if ( (*(_BYTE *)(a1 + 20657) & 2) != 0 )
    regulator_set_mode();
LABEL_6:
  kgsl_pwrctrl_disable_cx_gdsc(a1);
  result = *(_QWORD *)(a1 + 9000);
  if ( result )
  {
    if ( (*(_BYTE *)(a1 + 20657) & 2) != 0 )
      return regulator_set_mode();
  }
  return result;
}
