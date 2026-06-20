__int64 sub_38DD68()
{
  unsigned __int64 v0; // x27

  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v0);
  return wlan_hdd_pm_qos_notify();
}
