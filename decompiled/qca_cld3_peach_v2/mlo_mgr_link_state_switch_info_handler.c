__int64 __fastcall mlo_mgr_link_state_switch_info_handler(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  const char *v13; // x19
  __int64 v14; // x24
  unsigned __int64 v15; // x25
  __int64 mlo_ctx; // x0
  __int64 v17; // x26
  __int64 v18; // x8
  __int64 v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  unsigned __int8 *v38; // x21
  unsigned int v39; // w27
  __int64 v40; // x4
  __int64 v41; // x8
  _DWORD *v42; // x8
  __int64 v43; // x1
  __int64 v44; // x0
  void (__fastcall *v45)(__int64, __int64); // x8
  __int64 v46; // x0
  __int64 v47; // x28
  const char *v48; // x22
  int v49; // w19
  int v50; // w21
  char is_hw_dbs_capable; // w0
  bool v52; // zf
  __int64 result; // x0
  unsigned __int8 *v54; // [xsp+0h] [xbp-40h]
  _BYTE *v55; // [xsp+8h] [xbp-38h]
  __int64 v56; // [xsp+10h] [xbp-30h]
  unsigned int sta_num_links; // [xsp+18h] [xbp-28h]
  _BOOL4 v58; // [xsp+1Ch] [xbp-24h]
  _QWORD v59[4]; // [xsp+20h] [xbp-20h] BYREF

  v59[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59[0] = 0;
  v55 = a2 + 4;
  wlan_mlo_get_mlpeer_by_peer_mladdr((__int64)(a2 + 4), v59);
  if ( v59[0] )
  {
    if ( *a2 )
    {
      v12 = 0;
      v54 = a2;
      v13 = "%s: vdev:%d is_link_active:%d num_links:%d";
      do
      {
        wlan_connectivity_mld_link_status_event(a1, &v55[24 * v12]);
        if ( v12 == 5 )
          __break(0x5512u);
        v14 = v59[0];
        v15 = *(unsigned int *)&v55[24 * v12 + 8];
        mlo_ctx = wlan_objmgr_get_mlo_ctx();
        v17 = mlo_ctx;
        v56 = v12;
        v58 = mlo_ctx && (v18 = *(_QWORD *)(mlo_ctx + 360)) != 0 && *(_QWORD *)(v18 + 48) != 0;
        v19 = 0;
        sta_num_links = (unsigned __int8)mlo_get_sta_num_links(v14);
        do
        {
          v37 = *(__int64 *)((char *)&qword_F28 + v14);
          if ( *(_DWORD *)(v37 + v19 + 24) | *(unsigned __int16 *)(v37 + v19 + 28)
            && *(_DWORD *)(v37 + v19) | *(unsigned __int16 *)(v37 + v19 + 4) )
          {
            v38 = (unsigned __int8 *)(v37 + v19);
            v39 = *(unsigned __int8 *)(v37 + v19 + 12);
            v40 = *(unsigned __int8 *)(v37 + v19 + 12);
            *(_BYTE *)(v37 + v19 + 40) = (v15 >> *(_BYTE *)(v37 + v19 + 6)) & 1;
            qdf_trace_msg(0x8Fu, 8u, v13, v20, v21, v22, v23, v24, v25, v26, v27, "mlo_mgr_update_link_state", v40);
            if ( sta_num_links >= 2 )
            {
              if ( v17 )
              {
                if ( (v38[40] & 1) == 0 )
                {
                  v41 = *(_QWORD *)(v17 + 352);
                  if ( v41 )
                  {
                    v42 = *(_DWORD **)(v41 + 112);
                    if ( v42 )
                    {
                      if ( *(v42 - 1) != -132374536 )
                        __break(0x8228u);
                      ((void (__fastcall *)(__int64, _QWORD))v42)(a1, v39);
                    }
                  }
                }
              }
            }
            if ( v58 )
            {
              v43 = v38[40];
              v44 = v38[12];
              v45 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v17 + 360) + 48LL);
              if ( *((_DWORD *)v45 - 1) != 2130452855 )
                __break(0x8228u);
              v45(v44, v43);
            }
            v46 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v39, 90);
            if ( v46 )
            {
              v47 = v46;
              if ( wlan_cm_is_vdev_connected(v46, v20, v21, v22, v23, v24, v25, v26, v27) )
              {
                v48 = v13;
                v49 = v38[6];
                v50 = v38[40];
                is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(a1);
                v52 = v49 == 255;
                v13 = v48;
                if ( !v52 && (is_hw_dbs_capable & 1) == 0 )
                {
                  if ( v50 )
                    policy_mgr_move_vdev_from_disabled_to_connection_tbl(a1, v39);
                  else
                    policy_mgr_move_vdev_from_connection_to_disabled_tbl(a1, v39);
                }
              }
              wlan_objmgr_vdev_release_ref(v47, 0x5Au, v28, v29, v30, v31, v32, v33, v34, v35, v36);
            }
          }
          v19 += 48;
        }
        while ( v19 != 144 );
        v12 = v56 + 1;
      }
      while ( v56 + 1 < (unsigned __int64)*v54 );
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo dev ctx for mld_mac: %02x:%02x:%02x:**:**:%02x not found",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_mgr_link_state_switch_info_handler",
      a2[4],
      a2[5],
      a2[6],
      a2[9]);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
