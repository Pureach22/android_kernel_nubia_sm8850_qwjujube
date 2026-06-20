__int64 __fastcall sub_1238C(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v3; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return dwc3_msm_vbus_notifier(a1, a2, a3);
}
