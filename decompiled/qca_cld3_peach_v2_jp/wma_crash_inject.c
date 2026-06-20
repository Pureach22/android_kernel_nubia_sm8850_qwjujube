__int64 __fastcall wma_crash_inject(__int64 *a1)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  result = wmi_crash_inject(*a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
