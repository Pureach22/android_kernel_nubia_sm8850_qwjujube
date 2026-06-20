__int64 sysmon_smem_init_cdsp()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x0
  unsigned __int64 v2; // x0
  __int64 result; // x0
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  byte_9601 = 1;
  byte_9603 = 1;
  v0 = qcom_smem_get(5, 624, v4);
  qword_9688 = v0;
  if ( !v0 || v0 > 0xFFFFFFFFFFFFF000LL || v4[0] <= 0x33u )
  {
    printk(&unk_9A96, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  v1 = qcom_smem_get(5, 607, v4);
  qword_9648 = v1;
  if ( !v1 || v1 > 0xFFFFFFFFFFFFF000LL || v4[0] <= 0x1Fu )
  {
    printk(&unk_99A0, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  v2 = qcom_smem_get(5, 634, v4);
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL || !v4[0] )
  {
    printk(&unk_A723, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  result = update_sysmon_smem_pointers();
  if ( !qword_9628 || (unsigned __int64)qword_9628 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A581, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  if ( !qword_9610 || (unsigned __int64)qword_9610 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_9F77, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  if ( !qword_9670 || (unsigned __int64)qword_9670 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_9FBB, "sysmon_subsystem_stats");
    byte_9601 = 0;
  }
  if ( !qword_96A8 || (unsigned __int64)qword_96A8 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A377, "sysmon_subsystem_stats");
    byte_9603 = 0;
  }
  if ( !qword_96B0 || (unsigned __int64)qword_96B0 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A377, "sysmon_subsystem_stats");
    byte_9603 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
