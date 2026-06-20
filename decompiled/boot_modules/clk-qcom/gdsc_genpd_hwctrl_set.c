__int64 __fastcall gdsc_genpd_hwctrl_set(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  _BOOL4 v3; // w20
  __int64 v4; // x0
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 16);
  v3 = a2 != 0;
  v4 = *(_QWORD *)(v2 + 1640);
  if ( !v4 || (result = regulator_enable(v4), !(_DWORD)result) )
  {
    regmap_update_bits_base(*(_QWORD *)(v2 + 1544), *(unsigned int *)(v2 + 1552), 2, (unsigned int)(2 * v3), 0, 0, 0);
    result = *(_QWORD *)(v2 + 1640);
    if ( result )
      return regulator_disable(result);
  }
  return result;
}
