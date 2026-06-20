__int64 __fastcall wlan_p2p_lo_event_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  _QWORD *v21; // x8
  __int64 v22; // x19
  _QWORD *v23; // x8
  __int64 v24; // x0
  __int64 v25; // x21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int *v34; // x8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  __int64 result; // x0
  const char *v45; // x2
  unsigned int v46; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+8h] [xbp-8h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: user data:%pK, vdev id:%d, reason code:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_p2p_lo_event_callback",
    a1,
    *a2,
    a2[1]);
  if ( a1 )
  {
    v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 15);
    if ( v20 )
    {
      v21 = *(_QWORD **)(v20 + 680);
      v22 = v20;
      if ( v21 )
      {
        v23 = (_QWORD *)*v21;
        if ( v23 )
        {
          v24 = _cfg80211_alloc_event_skb(*v23, 0, 103, 197, 0, 27, 20, 3264);
          if ( v24 )
          {
            v25 = v24;
            v46 = a2[1];
            if ( (unsigned int)nla_put(v24, 8, 4, &v46) )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: nla put failed",
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                "wlan_p2p_lo_event_callback");
              sk_skb_reason_drop(0, v25, 2);
            }
            else
            {
              _cfg80211_send_event_skb(v25, 3264);
            }
            goto LABEL_15;
          }
          v45 = "%s: wlan_cfg80211_vendor_event_alloc failed";
        }
        else
        {
          v45 = "%s: wireless dev is null";
        }
      }
      else
      {
        v45 = "%s: osif_priv is null";
      }
      qdf_trace_msg(0x48u, 2u, v45, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_lo_event_callback");
LABEL_15:
      result = wlan_objmgr_vdev_release_ref(v22, 0xFu, v34, v35, v36, v37, v38, v39, v40, v41, v42);
      goto LABEL_16;
    }
    v43 = "%s: vdev is null";
  }
  else
  {
    v43 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v43, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_lo_event_callback");
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
