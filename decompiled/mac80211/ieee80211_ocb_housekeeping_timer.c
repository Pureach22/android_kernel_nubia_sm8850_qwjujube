__int64 __fastcall ieee80211_ocb_housekeeping_timer(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v9; // x10

  v1 = *(_QWORD *)(a1 - 648);
  _X9 = (unsigned __int64 *)(a1 + 40);
  __asm { PRFM            #0x11, [X9] }
  do
    v9 = __ldxr(_X9);
  while ( __stxr(v9 | 1, _X9) );
  return wiphy_work_queue(*(_QWORD *)(v1 + 72), a1 - 304);
}
