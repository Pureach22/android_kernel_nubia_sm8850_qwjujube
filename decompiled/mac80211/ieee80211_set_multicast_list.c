__int64 __fastcall ieee80211_set_multicast_list(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v6; // w10
  unsigned int v13; // w9

  v2 = *(_QWORD *)(a1 + 4304);
  if ( (*(_DWORD *)(a1 + 4312) & 1) != (*(_DWORD *)(a1 + 176) & 0x200u) >> 9 )
  {
    if ( (*(_DWORD *)(a1 + 176) & 0x200) != 0 )
    {
      _X8 = (unsigned int *)(v2 + 2528);
      __asm { PRFM            #0x11, [X8] }
      do
        v13 = __ldxr(_X8);
      while ( __stxr(v13 + 1, _X8) );
    }
    else
    {
      _X8 = (unsigned int *)(v2 + 2528);
      __asm { PRFM            #0x11, [X8] }
      do
        v6 = __ldxr(_X8);
      while ( __stxr(v6 - 1, _X8) );
    }
    *(_DWORD *)(a1 + 4312) ^= 1u;
  }
  raw_spin_lock_bh(v2 + 1404);
  _hw_addr_sync(v2 + 1432, a1 + 880, *(unsigned __int8 *)(a1 + 824));
  raw_spin_unlock_bh(v2 + 1404);
  return wiphy_work_queue(*(_QWORD *)(v2 + 72), v2 + 1408);
}
