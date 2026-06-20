__int64 sysmon_smem_init_slpi()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x0
  unsigned __int64 v2; // x0
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  byte_9602 = 1;
  v0 = qcom_smem_get(3, 608, v4);
  qword_9650 = v0;
  if ( !v0 || v0 > 0xFFFFFFFFFFFFF000LL || v4[0] <= 0x1Fu )
  {
    printk(&unk_9EE4, "sysmon_subsystem_stats");
    byte_9602 = 0;
  }
  v1 = qcom_smem_get(3, 613, v4);
  qword_9660 = v1;
  if ( !v1 || v1 > 0xFFFFFFFFFFFFF000LL || v4[0] <= 0x1Fu )
  {
    printk(&unk_99EC, "sysmon_subsystem_stats");
    byte_9602 = 0;
  }
  v2 = qcom_smem_get(3, 634, v4);
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL || !v4[0] )
    printk(&unk_9BC2, "sysmon_subsystem_stats");
  result = update_sysmon_smem_pointers();
  if ( !qword_9630 || (unsigned __int64)qword_9630 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A272, "sysmon_subsystem_stats");
    byte_9602 = 0;
  }
  if ( !qword_9618 || (unsigned __int64)qword_9618 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A034, "sysmon_subsystem_stats");
    byte_9602 = 0;
  }
  if ( !qword_9678 || (unsigned __int64)qword_9678 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A109, "sysmon_subsystem_stats");
    byte_9602 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
