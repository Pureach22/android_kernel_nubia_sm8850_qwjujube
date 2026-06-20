__int64 __fastcall lim_send_he_caps_ie(__int64 a1, int a2, unsigned int a3)
{
  _QWORD *v6; // x22
  char v7; // w23
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 v16; // x8
  int v17; // w26
  unsigned int v18; // w8
  unsigned int v19; // w8
  char v20; // w0
  unsigned int v21; // w8
  unsigned int v22; // w21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x0
  unsigned int v42; // w22
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x23
  char force_20mhz_in_24ghz; // w24
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned int v71; // w8
  unsigned int v72; // w9
  unsigned int v73; // w19
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v83; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v84[7]; // [xsp+8h] [xbp-48h] BYREF
  char v85; // [xsp+40h] [xbp-10h]
  __int64 v86; // [xsp+48h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (_QWORD *)(a1 + 21797);
  v85 = 0;
  memset(v84, 0, sizeof(v84));
  BYTE4(v83) = 0;
  LOBYTE(v83) = 0;
  qdf_mem_set(v84, 0x20u, 0);
  LOWORD(v84[0]) = 5631;
  qdf_mem_copy((char *)v84 + 2, "#", 1u);
  lim_set_he_caps(a1, v84, 32, 2);
  v7 = (a2 != 11) | ucfg_nan_is_beamforming_supported(*(_QWORD *)(a1 + 21624));
  if ( (v7 & 1) != 0 )
  {
    v16 = *(_QWORD *)((char *)v6 + 60);
    *(_QWORD *)((char *)v84 + 7) = *(_QWORD *)((char *)v84 + 7) & 0xC703FFFFFFFFFFFFLL
                                 | (((v16 >> 19) & 7) << 50)
                                 | (v16 << 29) & 0x38E0000000000000LL;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: he_cap_5g: bfee_sts_gt_80 %d num_sounding_gt_80 %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "lim_send_he_caps_ie",
      BYTE3(v16) & 7,
      (v16 >> 30) & 7);
    if ( (v84[1] & 0x8000000000000000LL) != 0 )
      goto LABEL_3;
  }
  else
  {
    *(_QWORD *)((char *)v84 + 7) &= 0x7FFFFFFFFFFFuLL;
    if ( (v84[1] & 0x8000000000000000LL) != 0 )
    {
LABEL_3:
      v17 = (unsigned __int8)lim_set_he_caps_ppet(a1, v84, 2) + 1;
      if ( a2 > 1 )
        goto LABEL_4;
LABEL_10:
      if ( !a2 )
        goto LABEL_13;
      if ( a2 != 1 )
        goto LABEL_22;
LABEL_18:
      wlan_twt_get_responder_cfg(*(_QWORD *)(a1 + 21624), &v83);
      v20 = wlan_twt_check_responder_bit(*(_QWORD *)(a1 + 21624), a3, (unsigned int)a2, (unsigned __int8)v83);
      v21 = *(_DWORD *)((char *)v84 + 3);
      if ( (v20 & 1) == 0 )
        v21 = *(_DWORD *)((_BYTE *)v84 + 3) & 0xBFFFFFF9;
      v19 = v21 & 0xFFFFFFFD;
      goto LABEL_21;
    }
  }
  v17 = 1;
  if ( a2 <= 1 )
    goto LABEL_10;
LABEL_4:
  if ( a2 == 3 )
  {
    if ( !wlan_vdev_p2p_is_wfd_r2_mode(*(_QWORD *)(a1 + 21624), a3, v8, v9, v10, v11, v12, v13, v14, v15) )
      goto LABEL_22;
    goto LABEL_18;
  }
  if ( a2 == 2 && wlan_vdev_p2p_is_wfd_r2_mode(*(_QWORD *)(a1 + 21624), a3, v8, v9, v10, v11, v12, v13, v14, v15) )
  {
LABEL_13:
    ucfg_twt_cfg_get_requestor(*(_QWORD *)(a1 + 21624), (char *)&v83 + 4);
    if ( BYTE4(v83) )
      v18 = *(_DWORD *)((char *)v84 + 3);
    else
      v18 = *(_DWORD *)((_BYTE *)v84 + 3) & 0xBFFFFFF9;
    v19 = v18 & 0xFFFFFFFB;
LABEL_21:
    *(_DWORD *)((char *)v84 + 3) = v19;
  }
LABEL_22:
  v22 = lim_send_ie((unsigned __int8)a3, 255, 2, (char *)v84 + 2, v17 + (unsigned int)BYTE1(v84[0]));
  if ( v22 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Unable send HE Cap IE for 5GHZ band, status: %d",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "lim_send_he_caps_ie",
      v22);
  qdf_mem_set(v84, 0x20u, 0);
  LOWORD(v84[0]) = 5631;
  qdf_mem_copy((char *)v84 + 2, "#", 1u);
  lim_set_he_caps(a1, v84, 32, 1);
  if ( (v7 & 1) != 0 )
  {
    v39 = BYTE3(*v6) & 7;
    v40 = (*v6 >> 30) & 7LL;
    *(_QWORD *)((char *)v84 + 7) = *(_QWORD *)((char *)v84 + 7) & 0xC703FFFFFFFFFFFFLL
                                 | (((*v6 >> 19) & 7LL) << 50)
                                 | (*v6 << 29) & 0x38E0000000000000LL;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: he_cap_2g: bfee_sts_gt_80 %d num_sounding_gt_80 %d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_send_he_caps_ie",
      v39,
      v40);
  }
  v41 = *(_QWORD *)(a1 + 21624);
  if ( v41 )
  {
    v42 = *(unsigned __int8 *)(a1 + 17192);
    v43 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v41, a3, 1);
    if ( v43
      && (v52 = v43,
          force_20mhz_in_24ghz = wlan_cm_get_force_20mhz_in_24ghz(v43, v44, v45, v46, v47, v48, v49, v50, v51),
          wlan_objmgr_vdev_release_ref(v52, 1u, v54, v55, v56, v57, v58, v59, v60, v61, v62),
          (force_20mhz_in_24ghz & 1) != 0) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: channel bonding mode 2.4GHz %d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_intersect_he_ch_width_2g",
        0);
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: channel bonding mode 2.4GHz %d",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "lim_intersect_he_ch_width_2g",
        v42,
        v83);
      if ( v42 )
      {
        v71 = *(_DWORD *)((char *)v84 + 7);
        v72 = *(_DWORD *)((char *)&v84[1] + 7);
LABEL_33:
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: HE cap: chan_width: 0x%07x he_ppdu_20_in_40Mhz_2G %d",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "lim_intersect_he_ch_width_2g",
          (v71 >> 17) & 0x7F,
          (v72 >> 17) & 1,
          v83);
        goto LABEL_34;
      }
    }
    v71 = *(_DWORD *)((_BYTE *)v84 + 7) & 0xFFFDFFFF;
    v72 = *(_DWORD *)((_BYTE *)&v84[1] + 7) & 0xFFFDFFFF;
    *(_QWORD *)((char *)v84 + 7) &= ~0x20000uLL;
    *(_DWORD *)((char *)&v84[1] + 7) &= ~0x20000u;
    goto LABEL_33;
  }
LABEL_34:
  if ( (v84[1] & 0x8000000000000000LL) != 0 )
    v17 = (unsigned __int8)lim_set_he_caps_ppet(a1, v84, 1) + 1;
  v73 = lim_send_ie((unsigned __int8)a3, 255, 1, (char *)v84 + 2, v17 + (unsigned int)BYTE1(v84[0]));
  if ( v73 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Unable send HE Cap IE for 2GHZ band, status: %d",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "lim_send_he_caps_ie",
      v73);
  _ReadStatusReg(SP_EL0);
  return 16 * (unsigned int)((v73 | v22) != 0);
}
