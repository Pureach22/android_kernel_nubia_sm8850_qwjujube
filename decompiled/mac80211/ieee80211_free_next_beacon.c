__int64 __fastcall ieee80211_free_next_beacon(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 568);
  if ( v1 )
  {
    v2 = result;
    kfree(*(_QWORD *)(v1 + 72));
    kfree(*(_QWORD *)(*(_QWORD *)(v2 + 568) + 80LL));
    result = kfree(*(_QWORD *)(v2 + 568));
    *(_QWORD *)(v2 + 568) = 0;
  }
  return result;
}
