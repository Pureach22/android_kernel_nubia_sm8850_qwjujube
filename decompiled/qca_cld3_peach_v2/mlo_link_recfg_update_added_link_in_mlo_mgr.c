__int64 __fastcall mlo_link_recfg_update_added_link_in_mlo_mgr(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x27
  __int64 v12; // x20
  __int64 pdev_by_id; // x0
  __int64 v15; // x26
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x8
  __int64 v26; // x25
  unsigned __int64 v27; // x24
  unsigned __int8 *v28; // x19
  __int64 link_info_by_self_addr; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x5
  __int64 v39; // x4
  void **v40; // x28
  __int64 v41; // x4
  int v42; // w25
  __int64 entry_by_bssid; // x0
  __int64 v44; // x23
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  char v53; // w0
  unsigned int v54; // w8
  unsigned int v55; // w9
  unsigned int v56; // w10
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x5
  __int64 v90; // x6
  __int64 v91; // x7
  int v92; // w8
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  int v101; // w1
  unsigned __int8 v102; // w8
  int v103; // w8
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 result; // x0
  const char *v107; // x2
  unsigned int v108; // w19
  unsigned int *v109; // x8
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x6
  __int64 v119; // x7
  int v120; // w8
  const char *v121; // x2
  int v122; // w9
  __int64 v123; // [xsp+0h] [xbp-60h]
  __int64 v124; // [xsp+0h] [xbp-60h]
  __int64 v125; // [xsp+0h] [xbp-60h]
  __int64 v126; // [xsp+8h] [xbp-58h]
  __int64 v127; // [xsp+10h] [xbp-50h]
  __int64 v128; // [xsp+18h] [xbp-48h]
  __int64 v129; // [xsp+20h] [xbp-40h]
  int v130; // [xsp+2Ch] [xbp-34h]
  _QWORD v131[2]; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int64 v132; // [xsp+40h] [xbp-20h]
  __int64 v133; // [xsp+48h] [xbp-18h]
  __int64 v134; // [xsp+50h] [xbp-10h]
  __int64 v135; // [xsp+58h] [xbp-8h]

  v135 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(a2 + 120) )
  {
    result = 0;
    goto LABEL_61;
  }
  v10 = *(_QWORD *)(a1 + 8);
  v133 = 0;
  v134 = 0;
  v131[1] = 0;
  v132 = 0;
  v131[0] = 0;
  if ( !v10 )
  {
    v107 = "%s: mlo_ctx null";
LABEL_41:
    qdf_trace_msg(0x8Fu, 2u, v107, a3, a4, a5, a6, a7, a8, a9, a10, "mlo_link_recfg_update_added_link_in_mlo_mgr");
    result = 4;
    goto LABEL_61;
  }
  v12 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1 )
  {
    v107 = "%s: psoc is null";
    goto LABEL_41;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(*(_QWORD *)a1, 0, 0x6Cu);
  if ( !pdev_by_id )
  {
    v107 = "%s: Invalid pdev";
    goto LABEL_41;
  }
  v15 = pdev_by_id;
  v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          v12,
          *(unsigned __int8 *)(a1 + 16),
          108);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid link recfg VDEV %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlo_link_recfg_update_added_link_in_mlo_mgr",
      *(unsigned __int8 *)(a1 + 16));
    v108 = 4;
    goto LABEL_60;
  }
  v25 = (unsigned int *)*(unsigned __int8 *)(a2 + 120);
  v26 = v16;
  if ( !*(_BYTE *)(a2 + 120) )
  {
LABEL_42:
    v108 = 0;
    goto LABEL_59;
  }
  v27 = 0;
  v28 = (unsigned __int8 *)(a2 + 10);
  v130 = 0;
  v128 = v15;
  v129 = v16;
  while ( 1 )
  {
    if ( v27 == 4 )
      __break(0x5512u);
    if ( !*(_DWORD *)(v28 + 10) )
      break;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: link id %d add with failure status code %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlo_link_recfg_update_added_link_in_mlo_mgr",
      *(v28 - 9));
LABEL_9:
    v25 = (unsigned int *)*(unsigned __int8 *)(a2 + 120);
    ++v27;
    v28 += 40;
    if ( v27 >= (unsigned __int64)v25 )
      goto LABEL_42;
  }
  link_info_by_self_addr = mlo_mgr_get_link_info_by_self_addr(v26, (__int64)(v28 + 4));
  if ( !link_info_by_self_addr )
  {
    v39 = *(v28 - 9);
    if ( v28 == (unsigned __int8 *)-4LL )
    {
      v119 = 0;
      v38 = 0;
      v118 = 0;
      v120 = 0;
    }
    else
    {
      v38 = v28[4];
      v118 = v28[5];
      v119 = v28[6];
      v120 = v28[9];
    }
    v121 = "%s: unexpected link info null for link id %d self mac %02x:%02x:%02x:**:**:%02x";
LABEL_56:
    LODWORD(v123) = v120;
    goto LABEL_57;
  }
  v38 = *(unsigned __int8 *)(link_info_by_self_addr + 6);
  v39 = *(v28 - 9);
  v40 = (void **)link_info_by_self_addr;
  if ( (_DWORD)v38 != (_DWORD)v39 || *(_DWORD *)(a1 + 284) != 4 )
  {
    if ( (_DWORD)v38 != 255 && (*(_QWORD *)(link_info_by_self_addr + 16) & 1) == 0 )
    {
      if ( v28 == (_BYTE *)&off_0 + 2 )
      {
        v120 = 0;
        v118 = 0;
        v119 = 0;
        v122 = 0;
      }
      else
      {
        v118 = *(v28 - 2);
        v119 = *(v28 - 1);
        v120 = *v28;
        v122 = v28[3];
      }
      v121 = "%s: can't updated link %d to mgr connected link id %d ap link %02x:%02x:%02x:**:**:%02x";
      LODWORD(v126) = v122;
      goto LABEL_56;
    }
    v42 = ((_DWORD)v38 == (_DWORD)v39) | v130;
    goto LABEL_21;
  }
  v41 = *(unsigned __int8 *)(a1 + 288);
  if ( (_DWORD)v41 == 255 || (_DWORD)v41 == *(unsigned __int8 *)(link_info_by_self_addr + 12) )
  {
    v42 = 1;
LABEL_21:
    entry_by_bssid = wlan_scan_get_entry_by_bssid(v15, v28 - 2);
    if ( entry_by_bssid )
    {
      v44 = entry_by_bssid;
      qdf_mem_set(v131, 0x28u, 0);
      LOWORD(v131[0]) = *(_DWORD *)(v44 + 1192);
      v53 = wlan_reg_freq_to_chan(v15, LOWORD(v131[0]), v45, v46, v47, v48, v49, v50, v51, v52);
      v54 = *(_DWORD *)(v44 + 52);
      v55 = *(_DWORD *)(v44 + 1196);
      v56 = *(_DWORD *)(v44 + 1200);
      BYTE2(v131[0]) = v53;
      HIDWORD(v133) = v54;
      v132 = __PAIR64__(v56, v55);
      LODWORD(v133) = wlan_mlme_get_ch_width_from_phymode(v54, v57, v58, v59, v60, v61, v62, v63, v64);
      if ( (_DWORD)v133 )
      {
        v130 = v42;
        if ( (v42 & 1) != 0 )
        {
LABEL_25:
          LODWORD(v123) = *((unsigned __int8 *)v40 + 12);
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: curr self link mac %02x:%02x:%02x:**:**:%02x vdev %d ",
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            "mlo_link_recfg_update_added_link_in_mlo_mgr",
            *(unsigned __int8 *)v40,
            *((unsigned __int8 *)v40 + 1),
            *((unsigned __int8 *)v40 + 2),
            *((unsigned __int8 *)v40 + 5),
            v123);
          LODWORD(v124) = *((unsigned __int8 *)v40 + 29);
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: delete old link id %d ap link %02x:%02x:%02x:**:**:%02x",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "mlo_link_recfg_update_added_link_in_mlo_mgr",
            *((unsigned __int8 *)v40 + 6),
            *((unsigned __int8 *)v40 + 24),
            *((unsigned __int8 *)v40 + 25),
            *((unsigned __int8 *)v40 + 26),
            v124);
          if ( v28 == (_BYTE *)&off_0 + 2 )
          {
            v91 = 0;
            v89 = 0;
            v90 = 0;
            v92 = 0;
          }
          else
          {
            v89 = *(v28 - 2);
            v90 = *(v28 - 1);
            v91 = *v28;
            v92 = v28[3];
          }
          LODWORD(v127) = HIDWORD(v133);
          LODWORD(v126) = LOWORD(v131[0]);
          LODWORD(v125) = v92;
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: update to added link id %d ap link %02x:%02x:%02x:**:**:%02x ch %d phymode %d",
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            v87,
            v88,
            "mlo_link_recfg_update_added_link_in_mlo_mgr",
            *(v28 - 9),
            v89,
            v90,
            v91,
            v125,
            v126,
            v127);
          qdf_mutex_acquire(v10 + 1656);
          v101 = *((unsigned __int8 *)v40 + 6);
          v26 = v129;
          if ( v101 != 255 )
            ml_nlink_update_force_state_on_link_delete(v129, v101, v93, v94, v95, v96, v97, v98, v99, v100);
          qdf_mem_copy(v40 + 3, v28 - 2, 6u);
          qdf_mem_copy(v40[4], v131, 0x28u);
          v40[2] = nullptr;
          v102 = *(v28 - 9);
          *((_BYTE *)v40 + 40) = 0;
          *((_BYTE *)v40 + 6) = v102;
          v103 = *(_DWORD *)(v28 - 6);
          *((_DWORD *)v40 + 11) = 0;
          *((_WORD *)v40 + 5) = v103;
          qdf_mutex_release(v10 + 1656);
          mlo_link_recfg_update_scan_mlme(v129, v40 + 3, 2);
          v104 = *(_QWORD *)(v44 + 1320);
          if ( v104 )
            _qdf_mem_free(v104);
          v105 = *(_QWORD *)(v44 + 1896);
          v15 = v128;
          if ( v105 )
            _qdf_mem_free(v105);
          _qdf_mem_free(v44);
          goto LABEL_9;
        }
      }
      else
      {
        LODWORD(v132) = LOWORD(v131[0]);
        v130 = v42;
        if ( (v42 & 1) != 0 )
          goto LABEL_25;
      }
      mlo_free_cache_link_assoc_rsp(v129, *((_BYTE *)v40 + 6), v65, v66, v67, v68, v69, v70, v71, v72);
      goto LABEL_25;
    }
    v26 = v129;
    if ( v28 == (_BYTE *)&off_0 + 2 )
    {
      v118 = 0;
      v39 = 0;
      v38 = 0;
      v119 = 0;
    }
    else
    {
      v39 = *(v28 - 2);
      v38 = *(v28 - 1);
      v118 = *v28;
      v119 = v28[3];
    }
    v121 = "%s: add link %02x:%02x:%02x:**:**:%02x scan entry not found";
LABEL_57:
    qdf_trace_msg(
      0x8Fu,
      8u,
      v121,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "mlo_link_recfg_update_added_link_in_mlo_mgr",
      v39,
      v38,
      v118,
      v119,
      v123,
      v126);
    goto LABEL_58;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: unexpected join pending vdev %d, link info %d link id %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "mlo_link_recfg_update_added_link_in_mlo_mgr",
    v41,
    *(unsigned __int8 *)(link_info_by_self_addr + 12),
    *(unsigned __int8 *)(link_info_by_self_addr + 6));
LABEL_58:
  v108 = 4;
LABEL_59:
  wlan_objmgr_vdev_release_ref(v26, 0x6Cu, v25, v17, v18, v19, v20, v21, v22, v23, v24);
LABEL_60:
  wlan_objmgr_pdev_release_ref(v15, 0x6Cu, v109, v110, v111, v112, v113, v114, v115, v116, v117);
  result = v108;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
