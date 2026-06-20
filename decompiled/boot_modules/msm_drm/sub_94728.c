__int64 __fastcall sub_94728(int a1, int a2)
{
  unsigned __int64 v2; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v2);
  return dp_display_usb_notifier(a1, a2);
}
