__int64 __fastcall _ieee80211_sta_recalc_aggregates(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int16 v3; // w20
  __int64 lock; // x0
  __int64 v5; // x8
  unsigned __int64 v6; // x9
  _QWORD *v7; // x20
  char v8; // w12
  unsigned int v9; // w14
  unsigned int v10; // w14
  unsigned int v11; // w14
  unsigned int v12; // w14
  unsigned int v13; // w14
  unsigned int v14; // w14
  unsigned int v15; // w14
  unsigned int v16; // w14
  unsigned int v17; // w14
  unsigned int v18; // w14
  unsigned int v19; // w14
  unsigned int v20; // w14
  unsigned int v21; // w14
  unsigned int v22; // w14
  unsigned int v23; // w14
  unsigned int v24; // w14
  unsigned int v25; // w14
  unsigned int v26; // w13
  _WORD *v27; // x13
  __int64 v28; // x14
  int v29; // w15
  __int64 v30; // x13
  __int64 v31; // x14

  v2 = result;
  if ( *(_WORD *)(result + 2872) && (*(_BYTE *)(result + 2715) & 1) != 0 )
  {
    v3 = a2;
    lock = _rcu_read_lock(result, a2);
    v5 = 0;
    v6 = v3;
    v7 = (_QWORD *)(v2 + 1600);
    v8 = 1;
    do
    {
      if ( ((v6 >> v5) & 1) != 0 )
      {
        v27 = *(_WORD **)(v2 + 3128 + 8 * v5);
        if ( v27 )
        {
          if ( (v8 & 1) != 0 )
          {
            v28 = *(_QWORD *)(v2 + 3098);
            v8 = 0;
            v29 = *(_DWORD *)(v2 + 3106);
            *(_QWORD *)(v2 + 1616) = *(_QWORD *)(v2 + 3090);
            *(_QWORD *)(v2 + 1624) = v28;
            v31 = *(_QWORD *)(v2 + 3074);
            v30 = *(_QWORD *)(v2 + 3082);
            *(_DWORD *)(v2 + 1632) = v29;
            *v7 = v31;
            *(_QWORD *)(v2 + 1608) = v30;
          }
          else
          {
            v9 = *(unsigned __int16 *)(v2 + 1600);
            v8 = 0;
            if ( v9 >= (unsigned __int16)v27[97] )
              LOWORD(v9) = v27[97];
            *(_WORD *)(v2 + 1600) = v9;
            v10 = *(unsigned __int16 *)(v2 + 1602);
            if ( v10 >= (unsigned __int16)v27[98] )
              LOWORD(v10) = v27[98];
            *(_WORD *)(v2 + 1602) = v10;
            v11 = *(unsigned __int16 *)(v2 + 1604);
            if ( v11 >= (unsigned __int16)v27[99] )
              LOWORD(v11) = v27[99];
            *(_WORD *)(v2 + 1604) = v11;
            v12 = *(unsigned __int16 *)(v2 + 1606);
            if ( v12 >= (unsigned __int16)v27[100] )
              LOWORD(v12) = v27[100];
            *(_WORD *)(v2 + 1606) = v12;
            v13 = *(unsigned __int16 *)(v2 + 1608);
            if ( v13 >= (unsigned __int16)v27[101] )
              LOWORD(v13) = v27[101];
            *(_WORD *)(v2 + 1608) = v13;
            v14 = *(unsigned __int16 *)(v2 + 1610);
            if ( v14 >= (unsigned __int16)v27[102] )
              LOWORD(v14) = v27[102];
            *(_WORD *)(v2 + 1610) = v14;
            v15 = *(unsigned __int16 *)(v2 + 1612);
            if ( v15 >= (unsigned __int16)v27[103] )
              LOWORD(v15) = v27[103];
            *(_WORD *)(v2 + 1612) = v15;
            v16 = *(unsigned __int16 *)(v2 + 1614);
            if ( v16 >= (unsigned __int16)v27[104] )
              LOWORD(v16) = v27[104];
            *(_WORD *)(v2 + 1614) = v16;
            v17 = *(unsigned __int16 *)(v2 + 1616);
            if ( v17 >= (unsigned __int16)v27[105] )
              LOWORD(v17) = v27[105];
            *(_WORD *)(v2 + 1616) = v17;
            v18 = *(unsigned __int16 *)(v2 + 1618);
            if ( v18 >= (unsigned __int16)v27[106] )
              LOWORD(v18) = v27[106];
            *(_WORD *)(v2 + 1618) = v18;
            v19 = *(unsigned __int16 *)(v2 + 1620);
            if ( v19 >= (unsigned __int16)v27[107] )
              LOWORD(v19) = v27[107];
            *(_WORD *)(v2 + 1620) = v19;
            v20 = *(unsigned __int16 *)(v2 + 1622);
            if ( v20 >= (unsigned __int16)v27[108] )
              LOWORD(v20) = v27[108];
            *(_WORD *)(v2 + 1622) = v20;
            v21 = *(unsigned __int16 *)(v2 + 1624);
            if ( v21 >= (unsigned __int16)v27[109] )
              LOWORD(v21) = v27[109];
            *(_WORD *)(v2 + 1624) = v21;
            v22 = *(unsigned __int16 *)(v2 + 1626);
            if ( v22 >= (unsigned __int16)v27[110] )
              LOWORD(v22) = v27[110];
            *(_WORD *)(v2 + 1626) = v22;
            v23 = *(unsigned __int16 *)(v2 + 1628);
            if ( v23 >= (unsigned __int16)v27[111] )
              LOWORD(v23) = v27[111];
            *(_WORD *)(v2 + 1628) = v23;
            v24 = *(unsigned __int16 *)(v2 + 1630);
            if ( v24 >= (unsigned __int16)v27[112] )
              LOWORD(v24) = v27[112];
            *(_WORD *)(v2 + 1630) = v24;
            v25 = *(unsigned __int16 *)(v2 + 1632);
            if ( v25 >= (unsigned __int16)v27[113] )
              LOWORD(v25) = v27[113];
            *(_WORD *)(v2 + 1632) = v25;
            v26 = (unsigned __int16)v27[114];
            if ( *(unsigned __int16 *)(v2 + 1634) < v26 )
              LOWORD(v26) = *(_WORD *)(v2 + 1634);
            *(_WORD *)(v2 + 1634) = v26;
          }
        }
      }
      ++v5;
    }
    while ( v5 != 15 );
    result = _rcu_read_unlock(lock);
  }
  else
  {
    v7 = (_QWORD *)(result + 3074);
  }
  *(_QWORD *)(v2 + 2720) = v7;
  return result;
}
