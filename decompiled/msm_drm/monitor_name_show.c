__int64 __fastcall monitor_name_show(int a1, int a2, char *s)
{
  if ( edid_ctl )
    return snprintf(s, 0x16u, "%s\n", (const char *)edid_ctl);
  else
    return 0;
}
