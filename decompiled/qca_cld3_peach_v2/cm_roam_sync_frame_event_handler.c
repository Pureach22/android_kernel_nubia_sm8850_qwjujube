__int64 __fastcall cm_roam_sync_frame_event_handler(__int64 a1, __int64 a2)
{
  unsigned int v2; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x19
  __int64 rso_config_fl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x23
  unsigned int v26; // w20
  __int64 v27; // x0
  int v28; // w8
  __int64 v29; // x0
  int v30; // w8
  __int64 v31; // x0
  int v32; // w8
  __int64 v33; // x0
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(unsigned __int8 *)(a2 + 64);
    v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
           a1,
           *(unsigned __int8 *)(a2 + 64),
           1);
    if ( v5 )
    {
      v14 = v5;
      rso_config_fl = wlan_cm_get_rso_config_fl(
                        v5,
                        (__int64)"cm_roam_sync_frame_event_handler",
                        0x19Au,
                        v6,
                        v7,
                        v8,
                        v9,
                        v10,
                        v11,
                        v12,
                        v13);
      if ( !rso_config_fl )
      {
        v26 = 16;
        goto LABEL_31;
      }
      v25 = rso_config_fl;
      if ( (unsigned int)mlme_get_roam_state(a1, v2) == 5 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Ignoring this event as it is unexpected",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "cm_roam_sync_frame_event_handler",
          0,
          0,
          0,
          v35);
        wlan_cm_free_roam_synch_frame_ind(v25);
        v26 = 16;
LABEL_31:
        wlan_objmgr_vdev_release_ref(v14, 1u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
        goto LABEL_32;
      }
      if ( *(_DWORD *)a2 )
      {
        *(_DWORD *)(v25 + 872) = *(_DWORD *)a2;
        v27 = *(_QWORD *)(v25 + 880);
        *(_BYTE *)(v25 + 888) = *(_BYTE *)(a2 + 16);
        if ( v27 )
          _qdf_mem_free(v27);
        *(_QWORD *)(v25 + 880) = *(_QWORD *)(a2 + 8);
      }
      v28 = *(_DWORD *)(a2 + 20);
      if ( v28 )
      {
        *(_DWORD *)(v25 + 892) = v28;
        v29 = *(_QWORD *)(v25 + 896);
        *(_BYTE *)(v25 + 904) = *(_BYTE *)(a2 + 32);
        if ( v29 )
          _qdf_mem_free(v29);
        *(_QWORD *)(v25 + 896) = *(_QWORD *)(a2 + 24);
      }
      v30 = *(_DWORD *)(a2 + 36);
      if ( v30 )
      {
        v31 = *(_QWORD *)(v25 + 912);
        *(_DWORD *)(v25 + 908) = v30;
        if ( v31 )
          _qdf_mem_free(v31);
        *(_QWORD *)(v25 + 912) = *(_QWORD *)(a2 + 40);
      }
      v32 = *(_DWORD *)(a2 + 48);
      if ( v32 )
      {
        v33 = *(_QWORD *)(v25 + 928);
        *(_DWORD *)(v25 + 920) = v32;
        if ( v33 )
          _qdf_mem_free(v33);
        *(_QWORD *)(v25 + 928) = *(_QWORD *)(a2 + 56);
      }
      if ( *(_DWORD *)a2 )
      {
        wlan_cm_add_all_link_probe_rsp_to_scan_db();
        v16 = (unsigned int *)*(unsigned int *)(a2 + 20);
        if ( !(_DWORD)v16 )
          goto LABEL_30;
      }
      else
      {
        v16 = (unsigned int *)*(unsigned int *)(a2 + 20);
        if ( !(_DWORD)v16 )
        {
LABEL_30:
          v26 = 0;
          goto LABEL_31;
        }
      }
      wlan_cm_add_all_link_probe_rsp_to_scan_db();
      goto LABEL_30;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev object is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_roam_sync_frame_event_handler",
      0,
      0,
      0,
      v35);
    v26 = 16;
  }
  else
  {
    v26 = 29;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v26;
}
