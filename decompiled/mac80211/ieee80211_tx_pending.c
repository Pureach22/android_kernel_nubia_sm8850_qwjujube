__int64 __fastcall ieee80211_tx_pending(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x21
  unsigned int v5; // w8
  __int64 v6; // x24
  __int64 v7; // x20
  __int64 v8; // x25
  __int64 v9; // x26
  __int64 v10; // x22
  char v11; // w0
  char v12; // w22
  __int64 v13; // x8
  _QWORD *v14; // x9
  char v15; // w8
  __int64 v16; // x21
  unsigned __int64 v17; // x0
  _DWORD **v18; // x8
  unsigned __int64 v19; // x2
  __int64 v20; // x0
  __int64 result; // x0
  unsigned __int16 *v22; // [xsp+8h] [xbp-38h]
  __int64 v23; // [xsp+10h] [xbp-30h]
  _QWORD v24[2]; // [xsp+18h] [xbp-28h] BYREF
  int v25; // [xsp+28h] [xbp-18h]
  int v26; // [xsp+2Ch] [xbp-14h]
  unsigned __int64 v27[2]; // [xsp+30h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _rcu_read_lock(a1, a2);
  v3 = a1 - 1072;
  v4 = raw_spin_lock_irqsave(a1 - 1072);
  v22 = (unsigned __int16 *)(a1 - 2256);
  v5 = *(unsigned __int16 *)(a1 - 2256);
  if ( *(_WORD *)(a1 - 2256) )
  {
    v6 = 0;
    v7 = a1 - 2384;
    v8 = a1 - 1904;
    v23 = a1 - 384;
    while ( 1 )
    {
      if ( v6 == 16 )
        __break(0x5512u);
      if ( !*(_QWORD *)(v8 + 8 * v6) )
      {
        v9 = v23 + 24 * v6;
        v10 = *(_QWORD *)v9;
        if ( *(_QWORD *)v9 != v9 )
          break;
      }
LABEL_4:
      if ( ++v6 >= (unsigned __int64)v5 )
        goto LABEL_29;
    }
    while ( 1 )
    {
      if ( v10 )
      {
        --*(_DWORD *)(v9 + 16);
        v13 = *(_QWORD *)v10;
        v14 = *(_QWORD **)(v10 + 8);
        *(_QWORD *)v10 = 0;
        *(_QWORD *)(v10 + 8) = 0;
        *(_QWORD *)(v13 + 8) = v14;
        *v14 = v13;
      }
      if ( *(_QWORD *)(v10 + 64) )
      {
        raw_spin_unlock_irqrestore(v3, v4);
        v15 = *(_BYTE *)(v10 + 80);
        v16 = *(_QWORD *)(v10 + 64);
        v27[0] = 0;
        if ( (v15 & 0x40) != 0 )
        {
          if ( *(_WORD *)(v16 + 1080) )
            goto LABEL_10;
          v18 = *(_DWORD ***)(v16 + 920);
          if ( v18 )
          {
            *(_DWORD *)(v10 + 44) = *(_DWORD *)(v10 + 44) & 0xFFFFFFF8 | **v18 & 7;
LABEL_10:
            v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64))ieee80211_tx)(v16 - 4720, 0, v10, 1);
LABEL_11:
            v12 = v11;
            v4 = raw_spin_lock_irqsave(v3);
            if ( (v12 & 1) == 0 )
              goto LABEL_3;
            goto LABEL_12;
          }
        }
        else
        {
          if ( (*(_BYTE *)(v10 + 41) & 0x40) == 0 )
          {
            v26 = 0;
            *(_QWORD *)v10 = v24;
            *(_QWORD *)(v10 + 8) = v24;
            v24[1] = v10;
            v24[0] = v10;
            v25 = 1;
            v17 = sta_info_get(v16 - 4720, (const void *)(*(_QWORD *)(v10 + 224) + 4LL));
            v11 = _ieee80211_tx(v7, v24, v17, 1);
            goto LABEL_11;
          }
          if ( !(unsigned int)ieee80211_lookup_ra_sta(v16 - 4720, v10, v27) )
          {
            v19 = v27[0];
            if ( v27[0] > 0xFFFFFFFFFFFFF000LL || v27[0] && (*(_BYTE *)(v27[0] + 204) & 1) == 0 )
            {
              v19 = 0;
              v27[0] = 0;
            }
            v11 = ieee80211_tx_8023(v16 - 4720, v10, v19, 1);
            goto LABEL_11;
          }
        }
        consume_skb(v10);
        v4 = raw_spin_lock_irqsave(v3);
      }
      else
      {
        __break(0x800u);
        ieee80211_free_txskb(v7, v10);
      }
LABEL_12:
      v10 = *(_QWORD *)v9;
      if ( *(_QWORD *)v9 == v9 )
      {
LABEL_3:
        v5 = *v22;
        goto LABEL_4;
      }
    }
  }
LABEL_29:
  v20 = raw_spin_unlock_irqrestore(v3, v4);
  result = _rcu_read_unlock(v20);
  _ReadStatusReg(SP_EL0);
  return result;
}
