__int64 __fastcall wlan_hdd_current_time_info_debugfs(__int64 a1, __int64 a2)
{
  int v4; // w0
  _QWORD v6[4]; // [xsp+0h] [xbp-20h] BYREF

  v6[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v6, 0, 24);
  qdf_get_time_of_the_day_in_hr_min_sec_usec((__int64)v6, 24);
  scnprintf(a1, a2, "\nTime at which this file generated = %s\n", (const char *)v6);
  _ReadStatusReg(SP_EL0);
  return v4 & (unsigned int)~(v4 >> 31);
}
