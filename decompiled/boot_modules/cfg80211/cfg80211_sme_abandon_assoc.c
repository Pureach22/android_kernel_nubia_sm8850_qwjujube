__int64 *__fastcall cfg80211_sme_abandon_assoc(__int64 *result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x1

  v2 = *result;
  if ( *result )
  {
    v3 = result[10];
    if ( v3 )
    {
      v4 = system_wq;
      *(_DWORD *)(v3 + 400) = 10;
      return (__int64 *)queue_work_on(32, v4, v2 - 688);
    }
  }
  else
  {
    __break(0x800u);
    return (__int64 *)cfg80211_wdev_release_link_bsses(result, a2);
  }
  return result;
}
