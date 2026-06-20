__int64 sub_BC6C()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return rpmh_rsc_cpu_pm_callback();
}
