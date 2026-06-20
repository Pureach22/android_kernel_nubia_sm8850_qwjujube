__int64 __fastcall wma_csa_offload_handler(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  int v21; // w8
  int v22; // w9
  int v23; // w25
  int v24; // w26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w22
  int v34; // w26
  __int64 ap_link_by_link_id; // x0
  __int16 v36; // w9
  __int64 v37; // x5
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22
  __int64 v47; // x24
  int v48; // w9
  unsigned int v49; // w23
  unsigned __int8 *v50; // x0
  const char *v51; // x2
  int v52; // w8
  unsigned int v53; // w1
  int v54; // w9
  _QWORD *peer_by_mac; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w24
  __int64 v65; // x0
  __int64 v66; // x22
  __int64 v67; // x0
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned __int8 *v77; // x23
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x5
  __int64 v87; // x6
  int v88; // w9
  __int64 v89; // x7
  int v90; // w8
  const char *v91; // x2
  const char *v92; // x3
  __int64 v93; // x4
  __int16 v94; // w9
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  int v103; // w8
  int v104; // w8
  const char *v105; // x2
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 result; // x0
  __int64 v115; // x25
  unsigned __int8 *v116; // x26
  __int64 v117; // x0
  int v118; // w8
  __int16 v119; // w9
  __int64 v120; // x23
  _WORD *v121; // x10
  int v122; // w9
  int v123; // w11
  int v124; // w12
  unsigned __int16 *v125; // x8
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  _DWORD *v134; // x8
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  unsigned __int8 v143; // w1
  unsigned __int8 v144; // w3
  int v145; // w0
  int v146; // w8
  unsigned __int8 *v147; // x0
  unsigned __int8 v148; // w1
  unsigned __int8 v149; // w3
  int v150; // w8
  __int64 active_channel; // x0
  unsigned int *v152; // x8
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  unsigned __int16 *v161; // x20
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  unsigned int *v170; // x8
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x0
  __int64 v180; // [xsp+0h] [xbp-C0h]
  __int64 v181; // [xsp+8h] [xbp-B8h]
  __int64 v182; // [xsp+10h] [xbp-B0h]
  __int64 v183; // [xsp+18h] [xbp-A8h]
  __int64 v184; // [xsp+20h] [xbp-A0h]
  __int64 v185; // [xsp+28h] [xbp-98h]
  __int64 v186; // [xsp+30h] [xbp-90h]
  __int64 v187; // [xsp+50h] [xbp-70h] BYREF
  int v188; // [xsp+58h] [xbp-68h] BYREF
  __int16 v189; // [xsp+5Ch] [xbp-64h]
  _QWORD v190[3]; // [xsp+60h] [xbp-60h] BYREF
  __int64 v191; // [xsp+78h] [xbp-48h]
  __int64 v192; // [xsp+80h] [xbp-40h]
  _QWORD v193[4]; // [xsp+88h] [xbp-38h] BYREF
  int v194; // [xsp+A8h] [xbp-18h]
  int v195; // [xsp+B0h] [xbp-10h] BYREF
  __int16 v196; // [xsp+B4h] [xbp-Ch]
  __int64 v197; // [xsp+B8h] [xbp-8h]

  v197 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wma_csa_offload_handler");
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid csa event buffer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_csa_offload_handler");
    goto LABEL_37;
  }
  v20 = *a2;
  if ( (~*(_DWORD *)(*a2 + 104) & 5) != 0 )
  {
    v54 = *(_DWORD *)(v20 + 20);
    v188 = *(_DWORD *)(v20 + 16);
    v189 = v54;
    goto LABEL_12;
  }
  v21 = *(_DWORD *)(v20 + 88);
  v22 = *(_DWORD *)(v20 + 92);
  v23 = *(_DWORD *)(v20 + 96);
  v24 = *(_DWORD *)(v20 + 100);
  v190[0] = 0;
  LODWORD(v193[0]) = v21;
  WORD2(v193[0]) = v22;
  wlan_mlo_get_mlpeer_by_peer_mladdr(v193, v190);
  v33 = *(_DWORD *)(v20 + 84);
  v34 = BYTE1(v24);
  if ( !v190[0] )
  {
    v86 = LOBYTE(v193[0]);
    v87 = BYTE1(v193[0]);
    v88 = (unsigned __int8)v23;
    v89 = BYTE2(v193[0]);
    v90 = BYTE5(v193[0]);
    v91 = "%s: NULL ml dev ctx, link id %d peer mld addr %02x:%02x:%02x:**:**:%02x peer link addr %02x:%02x:%02x:**:**:%02x";
    LODWORD(v184) = v34;
    v92 = "fill_peer_mac_addr";
    LODWORD(v183) = BYTE2(v23);
    LODWORD(v182) = BYTE1(v23);
    v93 = v33;
LABEL_21:
    LODWORD(v181) = v88;
LABEL_22:
    LODWORD(v180) = v90;
    qdf_trace_msg(
      0x36u,
      2u,
      v91,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v92,
      v93,
      v86,
      v87,
      v89,
      v180,
      v181,
      v182,
      v183,
      v184);
    goto LABEL_37;
  }
  ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(v190[0], (unsigned __int8)*(_DWORD *)(v20 + 84));
  if ( !ap_link_by_link_id )
  {
    v93 = *(unsigned int *)(v20 + 84);
    v86 = LOBYTE(v193[0]);
    v88 = (unsigned __int8)v23;
    v87 = BYTE1(v193[0]);
    v89 = BYTE2(v193[0]);
    v91 = "%s: NULL link info, link id %d peer mld addr %02x:%02x:%02x:**:**:%02x peer link addr %02x:%02x:%02x:**:**:%02x";
    v90 = BYTE5(v193[0]);
    v92 = "fill_peer_mac_addr";
    LODWORD(v184) = v34;
    LODWORD(v183) = BYTE2(v23);
    LODWORD(v182) = BYTE1(v23);
    goto LABEL_21;
  }
  v36 = *(_WORD *)(ap_link_by_link_id + 28);
  v37 = *(unsigned __int8 *)(ap_link_by_link_id + 12);
  v188 = *(_DWORD *)(ap_link_by_link_id + 24);
  v189 = v36;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: csa event link id %d vdev id %d peer mld addr %02x:%02x:%02x:**:**:%02x peer link addr %02x:%02x:%02x:**:**:%02x"
    " host link info ap_link_addr %02x:%02x:%02x:**:**:%02x",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "fill_peer_mac_addr",
    (unsigned __int8)v33,
    v37,
    LOBYTE(v193[0]),
    BYTE1(v193[0]),
    BYTE2(v193[0]),
    BYTE5(v193[0]),
    (unsigned __int8)v23,
    BYTE1(v23),
    BYTE2(v23),
    v34,
    *(unsigned __int8 *)(ap_link_by_link_id + 24),
    *(unsigned __int8 *)(ap_link_by_link_id + 25),
    *(unsigned __int8 *)(ap_link_by_link_id + 26),
    *(unsigned __int8 *)(ap_link_by_link_id + 29));
  v46 = *(_QWORD *)(a1 + 24);
  v47 = *(_QWORD *)(a1 + 32);
  v187 = 0;
  v194 = 0;
  memset(v193, 0, sizeof(v193));
  v191 = 0;
  v192 = 0;
  memset(v190, 0, sizeof(v190));
  if ( v46 )
  {
    v48 = *(_DWORD *)(v20 + 92);
    v195 = *(_DWORD *)(v20 + 88);
    v196 = v48;
    wlan_mlo_get_mlpeer_by_peer_mladdr(&v195, &v187);
    v49 = *(_DWORD *)(v20 + 84);
    if ( !v187 )
    {
      v51 = "%s: NULL ml dev ctx, link id %d peer mld addr %02x:%02x:%02x:**:**:%02x";
      v52 = HIBYTE(v196);
      v53 = 2;
      goto LABEL_40;
    }
    v50 = (unsigned __int8 *)mlo_mgr_get_ap_link_by_link_id(v187, (unsigned __int8)*(_DWORD *)(v20 + 84));
    if ( !v50 )
    {
      v51 = "%s: NULL link info link id %d peer mld addr %02x:%02x:%02x:**:**:%02x";
      v52 = HIBYTE(v196);
      v53 = 2;
      goto LABEL_40;
    }
    if ( v50[12] != 255 )
    {
      v51 = "%s: vdev id %d link id %d Active link CSA event: BSSID %02x:%02x:%02x:**:**:%02x";
      v52 = v50[26];
      LODWORD(v181) = v50[29];
      v53 = 8;
LABEL_40:
      LODWORD(v180) = v52;
      qdf_trace_msg(0x36u, v53, v51, v38, v39, v40, v41, v42, v43, v44, v45, "handle_csa_standby_link", v180, v181);
      goto LABEL_12;
    }
    v115 = *(_QWORD *)(v46 + 2128);
    if ( v115 == -1984 )
    {
      v105 = "%s: tx_ops is null!";
    }
    else
    {
      v116 = v50;
      if ( (fill_csa_offload_params(v20, v193, v47) & 1) != 0 )
      {
        mlo_mgr_update_csa_link_info(v47, v187, v193, v49);
        mlo_mgr_standby_link_csa_notify(v116 + 24);
        LOBYTE(v190[0]) = v116[6];
        v117 = _qdf_mem_malloc(0x28u, "handle_csa_standby_link", 1580);
        v191 = v117;
        if ( v117 )
        {
          v118 = *((_DWORD *)v116 + 6);
          v119 = *((_WORD *)v116 + 14);
          v120 = v117;
          LOBYTE(v192) = 0;
          v121 = *((_WORD **)v116 + 4);
          *(_DWORD *)((char *)v190 + 1) = v118;
          *(_WORD *)((char *)v190 + 5) = v119;
          *(_WORD *)v117 = *v121;
          v122 = SBYTE1(v190[0]);
          LODWORD(v121) = SBYTE2(v190[0]);
          v123 = SBYTE3(v190[0]);
          v124 = SBYTE6(v190[0]);
          *(_DWORD *)(v117 + 16) = *(_DWORD *)(*((_QWORD *)v116 + 4) + 16LL);
          *(_DWORD *)(v117 + 20) = *(_DWORD *)(*((_QWORD *)v116 + 4) + 20LL);
          *(_DWORD *)(v117 + 28) = *(_DWORD *)(*((_QWORD *)v116 + 4) + 28LL);
          v125 = *((unsigned __int16 **)v116 + 4);
          LODWORD(v184) = v124;
          LODWORD(v183) = v123;
          LODWORD(v182) = (_DWORD)v121;
          LODWORD(v181) = v122;
          LODWORD(v180) = *((_DWORD *)v125 + 7);
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: link id %d chan freq %d cfreq1 %d cfreq2 %d host phymode %d ap mld mac %02x:%02x:%02x:**:**:%02x",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "handle_csa_standby_link",
            v116[6],
            *v125,
            *((unsigned int *)v125 + 4),
            *((unsigned int *)v125 + 5),
            v180,
            v181,
            v182,
            v183,
            v184);
          v134 = *(_DWORD **)(v115 + 2016);
          if ( v134 )
          {
            if ( *(v134 - 1) != -82738735 )
              __break(0x8228u);
            if ( !((unsigned int (__fastcall *)(__int64, _QWORD *))v134)(v46, v190) )
            {
              v179 = v191;
              goto LABEL_62;
            }
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: failed to send link set bss request command to FW",
              v135,
              v136,
              v137,
              v138,
              v139,
              v140,
              v141,
              v142,
              "handle_csa_standby_link");
            _qdf_mem_free(v191);
          }
          else
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: handler is not registered",
              v126,
              v127,
              v128,
              v129,
              v130,
              v131,
              v132,
              v133,
              "handle_csa_standby_link");
            _qdf_mem_free(v120);
          }
          goto LABEL_12;
        }
        v105 = "%s: no mem acquired";
      }
      else
      {
        v105 = "%s: CSA Event error: No CSA IE present";
      }
    }
  }
  else
  {
    v105 = "%s: null psoc";
  }
  qdf_trace_msg(0x36u, 2u, v105, v38, v39, v40, v41, v42, v43, v44, v45, "handle_csa_standby_link");
LABEL_12:
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), &v188, 8u);
  if ( peer_by_mac )
  {
    v64 = *(unsigned __int8 *)(peer_by_mac[12] + 168LL);
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v56, v57, v58, v59, v60, v61, v62, v63);
    v65 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *(_QWORD *)(a1 + 24),
            v64,
            8);
    if ( v65 )
    {
      v66 = v65;
      v67 = _qdf_mem_malloc(0x24u, "wma_csa_offload_handler", 1753);
      if ( !v67 )
      {
LABEL_35:
        wlan_objmgr_vdev_release_ref(v66, 8u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
LABEL_36:
        wlan_mlme_send_csa_event_status_ind(v66, 0, v106, v107, v108, v109, v110, v111, v112, v113);
        goto LABEL_37;
      }
      v77 = (unsigned __int8 *)v67;
      if ( wlan_cm_is_vdev_roaming(v66, v69, v70, v71, v72, v73, v74, v75, v76) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Roaming in progress for vdev %d, ignore csa event",
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          "wma_csa_offload_handler",
          v64);
LABEL_34:
        _qdf_mem_free((__int64)v77);
        goto LABEL_35;
      }
      qdf_mem_set(v77, 0x24u, 0);
      v94 = v189;
      *((_DWORD *)v77 + 7) = v188;
      *((_WORD *)v77 + 16) = v94;
      if ( (fill_csa_offload_params(v20, v77, *(_QWORD *)(a1 + 32)) & 1) == 0 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: CSA Event error: No CSA IE present",
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          "wma_csa_offload_handler");
        goto LABEL_34;
      }
      v103 = *(_DWORD *)(v20 + 52);
      if ( (v103 & 0x40) != 0 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: WMI_CSWRAP_IE_EXT_VER_2 received",
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          "wma_csa_offload_handler");
        if ( !(unsigned int)wma_parse_bw_indication_ie(a2[2], *((unsigned int *)a2 + 6), v77) )
        {
          v104 = *((_DWORD *)v77 + 6) | 0x10;
          goto LABEL_57;
        }
        v103 = *(_DWORD *)(v20 + 52);
      }
      if ( (v103 & 4) != 0 )
      {
        v143 = *v77;
        v77[19] = *(_BYTE *)(v20 + 43);
        v144 = *(_BYTE *)(v20 + 44);
        v77[20] = v144;
        v145 = wlan_mlme_convert_vht_op_bw_to_phy_ch_width(*(_BYTE *)(v20 + 42), v143, *(_BYTE *)(v20 + 43), v144);
        v146 = *((_DWORD *)v77 + 6);
        *((_DWORD *)v77 + 3) = v145;
        v104 = v146 | 4;
      }
      else
      {
        if ( (v103 & 0x20) == 0 )
        {
          v104 = *((_DWORD *)v77 + 6);
LABEL_58:
          LODWORD(v184) = v77[19];
          LODWORD(v186) = v77[18];
          LODWORD(v185) = v77[20];
          LODWORD(v183) = *((_DWORD *)v77 + 3);
          LODWORD(v182) = v104;
          LODWORD(v181) = *((_DWORD *)v77 + 1);
          LODWORD(v180) = *v77;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: CSA: BSSID %02x:%02x:%02x:**:**:%02x chan %d freq %d flag 0x%x width = %d freq1 = %d freq2 = %d op class = %d",
            v95,
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            "wma_csa_offload_handler",
            v77[28],
            v77[29],
            v77[30],
            v77[33],
            v180,
            v181,
            v182,
            v183,
            v184,
            v185,
            v186);
          active_channel = wlan_vdev_get_active_channel(v66);
          if ( active_channel )
          {
            v161 = (unsigned __int16 *)active_channel;
            wlan_objmgr_vdev_release_ref(v66, 8u, v152, v153, v154, v155, v156, v157, v158, v159, v160);
            cds_freq_to_chan(*v161);
            if ( *v77 )
            {
              wma_send_msg(a1, 4297, v77, 0);
              result = 0;
              goto LABEL_38;
            }
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: CSA Event with channel %d. Ignore !!",
              v162,
              v163,
              v164,
              v165,
              v166,
              v167,
              v168,
              v169,
              "wma_csa_offload_handler",
              0);
            _qdf_mem_free((__int64)v77);
            goto LABEL_36;
          }
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: failed to get active channel",
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            "wma_csa_offload_handler");
          wlan_objmgr_vdev_release_ref(v66, 8u, v170, v171, v172, v173, v174, v175, v176, v177, v178);
          v179 = (__int64)v77;
LABEL_62:
          _qdf_mem_free(v179);
          result = 0;
          goto LABEL_38;
        }
        v147 = (unsigned __int8 *)wma_parse_ch_switch_wrapper_ie(v20 + 60, 194, 0);
        if ( v147 )
        {
          v148 = *v77;
          v77[19] = v147[3];
          v149 = v147[4];
          v77[20] = v149;
          *((_DWORD *)v77 + 3) = wlan_mlme_convert_vht_op_bw_to_phy_ch_width(v147[2], v148, v147[3], v149);
          *(_DWORD *)(v20 + 52) |= 4u;
          v150 = *((_DWORD *)v77 + 6) | 4;
        }
        else
        {
          v150 = *((_DWORD *)v77 + 6);
        }
        v104 = v150 | 8;
      }
LABEL_57:
      *((_DWORD *)v77 + 6) = v104;
      goto LABEL_58;
    }
    v86 = (unsigned __int8)v188;
    v87 = BYTE1(v188);
    v91 = "%s: NULL vdev, vdev_id %d peer mac addr %02x:%02x:%02x:**:**:%02x";
    v89 = BYTE2(v188);
    v90 = HIBYTE(v189);
    v92 = "wma_csa_offload_handler";
    v93 = v64;
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid peer, peer mac addr %02x:%02x:%02x:**:**:%02x",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    "wma_csa_offload_handler",
    (unsigned __int8)v188,
    BYTE1(v188),
    BYTE2(v188),
    HIBYTE(v189));
LABEL_37:
  result = 4294967274LL;
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
