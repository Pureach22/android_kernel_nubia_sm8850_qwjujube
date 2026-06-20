__int64 __fastcall qcom_wdt_cpu_pm_notify(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x27
  __int64 v3; // x8
  int v4; // w9

  v3 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned __int64)(a2 - 1) >= 2 )
  {
    if ( a2 )
      return 1;
    if ( (unsigned int)v3 < 0x20 )
    {
      v4 = 1;
      goto LABEL_7;
    }
  }
  else if ( (unsigned int)v3 <= 0x1F )
  {
    v4 = 0;
LABEL_7:
    *(_DWORD *)(a1 + 4 * v3 + 664) = v4;
    return 1;
  }
  __break(0x5512u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
  return qcom_wdt_hibernation_notifier();
}
