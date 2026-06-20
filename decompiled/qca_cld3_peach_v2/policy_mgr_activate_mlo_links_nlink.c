__int64 __fastcall policy_mgr_activate_mlo_links_nlink(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned __int8 *a4,
        unsigned int a5)
{
  unsigned int v7; // w19
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w25
  unsigned int v36; // w23
  unsigned int v37; // w19
  unsigned __int8 *v38; // x21
  bool v39; // cf
  __int64 v40; // x4
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  __int64 v44; // x25
  unsigned __int8 *v45; // x24
  char v46; // w20
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  const char *v52; // x2
  unsigned int v53; // w1
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x4
  __int64 v64; // x6
  __int64 v65; // x7
  unsigned int v66; // [xsp+0h] [xbp-30h]
  unsigned int v67; // [xsp+4h] [xbp-2Ch]
  __int64 v68; // [xsp+10h] [xbp-20h]
  unsigned int v70; // [xsp+2Ch] [xbp-4h]

  v7 = a2;
  v9 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v9 )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: vdev_id: %d vdev not found",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "policy_mgr_activate_mlo_links_nlink",
             (unsigned __int8)v7);
  v18 = v9;
  if ( !wlan_cm_is_vdev_connected(v9, v10, v11, v12, v13, v14, v15, v16, v17) )
  {
    v52 = "%s: vdev is not in connected state";
LABEL_24:
    v53 = 2;
    goto LABEL_25;
  }
  if ( (wlan_vdev_mlme_is_mlo_vdev(v18, v19, v20, v21, v22, v23, v24, v25, v26) & 1) == 0 )
  {
    v52 = "%s: vdev is not mlo vdev";
    goto LABEL_24;
  }
  v66 = a5;
  v67 = v7;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: Num active links: %d",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "policy_mgr_activate_mlo_links_nlink",
    a3);
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = *(unsigned __int8 **)(*(_QWORD *)(v18 + 1360) + 3880LL);
  v68 = v18;
  do
  {
    if ( v38[6] != 255 )
    {
      if ( v38 )
      {
        v40 = *v38;
        v41 = v38[1];
        v42 = v38[2];
        v43 = v38[5];
      }
      else
      {
        v42 = 0;
        v40 = 0;
        v41 = 0;
        v43 = 0;
      }
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: link addr: %02x:%02x:%02x:**:**:%02x",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "policy_mgr_activate_mlo_links_nlink",
        v40,
        v41,
        v42,
        v43);
      if ( !a3 )
        goto LABEL_5;
      v70 = v35;
      v44 = a3;
      v45 = a4;
      v46 = 0;
      do
      {
        if ( v45 )
        {
          v47 = *v45;
          v48 = v45[1];
          v49 = v45[2];
          v50 = v45[5];
        }
        else
        {
          v49 = 0;
          v47 = 0;
          v48 = 0;
          v50 = 0;
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: active addr: %02x:%02x:%02x:**:**:%02x",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "policy_mgr_activate_mlo_links_nlink",
          v47,
          v48,
          v49,
          v50);
        if ( !(unsigned int)qdf_mem_cmp(v38, v45, 6u) )
        {
          v46 = 1;
          v36 |= 1 << v38[6];
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Link address match",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "policy_mgr_activate_mlo_links_nlink");
        }
        --v44;
        v45 += 6;
      }
      while ( v44 );
      v35 = v70;
      if ( (v46 & 1) == 0 )
      {
LABEL_5:
        v35 |= 1 << v38[6];
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: No link address match",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "policy_mgr_activate_mlo_links_nlink");
      }
    }
    v39 = v37++ >= 2;
    v38 += 48;
  }
  while ( !v39 );
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: active link bitmap: 0x%x, inactive link bitmap: 0x%x",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "policy_mgr_activate_mlo_links_nlink",
    v36,
    v35);
  v18 = v68;
  if ( !v36 )
    return wlan_objmgr_vdev_release_ref(v18, 0x18u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
  if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) == 0 || (wlan_mlme_is_aux_emlsr_support(a1) & 1) != 0 )
  {
    if ( v35 )
    {
      v63 = 6;
      v64 = v36;
      v65 = v35;
    }
    else
    {
      v63 = 1;
      v64 = v36;
      v65 = 0;
    }
    ml_nlink_vendor_command_set_link(a1, v67, 1, v66, v63, 0, v64, v65);
    return wlan_objmgr_vdev_release_ref(v18, 0x18u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
  }
  v52 = "%s: Concurrency exists, cannot enter EMLSR mode";
  v53 = 8;
LABEL_25:
  qdf_trace_msg(0x4Fu, v53, v52, v19, v20, v21, v22, v23, v24, v25, v26, "policy_mgr_activate_mlo_links_nlink");
  return wlan_objmgr_vdev_release_ref(v18, 0x18u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
}
