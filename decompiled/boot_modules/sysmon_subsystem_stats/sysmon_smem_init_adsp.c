__int64 sysmon_smem_init_adsp()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x0
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  __int64 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  g_sysmon_stats = 1;
  v0 = qcom_smem_get(2, 624, v5);
  qword_9680 = v0;
  if ( !v0 || v0 > 0xFFFFFFFFFFFFF000LL || v5[0] <= 0x33u )
  {
    printk(&unk_9768, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  v1 = qcom_smem_get(2, 606, v5);
  qword_9640 = v1;
  if ( !v1 || v1 > 0xFFFFFFFFFFFFF000LL || v5[0] <= 0x1Fu )
  {
    printk(&unk_9B76, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  v2 = qcom_smem_get(2, 613, v5);
  qword_9658 = v2;
  if ( !v2 || v2 > 0xFFFFFFFFFFFFF000LL || v5[0] <= 0x1Fu )
  {
    printk(&unk_9900, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  v3 = qcom_smem_get(2, 634, v5);
  if ( !v3 || v3 > 0xFFFFFFFFFFFFF000LL || !v5[0] )
  {
    printk(&unk_97B5, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  result = update_sysmon_smem_pointers();
  if ( !qword_9620 || (unsigned __int64)qword_9620 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A769, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  if ( !qword_9608 || (unsigned __int64)qword_9608 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_9802, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  if ( !qword_9668 || (unsigned __int64)qword_9668 >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_A1B8, "sysmon_subsystem_stats");
    g_sysmon_stats = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
