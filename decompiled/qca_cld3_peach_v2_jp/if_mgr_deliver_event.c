__int64 __fastcall if_mgr_deliver_event(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x4
  const char *v13; // x5
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0

  v11 = *(_QWORD *)(a1 + 152);
  if ( !v11 )
    return 16;
  if ( !*(_QWORD *)(v11 + 80) )
    return 16;
  v12 = *(unsigned __int8 *)(a1 + 104);
  if ( a2 <= 0x19 )
  {
    v13 = "WLAN_IF_MGR_EV_AP_START_ACS";
    switch ( a2 )
    {
      case 0u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_CONNECT_START",
          0);
        result = ((__int64 (__fastcall *)(__int64, __int64))if_mgr_connect_start)(a1, a3);
        break;
      case 1u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_CONNECT_COMPLETE",
          1);
        result = if_mgr_connect_complete(a1, a3);
        break;
      case 2u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_DISCONNECT_START",
          2);
        result = if_mgr_disconnect_start(a1, a3);
        break;
      case 3u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_DISCONNECT_COMPLETE",
          3);
        result = if_mgr_disconnect_complete(a1, a3);
        break;
      case 4u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_VALIDATE_CANDIDATE",
          4);
        result = if_mgr_validate_candidate(a1, a3);
        break;
      case 5u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_START_BSS",
          5);
        result = if_mgr_ap_start_bss(a1, a3);
        break;
      case 6u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_START_BSS_COMPLETE",
          6);
        result = if_mgr_ap_start_bss_complete(a1, a3);
        break;
      case 7u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_STOP_BSS",
          7);
        result = if_mgr_ap_stop_bss(a1, a3);
        break;
      case 8u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_STOP_BSS_COMPLETE",
          8);
        result = if_mgr_ap_stop_bss_complete(a1, a3);
        break;
      case 9u:
        goto LABEL_5;
      case 0xAu:
        v13 = "WLAN_IF_MGR_EV_AP_STOP_ACS";
        goto LABEL_5;
      case 0xBu:
        v13 = "WLAN_IF_MGR_EV_AP_DONE_ACS";
        goto LABEL_5;
      case 0xCu:
        v13 = "WLAN_IF_MGR_EV_AP_CANCEL_ACS";
        goto LABEL_5;
      case 0xDu:
        v13 = "WLAN_IF_MGR_EV_AP_START_HT40";
        goto LABEL_5;
      case 0xEu:
        v13 = "WLAN_IF_MGR_EV_AP_STOP_HT40";
        goto LABEL_5;
      case 0xFu:
        v13 = "WLAN_IF_MGR_EV_AP_DONE_HT40";
        goto LABEL_5;
      case 0x10u:
        v13 = "WLAN_IF_MGR_EV_AP_CANCEL_HT40";
        goto LABEL_5;
      case 0x11u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_CSA_START",
          17);
        result = if_mgr_ap_csa_start(a1, a3);
        break;
      case 0x12u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_CSA_COMPLETE",
          18);
        result = if_mgr_ap_csa_complete(a1, a3);
        break;
      case 0x13u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_STA_CSA_COMPLETE",
          19);
        result = if_mgr_sta_csa_complete(a1, a3);
        break;
      case 0x14u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_CONNECT_ACTIVE",
          20);
        result = if_mgr_connect_active(a1, a3);
        break;
      case 0x15u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_NAN_PRE_ENABLE",
          21);
        result = if_mgr_nan_pre_enable(a1, a3);
        break;
      case 0x16u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_NAN_POST_ENABLE",
          22);
        result = if_mgr_nan_post_enable(a1, a3);
        break;
      case 0x17u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_NAN_POST_DISABLE",
          23);
        result = if_mgr_nan_post_disable(a1, a3);
        break;
      case 0x18u:
        qdf_trace_msg(
          0x78u,
          8u,
          "%s: vdev %d event: %s(%d)",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "if_mgr_deliver_event",
          v12,
          "WLAN_IF_MGR_EV_AP_CHANNEL_SELECTED",
          24);
        result = if_mgr_ap_channel_selected(a1, a3);
        break;
      default:
        v13 = "Unknown";
        goto LABEL_5;
    }
  }
  else
  {
    v13 = (const char *)&unk_8B9E43;
LABEL_5:
    qdf_trace_msg(
      0x78u,
      8u,
      "%s: vdev %d event: %s(%d)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "if_mgr_deliver_event",
      v12,
      v13,
      a2);
    qdf_trace_msg(0x78u, 2u, "%s: Invalid event", v14, v15, v16, v17, v18, v19, v20, v21, "if_mgr_deliver_mbss_event");
    return 4;
  }
  return result;
}
