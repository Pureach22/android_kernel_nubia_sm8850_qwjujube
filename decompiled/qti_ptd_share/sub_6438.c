__int64 sub_6438()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return qti_pdt_share_updated_data_cb();
}
