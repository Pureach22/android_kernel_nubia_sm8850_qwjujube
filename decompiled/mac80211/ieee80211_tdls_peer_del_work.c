__int64 __fastcall ieee80211_tdls_peer_del_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0

  v2 = a2 - 6;
  if ( *(_DWORD *)(a2 - 6) | *(unsigned __int16 *)(a2 - 2) )
  {
    result = sta_info_destroy_addr(a2 - 2648, (const void *)(a2 - 6));
    *(_DWORD *)v2 = 0;
    *(_WORD *)(v2 + 4) = 0;
  }
  return result;
}
