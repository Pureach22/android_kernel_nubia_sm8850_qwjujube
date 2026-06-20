__int64 __fastcall ieee80211_get_max_required_bw(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x21
  __int64 v6; // x8
  _QWORD *v7; // x22
  __int64 v8; // x23
  unsigned int v9; // w19
  unsigned int v10; // w9
  __int64 v11; // x9
  __int64 v12; // x9
  _QWORD *v13; // x8
  __int64 v14; // x20

  v5 = *(_QWORD *)a1;
  v6 = *(_QWORD *)(*(_QWORD *)a1 + 1616LL);
  v7 = *(_QWORD **)(v6 + 1616);
  if ( v7 != (_QWORD *)(v6 + 1616) )
  {
    v8 = a1[2];
    v9 = 0;
    while ( 1 )
    {
      v11 = v7[10];
      if ( v5 != v11 )
      {
        v12 = *(_QWORD *)(v11 + 2032);
        if ( !v12 || v12 != *(_QWORD *)(v5 + 2032) )
          goto LABEL_6;
      }
      if ( (unsigned int)v8 >= 0xF )
      {
        __break(0x5512u);
        return ieee80211_change_chanctx(a1, a2, a3, a4, a5);
      }
      v13 = &v7[v8];
      v14 = v13[321];
      if ( !v14 )
      {
        v10 = 0;
        goto LABEL_4;
      }
      a1 = (unsigned int *)((__int64 (__fastcall *)(_QWORD, _QWORD))ieee80211_sta_cap_rx_bw)(v13[321], 0);
      if ( (int)a1 <= 1 )
      {
        if ( !(_DWORD)a1 )
        {
          v10 = *(unsigned __int8 *)(*(_QWORD *)(v14 + 920) + 46LL);
          goto LABEL_4;
        }
        if ( (_DWORD)a1 == 1 )
        {
          v10 = 2;
          goto LABEL_4;
        }
      }
      else
      {
        switch ( (_DWORD)a1 )
        {
          case 2:
            v10 = 3;
            goto LABEL_4;
          case 3:
            v10 = 5;
            goto LABEL_4;
          case 4:
            v10 = 13;
            goto LABEL_4;
        }
      }
      v10 = 1;
      __break(0x800u);
LABEL_4:
      v6 = *(_QWORD *)(v5 + 1616);
      if ( v9 <= v10 )
        v9 = v10;
LABEL_6:
      v7 = (_QWORD *)*v7;
      if ( v7 == (_QWORD *)(v6 + 1616) )
        return v9;
    }
  }
  return 0;
}
