__int64 __fastcall wlan_cm_enable_roaming_on_connected_sta(__int64 a1, unsigned int a2)
{
  __int64 v4; // x21
  __int64 result; // x0
  int mode_specific_conn_info; // w0
  int v7; // w22
  unsigned __int8 *v8; // x8
  unsigned int v9; // w22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v18; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v19; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v20[2]; // [xsp+10h] [xbp-20h] BYREF
  int v21; // [xsp+20h] [xbp-10h]
  __int64 v22; // [xsp+28h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 80);
  v21 = 0;
  v20[0] = 0;
  v20[1] = 0;
  v19 = 0;
  v18 = 0;
  if ( (unsigned __int8)((__int64 (__fastcall *)(__int64))policy_mgr_get_roam_enabled_sta_session_id)(v4) != 0xFF )
    goto LABEL_2;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(v4, (unsigned __int64)v20, (unsigned __int64)&v18, 0);
  if ( !mode_specific_conn_info )
    goto LABEL_2;
  v7 = mode_specific_conn_info;
  if ( (unsigned __int8)v18 == (unsigned __int8)a2
    || !(unsigned int)mlme_get_roam_trigger_bitmap(v4, (unsigned __int8)v18) )
  {
    if ( v7 == 1 )
      goto LABEL_2;
    if ( BYTE1(v18) == (unsigned __int8)a2 || !(unsigned int)mlme_get_roam_trigger_bitmap(v4, BYTE1(v18)) )
    {
      if ( v7 == 2 )
        goto LABEL_2;
      if ( BYTE2(v18) == (unsigned __int8)a2 || !(unsigned int)mlme_get_roam_trigger_bitmap(v4, BYTE2(v18)) )
      {
        if ( v7 == 3 )
          goto LABEL_2;
        if ( HIBYTE(v18) == (unsigned __int8)a2 || !(unsigned int)mlme_get_roam_trigger_bitmap(v4, HIBYTE(v18)) )
        {
          if ( v7 == 4 )
            goto LABEL_2;
          if ( v19 == (unsigned __int8)a2 || !(unsigned int)mlme_get_roam_trigger_bitmap(v4, v19) )
          {
            if ( v7 != 5 )
              __break(0x5512u);
            goto LABEL_2;
          }
          v8 = &v19;
        }
        else
        {
          v8 = (unsigned __int8 *)&v18 + 3;
        }
      }
      else
      {
        v8 = (unsigned __int8 *)&v18 + 2;
      }
    }
    else
    {
      v8 = (unsigned __int8 *)&v18 + 1;
    }
  }
  else
  {
    v8 = (unsigned __int8 *)&v18;
  }
  v9 = *v8;
  if ( v9 != 255 )
  {
    if ( (mlo_check_is_given_vdevs_on_same_mld(v4, *v8, a2) & 1) == 0 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: ROAM: Enabling roaming on vdev[%d]",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wlan_cm_enable_roaming_on_connected_sta",
        v9);
      result = cm_roam_state_change(a1, v9, 2u, 0x28u, 0, 0);
      goto LABEL_3;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: RSO_CFG: vdev:%d , vdev:%d are on same MLD skip RSO enable",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_cm_enable_roaming_on_connected_sta",
      v9,
      (unsigned __int8)a2);
  }
LABEL_2:
  result = 16;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
