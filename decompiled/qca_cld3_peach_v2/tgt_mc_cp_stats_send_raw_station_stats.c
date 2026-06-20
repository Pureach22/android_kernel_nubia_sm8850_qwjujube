__int64 __fastcall tgt_mc_cp_stats_send_raw_station_stats(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  void (__fastcall *v10)(__int64 *, __int64); // x23
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 comp_private_obj; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v43; // x24
  __int64 v44; // x8
  __int64 v45; // x10
  __int64 v46; // x11
  __int64 v47; // x12
  __int64 v48; // x10
  __int64 v49; // x11
  __int64 v50; // x12
  __int64 v51; // x10
  __int64 v52; // x11
  __int64 v53; // x12
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x8
  unsigned int *v57; // x8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  _QWORD *peer; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x21
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x22
  unsigned __int64 v86; // x8
  __int64 v87; // x8
  __int64 v88; // x8
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  const char *v97; // x2
  __int64 result; // x0
  unsigned int *v99; // x8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // x1
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // [xsp+0h] [xbp-E0h] BYREF
  __int64 v118; // [xsp+8h] [xbp-D8h]
  __int64 v119; // [xsp+10h] [xbp-D0h]
  __int64 v120; // [xsp+18h] [xbp-C8h]
  __int64 v121; // [xsp+20h] [xbp-C0h]
  __int64 v122; // [xsp+28h] [xbp-B8h]
  __int64 v123; // [xsp+30h] [xbp-B0h]
  int v124[2]; // [xsp+38h] [xbp-A8h]
  __int64 v125; // [xsp+40h] [xbp-A0h]
  __int64 v126; // [xsp+48h] [xbp-98h]
  __int64 v127; // [xsp+50h] [xbp-90h]
  __int64 v128; // [xsp+58h] [xbp-88h]
  __int64 v129; // [xsp+60h] [xbp-80h]
  __int64 v130; // [xsp+68h] [xbp-78h]
  __int64 v131; // [xsp+70h] [xbp-70h]
  __int64 v132; // [xsp+78h] [xbp-68h]
  _BYTE *v133; // [xsp+80h] [xbp-60h]
  __int64 v134; // [xsp+88h] [xbp-58h]
  __int64 v135; // [xsp+90h] [xbp-50h]
  __int64 v136; // [xsp+98h] [xbp-48h]
  __int64 v137; // [xsp+A0h] [xbp-40h]
  __int64 v138; // [xsp+A8h] [xbp-38h]
  __int64 v139; // [xsp+B0h] [xbp-30h]
  __int64 v140; // [xsp+B8h] [xbp-28h]
  int v141[2]; // [xsp+C0h] [xbp-20h]
  __int64 v142; // [xsp+C8h] [xbp-18h]
  int v143[2]; // [xsp+D0h] [xbp-10h]
  __int64 v144; // [xsp+D8h] [xbp-8h]

  v144 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = (void (__fastcall *)(__int64 *, __int64))a2[1];
  v142 = 0;
  *(_QWORD *)v143 = 0;
  v140 = 0;
  *(_QWORD *)v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = nullptr;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  *(_QWORD *)v124 = 0;
  v125 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = 0;
  v117 = 0;
  if ( !v10 )
  {
    result = qdf_trace_msg(
               0x62u,
               2u,
               "%s: callback is null",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "tgt_mc_cp_stats_send_raw_station_stats",
               v117,
               v118,
               v119,
               v120,
               v121,
               v122,
               v123,
               *(_QWORD *)v124,
               v125,
               v126,
               v127,
               v128,
               v129,
               v130,
               v131,
               v132,
               v133,
               v134,
               v135,
               v136,
               v137,
               v138,
               v139,
               v140,
               *(_QWORD *)v141,
               v142);
    goto LABEL_40;
  }
  LODWORD(v128) = 1;
  LODWORD(v132) = 1;
  HIDWORD(v140) = 1;
  v129 = _qdf_mem_malloc(0x68u, "tgt_mc_cp_stats_send_raw_station_stats", 1334);
  v133 = (_BYTE *)_qdf_mem_malloc(3u, "tgt_mc_cp_stats_send_raw_station_stats", 1335);
  v13 = _qdf_mem_malloc(8u, "tgt_mc_cp_stats_send_raw_station_stats", 1337);
  *(_QWORD *)v141 = v13;
  if ( v129 )
  {
    if ( v133 )
    {
      if ( v13 )
      {
        if ( (wlan_cp_stats_is_bcn_rssi_history_report_cfg_enable(a1) & 1) == 0
          || (LODWORD(v142) = 1,
              (*(_QWORD *)v143 = _qdf_mem_malloc(0x54u, "tgt_mc_cp_stats_send_raw_station_stats", 1345)) != 0) )
        {
          if ( a2 )
          {
            v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1,
                    *((unsigned int *)a2 + 4),
                    38);
            if ( v22 )
            {
              v31 = v22;
              comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v22, 0x1Bu);
              if ( comp_private_obj )
              {
                v41 = comp_private_obj;
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(comp_private_obj + 24);
                }
                else
                {
                  raw_spin_lock_bh(comp_private_obj + 24);
                  *(_QWORD *)(v41 + 32) |= 1uLL;
                }
                v43 = *(_QWORD *)(v41 + 8);
                *(_BYTE *)v129 = *((_DWORD *)a2 + 4);
                v44 = v129;
                *(_QWORD *)(v129 + 4) = *(_QWORD *)(v43 + 12);
                v45 = *(_QWORD *)(v43 + 36);
                v46 = *(_QWORD *)(v43 + 20);
                v47 = *(_QWORD *)(v43 + 28);
                *(_QWORD *)(v44 + 36) = *(_QWORD *)(v43 + 44);
                *(_QWORD *)(v44 + 28) = v45;
                *(_QWORD *)(v44 + 20) = v47;
                *(_QWORD *)(v44 + 12) = v46;
                v48 = *(_QWORD *)(v43 + 68);
                v49 = *(_QWORD *)(v43 + 52);
                v50 = *(_QWORD *)(v43 + 60);
                *(_QWORD *)(v44 + 68) = *(_QWORD *)(v43 + 76);
                *(_QWORD *)(v44 + 60) = v48;
                *(_QWORD *)(v44 + 52) = v50;
                *(_QWORD *)(v44 + 44) = v49;
                v51 = *(_QWORD *)(v43 + 100);
                v52 = *(_QWORD *)(v43 + 84);
                v53 = *(_QWORD *)(v43 + 92);
                *(_DWORD *)(v44 + 100) = *(_DWORD *)(v43 + 108);
                *(_QWORD *)(v44 + 92) = v51;
                *(_QWORD *)(v44 + 84) = v53;
                *(_QWORD *)(v44 + 76) = v52;
                *v133 = *((_DWORD *)a2 + 4);
                qdf_mem_copy(v133 + 1, (const void *)(v43 + 8), 2u);
                LODWORD(v135) = *(_DWORD *)(v43 + 4);
                v55 = *(_QWORD *)(v43 + 112);
                v54 = *(_QWORD *)(v43 + 120);
                LODWORD(v140) = *(_DWORD *)(v43 + 128);
                v138 = v55;
                v139 = v54;
                qdf_mem_copy(*(void **)v141, (const void *)(v43 + 132), 8u);
                if ( *(_QWORD *)v143 )
                  qdf_mem_copy(*(void **)v143, (const void *)(v43 + 140), 0x54u);
                v56 = *(_QWORD *)(v41 + 32);
                if ( (v56 & 1) != 0 )
                {
                  *(_QWORD *)(v41 + 32) = v56 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v41 + 24);
                }
                else
                {
                  raw_spin_unlock(v41 + 24);
                }
                wlan_objmgr_vdev_release_ref(v31, 0x26u, v57, v58, v59, v60, v61, v62, v63, v64, v65);
                *(_QWORD *)v124 = _qdf_mem_malloc(0x18u, "tgt_mc_cp_stats_send_raw_station_stats", 1356);
                if ( !*(_QWORD *)v124 )
                  goto LABEL_37;
                peer = wlan_objmgr_get_peer(a1, *((_DWORD *)a2 + 5), (_BYTE *)a2 + 24, 0x26u);
                if ( peer )
                {
                  v75 = (__int64)peer;
                  v76 = wlan_objmgr_peer_get_comp_private_obj((__int64)peer, 0x1Bu);
                  if ( v76 )
                  {
                    v85 = v76;
                    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                      || (v86 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v86 + 16) & 0xF0000) != 0)
                      || (*(_DWORD *)(v86 + 16) & 0xFF00) != 0 )
                    {
                      raw_spin_lock(v76 + 24);
                    }
                    else
                    {
                      raw_spin_lock_bh(v76 + 24);
                      *(_QWORD *)(v85 + 32) |= 1uLL;
                    }
                    v87 = *(_QWORD *)(v85 + 8);
                    LODWORD(v134) = *(_DWORD *)v87 / 0x64u;
                    HIDWORD(v134) = *(_DWORD *)(v87 + 4) / 0x64u;
                    if ( *(_QWORD *)(v87 + 24) )
                    {
                      LODWORD(v123) = 1;
                      qdf_mem_copy(*(void **)v124, *(const void **)(v87 + 24), 0x18u);
                    }
                    v88 = *(_QWORD *)(v85 + 32);
                    if ( (v88 & 1) != 0 )
                    {
                      *(_QWORD *)(v85 + 32) = v88 & 0xFFFFFFFFFFFFFFFELL;
                      raw_spin_unlock_bh(v85 + 24);
                    }
                    else
                    {
                      raw_spin_unlock(v85 + 24);
                    }
                    wlan_objmgr_peer_release_ref(v75, 0x26u, v89, v90, v91, v92, v93, v94, v95, v96);
                    LODWORD(v117) = 1;
                    v118 = _qdf_mem_malloc(0x3180u, "tgt_mc_cp_stats_send_raw_station_stats", 1367);
                    if ( !v118 || !(unsigned int)tgt_send_pdev_mc_cp_stats(a1, &v117, a2) )
                      goto LABEL_37;
                    v97 = "%s: tgt_send_pdev_mc_cp_stats failed";
                    goto LABEL_36;
                  }
                  qdf_trace_msg(
                    0x62u,
                    2u,
                    "%s: peer cp stats object is null",
                    v77,
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    "tgt_send_peer_mc_cp_stats",
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    *(_QWORD *)v124,
                    v125,
                    v126,
                    v127,
                    v128);
                  wlan_objmgr_peer_release_ref(v75, 0x26u, v109, v110, v111, v112, v113, v114, v115, v116);
                }
                else
                {
                  qdf_trace_msg(
                    0x62u,
                    8u,
                    "%s: peer object is null",
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    "tgt_send_peer_mc_cp_stats",
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    *(_QWORD *)v124,
                    v125,
                    v126,
                    v127,
                    v128);
                }
                v97 = "%s: tgt_send_peer_mc_cp_stats failed";
LABEL_36:
                qdf_trace_msg(
                  0x62u,
                  2u,
                  v97,
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "tgt_mc_cp_stats_send_raw_station_stats",
                  v117,
                  v118);
                goto LABEL_37;
              }
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: vdev cp stats object is null",
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                "tgt_send_vdev_mc_cp_stats",
                v117,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                *(_QWORD *)v124,
                v125,
                v126,
                v127,
                v128);
              wlan_objmgr_vdev_release_ref(v31, 0x26u, v99, v100, v101, v102, v103, v104, v105, v106, v107);
            }
            else
            {
              qdf_trace_msg(
                0x62u,
                2u,
                "%s: vdev object is null",
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                "tgt_send_vdev_mc_cp_stats",
                v117,
                v118,
                v119,
                v120,
                v121,
                v122,
                v123,
                *(_QWORD *)v124,
                v125,
                v126,
                v127,
                v128);
            }
          }
          v97 = "%s: tgt_send_vdev_mc_cp_stats failed";
          goto LABEL_36;
        }
      }
    }
  }
LABEL_37:
  v108 = *a2;
  if ( *((_DWORD *)v10 - 1) != 488738581 )
    __break(0x8237u);
  v10(&v117, v108);
  result = ucfg_mc_cp_stats_free_stats_resources(&v117);
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
