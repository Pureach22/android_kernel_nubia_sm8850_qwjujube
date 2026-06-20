__int64 __fastcall ieee80211_recalc_idle(__int64 result)
{
  _BOOL4 v1; // w8
  _BOOL4 v2; // w9
  unsigned int v3; // w8
  _DWORD *v4; // x19

  v1 = *(_QWORD *)(result + 4984) != result + 4984 || *(_DWORD *)(result + 1320) != 0;
  if ( *(_QWORD *)(*(_QWORD *)(result + 464) + 472LL) )
    v2 = 0;
  else
    v2 = *(_QWORD *)(result + 5264) != result + 5264;
  if ( (*(_QWORD *)(result + 4696) & 1) != 0 || ((v2 || v1) | (*(_QWORD *)(result + 4696) >> 2) & 1) == 1 )
  {
    if ( (*(_DWORD *)result & 4) == 0 )
      return result;
    v3 = *(_DWORD *)result & 0xFFFFFFFB;
  }
  else
  {
    if ( (*(_BYTE *)result & 4) != 0 )
      return result;
    v4 = (_DWORD *)result;
    ieee80211_flush_queues(result, 0, 0);
    result = (__int64)v4;
    v3 = *v4 | 4;
  }
  *(_DWORD *)result = v3;
  return ieee80211_hw_config(result, 256);
}
