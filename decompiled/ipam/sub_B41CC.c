__int64 sub_B41CC()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return ipa3_rmnet_mem_notifier();
}
