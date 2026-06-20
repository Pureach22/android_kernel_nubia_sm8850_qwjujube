__int64 sub_11504()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return dwc3_msm_host_notifier();
}
