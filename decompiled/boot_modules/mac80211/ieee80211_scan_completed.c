__int64 __fastcall ieee80211_scan_completed(_QWORD *a1, __int64 *a2)
{
  __int64 v2; // x10
  __int64 v3; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v14; // x9

  _X8 = a1 + 587;
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 | 8, _X8) );
  if ( *((_BYTE *)a2 + 14) == 1 )
  {
    _X8 = a1 + 587;
    __asm { PRFM            #0x11, [X8] }
    do
      v14 = __ldxr(_X8);
    while ( __stxr(v14 | 0x10, _X8) );
  }
  v2 = *a2;
  v3 = a1[9];
  a1[603] = a2[1];
  a1[602] = v2;
  return wiphy_delayed_work_queue(v3, a1 + 612, 0);
}
