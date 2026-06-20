__int64 __fastcall ieee80211_iter_keys(__int64 result, __int64 a2, _DWORD *a3, __int64 a4)
{
  __int64 v6; // x21
  _QWORD *v7; // x23
  _QWORD *v9; // x8
  __int64 v10; // x9
  _QWORD *v11; // x24
  __int64 v12; // x2
  _QWORD *v13; // x22
  _QWORD *i; // x23
  _QWORD *v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x26
  __int64 v18; // x2

  v6 = result;
  if ( a2 )
  {
    v7 = (_QWORD *)(a2 - 3208);
    v9 = *(_QWORD **)(a2 - 3208);
    if ( v9 != (_QWORD *)(a2 - 3208) )
    {
      do
      {
        v10 = *(v9 - 1);
        v11 = (_QWORD *)*v9;
        if ( v10 )
          v12 = v10 + 2688;
        else
          v12 = 0;
        if ( *(a3 - 1) != 1883079838 )
          __break(0x8234u);
        result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD *, __int64))a3)(v6, a2, v12, v9 + 64, a4);
        v9 = v11;
      }
      while ( v11 != v7 );
    }
  }
  else
  {
    v13 = *(_QWORD **)(result + 4616);
    for ( i = (_QWORD *)(result + 4616); v13 != i; v13 = (_QWORD *)*v13 )
    {
      v15 = (_QWORD *)v13[189];
      if ( v15 != v13 + 189 )
      {
        do
        {
          v16 = *(v15 - 1);
          v17 = (_QWORD *)*v15;
          if ( v16 )
            v18 = v16 + 2688;
          else
            v18 = 0;
          if ( *(a3 - 1) != 1883079838 )
            __break(0x8234u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, _QWORD *, __int64))a3)(
                     v6,
                     v13 + 590,
                     v18,
                     v15 + 64,
                     a4);
          v15 = v17;
        }
        while ( v17 != v13 + 189 );
      }
    }
  }
  return result;
}
