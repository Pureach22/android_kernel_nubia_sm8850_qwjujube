__int64 __fastcall hdd_tx_latency_fill_link_stats(__int64 a1, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v6; // x22
  __int64 v7; // x23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _WORD *v16; // x25
  __int64 result; // x0
  __int64 v18; // x23
  __int64 v19; // x21
  __int64 v20; // x22
  _WORD *v21; // x27
  __int64 v22; // x21
  unsigned __int8 *v23; // x22
  __int64 v24; // x23
  __int64 v25; // x24
  _WORD *v26; // x23
  __int64 v27; // x23
  int v28; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+18h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 216);
  v7 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, a3 | 0x8000, 0, 0) & 0x80000000) == 0 )
  {
    v16 = (_WORD *)(v6 + v7);
    if ( v6 + v7 )
    {
      if ( !(unsigned int)nla_put(a1, 1, 6, a2 + 16) )
      {
        v18 = jiffies;
        if ( hdd_tx_latency_fill_link_stats___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: idx %d link mac %02x:%02x:%02x:**:**:%02x",
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            "hdd_tx_latency_fill_link_stats",
            a3,
            a2[16],
            a2[17],
            a2[18],
            a2[21]);
          hdd_tx_latency_fill_link_stats___last_ticks = v18;
        }
        v19 = *(_QWORD *)(a1 + 216);
        v20 = *(unsigned int *)(a1 + 208);
        if ( (nla_put(a1, 32770, 0, 0) & 0x80000000) == 0 )
        {
          v21 = (_WORD *)(v19 + v20);
          if ( v19 + v20 )
          {
            v22 = 0;
            v23 = a2 + 32;
            while ( 1 )
            {
              v24 = *(_QWORD *)(a1 + 216);
              v25 = *(unsigned int *)(a1 + 208);
              if ( (nla_put(a1, (unsigned int)v22 | 0x8000, 0, 0) & 0x80000000) != 0 )
                break;
              v26 = (_WORD *)(v24 + v25);
              if ( !v26 )
                break;
              LOBYTE(v28) = v22;
              if ( (unsigned int)nla_put(a1, 1, 1, &v28) )
                break;
              v28 = *((_DWORD *)v23 - 1);
              if ( (unsigned int)nla_put(a1, 2, 4, &v28) )
                break;
              v28 = *((_DWORD *)v23 - 2);
              if ( (unsigned int)nla_put(a1, 3, 4, &v28) || (unsigned int)nla_put(a1, 4, 16, v23) )
                break;
              *v26 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v26;
              v27 = jiffies;
              if ( hdd_tx_latency_fill_link_stats___last_ticks_398 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: \ttype %u granularity %u average %u",
                  v8,
                  v9,
                  v10,
                  v11,
                  v12,
                  v13,
                  v14,
                  v15,
                  "hdd_tx_latency_fill_link_stats",
                  (unsigned int)v22,
                  *((unsigned int *)v23 - 1),
                  *((unsigned int *)v23 - 2));
                hdd_tx_latency_fill_link_stats___last_ticks_398 = v27;
              }
              ++v22;
              v23 += 24;
              if ( v22 == 4 )
              {
                result = 0;
                *v21 = *(_DWORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v21;
                *v16 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v16;
                goto LABEL_5;
              }
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: failed for link %02x:%02x:%02x:**:**:%02x",
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    "hdd_tx_latency_fill_link_stats",
    a2[16],
    a2[17],
    a2[18],
    a2[21]);
  result = 4294967206LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
