__int64 __fastcall recovery_store(__int64 a1, const char **a2, __int64 a3, __int64 a4)
{
  const char *v4; // x21
  unsigned int v7; // w8
  char *v8; // x21
  char v9; // w8

  v4 = *a2;
  if ( !strcmp(*a2, "trustedvm_recovery") )
  {
    v7 = 0;
  }
  else
  {
    if ( strcmp(v4, "oemvm_recovery") )
      return -22;
    v7 = 1;
  }
  v8 = (char *)(recovery_vms + 40LL * v7);
  if ( !v8 )
    return -22;
  if ( (sysfs_streq(a3, "enabled") & 1) == 0 )
  {
    if ( (sysfs_streq(a3, "disabled") & 1) != 0 )
    {
      v9 = 0;
      goto LABEL_10;
    }
    return -22;
  }
  v9 = 1;
LABEL_10:
  *v8 = v9;
  return a4;
}
