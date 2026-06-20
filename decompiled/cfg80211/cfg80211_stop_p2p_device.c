__int64 __fastcall cfg80211_stop_p2p_device(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x8
  __int64 v8; // x8

  if ( *(_DWORD *)(a2 + 8) != 10 )
  {
    __break(0x800u);
    return result;
  }
  v2 = *(_QWORD *)(a2 + 32);
  v4 = result;
  if ( v2 )
  {
    if ( (*(_QWORD *)(v2 + 168) & 1) == 0 )
      return result;
  }
  else if ( *(_BYTE *)(a2 + 66) != 1 )
  {
    return result;
  }
  v5 = result + 992;
  v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 664LL);
  if ( *((_DWORD *)v6 - 1) != 1366774891 )
    __break(0x8228u);
  result = v6(v5);
  *(_BYTE *)(a2 + 66) = 0;
  v7 = *(_QWORD *)(v4 + 224);
  --*(_DWORD *)(v4 + 112);
  if ( v7 && *(_QWORD *)(v7 + 64) == a2 )
  {
    if ( (*(_BYTE *)(v7 + 128) & 1) == 0 )
    {
      v8 = *(_QWORD *)(v4 + 232);
      if ( !v8 || (*(_BYTE *)(v8 + 128) & 1) == 0 )
      {
        __break(0x800u);
        *(_BYTE *)(*(_QWORD *)(v4 + 224) + 126LL) = 1;
      }
    }
    return __cfg80211_scan_done(v4, 0);
  }
  return result;
}
