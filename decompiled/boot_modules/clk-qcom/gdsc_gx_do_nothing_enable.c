__int64 __fastcall gdsc_gx_do_nothing_enable(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 1640);
  if ( result )
    return regulator_enable(result);
  return result;
}
