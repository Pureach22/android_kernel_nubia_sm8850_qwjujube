unsigned __int16 *__fastcall wlan_dcs_process_awgn_sap(unsigned __int16 *result, __int64 a2, unsigned int *a3)
{
  unsigned int v4; // w20
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w27
  __int64 v15; // x5
  unsigned int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x0
  __int64 v26; // x23
  __int64 v27; // x22
  __int64 v28; // x26
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  unsigned int v39; // w0
  _DWORD *v40; // x25
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w21
  __int64 v50; // x8
  _DWORD *v51; // x8
  unsigned __int64 v52; // x27
  int v53; // w28
  unsigned int v54; // w26
  __int64 v55; // x24
  unsigned int v56; // w23
  unsigned int v58; // w25
  int v59; // w26
  unsigned int v60; // w27
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w10
  unsigned int v78; // w8
  const char *v79; // x2
  unsigned int v80; // w8
  unsigned int v81; // w8
  unsigned int v82; // w8
  unsigned int v83; // w8
  int v84; // w9
  unsigned int v85; // w11
  unsigned int v86; // w11
  unsigned int v87; // w11
  unsigned int v88; // w11
  unsigned int v89; // w8
  unsigned int v90; // w8
  unsigned int v91; // w8
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int16 *v109; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v110; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v111; // [xsp+18h] [xbp-8h]

  v111 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v108) = 8;
  if ( !result )
    goto LABEL_5;
  if ( !a2 )
    goto LABEL_5;
  if ( *(_DWORD *)(a2 + 16) != 1 )
    goto LABEL_5;
  v4 = *(unsigned __int8 *)(a2 + 168);
  result = (unsigned __int16 *)wlan_vdev_mlme_is_active(a2);
  if ( (_DWORD)result )
    goto LABEL_5;
  result = (unsigned __int16 *)wlan_vdev_get_active_channel(a2);
  if ( !result )
    goto LABEL_5;
  v14 = *result;
  v15 = a3[1];
  if ( (_DWORD)v15 != v14 )
  {
    result = (unsigned __int16 *)qdf_trace_msg(
                                   0x74u,
                                   8u,
                                   "%s: SAP-%d: freq not match rpt:%u - op:%u",
                                   v6,
                                   v7,
                                   v8,
                                   v9,
                                   v10,
                                   v11,
                                   v12,
                                   v13,
                                   "wlan_dcs_process_awgn_sap",
                                   v4,
                                   v15,
                                   *result);
    goto LABEL_5;
  }
  v16 = *((_DWORD *)result + 6);
  if ( (wlan_dcs_get_max_no_intf_bw(a3, (char *)&v108 + 4) & 1) != 0 )
  {
    if ( v16 <= HIDWORD(v108) )
    {
      result = (unsigned __int16 *)qdf_trace_msg(
                                     0x74u,
                                     8u,
                                     "%s: SAP-%d: both freq and bw are unchanged",
                                     v17,
                                     v18,
                                     v19,
                                     v20,
                                     v21,
                                     v22,
                                     v23,
                                     v24,
                                     "wlan_dcs_process_awgn_sap",
                                     v4);
      goto LABEL_5;
    }
    goto LABEL_21;
  }
  v25 = _qdf_mem_malloc(0x198u, "wlan_dcs_sap_select_chan", 1322);
  if ( !v25 )
  {
    v14 = 0;
    goto LABEL_21;
  }
  v26 = *(_QWORD *)(a2 + 216);
  v27 = v25;
  if ( !v26
    || (v28 = *(_QWORD *)(v26 + 80)) == 0
    || (v29 = _qdf_mem_malloc(0x204u, "wlan_dcs_get_pcl_for_sap", 1017)) == 0 )
  {
LABEL_18:
    v14 = 0;
    goto LABEL_19;
  }
  v38 = v29;
  v39 = policy_mgr_qdf_opmode_to_pm_con_mode(v28, 1, *(_BYTE *)(a2 + 168), v30, v31, v32, v33, v34, v35, v36, v37);
  v40 = (_DWORD *)(v38 + 512);
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, __int64, __int64, _QWORD))policy_mgr_get_pcl_for_vdev_id)(
                       v28,
                       v39,
                       v38,
                       v38 + 512,
                       v38 + 408,
                       102,
                       *(unsigned __int8 *)(a2 + 168))
    || !*v40 )
  {
    _qdf_mem_free(v38);
    goto LABEL_18;
  }
  v52 = 0;
  v53 = 0;
  do
  {
    v54 = *(_DWORD *)(v38 + 4 * v52);
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(v26, v54, 0, v41, v42, v43, v44, v45, v46, v47, v48) == 3 )
      *(_DWORD *)(v27 + 4LL * v53++) = v54;
    if ( v52 > 0x64 )
      break;
    ++v52;
  }
  while ( v52 < (unsigned int)*v40 );
  _qdf_mem_free(v38);
  if ( !v53 )
    goto LABEL_18;
  v55 = *(_QWORD *)(a2 + 216);
  v14 = 0;
  if ( v55 )
  {
    v56 = *a3;
    if ( (*a3 & 0x80000000) == 0 )
    {
      do
      {
        v58 = 0;
        v59 = 0;
        v109 = nullptr;
        LODWORD(v108) = 1;
        v110 = 0;
        do
        {
          v60 = *(_DWORD *)(v27 + 4LL * v59);
          if ( (wlan_reg_is_same_band_freqs(v60, a3[1]) & 1) == 0 )
            goto LABEL_41;
          if ( (wlan_reg_is_dfs_for_freq(v55, v60, v61, v62, v63, v64, v65, v66, v67, v68) & 1) != 0 )
          {
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: skip dfs freq %u",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "wlan_dcs_get_available_chan_for_bw",
              v60);
            goto LABEL_41;
          }
          if ( v109 && v60 >= *v109 && v60 <= v109[1] )
          {
            if ( (v108 & 1) == 0 )
            {
LABEL_82:
              LODWORD(v108) = 0;
              goto LABEL_41;
            }
            v79 = "%s: add freq directly [%d] = %u";
LABEL_60:
            qdf_trace_msg(
              0x74u,
              8u,
              v79,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "wlan_dcs_get_available_chan_for_bw",
              v58,
              v60,
              v108);
            v83 = v58 + 1;
            *(_DWORD *)(v27 + 4LL * (int)v58) = v60;
            LODWORD(v108) = 1;
            goto LABEL_96;
          }
          if ( (unsigned int)wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(
                               v55,
                               v60,
                               v56,
                               &v109,
                               0,
                               0,
                               v69,
                               v70,
                               v71,
                               v72,
                               v73,
                               v74,
                               v75,
                               v76) != 3 )
            goto LABEL_41;
          if ( v56 )
          {
            v77 = *v109;
            v78 = v109[1];
            if ( v77 > v78 )
            {
LABEL_50:
              v79 = "%s: add freq[%d] = %u";
              goto LABEL_60;
            }
            v84 = *a3;
            while ( 2 )
            {
              if ( v84 <= 1 )
              {
                if ( v84 )
                {
                  if ( v84 == 1 )
                  {
                    v87 = a3[2];
                    if ( v87 - 10 <= (unsigned __int16)v77 && v87 + 10 >= (unsigned __int16)v77 )
                      goto LABEL_82;
                  }
                }
                else if ( a3[1] == (unsigned __int16)v77 )
                {
                  goto LABEL_82;
                }
              }
              else
              {
                switch ( v84 )
                {
                  case 2:
                    v86 = a3[2];
                    goto LABEL_77;
                  case 3:
                    v88 = a3[3];
                    if ( v88 - 70 <= (unsigned __int16)v77 && v88 + 70 >= (unsigned __int16)v77 )
                      goto LABEL_82;
                    break;
                  case 4:
                    v85 = a3[2];
                    if ( v85 - 30 <= (unsigned __int16)v77 && v85 + 30 >= (unsigned __int16)v77 )
                      goto LABEL_82;
                    v86 = a3[3];
LABEL_77:
                    if ( v86 - 30 <= (unsigned __int16)v77 && v86 + 30 >= (unsigned __int16)v77 )
                      goto LABEL_82;
                    break;
                }
              }
              LOWORD(v77) = v77 + 20;
              if ( v78 < (unsigned __int16)v77 )
                goto LABEL_50;
              continue;
            }
          }
          v80 = *a3;
          if ( (int)*a3 <= 1 )
          {
            if ( v80 )
            {
              if ( v80 == 1 )
              {
                v89 = a3[2];
                if ( v60 >= v89 - 10 )
                {
                  v90 = v89 + 10;
LABEL_92:
                  if ( v60 <= v90 )
                    goto LABEL_41;
                }
              }
            }
            else if ( a3[1] == v60 )
            {
              goto LABEL_41;
            }
LABEL_95:
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: add freq[%d] = %u",
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              "wlan_dcs_get_available_chan_for_bw",
              v58,
              v60,
              v108);
            v83 = v58 + 1;
            *(_DWORD *)(v27 + 4LL * (int)v58) = v60;
LABEL_96:
            v58 = v83;
            goto LABEL_41;
          }
          if ( v80 == 2 )
          {
            v82 = a3[2];
LABEL_88:
            if ( v60 >= v82 - 30 )
            {
              v90 = v82 + 30;
              goto LABEL_92;
            }
            goto LABEL_95;
          }
          if ( v80 == 3 )
          {
            v91 = a3[3];
            if ( v60 >= v91 - 70 )
            {
              v90 = v91 + 70;
              goto LABEL_92;
            }
            goto LABEL_95;
          }
          if ( v80 != 4 )
            goto LABEL_95;
          v81 = a3[2];
          if ( v60 < v81 - 30 || v60 > v81 + 30 )
          {
            v82 = a3[3];
            goto LABEL_88;
          }
LABEL_41:
          ++v59;
        }
        while ( v59 != v53 );
        if ( v58 )
        {
          get_random_bytes(&v110, 4);
          v110 %= v58;
          v14 = *(_DWORD *)(v27 + 4LL * v110);
          qdf_trace_msg(
            0x74u,
            8u,
            "%s: get freq[%d] = %u for bw %u",
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            v99,
            "wlan_dcs_get_available_chan_for_bw");
          if ( v14 )
          {
            HIDWORD(v108) = v56;
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: new_width: %d new_freq %u",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "wlan_dcs_sap_select_chan",
              v56,
              v14);
            break;
          }
        }
        v14 = 0;
      }
      while ( (int)v56-- > 0 );
    }
  }
LABEL_19:
  _qdf_mem_free(v27);
LABEL_21:
  v49 = HIDWORD(v108);
  result = (unsigned __int16 *)qdf_trace_msg(
                                 0x74u,
                                 8u,
                                 "%s: SAP-%d: target freq %u width %u",
                                 v17,
                                 v18,
                                 v19,
                                 v20,
                                 v21,
                                 v22,
                                 v23,
                                 v24,
                                 "wlan_dcs_process_awgn_sap",
                                 v4,
                                 v14,
                                 HIDWORD(v108),
                                 v108);
  v50 = *(_QWORD *)(a2 + 216);
  if ( v50 )
  {
    result = *(unsigned __int16 **)(v50 + 80);
    if ( result )
    {
      result = (unsigned __int16 *)wlan_objmgr_psoc_get_comp_private_obj((__int64)result, 0x24u);
      if ( result )
      {
        v51 = *((_DWORD **)result + 146);
        if ( v51 )
        {
          if ( *(v51 - 1) != 1670170395 )
            __break(0x8228u);
          result = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v51)(a2, v14, v49);
        }
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
