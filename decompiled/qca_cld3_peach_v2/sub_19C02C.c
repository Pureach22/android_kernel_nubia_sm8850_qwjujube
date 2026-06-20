__int64 sub_19C02C()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return qdf_va_md_notif_handler();
}
