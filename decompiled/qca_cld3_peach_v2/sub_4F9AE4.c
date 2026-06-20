__int64 sub_4F9AE4()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return osif_dp_lpass_ssr_cb();
}
