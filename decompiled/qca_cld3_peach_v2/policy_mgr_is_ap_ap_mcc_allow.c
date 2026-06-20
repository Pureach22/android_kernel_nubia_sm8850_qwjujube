bool __fastcall policy_mgr_is_ap_ap_mcc_allow(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        _BYTE *a6,
        unsigned int *a7)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 context; // x0
  unsigned int mode_specific_conn_info; // w28
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w23
  const char *v33; // x2
  unsigned int v34; // w1
  _BOOL8 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int64 v44; // x24
  int v45; // w8
  unsigned int v46; // w26
  unsigned int v47; // w27
  __int64 v48; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x27
  unsigned int v58; // w21
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x21
  unsigned int v69; // w26
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  int v78; // w0
  __int64 v79; // x22
  int v80; // w27
  unsigned __int64 v81; // x23
  char v82; // w5
  __int64 v83; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x21
  unsigned int v93; // w22
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  unsigned int v102; // w8
  unsigned int *v103; // x21
  _BYTE *v104; // x8
  int v105; // w8
  __int64 v106; // x26
  unsigned int *v107; // x8
  __int64 assoc_link_vdev; // x0
  unsigned int v109; // w24
  unsigned int bw; // w0
  int conc_ml_sap_link_freq; // w20
  char *v112; // [xsp+0h] [xbp-300h]
  unsigned int v113; // [xsp+40h] [xbp-2C0h]
  unsigned int v114; // [xsp+44h] [xbp-2BCh]
  _BYTE *v115; // [xsp+48h] [xbp-2B8h]
  unsigned int *v116; // [xsp+50h] [xbp-2B0h]
  __int64 v117; // [xsp+60h] [xbp-2A0h]
  __int64 v118; // [xsp+68h] [xbp-298h]
  bool v119; // [xsp+74h] [xbp-28Ch]
  _BYTE v120[4]; // [xsp+78h] [xbp-288h] BYREF
  _DWORD s[129]; // [xsp+7Ch] [xbp-284h] BYREF
  __int64 v122; // [xsp+280h] [xbp-80h] BYREF
  __int16 v123; // [xsp+288h] [xbp-78h]
  __int64 v124; // [xsp+290h] [xbp-70h] BYREF
  __int16 v125; // [xsp+298h] [xbp-68h]
  __int64 v126; // [xsp+2A0h] [xbp-60h] BYREF
  __int64 v127; // [xsp+2A8h] [xbp-58h] BYREF
  __int64 v128; // [xsp+2B0h] [xbp-50h] BYREF
  __int64 v129; // [xsp+2B8h] [xbp-48h] BYREF
  __int64 v130; // [xsp+2C0h] [xbp-40h] BYREF
  __int64 v131; // [xsp+2C8h] [xbp-38h] BYREF
  __int64 v132; // [xsp+2D0h] [xbp-30h]
  __int64 v133; // [xsp+2D8h] [xbp-28h]
  __int64 v134; // [xsp+2E0h] [xbp-20h]
  __int64 v135; // [xsp+2E8h] [xbp-18h]
  __int64 v136; // [xsp+2F0h] [xbp-10h]

  v136 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v128 = 0;
  v129 = 0;
  v126 = 0;
  v127 = 0;
  v125 = 0;
  v124 = 0;
  v123 = 0;
  v122 = 0;
  memset(s, 0, sizeof(s));
  v120[0] = 0;
  if ( !a2 || !a1 || !a3 )
  {
    v33 = "%s: psoc or vdev or pdev is NULL";
LABEL_13:
    v34 = 8;
LABEL_15:
    qdf_trace_msg(0x4Fu, v34, v33, v14, v15, v16, v17, v18, v19, v20, v21, "policy_mgr_is_ap_ap_mcc_allow", v112);
LABEL_16:
    result = 0;
    goto LABEL_98;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v33 = "%s: Invalid Context";
    v34 = 2;
    goto LABEL_15;
  }
  v117 = context;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                              a1,
                              (unsigned __int64)&v131,
                              (unsigned __int64)&v124,
                              1u);
  if ( mode_specific_conn_info < 5 )
  {
    mode_specific_conn_info += policy_mgr_get_mode_specific_conn_info(
                                 a1,
                                 (unsigned __int64)&v131 + 4 * mode_specific_conn_info,
                                 (unsigned __int64)&v124 + mode_specific_conn_info,
                                 3u);
    if ( !mode_specific_conn_info )
      goto LABEL_97;
  }
  v32 = *(_DWORD *)(a3 + 16);
  if ( v32 <= 1 )
  {
    if ( !v32 )
      goto LABEL_24;
    if ( v32 == 1 )
    {
      if ( (policy_mgr_is_vdev_ll_lt_sap(a1, *(unsigned __int8 *)(a3 + 168)) & 1) != 0 )
        v32 = 6;
      else
        v32 = 1;
      goto LABEL_24;
    }
    goto LABEL_22;
  }
  if ( (unsigned int)(v32 - 2) >= 2 )
  {
    if ( v32 == 11 )
    {
      v32 = 4;
      goto LABEL_24;
    }
    if ( v32 == 16 )
    {
      v32 = 5;
      goto LABEL_24;
    }
LABEL_22:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Unsupported mode (%d)",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "policy_mgr_qdf_opmode_to_pm_con_mode",
      (unsigned int)v32);
    v32 = 7;
  }
LABEL_24:
  qdf_mem_set(s, 0x204u, 0);
  ((void (__fastcall *)(__int64, _QWORD, _DWORD *, _DWORD *, _DWORD *, __int64, _QWORD))policy_mgr_get_pcl)(
    a1,
    (unsigned int)v32,
    s,
    &s[128],
    &s[102],
    102,
    *(unsigned __int8 *)(a3 + 168));
  if ( !s[128] )
    goto LABEL_97;
  v113 = v32;
  v114 = a5;
  v115 = a6;
  v116 = a7;
  v44 = 0;
  v118 = a3;
  v119 = 0;
  v112 = (char *)&v130 + 4;
  do
  {
    if ( v44 == 102 )
      goto LABEL_148;
    v45 = s[v44];
    if ( (_DWORD)v131 == v45 )
    {
      v46 = 0;
    }
    else
    {
      if ( mode_specific_conn_info < 2 )
        goto LABEL_27;
      if ( HIDWORD(v131) == v45 )
      {
        v46 = 1;
      }
      else
      {
        if ( mode_specific_conn_info == 2 )
          goto LABEL_27;
        if ( (_DWORD)v132 == v45 )
        {
          v46 = 2;
        }
        else
        {
          if ( mode_specific_conn_info == 3 )
            goto LABEL_27;
          if ( HIDWORD(v132) == v45 )
          {
            v46 = 3;
          }
          else
          {
            if ( mode_specific_conn_info == 4 )
              goto LABEL_27;
            if ( (_DWORD)v133 == v45 )
            {
              v46 = 4;
            }
            else
            {
              if ( mode_specific_conn_info == 5 )
                goto LABEL_27;
              if ( HIDWORD(v133) == v45 )
              {
                v46 = 5;
              }
              else
              {
                if ( mode_specific_conn_info == 6 )
                  goto LABEL_27;
                if ( (_DWORD)v134 == v45 )
                {
                  v46 = 6;
                }
                else
                {
                  if ( mode_specific_conn_info == 7 )
                    goto LABEL_27;
                  if ( HIDWORD(v134) == v45 )
                  {
                    v46 = 7;
                  }
                  else
                  {
                    if ( mode_specific_conn_info == 8 )
                      goto LABEL_27;
                    if ( (_DWORD)v135 == v45 )
                    {
                      v46 = 8;
                    }
                    else
                    {
                      if ( mode_specific_conn_info == 9 )
                        goto LABEL_27;
                      if ( HIDWORD(v135) != v45 )
                      {
                        if ( mode_specific_conn_info != 10 )
                          goto LABEL_148;
                        goto LABEL_27;
                      }
                      v46 = 9;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ( v45 == a4 )
      goto LABEL_76;
    if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
      goto LABEL_76;
    if ( (wlan_reg_is_same_band_freqs(a4, *((_DWORD *)&v131 + v46)) & 1) != 0 )
    {
      v47 = *((_DWORD *)&v131 + v46);
      if ( (policy_mgr_is_hw_sbs_capable(a1) & 1) == 0
        || wlan_reg_is_24ghz_ch_freq(a4)
        || wlan_reg_is_24ghz_ch_freq(v47)
        || (policy_mgr_2_freq_same_mac_in_sbs(a1, a4, v47) & 1) != 0 )
      {
        goto LABEL_76;
      }
    }
    if ( (wlan_reg_is_same_band_freqs(a4, *((_DWORD *)&v131 + v46)) & 1) != 0 )
    {
      v48 = policy_mgr_get_context(a1);
      if ( v48 )
      {
        v57 = v48;
        qdf_mutex_acquire(v48 + 56);
        v58 = BYTE4(qword_8D4F24)
            + BYTE4(qword_8D4F00)
            + BYTE4(qword_8D4F48)
            + BYTE4(qword_8D4F6C)
            + BYTE4(qword_8D4F90);
        qdf_mutex_release(v57 + 56);
        if ( v58 > 2 )
          goto LABEL_76;
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          "policy_mgr_get_connection_count");
      }
    }
    v59 = policy_mgr_get_context(a1);
    if ( v59 )
    {
      v68 = v59;
      qdf_mutex_acquire(v59 + 56);
      v69 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
      qdf_mutex_release(v68 + 56);
      if ( v69 >= 3 && !v119 )
        v119 = s[v44] == a4;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "policy_mgr_get_connection_count");
    }
LABEL_27:
    ++v44;
  }
  while ( v44 < s[128] );
  v46 = mode_specific_conn_info;
LABEL_76:
  if ( (wlan_vdev_mlme_is_mlo_vdev(v118, v36, v37, v38, v39, v40, v41, v42, v43) & 1) == 0 )
  {
    if ( mode_specific_conn_info >= 5 && v46 < mode_specific_conn_info )
    {
      if ( v46 <= 9 )
      {
        v82 = *((_BYTE *)&v124 + v46);
        *v116 = *((_DWORD *)&v131 + v46);
        *v115 = v82;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: con freq %d con vdev %d",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "policy_mgr_is_ap_ap_mcc_allow",
          *v116);
        goto LABEL_16;
      }
LABEL_148:
      __break(0x5512u);
    }
    v83 = policy_mgr_get_context(a1);
    if ( v83 )
    {
      v92 = v83;
      qdf_mutex_acquire(v83 + 56);
      v93 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
      qdf_mutex_release(v92 + 56);
      if ( v119 )
        v102 = v46;
      else
        v102 = 0;
      if ( v93 > 2 )
        v46 = v102;
      if ( v46 >= mode_specific_conn_info )
        goto LABEL_97;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "policy_mgr_get_connection_count");
      if ( v46 >= mode_specific_conn_info )
        goto LABEL_97;
    }
    if ( v46 > 9 )
      goto LABEL_148;
    v103 = v116;
    v104 = (char *)&v124 + v46;
    *v116 = *((_DWORD *)&v131 + v46);
LABEL_134:
    *v115 = *v104;
    if ( *(_DWORD *)(v118 + 16) || (wlan_vdev_mlme_is_mlo_vdev(v118, v94, v95, v96, v97, v98, v99, v100, v101) & 1) == 0 )
    {
      v109 = 0;
    }
    else if ( (*(_BYTE *)(v118 + 60) & 2) != 0 && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v118)) != 0 )
    {
      if ( ucfg_cm_is_vdev_active(assoc_link_vdev, v94, v95, v96, v97, v98, v99, v100, v101) )
        v109 = 3;
      else
        v109 = 1;
    }
    else
    {
      v109 = 1;
    }
    bw = policy_mgr_get_bw(v114, v94, v95, v96, v97, v98, v99, v100, v101);
    if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
            a1,
            v113,
            a4,
            bw,
            v109,
            *(unsigned __int8 *)(v118 + 168))
        & 1) != 0 )
    {
      if ( *v103 != a4 || (unsigned __int16)wlan_reg_get_bw_value(v114) <= 0x14u )
      {
        qdf_mutex_acquire(v117 + 56);
        conc_ml_sap_link_freq = policy_mgr_get_conc_ml_sap_link_freq(a1, *(_BYTE *)(v118 + 168), v120);
        qdf_mutex_release(v117 + 56);
        result = conc_ml_sap_link_freq != a4;
        goto LABEL_98;
      }
      goto LABEL_16;
    }
    v33 = "%s: AP AP mcc not allowed, try to override 2nd SAP/GO chan";
    goto LABEL_13;
  }
  v78 = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)&v126, (unsigned __int64)&v122, 0);
  if ( v78 )
  {
    v79 = v46 >= mode_specific_conn_info ? 0LL : v46;
    if ( s[128] )
    {
      v80 = v78;
      v81 = 0;
      while ( 1 )
      {
        if ( v81 == 102 )
          goto LABEL_148;
        v105 = s[v81];
        if ( (_DWORD)v126 == v105 )
        {
          v106 = 0;
          v107 = (unsigned int *)&v126;
        }
        else
        {
          if ( v80 == 1 )
            goto LABEL_100;
          if ( HIDWORD(v126) == v105 )
          {
            v107 = (unsigned int *)&v126 + 1;
            v106 = 1;
          }
          else
          {
            if ( v80 == 2 )
              goto LABEL_100;
            if ( (_DWORD)v127 == v105 )
            {
              v107 = (unsigned int *)&v127;
              v106 = 2;
            }
            else
            {
              if ( v80 == 3 )
                goto LABEL_100;
              if ( HIDWORD(v127) == v105 )
              {
                v107 = (unsigned int *)&v127 + 1;
                v106 = 3;
              }
              else
              {
                if ( v80 == 4 )
                  goto LABEL_100;
                if ( (_DWORD)v128 == v105 )
                {
                  v107 = (unsigned int *)&v128;
                  v106 = 4;
                }
                else
                {
                  if ( v80 == 5 )
                    goto LABEL_100;
                  if ( HIDWORD(v128) == v105 )
                  {
                    v107 = (unsigned int *)&v128 + 1;
                    v106 = 5;
                  }
                  else
                  {
                    if ( v80 == 6 )
                      goto LABEL_100;
                    if ( (_DWORD)v129 == v105 )
                    {
                      v107 = (unsigned int *)&v129;
                      v106 = 6;
                    }
                    else
                    {
                      if ( v80 == 7 )
                        goto LABEL_100;
                      if ( HIDWORD(v129) == v105 )
                      {
                        v107 = (unsigned int *)&v129 + 1;
                        v106 = 7;
                      }
                      else
                      {
                        if ( v80 == 8 )
                          goto LABEL_100;
                        if ( (_DWORD)v130 == v105 )
                        {
                          v107 = (unsigned int *)&v130;
                          v106 = 8;
                        }
                        else
                        {
                          if ( v80 == 9 )
                            goto LABEL_100;
                          if ( HIDWORD(v130) != v105 )
                          {
                            if ( v80 != 10 )
                              goto LABEL_148;
                            goto LABEL_100;
                          }
                          v107 = (unsigned int *)&v130 + 1;
                          v106 = 9;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        if ( (unsigned int)v79 > 9 )
          goto LABEL_148;
        if ( (wlan_reg_is_same_band_freqs(*v107, *((_DWORD *)&v131 + v79)) & 1) == 0 )
        {
          v103 = v116;
          *v116 = *((_DWORD *)&v126 + v106);
          v104 = (char *)&v122 + v106;
          goto LABEL_134;
        }
LABEL_100:
        ++v81;
        result = 1;
        if ( v81 >= s[128] )
          goto LABEL_98;
      }
    }
  }
LABEL_97:
  result = 1;
LABEL_98:
  _ReadStatusReg(SP_EL0);
  return result;
}
