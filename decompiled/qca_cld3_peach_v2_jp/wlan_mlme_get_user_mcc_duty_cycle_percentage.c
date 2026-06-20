__int64 __fastcall wlan_mlme_get_user_mcc_duty_cycle_percentage(__int64 a1)
{
  __int64 psoc_ext_obj_fl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w21
  unsigned int v12; // w20
  unsigned int v13; // w23
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int v23; // w0
  unsigned int v24; // w1
  __int64 result; // x0
  unsigned int v26; // w22
  __int64 pdev_by_id; // x0
  __int64 v28; // x19
  unsigned __int8 v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w24
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int8 v47; // w0
  int v48; // w20
  unsigned int v49; // w20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v78; // [xsp+8h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v77 = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
  {
    v22 = "%s: Error getting user quota set";
    v23 = 104;
    v24 = 8;
LABEL_7:
    qdf_trace_msg(v23, v24, v22, v3, v4, v5, v6, v7, v8, v9, v10, "wlan_mlme_get_user_mcc_duty_cycle_percentage");
    goto LABEL_9;
  }
  v11 = *(unsigned __int8 *)(psoc_ext_obj_fl + 1121);
  v12 = *(unsigned __int8 *)(psoc_ext_obj_fl + 1120);
  if ( v11 == 255 || !*(_BYTE *)(psoc_ext_obj_fl + 1120) )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Invalid quota : vdev %u, quota %u",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_mlme_get_user_mcc_duty_cycle_percentage",
      *(unsigned __int8 *)(psoc_ext_obj_fl + 1121),
      *(unsigned __int8 *)(psoc_ext_obj_fl + 1120));
    goto LABEL_9;
  }
  v13 = *(_DWORD *)(psoc_ext_obj_fl + 1116);
  if ( !(unsigned int)policy_mgr_get_chan_by_session_id(a1, v11, &v77) )
  {
    result = policy_mgr_get_mcc_operating_channel(a1, v11);
    if ( !(_DWORD)result )
      goto LABEL_10;
    v26 = result;
    pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, 0, 2u);
    if ( pdev_by_id )
    {
      v28 = pdev_by_id;
      v29 = wlan_reg_freq_to_chan(pdev_by_id, v77, v3, v4, v5, v6, v7, v8, v9, v10);
      if ( v29 )
      {
        v38 = v29;
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: Opmode (%d) vdev (%u) channel %u and quota %u",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_mlme_get_user_mcc_duty_cycle_percentage",
          v13,
          v11,
          v29,
          v12);
        v47 = wlan_reg_freq_to_chan(v28, v26, v39, v40, v41, v42, v43, v44, v45, v46);
        if ( v47 )
        {
          v48 = ((v12 << 16) | (v38 << 8)) & 0xFCFFFFFF | v47 | ((wlan_reg_freq_to_band(v77) & 3) << 24);
          v49 = v48 & 0xF3FFFFFF | ((wlan_reg_freq_to_band(v26) & 3) << 26);
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: quota value: 0x%x",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "wlan_mlme_get_user_mcc_duty_cycle_percentage",
            v49);
          wlan_objmgr_pdev_release_ref(v28, 2u, v58, v59, v60, v61, v62, v63, v64, v65, v66);
          result = v49;
          goto LABEL_10;
        }
        v67 = "%s: Secondary op channel is invalid";
      }
      else
      {
        v67 = "%s: Primary op channel is invalid";
      }
      qdf_trace_msg(
        0x68u,
        8u,
        v67,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "wlan_mlme_get_user_mcc_duty_cycle_percentage");
      wlan_objmgr_pdev_release_ref(v28, 2u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
      goto LABEL_9;
    }
    v22 = "%s: pdev is NULL";
    v23 = 52;
    v24 = 2;
    goto LABEL_7;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Could not get vdev %u chan",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "wlan_mlme_get_user_mcc_duty_cycle_percentage",
    v11);
LABEL_9:
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
