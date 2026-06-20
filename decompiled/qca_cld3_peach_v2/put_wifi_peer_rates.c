__int64 __fastcall put_wifi_peer_rates(__int64 a1, __int64 a2)
{
  __int64 v4; // x21
  __int64 v5; // x22
  int v6; // w8
  __int64 result; // x0
  _WORD *v8; // x22
  unsigned __int64 v9; // x23
  __int64 v10; // x21
  __int64 v11; // x24
  __int64 v12; // x25
  const char *v13; // x2
  int v14; // w8
  _WORD *v15; // x24
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !*(_DWORD *)(a1 + 16) )
    return 1;
  v4 = *(_QWORD *)(a2 + 216);
  v5 = *(unsigned int *)(a2 + 208);
  v6 = nla_put(a2, 32837, 0, 0);
  result = 0;
  if ( (v6 & 0x80000000) == 0 )
  {
    v8 = (_WORD *)(v4 + v5);
    if ( v8 )
    {
      if ( *(_DWORD *)(a1 + 16) )
      {
        v9 = 0;
        v10 = a1 + 20;
        while ( 1 )
        {
          v11 = *(_QWORD *)(a2 + 216);
          v12 = *(unsigned int *)(a2 + 208);
          v14 = nla_put(a2, (unsigned int)v9 | 0x8000, 0, 0);
          result = 0;
          if ( v14 < 0 )
            break;
          v15 = (_WORD *)(v11 + v12);
          if ( !v15 )
            break;
          if ( (put_wifi_rate_stat(v10, a2, v13) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: QCA_WLAN_VENDOR_ATTR put fail",
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              "put_wifi_peer_rates");
            return 0;
          }
          ++v9;
          v10 += 32;
          *v15 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v15;
          if ( v9 >= *(unsigned int *)(a1 + 16) )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        *v8 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v8;
        return 1;
      }
    }
  }
  return result;
}
