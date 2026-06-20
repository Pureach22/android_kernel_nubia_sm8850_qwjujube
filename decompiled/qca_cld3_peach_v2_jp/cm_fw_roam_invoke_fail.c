__int64 __fastcall cm_fw_roam_invoke_fail(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 cm_ctx_fl; // x0
  unsigned int *v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x21
  unsigned int *first_roam_command; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 v42; // x0
  unsigned int v43; // w23
  unsigned int v44; // w22
  __int64 psoc_ext_obj_fl; // x0
  __int64 v46; // x24
  __int64 rso_config_fl; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w24
  __int64 v57; // x21
  int v59; // w8
  unsigned int v61; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v62; // [xsp+18h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v61 = -1;
  v2 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v2 )
  {
    v11 = v2;
    cm_ctx_fl = cm_get_cm_ctx_fl(v2, (__int64)"cm_fw_roam_invoke_fail", 0x69Fu, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( cm_ctx_fl )
    {
      v22 = (__int64 *)cm_ctx_fl;
      first_roam_command = (unsigned int *)cm_get_first_roam_command(v11, v14, v15, v16, v17, v18, v19, v20, v21);
      if ( first_roam_command )
        v61 = *first_roam_command;
      v32 = cm_sm_deliver_event(v11, 0x13u, 4u, (__int64)&v61, v24, v25, v26, v27, v28, v29, v30, v31);
      if ( v32 )
        cm_remove_cmd(v22, &v61, v33, v34, v35, v36, v37, v38, v39, v40);
      v41 = *(_QWORD *)(v11 + 152);
      if ( v41 && (v42 = *(_QWORD *)(v41 + 80)) != 0 )
      {
        v43 = *(unsigned __int8 *)(v11 + 104);
        v44 = v61;
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v42);
        if ( psoc_ext_obj_fl )
        {
          v46 = psoc_ext_obj_fl;
          rso_config_fl = wlan_cm_get_rso_config_fl(
                            v11,
                            (__int64)"cm_disconnect_roam_invoke_fail",
                            0x665u,
                            v14,
                            v15,
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21);
          if ( rso_config_fl )
          {
            v56 = *(unsigned __int8 *)(v46 + 2560);
            v57 = rso_config_fl;
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: vdev %d cm_id 0x%x: disconnect on NUD %d, source %d forced roaming %d",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "cm_disconnect_roam_invoke_fail",
              v43,
              v44,
              v56,
              *(unsigned int *)(rso_config_fl + 948),
              *(unsigned __int8 *)(rso_config_fl + 958));
            if ( *(_DWORD *)(v57 + 952) == -1 && *(__int16 *)(v57 + 956) == -1 )
            {
              v13 = (unsigned int *)(v57 + 952);
              *(_WORD *)(v57 + 956) = 0;
              *(_DWORD *)(v57 + 952) = 0;
            }
            else
            {
              v13 = (unsigned int *)*(unsigned int *)(v57 + 948);
              if ( (_DWORD)v13 == 1
                || (_DWORD)v13 == 4
                || (_DWORD)v13 == 2
                && ((v56 & 1) != 0 || (v13 = (unsigned int *)*(unsigned __int8 *)(v57 + 958), (_DWORD)v13 == 1)) )
              {
                v59 = *(unsigned __int8 *)(v57 + 958);
                *(_DWORD *)(v57 + 948) = 21;
                if ( v59 == 1 )
                  *(_BYTE *)(v57 + 958) = 0;
                wlan_cm_disconnect(v11, 10, 65534, nullptr);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: vdev %d cm_id 0x%x: rso cfg not found",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "cm_disconnect_roam_invoke_fail",
              v43,
              v44);
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: psoc not found",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "cm_disconnect_roam_invoke_fail",
          *(unsigned __int8 *)(v11 + 104),
          v61);
      }
    }
    else
    {
      v32 = 29;
    }
    wlan_objmgr_vdev_release_ref(v11, 1u, v13, v14, v15, v16, v17, v18, v19, v20, v21);
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v3, v4, v5, v6, v7, v8, v9, v10, "cm_fw_roam_invoke_fail");
    v32 = 29;
  }
  _ReadStatusReg(SP_EL0);
  return v32;
}
