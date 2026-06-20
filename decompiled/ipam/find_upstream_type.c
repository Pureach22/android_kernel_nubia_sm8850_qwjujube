__int64 __fastcall find_upstream_type(char *s2)
{
  const char *v2; // x20
  int v3; // w8
  __int64 result; // x0

  v2 = (const char *)rmnet_ipa3_ctx;
  if ( !strcmp((const char *)(rmnet_ipa3_ctx + 560), s2)
    || !strcmp(v2 + 592, s2)
    || !strcmp(v2 + 624, s2)
    || !strcmp(v2 + 656, s2)
    || !strcmp(v2 + 688, s2)
    || !strcmp(v2 + 720, s2)
    || !strcmp(v2 + 752, s2)
    || !strcmp(v2 + 784, s2)
    || !strcmp(v2 + 816, s2)
    || !strcmp(v2 + 848, s2)
    || !strcmp(v2 + 880, s2)
    || !strcmp(v2 + 912, s2)
    || !strcmp(v2 + 944, s2)
    || !strcmp(v2 + 976, s2)
    || !strcmp(v2 + 1008, s2) )
  {
    return 1;
  }
  v3 = strcmp("wlan0", s2);
  result = 2;
  if ( v3 )
  {
    if ( !strcmp("wlan1", s2) )
      return 2;
    else
      return 15;
  }
  return result;
}
