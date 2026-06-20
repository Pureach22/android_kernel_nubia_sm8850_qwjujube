__int64 __fastcall ieee80211_channel_switch_disconnect(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20

  v5 = *(_QWORD *)(a1 - 3104);
  printk(&unk_B8291, a1 - 3080, a3, a4);
  return wiphy_work_queue(*(_QWORD *)(v5 + 72), a1 - 2288);
}
