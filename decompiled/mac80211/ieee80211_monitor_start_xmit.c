__int64 __fastcall ieee80211_monitor_start_xmit(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x8
  _QWORD *v3; // x24
  unsigned __int64 v4; // x23
  __int64 v5; // x8
  unsigned int v6; // w19
  int v7; // w9
  unsigned __int16 *v8; // x22
  __int64 v9; // x25
  unsigned __int16 v11; // w20
  __int64 v12; // x1
  int v13; // w8
  int v14; // w11
  __int64 v15; // x20
  char *v16; // x8
  __int64 lock; // x0
  __int64 v18; // x8
  _DWORD **v19; // x23
  int v20; // w8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v25; // x0
  int v26; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v27; // [xsp+10h] [xbp-10h]
  __int64 v28; // [xsp+18h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a2 + 992);
  if ( v2 )
  {
    v3 = (_QWORD *)*v2;
    if ( *v2 )
    {
      if ( (*(_QWORD *)(a2 + 4320) & 1) != 0 )
      {
        v4 = *(unsigned int *)(a1 + 112);
        *(_QWORD *)(a1 + 72) = 0;
        *(_QWORD *)(a1 + 80) = 0;
        *(_QWORD *)(a1 + 56) = 0;
        *(_QWORD *)(a1 + 64) = 0;
        *(_QWORD *)(a1 + 40) = 0;
        *(_QWORD *)(a1 + 48) = 0;
        *(_DWORD *)(a1 + 40) = 129;
        if ( (unsigned int)v4 >= 8 )
        {
          v5 = *(_QWORD *)(a1 + 224);
          if ( !*(_BYTE *)v5 )
          {
            v6 = *(unsigned __int16 *)(v5 + 2);
            if ( (unsigned int)v4 >= v6 )
            {
              v7 = v6 + v5 - *(_DWORD *)(a1 + 216);
              *(_WORD *)(a1 + 186) = v6 + v5 - *(_WORD *)(a1 + 216);
              *(_WORD *)(a1 + 184) = v7;
              *(_WORD *)(a1 + 182) = v7;
              if ( (unsigned int)v4 >= v6 + 2 )
              {
                v8 = (unsigned __int16 *)(v5 + v6);
                v9 = a1;
                v11 = *v8;
                v13 = ieee80211_hdrlen(*v8);
                a1 = v9;
                if ( (unsigned int)v4 >= v13 + v6 )
                {
                  v14 = v11 & 0xC;
                  v15 = a2 + 2688;
                  if ( v14 == 8 && (int)(v13 + v6) + 8LL <= v4 )
                  {
                    v16 = (char *)v8 + v13;
                    if ( !(rfc1042_header ^ *(_DWORD *)v16
                         | *((unsigned __int16 *)&rfc1042_header + 2) ^ *((unsigned __int16 *)v16 + 2)) )
                      *(_WORD *)(v9 + 180) = *((_WORD *)v16 + 3);
                  }
                  lock = _rcu_read_lock(v9, v12);
                  v18 = v3[769];
                  if ( (_QWORD *)v18 != v3 + 769 )
                  {
                    while ( (*(_QWORD *)(v18 + 1632) & 1) == 0
                         || (*(_DWORD *)(v18 + 4720) | 2) == 6
                         || *(_DWORD *)(v8 + 5) ^ *(_DWORD *)(v18 + 5842) | v8[7] ^ *(unsigned __int16 *)(v18 + 5846) )
                    {
                      v18 = *(_QWORD *)v18;
                      if ( (_QWORD *)v18 == v3 + 769 )
                        goto LABEL_20;
                    }
                    v15 = v18;
                  }
LABEL_20:
                  v19 = *(_DWORD ***)(v15 + 5640);
                  if ( v19 || (v23 = v3[865]) != 0 && (v19 = *(_DWORD ***)(v23 + 5640)) != nullptr )
                  {
                    lock = cfg80211_chandef_usable(v3[201], v19, 1);
                    if ( (lock & 1) != 0 )
                    {
                      v20 = *(_DWORD *)(v15 + 4720);
                      v21 = v3[201];
                      v27 = 0;
                      v26 = v20;
                      lock = cfg80211_reg_check_beaconing(v21, v19, &v26);
                      if ( (lock & 1) != 0 )
                      {
                        *(_DWORD *)(v9 + 44) = *(_DWORD *)(v9 + 44) & 0xFFFFFFF8 | **v19 & 7;
                        ieee80211_select_queue_80211(v15, v9, v8);
                        *(_WORD *)(v9 + 124) = ieee802_1d_to_ac[*(_DWORD *)(v9 + 144) & 7];
                        lock = ((__int64 (__fastcall *)(__int64, __int64))ieee80211_parse_tx_radiotap)(v9, a2);
                        if ( (lock & 1) != 0 )
                        {
                          skb_pull(v9, v6);
                          v22 = ieee80211_xmit(v15, 0, v9);
                          _rcu_read_unlock(v22);
LABEL_29:
                          _ReadStatusReg(SP_EL0);
                          return 0;
                        }
                      }
                    }
                  }
                  _rcu_read_unlock(lock);
                  a1 = v9;
                }
              }
            }
          }
        }
      }
      consume_skb(a1);
      goto LABEL_29;
    }
  }
  else
  {
    __break(0x800u);
  }
  __break(0x800u);
  v25 = MEMORY[0x171430C]();
  return ieee80211_lookup_ra_sta(v25);
}
