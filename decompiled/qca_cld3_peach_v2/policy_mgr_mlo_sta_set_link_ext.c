__int64 __fastcall policy_mgr_mlo_sta_set_link_ext(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned __int8 *a5,
        int a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 context; // x0
  __int64 v23; // x22
  __int64 v24; // x0
  __int64 v25; // x19
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x23
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x25
  unsigned __int64 v45; // x6
  unsigned __int64 v46; // x4
  unsigned int v47; // w8
  const char *v48; // x2
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned __int8 *v58; // x20
  __int64 v59; // x25
  char v60; // w6
  unsigned int v61; // t1
  unsigned __int64 v62; // x4
  unsigned int v63; // w8
  unsigned int v64; // w20
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+8h] [xbp-38h]
  unsigned int v92; // [xsp+14h] [xbp-2Ch]
  __int64 v93; // [xsp+18h] [xbp-28h]

  if ( !(_BYTE)a4 )
  {
    v48 = "%s: invalid 0 num_mlo_vdev";
LABEL_13:
    qdf_trace_msg(0x4Fu, 2u, v48, a8, a9, a10, a11, a12, a13, a14, a15, "policy_mgr_mlo_sta_set_link_ext");
    return 4;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v48 = "%s: Invalid Context";
    goto LABEL_13;
  }
  v23 = context;
  v24 = _qdf_mem_malloc(0xA0u, "policy_mgr_mlo_sta_set_link_ext", 7215);
  if ( !v24 )
    return 2;
  v25 = v24;
  v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a5, 24);
  if ( !v26 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev %d: invalid vdev",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "policy_mgr_mlo_sta_set_link_ext",
      *a5);
    _qdf_mem_free(v25);
    return 16;
  }
  v91 = a7;
  v35 = v26;
  v93 = a1;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: vdev %d: mode %d num_mlo_vdev %d reason %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "policy_mgr_mlo_sta_set_link_ext",
    *(unsigned __int8 *)(v26 + 168),
    a3,
    (unsigned __int8)a4,
    a2);
  v44 = 0;
  v92 = a2;
  *(_DWORD *)(v25 + 32) = a3;
  *(_DWORD *)(v25 + 36) = a2;
  *(_QWORD *)v25 = v35;
  *(_QWORD *)(v25 + 8) = policy_mgr_handle_link_enable_disable_resp;
  *(_QWORD *)(v25 + 16) = policy_mgr_validate_set_mlo_link_cb;
  *(_QWORD *)(v25 + 24) = v25;
  do
  {
    v45 = a5[v44];
    v46 = v45 >> 5;
    if ( (unsigned int)v45 >= 0x40 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid entry_idx %d num_mlo_vdev %d vdev %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "policy_mgr_fill_ml_active_link_vdev_bitmap",
        v46,
        (unsigned __int8)a4);
    }
    else
    {
      v47 = *(_DWORD *)(v25 + 44);
      *(_DWORD *)(v25 + 84 + 4 * v46) |= 1 << v45;
      if ( v47 <= (unsigned int)v46 )
        *(_DWORD *)(v25 + 44) = v46 + 1;
    }
    ++v44;
  }
  while ( (unsigned __int8)a4 != v44 );
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: num_vdev_bitmap %d vdev_bitmap[0] = 0x%x, vdev_bitmap[1] = 0x%x",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "policy_mgr_fill_ml_active_link_vdev_bitmap",
    *(unsigned int *)(v25 + 44),
    *(unsigned int *)(v25 + 84),
    *(unsigned int *)(v25 + 88));
  *(_DWORD *)(v23 + 2880) = *(_DWORD *)(v25 + 84);
  *(_DWORD *)(v23 + 2884) = *(_DWORD *)(v25 + 88);
  if ( a3 == 6 )
  {
    if ( (_BYTE)a6 )
    {
      v58 = (unsigned __int8 *)v91;
      v59 = (unsigned __int8)a6;
      do
      {
        v61 = *v58++;
        v60 = v61;
        v62 = (unsigned __int64)v61 >> 5;
        if ( v61 >= 0x40 )
        {
          qdf_trace_msg(
            0x4Fu,
            2u,
            "%s: Invalid entry_idx %d num_mlo_vdev %d vdev %d",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "policy_mgr_fill_ml_inactive_link_vdev_bitmap",
            v62,
            (unsigned __int8)a6);
        }
        else
        {
          v63 = *(_DWORD *)(v25 + 48);
          *(_DWORD *)(v25 + 92 + 4 * v62) |= 1 << v60;
          if ( v63 <= (unsigned int)v62 )
            *(_DWORD *)(v25 + 48) = v62 + 1;
        }
        --v59;
      }
      while ( v59 );
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: num_vdev_bitmap %d inactive_vdev_bitmap[0] = 0x%x, inactive_vdev_bitmap[1] = 0x%x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "policy_mgr_fill_ml_inactive_link_vdev_bitmap",
      *(unsigned int *)(v25 + 48),
      *(unsigned int *)(v25 + 92),
      *(unsigned int *)(v25 + 96));
  }
  if ( a3 - 3 <= 1 )
  {
    *(_DWORD *)(v25 + 40) = 1;
    *(_DWORD *)(v25 + 52) = (unsigned __int8)a4 - 1;
  }
  if ( (ml_is_nlink_service_supported(v93) & 1) != 0 )
  {
    v64 = policy_mgr_mlo_sta_set_link_by_linkid(v93, v35, v92, a3, *(_DWORD *)(v25 + 52), a4, (int)a5, a6, v91);
    _qdf_mem_free(v25);
    wlan_objmgr_vdev_release_ref(v35, 0x18u, v65, v66, v67, v68, v69, v70, v71, v72, v73);
    if ( v64 == 24 )
      return 0;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: set_link_by_linkid status %d",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "policy_mgr_mlo_sta_set_link_ext",
      v64);
  }
  else
  {
    policy_mgr_set_link_in_progress(v23, 1);
    v64 = mlo_ser_set_link_req(v25);
    if ( v64 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: vdev %d: Failed to set link mode %d num_mlo_vdev %d reason %d",
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        "policy_mgr_mlo_sta_set_link_ext",
        *(unsigned __int8 *)(v35 + 168),
        a3,
        (unsigned __int8)a4,
        v92);
      _qdf_mem_free(v25);
      v83 = policy_mgr_set_link_in_progress(v23, 0);
    }
    wlan_objmgr_vdev_release_ref(v35, 0x18u, v82, v83, v84, v85, v86, v87, v88, v89, v90);
  }
  return v64;
}
