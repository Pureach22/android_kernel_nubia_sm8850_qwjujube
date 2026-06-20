__int64 __fastcall hdd_cfg80211_update_channel_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x21
  __int64 v7; // x23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _WORD *v16; // x26
  int v17; // w23
  int v18; // w24
  unsigned int v19; // w28
  __int64 v20; // x21
  __int64 v21; // x25
  _WORD *v22; // x27
  unsigned __int16 *v23; // x21
  int v24; // w25
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  const char *v34; // x2
  int v35; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a2 + 216);
  v7 = *(unsigned int *)(a2 + 208);
  if ( (nla_put(a2, 32780, 0, 0) & 0x80000000) != 0 || (v16 = (_WORD *)(v6 + v7)) == nullptr )
  {
LABEL_28:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: nl channel update failed",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "hdd_cfg80211_update_channel_info");
    result = 4294967274LL;
  }
  else
  {
    if ( *(_DWORD *)(a3 + 1864) )
    {
      v17 = 0;
      v18 = 0;
      v19 = 0;
      while ( 1 )
      {
        v20 = *(_QWORD *)(a2 + 216);
        v21 = *(unsigned int *)(a2 + 208);
        if ( (nla_put(a2, v19 | 0x8000, 0, 0) & 0x80000000) != 0 )
          goto LABEL_28;
        v22 = (_WORD *)(v20 + v21);
        if ( !(v20 + v21) )
          goto LABEL_28;
        v23 = (unsigned __int16 *)(*(_QWORD *)(a3 + 1856) + 20LL * (int)v19);
        if ( !v23 )
          break;
        v24 = 1 << wlan_reg_freq_to_band(*v23);
        if ( *((_BYTE *)v23 + 16) )
          v18 = wlan_reg_chan_band_to_freq(
                  *(_QWORD *)(a1 + 8),
                  *((unsigned __int8 *)v23 + 16),
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32);
        if ( *((_BYTE *)v23 + 17) )
          v17 = wlan_reg_chan_band_to_freq(
                  *(_QWORD *)(a1 + 8),
                  *((unsigned __int8 *)v23 + 17),
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  v29,
                  v30,
                  v31,
                  v32);
        LOWORD(v35) = *v23;
        if ( (unsigned int)nla_put(a2, 3, 2, &v35) )
          goto LABEL_26;
        v35 = *((_DWORD *)v23 + 1);
        if ( (unsigned int)nla_put(a2, 1, 4, &v35) )
          goto LABEL_26;
        v35 = v23[4];
        if ( (unsigned int)nla_put(a2, 2, 4, &v35) )
          goto LABEL_26;
        LOBYTE(v35) = *((_BYTE *)v23 + 11);
        if ( (unsigned int)nla_put(a2, 4, 1, &v35) )
          goto LABEL_26;
        LOBYTE(v35) = *((_BYTE *)v23 + 12);
        if ( (unsigned int)nla_put(a2, 5, 1, &v35)
          || (LOBYTE(v35) = *((_BYTE *)v23 + 13), (unsigned int)nla_put(a2, 6, 1, &v35))
          || (LOBYTE(v35) = *((_BYTE *)v23 + 14), (unsigned int)nla_put(a2, 7, 1, &v35))
          || (LOBYTE(v35) = *((_BYTE *)v23 + 15), (unsigned int)nla_put(a2, 8, 1, &v35))
          || (LOBYTE(v35) = *((_BYTE *)v23 + 16), (unsigned int)nla_put(a2, 9, 1, &v35))
          || (LOBYTE(v35) = *((_BYTE *)v23 + 17), (unsigned int)nla_put(a2, 10, 1, &v35))
          || (v35 = v18, (unsigned int)nla_put(a2, 12, 4, &v35))
          || (v35 = v17, (unsigned int)nla_put(a2, 13, 4, &v35)) )
        {
LABEL_26:
          v34 = "%s: put fail";
LABEL_27:
          qdf_trace_msg(0x33u, 2u, v34, v8, v9, v10, v11, v12, v13, v14, v15, "hdd_cfg80211_update_channel_info");
          goto LABEL_28;
        }
        ++v19;
        *v22 = *(_DWORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v22;
        if ( v19 >= *(_DWORD *)(a3 + 1864) )
          goto LABEL_25;
      }
      v34 = "%s: channel info not found";
      goto LABEL_27;
    }
LABEL_25:
    result = 0;
    *v16 = *(_WORD *)(a2 + 216) + *(_DWORD *)(a2 + 208) - (_WORD)v16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
