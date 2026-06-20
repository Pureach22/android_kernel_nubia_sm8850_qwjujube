__int64 sub_7E8C()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return wcd_mbhc_usbc_ana_event_handler();
}
