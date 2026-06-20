__int64 sub_1613DC()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return hif_recovery_notifier_cb();
}
