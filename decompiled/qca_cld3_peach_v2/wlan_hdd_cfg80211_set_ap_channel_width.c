__int64 __fastcall wlan_hdd_cfg80211_set_ap_channel_width(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  int v16; // w0
  unsigned int v17; // w19
  __int64 v18; // x19
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w21
  _QWORD v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  result = _osif_vdev_sync_op_start(a2, v28, "wlan_hdd_cfg80211_set_ap_channel_width");
  if ( !(_DWORD)result )
  {
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      v15 = "%s: Command not allowed in FTM mode";
    }
    else
    {
      if ( (*(_DWORD *)(a2 + 2728) | 2) != 3 )
      {
        v16 = -95;
        goto LABEL_5;
      }
      v18 = *(_QWORD *)(a2 + 55520);
      if ( v18 )
      {
        v16 = _wlan_hdd_validate_context(*(_QWORD *)(a2 + 2712), "__wlan_hdd_cfg80211_set_ap_channel_width");
        if ( v16 )
          goto LABEL_5;
        v27 = a4[2];
        if ( v27 > 2 )
        {
          v27 = 3;
        }
        else if ( v27 == 2 )
        {
          if ( a4[3] <= *(_DWORD *)(*(_QWORD *)a4 + 4LL) )
            v27 = 2;
          else
            v27 = 3;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Channel width changed to %d ",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__wlan_hdd_cfg80211_set_ap_channel_width",
          v27);
        v16 = hdd_set_sap_ht2040_mode(v18, v27);
        if ( !v16 )
          goto LABEL_5;
        v15 = "%s: Cannot set SAP HT20/40 mode!";
      }
      else
      {
        v15 = "%s: invalid link_info";
      }
    }
    qdf_trace_msg(0x33u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, "__wlan_hdd_cfg80211_set_ap_channel_width");
    v16 = -22;
LABEL_5:
    v17 = v16;
    _osif_vdev_sync_op_stop(v28[0], "wlan_hdd_cfg80211_set_ap_channel_width");
    result = v17;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
