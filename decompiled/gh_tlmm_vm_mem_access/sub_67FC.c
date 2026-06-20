__int64 sub_67FC()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return gh_guest_memshare_notify_nb_handler();
}
