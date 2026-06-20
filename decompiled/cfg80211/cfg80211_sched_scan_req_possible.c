__int64 __fastcall cfg80211_sched_scan_req_possible(__int64 a1, char a2)
{
  _QWORD *v2; // x9
  int v3; // w10

  v2 = *(_QWORD **)(a1 + 248);
  if ( v2 == (_QWORD *)(a1 + 248) )
    return 0;
  v3 = 0;
  do
  {
    if ( !v3 && !*(v2 - 21) )
      return 4294967181LL;
    v2 = (_QWORD *)*v2;
    ++v3;
  }
  while ( v2 != (_QWORD *)(a1 + 248) );
  if ( !v3 )
    return 0;
  if ( (a2 & 1) == 0 )
    return 4294967181LL;
  if ( *(unsigned __int8 *)(a1 + 1129) != v3 )
    return 0;
  return 4294967268LL;
}
