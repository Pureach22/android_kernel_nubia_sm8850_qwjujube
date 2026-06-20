__int64 __fastcall policy_mgr_get_preferred_dbs_action_table(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4)
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
  __int64 v17; // x25
  char is_2x2_5G_1x1_2G_dbs_capable; // w22
  char is_2x2_2G_1x1_5G_dbs_capable; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 result; // x0
  int v37; // w28
  __int64 v38; // x8
  int v39; // w22
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned int v41; // w24
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  const char *v66; // x2
  unsigned int v67; // w25
  bool v68; // cc
  unsigned int v69; // w8
  unsigned int v70; // w27
  unsigned int mode_specific_conn_info; // w26
  bool v72; // zf
  char v73; // w23
  bool is_5ghz_ch_freq; // w19
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  char v83; // w8
  int v84; // [xsp+8h] [xbp-28h] BYREF
  __int16 v85; // [xsp+Ch] [xbp-24h]
  __int64 v86; // [xsp+10h] [xbp-20h] BYREF
  __int64 v87; // [xsp+18h] [xbp-18h]
  __int64 v88; // [xsp+20h] [xbp-10h]
  __int64 v89; // [xsp+28h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v87 = 0;
  v88 = 0;
  v86 = 0;
  v85 = 0;
  v84 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid context",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "policy_mgr_get_preferred_dbs_action_table");
    result = 0;
    goto LABEL_76;
  }
  v17 = context;
  is_2x2_5G_1x1_2G_dbs_capable = policy_mgr_is_2x2_5G_1x1_2G_dbs_capable(a1);
  is_2x2_2G_1x1_5G_dbs_capable = policy_mgr_is_2x2_2G_1x1_5G_dbs_capable(a1);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: target support DBS1 %d DBS2 %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "policy_mgr_get_preferred_dbs_action_table",
    is_2x2_5G_1x1_2G_dbs_capable & 1,
    is_2x2_2G_1x1_5G_dbs_capable & 1);
  if ( (is_2x2_5G_1x1_2G_dbs_capable & 1) == 0 && (is_2x2_2G_1x1_5G_dbs_capable & 1) == 0 )
  {
    result = 0;
    goto LABEL_76;
  }
  if ( (is_2x2_5G_1x1_2G_dbs_capable & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: target only supports DBS2!",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "policy_mgr_get_preferred_dbs_action_table");
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: band_pref_5g %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "policy_mgr_get_preferred_dbs_action_table",
      0);
    goto LABEL_17;
  }
  if ( (is_2x2_2G_1x1_5G_dbs_capable & 1) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: target only supports DBS1!",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "policy_mgr_get_preferred_dbs_action_table");
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: band_pref_5g %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "policy_mgr_get_preferred_dbs_action_table",
      1);
    goto LABEL_75;
  }
  v37 = *(_DWORD *)(v17 + 2220);
  if ( (v37 & 2) == 0 )
    goto LABEL_74;
  v38 = v17;
  if ( !*(_DWORD *)(v17 + 2224) )
    goto LABEL_74;
  v39 = 7;
  if ( a2 != 255 && a3 )
  {
    v40 = *(__int64 (__fastcall **)(_QWORD))(v17 + 312);
    if ( v40 )
    {
      if ( *((_DWORD *)v40 - 1) != -228160499 )
        __break(0x8228u);
      v41 = v40(a2);
    }
    else
    {
      v41 = 17;
    }
    v39 = policy_mgr_qdf_opmode_to_pm_con_mode(a1, v41, a2);
    if ( v39 == 7 )
      v66 = "%s: new vdev %d op_mode %d freq %d reason %d: not prioritized";
    else
      v66 = "%s: new vdev %d op_mode %d freq %d : reason %d";
    qdf_trace_msg(
      0x4Fu,
      8u,
      v66,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "policy_mgr_get_preferred_dbs_action_table",
      a2,
      v41,
      a3,
      a4);
    v38 = v17;
  }
  v67 = *(_DWORD *)(v38 + 2224);
  if ( !v67 )
    goto LABEL_74;
  while ( 1 )
  {
    v69 = (v67 & 0xF) - 1;
    if ( v69 >= 4 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: vdev_pri_id %d prioritization not supported",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "policy_mgr_get_preferred_dbs_action_table");
      goto LABEL_27;
    }
    v70 = dword_A2FAA8[v69];
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, &v86, &v84, v70);
    if ( !mode_specific_conn_info )
    {
      v73 = 0;
      goto LABEL_59;
    }
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: [%d] vdev %d chan %d conn_mode %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "policy_mgr_get_preferred_dbs_action_table",
      0,
      (unsigned __int8)v84,
      (unsigned int)v86,
      v70);
    v72 = v39 == v70 && (unsigned __int8)v84 == a2;
    v73 = v72;
    if ( v72 )
      LODWORD(v86) = a3;
    if ( mode_specific_conn_info != 1 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: [%d] vdev %d chan %d conn_mode %d",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "policy_mgr_get_preferred_dbs_action_table",
        1,
        BYTE1(v84),
        HIDWORD(v86),
        v70);
      if ( v39 == v70 && BYTE1(v84) == a2 )
      {
        v73 = 1;
        HIDWORD(v86) = a3;
      }
      if ( mode_specific_conn_info != 2 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: [%d] vdev %d chan %d conn_mode %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "policy_mgr_get_preferred_dbs_action_table",
          2,
          BYTE2(v84),
          (unsigned int)v87,
          v70);
        if ( v39 == v70 && BYTE2(v84) == a2 )
        {
          v73 = 1;
          LODWORD(v87) = a3;
        }
        if ( mode_specific_conn_info != 3 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: [%d] vdev %d chan %d conn_mode %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "policy_mgr_get_preferred_dbs_action_table",
            3,
            HIBYTE(v84),
            HIDWORD(v87),
            v70);
          if ( v39 == v70 && HIBYTE(v84) == a2 )
          {
            v73 = 1;
            HIDWORD(v87) = a3;
          }
          if ( mode_specific_conn_info != 4 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: [%d] vdev %d chan %d conn_mode %d",
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              "policy_mgr_get_preferred_dbs_action_table",
              4,
              (unsigned __int8)v85,
              (unsigned int)v88,
              v70);
            if ( v39 == v70 && (unsigned __int8)v85 == a2 )
            {
              v73 = 1;
              LODWORD(v88) = a3;
            }
            if ( mode_specific_conn_info != 5 )
              break;
          }
        }
      }
    }
LABEL_59:
    if ( v39 == v70 && (v73 & 1) == 0 )
    {
      *((_DWORD *)&v86 + mode_specific_conn_info) = a3;
      *((_BYTE *)&v84 + mode_specific_conn_info++) = a2;
    }
    if ( mode_specific_conn_info > 1 )
      goto LABEL_74;
    if ( mode_specific_conn_info == 1 )
    {
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v86);
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: band_pref_5g %d",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        "policy_mgr_get_preferred_dbs_action_table",
        is_5ghz_ch_freq);
      if ( !is_5ghz_ch_freq )
        goto LABEL_17;
      goto LABEL_75;
    }
LABEL_27:
    v68 = v67 > 0xF;
    v67 >>= 4;
    if ( !v68 )
      goto LABEL_74;
  }
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: [%d] vdev %d chan %d conn_mode %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "policy_mgr_get_preferred_dbs_action_table",
    5,
    HIBYTE(v85),
    HIDWORD(v88),
    v70);
  if ( v39 == v70 && HIBYTE(v85) == a2 )
  {
    v73 = 1;
    HIDWORD(v88) = a3;
  }
  if ( v39 == v70 )
    v83 = v73;
  else
    v83 = 1;
  if ( mode_specific_conn_info != 6 || (v83 & 1) == 0 )
  {
    __break(0x5512u);
    return policy_mgr_get_connection_table_entry_info();
  }
LABEL_74:
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: band_pref_5g %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "policy_mgr_get_preferred_dbs_action_table",
    !(v37 & 1));
  if ( (v37 & 1) == 0 )
  {
LABEL_75:
    result = 10;
    goto LABEL_76;
  }
LABEL_17:
  result = 12;
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
