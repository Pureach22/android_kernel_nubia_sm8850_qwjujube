__int64 __fastcall osif_dp_send_tcp_param_update_event(__int64 a1, int *a2, unsigned __int8 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  int v15; // w25
  char v16; // w23
  unsigned int v17; // w22
  __int64 v18; // x6
  __int16 v19; // w9
  unsigned int v20; // w10
  unsigned int v21; // w9
  int v22; // w24
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  int v60; // w8
  int v61; // w8
  int v62; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_objmgr_get_pdev_by_id(a1, 0, 0x61u);
  if ( !result )
    goto LABEL_20;
  v14 = result;
  if ( a3 == 1 )
  {
    v19 = *((_WORD *)a2 + 2);
    v15 = 0;
    v16 = v19 & 1;
    if ( (v19 & 1) != 0 )
      v20 = 22;
    else
      v20 = 18;
    v21 = v19 & 2;
    v17 = v21 >> 1;
    if ( v21 )
      v18 = v20 + 4;
    else
      v18 = v20;
  }
  else
  {
    if ( a3 )
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid Direction [%d]",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "osif_dp_send_tcp_param_update_event",
        a3);
LABEL_19:
      result = wlan_objmgr_pdev_release_ref(v14, 0x61u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
      goto LABEL_20;
    }
    v15 = *((unsigned __int8 *)a2 + 4);
    v16 = 0;
    LOBYTE(v17) = 0;
    if ( *((_BYTE *)a2 + 4) )
      v18 = 22;
    else
      v18 = 18;
  }
  v22 = *a2;
  v23 = _cfg80211_alloc_event_skb(**(_QWORD **)(result + 24), 0, 103, 197, 0, 35, v18, 3264);
  if ( !v23 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: wlan_cfg80211_vendor_event_alloc failed",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "osif_dp_send_tcp_param_update_event");
    goto LABEL_19;
  }
  v32 = v23;
  LOBYTE(v62) = a3;
  if ( !(unsigned int)nla_put(v23, 1, 1, &v62) )
  {
    LOBYTE(v62) = 2 * (v22 != 1);
    if ( !(unsigned int)nla_put(v32, 2, 1, &v62) )
    {
      if ( !v15 || (v22 != 1 ? (v59 = 4048579) : (v59 = 506072), v62 = v59, !(unsigned int)nla_put(v32, 3, 4, &v62)) )
      {
        if ( (v16 & 1) == 0 || (v22 != 1 ? (v60 = 20) : (v60 = 0), v62 = v60, !(unsigned int)nla_put(v32, 5, 4, &v62)) )
        {
          if ( (v17 & 1) == 0 || (v22 != 1 ? (v61 = 1) : (v61 = 2), v62 = v61, !(unsigned int)nla_put(v32, 4, 4, &v62)) )
          {
            _cfg80211_send_event_skb(v32, 3264);
            goto LABEL_19;
          }
        }
      }
    }
  }
  wlan_objmgr_pdev_release_ref(v14, 0x61u, v33, v34, v35, v36, v37, v38, v39, v40, v41);
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: nla_put api failed",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "osif_dp_send_tcp_param_update_event");
  result = sk_skb_reason_drop(0, v32, 2);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
