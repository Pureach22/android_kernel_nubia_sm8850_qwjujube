__int64 sub_126840()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return kgsl_va_minidump_callback();
}
