__int64 __fastcall hdd_sysfs_wakeup_logs_to_console_store(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        unsigned __int64 a12)
{
  __int64 v12; // x19
  int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w20
  __int64 v23; // x21
  char *v24; // x0
  char *v26; // [xsp+0h] [xbp-40h] BYREF
  int v27; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v28[4]; // [xsp+10h] [xbp-30h] BYREF
  char v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v12 = a12;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  memset(v28, 0, sizeof(v28));
  v27 = 0;
  v13 = hdd_sysfs_validate_and_copy_buf((__int64)v28, 33, a11, a12, a1, a2, a3, a4, a5, a6, a7, a8);
  if ( v13 )
  {
    v22 = v13;
    v23 = jiffies;
    if ( hdd_sysfs_wakeup_logs_to_console_store___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid input",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "hdd_sysfs_wakeup_logs_to_console_store");
      hdd_sysfs_wakeup_logs_to_console_store___last_ticks = v23;
    }
    v12 = v22;
  }
  else
  {
    v26 = (char *)v28;
    v24 = strsep(&v26, " ");
    if ( v24 && !(unsigned int)kstrtouint(v24, 0, &v27) )
      wma_set_wakeup_logs_to_console(v27 != 0);
    else
      v12 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
