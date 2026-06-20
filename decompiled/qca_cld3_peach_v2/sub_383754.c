__int64 sub_383754()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return wlan_hdd_get_port_status_notify();
}
