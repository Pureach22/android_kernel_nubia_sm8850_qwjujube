__int64 __fastcall recovery_show(__int64 a1, const char **a2, __int64 a3)
{
  const char *v3; // x20
  unsigned int v5; // w8
  _BYTE *v6; // x8
  const char *v7; // x2

  v3 = *a2;
  if ( !strcmp(*a2, "trustedvm_recovery") )
  {
    v5 = 0;
  }
  else
  {
    if ( strcmp(v3, "oemvm_recovery") )
      return -22;
    v5 = 1;
  }
  v6 = (_BYTE *)(recovery_vms + 40LL * v5);
  if ( !v6 )
    return -22;
  if ( *v6 )
    v7 = "enabled";
  else
    v7 = "disabled";
  return (int)sysfs_emit(a3, "%s\n", v7);
}
