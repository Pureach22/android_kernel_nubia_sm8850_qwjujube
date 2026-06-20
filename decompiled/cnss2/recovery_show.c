__int64 __fastcall recovery_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  unsigned int v5; // w19
  const char *v6; // x3
  __int64 v7; // x19
  const char *v8; // x3

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return -19;
  v5 = scnprintf(
         a3,
         4096,
         "Usage: echo [recovery_bitmap] > /sys/kernel/cnss/recovery\n"
         "BIT0 -- wlan fw recovery\n"
         "BIT1 -- wlan pcss recovery\n"
         "---------------------------------\n");
  if ( *(_BYTE *)(v3 + 544) )
    v6 = "Enabled";
  else
    v6 = "Disabled";
  v7 = (unsigned int)scnprintf(a3 + v5, 4096 - v5, "WLAN recovery %s[%d]\n", v6, *(unsigned __int8 *)(v3 + 544)) + v5;
  if ( *(_BYTE *)(v3 + 545) )
    v8 = "Enabled";
  else
    v8 = "Disabled";
  return (unsigned int)scnprintf(a3 + v7, (unsigned int)(4096 - v7), "WLAN PCSS recovery %s[%d]\n", v8)
       + (unsigned int)v7;
}
