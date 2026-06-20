__int64 __fastcall wlan_hdd_cfg80211_deregister_frames(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 24)) != 0 )
  {
    v11 = *(_QWORD *)(v9 + 16);
    qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_deregister_frames");
    if ( v11 )
    {
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_A3C94B, 2);
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_95CB17, 2);
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_9379B8, 2);
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_9CCE51, 2);
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_950D71, 6);
      sme_deregister_mgmt_frame(v11, 50, 208, &unk_982DAF, 5);
      return sme_deregister_mgmt_frame(v11, *(unsigned __int8 *)(*(_QWORD *)(a1 + 52832) + 8LL), 208, &unk_A24094, 2);
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_cfg80211_deregister_frames");
  }
  return qdf_trace_msg(
           0x33u,
           2u,
           "%s: mac_handle is NULL, failed to deregister frames",
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           "wlan_hdd_cfg80211_deregister_frames");
}
