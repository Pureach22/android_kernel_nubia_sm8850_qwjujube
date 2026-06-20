bool __fastcall ieee80211_chanreq_identical(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  if ( *(_QWORD *)a1 != *(_QWORD *)a2
    || *(_DWORD *)(a1 + 8) != *(_DWORD *)(a2 + 8)
    || *(_DWORD *)(a1 + 12) != *(_DWORD *)(a2 + 12)
    || *(unsigned __int16 *)(a1 + 28) != *(unsigned __int16 *)(a2 + 28)
    || *(_DWORD *)(a1 + 16) != *(_DWORD *)(a2 + 16)
    || *(unsigned __int16 *)(a1 + 30) != *(unsigned __int16 *)(a2 + 30) )
  {
    return 0;
  }
  v2 = *(_QWORD *)(a1 + 32);
  v3 = *(_QWORD *)(a2 + 32);
  if ( !(v2 | v3) )
    return 1;
  return v2 == v3
      && *(_DWORD *)(a1 + 40) == *(_DWORD *)(a2 + 40)
      && *(_DWORD *)(a1 + 44) == *(_DWORD *)(a2 + 44)
      && *(unsigned __int16 *)(a1 + 60) == *(unsigned __int16 *)(a2 + 60)
      && *(_DWORD *)(a1 + 48) == *(_DWORD *)(a2 + 48)
      && *(unsigned __int16 *)(a1 + 62) == *(unsigned __int16 *)(a2 + 62);
}
