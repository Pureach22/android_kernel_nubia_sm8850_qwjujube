__int64 __fastcall ieee80211_set_active_links_async(__int64 result, int a2)
{
  if ( (_WORD)a2 )
  {
    if ( (*(_QWORD *)(result - 3088) & 1) != 0
      && *(_DWORD *)result == 2
      && (a2
        & ((unsigned __int16)(*(_WORD *)(result + 1084) & *(_WORD *)(result + 1080))
         | *(unsigned __int16 *)(result + 1080) ^ 0xFFFF)) == 0
      && *(unsigned __int16 *)(result + 1082) != (unsigned __int16)a2 )
    {
      *(_WORD *)(result - 8) = a2;
      return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(result - 3104) + 72LL), result - 32);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
