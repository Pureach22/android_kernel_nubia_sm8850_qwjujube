__int64 sub_541EE0()
{
  unsigned __int16 *v0; // x30

  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  __ldxr(v0);
  return hdd_sysfs_dp_traffic_end_indication_create();
}
