__int64 __fastcall sub_6895DC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, int a6)
{
  return hdd_roam_scan_stats_cb(a1, a2, a3, a4, a6 ^ (unsigned int)~((int)a2 >> 6));
}
