__int64 __fastcall lim_set_session_channel_params(__int64 a1, __int64 a2)
{
  unsigned int v4; // w0
  unsigned __int8 *v5; // x24
  int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w25
  int v16; // w22
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
  int v30; // w23
  unsigned int v31; // w1
  unsigned __int16 v32; // w21
  unsigned __int16 v33; // w9
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 result; // x0
  unsigned __int8 v51; // w9
  unsigned __int8 v52; // w8
  __int64 v53; // x0
  __int64 cmpt_obj; // x0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x22
  int v64; // w8
  unsigned int v65; // w10
  char v66; // w9
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  int v91; // w9
  char v92; // w10
  unsigned __int8 v93; // w11
  __int16 v94; // w12
  unsigned __int8 v95; // w10
  unsigned __int8 v96; // w9
  __int16 v97; // w10
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned int v106; // [xsp+48h] [xbp-18h] BYREF
  __int64 v107; // [xsp+4Ch] [xbp-14h]
  int v108; // [xsp+54h] [xbp-Ch]
  __int64 v109; // [xsp+58h] [xbp-8h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 284);
  v108 = 0;
  v5 = (unsigned __int8 *)(a2 + 7020);
  v107 = 0;
  v6 = wlan_reg_freq_to_band(v4);
  v15 = *(_DWORD *)(a2 + 7176);
  v16 = v6;
  v17 = 1 << v6;
  if ( v15 == 4 )
  {
    v15 = 2;
    v5[164] = 0;
    *(_DWORD *)(a2 + 7176) = 2;
  }
  v18 = *(_QWORD *)(a1 + 21560);
  v19 = v5[154];
  v106 = v15;
  v20 = wlan_reg_chan_band_to_freq(v18, v19, v17, v7, v8, v9, v10, v11, v12, v13, v14);
  v29 = v5[164];
  v30 = v20;
  HIDWORD(v107) = v20;
  if ( v29
    && (v108 = wlan_reg_chan_band_to_freq(*(_QWORD *)(a1 + 21560), v29, v17, v21, v22, v23, v24, v25, v26, v27, v28)) != 0
    || v15 != 7 )
  {
    v31 = *(_DWORD *)(a2 + 284);
    v32 = 0;
    if ( !v16 && v15 == 1 )
    {
      v33 = v31 + 20;
      if ( v30 != v31 + 10 )
        v33 = 0;
      if ( v30 == v31 - 10 )
        v32 = v31 - 20;
      else
        v32 = v33;
    }
  }
  else
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
    v31 = *(_DWORD *)(a2 + 284);
    v32 = 0;
    v106 = 3;
  }
  wlan_reg_set_channel_params_for_pwrmode(
    *(_QWORD *)(a1 + 21560),
    v31,
    v32,
    (__int64)&v106,
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
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    "lim_set_session_channel_params",
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned int *)(a2 + 284),
    BYTE1(v107),
    BYTE2(v107),
    v106,
    *(_DWORD *)(a2 + 10048),
    *(unsigned __int16 *)(a2 + 7158),
    *v5,
    *(unsigned __int8 *)(a2 + 251),
    *(unsigned __int8 *)(a2 + 250),
    *((unsigned __int16 *)v5 + 818),
    HIDWORD(v107),
    v108);
  if ( v106 == 8 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: abort vdev start invalid chan parameters",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "lim_set_session_channel_params");
    result = 4;
  }
  else
  {
    v51 = BYTE1(v107);
    *(_DWORD *)(a2 + 7176) = v106;
    v52 = BYTE2(v107);
    v53 = *(_QWORD *)(a2 + 16);
    v5[154] = v51;
    v5[164] = v52;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v53, v42, v43, v44, v45, v46, v47, v48, v49);
    if ( cmpt_obj )
    {
      v63 = *(_QWORD *)(*(_QWORD *)(cmpt_obj + 504) + 40LL);
      v64 = *(_DWORD *)(a2 + 284);
      *(_WORD *)v63 = v64;
      v65 = v106;
      *(_BYTE *)(v63 + 3) = BYTE1(v107);
      v66 = BYTE2(v107);
      *(_DWORD *)(v63 + 24) = v65;
      *(_BYTE *)(v63 + 4) = v66;
      *(_BYTE *)(v63 + 2) = wlan_reg_freq_to_chan(
                              *(_QWORD *)(a1 + 21560),
                              (unsigned __int16)v64,
                              v55,
                              v56,
                              v57,
                              v58,
                              v59,
                              v60,
                              v61,
                              v62);
      if ( *(_DWORD *)(a2 + 88) == 1 )
      {
        wlan_reg_set_non_eht_ch_params();
        wlan_reg_set_input_punc_bitmap();
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 21560),
          *(_DWORD *)(a2 + 284),
          v32,
          (__int64)&v106,
          0,
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: freq0: %d, freq1: %d, width: %d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "lim_update_ap_he_op",
          BYTE1(v107),
          BYTE2(v107),
          v106);
        v91 = *(_DWORD *)(v5 + 1721);
        if ( (v91 & 0x40000) != 0 )
        {
          v95 = v106;
          *(_WORD *)(v5 + 1729) = *(_WORD *)((char *)&v107 + 1);
          v5[1728] = v95;
        }
        else if ( v5[1744] == 1 )
        {
          v92 = v106;
          v93 = v5[1733];
          v94 = *(_WORD *)((char *)&v107 + 1);
          *(_DWORD *)(v5 + 1721) = v91 | 0x200000;
          *((_WORD *)v5 + 867) = v94;
          v5[1733] = v93 & 0xFC | v92 & 3;
        }
        else
        {
          v96 = v106;
          v97 = *(_WORD *)((char *)&v107 + 1);
          v5[2760] = 1;
          v5[2757] = v96;
          *((_WORD *)v5 + 1379) = v97;
        }
        wlan_mlme_set_ap_oper_ch_width(
          *(_QWORD *)(a2 + 16),
          *(_DWORD *)(a2 + 7176),
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90);
        if ( *(_DWORD *)(a2 + 7176) == 7
          && policy_mgr_is_conn_lead_to_bw_downgrade(
               *(_QWORD *)(a1 + 21552),
               *(_BYTE *)(a2 + 10),
               *(_DWORD *)(a2 + 284),
               7u) )
        {
          wlan_mlme_set_ap_oper_ch_width(*(_QWORD *)(a2 + 16), 3u, v98, v99, v100, v101, v102, v103, v104, v105);
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
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "lim_set_session_channel_params");
      result = 16;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
