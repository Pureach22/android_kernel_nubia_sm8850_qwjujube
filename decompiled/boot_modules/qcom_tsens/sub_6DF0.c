__int64 __fastcall sub_6DF0(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x23

  _WriteStatusReg(ARM64_SYSREG(3, 0, 14, 6, 2), v2);
  return tsens_calibrate_nvmem(a1, a2);
}
