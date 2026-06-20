__int64 __fastcall ieee80211_sta_reorder_release(__int64 result)
{
  unsigned int v1; // w9
  unsigned int v2; // w8
  __int64 v3; // x11
  __int64 v4; // x19
  unsigned int v5; // w22
  __int64 v6; // x12
  unsigned __int64 v7; // x10
  __int64 v8; // x12
  unsigned int v9; // w21
  int v10; // w26
  __int64 v11; // x11
  __int64 v12; // x11
  int v13; // w9
  unsigned __int64 v14; // x11
  __int64 v15; // x13
  __int64 v16; // x13
  unsigned __int64 v17; // x12
  __int64 v18; // x10
  __int64 v19; // x11
  unsigned int i; // w27
  __int64 v21; // x28
  __int64 *v22; // x1
  __int64 v24; // x8
  _QWORD *v25; // x9

  v1 = *(unsigned __int16 *)(result + 144);
  v2 = *(unsigned __int16 *)(result + 150);
  v3 = *(_QWORD *)(result + 32);
  v4 = result;
  v5 = v1 % v2;
  v6 = v3 + 24LL * (v1 % v2);
  v7 = *(_QWORD *)(result + 24);
  if ( *(_QWORD *)(v6 + 8) == v6 )
    v8 = 0;
  else
    v8 = *(_QWORD *)(v6 + 8);
  if ( v7 && ((v7 >> v5) & 1) != 0 || v8 && (*(_BYTE *)(v8 + 66) & 8) == 0 || !*(_WORD *)(result + 146) )
  {
    while ( 1 )
    {
      v11 = v3 + 24LL * v5;
      v12 = *(_QWORD *)(v11 + 8) == v11 ? 0LL : *(_QWORD *)(v11 + 8);
      if ( (!v7 || ((v7 >> v5) & 1) == 0) && (!v12 || (*(_BYTE *)(v12 + 66) & 8) != 0) )
        break;
      result = ieee80211_release_reorder_frame(v4);
      v1 = *(unsigned __int16 *)(v4 + 144);
      v2 = *(unsigned __int16 *)(v4 + 150);
      v5 = v1 % v2;
      v7 = *(_QWORD *)(v4 + 24);
      v3 = *(_QWORD *)(v4 + 32);
    }
  }
  else if ( (unsigned __int16)(v5 + 1) % v2 != (unsigned __int16)v5 )
  {
    v9 = (unsigned __int16)((unsigned __int16)(v5 + 1) % *(_WORD *)(result + 150));
    v10 = 1;
    do
    {
      v17 = *(_QWORD *)(v4 + 24);
      v18 = *(_QWORD *)(v4 + 32) + 24LL * v9;
      v19 = *(_QWORD *)(v18 + 8);
      if ( v19 == v18 )
        v19 = 0;
      if ( v17 && ((v17 >> v9) & 1) != 0 || v19 && (*(_BYTE *)(v19 + 66) & 8) == 0 )
      {
        if ( v10 && *(_QWORD *)(*(_QWORD *)(v4 + 40) + 8LL * v9) - jiffies + 25LL >= 0 )
          goto LABEL_58;
        for ( i = (v5 + 1) % (unsigned __int16)v2; i != v9; i = (i + 1) % (unsigned __int16)v2 )
        {
          v21 = *(_QWORD *)(v4 + 32) + 24LL * i;
          v22 = *(__int64 **)v21;
          if ( *(_QWORD *)v21 != v21 && v22 != nullptr )
          {
            do
            {
              --*(_DWORD *)(v21 + 16);
              v24 = *v22;
              v25 = (_QWORD *)v22[1];
              *v22 = 0;
              v22[1] = 0;
              *(_QWORD *)(v24 + 8) = v25;
              *v25 = v24;
              sk_skb_reason_drop(0);
              v22 = *(__int64 **)v21;
            }
            while ( *(_QWORD *)v21 != v21 && v22 );
            LOWORD(v2) = *(_WORD *)(v4 + 150);
          }
        }
        result = ieee80211_release_reorder_frame(v4);
        LOWORD(v2) = *(_WORD *)(v4 + 144) + v10;
        v10 = 0;
        LOWORD(v1) = v2 & 0xFFF;
        LOWORD(v2) = *(_WORD *)(v4 + 150);
        *(_WORD *)(v4 + 144) = v1;
      }
      else
      {
        ++v10;
      }
      v9 = (v9 + 1) % (unsigned __int16)v2;
    }
    while ( v9 != v5 );
  }
  if ( !*(_WORD *)(v4 + 146) )
    return timer_delete((timer_t)(v4 + 96));
  v9 = (unsigned __int16)v1 % (unsigned int)(unsigned __int16)v2;
  v13 = (int)(v9 - 1) % (unsigned __int16)v2;
  if ( v13 != v9 )
  {
    v14 = *(_QWORD *)(v4 + 24);
    while ( 1 )
    {
      v15 = *(_QWORD *)(v4 + 32) + 24LL * v9;
      v16 = *(_QWORD *)(v15 + 8) == v15 ? 0LL : *(_QWORD *)(v15 + 8);
      if ( v14 && ((v14 >> v9) & 1) != 0 || v16 && (*(_BYTE *)(v16 + 66) & 8) == 0 )
        break;
      if ( v9 + 1 == (unsigned __int16)v2 )
        v9 = 0;
      else
        ++v9;
      if ( v9 == v13 )
      {
        v9 = v13;
        break;
      }
    }
  }
LABEL_58:
  if ( (*(_BYTE *)(v4 + 155) & 2) == 0 )
    return mod_timer(v4 + 96, *(_QWORD *)(*(_QWORD *)(v4 + 40) + 8LL * v9) + 26LL);
  return result;
}
