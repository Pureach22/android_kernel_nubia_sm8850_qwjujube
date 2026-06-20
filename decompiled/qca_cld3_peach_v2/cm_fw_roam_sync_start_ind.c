__int64 __fastcall cm_fw_roam_sync_start_ind(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  unsigned int v5; // w21
  __int64 v6; // x22
  __int64 cmpt_obj; // x0
  __int64 v8; // x24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w8
  int v18; // w9
  __int64 result; // x0
  unsigned int v20; // w21
  unsigned int v21; // [xsp+8h] [xbp-78h] BYREF
  unsigned __int16 v22; // [xsp+Ch] [xbp-74h]
  _QWORD v23[11]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v24; // [xsp+68h] [xbp-18h]
  __int64 v25; // [xsp+70h] [xbp-10h]
  __int64 v26; // [xsp+78h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 216);
  v5 = *(unsigned __int8 *)(a1 + 168);
  v22 = 0;
  v21 = 0;
  v6 = *(_QWORD *)(v4 + 80);
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(v6);
  if ( cmpt_obj )
  {
    if ( (*(_BYTE *)(a1 + 60) & 2) != 0 )
    {
      if ( (unsigned int)mlme_get_roam_state(v6, *(unsigned __int8 *)(a2 + 13)) != 5 )
        wlan_cm_roam_state_change(v4, *(unsigned __int8 *)(a2 + 13), 5u, 0x34u);
      result = wlan_cm_roam_state_change(v4, v5, 6u, 0x34u);
    }
    else
    {
      v8 = cmpt_obj;
      wlan_mlme_get_bssid_vdev_id(v4, v5, &v21);
      dlm_update_bssid_connect_params(v4, v21 | ((unsigned __int64)v22 << 32), 1u);
      if ( (~*(unsigned __int8 *)(a2 + 61) & 0xF) == 0 )
      {
        v17 = *(unsigned __int8 *)(v8 + 1949);
        v18 = *(char *)(a2 + 60);
        v24 = 0;
        v25 = 0;
        memset(v23, 0, sizeof(v23));
        if ( v17 > v18 )
        {
          qdf_mem_set(v23, 0x68u, 0);
          LODWORD(v23[0]) = v21;
          v24 = 0x200000002LL;
          WORD2(v23[0]) = v22;
          LODWORD(v25) = 1;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dlm_update_mlo_reject_ap_info)(v4, v5, v23);
          dlm_add_bssid_to_reject_list(v4, (__int64)v23);
        }
      }
      if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v9, v10, v11, v12, v13, v14, v15, v16) & 1) != 0
        && (mlo_get_single_link_ml_roaming(v6, v5) & 1) != 0 )
      {
        cm_update_scan_mlme_for_mlo_roam(a1);
      }
      else
      {
        cm_update_scan_mlme_on_roam(a1, &v21, 0);
      }
      if ( (unsigned int)mlme_get_roam_state(v6, v5) == 5 )
        v20 = 0;
      else
        v20 = wlan_cm_roam_state_change(v4, v5, 5u, 0x34u);
      ((void (__fastcall *)(_QWORD, unsigned int *, __int64))mlme_init_twt_context)(*(_QWORD *)(v4 + 80), &v21, 255);
      mlme_cm_osif_roam_sync_ind();
      result = v20;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
