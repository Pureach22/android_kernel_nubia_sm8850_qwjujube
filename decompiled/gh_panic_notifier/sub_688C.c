__int64 sub_688C()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return gh_panic_notifier_rm_cb();
}
