__int64 __fastcall gdsc_genpd_hwctrl_get(__int64 a1, unsigned __int64 *a2)
{
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 16);
  v6 = 0;
  v4 = *(_QWORD *)(v3 + 1640);
  if ( !v4 || (result = regulator_enable(v4), !(_DWORD)result) )
  {
    regmap_read(*(_QWORD *)(v3 + 1544), *(unsigned int *)(v3 + 1552), &v6);
    *a2 = ((unsigned __int64)v6 >> 1) & 1;
    result = *(_QWORD *)(v3 + 1640);
    if ( result )
      result = regulator_disable(result);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
