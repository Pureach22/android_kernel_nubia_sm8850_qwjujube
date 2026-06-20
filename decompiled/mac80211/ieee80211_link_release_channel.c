__int64 *__fastcall ieee80211_link_release_channel(__int64 *result)
{
  if ( *(_QWORD *)(result[118] + 832) )
    return _ieee80211_link_release_channel(result, 0);
  return result;
}
