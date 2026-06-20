__int64 __fastcall cm_create_roam_scan_channel_list(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        unsigned int *a4,
        unsigned __int8 a5,
        unsigned int a6)
{
  __int64 v7; // x0
  __int64 psoc_ext_obj_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x26
  __int64 v22; // x24
  const char *v23; // x2
  __int64 v24; // x4
  __int64 v26; // x20
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x28
  unsigned __int8 v37; // w26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 v47; // x9
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  unsigned int v57; // w20
  __int64 v58; // x0
  __int64 v59; // x25
  unsigned int operation_chan_freq_vdev_id; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned __int8 v69; // w20
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x8
  __int64 v73; // x27
  __int64 v74; // x28
  int v75; // w4
  __int64 v76; // x8
  __int64 v77; // x8
  __int64 v78; // x0
  unsigned int v79; // w21
  __int64 v80; // x22
  unsigned int *v81; // x23
  __int64 v82; // x9
  unsigned int v83; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(a1 + 80);
  if ( !v7 )
    return 4;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v7);
  if ( !psoc_ext_obj_fl )
    return 4;
  v21 = *(unsigned __int8 *)(a2 + 272);
  v22 = psoc_ext_obj_fl;
  v83 = a6;
  if ( !*(_BYTE *)(a2 + 272) )
  {
    LOBYTE(v26) = a5;
    goto LABEL_13;
  }
  if ( !a4 )
  {
LABEL_12:
    LOBYTE(v26) = 0;
    goto LABEL_13;
  }
  if ( (unsigned int)v21 >= 0x65 )
  {
    v23 = "%s: Wrong Number of Input Channels %d";
    v24 = *(unsigned __int8 *)(a2 + 272);
LABEL_11:
    qdf_trace_msg(0x68u, 2u, v23, v13, v14, v15, v16, v17, v18, v19, v20, "cm_roam_merge_channel_lists", v24);
    goto LABEL_12;
  }
  v24 = a5;
  if ( a5 > 0x63u )
  {
    v23 = "%s: Wrong Number of Output Channels %d";
    goto LABEL_11;
  }
  v73 = 0;
  v74 = a2 + 276;
  LOBYTE(v26) = a5;
  while ( 1 )
  {
    if ( a5 )
    {
      v75 = *(_DWORD *)(v74 + 4 * v73);
      v76 = 0;
      while ( v75 != a4[v76] )
      {
        if ( a5 == ++v76 )
        {
          if ( v75 )
            goto LABEL_63;
          goto LABEL_53;
        }
      }
    }
    else
    {
      LOBYTE(v76) = 0;
    }
    if ( (unsigned __int8)v76 != a5 || !*(_DWORD *)(v74 + 4 * v73) )
      goto LABEL_53;
LABEL_63:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Adding extra %d to roam channel list",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cm_roam_merge_channel_lists");
    v77 = (unsigned __int8)v26;
    LOBYTE(v26) = v26 + 1;
    a4[v77] = *(_DWORD *)(v74 + 4 * v73);
    if ( (unsigned __int8)v26 >= 0x64u )
      break;
LABEL_53:
    if ( ++v73 == v21 )
      goto LABEL_13;
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Merge Neighbor channel list reached Max limit %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "cm_roam_merge_channel_lists",
    (unsigned int)v21);
LABEL_13:
  v27 = _qdf_mem_malloc(0x190u, "cm_create_roam_scan_channel_list", 5626);
  if ( !v27 )
    return 2;
  v36 = v27;
  if ( v83 == 2 )
  {
    if ( (_BYTE)v26 )
    {
      v37 = 0;
      v26 = (unsigned __int8)v26;
      do
      {
        if ( wlan_reg_is_5ghz_ch_freq(*a4)
          && (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(v22 + 5756, *a4) & 1) != 0
          && (wlan_reg_is_dfs_for_freq(a1, *a4, v48, v49, v50, v51, v52, v53, v54, v55) & 1) == 0 )
        {
          v56 = v37++;
          *(_DWORD *)(v36 + 4 * v56) = *a4;
        }
        --v26;
        ++a4;
      }
      while ( v26 );
LABEL_39:
      v58 = _qdf_mem_malloc(0x190u, "cm_create_roam_scan_channel_list", 5661);
      if ( !v58 )
      {
LABEL_69:
        v57 = 2;
        goto LABEL_77;
      }
      v59 = v58;
      if ( v83 || (*(_BYTE *)(v22 + 1773) & 1) == 0 )
      {
        v69 = v37;
      }
      else
      {
        operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(a1, a3);
        if ( v37 > 0x64u )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Wrong Number of Input Channels %d",
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            "cm_roam_channels_filter_by_current_band");
LABEL_46:
          v70 = *(_QWORD *)(a2 + 848);
          if ( v70 )
          {
            _qdf_mem_free(v70);
            *(_QWORD *)(a2 + 848) = 0;
            *(_BYTE *)(a2 + 840) = 0;
          }
          v71 = _qdf_mem_malloc(4LL * v37, "cm_create_roam_scan_channel_list", 5685);
          *(_QWORD *)(a2 + 848) = v71;
          if ( v71 )
          {
            v72 = 0;
            do
            {
              *(_DWORD *)(*(_QWORD *)(a2 + 848) + 4 * v72) = *(_DWORD *)(v59 + 4 * v72);
              ++v72;
            }
            while ( v37 != v72 );
            v57 = 0;
            *(_BYTE *)(a2 + 840) = v37;
          }
          else
          {
            *(_BYTE *)(a2 + 840) = 0;
            v57 = 2;
          }
          goto LABEL_76;
        }
        if ( !v37 )
          goto LABEL_75;
        v79 = operation_chan_freq_vdev_id;
        v69 = 0;
        v80 = v37;
        v81 = (unsigned int *)v36;
        do
        {
          if ( (wlan_reg_is_same_band_freqs(v79, *v81) & 1) != 0 )
          {
            v82 = v69++;
            *(_DWORD *)(v59 + 4 * v82) = *v81;
          }
          --v80;
          ++v81;
        }
        while ( v80 );
      }
      v37 = v69;
      if ( !v69 )
        goto LABEL_75;
      goto LABEL_46;
    }
LABEL_38:
    v37 = 0;
    goto LABEL_39;
  }
  if ( v83 == 1 )
  {
    if ( (_BYTE)v26 )
    {
      v37 = 0;
      v26 = (unsigned __int8)v26;
      do
      {
        if ( wlan_reg_is_24ghz_ch_freq(*a4)
          && (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(v22 + 5756, *a4) & 1) != 0 )
        {
          v47 = v37++;
          *(_DWORD *)(v36 + 4 * v47) = *a4;
        }
        --v26;
        ++a4;
      }
      while ( v26 );
      goto LABEL_39;
    }
    goto LABEL_38;
  }
  if ( v83 )
  {
    qdf_trace_msg(
      0x68u,
      3u,
      "%s: Invalid band, No operation carried out (Band %d)",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "cm_create_roam_scan_channel_list",
      v83);
    v57 = 4;
    goto LABEL_77;
  }
  if ( (_BYTE)v26 )
  {
    v37 = 0;
    v26 = (unsigned __int8)v26;
    do
    {
      if ( (((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(v22 + 5756, *a4) & 1) != 0
        && (wlan_reg_is_dfs_for_freq(a1, *a4, v38, v39, v40, v41, v42, v43, v44, v45) & 1) == 0 )
      {
        v46 = v37++;
        *(_DWORD *)(v36 + 4 * v46) = *a4;
      }
      --v26;
      ++a4;
    }
    while ( v26 );
    goto LABEL_39;
  }
  v78 = _qdf_mem_malloc(0x190u, "cm_create_roam_scan_channel_list", 5661);
  if ( !v78 )
    goto LABEL_69;
  v59 = v78;
  if ( *(_BYTE *)(v22 + 1773) == 1 )
    wlan_get_operation_chan_freq_vdev_id(a1, a3);
LABEL_75:
  v57 = 0;
LABEL_76:
  _qdf_mem_free(v59);
LABEL_77:
  _qdf_mem_free(v36);
  return v57;
}
