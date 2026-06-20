__int64 __fastcall user_config_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v5; // w19
  const char *v6; // x3
  __int64 v7; // x19
  const char *v8; // x3
  __int64 v9; // x19
  const char *v10; // x3

  v3 = *(_QWORD *)(a1 + 152);
  if ( !v3 )
    return -19;
  v5 = scnprintf(
         a3,
         4096,
         "Usage: echo [config_bitmap(in decimal format)] > /sys/kernel/cnss/user_config\n"
         "BIT0 -- XDUMP: Collect WLAN dump over BT\n"
         "BIT1 -- XDUMP: Collect BT dump over WLAN\n"
         "---------------------------------\n");
  if ( (*(_BYTE *)(v3 + 7952) & 1) != 0 )
    v6 = "Yes";
  else
    v6 = "No";
  v7 = (unsigned int)scnprintf(a3 + v5, 4096 - v5, "XDUMP: User specified: %s\n", v6) + v5;
  if ( (*(_BYTE *)(v3 + 7952) & 2) != 0 )
    v8 = "Enabled";
  else
    v8 = "Disabled";
  v9 = (unsigned int)scnprintf(a3 + v7, (unsigned int)(4096 - v7), "XDUMP: Collect WLAN dump over BT: %s\n", v8)
     + (unsigned int)v7;
  if ( (*(_BYTE *)(v3 + 7952) & 4) != 0 )
    v10 = "Enabled";
  else
    v10 = "Disabled";
  return (unsigned int)scnprintf(a3 + v9, (unsigned int)(4096 - v9), "XDUMP: Collect BT dump over WLAN: %s\n", v10)
       + (unsigned int)v9;
}
