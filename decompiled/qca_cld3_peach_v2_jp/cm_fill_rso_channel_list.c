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
  unsigned int v41; // w24
  int v42; // w24
  unsigned __int8 v43; // w24
  __int64 v44; // x21
  char v45; // w0
  unsigned __int64 v46; // x9
  unsigned int v47; // w25
  __int64 v48; // x27
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x9
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int64 v59; // x25
  __int64 v60; // x26
  unsigned int v61; // w1
  unsigned __int64 v62; // x8
  int v63; // w9
  _QWORD v64[17]; // [xsp+8h] [xbp-88h] BYREF

  v64[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a2 + 104);
  memset(v64, 0, 128);
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
            goto LABEL_75;
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
                   v64);
        goto LABEL_49;
      }
      operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
      if ( *(_BYTE *)(v19 + 1773) == 1 )
      {
        v41 = operation_chan_freq;
        if ( wlan_reg_is_5ghz_ch_freq(operation_chan_freq) )
        {
          v42 = 2;
        }
        else if ( wlan_reg_is_24ghz_ch_freq(v41) )
        {
          v42 = 1;
        }
        else
        {
          v42 = 3;
        }
      }
      else
      {
        v42 = 0;
      }
      if ( (unsigned int)*(unsigned __int8 *)(a3 + 272) - 1 > 0x62 )
      {
        LOBYTE(v47) = 0;
      }
      else
      {
        v47 = 0;
        v48 = 69;
        do
        {
          if ( (cm_is_dfs_unsafe_extra_band_chan(a2, v19, *(_DWORD *)(a3 + 4 * v48), v42) & 1) == 0 )
          {
            if ( v47 > 0x63 )
              goto LABEL_75;
            *(_DWORD *)(a4 + 8 + 4LL * v47++) = *(_DWORD *)(a3 + 4 * v48);
          }
          v49 = *(unsigned __int8 *)(a3 + 272);
          if ( v49 > 0x63 )
            break;
          v50 = v48 - 68;
          ++v48;
        }
        while ( v50 < v49 );
      }
      *(_BYTE *)(a4 + 4) = v47;
      *(_BYTE *)(a4 + 408) = 2;
      if ( *(_BYTE *)(a3 + 168) )
      {
        if ( (unsigned int)cm_populate_roam_chan_list(a2, v19, a4, a3 + 168) )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: Failed to copy channels to roam list",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "cm_add_ch_lst_from_roam_scan_list");
        }
        else
        {
          cm_dump_freq_list(a3 + 168);
          *(_BYTE *)(a4 + 408) = 2;
        }
      }
      if ( *(_BYTE *)(a3 + 960) )
      {
        v59 = 0;
        v60 = a3 + 964;
        do
        {
          v61 = *(unsigned __int8 *)(a4 + 4);
          if ( v61 > 0x63 )
            break;
          if ( v59 == 100 )
            goto LABEL_75;
          if ( !wlan_is_channel_present_in_list((int *)(a4 + 8), v61, *(_DWORD *)(v60 + 4 * v59)) )
          {
            v62 = *(unsigned __int8 *)(a4 + 4);
            v63 = *(_DWORD *)(v60 + 4 * v59);
            *(_BYTE *)(a4 + 4) = v62 + 1;
            if ( v62 > 0x63 )
              goto LABEL_75;
            *(_DWORD *)(a4 + 8 + 4 * v62) = v63;
          }
          ++v59;
        }
        while ( v59 < *(unsigned __int8 *)(a3 + 960) );
      }
LABEL_18:
      v33 = *(unsigned __int8 *)(a4 + 4);
      if ( a5 == 9 || *(_BYTE *)(a4 + 4) )
      {
LABEL_41:
        if ( v33 )
        {
          v43 = 0;
          v44 = 2;
          while ( v44 != 102 )
          {
            v45 = snprintf((char *)v64 + v43, (unsigned __int8)(0x80 - v43), " %d", *(_DWORD *)(a4 + 4 * v44));
            v32 = *(unsigned __int8 *)(a4 + 4);
            if ( ((v43 + v45) & 0x80) == 0 )
            {
              v46 = v44 - 1;
              v43 += v45;
              ++v44;
              if ( v46 < v32 )
                continue;
            }
            goto LABEL_48;
          }
LABEL_75:
          __break(0x5512u);
        }
        v32 = 0;
        goto LABEL_48;
      }
      v34 = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a2);
      if ( *(_BYTE *)(v19 + 1773) == 1 )
      {
        v35 = v34;
        if ( wlan_reg_is_5ghz_ch_freq(v34) )
        {
          v36 = 2;
          if ( !*(_DWORD *)(v19 + 6176) )
            goto LABEL_39;
        }
        else
        {
          if ( wlan_reg_is_24ghz_ch_freq(v35) )
            v36 = 1;
          else
            v36 = 3;
          if ( !*(_DWORD *)(v19 + 6176) )
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
        if ( !*(_DWORD *)(v19 + 6176) )
          goto LABEL_39;
      }
      v33 = 0;
      v37 = 0;
      v38 = v19 + 5776;
      while ( 1 )
      {
        v39 = v37;
        if ( (wlan_reg_is_dsrc_freq() & 1) == 0
          && (cm_is_dfs_unsafe_extra_band_chan(a2, v19, *(_DWORD *)(v38 + 4 * v39), v36) & 1) == 0 )
        {
          if ( v33 >= 0x64 )
            goto LABEL_75;
          *(_DWORD *)(a4 + 8 + 4LL * v33++) = *(_DWORD *)(v38 + 4 * v39);
        }
        v37 = v39 + 1;
        if ( *(_DWORD *)(v19 + 6176) <= (unsigned int)(unsigned __int8)(v39 + 1) )
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
