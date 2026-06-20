__int64 __fastcall cm_rso_set_roam_trigger(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x20
  __int64 v5; // x0
  unsigned int v7; // w19
  __int16 roam_trigger_bitmap; // w22
  unsigned int v9; // w24
  char is_rso_enabled; // w0
  unsigned int v11; // w8
  unsigned int v12; // w8
  __int16 v13; // w22
  __int64 result; // x0
  unsigned int v15; // w21
  unsigned int v16; // w21
  __int64 v17; // x3
  __int64 v18; // [xsp+8h] [xbp-38h] BYREF
  int v19; // [xsp+10h] [xbp-30h]
  __int64 v20; // [xsp+18h] [xbp-28h] BYREF
  __int64 v21; // [xsp+20h] [xbp-20h] BYREF
  __int64 v22; // [xsp+28h] [xbp-18h] BYREF
  int v23; // [xsp+30h] [xbp-10h] BYREF
  __int64 v24; // [xsp+38h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 80);
  if ( v3 )
  {
    v5 = *(_QWORD *)(a1 + 80);
    v7 = a2;
    v23 = 0;
    v21 = 0;
    v22 = 0;
    v20 = 0;
    v18 = 0;
    v19 = 0;
    roam_trigger_bitmap = mlme_get_roam_trigger_bitmap(v5, a2);
    mlme_set_roam_trigger_bitmap(v3, *a3, a3[1]);
    v9 = a3[1];
    is_rso_enabled = wlan_is_rso_enabled(a1, v7);
    v11 = a3[1];
    if ( (is_rso_enabled & 1) != 0 && v11 )
    {
      cm_roam_triggers(v3, v7, a3);
      LODWORD(v20) = (unsigned __int8)v7;
      wlan_mlme_get_enable_idle_roam(v3, (_BYTE *)&v20 + 4);
      wlan_mlme_get_idle_roam_rssi_delta(v3, (int *)&v21 + 1);
      wlan_mlme_get_idle_roam_inactive_time(v3, (int *)&v22 + 1);
      wlan_mlme_get_idle_data_packet_count(v3, &v23);
      wlan_mlme_get_idle_roam_min_rssi(v3, (int *)&v22);
      wlan_mlme_get_idle_roam_band(v3, &v21);
      cm_roam_disconnect_params(v3, v7, &v18);
      v12 = a3[1];
      if ( (v12 & 0x4000) == 0 )
        BYTE4(v20) = 0;
      v13 = v9 ^ roam_trigger_bitmap;
      if ( (v12 & 0x2000) == 0 )
        BYTE4(v18) = 0;
      result = wlan_cm_tgt_send_roam_triggers(v3, v7, a3);
      if ( (v13 & 0x2000) != 0 )
      {
        v15 = result;
        wlan_cm_tgt_send_disconnect_roam_params(v3, v7, &v18);
        result = v15;
      }
      if ( (v13 & 0x4000) != 0 )
      {
        v16 = result;
        wlan_cm_tgt_send_idle_params(v3, v7, &v20);
        result = v16;
      }
    }
    else
    {
      if ( v9 )
        v17 = 46;
      else
        v17 = 47;
      result = cm_roam_state_change(a1, v7, 2 * (unsigned int)(v11 != 0), v17, 0, 0);
      if ( !(_DWORD)result )
        result = wlan_cm_tgt_send_roam_triggers(v3, v7, a3);
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
