__int64 __fastcall osif_link_reconfig_notify_cb(__int64 a1)
{
  __int64 assoc_link_vdev; // x0
  __int64 *v3; // x8
  __int64 v4; // x19
  __int64 v5; // x8
  _QWORD *v6; // x22
  int v7; // w5
  int v8; // w21
  unsigned int bss_peer_mld_mac; // w0
  unsigned int v10; // w19
  __int64 result; // x0
  const char *v12; // x2
  __int64 v13; // x1
  __int64 v14; // x0
  __int64 v15; // x19
  __int16 v16; // [xsp+Ch] [xbp-14h] BYREF
  int v17; // [xsp+10h] [xbp-10h] BYREF
  __int16 v18; // [xsp+14h] [xbp-Ch]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v17 = 0;
  assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev();
  if ( !assoc_link_vdev )
  {
    v12 = "%s: Failed to get assoc vdev";
LABEL_12:
    v13 = 2;
LABEL_13:
    qdf_trace_msg(72, v13, v12, "osif_link_reconfig_notify_cb");
LABEL_14:
    result = 4;
    goto LABEL_15;
  }
  v3 = *(__int64 **)(assoc_link_vdev + 680);
  if ( !v3 )
  {
    v12 = "%s: Invalid vdev osif priv";
    goto LABEL_12;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v12 = "%s: wdev is null";
    goto LABEL_12;
  }
  v5 = *(_QWORD *)(assoc_link_vdev + 216);
  if ( !v5 )
  {
    v12 = "%s: null pdev";
    goto LABEL_18;
  }
  v6 = *(_QWORD **)(v5 + 24);
  if ( !v6 || !*v6 )
  {
    v12 = "%s: null wiphy";
LABEL_18:
    v13 = 8;
    goto LABEL_13;
  }
  v7 = *(unsigned __int8 *)(a1 + 93);
  v8 = 1 << v7;
  qdf_trace_msg(
    72,
    8,
    "%s: link reconfig on vdev %d with link id %d mask 0x%x",
    "osif_link_reconfig_notify_cb",
    *(unsigned __int8 *)(a1 + 168),
    v7,
    (unsigned __int16)(1 << v7));
  bss_peer_mld_mac = wlan_vdev_get_bss_peer_mld_mac(a1, &v17);
  if ( !bss_peer_mld_mac )
  {
    qdf_trace_msg(
      72,
      8,
      "%s: ap mld addr: %02x:%02x:%02x:**:**:%02x",
      "osif_link_reconfig_notify_cb",
      (unsigned __int8)v17,
      BYTE1(v17),
      BYTE2(v17),
      HIBYTE(v18));
    v14 = _cfg80211_alloc_event_skb(*v6, v4, 103, 197, 0, 63, 36, 3264);
    if ( !v14 )
    {
      qdf_trace_msg(72, 8, "%s: wlan_cfg80211_vendor_event_alloc failed", "osif_link_reconfig_notify_cb");
      result = 2;
      goto LABEL_15;
    }
    v15 = v14;
    if ( !(unsigned int)nla_put(v14, 1, 6, &v17) )
    {
      v16 = v8;
      if ( !(unsigned int)nla_put(v15, 2, 2, &v16) )
      {
        _cfg80211_send_event_skb(v15, 3264);
        result = 0;
        goto LABEL_15;
      }
    }
    qdf_trace_msg(72, 8, "%s: QCA_WLAN_VENDOR_ATTR put fail", "osif_link_reconfig_notify_cb");
    sk_skb_reason_drop(0, v15, 2);
    goto LABEL_14;
  }
  v10 = bss_peer_mld_mac;
  qdf_trace_msg(
    72,
    8,
    "%s: get peer mld failed, vdev %d",
    "osif_link_reconfig_notify_cb",
    *(unsigned __int8 *)(a1 + 168));
  result = v10;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
