__int64 __fastcall wlan_cfg80211_coap_offload_cache_deliver(__int64 a1, __int64 *a2)
{
  __int64 v3; // x3
  __int64 i; // x8
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  __int64 v15; // x22
  __int64 v16; // x20
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _WORD *v25; // x23
  __int64 v26; // x22
  int v27; // w25
  const char *v28; // x21
  int v29; // w9
  unsigned int v30; // w9
  __int64 *v31; // x26
  __int64 v32; // x27
  __int64 v33; // x28
  _WORD *v34; // x27
  __int64 result; // x0
  const char *v36; // x2
  const char *v37; // x3
  unsigned int v38; // w0
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = 20;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  for ( i = *a2; (__int64 *)i != a2; i = *(_QWORD *)i )
  {
    v29 = *(_DWORD *)(i + 28);
    if ( v29 )
    {
      v30 = v3 + ((v29 + 7) & 0xFFFFFFFC) + 24;
      if ( *(_QWORD *)(i + 32) )
        v3 = v30;
      else
        v3 = (unsigned int)v3;
    }
  }
  v5 = _cfg80211_alloc_reply_skb(a1, 103, 197, v3);
  if ( !v5 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_cfg80211_coap_offload_cache_deliver");
    result = 4294967284LL;
    goto LABEL_27;
  }
  v14 = *(_QWORD *)(v5 + 216);
  v15 = *(unsigned int *)(v5 + 208);
  v16 = v5;
  if ( (nla_put(v5, 32773, 0, 0) & 0x80000000) != 0 || (v25 = (_WORD *)(v14 + v15)) == nullptr )
  {
    v36 = "%s: nla_nest_start failed";
    v37 = "wlan_cfg80211_coap_offload_cache_deliver";
    v38 = 51;
    goto LABEL_26;
  }
  v26 = *a2;
  if ( (__int64 *)*a2 == a2 )
  {
LABEL_23:
    *v25 = *(_WORD *)(v16 + 216) + *(_DWORD *)(v16 + 208) - (_WORD)v25;
    result = cfg80211_vendor_cmd_reply(v16);
    goto LABEL_27;
  }
  v27 = 0;
  v28 = "%s: nla_nest_start failed";
  while ( 1 )
  {
    v31 = *(__int64 **)v26;
    if ( !*(_DWORD *)(v26 + 28) || !*(_QWORD *)(v26 + 32) )
      goto LABEL_12;
    qdf_list_remove_node((__int64)a2, (_QWORD *)v26);
    v32 = *(_QWORD *)(v16 + 216);
    v33 = *(unsigned int *)(v16 + 208);
    if ( (nla_put(v16, v27 | 0x8000u, 0, 0) & 0x80000000) != 0 )
      goto LABEL_25;
    v34 = (_WORD *)(v32 + v33);
    if ( !v34 )
      goto LABEL_25;
    v39[0] = *(_QWORD *)(v26 + 16);
    if ( (unsigned int)nla_put_64bit(v16, 1, 8, v39, 229) )
      break;
    LODWORD(v39[0]) = *(_DWORD *)(v26 + 24);
    if ( (unsigned int)nla_put(v16, 2, 4, v39)
      || (unsigned int)nla_put(v16, 4, *(unsigned int *)(v26 + 28), *(_QWORD *)(v26 + 32)) )
    {
      break;
    }
    ++v27;
    *v34 = *(_WORD *)(v16 + 216) + *(_DWORD *)(v16 + 208) - (_WORD)v34;
    _qdf_mem_free(*(_QWORD *)(v26 + 32));
    _qdf_mem_free(v26);
LABEL_12:
    v26 = (__int64)v31;
    if ( v31 == a2 )
      goto LABEL_23;
  }
  v28 = "%s: nla_put failed";
LABEL_25:
  v37 = "wlan_cfg80211_coap_fill_buf_info";
  v38 = 156;
  v36 = v28;
LABEL_26:
  qdf_trace_msg(v38, 2u, v36, v17, v18, v19, v20, v21, v22, v23, v24, v37);
  sk_skb_reason_drop(0, v16, 2);
  result = 4294967274LL;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}
