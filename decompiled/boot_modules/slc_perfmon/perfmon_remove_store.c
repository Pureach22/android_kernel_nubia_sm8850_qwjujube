__int64 __fastcall perfmon_remove_store(__int64 a1, __int64 a2, char *a3, __int64 a4)
{
  _BYTE *v6; // x19
  char *v7; // x0
  char *v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_BYTE **)(a1 + 152);
  v9[0] = a3;
  mutex_lock(v6 + 136);
  if ( (v6[131] & 1) != 0 )
  {
    dev_err(a1, "PERF_RM_ERR: PERFMON is running, can't remove the configuration.\n");
  }
  else
  {
    v7 = strsep(v9, " ");
    if ( v7 && (sysfs_streq(v7, "REMOVE") & 1) != 0 )
    {
      if ( (v6[128] & 1) != 0 || v6[133] )
      {
        if ( !(unsigned int)perf_remove(a1, v6) )
        {
          dev_info(a1, "PERFMON is removed.\n");
          v6[131] = 0;
          goto LABEL_10;
        }
        dev_err(a1, "PERF_RM_ERR: PERFMON Config remove failed.\n");
      }
      else
      {
        dev_err(a1, "PERF_RM_ERR: PERFMON is not configured.\n");
      }
    }
    else
    {
      dev_err(a1, "PERF_RM_ERR: Invalid configuration, try again.\n");
    }
  }
  a4 = -22;
LABEL_10:
  mutex_unlock(v6 + 136);
  _ReadStatusReg(SP_EL0);
  return a4;
}
