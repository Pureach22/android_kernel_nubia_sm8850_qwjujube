__int64 *__fastcall hdd_report_max_rate(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        char a12,
        unsigned int a13,
        unsigned int a14,
        int a15,
        unsigned int a16)
{
  __int64 *result; // x0
  __int64 *v24; // x25
  _BOOL4 v25; // w19
  __int64 v26; // x22
  __int64 vdev_by_user; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x27
  __int64 opr_rate; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned __int16 v46; // w23
  unsigned __int16 v47; // w20
  char *v48; // x8
  char v49; // t1
  _WORD *v50; // x7
  unsigned int v51; // w7
  const char *v52; // x2
  __int64 ext_opr_rate; // x28
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 cmpt_obj; // x0
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char *v72; // x4
  char v73; // t1
  _WORD *v74; // x6
  unsigned int v75; // w19
  unsigned int v76; // w22
  unsigned int v77; // w23
  __int64 v78; // x27
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  int v87; // w8
  char v88; // w12
  int v89; // w10
  char v90; // w8
  __int64 mcs_rate; // x0
  char *v92; // x8
  unsigned __int8 v93; // w14
  char v94; // w9
  char v95; // w10
  unsigned __int8 v96; // w11
  char v97; // w10
  __int64 v99; // x9
  unsigned __int8 v100; // w11
  unsigned __int16 v101; // w16
  unsigned __int8 v102; // w15
  char *v103; // x17
  unsigned __int8 v104; // w8
  unsigned int v105; // w8
  int v106; // [xsp+Ch] [xbp-64h]
  __int64 v107; // [xsp+10h] [xbp-60h]
  char v108; // [xsp+18h] [xbp-58h]
  int v109; // [xsp+1Ch] [xbp-54h]
  unsigned int v110; // [xsp+20h] [xbp-50h]
  unsigned int v111; // [xsp+24h] [xbp-4Ch]
  __int64 v112; // [xsp+28h] [xbp-48h] BYREF
  __int64 v113; // [xsp+30h] [xbp-40h] BYREF
  char v114[4]; // [xsp+38h] [xbp-38h] BYREF
  int v115; // [xsp+3Ch] [xbp-34h] BYREF
  _QWORD v116[2]; // [xsp+40h] [xbp-30h] BYREF
  __int64 v117; // [xsp+50h] [xbp-20h] BYREF
  __int64 v118; // [xsp+58h] [xbp-18h] BYREF
  int v119; // [xsp+60h] [xbp-10h]
  __int64 v120; // [xsp+68h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v115 = 0;
  v114[0] = 0;
  v119 = 0;
  v117 = 0;
  v118 = 0;
  v116[0] = 0;
  v116[1] = 0;
  v112 = 0;
  v113 = 0;
  result = _cds_get_context(51, (__int64)"hdd_report_max_rate", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    goto LABEL_169;
  v24 = result;
  ucfg_mlme_stats_get_cfg_values(*result, (_DWORD *)&v113 + 1, &v113, (_DWORD *)&v112 + 1, &v112);
  v111 = a14;
  if ( (ucfg_mlme_stats_is_link_speed_report_max_scaled(*v24) & 1) != 0 && SHIDWORD(v113) > a12 )
  {
    if ( (int)v113 <= a12 )
    {
      v25 = 0;
      v108 = 0;
      v26 = 1;
    }
    else
    {
      v108 = 0;
      v25 = SHIDWORD(v112) > a12;
      if ( SHIDWORD(v112) <= a12 )
        v26 = 2;
      else
        v26 = 3;
    }
  }
  else
  {
    v25 = 0;
    v26 = 0;
    v108 = 1;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 0x51u, (__int64)"hdd_report_max_rate");
  if ( !vdev_by_user )
  {
    v52 = "%s: failed to get vdev";
LABEL_33:
    qdf_trace_msg(0x33u, 2u, v52, v28, v29, v30, v31, v32, v33, v34, v35, "hdd_report_max_rate");
    result = nullptr;
LABEL_169:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v36 = vdev_by_user;
  v109 = a15;
  v110 = a16;
  v107 = a11;
  opr_rate = mlme_get_opr_rate(vdev_by_user, &v118, 0xCu, v28, v29, v30, v31, v32, v33, v34, v35);
  if ( opr_rate )
  {
    if ( (unsigned __int64)(opr_rate - 13) < 0xFFFFFFFFFFFFFFF4LL )
      goto LABEL_171;
    v46 = 0;
    v47 = 0;
    v48 = (char *)&v118;
    do
    {
      v49 = *v48++;
      v50 = &supported_data_rate;
      switch ( v49 & 0x7F )
      {
        case 2:
          goto LABEL_27;
        case 4:
          v50 = &unk_A08C4A;
          goto LABEL_27;
        case 0xB:
          v50 = &unk_A08C54;
          goto LABEL_27;
        case 0xC:
          v50 = &unk_A08C5E;
          goto LABEL_27;
        case 0x12:
          v50 = &unk_A08C68;
          goto LABEL_27;
        case 0x16:
          v50 = &unk_A08C72;
          goto LABEL_27;
        case 0x18:
          v50 = &unk_A08C7C;
          goto LABEL_27;
        case 0x24:
          v50 = &unk_A08C86;
          goto LABEL_27;
        case 0x2C:
          v50 = &unk_A08C90;
          goto LABEL_27;
        case 0x30:
          v50 = &unk_A08C9A;
          goto LABEL_27;
        case 0x42:
          v50 = &unk_A08CA4;
          goto LABEL_27;
        case 0x48:
          v50 = &unk_A08CAE;
          goto LABEL_27;
        case 0x60:
          v50 = &unk_A08CB8;
          goto LABEL_27;
        case 0x6C:
          v50 = &unk_A08CC2;
LABEL_27:
          v46 = v50[v26 + 1];
          break;
        default:
          break;
      }
      v51 = v47;
      v47 = v46;
      if ( v46 <= v51 )
        v47 = v51;
      --opr_rate;
    }
    while ( opr_rate );
  }
  else
  {
    v47 = 0;
    v46 = 0;
  }
  ext_opr_rate = mlme_get_ext_opr_rate(v36, &v117, 8u, v38, v39, v40, v41, v42, v43, v44, v45);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v36, v54, v55, v56, v57, v58, v59, v60, v61);
  if ( cmpt_obj )
  {
    v63 = (unsigned int *)*(unsigned __int16 *)(cmpt_obj + 264);
    v106 = *(unsigned __int16 *)(cmpt_obj + 264);
  }
  else
  {
    v106 = 0;
  }
  _hdd_objmgr_put_vdev_by_user(v36, 0x51u, (__int64)"hdd_report_max_rate", v63, v64, v65, v66, v67, v68, v69, v70, v71);
  if ( ext_opr_rate )
  {
    if ( (unsigned __int64)(ext_opr_rate - 9) < 0xFFFFFFFFFFFFFFF8LL )
      goto LABEL_171;
    v72 = (char *)&v117;
    do
    {
      v73 = *v72++;
      v74 = &supported_data_rate;
      switch ( v73 & 0x7F )
      {
        case 2:
          goto LABEL_55;
        case 4:
          v74 = &unk_A08C4A;
          goto LABEL_55;
        case 0xB:
          v74 = &unk_A08C54;
          goto LABEL_55;
        case 0xC:
          v74 = &unk_A08C5E;
          goto LABEL_55;
        case 0x12:
          v74 = &unk_A08C68;
          goto LABEL_55;
        case 0x16:
          v74 = &unk_A08C72;
          goto LABEL_55;
        case 0x18:
          v74 = &unk_A08C7C;
          goto LABEL_55;
        case 0x24:
          v74 = &unk_A08C86;
          goto LABEL_55;
        case 0x2C:
          v74 = &unk_A08C90;
          goto LABEL_55;
        case 0x30:
          v74 = &unk_A08C9A;
          goto LABEL_55;
        case 0x42:
          v74 = &unk_A08CA4;
          goto LABEL_55;
        case 0x48:
          v74 = &unk_A08CAE;
          goto LABEL_55;
        case 0x60:
          v74 = &unk_A08CB8;
          goto LABEL_55;
        case 0x6C:
          v74 = &unk_A08CC2;
LABEL_55:
          v46 = v74[v26 + 1];
          break;
        default:
          break;
      }
      if ( v46 > (unsigned int)v47 )
        v47 = v46;
      --ext_opr_rate;
    }
    while ( ext_opr_rate );
  }
  if ( ((a13 | v25) & 1) != 0 )
  {
    v76 = v109;
    v75 = v110;
    if ( (a13 & 1) != 0 )
    {
      v77 = 0;
    }
    else
    {
      v47 = v109;
      v77 = v111;
    }
LABEL_164:
    v105 = (unsigned __int16)v76;
    if ( v47 > (unsigned int)(unsigned __int16)v76 )
      v105 = v47;
    if ( v47 )
      v76 = v105;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: RLMS %u, rate_flags 0x%x, max_rate %d mcs %d nss %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_report_max_rate",
      (unsigned int)v112,
      a13,
      (unsigned __int16)v76,
      (unsigned __int8)v77,
      (unsigned __int8)v75);
    wlan_hdd_fill_os_rate_info(a13, v76, v107, v77, v75, 0, 0);
    result = (__int64 *)(&off_0 + 1);
    goto LABEL_169;
  }
  v76 = v109;
  v75 = v110;
  if ( (a13 & 0x39C80) != 0 )
    v78 = 2;
  else
    v78 = (a13 & 0x4244) != 0;
  if ( (a13 & 0x3FFE0) == 0 )
  {
    mcs_rate = mlme_get_mcs_rate(*(_QWORD *)(a1 + 32), v116, 0x10u, v28, v29, v30, v31, v32, v33, v34, v35);
    if ( mcs_rate )
    {
      v92 = (char *)&supported_mcs_rate_nss1_0;
      if ( (unsigned __int8)v110 != 1 )
        v92 = (char *)&supported_mcs_rate_nss2_0;
      if ( (v108 & 1) != 0 )
      {
        v93 = 8;
      }
      else if ( rssi_mcs_tbl[14 * (unsigned int)v78] >= a12 )
      {
        v93 = 1;
      }
      else
      {
        if ( ((56 * v78) | 4uLL) > 0xA8 )
          goto LABEL_172;
        if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 1] >= a12 )
        {
          v93 = 2;
        }
        else if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 2] >= a12 )
        {
          v93 = 3;
        }
        else if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 3] >= a12 )
        {
          v93 = 4;
        }
        else if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 4] >= a12 )
        {
          v93 = 5;
        }
        else if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 5] >= a12 )
        {
          v93 = 6;
        }
        else if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 6] >= a12 )
        {
          v93 = 7;
        }
        else
        {
          v93 = 8;
        }
      }
      if ( (unsigned __int64)(mcs_rate - 17) >= 0xFFFFFFFFFFFFFFF0LL )
      {
        v76 = v109;
        v75 = v110;
        v99 = 0;
        v100 = 0;
        do
        {
          v102 = 0;
          while ( 1 )
          {
            v103 = &v92[10 * v102];
            if ( *v103 == *((_BYTE *)v116 + v99) )
              break;
            if ( v93 <= (unsigned int)++v102 )
              goto LABEL_149;
          }
          v46 = *(_WORD *)&v103[2 * ((a13 >> 2) & 3) + 2];
          v100 = *((_BYTE *)v116 + v99);
LABEL_149:
          v101 = v47;
          ++v99;
          if ( v46 > (unsigned int)v47 )
            v101 = v46;
          if ( (v102 & 0xF8) == 0 )
            v47 = v101;
        }
        while ( v99 != mcs_rate );
        if ( (unsigned __int8)v110 == 2 )
          v104 = v100 + 8;
        else
          v104 = v100;
        if ( v104 <= (unsigned int)(unsigned __int8)v111 )
          v77 = (unsigned __int8)v111;
        else
          v77 = v104;
        goto LABEL_164;
      }
LABEL_171:
      __break(0x5512u);
      goto LABEL_172;
    }
    v52 = "%s: Failed to get current mcs rate set";
    goto LABEL_33;
  }
  if ( (unsigned int)wlan_mlme_cfg_get_vht_tx_mcs_map(*v24, &v115) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to get tx_mcs_map",
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      "hdd_report_max_rate");
  if ( (unsigned int)wlan_mlme_get_vht20_mcs9(*v24, v114) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get VHT20 MCS9 enable val",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_report_max_rate");
  v87 = v115 & 3;
  if ( (v115 & 3) != 0 )
  {
    v88 = v108;
    v89 = v106;
    if ( v87 == 2 )
    {
      if ( ((a13 & 0x20) == 0) | v114[0] & 1 )
        v90 = 9;
      else
        v90 = 8;
    }
    else if ( v87 == 1 )
    {
      v90 = 8;
    }
    else
    {
      v90 = 0;
    }
  }
  else
  {
    v88 = v108;
    v89 = v106;
    v90 = 7;
  }
  if ( (a13 & 0x3E000) != 0 )
    v90 = 13;
  if ( v89 )
    v94 = 13;
  else
    v94 = 11;
  if ( (a13 & 0xF00) != 0 )
    v95 = v94;
  else
    v95 = v90;
  v96 = v95;
  if ( (v88 & 1) != 0 )
    goto LABEL_95;
  v96 = 0;
  if ( rssi_mcs_tbl[14 * (unsigned int)v78] >= a12 || !v95 )
    goto LABEL_95;
  if ( ((56 * v78) | 4uLL) <= 0xA8 )
  {
    v96 = 1;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 1] >= a12 )
      goto LABEL_95;
    v97 = v95 + 1;
    if ( v97 == 2 )
      goto LABEL_95;
    v96 = 2;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 2] >= a12 )
      goto LABEL_95;
    if ( v97 == 3 )
      goto LABEL_95;
    v96 = 3;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 3] >= a12 )
      goto LABEL_95;
    if ( v97 == 4 )
      goto LABEL_95;
    v96 = 4;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 4] >= a12 )
      goto LABEL_95;
    if ( v97 == 5 )
      goto LABEL_95;
    v96 = 5;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 5] >= a12 )
      goto LABEL_95;
    if ( v97 == 6 )
      goto LABEL_95;
    v96 = 6;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 6] >= a12 )
      goto LABEL_95;
    if ( v97 == 7 )
      goto LABEL_95;
    v96 = 7;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 7] >= a12 )
      goto LABEL_95;
    if ( v97 == 8 )
      goto LABEL_95;
    v96 = 8;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 8] >= a12 )
      goto LABEL_95;
    if ( v97 == 9 )
      goto LABEL_95;
    v96 = 9;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 9] >= a12 || v97 == 10 )
      goto LABEL_95;
    v96 = 10;
    if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 10] < a12 )
    {
      v76 = v109;
      v75 = v110;
      if ( v97 == 11 )
        goto LABEL_95;
      v96 = 11;
      if ( rssi_mcs_tbl[14 * (unsigned int)v78 + 11] < a12 )
      {
        v76 = v109;
        v75 = v110;
        if ( v97 != 12 )
        {
          if ( v97 != 13 && rssi_mcs_tbl[14 * (unsigned int)v78 + 12] < a12 )
            v96 = 13;
          else
            v96 = 12;
        }
        goto LABEL_95;
      }
    }
    v76 = v109;
    v75 = v110;
LABEL_95:
    if ( v96 <= (unsigned int)(unsigned __int8)v111 )
      v77 = (unsigned __int8)v111;
    else
      v77 = v96;
    goto LABEL_164;
  }
LABEL_172:
  __break(1u);
  return (__int64 *)((__int64 (*)(void))wlan_hdd_fill_os_rate_info)();
}
