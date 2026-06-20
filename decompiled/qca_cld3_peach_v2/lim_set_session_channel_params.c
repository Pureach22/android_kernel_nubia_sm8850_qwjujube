__int64 __fastcall lim_set_session_channel_params(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned __int8 *v5; // x25
  int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w26
  int v16; // w23
  int v17; // w21
  __int64 v18; // x0
  unsigned int v19; // w1
  int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w1
  int v30; // w24
  unsigned int v31; // w22
  unsigned int v32; // w21
  int v33; // w8
  unsigned int v34; // w10
  bool v35; // zf
  int v36; // w9
  unsigned int v37; // w8
  unsigned __int16 v38; // w23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 result; // x0
  unsigned int v65; // w0
  unsigned int v66; // w2
  unsigned __int16 v67; // w1
  unsigned int v68; // w9
  unsigned __int8 v69; // w10
  __int64 v70; // x0
  unsigned __int8 v71; // w8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 cmpt_obj; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x22
  int v90; // w8
  unsigned int v91; // w10
  char v92; // w9
  __int16 v93; // w1
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  int v118; // w9
  char v119; // w10
  unsigned __int8 v120; // w11
  __int16 v121; // w12
  unsigned __int8 v122; // w10
  unsigned __int8 v123; // w9
  __int16 v124; // w10
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  int v133; // [xsp+4Ch] [xbp-24h] BYREF
  __int64 v134; // [xsp+50h] [xbp-20h]
  __int64 v135; // [xsp+58h] [xbp-18h]
  int v136; // [xsp+60h] [xbp-10h]
  unsigned __int16 v137; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v138; // [xsp+68h] [xbp-8h]

  v138 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 284);
  v136 = 0;
  v5 = (unsigned __int8 *)(a2 + 7020);
  v134 = 0;
  v135 = 0;
  v6 = wlan_reg_freq_to_band(v4);
  v15 = *(_DWORD *)(a2 + 7176);
  v16 = v6;
  v17 = 1 << v6;
  if ( v15 == 4 )
  {
    v15 = 2;
    v5[166] = 0;
    *(_DWORD *)(a2 + 7176) = 2;
  }
  v18 = *(_QWORD *)(a1 + 21632);
  v19 = v5[154];
  v133 = v15;
  v20 = wlan_reg_chan_band_to_freq(v18, v19, v17, v7, v8, v9, v10, v11, v12, v13, v14);
  v29 = v5[166];
  v30 = v20;
  HIDWORD(v134) = v20;
  if ( v29 )
  {
    v31 = wlan_reg_chan_band_to_freq(*(_QWORD *)(a1 + 21632), v29, v17, v21, v22, v23, v24, v25, v26, v27, v28);
    LODWORD(v135) = v31;
    if ( v31 )
      goto LABEL_9;
  }
  else
  {
    v31 = 0;
  }
  if ( v15 == 7 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Downgrade ch_width to 160MHz",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_set_session_channel_params");
    v32 = 0;
    v133 = 3;
    goto LABEL_16;
  }
LABEL_9:
  v32 = 0;
  if ( !v16 && v15 == 1 )
  {
    v33 = *(_DWORD *)(a2 + 284);
    v34 = v33 + 20;
    v35 = v30 == v33 + 10;
    v36 = v33 - 10;
    v37 = v33 - 20;
    if ( !v35 )
      v34 = 0;
    if ( v30 == v36 )
      v32 = v37;
    else
      v32 = v34;
  }
LABEL_16:
  if ( *(_DWORD *)(a2 + 88) == 1 )
  {
    v38 = *(_WORD *)(a2 + 7184);
    if ( v38 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Apply puncture to reg: bitmap 0x%x, freq: %d, bw %d, mhz_freq_seg1: %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "lim_apply_puncture",
        *(unsigned __int16 *)(a2 + 7184),
        *(unsigned int *)(a2 + 284),
        *(unsigned int *)(a2 + 7176),
        v31);
      wlan_reg_apply_puncture(
        *(_QWORD *)(a1 + 21632),
        v38,
        *(_DWORD *)(a2 + 284),
        *(_DWORD *)(a2 + 7176),
        v31,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46);
    }
  }
  v47 = *(unsigned __int8 *)(a2 + 154);
  if ( v47 <= 0xD
    && ((1 << v47) & 0x3001) != 0
    && (*(_DWORD *)(a2 + 88) != 2 || (v5[3145] & 2) != 0 && *(_WORD *)(v5 + 3153)) )
  {
    wlan_reg_set_create_punc_bitmap((__int64)&v133, 1);
  }
  wlan_reg_set_channel_params_for_pwrmode(
    *(_QWORD *)(a1 + 21632),
    *(_DWORD *)(a2 + 284),
    v32,
    (__int64)&v133,
    0,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: vdev id %d freq %d seg0 %d seg1 %d ch_width %d cac_duration_ms %d beacon_interval %d hidden_ssid: %d dtimPeriod "
    "%d slot_time %d bcn tx rate %d mhz seg0 %d mhz seg1 %d",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "lim_set_session_channel_params",
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned int *)(a2 + 284),
    BYTE1(v134),
    BYTE2(v134),
    v133,
    *(_DWORD *)(a2 + 10048),
    *(unsigned __int16 *)(a2 + 7158),
    *v5,
    *(unsigned __int8 *)(a2 + 251),
    *(unsigned __int8 *)(a2 + 250),
    *((unsigned __int16 *)v5 + 818),
    HIDWORD(v134),
    v135);
  if ( v133 == 8 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: abort vdev start invalid chan parameters",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "lim_set_session_channel_params");
    result = 4;
  }
  else
  {
    v65 = *(_DWORD *)(a2 + 7176);
    v66 = *(_DWORD *)(a2 + 284);
    v67 = *(_WORD *)(a2 + 7184);
    v137 = 0;
    wlan_reg_extract_puncture_by_bw(v65, v67, v66, v135, v133, &v137, v56, v57, v58, v59, v60, v61, v62, v63);
    v68 = v133;
    v69 = BYTE1(v134);
    v70 = *(_QWORD *)(a2 + 16);
    HIWORD(v135) = v137;
    *(_WORD *)(a2 + 7184) = v137;
    v71 = BYTE2(v134);
    *(_DWORD *)(a2 + 7176) = v68;
    v5[154] = v69;
    v5[166] = v71;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v70, v72, v73, v74, v75, v76, v77, v78, v79);
    if ( cmpt_obj )
    {
      v89 = *(_QWORD *)(*(_QWORD *)(cmpt_obj + 520) + 40LL);
      v90 = *(_DWORD *)(a2 + 284);
      *(_WORD *)v89 = v90;
      v91 = v133;
      *(_BYTE *)(v89 + 3) = BYTE1(v134);
      v92 = BYTE2(v134);
      *(_DWORD *)(v89 + 24) = v91;
      *(_BYTE *)(v89 + 4) = v92;
      *(_BYTE *)(v89 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(a1 + 21632),
                              (unsigned __int16)v90,
                              v81,
                              v82,
                              v83,
                              v84,
                              v85,
                              v86,
                              v87,
                              v88);
      *(_WORD *)(v89 + 32) = HIWORD(v135);
      if ( *(_DWORD *)(a2 + 88) == 1 )
      {
        wlan_reg_set_create_punc_bitmap((__int64)&v133, 0);
        wlan_reg_set_non_eht_ch_params((__int64)&v133, 1);
        v93 = 0;
        if ( (v5[3145] & 2) != 0 )
          v93 = *(_WORD *)(v5 + 3153);
        wlan_reg_set_input_punc_bitmap((__int64)&v133, v93);
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 21632),
          *(_DWORD *)(a2 + 284),
          v32,
          (__int64)&v133,
          0,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          v101);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: freq0: %d, freq1: %d, width: %d",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "lim_update_ap_he_op",
          BYTE1(v134),
          BYTE2(v134),
          (unsigned int)v133);
        v118 = *(_DWORD *)(v5 + 1721);
        if ( (v118 & 0x40000) != 0 )
        {
          v122 = v133;
          *(_WORD *)(v5 + 1729) = *(_WORD *)((char *)&v134 + 1);
          v5[1728] = v122;
        }
        else if ( v5[1744] == 1 )
        {
          v119 = v133;
          v120 = v5[1733];
          v121 = *(_WORD *)((char *)&v134 + 1);
          *(_DWORD *)(v5 + 1721) = v118 | 0x200000;
          *((_WORD *)v5 + 867) = v121;
          v5[1733] = v120 & 0xFC | v119 & 3;
        }
        else
        {
          v123 = v133;
          v124 = *(_WORD *)((char *)&v134 + 1);
          v5[2760] = 1;
          v5[2757] = v123;
          *((_WORD *)v5 + 1379) = v124;
        }
        wlan_mlme_set_ap_oper_ch_width(
          *(_QWORD *)(a2 + 16),
          *(_DWORD *)(a2 + 7176),
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117);
        if ( *(_DWORD *)(a2 + 7176) == 7
          && policy_mgr_is_conn_lead_to_bw_downgrade(
               *(_QWORD *)(a1 + 21624),
               *(_BYTE *)(a2 + 10),
               *(_DWORD *)(a2 + 284),
               7u) )
        {
          wlan_mlme_set_ap_oper_ch_width(*(_QWORD *)(a2 + 16), 3u, v125, v126, v127, v128, v129, v130, v131, v132);
        }
      }
      result = 0;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: vdev component object is NULL",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "lim_set_session_channel_params");
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
