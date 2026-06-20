__int64 __fastcall sub_45CA08(int a1, int a2, int a3, int a4, int a5, int a6)
{
  unsigned __int64 v6; // x26

  _WriteStatusReg(ARM64_SYSREG(3, 2, 13, 8, 1), v6);
  return populate_dot11f_he_caps(a1, a2, a3, a4, a5, a6);
}
