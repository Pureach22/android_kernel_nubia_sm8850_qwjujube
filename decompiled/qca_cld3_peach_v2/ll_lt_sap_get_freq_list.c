__int64 __fastcall ll_lt_sap_get_freq_list(__int64 a1, unsigned int *a2, unsigned int a3, unsigned int a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x22
  __int64 v18; // x26
  __int64 v19; // x0
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x25
  unsigned int user_config_acs_ch_list; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int pcl_ch_list_for_ll_sap; // w24
  __int64 v40; // x0
  __int64 v41; // x22
  int v42; // w27
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x28
  unsigned __int64 v52; // x24
  unsigned int *v53; // x8
  unsigned int v54; // w25
  unsigned int v55; // w23
  unsigned int v56; // w0
  unsigned int v57; // w26
  unsigned int *v58; // x8
  __int64 v59; // x9
  bool v60; // zf
  unsigned int v61; // w8
  unsigned int v62; // w25
  bool is_5ghz_ch_freq; // w0
  unsigned int v64; // w10
  bool v65; // w0
  unsigned int *v66; // x8
  __int64 v67; // x9
  unsigned int v68; // w26
  unsigned int *v69; // x8
  unsigned int v70; // w26
  _QWORD *scan_result; // x26
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v81; // [xsp+74h] [xbp-8Ch]
  unsigned int v82; // [xsp+74h] [xbp-8Ch]
  unsigned int v83; // [xsp+74h] [xbp-8Ch]
  unsigned int v84; // [xsp+74h] [xbp-8Ch]
  _DWORD *v85; // [xsp+78h] [xbp-88h]
  unsigned int v86; // [xsp+84h] [xbp-7Ch]
  _DWORD *v87; // [xsp+88h] [xbp-78h]
  _DWORD *v88; // [xsp+90h] [xbp-70h]
  _DWORD *v89; // [xsp+98h] [xbp-68h]
  _DWORD *v90; // [xsp+A0h] [xbp-60h]
  unsigned int sbs_cut_off_freq; // [xsp+ACh] [xbp-54h]
  __int64 v92; // [xsp+B0h] [xbp-50h] BYREF
  __int64 v93; // [xsp+B8h] [xbp-48h]
  char v94[4]; // [xsp+C4h] [xbp-3Ch] BYREF
  __int64 v95; // [xsp+C8h] [xbp-38h] BYREF
  __int64 v96; // [xsp+D0h] [xbp-30h]
  __int64 v97; // [xsp+D8h] [xbp-28h]
  __int64 v98; // [xsp+E0h] [xbp-20h]
  __int64 v99; // [xsp+E8h] [xbp-18h]
  __int64 v100; // [xsp+F0h] [xbp-10h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v92 = 0;
  v93 = 0;
  v8 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 105);
  if ( !v8 )
  {
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: Invalid vdev for vdev_id %d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "ll_lt_sap_get_sorted_user_config_acs_ch_list",
      (unsigned __int8)a3);
    goto LABEL_103;
  }
  v17 = v8;
  v18 = *(_QWORD *)(v8 + 216);
  v19 = _qdf_mem_malloc(0x2D8u, "ll_lt_sap_get_sorted_user_config_acs_ch_list", 121);
  if ( v19 )
  {
    v29 = v19;
    user_config_acs_ch_list = wlan_sap_get_user_config_acs_ch_list();
    if ( user_config_acs_ch_list )
    {
      pcl_ch_list_for_ll_sap = user_config_acs_ch_list;
      qdf_trace_msg(
        0xA1u,
        2u,
        "%s: vdev %d failed to get user config acs ch_list",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "ll_lt_sap_get_sorted_user_config_acs_ch_list",
        (unsigned __int8)a3);
      _qdf_mem_free(v29);
    }
    else
    {
      scan_result = scm_get_scan_result(v18, v29, v31, v32, v33, v34, v35, v36, v37, v38);
      _qdf_mem_free(v29);
      if ( scan_result )
      {
        pcl_ch_list_for_ll_sap = wlan_ll_sap_sort_channel_list(a3, (__int64)scan_result, (__int64)&v92);
        if ( pcl_ch_list_for_ll_sap )
          qdf_trace_msg(
            0xA1u,
            2u,
            "%s: vdev %d failed to sort sap channel list",
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            "ll_lt_sap_get_sorted_user_config_acs_ch_list",
            (unsigned __int8)a3);
        else
          scm_purge_scan_results((__int64)scan_result, v72, v73, v74, v75, v76, v77, v78, v79);
      }
      else
      {
        pcl_ch_list_for_ll_sap = 0;
      }
    }
  }
  else
  {
    pcl_ch_list_for_ll_sap = 16;
  }
  wlan_objmgr_vdev_release_ref(v17, 0x69u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
  if ( pcl_ch_list_for_ll_sap || !(_BYTE)v93 )
    goto LABEL_109;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v95 = 0;
  v94[0] = 0;
  v40 = _qdf_mem_malloc(0x204u, "ll_lt_sap_get_allowed_freq_list", 594);
  if ( !v40 )
    goto LABEL_103;
  v41 = v40;
  ll_lt_store_to_avoid_list_and_flush_old(a1, a2[13], a4);
  pcl_ch_list_for_ll_sap = policy_mgr_get_pcl_ch_list_for_ll_sap(a1, v41, a3, (__int64)&v95, v94);
  if ( pcl_ch_list_for_ll_sap )
  {
LABEL_108:
    _qdf_mem_free(v41);
    goto LABEL_109;
  }
  v42 = (unsigned __int8)v94[0];
  sbs_cut_off_freq = policy_mgr_get_sbs_cut_off_freq(a1);
  if ( !(_BYTE)v93 )
  {
LABEL_107:
    qdf_trace_msg(
      0xA1u,
      8u,
      "%s: vdev %d, best %d[%d] Shared: low %d[%d] high %d[%d] 6Ghz %d[%d], Standalone: low %d[%d] high %d[%d] 6Ghz %d[%d"
      "], prev %d, existing connection cnt %d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "ll_lt_sap_update_freq_list",
      (unsigned __int8)a3,
      a2[12],
      a2[14],
      a2[6],
      a2[9],
      a2[7],
      a2[10],
      a2[8],
      a2[11],
      *a2,
      a2[3],
      a2[1],
      a2[4],
      a2[2],
      a2[5],
      a2[13],
      v42);
    pcl_ch_list_for_ll_sap = 0;
    goto LABEL_108;
  }
  v51 = 0;
  v85 = a2 + 2;
  v52 = 0;
  v86 = sbs_cut_off_freq - 1;
  v89 = a2 + 7;
  v90 = a2 + 6;
  v87 = a2 + 1;
  v88 = a2 + 8;
  while ( 1 )
  {
    v53 = (unsigned int *)(v92 + v51);
    if ( *(_BYTE *)(v92 + v51 + 20) == 1 )
    {
      v54 = *v53;
      if ( a2[13] != *v53 )
      {
        v55 = v53[3];
        if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_ll_sap_freq_present_in_pcl)(v41, v54) & 1) != 0 )
        {
          if ( !a2[12] )
          {
            a2[12] = v54;
            a2[14] = v55;
          }
          if ( !v42 )
            goto LABEL_107;
          if ( v55 <= 0x4E20 )
            break;
        }
      }
    }
LABEL_13:
    ++v52;
    v51 += 24;
    if ( v52 >= (unsigned __int8)v93 )
      goto LABEL_107;
  }
  if ( v54 == HIDWORD(v95) )
    goto LABEL_22;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v54, HIDWORD(v95)) & 1) != 0 )
  {
    if ( (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, BYTE1(v95)) == 1 )
      goto LABEL_22;
    v56 = 0;
    v57 = v54;
  }
  else
  {
    v57 = 0;
    v56 = v54;
  }
  if ( v42 == 1 )
    goto LABEL_34;
  if ( v54 == HIDWORD(v96) )
    goto LABEL_22;
  v81 = v56;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v54, HIDWORD(v96)) & 1) != 0 )
  {
    v60 = (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, BYTE1(v96)) == 1;
    v56 = v81;
    if ( v60 )
      goto LABEL_22;
    v61 = v54;
    if ( v57 )
      goto LABEL_22;
  }
  else
  {
    v56 = v81;
    v61 = v57;
    if ( !v81 )
      v56 = v54;
  }
  if ( v42 == 2 )
    goto LABEL_62;
  if ( v54 == HIDWORD(v97) )
    goto LABEL_22;
  v68 = v56;
  v82 = v61;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v54, HIDWORD(v97)) & 1) != 0 )
  {
    if ( (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, BYTE1(v97)) == 1 )
      goto LABEL_22;
    v56 = v68;
    v57 = v54;
    if ( v82 )
      goto LABEL_22;
  }
  else
  {
    if ( v68 )
      v56 = v68;
    else
      v56 = v54;
    v57 = v82;
  }
  if ( v42 == 3 )
    goto LABEL_34;
  if ( v54 == HIDWORD(v98) )
    goto LABEL_22;
  v83 = v56;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v54, HIDWORD(v98)) & 1) != 0 )
  {
    v60 = (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, BYTE1(v98)) == 1;
    v56 = v83;
    if ( v60 )
      goto LABEL_22;
    v61 = v54;
    if ( v57 )
      goto LABEL_22;
  }
  else
  {
    v56 = v83;
    v61 = v57;
    if ( !v83 )
      v56 = v54;
  }
  if ( v42 == 4 )
  {
LABEL_62:
    v57 = v61;
LABEL_34:
    if ( !v57 )
    {
      if ( !v56 )
        goto LABEL_22;
      v62 = v56;
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v56);
      v64 = v62;
      if ( is_5ghz_ch_freq && v86 >= v62 && !*a2 )
      {
        *a2 = v62;
        a2[3] = v55;
        if ( sbs_cut_off_freq )
          goto LABEL_22;
        v66 = a2 + 1;
        v67 = 4;
      }
      else
      {
        v65 = wlan_reg_is_5ghz_ch_freq(v62);
        v64 = v62;
        if ( v65 && v62 > sbs_cut_off_freq && !*v87 )
        {
          a2[1] = v62;
          a2[4] = v55;
          if ( sbs_cut_off_freq )
            goto LABEL_22;
          v66 = a2;
          v67 = 3;
        }
        else
        {
          if ( !wlan_reg_is_6ghz_chan_freq(v62) || *v85 )
            goto LABEL_22;
          v66 = a2 + 2;
          v64 = v62;
          v67 = 5;
        }
      }
      *v66 = v64;
      v69 = &a2[v67];
      goto LABEL_88;
    }
    if ( wlan_reg_is_5ghz_ch_freq(v57) && v86 >= v57 && !*v90 )
    {
      a2[6] = v57;
      a2[9] = v55;
      if ( sbs_cut_off_freq )
      {
LABEL_23:
        if ( *v89 && *v88 && *a2 && *v87 && *v85 )
          goto LABEL_107;
        goto LABEL_13;
      }
      v58 = a2 + 7;
      v59 = 4;
      goto LABEL_72;
    }
    if ( wlan_reg_is_5ghz_ch_freq(v57) && v57 > sbs_cut_off_freq && !*v89 )
    {
      a2[7] = v57;
      a2[10] = v55;
      if ( sbs_cut_off_freq )
        goto LABEL_22;
      v58 = a2 + 6;
      v59 = 3;
      goto LABEL_72;
    }
    if ( wlan_reg_is_6ghz_chan_freq(v57) && !*v88 )
    {
      v58 = a2 + 8;
      v59 = 5;
LABEL_72:
      *v58 = v57;
      v69 = &v90[v59];
LABEL_88:
      *v69 = v55;
    }
LABEL_22:
    if ( !*v90 )
      goto LABEL_13;
    goto LABEL_23;
  }
  if ( v54 == HIDWORD(v99) )
    goto LABEL_22;
  v70 = v56;
  v84 = v61;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v54, HIDWORD(v99)) & 1) != 0 )
  {
    if ( (unsigned int)policy_mgr_get_mode_by_vdev_id(a1, BYTE1(v99)) == 1 )
      goto LABEL_22;
    v56 = v70;
    if ( v84 )
      goto LABEL_22;
  }
  else
  {
    if ( v70 )
      v56 = v70;
    else
      v56 = v54;
    v54 = v84;
  }
  v57 = v54;
  if ( v42 == 5 )
    goto LABEL_34;
  __break(1u);
LABEL_103:
  pcl_ch_list_for_ll_sap = 16;
LABEL_109:
  wlan_ll_sap_free_chan_info();
  _ReadStatusReg(SP_EL0);
  return pcl_ch_list_for_ll_sap;
}
