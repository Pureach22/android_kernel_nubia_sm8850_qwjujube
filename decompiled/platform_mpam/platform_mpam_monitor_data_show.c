__int64 __fastcall platform_mpam_monitor_data_show(__int64 a1, __int64 a2)
{
  int v2; // w11
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v5; // x4
  __int64 result; // x0

  if ( *(_BYTE *)(a1 + 148) == 1 )
  {
    v2 = 32;
    v3 = 24;
    if ( (unsigned int)mpam_version <= 0x10001 )
      v2 = 24;
    v4 = mpam_mon_base + v2 * (__int64)*(int *)(a1 + 144);
    if ( (unsigned int)mpam_version <= 0x10001 )
      v3 = 16;
    if ( (unsigned int)mpam_version < 0x10002 )
      v5 = *(unsigned int *)(v4 + 12);
    else
      v5 = *(_QWORD *)(v4 + 16);
    LODWORD(result) = scnprintf(a2, 4096, "timestamp=%llu,byte_cnt=%llu\n", *(_QWORD *)(v4 + v3), v5);
  }
  else
  {
    LODWORD(result) = scnprintf(a2, 4096, "monitor not enabled\n");
  }
  return (int)result;
}
