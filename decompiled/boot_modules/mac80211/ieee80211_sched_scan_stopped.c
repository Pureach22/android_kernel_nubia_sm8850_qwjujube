__int64 __fastcall ieee80211_sched_scan_stopped(__int64 result)
{
  if ( (*(_BYTE *)(result + 1470) & 1) == 0 )
    return wiphy_work_queue(*(_QWORD *)(result + 72), result + 4832);
  return result;
}
