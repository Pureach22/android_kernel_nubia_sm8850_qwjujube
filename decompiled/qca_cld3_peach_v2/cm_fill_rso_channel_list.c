__int64 __fastcall cm_fill_rso_channel_list(__int64 a1, __int64 a2, __int64 a3, __int64 a4, char a5)
{
  int v9; // w24
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  __int64 v20; // x26
  unsigned __int64 v21; // x24
  unsigned int v22; // w25
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  char v31; // w8
  unsigned __int64 v32; // x5
  unsigned int v33; // w23
  unsigned int v34; // w0
  unsigned int v35; // w22
  int v36; // w22
  unsigned __int8 v37; // w8
  __int64 v38; // x24
  __int64 v39; // x26
  unsigned int operation_chan_freq; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w24
  int v50; // w24
  unsigned __int8 v51; // w24
  __int64 v52; // x21
  char v53; // w0
  unsigned __int64 v54; // x9
  unsigned int v55; // w25
  __int64 v56; // x27
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x9
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x24
  __int64 v68; // x26
  int v69; // w25
  unsigned __int64 v70; // x8
  int v71; // w25
  unsigned __int64 v72; // x8
  int v73; // w25
  unsigned __int64 v74; // x8
  unsigned __int64 v75; // x25
  __int64 v76; // x26
  unsigned int v77; // w1
  unsigned __int64 v78; // x8
  int v79; // w9
  _QWORD v80[17]; // [xsp+8h] [xbp-88h] BYREF

  v80[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a2 + 168);
  memset(v80, 0, 128);
  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    *(_DWORD *)a4 = v9;
    v19 = result;
    if ( (*(_BYTE *)(a3 + 678) & 1) == 0 && *(_BYTE *)(a3 + 840) )
    {
      v20 = *(_QWORD *)(a3 + 848);
      v21 = 0;
      v22 = 0;
      do
      {
        if ( (cm_is_dfs_unsafe_extra_band_chan(a2, v19, *(_DWORD *)(v20 + 4 * v21), 0) & 1) == 0 )
        {
          if ( v22 >= 0x64 )
            goto LABEL_91;
          *(_DWORD *)(a4 + 8 + 4LL * v22++) = *(_DWORD *)(v20 + 4 * v21);
        }
        ++v21;
      }
      while ( v21 < *(unsigned __int8 *)(a3 + 840) );
      v31 = 2;
      *(_BYTE *)(a4 + 4) = v22;
      goto LABEL_17;
    }
    if ( !*(_BYTE *)(a3 + 112) )
    {
      if ( a5 == 9 )
      {
        v32 = 0;
        *(_BYTE *)(a4 + 4) = 0;
        *(_BYTE *)(a4 + 408) = 1;
LABEL_48:
        result = qdf_trace_msg(
                   0x68u,
                   8u,
                   "%s: chan_cache_type:%d, No of chan:%d, chan: %s",
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   "cm_fill_rso_channel_list",
                   *(unsigned __int8 *)(a4 + 408),
                   v32,
                   v80);
        goto LABEL_49;
      }
      operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
      if ( *(_BYTE *)(v19 + 1977) == 1 )
      {
        v49 = operation_chan_freq;
        if ( wlan_reg_is_5ghz_ch_freq(operation_chan_freq) )
        {
          v50 = 2;
        }
        else if ( wlan_reg_is_24ghz_ch_freq(v49) )
        {
          v50 = 1;
        }
        else
        {
          v50 = 3;
        }
      }
      else
      {
        v50 = 0;
      }
      if ( (unsigned int)*(unsigned __int8 *)(a3 + 272) - 1 > 0x62 )
      {
        LOBYTE(v55) = 0;
      }
      else
      {
        v55 = 0;
        v56 = 69;
        do
        {
          if ( (cm_is_dfs_unsafe_extra_band_chan(a2, v19, *(_DWORD *)(a3 + 4 * v56), v50) & 1) == 0 )
          {
            if ( v55 > 0x63 )
              goto LABEL_91;
            *(_DWORD *)(a4 + 8 + 4LL * v55++) = *(_DWORD *)(a3 + 4 * v56);
          }
          v57 = *(unsigned __int8 *)(a3 + 272);
          if ( v57 > 0x63 )
            break;
          v58 = v56 - 68;
          ++v56;
        }
        while ( v58 < v57 );
      }
      *(_BYTE *)(a4 + 4) = v55;
      *(_BYTE *)(a4 + 408) = 2;
      if ( *(_BYTE *)(a3 + 168) )
      {
        if ( (unsigned int)cm_populate_roam_chan_list(a2, v19, a4, a3 + 168) )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Failed to copy channels to roam list",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "cm_add_ch_lst_from_roam_scan_list");
        }
        else
        {
          cm_dump_freq_list(a3 + 168);
          *(_BYTE *)(a4 + 408) = 2;
        }
      }
      if ( (wlan_vdev_mlme_is_mlo_vdev(a2, v41, v42, v43, v44, v45, v46, v47, v48) & 1) != 0 )
      {
        v67 = a4 + 8;
        v68 = *(_QWORD *)(*(_QWORD *)(a2 + 1360) + 3880LL);
        if ( *(_DWORD *)(v68 + 24) | *(unsigned __int16 *)(v68 + 28) )
        {
          if ( *(unsigned __int8 *)(v68 + 6) != 255 )
          {
            v69 = **(unsigned __int16 **)(v68 + 32);
            if ( !wlan_is_channel_present_in_list((int *)(a4 + 8), *(unsigned __int8 *)(a4 + 4), v69) )
            {
              v70 = *(unsigned __int8 *)(a4 + 4);
              *(_BYTE *)(a4 + 4) = v70 + 1;
              if ( v70 > 0x63 )
                goto LABEL_91;
              *(_DWORD *)(v67 + 4 * v70) = v69;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: link_id: %d added freq:%d ",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "cm_update_rso_freq_list_from_partner_link",
                *(unsigned __int8 *)(v68 + 6),
                **(unsigned __int16 **)(v68 + 32));
            }
          }
        }
        if ( *(_DWORD *)(v68 + 72) | *(unsigned __int16 *)(v68 + 76) )
        {
          if ( *(unsigned __int8 *)(v68 + 54) != 255 )
          {
            v71 = **(unsigned __int16 **)(v68 + 80);
            if ( !wlan_is_channel_present_in_list((int *)(a4 + 8), *(unsigned __int8 *)(a4 + 4), v71) )
            {
              v72 = *(unsigned __int8 *)(a4 + 4);
              *(_BYTE *)(a4 + 4) = v72 + 1;
              if ( v72 > 0x63 )
                goto LABEL_91;
              *(_DWORD *)(v67 + 4 * v72) = v71;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: link_id: %d added freq:%d ",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "cm_update_rso_freq_list_from_partner_link",
                *(unsigned __int8 *)(v68 + 54),
                **(unsigned __int16 **)(v68 + 80));
            }
          }
        }
        if ( *(_DWORD *)(v68 + 120) | *(unsigned __int16 *)(v68 + 124) )
        {
          if ( *(unsigned __int8 *)(v68 + 102) != 255 )
          {
            v73 = **(unsigned __int16 **)(v68 + 128);
            if ( !wlan_is_channel_present_in_list((int *)(a4 + 8), *(unsigned __int8 *)(a4 + 4), v73) )
            {
              v74 = *(unsigned __int8 *)(a4 + 4);
              *(_BYTE *)(a4 + 4) = v74 + 1;
              if ( v74 > 0x63 )
                goto LABEL_91;
              *(_DWORD *)(v67 + 4 * v74) = v73;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: link_id: %d added freq:%d ",
                v11,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                "cm_update_rso_freq_list_from_partner_link",
                *(unsigned __int8 *)(v68 + 102),
                **(unsigned __int16 **)(v68 + 128));
            }
          }
        }
      }
      if ( *(_BYTE *)(a3 + 976) )
      {
        v75 = 0;
        v76 = a3 + 980;
        do
        {
          v77 = *(unsigned __int8 *)(a4 + 4);
          if ( v77 > 0x63 )
            break;
          if ( v75 == 100 )
            goto LABEL_91;
          if ( !wlan_is_channel_present_in_list((int *)(a4 + 8), v77, *(_DWORD *)(v76 + 4 * v75)) )
          {
            v78 = *(unsigned __int8 *)(a4 + 4);
            v79 = *(_DWORD *)(v76 + 4 * v75);
            *(_BYTE *)(a4 + 4) = v78 + 1;
            if ( v78 > 0x63 )
              goto LABEL_91;
            *(_DWORD *)(a4 + 8 + 4 * v78) = v79;
          }
          ++v75;
        }
        while ( v75 < *(unsigned __int8 *)(a3 + 976) );
      }
LABEL_18:
      v33 = *(unsigned __int8 *)(a4 + 4);
      if ( a5 == 9 || *(_BYTE *)(a4 + 4) )
      {
LABEL_41:
        if ( v33 )
        {
          v51 = 0;
          v52 = 2;
          while ( v52 != 102 )
          {
            v53 = snprintf((char *)v80 + v51, (unsigned __int8)(0x80 - v51), " %d", *(_DWORD *)(a4 + 4 * v52));
            v32 = *(unsigned __int8 *)(a4 + 4);
            if ( ((v51 + v53) & 0x80) == 0 )
            {
              v54 = v52 - 1;
              v51 += v53;
              ++v52;
              if ( v54 < v32 )
                continue;
            }
            goto LABEL_48;
          }
LABEL_91:
          __break(0x5512u);
        }
        v32 = 0;
        goto LABEL_48;
      }
      v34 = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
      if ( *(_BYTE *)(v19 + 1977) == 1 )
      {
        v35 = v34;
        if ( wlan_reg_is_5ghz_ch_freq(v34) )
        {
          v36 = 2;
          if ( !*(_DWORD *)(v19 + 6392) )
            goto LABEL_39;
        }
        else
        {
          if ( wlan_reg_is_24ghz_ch_freq(v35) )
            v36 = 1;
          else
            v36 = 3;
          if ( !*(_DWORD *)(v19 + 6392) )
          {
LABEL_39:
            v33 = 0;
LABEL_40:
            *(_BYTE *)(a4 + 4) = v33;
            *(_BYTE *)(a4 + 408) = 2;
            goto LABEL_41;
          }
        }
      }
      else
      {
        v36 = 0;
        if ( !*(_DWORD *)(v19 + 6392) )
          goto LABEL_39;
      }
      v33 = 0;
      v37 = 0;
      v38 = v19 + 5992;
      while ( 1 )
      {
        v39 = v37;
        if ( (wlan_reg_is_dsrc_freq() & 1) == 0
          && (cm_is_dfs_unsafe_extra_band_chan(a2, v19, *(_DWORD *)(v38 + 4 * v39), v36) & 1) == 0 )
        {
          if ( v33 >= 0x64 )
            goto LABEL_91;
          *(_DWORD *)(a4 + 8 + 4LL * v33++) = *(_DWORD *)(v38 + 4 * v39);
        }
        v37 = v39 + 1;
        if ( *(_DWORD *)(v19 + 6392) <= (unsigned int)(unsigned __int8)(v39 + 1) )
          goto LABEL_40;
      }
    }
    if ( !(unsigned int)cm_populate_roam_chan_list(a2, result, a4, a3 + 112) )
    {
      v31 = 1;
LABEL_17:
      *(_BYTE *)(a4 + 408) = v31;
      goto LABEL_18;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to copy channels to roam list",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_fetch_ch_lst_from_ini");
    result = qdf_trace_msg(
               0x68u,
               2u,
               "%s: Fetch channel list from ini failed",
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               "cm_fill_rso_channel_list");
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
