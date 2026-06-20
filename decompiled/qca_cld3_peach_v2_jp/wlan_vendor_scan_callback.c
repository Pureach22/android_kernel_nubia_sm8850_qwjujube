__int64 __fastcall wlan_vendor_scan_callback(__int64 a1, char a2)
{
  __int64 v4; // x0
  __int64 v5; // x22
  __int64 v6; // x23
  __int64 v7; // x20
  _WORD *v8; // x23
  __int64 v9; // x22
  __int64 v10; // x24
  __int64 v11; // x22
  __int64 v12; // x23
  _WORD *v13; // x23
  unsigned int v14; // w22
  __int64 v15; // x3
  __int64 result; // x0
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _cfg80211_alloc_event_skb(**(_QWORD **)(a1 + 64), *(_QWORD *)(a1 + 64), 103, 197, 0, 22, 4116, 2080);
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 216);
    v6 = *(unsigned int *)(v4 + 208);
    v7 = v4;
    if ( (nla_put(v4, 32771, 0, 0) & 0x80000000) == 0 )
    {
      v8 = (_WORD *)(v5 + v6);
      if ( v8 )
      {
        if ( *(int *)(a1 + 8) < 1 )
        {
LABEL_8:
          *v8 = *(_WORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v8;
          v11 = *(_QWORD *)(v7 + 216);
          v12 = *(unsigned int *)(v7 + 208);
          if ( (nla_put(v7, 32770, 0, 0) & 0x80000000) == 0 )
          {
            v13 = (_WORD *)(v11 + v12);
            if ( v13 )
            {
              if ( *(_DWORD *)(a1 + 12) )
              {
                v14 = 0;
                while ( 1 )
                {
                  LODWORD(v17[0]) = *(_DWORD *)(*(_QWORD *)(a1 + 160 + 8LL * (int)v14) + 4LL);
                  if ( (unsigned int)nla_put(v7, v14, 4, v17) )
                    break;
                  if ( ++v14 >= *(_DWORD *)(a1 + 12) )
                    goto LABEL_14;
                }
              }
              else
              {
LABEL_14:
                *v13 = *(_WORD *)(v7 + 216) + *(_DWORD *)(v7 + 208) - (_WORD)v13;
                v15 = *(_QWORD *)(a1 + 16);
                if ( !v15 || !(unsigned int)nla_put(v7, 1, *(unsigned int *)(a1 + 24), v15) )
                {
                  if ( !*(_DWORD *)(a1 + 36)
                    || (LODWORD(v17[0]) = *(_DWORD *)(a1 + 36), !(unsigned int)nla_put(v7, 6, 4, v17)) )
                  {
                    v17[0] = a1;
                    if ( !(unsigned int)nla_put_64bit(v7, 7, 8, v17, 229) )
                    {
                      LOBYTE(v17[0]) = a2 & 1;
                      if ( !(unsigned int)nla_put(v7, 8, 1, v17) )
                      {
                        LOBYTE(v17[0]) = -1;
                        if ( !(unsigned int)nla_put(v7, 15, 1, v17) )
                        {
                          _cfg80211_send_event_skb(v7, 2080);
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
          v9 = 0;
          v10 = 32;
          while ( !(unsigned int)nla_put(
                                   v7,
                                   (unsigned int)v9,
                                   *(unsigned __int8 *)(*(_QWORD *)a1 + v10),
                                   *(_QWORD *)a1 + v10 - 32) )
          {
            ++v9;
            v10 += 33;
            if ( v9 >= *(int *)(a1 + 8) )
              goto LABEL_8;
          }
        }
      }
    }
    sk_skb_reason_drop(0, v7, 2);
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
