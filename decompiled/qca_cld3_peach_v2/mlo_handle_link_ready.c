__int64 __fastcall mlo_handle_link_ready(
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
  __int64 v10; // x20
  unsigned int link_vdev_ix; // w21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x5
  __int64 v21; // x6
  __int64 v22; // x7
  int v23; // w8
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x5
  __int64 v43; // x6
  __int64 v44; // x7
  int v45; // w8
  __int64 v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w22
  __int64 v64; // x0
  unsigned int v65; // w0
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
  __int64 v82; // x0
  unsigned int v83; // w0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned __int8 v92; // w0
  unsigned __int16 v93; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v94; // [xsp+18h] [xbp-18h] BYREF
  __int64 v95; // [xsp+20h] [xbp-10h]
  __int64 v96; // [xsp+28h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v94 = 0;
  v95 = 0;
  v93 = 0;
  if ( !a1 || !*(_QWORD *)(a1 + 1360) )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Invalid input", a2, a3, a4, a5, a6, a7, a8, a9, "mlo_handle_link_ready");
    goto LABEL_9;
  }
  if ( !(unsigned int)wlan_vdev_is_up() )
  {
LABEL_44:
    result = 1;
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 1360);
  link_vdev_ix = (unsigned __int8)mlo_get_link_vdev_ix(v10, a1);
  if ( link_vdev_ix == 255 )
  {
LABEL_9:
    result = 0;
    goto LABEL_10;
  }
  if ( (wlan_util_map_index_is_set(*(_QWORD *)(v10 + 2232) + 88LL, link_vdev_ix) & 1) == 0 )
  {
    qdf_mutex_acquire(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2232LL) + 16LL);
    if ( *(_DWORD *)(a1 + 20) == 3 && *(_DWORD *)(a1 + 24) == 18 )
    {
      v33 = (unsigned __int8)mlo_get_link_vdev_ix(v10, a1);
      if ( v33 == 255 )
        goto LABEL_23;
      wlan_util_change_map_index(*(_QWORD *)(v10 + 2232) + 88LL, v33, 1);
      if ( v10 == -17 )
      {
        v44 = 0;
        v42 = 0;
        v43 = 0;
        v45 = 0;
      }
      else
      {
        v42 = *(unsigned __int8 *)(v10 + 17);
        v43 = *(unsigned __int8 *)(v10 + 18);
        v44 = *(unsigned __int8 *)(v10 + 19);
        v45 = *(unsigned __int8 *)(v10 + 22);
      }
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: Setting Bmap for idx:%u mld_addr %02x:%02x:%02x:**:**:%02x",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "mlo_handle_link_ready",
        v33,
        v42,
        v43,
        v44,
        v45);
    }
    v46 = *(_QWORD *)(a1 + 1360);
    if ( **(unsigned __int8 **)(v46 + 2232) == (unsigned __int16)wlan_mlo_ap_get_active_links(
                                                                   a1,
                                                                   v25,
                                                                   v26,
                                                                   v27,
                                                                   v28,
                                                                   v29,
                                                                   v30,
                                                                   v31,
                                                                   v32) )
    {
      mlo_ap_get_vdev_list(a1, &v93, (__int64)&v94, v47, v48, v49, v50, v51, v52, v53, v54);
      v63 = v93;
      if ( (unsigned int)v93 - 3 < 0xFFFFFFFE )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Invalid number of VDEVs under AP-MLD",
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          "mlo_handle_link_ready");
        goto LABEL_23;
      }
      v64 = v94;
      if ( v94 )
      {
        if ( *(_DWORD *)(v94 + 20) != 3 || *(_DWORD *)(v94 + 24) != 18 )
          goto LABEL_32;
        if ( v94 == a1 )
        {
          mlo_release_vdev_ref(v94);
        }
        else
        {
          v46 = v94;
          v65 = mlo_get_link_vdev_ix(v10, v94);
          if ( (_BYTE)v65 != 0xFF )
          {
            if ( (wlan_util_map_index_is_set(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2232LL) + 88LL, v65) & 1) != 0 )
            {
              wlan_vdev_mlme_sm_deliver_evt(v46, 0x1Fu, 0, 0, v66, v67, v68, v69, v70, v71, v72, v73);
              v64 = v94;
            }
            else
            {
              v64 = v46;
            }
            goto LABEL_32;
          }
          mlo_release_vdev_ref(v46);
        }
LABEL_33:
        if ( v63 >= 2 )
        {
          v82 = v95;
          if ( !v95 )
          {
            qdf_trace_msg(0x8Fu, 2u, "%s: vdev is NULL", v74, v75, v76, v77, v78, v79, v80, v81, "mlo_pre_link_up");
            v82 = 0;
            goto LABEL_42;
          }
          if ( *(_DWORD *)(v95 + 20) != 3 || *(_DWORD *)(v95 + 24) != 18 )
          {
LABEL_42:
            while ( 1 )
            {
              mlo_release_vdev_ref(v82);
              if ( v93 <= 2u )
                break;
LABEL_50:
              __break(0x5512u);
LABEL_51:
              v82 = v46;
            }
            goto LABEL_43;
          }
          if ( v95 != a1 )
          {
            v46 = v95;
            v83 = mlo_get_link_vdev_ix(v10, v95);
            if ( (_BYTE)v83 != 0xFF )
            {
              if ( (wlan_util_map_index_is_set(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2232LL) + 88LL, v83) & 1) == 0 )
                goto LABEL_51;
              wlan_vdev_mlme_sm_deliver_evt(v46, 0x1Fu, 0, 0, v84, v85, v86, v87, v88, v89, v90, v91);
              v82 = v95;
              goto LABEL_42;
            }
            v82 = v46;
          }
          mlo_release_vdev_ref(v82);
          if ( v63 > 2 )
            goto LABEL_50;
        }
LABEL_43:
        v92 = mlo_get_link_vdev_ix(v10, a1);
        wlan_util_change_map_index(*(_QWORD *)(v10 + 2232) + 88LL, v92, 0);
        qdf_mutex_release(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2232LL) + 16LL);
        goto LABEL_44;
      }
      qdf_trace_msg(0x8Fu, 2u, "%s: vdev is NULL", v55, v56, v57, v58, v59, v60, v61, v62, "mlo_pre_link_up");
      v64 = 0;
LABEL_32:
      mlo_release_vdev_ref(v64);
      v63 = v93;
      goto LABEL_33;
    }
LABEL_23:
    qdf_mutex_release(*(_QWORD *)(*(_QWORD *)(a1 + 1360) + 2232LL) + 16LL);
    result = 0;
    goto LABEL_10;
  }
  if ( v10 == -17 )
  {
    v22 = 0;
    v20 = 0;
    v21 = 0;
    v23 = 0;
  }
  else
  {
    v20 = *(unsigned __int8 *)(v10 + 17);
    v21 = *(unsigned __int8 *)(v10 + 18);
    v22 = *(unsigned __int8 *)(v10 + 19);
    v23 = *(unsigned __int8 *)(v10 + 22);
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: Bmap is set for idx:%u mld_addr %02x:%02x:%02x:**:**:%02x",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "mlo_handle_link_ready",
    link_vdev_ix,
    v20,
    v21,
    v22,
    v23);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
