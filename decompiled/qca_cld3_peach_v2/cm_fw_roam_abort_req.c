__int64 __fastcall cm_fw_roam_abort_req(__int64 a1, __int64 a2)
{
  unsigned int v2; // w21
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  __int64 v14; // x19
  __int64 cm_ctx_fl; // x0
  unsigned int *v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x20
  unsigned int *first_roam_command; // x0
  unsigned int v27; // w24
  unsigned int v28; // w21
  unsigned int v29; // w2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v48; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v4 )
  {
    v13 = *(_QWORD *)(v4 + 216);
    v14 = v4;
    if ( v13 )
    {
      cm_ctx_fl = cm_get_cm_ctx_fl(v4, (__int64)"cm_fw_roam_abort_req", 0x14Eu, v5, v6, v7, v8, v9, v10, v11, v12);
      if ( cm_ctx_fl )
      {
        v25 = (__int64 *)cm_ctx_fl;
        first_roam_command = (unsigned int *)cm_get_first_roam_command(v14, v17, v18, v19, v20, v21, v22, v23, v24);
        if ( first_roam_command )
          v27 = *first_roam_command;
        else
          v27 = -1;
        if ( (unsigned int)mlme_get_roam_state(a1, v2) == 4 || (unsigned int)mlme_get_roam_state(a1, v2) == 5 )
        {
          v29 = 2;
        }
        else
        {
          if ( (unsigned int)mlme_get_roam_state(a1, v2) != 6 )
          {
            v28 = 16;
LABEL_14:
            v38 = *v25;
            v48 = v27;
            cm_get_first_roam_command(v38, v30, v31, v32, v33, v34, v35, v36, v37);
            mlme_cm_osif_roam_abort_ind();
            if ( (unsigned int)cm_sm_deliver_event(
                                 *v25,
                                 0x1Fu,
                                 4u,
                                 (__int64)&v48,
                                 v39,
                                 v40,
                                 v41,
                                 v42,
                                 v43,
                                 v44,
                                 v45,
                                 v46) )
              cm_remove_cmd(v25, &v48, v17, v18, v19, v20, v21, v22, v23, v24);
            goto LABEL_16;
          }
          v29 = 0;
        }
        v28 = wlan_cm_roam_state_change(v13, v2, v29, 0x35u);
        goto LABEL_14;
      }
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Failed to find pdev for vdev id %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "cm_fw_roam_abort_req",
        (unsigned __int8)v2);
    }
    v28 = 16;
LABEL_16:
    wlan_objmgr_vdev_release_ref(v14, 1u, v16, v17, v18, v19, v20, v21, v22, v23, v24);
    goto LABEL_17;
  }
  qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "cm_fw_roam_abort_req");
  v28 = 29;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v28;
}
