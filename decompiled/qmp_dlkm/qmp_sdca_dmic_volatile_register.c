__int64 __fastcall qmp_sdca_dmic_volatile_register(__int64 a1, int a2)
{
  __int64 result; // x0

  result = 1;
  if ( a2 <= 1082130831 )
  {
    if ( a2 == 1077936528 || a2 == 1078460672 )
      return result;
    return 0;
  }
  if ( a2 != 1082130832 && a2 != 1082654976 )
    return 0;
  return result;
}
