__int64 sub_695A38()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return dp_fim_policy_update_notifier();
}
