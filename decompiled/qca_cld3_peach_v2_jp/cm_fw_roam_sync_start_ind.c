__int64 __fastcall cm_fw_roam_sync_start_ind(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  unsigned int v5; // w21
  __int64 v6; // x22
  __int64 cmpt_obj; // x0
  __int64 v8; // x24
  int v9; // w8
  int v10; // w9
  int roam_state; // w0
  unsigned int v12; // w22
  _QWORD v14[4]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  unsigned int v17; // [xsp+30h] [xbp-10h] BYREF
  unsigned __int16 v18; // [xsp+34h] [xbp-Ch]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v5 = *(unsigned __int8 *)(a1 + 104);
  v18 = 0;
  v17 = 0;
  v6 = *(_QWORD *)(v4 + 80);
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(v6);
  if ( cmpt_obj )
  {
    v8 = cmpt_obj;
    wlan_mlme_get_bssid_vdev_id(v4, v5, &v17);
    dlm_update_bssid_connect_params(v4, v17 | ((unsigned __int64)v18 << 32), 1u);
    if ( (~*(unsigned __int8 *)(a2 + 61) & 0xF) == 0 )
    {
      v9 = *(unsigned __int8 *)(v8 + 1937);
      v10 = *(char *)(a2 + 60);
      v15 = 0;
      v16 = 0;
      memset(v14, 0, sizeof(v14));
      if ( v9 > v10 )
      {
        qdf_mem_set(v14, 0x30u, 0);
        v15 = 0x200000002LL;
        LODWORD(v14[0]) = v17;
        WORD2(v14[0]) = v18;
        LODWORD(v16) = 1;
        dlm_add_bssid_to_reject_list(v4, (__int64)v14);
      }
    }
    cm_update_scan_mlme_on_roam(a1, &v17, 0);
    roam_state = mlme_get_roam_state(v6, v5);
    v12 = 0;
    if ( roam_state != 5 )
      v12 = wlan_cm_roam_state_change(v4, v5, 5, 0x34u);
    ((void (__fastcall *)(_QWORD, unsigned int *, __int64))mlme_init_twt_context)(*(_QWORD *)(v4 + 80), &v17, 255);
    mlme_cm_osif_roam_sync_ind();
  }
  else
  {
    v12 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
