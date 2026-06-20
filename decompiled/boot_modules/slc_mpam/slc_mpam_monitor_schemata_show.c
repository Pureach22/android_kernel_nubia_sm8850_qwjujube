__int64 __fastcall slc_mpam_monitor_schemata_show(_BYTE *a1, __int64 a2)
{
  __int64 v4; // x21

  if ( a1[144] == 1 )
    v4 = (int)scnprintf(a2, 4096, "cap=%d,", (unsigned __int8)a1[145]);
  else
    v4 = 0;
  if ( a1[146] == 1 )
    v4 += (int)scnprintf(a2 + v4, 4096 - v4, "miss=%d,", (unsigned __int8)a1[147]);
  if ( a1[148] == 1 )
    v4 += (int)scnprintf(a2 + v4, 4096 - v4, "fe=%d,", (unsigned __int8)a1[149]);
  if ( a1[150] == 1 )
    v4 += (int)scnprintf(a2 + v4, 4096 - v4, "be=%d,", (unsigned __int8)a1[151]);
  if ( v4 )
    return v4 + (int)scnprintf(a2 + v4 - 1, 4096 - v4, "\n");
  else
    return 0;
}
