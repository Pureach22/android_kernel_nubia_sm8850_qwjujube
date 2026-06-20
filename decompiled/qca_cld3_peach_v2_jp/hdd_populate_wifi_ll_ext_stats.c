__int64 __fastcall hdd_populate_wifi_ll_ext_stats(int *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // x21
  __int64 v15; // x22
  _WORD *v16; // x21
  __int64 v17; // x22
  unsigned __int64 v18; // x23
  __int64 v19; // x24
  __int64 v20; // x25
  _WORD *v21; // x24
  __int64 v22; // x21
  __int64 v23; // x22
  _WORD *v24; // x21
  __int64 v25; // x22
  unsigned __int64 v26; // x23
  __int64 v27; // x24
  __int64 v28; // x25
  _WORD *v29; // x24
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = *a1;
  if ( (unsigned int)nla_put(a2, 10, 4, &v30)
    || (v30 = a1[1], (unsigned int)nla_put(a2, 15, 4, &v30))
    || (v30 = a1[2], (unsigned int)nla_put(a2, 16, 4, &v30))
    || (v30 = a1[3], (unsigned int)nla_put(a2, 13, 4, &v30))
    || (v30 = a1[4], (unsigned int)nla_put(a2, 14, 4, &v30))
    || (v30 = *((unsigned __int8 *)a1 + 21), (unsigned int)nla_put(a2, 18, 4, &v30))
    || (v30 = *((unsigned __int8 *)a1 + 20), (unsigned int)nla_put(a2, 17, 4, &v30)) )
  {
LABEL_8:
    v12 = "%s: QCA_WLAN_VENDOR_ATTR put fail";
  }
  else
  {
    v14 = *(_QWORD *)(a2 + 216);
    v15 = *(unsigned int *)(a2 + 208);
    if ( (nla_put(a2, 32787, 0, 0) & 0x80000000) == 0 )
    {
      v16 = (_WORD *)(v14 + v15);
      if ( v16 )
      {
        if ( *((_BYTE *)a1 + 21) )
        {
          v17 = 0;
          v18 = 0;
          while ( 1 )
          {
            v19 = *(_QWORD *)(a2 + 216);
            v20 = *(unsigned int *)(a2 + 208);
            if ( (nla_put(a2, (unsigned int)v18 | 0x8000, 0, 0) & 0x80000000) != 0 )
              break;
            v21 = (_WORD *)(v19 + v20);
            if ( !v21 )
              break;
            if ( (unsigned int)hdd_populate_wifi_channel_cca_info(*((_QWORD *)a1 + 7) + v17, a2) )
              goto LABEL_8;
            ++v18;
            v17 += 36;
            *v21 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v21;
            if ( v18 >= *((unsigned __int8 *)a1 + 21) )
              goto LABEL_19;
          }
        }
        else
        {
LABEL_19:
          *v16 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v16;
          v22 = *(_QWORD *)(a2 + 216);
          v23 = *(unsigned int *)(a2 + 208);
          if ( (nla_put(a2, 32788, 0, 0) & 0x80000000) == 0 )
          {
            v24 = (_WORD *)(v22 + v23);
            if ( v24 )
            {
              if ( !*((_BYTE *)a1 + 20) )
              {
LABEL_27:
                result = 0;
                *v24 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v24;
                goto LABEL_10;
              }
              v25 = 0;
              v26 = 0;
              while ( 1 )
              {
                v27 = *(_QWORD *)(a2 + 216);
                v28 = *(unsigned int *)(a2 + 208);
                if ( (nla_put(a2, (unsigned int)v26 | 0x8000, 0, 0) & 0x80000000) != 0 )
                  break;
                v29 = (_WORD *)(v27 + v28);
                if ( !v29 )
                  break;
                if ( (unsigned int)hdd_populate_wifi_ll_ext_peer_info(*((_QWORD *)a1 + 6) + v25, a2) )
                  goto LABEL_8;
                ++v26;
                v25 += 272;
                *v29 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v29;
                if ( v26 >= *((unsigned __int8 *)a1 + 20) )
                  goto LABEL_27;
              }
            }
          }
        }
      }
    }
    v12 = "%s: nla_nest_start failed";
  }
  qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_populate_wifi_ll_ext_stats");
  result = 4294967274LL;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
