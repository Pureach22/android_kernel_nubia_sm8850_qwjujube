__int64 __fastcall ieee80211_tx_h_calculate_duration(__int64 result, __int64 a2)
{
  __int64 v2; // x21
  __int64 *v3; // x22
  __int64 v4; // x19
  __int16 v5; // w20
  __int64 v6; // x27
  int v7; // w28
  int v8; // w26
  __int64 v9; // x20
  __int64 lock; // x0
  __int64 v11; // x8
  int v12; // w8
  int v13; // w24
  __int64 v14; // x25
  unsigned __int16 *v15; // x8
  int v16; // w10
  __int64 v17; // x11
  unsigned int *v18; // x26
  __int64 v19; // x2
  __int64 v20; // x10
  __int64 v21; // x11
  unsigned int v22; // w9
  __int64 v23; // x12
  __int64 v24; // x15
  int v25; // w16
  int v26; // w14
  __int64 v27; // x9
  char v28; // w24

  v2 = result + 8;
  v3 = *(__int64 **)(result + 8);
  if ( v3 != (__int64 *)(result + 8) )
  {
    v4 = result;
    do
    {
      v6 = v3[28];
      if ( (*(_WORD *)v6 & 0xFC) == 0xA4 )
        return result;
      if ( *v3 == v2 )
        v7 = 0;
      else
        v7 = *(_DWORD *)(*v3 + 112);
      if ( (*(_WORD *)(v4 + 65) & 0x2100) != 0 )
        goto LABEL_3;
      v8 = *(_DWORD *)(v6 + 4);
      v9 = *(_QWORD *)(v4 + 32);
      lock = _rcu_read_lock(result, a2);
      v11 = *(_QWORD *)(*(_QWORD *)(v4 + 40) + 5640LL);
      if ( v11 )
      {
        v12 = *(_DWORD *)(v11 + 8);
        if ( v12 == 6 )
          v13 = 32;
        else
          v13 = (v12 == 7) << 6;
      }
      else
      {
        v13 = 0;
      }
      result = _rcu_read_unlock(lock);
      if ( (*(char *)(v4 + 64) & 0x8000000000000000LL) != 0 )
      {
        v5 = 0;
        __break(0x800u);
        goto LABEL_4;
      }
      if ( (*((_DWORD *)v3 + 11) & 7u) >= 6 )
      {
        __break(0x5512u);
        return ieee80211_store_ack_skb(result, a2);
      }
      v14 = *(_QWORD *)(*(_QWORD *)(v9 + 72) + 8LL * (*((_DWORD *)v3 + 11) & 7) + 328);
      if ( *(_DWORD *)(v14 + 16) == 4 )
      {
LABEL_3:
        v5 = 0;
      }
      else
      {
        v5 = 0;
        if ( (v8 & 1) != 0 )
          goto LABEL_4;
        v15 = (unsigned __int16 *)v3[28];
        v16 = *v15;
        if ( (v16 & 0xC) == 4 )
          goto LABEL_4;
        v17 = *(_QWORD *)(v14 + 8);
        v18 = (unsigned int *)(v17 + 12LL * *(char *)(v4 + 64));
        v19 = *(unsigned __int16 *)(v17 + 4);
        a2 = *v18;
        if ( *(int *)(v14 + 24) >= 1 )
        {
          v20 = 0;
          v21 = 0;
          v22 = -1;
          while ( 1 )
          {
            v23 = *(_QWORD *)(v14 + 8) + v20;
            if ( *(unsigned __int16 *)(v23 + 4) > (unsigned int)*((unsigned __int16 *)v18 + 2) )
            {
LABEL_39:
              v16 = *v15;
              if ( v22 == -1 )
                v19 = (unsigned int)v19;
              else
                v19 = v22;
              break;
            }
            if ( (v13 & ~*(_DWORD *)v23) == 0 )
            {
              v24 = *(_QWORD *)(v4 + 40);
              v25 = *(_DWORD *)(v14 + 16);
              if ( (((unsigned __int64)*(unsigned int *)(v24 + 4880) >> v21) & 1) != 0 )
                v22 = *(unsigned __int16 *)(v23 + 4);
              v26 = 2;
              if ( v25 > 2 )
              {
                if ( v25 == 3 )
                  goto LABEL_36;
                if ( v25 == 5 )
                {
LABEL_33:
                  if ( *(_BYTE *)(v24 + 3752) )
                    v26 = 8;
                  else
                    v26 = 4;
LABEL_36:
                  if ( (v26 & *(_DWORD *)v23) != 0 )
                    LODWORD(v19) = *(unsigned __int16 *)(v23 + 4);
                  goto LABEL_22;
                }
              }
              else
              {
                if ( !v25 )
                  goto LABEL_33;
                if ( v25 == 1 )
                  goto LABEL_36;
              }
              __break(0x800u);
            }
LABEL_22:
            ++v21;
            v20 += 12;
            if ( v21 >= *(int *)(v14 + 24) )
              goto LABEL_39;
          }
        }
        if ( (v16 & 0x8C) != 0x88 )
          goto LABEL_46;
        v27 = 12;
        if ( (~v16 & 0x300) == 0 )
          v27 = 15;
        if ( (v15[v27] & 0x20) == 0 )
        {
LABEL_46:
          v28 = a2;
          result = ieee80211_frame_duration(
                     *(unsigned int *)(v14 + 16),
                     10,
                     v19,
                     a2 & 0x10,
                     *(unsigned __int8 *)(*(_QWORD *)(v4 + 40) + 4854LL));
          v5 = result;
          if ( !v7 )
            goto LABEL_4;
LABEL_49:
          result = ieee80211_frame_duration(
                     *(unsigned int *)(v14 + 16),
                     v7,
                     *((unsigned __int16 *)v18 + 2),
                     v28 & 0x10,
                     *(unsigned __int8 *)(*(_QWORD *)(v4 + 40) + 4854LL));
          v5 = result + 2 * v5;
          goto LABEL_4;
        }
        v28 = a2;
        v5 = 0;
        if ( v7 )
          goto LABEL_49;
      }
LABEL_4:
      *(_WORD *)(v6 + 2) = v5;
      v3 = (__int64 *)*v3;
    }
    while ( v3 != (__int64 *)v2 );
  }
  return result;
}
