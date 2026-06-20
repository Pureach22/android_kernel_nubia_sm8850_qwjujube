__int64 __fastcall policy_mgr_allow_non_force_link_bitmap(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        unsigned __int16 a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  int v18; // w25
  unsigned int v19; // w22
  unsigned int standby_link_freq; // w23
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w24
  __int64 v31; // x26
  const char *v32; // x24
  const char *v33; // x21
  unsigned int v34; // w8
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w28
  __int64 v45; // x27
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x25
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int *v64; // x8
  const char *v65; // x22
  const char *v66; // x21
  int v67; // w24
  int v68; // w23
  int v69; // w20
  bool v70; // zf
  __int64 v71; // x4
  unsigned int *v72; // x8
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w4
  unsigned __int16 *v82; // x8
  char is_concurrency_allowed; // w25
  unsigned int *v84; // x8
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 assoc_link_vdev; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w21
  char v103; // [xsp+8h] [xbp-108h]
  __int64 v104; // [xsp+10h] [xbp-100h]
  unsigned int v105; // [xsp+1Ch] [xbp-F4h]
  __int16 v106[2]; // [xsp+20h] [xbp-F0h] BYREF
  unsigned __int16 v107; // [xsp+24h] [xbp-ECh] BYREF
  unsigned __int8 v108; // [xsp+28h] [xbp-E8h]
  _BYTE v109[4]; // [xsp+2Ch] [xbp-E4h] BYREF
  int v110; // [xsp+30h] [xbp-E0h] BYREF
  unsigned __int8 v111; // [xsp+34h] [xbp-DCh]
  __int16 v112; // [xsp+38h] [xbp-D8h]
  _WORD v113[2]; // [xsp+3Ch] [xbp-D4h] BYREF
  _QWORD v114[22]; // [xsp+40h] [xbp-D0h] BYREF
  int v115; // [xsp+F0h] [xbp-20h]
  _QWORD v116[3]; // [xsp+F8h] [xbp-18h] BYREF

  v116[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v111 = 0;
  v113[0] = 0;
  v110 = 0;
  v116[0] = 0;
  v115 = 0;
  memset(v114, 0, sizeof(v114));
  v109[0] = 0;
  v108 = 0;
  v112 = 0;
  v107 = 0;
  v106[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_allow_non_force_link_bitmap");
    result = 0;
    goto LABEL_66;
  }
  v17 = context;
  v18 = a3;
  v19 = ml_nlink_get_standby_link_bitmap(a1, a2) & a3;
  if ( v19 )
    standby_link_freq = ml_nlink_get_standby_link_freq(a1, a2, v19);
  else
    standby_link_freq = 0;
  ml_nlink_convert_linkid_bitmap_to_vdev_bitmap(a1, a2, v18, 0, (int)&v110, (int)v116);
  if ( !v111 && !standby_link_freq )
  {
    result = 1;
    goto LABEL_66;
  }
  v108 = 0;
  if ( a4 )
    ml_nlink_convert_linkid_bitmap_to_vdev_bitmap(a1, a2, a4, 0, (int)&v110, (int)v116);
  qdf_mutex_acquire(v17 + 56);
  ml_nlink_get_dynamic_inactive_links(a1, a2, &v107, v106);
  if ( v108 )
  {
    v109[0] = 0;
    ((void (__fastcall *)(__int64, _QWORD, _QWORD *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
      a1,
      (unsigned __int8)v112,
      v114,
      v109);
    v30 = v109[0];
    if ( v108 >= 2u && v109[0] <= 4u )
    {
      v109[0] = 0;
      ((void (__fastcall *)(__int64, _QWORD, char *, _BYTE *))policy_mgr_store_and_del_conn_info_by_vdev_id)(
        a1,
        HIBYTE(v112),
        (char *)v114 + 36 * v30,
        v109);
      LOBYTE(v30) = v109[0] + v30;
      if ( v108 >= 3u && (unsigned __int8)v30 < 5u )
      {
        v109[0] = 0;
        goto LABEL_67;
      }
    }
  }
  else
  {
    LOBYTE(v30) = 0;
  }
  if ( standby_link_freq
    && ((unsigned __int16)v19 & v107) == 0
    && (policy_mgr_is_concurrency_allowed(a1, 0, standby_link_freq, 3, 3u, 0) & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: not allow - standby link 0x%x freq %d active due to conc",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "policy_mgr_allow_non_force_link_bitmap",
      v19,
      standby_link_freq);
    v102 = 0;
    goto LABEL_63;
  }
  if ( !v111 )
  {
    v102 = 1;
    goto LABEL_63;
  }
  v103 = v30;
  v104 = v17;
  v31 = 0;
  v32 = "%s: invalid vdev id %d ";
  v33 = "policy_mgr_allow_non_force_link_bitmap";
  v105 = 0;
  while ( 1 )
  {
    if ( v31 == 2 )
      goto LABEL_67;
    v35 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            *((unsigned __int8 *)v113 + v31),
            90);
    v44 = *((unsigned __int8 *)v113 + v31);
    if ( v35 )
      break;
    qdf_trace_msg(0x4Fu, 2u, v32, v36, v37, v38, v39, v40, v41, v42, v43, v33, *((unsigned __int8 *)v113 + v31));
LABEL_24:
    v34 = v111;
    if ( ++v31 >= (unsigned __int64)v111 )
      goto LABEL_58;
  }
  v45 = v35;
  v46 = policy_mgr_get_context(a1);
  if ( !v46 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "policy_mgr_vdev_is_force_inactive");
LABEL_41:
    wlan_objmgr_vdev_release_ref(v45, 0x5Au, v64, v56, v57, v58, v59, v60, v61, v62, v63);
    goto LABEL_24;
  }
  v55 = v46;
  qdf_mutex_acquire(v46 + 56);
  if ( pm_disabled_ml_links[0] == 1 && !dword_8D4FC4 && (unsigned __int8)byte_8D4FCC == v44 )
  {
    qdf_mutex_release(v55 + 56);
  }
  else
  {
    v65 = v33;
    v66 = v32;
    v67 = (unsigned __int8)byte_8D4FD0;
    v68 = dword_8D4FD4;
    v69 = (unsigned __int8)byte_8D4FDC;
    qdf_mutex_release(v55 + 56);
    v70 = v67 == 1;
    v32 = v66;
    v33 = v65;
    if ( !v70 || v68 || v69 != v44 )
      goto LABEL_41;
  }
  v71 = *(unsigned __int8 *)(v45 + 93);
  if ( (_DWORD)v71 == 255 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: invalid link id %d vdev id %d ",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v33,
      v71,
      *((unsigned __int8 *)v113 + v31));
    goto LABEL_41;
  }
  if ( ((v107 >> v71) & 1) != 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: link id %d vdev id %d is in dynamic_inactive 0x%x",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v33);
    wlan_objmgr_vdev_release_ref(v45, 0x5Au, v72, v73, v74, v75, v76, v77, v78, v79, v80);
    goto LABEL_24;
  }
  if ( !*(_DWORD *)(v45 + 16) )
  {
    if ( (*(_BYTE *)(v45 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v45)) != 0 )
    {
      if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v94, v95, v96, v97, v98, v99, v100, v101) )
        v81 = 3;
      else
        v81 = 1;
      v82 = *(unsigned __int16 **)(v45 + 32);
      if ( !v82 )
        goto LABEL_45;
    }
    else
    {
      v81 = 1;
      v82 = *(unsigned __int16 **)(v45 + 32);
      if ( !v82 )
        goto LABEL_45;
    }
LABEL_44:
    v105 = *v82;
    goto LABEL_45;
  }
  v81 = 0;
  v82 = *(unsigned __int16 **)(v45 + 32);
  if ( v82 )
    goto LABEL_44;
LABEL_45:
  is_concurrency_allowed = policy_mgr_is_concurrency_allowed(a1, 0, v105, 3, v81, 0);
  wlan_objmgr_vdev_release_ref(v45, 0x5Au, v84, v85, v86, v87, v88, v89, v90, v91, v92);
  if ( (is_concurrency_allowed & 1) != 0 )
    goto LABEL_24;
  v34 = v111;
LABEL_58:
  if ( v34 > (unsigned __int8)v31 )
  {
    if ( (unsigned __int8)v31 <= 1u )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: not allow - vdev %d freq %d active due to conc",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "policy_mgr_allow_non_force_link_bitmap",
        *(unsigned __int8 *)((unsigned __int64)v113 | v31 & 1),
        v105);
      v102 = 0;
      goto LABEL_62;
    }
LABEL_67:
    __break(0x5512u);
  }
  v102 = 1;
LABEL_62:
  LOBYTE(v30) = v103;
  v17 = v104;
LABEL_63:
  if ( (_BYTE)v30 )
    policy_mgr_restore_deleted_conn_info(a1, (unsigned int *)v114, v30, v22, v23, v24, v25, v26, v27, v28, v29);
  qdf_mutex_release(v17 + 56);
  result = v102;
LABEL_66:
  _ReadStatusReg(SP_EL0);
  return result;
}
