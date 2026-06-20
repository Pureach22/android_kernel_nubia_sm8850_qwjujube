__int64 __fastcall cfg80211_sme_deauth(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 80);
  if ( v1 )
  {
    v2 = result;
    kfree(*(_QWORD *)(v1 + 416));
    result = kfree(*(_QWORD *)(v2 + 80));
    *(_QWORD *)(v2 + 80) = 0;
  }
  return result;
}
