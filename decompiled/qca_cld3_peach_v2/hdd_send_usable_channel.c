__int64 __fastcall hdd_send_usable_channel(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x23
  __int64 v23; // x24
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x22
  _WORD *v34; // x23
  unsigned __int8 v35; // w24
  unsigned __int8 v36; // w25
  unsigned int *v37; // x27
  __int64 v38; // x26
  __int64 v39; // x28
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  _WORD *v48; // x28
  unsigned int v49; // w8
  unsigned int v50; // w26
  __int64 result; // x0
  unsigned int v52; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !(40 * a3) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: No data requested", a4, a5, a6, a7, a8, a9, a10, a11, "hdd_send_usable_channel");
LABEL_23:
    result = 4294967274LL;
    goto LABEL_26;
  }
  v13 = _cfg80211_alloc_reply_skb(*(_QWORD *)(a1 + 24), 103, 197, (unsigned int)(56 * a3 + 16));
  if ( !v13 )
  {
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_send_usable_channel");
    result = 4294967284LL;
    goto LABEL_26;
  }
  v22 = *(_QWORD *)(v13 + 216);
  v23 = *(unsigned int *)(v13 + 208);
  v24 = v13;
  v33 = "%s: nla nest start failure";
  if ( (nla_put(v13, 32772, 0, 0) & 0x80000000) != 0 || (v34 = (_WORD *)(v22 + v23)) == nullptr )
  {
LABEL_20:
    qdf_trace_msg(0x33u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "hdd_fill_usable_channels_data");
LABEL_21:
    qdf_trace_msg(0x33u, 2u, "%s: nla put fail", v40, v41, v42, v43, v44, v45, v46, v47, "hdd_send_usable_channel");
    sk_skb_reason_drop(0, v24, 2);
    goto LABEL_23;
  }
  if ( a3 >= 1 )
  {
    v35 = 0;
    v36 = 0;
    v33 = "%s: nla put failure";
    do
    {
      v37 = (unsigned int *)(a2 + 24LL * v36);
      if ( *v37 )
      {
        v38 = *(_QWORD *)(v24 + 216);
        v39 = *(unsigned int *)(v24 + 208);
        if ( (nla_put(v24, v35 | 0x8000u, 0, 0) & 0x80000000) != 0 )
          goto LABEL_21;
        v48 = (_WORD *)(v38 + v39);
        if ( !v48 )
          goto LABEL_21;
        v49 = v37[3] - 1;
        if ( v49 > 6 )
          v50 = 1;
        else
          v50 = dword_AF74F0[v49];
        v52 = *v37;
        if ( (unsigned int)nla_put(v24, 1, 4, &v52) )
          goto LABEL_20;
        v52 = v37[1];
        if ( (unsigned int)nla_put(v24, 2, 4, &v52) )
          goto LABEL_20;
        v52 = v37[2];
        if ( (unsigned int)nla_put(v24, 3, 4, &v52) )
          goto LABEL_20;
        v52 = v50;
        if ( (unsigned int)nla_put(v24, 4, 4, &v52) )
          goto LABEL_20;
        v52 = v37[4];
        if ( (unsigned int)nla_put(v24, 5, 4, &v52) )
          goto LABEL_20;
        ++v35;
        *v48 = *(_WORD *)(v24 + 216) + *(_DWORD *)(v24 + 208) - (_WORD)v48;
      }
      ++v36;
    }
    while ( a3 > (unsigned int)v36 );
  }
  *v34 = *(_WORD *)(v24 + 216) + *(_DWORD *)(v24 + 208) - (_WORD)v34;
  result = cfg80211_vendor_cmd_reply(v24);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
