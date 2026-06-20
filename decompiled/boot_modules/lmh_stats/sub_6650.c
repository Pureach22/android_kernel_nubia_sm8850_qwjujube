__int64 sub_6650()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return lmh_scmi_limit_notify_cb();
}
