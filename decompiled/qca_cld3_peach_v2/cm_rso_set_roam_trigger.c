__int64 __fastcall cm_rso_set_roam_trigger(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x20
  __int64 v5; // x0
  unsigned int v7; // w19
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  __int16 roam_trigger_bitmap; // w22
  unsigned int v18; // w24
  char is_rso_enabled; // w0
  unsigned int v20; // w8
  unsigned int v21; // w8
  __int16 v22; // w22
  unsigned int v23; // w21
  unsigned int v24; // w21
  __int64 v25; // x3
  __int64 v26; // [xsp+8h] [xbp-38h] BYREF
  int v27; // [xsp+10h] [xbp-30h]
  __int64 v28; // [xsp+18h] [xbp-28h] BYREF
  __int64 v29; // [xsp+20h] [xbp-20h] BYREF
  __int64 v30; // [xsp+28h] [xbp-18h] BYREF
  int v31; // [xsp+30h] [xbp-10h] BYREF
  __int64 v32; // [xsp+38h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 80);
  if ( v3 )
  {
    v5 = *(_QWORD *)(a1 + 80);
    v7 = a2;
    v31 = 0;
    v29 = 0;
    v30 = 0;
    v28 = 0;
    v26 = 0;
    v27 = 0;
    if ( (wlan_vdev_mlme_get_is_mlo_link(v5, a2) & 1) != 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: MLO ROAM: skip RSO cmd for link vdev %d",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "cm_rso_set_roam_trigger",
        (unsigned __int8)v7);
      result = 0;
    }
    else
    {
      roam_trigger_bitmap = mlme_get_roam_trigger_bitmap(v3, v7);
      mlme_set_roam_trigger_bitmap(v3, *a3, a3[1]);
      v18 = a3[1];
      is_rso_enabled = wlan_is_rso_enabled(a1, v7);
      v20 = a3[1];
      if ( (is_rso_enabled & 1) != 0 && v20 )
      {
        cm_roam_triggers(v3, v7, a3);
        LODWORD(v28) = (unsigned __int8)v7;
        wlan_mlme_get_enable_idle_roam(v3, (_BYTE *)&v28 + 4);
        wlan_mlme_get_idle_roam_rssi_delta(v3, (int *)&v29 + 1);
        wlan_mlme_get_idle_roam_inactive_time(v3, (int *)&v30 + 1);
        wlan_mlme_get_idle_data_packet_count(v3, &v31);
        wlan_mlme_get_idle_roam_min_rssi(v3, (int *)&v30);
        wlan_mlme_get_idle_roam_band(v3, &v29);
        cm_roam_disconnect_params(v3, v7, &v26);
        v21 = a3[1];
        if ( (v21 & 0x4000) == 0 )
          BYTE4(v28) = 0;
        v22 = v18 ^ roam_trigger_bitmap;
        if ( (v21 & 0x2000) == 0 )
          BYTE4(v26) = 0;
        result = wlan_cm_tgt_send_roam_triggers(v3, v7, a3);
        if ( (v22 & 0x2000) != 0 )
        {
          v23 = result;
          wlan_cm_tgt_send_disconnect_roam_params(v3, v7, &v26);
          result = v23;
        }
        if ( (v22 & 0x4000) != 0 )
        {
          v24 = result;
          wlan_cm_tgt_send_idle_params(v3, v7, &v28);
          result = v24;
        }
      }
      else
      {
        if ( v18 )
          v25 = 46;
        else
          v25 = 47;
        result = cm_roam_state_change(a1, v7, 2 * (unsigned int)(v20 != 0), v25, 0, 0);
        if ( !(_DWORD)result )
          result = wlan_cm_tgt_send_roam_triggers(v3, v7, a3);
      }
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
