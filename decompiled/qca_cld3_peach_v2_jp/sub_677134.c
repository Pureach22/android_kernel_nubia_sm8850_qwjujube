__int64 __fastcall sub_677134(__int64 a1)
{
  unsigned __int16 *v1; // x30

  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  _ReadStatusReg(TPIDR_EL2);
  __ldxr(v1);
  return hdd_sysfs_txrx_fw_stats_create(a1);
}
