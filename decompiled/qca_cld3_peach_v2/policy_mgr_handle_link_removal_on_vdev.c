__int64 __fastcall policy_mgr_handle_link_removal_on_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 context; // x0
  _QWORD *v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  const char *v24; // x2
  unsigned int v25; // w1
  unsigned int v26; // w23
  unsigned int v27; // w22
  __int64 v28; // x1
  __int64 v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w24
  int v39; // w8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int8 v48[4]; // [xsp+4h] [xbp-3Ch] BYREF
  unsigned __int8 v49[4]; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int8 v50[4]; // [xsp+Ch] [xbp-34h] BYREF
  _BYTE v51[4]; // [xsp+10h] [xbp-30h] BYREF
  _BYTE v52[4]; // [xsp+14h] [xbp-2Ch] BYREF
  int v53; // [xsp+18h] [xbp-28h] BYREF
  unsigned __int8 v54; // [xsp+1Ch] [xbp-24h]
  _QWORD v55[2]; // [xsp+20h] [xbp-20h] BYREF
  int v56; // [xsp+30h] [xbp-10h]
  __int64 v57; // [xsp+38h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = -1;
  v9 = *(unsigned __int8 *)(a1 + 168);
  v48[0] = -1;
  v10 = *(_QWORD *)(a1 + 216);
  v52[0] = 0;
  v51[0] = 0;
  v54 = 0;
  v53 = 0;
  v56 = 0;
  v55[0] = 0;
  v55[1] = 0;
  v50[0] = v9;
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v24 = "%s: Failed to get psoc";
LABEL_7:
    v25 = 2;
LABEL_8:
    result = qdf_trace_msg(0x4Fu, v25, v24, a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_handle_link_removal_on_vdev");
    goto LABEL_9;
  }
  context = policy_mgr_get_context(*(_QWORD *)(v10 + 80));
  if ( !context )
  {
    v24 = "%s: Invalid Context";
    goto LABEL_7;
  }
  v14 = (_QWORD *)context;
  if ( (wlan_get_vdev_link_removed_flag_by_vdev_id(v11, v9) & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: removal link vdev %d is removed already",
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               "policy_mgr_handle_link_removal_on_vdev",
               v9);
    goto LABEL_9;
  }
  wlan_connectivity_mlo_reconfig_event(a1);
  wlan_set_vdev_link_removed_flag_by_vdev_id(v11, v9, 1);
  if ( (unsigned int)policy_mgr_handle_ml_sta_link_state_allowed(v11, 3, 0) )
  {
    result = wlan_set_vdev_link_removed_flag_by_vdev_id(v11, v9, 0);
    goto LABEL_9;
  }
  policy_mgr_get_ml_sta_info(v14, v52, v51, (__int64)&v53, (__int64)v55, nullptr, 0, 0);
  v26 = v52[0];
  if ( !v52[0] )
  {
    v24 = "%s: unexpected event, no ml sta";
    v25 = 8;
    goto LABEL_8;
  }
  v27 = v51[0];
  if ( v52[0] > 5u || v51[0] > 5u || v52[0] <= (unsigned int)v51[0] )
  {
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: unexpected ml sta num %d %d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "policy_mgr_handle_link_removal_on_vdev",
               v52[0],
               v51[0]);
    goto LABEL_9;
  }
  if ( v52[0] == 1 )
  {
    result = qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: no op for single link mlo, num_ml_sta %d",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "policy_mgr_handle_link_removal_on_vdev",
               1);
    goto LABEL_9;
  }
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: removal link vdev %d num_ml_sta %d num_disabled_ml_sta %d",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "policy_mgr_handle_link_removal_on_vdev",
             v50[0],
             v52[0],
             v51[0]);
  v38 = (unsigned __int8)(v26 - v27);
  if ( (((_BYTE)v26 - (_BYTE)v27) & 0xFE) != 0 )
    v39 = (unsigned __int8)(v26 - v27);
  else
    v39 = 1;
  if ( (unsigned __int8)v53 == v50[0] )
  {
    v39 = 0;
LABEL_39:
    if ( v39 == v38 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: removal link vdev %d is inactive already",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "policy_mgr_handle_link_removal_on_vdev",
        v50[0]);
    }
    else
    {
      if ( v38 < v26 )
        result = policy_mgr_pick_link_vdev_from_inactive_list(
                   v11,
                   a1,
                   v27,
                   (char *)&v53 + (unsigned __int8)(v26 - v27),
                   (char *)v55 + 4 * (unsigned __int8)(v26 - v27),
                   v48,
                   v49);
      if ( v48[0] != 255 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: active parnter vdev %d, inactive removal vdev %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "policy_mgr_handle_link_removal_on_vdev");
        result = policy_mgr_mlo_sta_set_link_ext(
                   v11,
                   3u,
                   6u,
                   1,
                   v48,
                   1,
                   (__int64)v50,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47);
        goto LABEL_9;
      }
      if ( v38 <= 1 )
      {
        if ( v49[0] != 255 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: trigger roaming, non_removal_link_vdev_id %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "policy_mgr_handle_link_removal_on_vdev");
          result = policy_mgr_trigger_roam_on_link_removal(a1);
        }
        goto LABEL_9;
      }
    }
    result = policy_mgr_mlo_sta_set_link_ext(v11, 3u, 2u, 1, v50, 0, 0, v30, v31, v32, v33, v34, v35, v36, v37);
LABEL_9:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v38 < 2 )
    goto LABEL_39;
  if ( BYTE1(v53) == v50[0] )
  {
    v39 = 1;
    goto LABEL_39;
  }
  if ( v38 == 2 )
    goto LABEL_39;
  if ( BYTE2(v53) == v50[0] )
  {
    v39 = 2;
    goto LABEL_39;
  }
  if ( v38 == 3 )
    goto LABEL_39;
  if ( HIBYTE(v53) == v50[0] )
  {
    v39 = 3;
    goto LABEL_39;
  }
  if ( v38 == 4 )
    goto LABEL_39;
  if ( v54 == v50[0] )
  {
    v39 = 4;
    goto LABEL_39;
  }
  if ( v38 == 5 )
    goto LABEL_39;
  __break(0x5512u);
  return policy_mgr_handle_ml_sta_link_state_allowed(result, v28, v29);
}
