__int64 sub_29010()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return qmi_rmnet_pm_notify_cb();
}
