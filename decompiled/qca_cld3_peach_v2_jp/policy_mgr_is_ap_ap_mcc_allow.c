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
  unsigned int mode_specific_conn_info; // w26
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w22
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
  __int64 v44; // x22
  int v45; // w8
  unsigned int v46; // w25
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
  unsigned int v58; // w24
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x24
  unsigned int v69; // w25
  char v70; // w5
  __int64 v71; // x0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x22
  unsigned int v81; // w23
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  unsigned int v90; // w8
  char v91; // w9
  unsigned int bw; // w0
  int conc_ml_sap_link_freq; // w20
  unsigned int v94; // [xsp+8h] [xbp-278h]
  unsigned int v95; // [xsp+Ch] [xbp-274h]
  __int64 v96; // [xsp+10h] [xbp-270h]
  _BYTE *v97; // [xsp+18h] [xbp-268h]
  unsigned int *v98; // [xsp+20h] [xbp-260h]
  bool v99; // [xsp+2Ch] [xbp-254h]
  _BYTE v100[4]; // [xsp+30h] [xbp-250h] BYREF
  _DWORD s[129]; // [xsp+34h] [xbp-24Ch] BYREF
  __int64 v102; // [xsp+238h] [xbp-48h] BYREF
  __int16 v103; // [xsp+240h] [xbp-40h]
  __int64 v104; // [xsp+248h] [xbp-38h] BYREF
  __int64 v105; // [xsp+250h] [xbp-30h]
  __int64 v106; // [xsp+258h] [xbp-28h]
  __int64 v107; // [xsp+260h] [xbp-20h]
  __int64 v108; // [xsp+268h] [xbp-18h]
  __int64 v109; // [xsp+270h] [xbp-10h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v107 = 0;
  v108 = 0;
  v105 = 0;
  v106 = 0;
  v104 = 0;
  v103 = 0;
  v102 = 0;
  memset(s, 0, sizeof(s));
  v100[0] = 0;
  if ( !a2 || !a1 || !a3 )
  {
    v33 = "%s: psoc or vdev or pdev is NULL";
LABEL_13:
    v34 = 8;
LABEL_15:
    qdf_trace_msg(0x4Fu, v34, v33, v14, v15, v16, v17, v18, v19, v20, v21, "policy_mgr_is_ap_ap_mcc_allow");
    goto LABEL_16;
  }
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v33 = "%s: Invalid Context";
    v34 = 2;
    goto LABEL_15;
  }
  v96 = context;
  v97 = a6;
  v98 = a7;
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                              a1,
                              (unsigned __int64)&v104,
                              (unsigned __int64)&v102,
                              1u);
  if ( mode_specific_conn_info < 5 )
  {
    mode_specific_conn_info += policy_mgr_get_mode_specific_conn_info(
                                 a1,
                                 (unsigned __int64)&v104 + 4 * mode_specific_conn_info,
                                 (unsigned __int64)&v102 + mode_specific_conn_info,
                                 3u);
    if ( !mode_specific_conn_info )
      goto LABEL_91;
  }
  v32 = *(_DWORD *)(a3 + 16);
  if ( v32 <= 1 )
  {
    if ( !v32 )
      goto LABEL_24;
    if ( v32 == 1 )
    {
      if ( (policy_mgr_is_vdev_ll_lt_sap(a1, *(unsigned __int8 *)(a3 + 104)) & 1) != 0 )
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
    *(unsigned __int8 *)(a3 + 104));
  if ( !s[128] )
    goto LABEL_91;
  v94 = v32;
  v95 = a5;
  v44 = 0;
  v99 = 0;
  while ( 1 )
  {
    if ( v44 == 102 )
      goto LABEL_94;
    v45 = s[v44];
    if ( (_DWORD)v104 == v45 )
    {
      v46 = 0;
      goto LABEL_31;
    }
    if ( mode_specific_conn_info >= 2 )
    {
      if ( HIDWORD(v104) == v45 )
      {
        v46 = 1;
        goto LABEL_31;
      }
      if ( mode_specific_conn_info != 2 )
      {
        if ( (_DWORD)v105 == v45 )
        {
          v46 = 2;
          goto LABEL_31;
        }
        if ( mode_specific_conn_info != 3 )
        {
          if ( HIDWORD(v105) == v45 )
          {
            v46 = 3;
            goto LABEL_31;
          }
          if ( mode_specific_conn_info != 4 )
          {
            if ( (_DWORD)v106 == v45 )
            {
              v46 = 4;
              goto LABEL_31;
            }
            if ( mode_specific_conn_info != 5 )
            {
              if ( HIDWORD(v106) == v45 )
              {
                v46 = 5;
                goto LABEL_31;
              }
              if ( mode_specific_conn_info != 6 )
              {
                if ( (_DWORD)v107 == v45 )
                {
                  v46 = 6;
                  goto LABEL_31;
                }
                if ( mode_specific_conn_info != 7 )
                {
                  if ( HIDWORD(v107) == v45 )
                  {
                    v46 = 7;
                    goto LABEL_31;
                  }
                  if ( mode_specific_conn_info != 8 )
                  {
                    if ( (_DWORD)v108 == v45 )
                    {
                      v46 = 8;
                      goto LABEL_31;
                    }
                    if ( mode_specific_conn_info != 9 )
                      break;
                  }
                }
              }
            }
          }
        }
      }
    }
LABEL_27:
    if ( ++v44 >= (unsigned __int64)s[128] )
    {
      v46 = mode_specific_conn_info;
      goto LABEL_78;
    }
  }
  if ( HIDWORD(v108) != v45 )
  {
    if ( mode_specific_conn_info != 10 )
      goto LABEL_94;
    goto LABEL_27;
  }
  v46 = 9;
LABEL_31:
  if ( v45 != a4 && (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
  {
    if ( (wlan_reg_is_same_band_freqs(a4, *((_DWORD *)&v104 + v46)) & 1) == 0
      || (v47 = *((_DWORD *)&v104 + v46), (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0)
      && !wlan_reg_is_24ghz_ch_freq(a4)
      && !wlan_reg_is_24ghz_ch_freq(v47)
      && (policy_mgr_2_freq_same_mac_in_sbs(a1, a4, v47) & 1) == 0 )
    {
      if ( (wlan_reg_is_same_band_freqs(a4, *((_DWORD *)&v104 + v46)) & 1) != 0 )
      {
        v48 = policy_mgr_get_context(a1);
        if ( v48 )
        {
          v57 = v48;
          qdf_mutex_acquire(v48 + 56);
          v58 = BYTE4(qword_81C47C)
              + BYTE4(qword_81C458)
              + BYTE4(qword_81C4A0)
              + BYTE4(qword_81C4C4)
              + BYTE4(qword_81C4E8);
          qdf_mutex_release(v57 + 56);
          if ( v58 > 2 )
            goto LABEL_75;
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
        v69 = BYTE4(qword_81C47C)
            + BYTE4(qword_81C458)
            + BYTE4(qword_81C4A0)
            + BYTE4(qword_81C4C4)
            + BYTE4(qword_81C4E8);
        qdf_mutex_release(v68 + 56);
        if ( v69 >= 3 && !v99 )
          v99 = s[v44] == a4;
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
      goto LABEL_27;
    }
  }
LABEL_75:
  if ( mode_specific_conn_info >= 5 )
  {
    v70 = *((_BYTE *)&v102 + v46);
    *v98 = *((_DWORD *)&v104 + v46);
    *a6 = v70;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: con freq %d con vdev %d",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "policy_mgr_is_ap_ap_mcc_allow",
      *v98);
    goto LABEL_16;
  }
LABEL_78:
  v71 = policy_mgr_get_context(a1);
  if ( !v71 )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      "policy_mgr_get_connection_count");
    if ( v46 < mode_specific_conn_info )
      goto LABEL_85;
    goto LABEL_91;
  }
  v80 = v71;
  qdf_mutex_acquire(v71 + 56);
  v81 = BYTE4(qword_81C47C) + BYTE4(qword_81C458) + BYTE4(qword_81C4A0) + BYTE4(qword_81C4C4) + BYTE4(qword_81C4E8);
  qdf_mutex_release(v80 + 56);
  v90 = v99 ? v46 : 0;
  if ( v81 > 2 )
    v46 = v90;
  if ( v46 >= mode_specific_conn_info )
  {
LABEL_91:
    result = 1;
    goto LABEL_92;
  }
LABEL_85:
  if ( v46 > 9 )
LABEL_94:
    __break(0x5512u);
  v91 = *((_BYTE *)&v102 + v46);
  *v98 = *((_DWORD *)&v104 + v46);
  *v97 = v91;
  bw = policy_mgr_get_bw(v95, v82, v83, v84, v85, v86, v87, v88, v89);
  if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
          a1,
          v94,
          a4,
          bw,
          0,
          *(unsigned __int8 *)(a3 + 104))
      & 1) == 0 )
  {
    v33 = "%s: AP AP mcc not allowed, try to override 2nd SAP/GO chan";
    goto LABEL_13;
  }
  if ( *v98 != a4 || (unsigned __int16)wlan_reg_get_bw_value(v95) <= 0x14u )
  {
    qdf_mutex_acquire(v96 + 56);
    conc_ml_sap_link_freq = policy_mgr_get_conc_ml_sap_link_freq(a1, *(_BYTE *)(a3 + 104), v100);
    qdf_mutex_release(v96 + 56);
    result = conc_ml_sap_link_freq != a4;
    goto LABEL_92;
  }
LABEL_16:
  result = 0;
LABEL_92:
  _ReadStatusReg(SP_EL0);
  return result;
}
