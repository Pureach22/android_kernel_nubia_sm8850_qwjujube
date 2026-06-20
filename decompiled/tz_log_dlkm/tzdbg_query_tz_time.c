bool tzdbg_query_tz_time()
{
  __int64 v0; // x20
  unsigned int v1; // w19
  __int64 v2; // x9
  unsigned int v4; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v5[2]; // [xsp+10h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v4 = 0;
  v0 = ktime_get_with_offset(1);
  v1 = qcom_scm_query_tz_time(v5, &v4);
  if ( v1 )
  {
    printk(&unk_98EB, "tzdbg_query_tz_time", v1);
  }
  else
  {
    v2 = ktime_get_with_offset(1) - v0;
    g_tz_ticks_baseline = v5[0];
    g_tz_ticks_frequency = v4;
    g_hlos_uptime_baseline = v0 + v2 / 2;
  }
  _ReadStatusReg(SP_EL0);
  return v1 == 0;
}
