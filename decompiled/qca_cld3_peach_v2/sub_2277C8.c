__int64 sub_2277C8()
{
  __int64 v0; // x0

  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  v0 = MEMORY[0xFFFFFFFFFC576874]();
  return wlan_roam_debug_log(v0);
}
