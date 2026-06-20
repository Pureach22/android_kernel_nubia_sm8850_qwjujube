__int64 sub_6E80()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return pmic_glink_ssr_notifier_cb();
}
