__int64 __fastcall wlan_hdd_add_key_vdev(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        const void *a5,
        __int64 a6,
        unsigned int a7,
        __int64 *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  int v18; // w8
  __int64 result; // x0
  __int64 v20; // x28
  __int64 *v25; // x24
  __int64 bsspeer; // x0
  long double v27; // q0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x26
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  __int64 v45; // x26
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int *v54; // x27
  __int64 v55; // x26
  __int64 v56; // x0
  _QWORD *peer_by_mac; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w26
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x0
  _BOOL4 v76; // w2
  unsigned int v77; // w1
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w8
  unsigned int v88; // w28
  unsigned int param; // w26
  unsigned int v90; // w25
  _QWORD *context; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  int v100; // w8
  const char *v101; // x2
  unsigned int v102; // w26
  unsigned int v103; // w24
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  char is_auth_status_connected; // w8
  unsigned int cmd; // w0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int v122; // w0
  __int64 v123; // x0
  char is_multipass_sap; // w0
  __int64 v125; // x2
  unsigned int v126; // w19
  unsigned int ref; // w0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  unsigned int v136; // w26
  const char *v137; // x2
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  unsigned int *v146; // x8
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 *v155; // [xsp+8h] [xbp-28h]
  unsigned int v156; // [xsp+14h] [xbp-1Ch] BYREF
  unsigned int v157; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v158; // [xsp+1Ch] [xbp-14h]
  __int64 v159; // [xsp+28h] [xbp-8h]

  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_DWORD *)(a6 + 28);
  v158 = 0;
  v157 = 0;
  if ( v18 == 4232959 )
  {
    result = sme_add_key_krk(a1, *(unsigned __int8 *)(a2 + 168), *(_QWORD *)a6, *(unsigned int *)(a6 + 16));
    goto LABEL_70;
  }
  if ( v18 != 4232958 )
  {
    v20 = *a8;
    v25 = *(__int64 **)(*a8 + 24);
    if ( (a4 & 1) != 0 || (*(_DWORD *)(a2 + 16) | 2) != 2 )
    {
      if ( a5 )
        qdf_mem_copy(&v157, a5, 6u);
      v54 = (int *)(v20 + 40);
      if ( !*(_DWORD *)(v20 + 40) && (a4 & 1) != 0 && (*(_BYTE *)(a2 + 60) & 2) != 0 )
      {
        v55 = *v25;
        if ( (mlo_roam_is_auth_status_connected(**(_QWORD **)(v20 + 24), *(unsigned __int8 *)(a2 + 168)) & 1) != 0 )
          wlan_crypto_free_key_by_link_id(v55, (unsigned __int8 *)(a2 + 86), *(_BYTE *)(a2 + 93));
      }
      if ( (a4 & 1) != 0 && !*v54 && (wlan_vdev_mlme_is_mlo_vdev(a2, a9, a10, a11, a12, a13, a14, a15, a16) & 1) != 0 )
      {
        v56 = *v25;
        v156 = 0;
        peer_by_mac = wlan_objmgr_get_peer_by_mac(v56, &v157, 6u);
        if ( peer_by_mac )
        {
          v66 = *((_DWORD *)peer_by_mac + 17);
          wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 6u, v58, v59, v60, v61, v62, v63, v64, v65);
        }
        else
        {
          if ( (hdd_mlo_vdev_allow_pairwise_without_peer(a2, &v157, &v156) & 1) == 0 )
          {
            result = 4294967274LL;
            goto LABEL_70;
          }
          v66 = v156;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Peer type %d",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "wlan_hdd_add_key_vdev",
          v66);
        if ( v66 == 6 )
        {
          if ( (ucfg_tdls_is_key_install_allowed(a2, &v157) & 1) == 0 )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: TDLS peer's key install disallowed",
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              "wlan_hdd_add_key_vdev");
            result = 0;
            goto LABEL_70;
          }
        }
        else if ( v66 == 2 )
        {
          v155 = v25;
          wlan_hdd_mlo_link_add_pairwise_key(a2, v25, a3, a6);
          v78 = 0;
          if ( !a2 )
            goto LABEL_29;
          goto LABEL_26;
        }
        v155 = v25;
        v75 = a2;
        v77 = a3;
        v76 = 0;
LABEL_25:
        v78 = wlan_cfg80211_store_key(v75, v77, v76, (__int64)&v157, a6);
        if ( !a2 )
          goto LABEL_29;
LABEL_26:
        if ( v20 )
        {
          if ( *(_QWORD *)(a2 + 1360) )
          {
            if ( !*v54 )
            {
              v102 = *(unsigned __int8 *)(a2 + 93);
              v103 = v78;
              if ( !wlan_cm_is_vdev_connected(a2, v79, v80, v81, v82, v83, v84, v85, v86)
                || (v78 = v103, (*(_BYTE *)(a2 + 60) & 2) != 0)
                && (is_auth_status_connected = mlo_roam_is_auth_status_connected(
                                                 **(_QWORD **)(v20 + 24),
                                                 *(unsigned __int8 *)(a2 + 168)),
                    v78 = v103,
                    (is_auth_status_connected & 1) != 0) )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: MLO:Defer set keys for link_id %d",
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  v110,
                  v111,
                  "wlan_hdd_mlo_defer_set_keys",
                  v102);
                mlo_defer_set_keys(a2, v102, 1);
                result = 0;
                goto LABEL_70;
              }
            }
          }
        }
LABEL_29:
        v87 = *(_DWORD *)(a2 + 16);
        v88 = v78;
        if ( (!v87 || v87 == 2) && (a4 & 1) == 0 && (mlo_is_set_key_defered(a2, a7) & 1) != 0 )
        {
          result = 0;
          goto LABEL_70;
        }
        param = wlan_crypto_get_param(a2, 4u);
        result = v88;
        if ( v88 )
          goto LABEL_70;
        v90 = osif_nl_to_crypto_cipher_type(*(_DWORD *)(a6 + 28));
        if ( (a4 & 1) != 0 )
          *(double *)&v27 = wma_set_peer_ucast_cipher(&v157, (unsigned int)(1 << v90), param);
        if ( v157 | v158 )
        {
          context = _cds_get_context(
                      71,
                      (__int64)"wlan_hdd_add_key_vdev",
                      *(double *)&v27,
                      v28,
                      v29,
                      v30,
                      v31,
                      v32,
                      v33,
                      v34);
          cdp_peer_flush_frags((__int64)context, v92, v93, v94, v95, v96, v97, v98, v99);
        }
        v100 = *v54;
        if ( *v54 <= 1 )
        {
          if ( v100 )
          {
            if ( v100 != 1 )
            {
LABEL_66:
              if ( v100 != 1 )
                wma_update_set_key(*(unsigned __int8 *)(a2 + 168), a4 & 1, a3, &v157, v90);
              v122 = 0;
              goto LABEL_69;
            }
LABEL_54:
            if ( *((_BYTE *)a8 + 2639) == 1 )
            {
              v101 = "%s: don't need install key during auth";
              goto LABEL_47;
            }
            v123 = *v155;
            LOBYTE(v156) = a3;
            is_multipass_sap = wlan_mlme_is_multipass_sap(v123, *(double *)&v27, v28, v29, v30, v31, v32, v33, v34);
            v125 = a3;
            if ( (is_multipass_sap & 1) != 0 )
            {
              v125 = a3;
              if ( *(_WORD *)(a6 + 24) )
              {
                result = wlan_hdd_add_vlan(a2, a8[34], a6, a3, &v156);
                if ( (result & 0x80000000) != 0 )
                  goto LABEL_70;
                v125 = (unsigned __int8)v156;
              }
            }
            v122 = wlan_hdd_add_key_sap(a8, a4 & 1, v125, v90);
            if ( !v122 )
              goto LABEL_65;
            goto LABEL_69;
          }
        }
        else if ( v100 != 2 )
        {
          if ( v100 != 16 )
          {
            if ( v100 != 3 )
              goto LABEL_66;
            goto LABEL_54;
          }
          cmd = ucfg_nan_send_pasn_peer_create_cmd(*v155, a2, v157 | ((unsigned __int64)v158 << 32), v27);
          if ( cmd )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: PASN peer creation fails %d",
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              "wlan_hdd_add_key_vdev",
              cmd);
            result = 4294967274LL;
            goto LABEL_70;
          }
        }
        v122 = wlan_hdd_add_key_sta(a8, a4 & 1, a3, (__int64)&v157);
        if ( !v122 )
        {
LABEL_65:
          v100 = *v54;
          goto LABEL_66;
        }
LABEL_69:
        v126 = v122;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          *(double *)&v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "wlan_hdd_add_key_vdev");
        result = v126;
        goto LABEL_70;
      }
LABEL_24:
      v75 = a2;
      v76 = (a4 & 1) == 0;
      v77 = a3;
      v155 = v25;
      goto LABEL_25;
    }
    bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a2, 6u);
    if ( bsspeer )
    {
      v35 = bsspeer;
      qdf_mem_copy(&v157, (const void *)(bsspeer + 48), 6u);
      wlan_objmgr_peer_release_ref(v35, 6u, v36, v37, v38, v39, v40, v41, v42, v43);
      if ( !(unsigned int)mlo_get_link_mac_addr_from_reassoc_rsp(a2, &v157) )
      {
LABEL_11:
        v54 = (int *)(v20 + 40);
        goto LABEL_24;
      }
      v44 = wlan_objmgr_vdev_try_get_bsspeer(a2, 6u);
      if ( v44 )
      {
        v45 = v44;
        qdf_mem_copy(&v157, (const void *)(v44 + 48), 6u);
        wlan_objmgr_peer_release_ref(v45, 6u, v46, v47, v48, v49, v50, v51, v52, v53);
        goto LABEL_11;
      }
    }
    else if ( (*(_BYTE *)(a2 + 60) & 2) != 0 && !*(_DWORD *)(v20 + 40) )
    {
      ref = wlan_objmgr_vdev_try_get_ref(a2, 6u, *(double *)&v27, v28, v29, v30, v31, v32, v33, v34);
      if ( ref )
      {
        v136 = ref;
        v137 = "%s: Failed to get vdev ref";
      }
      else
      {
        v136 = wlan_hdd_mlo_copy_partner_addr_from_mlie(a2, (__int64)&v157);
        wlan_objmgr_vdev_release_ref(a2, 6u, v146, v147, v148, v149, v150, v151, v152, v153, v154);
        if ( !v136 )
          goto LABEL_11;
        v137 = "%s: Failed to get peer address from ML IEs";
      }
      qdf_trace_msg(0x33u, 2u, v137, v128, v129, v130, v131, v132, v133, v134, v135, "wlan_hdd_add_key_vdev");
      result = qdf_status_to_os_return(v136);
      goto LABEL_70;
    }
    v101 = "%s: Peer is null return";
LABEL_47:
    qdf_trace_msg(0x33u, 2u, v101, *(double *)&v27, v28, v29, v30, v31, v32, v33, v34, "wlan_hdd_add_key_vdev");
    result = 4294967274LL;
    goto LABEL_70;
  }
  result = sme_add_key_btk(a1, *(unsigned __int8 *)(a2 + 168), *(_QWORD *)a6, *(unsigned int *)(a6 + 16));
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
