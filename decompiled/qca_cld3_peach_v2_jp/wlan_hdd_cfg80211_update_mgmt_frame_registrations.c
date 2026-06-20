__int64 __fastcall wlan_hdd_cfg80211_update_mgmt_frame_registrations(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  const char *v16; // x2
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 32);
  v17[0] = 0;
  result = _osif_vdev_sync_op_start(v5, v17, "wlan_hdd_cfg80211_update_mgmt_frame_registrations");
  if ( !(_DWORD)result )
  {
    v15 = *(_QWORD *)(a2 + 32);
    if ( v15 == -2688 )
    {
      v16 = "%s: Invalid adapter";
    }
    else
    {
      if ( *(_QWORD *)(v15 + 2712) )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Mode: %d, set mgmt regis update value 0x%x",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "__wlan_hdd_cfg80211_update_mgmt_frame_registrations",
          *(unsigned int *)(v15 + 2728),
          *(unsigned int *)(a3 + 4));
LABEL_8:
        result = _osif_vdev_sync_op_stop(v17[0], "wlan_hdd_cfg80211_update_mgmt_frame_registrations");
        goto LABEL_9;
      }
      v16 = "%s: HDD context is null";
    }
    qdf_trace_msg(
      0x33u,
      2u,
      v16,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "__wlan_hdd_cfg80211_update_mgmt_frame_registrations");
    goto LABEL_8;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
