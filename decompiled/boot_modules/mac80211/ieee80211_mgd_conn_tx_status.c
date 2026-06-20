__int64 __fastcall ieee80211_mgd_conn_tx_status(__int64 a1, __int16 a2, char a3)
{
  __int64 v3; // x8

  v3 = *(_QWORD *)(a1 + 1616);
  *(_WORD *)(a1 + 2508) = a2;
  *(_BYTE *)(a1 + 2506) = a3;
  *(_BYTE *)(a1 + 2507) = 1;
  return wiphy_work_queue(*(_QWORD *)(v3 + 72), a1 + 1960);
}
