__int64 sub_1575F8()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return ipa3_rmt_mdm_ssr_notifier_cb();
}
