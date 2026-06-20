__int64 __fastcall sap_select_channel(
        __int64 a1,
        __int64 a2,
        _QWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 v13; // w1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  __int64 v23; // x28
  unsigned int v24; // w1
  unsigned int *v25; // x24
  __int64 v26; // x27
  __int64 v27; // x8
  __int64 v28; // x1
  char is_channel_present_in_acs_list; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned __int8 v38; // w0
  unsigned int v39; // w22
  __int64 v40; // x8
  unsigned __int64 v41; // x9
  __int64 v42; // x10
  bool v43; // w11
  unsigned int next_lower_bandwidth; // w23
  __int64 v45; // x26
  __int64 v46; // x25
  __int64 v47; // x10
  __int64 v48; // x8
  unsigned __int64 v49; // x9
  unsigned int v50; // w27
  unsigned int v51; // w10
  __int64 v52; // x11
  bool v53; // w13
  __int64 v54; // x1
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w9
  unsigned int v64; // w9
  unsigned int v65; // w8
  unsigned int v66; // w9
  int v67; // w11
  int v68; // w12
  int *v69; // x10
  int v70; // w13
  __int64 v71; // x8
  int v72; // w9
  _QWORD v74[3]; // [xsp+8h] [xbp-38h] BYREF
  int v75; // [xsp+20h] [xbp-20h] BYREF
  int v76; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v77; // [xsp+28h] [xbp-18h] BYREF
  __int64 v78; // [xsp+30h] [xbp-10h]
  __int64 v79; // [xsp+38h] [xbp-8h]

  v79 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_BYTE *)(a2 + 12);
  v77 = 0;
  v78 = 0;
  v76 = 0;
  v75 = 0;
  if ( !(unsigned int)sap_sort_channel_list(a1, v13, a3, &v77, &v76, &v75, 0, a4, a5, a6, a7, a8, a9, a10, a11) )
  {
    v23 = (unsigned __int8)v78;
    if ( (_BYTE)v78 )
    {
      v24 = 0;
      v25 = (unsigned int *)(v77 + 12);
      v26 = (unsigned __int8)v78;
      while ( 1 )
      {
        if ( *((_BYTE *)v25 + 8) == 1 )
        {
          v27 = *(_QWORD *)(a2 + 1544);
          v22 = *(v25 - 3);
          v28 = *(_QWORD *)(v27 + 16);
          if ( v28 && *(_BYTE *)(v27 + 24) )
          {
            is_channel_present_in_acs_list = wlansap_is_channel_present_in_acs_list(
                                               v22,
                                               v28,
                                               *(unsigned __int8 *)(v27 + 24));
            v24 = 0;
            if ( (is_channel_present_in_acs_list & 1) != 0 && v22 )
            {
LABEL_14:
              if ( !wlan_reg_is_24ghz_ch_freq(v22)
                || (v38 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), v22, v30, v31, v32, v33, v34, v35, v36, v37),
                    (*(_BYTE *)(a2 + 1536) & 1) != 0)
                || v38 <= 0xBu && ((1 << v38) & 0x842) != 0 )
              {
                v39 = *v25;
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: ACS Selected freq %d, weight %d",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "sap_select_channel",
                  v22,
                  *v25);
                goto LABEL_23;
              }
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: freq %d is overlapping, skipped",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "sap_select_channel",
                v22);
              v24 = v22;
            }
          }
          else
          {
            if ( v22 )
              goto LABEL_14;
            v24 = 0;
          }
        }
        --v26;
        v25 += 6;
        if ( !v26 )
        {
          v39 = 26664;
          v22 = v24;
          goto LABEL_23;
        }
      }
    }
    v22 = 0;
    v39 = 26664;
LABEL_23:
    v40 = *(_QWORD *)(a2 + 1544);
    v41 = *(unsigned int *)(v40 + 556);
    if ( !(_DWORD)v41 )
      goto LABEL_29;
    v42 = 0;
    v43 = 1;
    do
    {
      if ( v42 == 102 )
LABEL_80:
        __break(0x5512u);
      if ( *(_DWORD *)(v40 + 4 * v42 + 44) == v22 )
        break;
      v43 = ++v42 < v41;
    }
    while ( v41 != v42 );
    if ( !v43 )
    {
LABEL_29:
      next_lower_bandwidth = *(unsigned __int16 *)(v40 + 42);
      v45 = v77;
      while ( 1 )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: check bw %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "sap_select_channel",
          next_lower_bandwidth);
        if ( (_DWORD)v23 )
        {
          v46 = 0;
          while ( 1 )
          {
            v47 = v45 + 24 * v46;
            memset(v74, 0, sizeof(v74));
            if ( *(_BYTE *)(v47 + 20) == 1 )
            {
              v48 = *(_QWORD *)(a2 + 1544);
              v49 = *(unsigned int *)(v48 + 556);
              if ( (_DWORD)v49 )
              {
                v50 = *(_DWORD *)v47;
                v51 = *(_DWORD *)(v47 + 12);
                v52 = 0;
                v53 = 1;
                do
                {
                  if ( v52 == 102 )
                    goto LABEL_80;
                  if ( *(_DWORD *)(v48 + 44 + 4 * v52) == v50 )
                    break;
                  v53 = ++v52 < v49;
                }
                while ( v49 != v52 );
                if ( v53 && v51 <= v39 && v22 != v50 )
                {
                  v54 = *(_QWORD *)(v48 + 16);
                  if ( !v54
                    || !*(_BYTE *)(v48 + 24)
                    || (wlansap_is_channel_present_in_acs_list(v50, v54, *(unsigned __int8 *)(v48 + 24)) & 1) != 0 )
                  {
                    if ( v50 )
                    {
                      LODWORD(v74[0]) = next_lower_bandwidth;
                      v55 = sap_acs_set_puncture_support(a2, v74);
                      wlan_reg_set_channel_params_for_pwrmode(
                        *(_QWORD *)(a1 + 21632),
                        v50,
                        0,
                        (__int64)v74,
                        0,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        v61,
                        v62);
                      if ( LODWORD(v74[0]) == next_lower_bandwidth )
                        break;
                    }
                  }
                }
              }
            }
            if ( ++v46 == v23 )
              goto LABEL_50;
          }
          LODWORD(v46) = (unsigned __int8)v46;
          *(_WORD *)(*(_QWORD *)(a2 + 1544) + 42LL) = next_lower_bandwidth;
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: Changed best freq to %d Preferred freq bw %d",
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            "sap_select_channel",
            v50,
            next_lower_bandwidth);
          v22 = v50;
        }
        else
        {
          LODWORD(v46) = 0;
        }
        if ( (_DWORD)v46 != (_DWORD)v23 )
          break;
LABEL_50:
        if ( next_lower_bandwidth - 8 >= 0xFFFFFFF9 && next_lower_bandwidth - 5 >= 2 )
        {
          next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth(next_lower_bandwidth);
          if ( next_lower_bandwidth != 8 )
            continue;
        }
        break;
      }
      v40 = *(_QWORD *)(a2 + 1544);
    }
    v63 = v75;
    *(_DWORD *)(v40 + 564) = v22;
    if ( v63 != 8 || *(_WORD *)(*(_QWORD *)(a2 + 1544) + 42LL) != 1 )
    {
LABEL_78:
      _qdf_mem_free(v77);
      goto LABEL_79;
    }
    v64 = (unsigned __int8)wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), v22, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v76 )
      v65 = 9;
    else
      v65 = 7;
    if ( v64 < 5 || v65 < v64 )
    {
      if ( (unsigned __int8)(v64 - 1) > 3u )
      {
        if ( v64 > 0xD || v65 > v64 )
        {
          if ( v64 != 14 )
          {
LABEL_77:
            *(_DWORD *)(a2 + 4) = *(_DWORD *)(*(_QWORD *)(a2 + 1544) + 568LL);
            goto LABEL_78;
          }
          v71 = *(_QWORD *)(a2 + 1544);
          v72 = 0;
LABEL_76:
          *(_DWORD *)(v71 + 568) = v72;
          goto LABEL_77;
        }
LABEL_74:
        v71 = *(_QWORD *)(a2 + 1544);
        v72 = *(_DWORD *)(v71 + 564) - 20;
        goto LABEL_76;
      }
    }
    else if ( (_DWORD)v23 )
    {
      v66 = v64 + 20;
      v67 = 26664;
      v68 = 26664;
      v69 = (int *)(v77 + 12);
      do
      {
        v70 = *(v69 - 3);
        if ( v70 == v22 - 20 )
          v68 = *v69;
        if ( v70 == v66 )
          v67 = *v69;
        --v23;
        v69 += 6;
      }
      while ( v23 );
      if ( v68 < v67 )
        goto LABEL_74;
    }
    v71 = *(_QWORD *)(a2 + 1544);
    v72 = *(_DWORD *)(v71 + 564) + 20;
    goto LABEL_76;
  }
  qdf_trace_msg(
    0x39u,
    2u,
    "%s: vdev %d failed to sort sap channel list",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "sap_select_channel",
    *(unsigned __int8 *)(a2 + 12));
  v22 = 0;
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return v22;
}
