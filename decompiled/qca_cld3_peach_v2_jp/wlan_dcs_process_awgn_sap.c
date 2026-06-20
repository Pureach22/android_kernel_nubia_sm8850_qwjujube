unsigned __int16 *__fastcall wlan_dcs_process_awgn_sap(unsigned __int16 *result, __int64 a2, int *a3)
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
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w21
  __int64 v58; // x8
  _DWORD *v59; // x8
  unsigned __int64 v60; // x27
  int v61; // w28
  unsigned int v62; // w26
  __int64 v63; // x24
  int v64; // w23
  unsigned int v66; // w25
  int v67; // w26
  unsigned int v68; // w27
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w10
  unsigned int v86; // w8
  const char *v87; // x2
  int v88; // w8
  int v89; // w8
  int v90; // w8
  unsigned int v91; // w8
  int v92; // w9
  int v93; // w11
  int v94; // w11
  int v95; // w11
  int v96; // w11
  int v97; // w8
  unsigned int v98; // w8
  int v99; // w8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int16 *v117; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v118; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v119; // [xsp+18h] [xbp-8h]

  v119 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v116) = 8;
  if ( !result )
    goto LABEL_5;
  if ( !a2 )
    goto LABEL_5;
  if ( *(_DWORD *)(a2 + 16) != 1 )
    goto LABEL_5;
  v4 = *(unsigned __int8 *)(a2 + 104);
  result = (unsigned __int16 *)wlan_vdev_mlme_is_active(a2);
  if ( (_DWORD)result )
    goto LABEL_5;
  result = (unsigned __int16 *)wlan_vdev_get_active_channel(a2);
  if ( !result )
    goto LABEL_5;
  v14 = *result;
  v15 = (unsigned int)a3[1];
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
  if ( (wlan_dcs_get_max_no_intf_bw(a3, (char *)&v116 + 4) & 1) != 0 )
  {
    if ( v16 <= HIDWORD(v116) )
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
  v26 = *(_QWORD *)(a2 + 152);
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
  v39 = policy_mgr_qdf_opmode_to_pm_con_mode(v28, 1, *(_BYTE *)(a2 + 104), v30, v31, v32, v33, v34, v35, v36, v37);
  v40 = (_DWORD *)(v38 + 512);
  if ( (unsigned int)policy_mgr_get_pcl_for_vdev_id(
                       v28,
                       v39,
                       v38,
                       (_DWORD *)(v38 + 512),
                       v38 + 408,
                       0x66u,
                       *(unsigned __int8 *)(a2 + 104),
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47,
                       v48)
    || !*v40 )
  {
    _qdf_mem_free(v38);
    goto LABEL_18;
  }
  v60 = 0;
  v61 = 0;
  do
  {
    v62 = *(_DWORD *)(v38 + 4 * v60);
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(v26, v62, 0, v49, v50, v51, v52, v53, v54, v55, v56) == 3 )
      *(_DWORD *)(v27 + 4LL * v61++) = v62;
    if ( v60 > 0x64 )
      break;
    ++v60;
  }
  while ( v60 < (unsigned int)*v40 );
  _qdf_mem_free(v38);
  if ( !v61 )
    goto LABEL_18;
  v63 = *(_QWORD *)(a2 + 152);
  v14 = 0;
  if ( v63 )
  {
    v64 = *a3;
    if ( (*a3 & 0x80000000) == 0 )
    {
      do
      {
        v66 = 0;
        v67 = 0;
        v117 = nullptr;
        LODWORD(v116) = 1;
        v118 = 0;
        do
        {
          v68 = *(_DWORD *)(v27 + 4LL * v67);
          if ( (wlan_reg_is_same_band_freqs(v68, a3[1]) & 1) == 0 )
            goto LABEL_41;
          if ( (wlan_reg_is_dfs_for_freq(v63, v68, v69, v70, v71, v72, v73, v74, v75, v76) & 1) != 0 )
          {
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: skip dfs freq %u",
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              "wlan_dcs_get_available_chan_for_bw",
              v68);
            goto LABEL_41;
          }
          if ( v117 && v68 >= *v117 && v68 <= v117[1] )
          {
            if ( (v116 & 1) == 0 )
            {
LABEL_82:
              LODWORD(v116) = 0;
              goto LABEL_41;
            }
            v87 = "%s: add freq directly [%d] = %u";
LABEL_60:
            qdf_trace_msg(
              0x74u,
              8u,
              v87,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              "wlan_dcs_get_available_chan_for_bw",
              v66,
              v68,
              v116);
            v91 = v66 + 1;
            *(_DWORD *)(v27 + 4LL * (int)v66) = v68;
            LODWORD(v116) = 1;
            goto LABEL_96;
          }
          if ( (unsigned int)wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(
                               v63,
                               v68,
                               v64,
                               &v117,
                               0,
                               v77,
                               v78,
                               v79,
                               v80,
                               v81,
                               v82,
                               v83,
                               v84) != 3 )
            goto LABEL_41;
          if ( v64 )
          {
            v85 = *v117;
            v86 = v117[1];
            if ( v85 > v86 )
            {
LABEL_50:
              v87 = "%s: add freq[%d] = %u";
              goto LABEL_60;
            }
            v92 = *a3;
            while ( 2 )
            {
              if ( v92 <= 1 )
              {
                if ( v92 )
                {
                  if ( v92 == 1 )
                  {
                    v95 = a3[2];
                    if ( v95 - 10 <= (unsigned int)(unsigned __int16)v85
                      && v95 + 10 >= (unsigned int)(unsigned __int16)v85 )
                    {
                      goto LABEL_82;
                    }
                  }
                }
                else if ( a3[1] == (unsigned __int16)v85 )
                {
                  goto LABEL_82;
                }
              }
              else
              {
                switch ( v92 )
                {
                  case 2:
                    v94 = a3[2];
                    goto LABEL_77;
                  case 3:
                    v96 = a3[3];
                    if ( v96 - 70 <= (unsigned int)(unsigned __int16)v85
                      && v96 + 70 >= (unsigned int)(unsigned __int16)v85 )
                    {
                      goto LABEL_82;
                    }
                    break;
                  case 4:
                    v93 = a3[2];
                    if ( v93 - 30 <= (unsigned int)(unsigned __int16)v85
                      && v93 + 30 >= (unsigned int)(unsigned __int16)v85 )
                    {
                      goto LABEL_82;
                    }
                    v94 = a3[3];
LABEL_77:
                    if ( v94 - 30 <= (unsigned int)(unsigned __int16)v85
                      && v94 + 30 >= (unsigned int)(unsigned __int16)v85 )
                    {
                      goto LABEL_82;
                    }
                    break;
                }
              }
              LOWORD(v85) = v85 + 20;
              if ( v86 < (unsigned __int16)v85 )
                goto LABEL_50;
              continue;
            }
          }
          v88 = *a3;
          if ( *a3 <= 1 )
          {
            if ( v88 )
            {
              if ( v88 == 1 )
              {
                v97 = a3[2];
                if ( v68 >= v97 - 10 )
                {
                  v98 = v97 + 10;
LABEL_92:
                  if ( v68 <= v98 )
                    goto LABEL_41;
                }
              }
            }
            else if ( a3[1] == v68 )
            {
              goto LABEL_41;
            }
LABEL_95:
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: add freq[%d] = %u",
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              "wlan_dcs_get_available_chan_for_bw",
              v66,
              v68,
              v116);
            v91 = v66 + 1;
            *(_DWORD *)(v27 + 4LL * (int)v66) = v68;
LABEL_96:
            v66 = v91;
            goto LABEL_41;
          }
          if ( v88 == 2 )
          {
            v90 = a3[2];
LABEL_88:
            if ( v68 >= v90 - 30 )
            {
              v98 = v90 + 30;
              goto LABEL_92;
            }
            goto LABEL_95;
          }
          if ( v88 == 3 )
          {
            v99 = a3[3];
            if ( v68 >= v99 - 70 )
            {
              v98 = v99 + 70;
              goto LABEL_92;
            }
            goto LABEL_95;
          }
          if ( v88 != 4 )
            goto LABEL_95;
          v89 = a3[2];
          if ( v68 < v89 - 30 || v68 > v89 + 30 )
          {
            v90 = a3[3];
            goto LABEL_88;
          }
LABEL_41:
          ++v67;
        }
        while ( v67 != v61 );
        if ( v66 )
        {
          get_random_bytes(&v118, 4);
          v118 %= v66;
          v14 = *(_DWORD *)(v27 + 4LL * v118);
          qdf_trace_msg(
            0x74u,
            8u,
            "%s: get freq[%d] = %u for bw %u",
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            "wlan_dcs_get_available_chan_for_bw");
          if ( v14 )
          {
            HIDWORD(v116) = v64;
            qdf_trace_msg(
              0x74u,
              8u,
              "%s: new_width: %d new_freq %u",
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              v115,
              "wlan_dcs_sap_select_chan",
              (unsigned int)v64,
              v14);
            break;
          }
        }
        v14 = 0;
      }
      while ( v64-- > 0 );
    }
  }
LABEL_19:
  _qdf_mem_free(v27);
LABEL_21:
  v57 = HIDWORD(v116);
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
                                 HIDWORD(v116),
                                 v116);
  v58 = *(_QWORD *)(a2 + 152);
  if ( v58 )
  {
    result = *(unsigned __int16 **)(v58 + 80);
    if ( result )
    {
      result = (unsigned __int16 *)wlan_objmgr_psoc_get_comp_private_obj((__int64)result, 0x24u);
      if ( result )
      {
        v59 = *((_DWORD **)result + 146);
        if ( v59 )
        {
          if ( *(v59 - 1) != 1670170395 )
            __break(0x8228u);
          result = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v59)(a2, v14, v57);
        }
      }
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
