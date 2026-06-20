_DWORD *__fastcall cfg80211_schedule_channels_check(_DWORD *result)
{
  if ( result[2] == 2 && (*(_BYTE *)(*(_QWORD *)result + 120LL) & 8) != 0 )
    return (_DWORD *)reg_check_channels(result);
  return result;
}
