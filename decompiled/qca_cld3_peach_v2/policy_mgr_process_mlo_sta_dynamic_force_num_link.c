__int64 __fastcall policy_mgr_process_mlo_sta_dynamic_force_num_link(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 context; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x19
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x22
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x20
  unsigned __int64 v39; // x6
  unsigned __int64 v40; // x4
  unsigned int v41; // w8
  const char *v42; // x2
  __int64 result; // x0
  unsigned int v44; // w21
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int *v62; // x8
  unsigned int v63; // w20
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned __int8 v72; // [xsp+Ch] [xbp-14h]
  __int64 v73; // [xsp+10h] [xbp-10h]

  if ( !(_BYTE)a2 )
  {
    v42 = "%s: invalid 0 num_mlo_vdev";
LABEL_13:
    qdf_trace_msg(
      0x4Fu,
      2u,
      v42,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "policy_mgr_process_mlo_sta_dynamic_force_num_link");
    return 4;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v42 = "%s: Invalid Context";
    goto LABEL_13;
  }
  v17 = context;
  v18 = _qdf_mem_malloc(0xA0u, "policy_mgr_process_mlo_sta_dynamic_force_num_link", 10164);
  if ( !v18 )
    return 2;
  v19 = v18;
  v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a3, 24);
  if ( v20 )
  {
    v72 = a4;
    v29 = v20;
    v73 = v17;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev %d: mode %d num_mlo_vdev %d reason %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "policy_mgr_process_mlo_sta_dynamic_force_num_link",
      *(unsigned __int8 *)(v20 + 168),
      3,
      (unsigned __int8)a2,
      1);
    v38 = 0;
    *(_QWORD *)(v19 + 24) = v19;
    *(_QWORD *)(v19 + 32) = 0x100000003LL;
    *(_QWORD *)v19 = v29;
    *(_QWORD *)(v19 + 8) = policy_mgr_handle_link_enable_disable_resp;
    *(_QWORD *)(v19 + 16) = policy_mgr_validate_set_mlo_link_cb;
    do
    {
      v39 = a3[v38];
      v40 = v39 >> 5;
      if ( (unsigned int)v39 >= 0x40 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid entry_idx %d num_mlo_vdev %d vdev %d",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "policy_mgr_fill_ml_active_link_vdev_bitmap",
          v40,
          (unsigned __int8)a2);
      }
      else
      {
        v41 = *(_DWORD *)(v19 + 44);
        *(_DWORD *)(v19 + 84 + 4 * v40) |= 1 << v39;
        if ( v41 <= (unsigned int)v40 )
          *(_DWORD *)(v19 + 44) = v40 + 1;
      }
      ++v38;
    }
    while ( (unsigned __int8)a2 != v38 );
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: num_vdev_bitmap %d vdev_bitmap[0] = 0x%x, vdev_bitmap[1] = 0x%x",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "policy_mgr_fill_ml_active_link_vdev_bitmap",
      *(unsigned int *)(v19 + 44),
      *(unsigned int *)(v19 + 84),
      *(unsigned int *)(v19 + 88));
    *(_DWORD *)(v73 + 2880) = *(_DWORD *)(v19 + 84);
    *(_DWORD *)(v73 + 2884) = *(_DWORD *)(v19 + 88);
    *(_DWORD *)(v19 + 40) = 1;
    *(_BYTE *)(v19 + 102) = 1;
    *(_DWORD *)(v19 + 52) = v72;
    if ( (ml_is_nlink_service_supported(a1) & 1) != 0 )
    {
      v44 = policy_mgr_mlo_sta_set_link_by_linkid(a1, v29, 1, 3, *(_DWORD *)(v19 + 52), a2, (int)a3, 0, 0);
      _qdf_mem_free(v19);
      wlan_objmgr_vdev_release_ref(v29, 0x18u, v45, v46, v47, v48, v49, v50, v51, v52, v53);
      result = 0;
      if ( v44 != 24 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: set_link_by_linkid status %d",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "policy_mgr_process_mlo_sta_dynamic_force_num_link",
          v44);
        return v44;
      }
    }
    else
    {
      policy_mgr_set_link_in_progress(v73, 1);
      v63 = mlo_ser_set_link_req(v19);
      if ( v63 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: vdev %d: Failed to set link mode %d num_mlo_vdev %d force_active_cnt: %d, reason %d",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "policy_mgr_process_mlo_sta_dynamic_force_num_link",
          *(unsigned __int8 *)(v29 + 168),
          3,
          (unsigned __int8)a2,
          v72,
          1);
        _qdf_mem_free(v19);
        policy_mgr_set_link_in_progress(v73, 0);
      }
      wlan_objmgr_vdev_release_ref(v29, 0x18u, v62, v64, v65, v66, v67, v68, v69, v70, v71);
      return v63;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev %d: invalid vdev",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "policy_mgr_process_mlo_sta_dynamic_force_num_link",
      *a3);
    _qdf_mem_free(v19);
    return 16;
  }
  return result;
}
