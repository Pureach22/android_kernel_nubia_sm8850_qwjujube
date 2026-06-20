__int64 sub_192D00()
{
  _ReadStatusReg(ARM64_SYSREG(3, 7, 5, 7, 1));
  return sde_hw_get_limit_conf();
}
