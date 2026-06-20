__int64 __fastcall is_redmagic_monitor_show(__int64 a1, __int64 a2, char *a3)
{
  const char *v3; // x20
  _BOOL4 v5; // w3

  v3 = (const char *)edid_ctl;
  if ( !edid_ctl )
    return 0;
  v5 = !strcmp("GM001J", (const char *)edid_ctl)
    || !strcmp("GM001S", v3)
    || !strcmp("GM003J", v3)
    || strcmp("GM002J", v3) == 0;
  return snprintf(a3, 3u, "%d\n", v5);
}
