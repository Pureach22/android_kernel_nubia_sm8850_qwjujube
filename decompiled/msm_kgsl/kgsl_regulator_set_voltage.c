__int64 __fastcall kgsl_regulator_set_voltage(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  unsigned int v6; // w21

  result = 0;
  if ( a2 && a2 <= 0xFFFFFFFFFFFFF000LL )
  {
    result = regulator_set_voltage(a2, a3, 0x7FFFFFFF);
    if ( (_DWORD)result )
    {
      v6 = result;
      dev_err(a1, "Regulator set voltage:%d failed:%d\n", a3, result);
      return v6;
    }
  }
  return result;
}
