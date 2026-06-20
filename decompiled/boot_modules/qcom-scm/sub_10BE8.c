__int64 __fastcall sub_10BE8(int a1, int a2, char *a3)
{
  unsigned __int64 v3; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return qcom_scm_do_restart(a1, a2, a3);
}
