__int64 __fastcall ieee80211_roc_setup(_QWORD *a1)
{
  _QWORD *v2; // x20
  __int64 result; // x0

  a1[660] = a1 + 660;
  a1[661] = a1 + 660;
  a1[662] = ieee80211_hw_roc_start;
  a1[663] = a1 + 663;
  v2 = a1 + 649;
  a1[664] = a1 + 663;
  a1[665] = ieee80211_hw_roc_done;
  result = init_timer_key(a1 + 653, &wiphy_delayed_work_timer, 0, 0, 0);
  a1[649] = v2;
  a1[650] = v2;
  a1[651] = ieee80211_roc_work;
  a1[658] = a1 + 658;
  a1[659] = a1 + 658;
  return result;
}
