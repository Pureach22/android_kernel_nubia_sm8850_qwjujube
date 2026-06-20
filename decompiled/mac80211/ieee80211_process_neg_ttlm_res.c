__int64 __fastcall ieee80211_process_neg_ttlm_res(__int64 result, __int64 a2)
{
  __int64 v3; // x19

  if ( *(_WORD *)(result + 5800) && *(unsigned __int8 *)(a2 + 26) == *(unsigned __int8 *)(result + 3152) )
  {
    v3 = result;
    result = wiphy_delayed_work_cancel(*(_QWORD *)(*(_QWORD *)(result + 1616) + 72LL), result + 3160);
    if ( *(_BYTE *)(a2 + 27) )
      return _ieee80211_disconnect(v3);
  }
  return result;
}
