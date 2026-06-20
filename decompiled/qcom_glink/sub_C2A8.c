__int64 __fastcall sub_C2A8(int a1, int a2, char *a3)
{
  unsigned __int64 v3; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return qcom_glink_ssr_notifier_call(a1, a2, a3);
}
