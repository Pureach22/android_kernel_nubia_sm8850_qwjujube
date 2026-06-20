__int64 __fastcall wlan_osif_send_audio_transport_switch_req(
        __int64 a1,
        unsigned int a2,
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
  _QWORD *v11; // x8
  unsigned int v12; // w19
  _QWORD *v14; // x1
  _QWORD *v16; // x20
  __int64 v17; // x0
  __int64 v18; // x21
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
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _BYTE v38[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v39[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+8h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD **)(a1 + 680);
  v12 = *(unsigned __int8 *)(a1 + 168);
  if ( !v11 )
  {
    v29 = "%s: Vdev %d osif_priv is null";
LABEL_12:
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
               "wlan_osif_send_audio_transport_switch_req",
               v12);
    goto LABEL_13;
  }
  v14 = (_QWORD *)*v11;
  if ( !*v11 )
  {
    v29 = "%s: vdev %d wireless dev is null";
    goto LABEL_12;
  }
  if ( a2 >= 2 )
  {
    v16 = (_QWORD *)*v11;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid audio transport switch type",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "osif_convert_audio_transport_switch_req_type_to_qca_type");
    v14 = v16;
    a2 = 0xFFFF;
  }
  v17 = _cfg80211_alloc_event_skb(*v14, v14, 103, 197, 0, 64, 24, 3264);
  if ( !v17 )
  {
    v29 = "%s: vdev %d wlan_cfg80211_vendor_event_alloc failed";
    goto LABEL_12;
  }
  v18 = v17;
  v38[0] = a2;
  if ( (unsigned int)nla_put(v17, 1, 1, v38) )
  {
    v27 = "%s: Vdev %d VENDOR_ATTR_AUDIO_TRANSPORT_SWITCH_TYPE put fail";
  }
  else
  {
    if ( a3 != 5 || (v39[0] = 0, !(unsigned int)nla_put(v18, 3, 1, v39)) )
    {
      _cfg80211_send_event_skb(v18, 3264);
      result = qdf_trace_msg(
                 0x48u,
                 8u,
                 "Vdev %d Audio Transport switch request %d sent",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 v12,
                 a2);
      goto LABEL_13;
    }
    v27 = "%s: Vdev %d AUDIO_TRANSPORT_SWITCH_REASON put fail";
  }
  qdf_trace_msg(
    0x48u,
    2u,
    v27,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "wlan_osif_send_audio_transport_switch_req",
    v12);
  result = sk_skb_reason_drop(0, v18, 2);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
