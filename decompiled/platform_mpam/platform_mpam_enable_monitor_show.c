__int64 __fastcall platform_mpam_enable_monitor_show(__int64 a1, __int64 a2)
{
  const char *v2; // x3

  if ( *(_BYTE *)(a1 + 148) )
    v2 = "enabled";
  else
    v2 = "disabled";
  return (int)scnprintf(a2, 4096, "%s\n", v2);
}
