__int64 __fastcall cpu_mpam_enable_monitor_show(__int64 a1, __int64 a2)
{
  const char *v2; // x3

  if ( *(_DWORD *)(a1 + 140) == 0x7FFFFFFF )
    v2 = "disabled";
  else
    v2 = "enabled";
  return (int)scnprintf(a2, 4096, "%s\n", v2);
}
