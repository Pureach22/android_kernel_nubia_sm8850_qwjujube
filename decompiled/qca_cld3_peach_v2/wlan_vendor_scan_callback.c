__int64 __fastcall wlan_vendor_scan_callback(__int64 a1, char a2, char a3)
{
  __int64 v6; // x0
  __int64 v7; // x23
  __int64 v8; // x24
  __int64 v9; // x20
  _WORD *v10; // x24
  __int64 v11; // x23
  __int64 v12; // x25
  __int64 v13; // x23
  __int64 v14; // x24
  _WORD *v15; // x24
  unsigned int v16; // w23
  __int64 v17; // x3
  __int64 result; // x0
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _cfg80211_alloc_event_skb(**(_QWORD **)(a1 + 64), *(_QWORD *)(a1 + 64), 103, 197, 0, 22, 4116, 2080);
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 216);
    v8 = *(unsigned int *)(v6 + 208);
    v9 = v6;
    if ( (nla_put(v6, 32771, 0, 0) & 0x80000000) == 0 )
    {
      v10 = (_WORD *)(v7 + v8);
      if ( v10 )
      {
        if ( *(int *)(a1 + 8) < 1 )
        {
LABEL_8:
          *v10 = *(_WORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v10;
          v13 = *(_QWORD *)(v9 + 216);
          v14 = *(unsigned int *)(v9 + 208);
          if ( (nla_put(v9, 32770, 0, 0) & 0x80000000) == 0 )
          {
            v15 = (_WORD *)(v13 + v14);
            if ( v15 )
            {
              if ( *(_DWORD *)(a1 + 12) )
              {
                v16 = 0;
                while ( 1 )
                {
                  LODWORD(v19[0]) = *(_DWORD *)(*(_QWORD *)(a1 + 160 + 8LL * (int)v16) + 4LL);
                  if ( (unsigned int)nla_put(v9, v16, 4, v19) )
                    break;
                  if ( ++v16 >= *(_DWORD *)(a1 + 12) )
                    goto LABEL_14;
                }
              }
              else
              {
LABEL_14:
                *v15 = *(_WORD *)(v9 + 216) + *(_DWORD *)(v9 + 208) - (_WORD)v15;
                v17 = *(_QWORD *)(a1 + 16);
                if ( !v17 || !(unsigned int)nla_put(v9, 1, *(unsigned int *)(a1 + 24), v17) )
                {
                  if ( !*(_DWORD *)(a1 + 36)
                    || (LODWORD(v19[0]) = *(_DWORD *)(a1 + 36), !(unsigned int)nla_put(v9, 6, 4, v19)) )
                  {
                    v19[0] = a1;
                    if ( !(unsigned int)nla_put_64bit(v9, 7, 8, v19, 229) )
                    {
                      LOBYTE(v19[0]) = a2 & 1;
                      if ( !(unsigned int)nla_put(v9, 8, 1, v19) )
                      {
                        LOBYTE(v19[0]) = a3;
                        if ( !(unsigned int)nla_put(v9, 15, 1, v19) )
                        {
                          _cfg80211_send_event_skb(v9, 2080);
                          goto LABEL_23;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        else
        {
          v11 = 0;
          v12 = 32;
          while ( !(unsigned int)nla_put(
                                   v9,
                                   (unsigned int)v11,
                                   *(unsigned __int8 *)(*(_QWORD *)a1 + v12),
                                   *(_QWORD *)a1 + v12 - 32) )
          {
            ++v11;
            v12 += 33;
            if ( v11 >= *(int *)(a1 + 8) )
              goto LABEL_8;
          }
        }
      }
    }
    sk_skb_reason_drop(0, v9, 2);
  }
  else
  {
    qdf_trace_msg(72, 2, "%s: skb alloc failed", "wlan_vendor_scan_callback");
  }
LABEL_23:
  result = _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
