__int64 __fastcall wlan_osif_send_high_ap_availability_resp(
        __int64 a1,
        int a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *v11; // x8
  unsigned int v12; // w19
  _QWORD *v14; // x1
  char v16; // w23
  __int64 v17; // x0
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  __int64 result; // x0
  const char *v29; // x2
  __int64 v30; // x4
  _QWORD *v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  _BYTE v40[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v41[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD **)(a1 + 680);
  v12 = *(unsigned __int8 *)(a1 + 168);
  if ( !v11 )
  {
    v29 = "%s: Vdev %d osif_priv is null";
LABEL_18:
    result = qdf_trace_msg(
               0x48u,
               2u,
               v29,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "wlan_osif_send_high_ap_availability_resp",
               v12);
    goto LABEL_19;
  }
  v14 = (_QWORD *)*v11;
  if ( !*v11 )
  {
    v29 = "%s: vdev %d wireless dev is null";
    goto LABEL_18;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 4 || a2 == 3 || a2 == 2 )
      goto LABEL_7;
LABEL_16:
    v30 = (unsigned int)a2;
    v31 = (_QWORD *)*v11;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid operation value %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "osif_convert_high_ap_availability_oper_to_qca",
      v30);
    v14 = v31;
    v16 = 0;
    a2 = 0xFFFF;
    goto LABEL_8;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
LABEL_7:
      v16 = 0;
      goto LABEL_8;
    }
    goto LABEL_16;
  }
  v16 = 1;
LABEL_8:
  v17 = _cfg80211_alloc_event_skb(*v14, v14, 103, 197, 0, 66, 24, 3264);
  if ( !v17 )
  {
    v29 = "%s: vdev %d wlan_cfg80211_vendor_event_alloc failed";
    goto LABEL_18;
  }
  v18 = v17;
  v40[0] = a3;
  if ( (unsigned int)nla_put(v17, 2, 1, v40) )
  {
    v27 = "%s: Vdev %d VENDOR_ATTR_HIGH_AP_AVAILABILITY_COOKIE put fail";
  }
  else
  {
    if ( (v16 & 1) != 0 || (v41[0] = a2, !(unsigned int)nla_put(v18, 1, 1, v41)) )
    {
      _cfg80211_send_event_skb(v18, 3264);
      result = qdf_trace_msg(
                 0x48u,
                 8u,
                 "Vdev %d high AP availability operation resp with cookie %d and operation %d sent",
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v12,
                 a3,
                 (unsigned int)a2);
      goto LABEL_19;
    }
    v27 = "%s: Vdev %d VENDOR_ATTR_HIGH_AP_AVAILABILITY_OPERATION put fail";
  }
  qdf_trace_msg(0x48u, 2u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "wlan_osif_send_high_ap_availability_resp", v12);
  result = sk_skb_reason_drop(0, v18, 2);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
