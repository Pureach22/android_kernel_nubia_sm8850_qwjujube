__int64 __fastcall wlan_hdd_cfg80211_lphb_ind_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int v41; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: LPHB indication arrived",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_cfg80211_lphb_ind_handler");
  result = _wlan_hdd_validate_context(a1, "wlan_hdd_cfg80211_lphb_ind_handler");
  if ( (_DWORD)result )
    goto LABEL_14;
  if ( !a2 )
  {
    v32 = "%s: invalid argument lphbInd";
LABEL_8:
    result = qdf_trace_msg(0x33u, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_cfg80211_lphb_ind_handler");
    goto LABEL_14;
  }
  v21 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 45, 69, 0, 0xFFFFFFFFLL, 3, 2080);
  if ( !v21 )
  {
    v32 = "%s: LPHB timeout, NL buffer alloc fail";
    goto LABEL_8;
  }
  v22 = v21;
  v41 = 1;
  if ( (unsigned int)nla_put(v21, 1, 4, &v41) )
  {
    v31 = "%s: WLAN_HDD_TM_ATTR_CMD put fail";
  }
  else
  {
    v41 = *(unsigned __int8 *)(a2 + 1);
    if ( (unsigned int)nla_put(v22, 4, 4, &v41) )
    {
      v31 = "%s: WLAN_HDD_TM_ATTR_TYPE put fail";
    }
    else
    {
      if ( !(unsigned int)nla_put(v22, 2, 3, a2) )
      {
        result = _cfg80211_send_event_skb(v22, 2080);
        goto LABEL_14;
      }
      v31 = "%s: WLAN_HDD_TM_ATTR_DATA put fail";
    }
  }
  qdf_trace_msg(0x33u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "wlan_hdd_cfg80211_lphb_ind_handler");
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: NLA Put fail",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "wlan_hdd_cfg80211_lphb_ind_handler");
  result = sk_skb_reason_drop(0, v22, 2);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
