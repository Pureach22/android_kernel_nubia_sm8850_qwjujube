__int64 __fastcall kgsl_pwrctrl_get_acv_perfmode_lvl(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 result; // x0

  v2 = *(unsigned int *)(a1 + 10400);
  if ( !a2 || (int)v2 < 1 )
    return (unsigned int)(v2 - 1);
  v3 = *(_QWORD *)(a1 + 10392);
  result = 0;
  while ( *(_DWORD *)(v3 + 4 * result) < a2 )
  {
    if ( v2 == ++result )
      return (unsigned int)(v2 - 1);
  }
  return result;
}
