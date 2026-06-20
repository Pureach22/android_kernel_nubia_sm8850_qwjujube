__int64 __fastcall cm_fw_roam_ser_cb(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x21
  __int64 cm_ctx_fl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  __int64 *v23; // x20
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v60; // [xsp+8h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 32);
    cm_ctx_fl = cm_get_cm_ctx_fl(v11, (__int64)"cm_fw_roam_ser_cb", 0x3Au, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( cm_ctx_fl )
    {
      if ( a2 > 1 )
      {
        if ( a2 == 2 )
        {
          cm_reset_active_cm_id(v11, *(_DWORD *)(a1 + 4), v14, v15, v16, v17, v18, v19, v20, v21);
          wlan_objmgr_vdev_release_ref(v11, 0x4Du, v50, v51, v52, v53, v54, v55, v56, v57, v58);
        }
        else
        {
          if ( a2 != 3 )
          {
LABEL_13:
            result = 4;
            goto LABEL_17;
          }
          v23 = (__int64 *)cm_ctx_fl;
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: Active command timeout",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "cm_fw_roam_ser_cb",
            *(unsigned __int8 *)(v11 + 104),
            *(unsigned int *)(a1 + 4));
          v24 = *v23;
          v59 = *(_DWORD *)(a1 + 4);
          cm_get_first_roam_command(v24, v25, v26, v27, v28, v29, v30, v31, v32);
          mlme_cm_osif_roam_abort_ind();
          if ( (unsigned int)cm_sm_deliver_event(*v23, 0x1Fu, 4u, (__int64)&v59, v33, v34, v35, v36, v37, v38, v39, v40) )
            cm_remove_cmd(v23, &v59, v41, v42, v43, v44, v45, v46, v47, v48);
        }
      }
      else
      {
        if ( !a2 )
        {
          v49 = cm_ctx_fl;
          result = 0;
          *(_DWORD *)(v49 + 88) = *(_DWORD *)(a1 + 4);
          goto LABEL_17;
        }
        if ( a2 != 1 )
          goto LABEL_13;
      }
      result = 0;
      goto LABEL_17;
    }
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: cmd is NULL, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "cm_fw_roam_ser_cb",
      (unsigned int)a2);
  }
  result = 29;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
