__int64 __fastcall ieee80211_stop(__int64 a1)
{
  __int64 v2; // x20
  _QWORD *v3; // x8
  _QWORD *v4; // x21
  _QWORD *v5; // x22
  __int64 v6; // x21
  __int64 v7; // x8
  _QWORD *v8; // x23
  _QWORD *v9; // x9
  _QWORD *v10; // x25
  __int64 v11; // x0

  v2 = a1 + 2688;
  if ( *(_DWORD *)(a1 + 7408) == 3 )
  {
    v3 = *(_QWORD **)(a1 + 4952);
    v4 = (_QWORD *)(a1 + 4952);
    if ( v3 != (_QWORD *)(a1 + 4952) )
    {
      do
      {
        v5 = (_QWORD *)*v3;
        dev_close(*(v3 - 82));
        v3 = v5;
      }
      while ( v5 != v4 );
    }
    v6 = *(_QWORD *)(a1 + 8576);
    if ( v6 )
    {
      *(_QWORD *)(a1 + 8576) = 0;
      v7 = *(_QWORD *)(v6 - 3104);
      v8 = (_QWORD *)(v6 - 4720);
      v9 = *(_QWORD **)(v7 + 4616);
      if ( v9 != (_QWORD *)(v7 + 4616) )
      {
        do
        {
          v10 = (_QWORD *)*v9;
          if ( v9 != (_QWORD *)v2 && v9 != v8 && v9[736] == v6 && (v9[204] & 1) != 0 )
          {
            v11 = v9[6];
            v9[736] = 0;
            dev_close(v11);
            v7 = *(_QWORD *)(v6 - 3104);
          }
          v9 = v10;
        }
        while ( v10 != (_QWORD *)(v7 + 4616) );
      }
      if ( v8 != (_QWORD *)v2 && (*(_QWORD *)(v6 - 3088) & 1) != 0 )
      {
        *(_QWORD *)(v6 + 1168) = 0;
        dev_close(*(_QWORD *)(v6 - 4672));
      }
    }
  }
  mutex_lock(*(_QWORD *)(*(_QWORD *)(a1 + 4304) + 72LL));
  wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(a1 + 4304) + 72LL), a1 + 7376);
  ieee80211_do_stop(v2, 1);
  mutex_unlock(*(_QWORD *)(*(_QWORD *)(a1 + 4304) + 72LL));
  return 0;
}
