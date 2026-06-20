__int64 __fastcall ieee80211_check_fast_rx_iface(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x20
  _QWORD *v4; // x21
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x8

  v2 = *(_QWORD *)(result + 1616);
  v3 = *(_QWORD **)(v2 + 1616);
  v4 = (_QWORD *)(v2 + 1616);
  if ( v3 != (_QWORD *)(v2 + 1616) )
  {
    v5 = result;
    do
    {
      v6 = v3[10];
      if ( v6 == v5 || (v7 = *(_QWORD *)(v6 + 2032)) != 0 && v7 == *(_QWORD *)(v5 + 2032) )
        result = ieee80211_check_fast_rx((__int64)v3, a2);
      v3 = (_QWORD *)*v3;
    }
    while ( v3 != v4 );
  }
  return result;
}
