__int64 __fastcall sub_60C4(int a1, int a2, char *a3)
{
  unsigned __int64 v3; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return qcom_reboot_reason_reboot(a1, a2, a3);
}
