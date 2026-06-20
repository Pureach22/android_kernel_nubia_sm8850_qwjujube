__int64 __fastcall ieee80211_sta_bcn_mon_timer(__int64 result)
{
  __int64 v1; // x9

  if ( *(_WORD *)(result + 3456) )
  {
    __break(0x800u);
  }
  else if ( (*(_BYTE *)(result + 3294) != 1 || *(_BYTE *)(result + 2056) == 1) && (*(_BYTE *)(result + 3528) & 1) == 0 )
  {
    v1 = *(_QWORD *)(result - 728);
    *(_BYTE *)(result + 133) &= ~1u;
    return wiphy_work_queue(*(_QWORD *)(v1 + 72), result + 64);
  }
  return result;
}
