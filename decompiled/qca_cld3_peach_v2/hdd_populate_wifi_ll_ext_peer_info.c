__int64 __fastcall hdd_populate_wifi_ll_ext_peer_info(int *a1, __int64 a2)
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
  __int64 v16; // x21
  _DWORD *v17; // x20
  _WORD *v18; // [xsp+8h] [xbp-18h]
  int v19; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *a1;
  if ( (unsigned int)nla_put(a2, 12, 4, &v19)
    || (v19 = a1[1], (unsigned int)nla_put(a2, 11, 4, &v19))
    || (v19 = a1[4], (unsigned int)nla_put(a2, 50, 4, &v19))
    || (v19 = a1[5], (unsigned int)nla_put(a2, 51, 4, &v19))
    || (v19 = a1[6], (unsigned int)nla_put(a2, 52, 4, &v19))
    || (v19 = a1[7], (unsigned int)nla_put(a2, 53, 4, &v19))
    || (unsigned int)nla_put(a2, 8, 6, a1 + 2)
    || (unsigned int)hdd_populate_wifi_signal_info(a1 + 8, a2) )
  {
    v12 = "%s: put peer signal attr failed";
  }
  else
  {
    v14 = *(_QWORD *)(a2 + 216);
    v15 = *(unsigned int *)(a2 + 208);
    if ( (nla_put(a2, 32774, 0, 0) & 0x80000000) != 0 || !(v14 + v15) )
    {
      v12 = "%s: nla_nest_start failed";
    }
    else
    {
      v18 = (_WORD *)(v14 + v15);
      v16 = 0;
      v17 = a1 + 44;
      while ( !(unsigned int)hdd_populate_wifi_wmm_ac_info(&v17[v16], a2) )
      {
        v16 += 6;
        if ( v16 == 24 )
        {
          result = 0;
          *v18 = *(_WORD *)(a2 + 216) + *(_WORD *)(a2 + 208) - (_WORD)v18;
          goto LABEL_11;
        }
      }
      v12 = "%s: put WMM AC attr failed";
    }
  }
  qdf_trace_msg(0x33u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "hdd_populate_wifi_ll_ext_peer_info");
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
