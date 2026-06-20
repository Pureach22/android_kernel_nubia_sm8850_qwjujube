__int64 __fastcall tdls_extract_peer_state_param(
        _DWORD *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x24
  __int64 v11; // x8
  __int64 v13; // x0
  __int64 comp_private_obj; // x4
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  char v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
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
  const char *v51; // x2
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x0
  __int64 v61; // x1
  unsigned int v62; // w22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x25
  unsigned int v72; // w26
  char v73; // w8
  unsigned int v74; // w23
  __int64 v75; // x28
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w2
  int v85; // w8
  __int64 v86; // x8
  int v87; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v88; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v89; // [xsp+18h] [xbp-8h]

  v89 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a2 + 16);
  v87 = 0;
  if ( !*v10 )
  {
    v51 = "%s: NULL vdev";
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(*v10 + 152);
  if ( !v11 || (v13 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v51 = "%s: can't get psoc";
LABEL_10:
    qdf_trace_msg(0, 2u, v51, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj");
    comp_private_obj = 0;
    v24 = *(_QWORD *)(*v10 + 152);
LABEL_11:
    result = qdf_trace_msg(
               0,
               2u,
               "%s: soc_obj: %pK, pdev: %pK",
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               "tdls_extract_peer_state_param",
               comp_private_obj,
               v24);
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0xAu);
  v24 = *(_QWORD *)(*v10 + 152);
  if ( !comp_private_obj || !v24 )
    goto LABEL_11;
  qdf_mem_set(a1, 0x444u, 0);
  *a1 = *(unsigned __int8 *)(*v10 + 104);
  qdf_mem_copy(a1 + 1, (const void *)(a2 + 24), 6u);
  a1[3] = 1;
  *((_BYTE *)a1 + 16) = *(_BYTE *)(a2 + 40);
  *((_BYTE *)a1 + 17) = *(_BYTE *)(a2 + 48);
  *((_BYTE *)a1 + 18) = *(_BYTE *)(a2 + 49);
  *((_BYTE *)a1 + 19) = *(_BYTE *)(a2 + 50);
  v25 = *(_BYTE *)(a2 + 51);
  *((_BYTE *)a1 + 21) = 0;
  *((_BYTE *)a1 + 20) = v25;
  *((_BYTE *)a1 + 22) = *(_BYTE *)(a2 + 490);
  *((_BYTE *)a1 + 1081) = wlan_reg_freq_to_chan(v24, *(_DWORD *)(a2 + 492), v26, v27, v28, v29, v30, v31, v32, v33);
  *((_BYTE *)a1 + 1082) = *(_BYTE *)(a2 + 496);
  *((_BYTE *)a1 + 1083) = *(_BYTE *)(a2 + 490);
  a1[271] = *(_DWORD *)(a2 + 492);
  if ( !(unsigned int)ucfg_reg_get_band(v24, &v87, v34, v35, v36, v37, v38, v39, v40, v41) )
  {
    if ( v87 == 1 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: sending the offchannel value as 0 as only 2g is supported",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "tdls_extract_peer_state_param");
      *((_BYTE *)a1 + 1081) = 0;
      *((_BYTE *)a1 + 1083) = 0;
      a1[271] = 0;
    }
    if ( (wlan_reg_is_dfs_for_freq(v24, *(_DWORD *)(a2 + 492), v42, v43, v44, v45, v46, v47, v48, v49) & 1) != 0 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: Resetting TDLS off-channel from %d to %d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "tdls_extract_peer_state_param",
        *((unsigned __int8 *)a1 + 1081),
        36);
      *((_BYTE *)a1 + 1081) = 36;
      a1[271] = 5180;
    }
    v60 = *(_QWORD *)(v24 + 80);
    v61 = *v10;
    v88 = 0;
    if ( v60 && (*(_BYTE *)(v60 + 25) & 1) != 0 )
    {
      if ( (policy_mgr_get_allowed_tdls_offchannel_freq(v60, v61, &v88) & 1) != 0 )
      {
        v62 = v88;
        goto LABEL_23;
      }
      qdf_trace_msg(
        0,
        8u,
        "%s: off channel not allowed for current concurrency",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "tdls_get_allowed_off_channel_for_concurrency");
    }
    v62 = 0;
LABEL_23:
    result = qdf_trace_msg(
               0,
               8u,
               "%s: allowed freq:%u",
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               "tdls_extract_peer_state_param",
               v62);
    if ( *(_BYTE *)(a2 + 52) )
    {
      v71 = 0;
      v72 = 0;
      while ( v71 != 100 )
      {
        v74 = *(_DWORD *)(a2 + 56 + 4 * v71);
        if ( !v62 || v62 == v74 )
        {
          result = wlan_reg_get_channel_state_for_pwrmode(v24, v74, 6u, v63, v64, v65, v66, v67, v68, v69, v70);
          if ( (_DWORD)result != 4 )
          {
            result = wlan_reg_is_dfs_for_freq(v24, v74, v63, v64, v65, v66, v67, v68, v69, v70);
            if ( (result & 1) == 0 )
            {
              result = wlan_reg_is_dsrc_freq();
              if ( (result & 1) == 0 )
              {
                if ( v72 > 0x7F )
                  break;
                v75 = (__int64)&a1[2 * v72 + 6];
                *(_DWORD *)v75 = v74;
                if ( wlan_reg_is_6ghz_chan_freq(v74) )
                {
                  if ( (wlan_reg_is_indoor_ap_detected(v24, v76, v77, v78, v79, v80, v81, v82, v83) & 1) != 0 )
                    v84 = 11;
                  else
                    v84 = 6;
                  result = tdls_get_6g_pwr_for_power_type(*v10, v74, v84);
                }
                else
                {
                  result = (unsigned __int8)wlan_reg_get_channel_reg_power_for_freq(
                                              v24,
                                              v74,
                                              v76,
                                              v77,
                                              v78,
                                              v79,
                                              v80,
                                              v81,
                                              v82,
                                              v83);
                }
                v73 = *((_BYTE *)a1 + 23);
                ++v72;
                *(_BYTE *)(v75 + 4) = result;
                *(_BYTE *)(v75 + 5) = 0;
                *((_BYTE *)a1 + 23) = v73 + 1;
              }
            }
          }
        }
        if ( ++v71 >= (unsigned __int64)*(unsigned __int8 *)(a2 + 52) )
          goto LABEL_40;
      }
    }
    else
    {
LABEL_40:
      v85 = *(unsigned __int8 *)(a2 + 456);
      *((_BYTE *)a1 + 1048) = v85;
      if ( !v85 )
        goto LABEL_12;
      v86 = 0;
      while ( v86 != 32 )
      {
        *((_BYTE *)a1 + v86 + 1049) = *(_BYTE *)(a2 + 457 + v86);
        if ( ++v86 >= (unsigned __int64)*(unsigned __int8 *)(a2 + 456) )
          goto LABEL_12;
      }
    }
    __break(0x5512u);
  }
  result = qdf_trace_msg(
             0,
             2u,
             "%s: not able get the current frequency band",
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             "tdls_extract_peer_state_param");
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
