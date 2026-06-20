__int64 __fastcall wlan_hdd_send_avoid_freq_for_dnbs(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w22
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x2
  unsigned int v31; // w19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w21
  int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w0
  _BYTE *v51; // x23
  unsigned int chan_enum_for_freq; // w0
  int v53; // w0
  unsigned int v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x10
  __int64 v64; // x11
  int v65; // w13
  __int64 v66; // x10
  __int64 v67; // x8
  __int64 v68; // x9
  _BYTE *v69; // x11
  __int64 v70; // x12
  _BYTE *v71; // x13
  __int64 v72; // x14
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  _BYTE v90[680]; // [xsp+0h] [xbp-2B0h] BYREF
  __int64 v91; // [xsp+2A8h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v90, 0, sizeof(v90));
  qdf_trace_msg(0x33u, 8u, "%s: enter", v4, v5, v6, v7, v8, v9, v10, v11, "wlan_hdd_send_avoid_freq_for_dnbs");
  if ( !a1 )
  {
    v30 = "%s: invalid param";
LABEL_6:
    qdf_trace_msg(
      0x33u,
      2u,
      v30,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_hdd_send_avoid_freq_for_dnbs",
      *(_QWORD *)v90);
    v31 = -22;
    goto LABEL_38;
  }
  qdf_mem_set(v90, 0x2A8u, 0);
  if ( a2 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a2) )
    {
      v20 = wlan_reg_min_24ghz_chan_freq();
      v21 = wlan_reg_max_24ghz_chan_freq();
    }
    else
    {
      if ( !wlan_reg_is_5ghz_ch_freq(a2) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: invalid channel freq:%d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_hdd_send_avoid_freq_for_dnbs",
          a2);
        v31 = -22;
        goto LABEL_38;
      }
      v20 = wlan_reg_min_5ghz_chan_freq();
      v21 = wlan_reg_max_5ghz_chan_freq();
    }
    v40 = v21;
    if ( v20 >= a2 || v21 <= a2 )
    {
      v51 = &v90[8];
      *(_DWORD *)v90 = 1;
      if ( v20 == a2 )
      {
        chan_enum_for_freq = wlan_reg_get_chan_enum_for_freq(a2, v22, v23, v24, v25, v26, v27, v28, v29);
        if ( chan_enum_for_freq > 0x64 )
          *(_DWORD *)&v90[4] = -22;
        else
          *(_DWORD *)&v90[4] = wlan_reg_ch_to_freq(chan_enum_for_freq + 1);
      }
      else
      {
        *(_DWORD *)&v90[4] = v20;
        v53 = wlan_reg_get_chan_enum_for_freq(a2, v22, v23, v24, v25, v26, v27, v28, v29);
        if ( (unsigned int)(v53 - 102) >= 0xFFFFFF9B )
          v40 = wlan_reg_ch_to_freq(v53 - 1);
        else
          v40 = -22;
      }
    }
    else
    {
      *(_DWORD *)v90 = 2;
      *(_DWORD *)&v90[4] = v20;
      v41 = wlan_reg_get_chan_enum_for_freq(a2, v22, v23, v24, v25, v26, v27, v28, v29);
      if ( (unsigned int)(v41 - 102) >= 0xFFFFFF9B )
        v50 = wlan_reg_ch_to_freq(v41 - 1);
      else
        v50 = -22;
      *(_DWORD *)&v90[8] = v50;
      v51 = &v90[24];
      v54 = wlan_reg_get_chan_enum_for_freq(a2, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( v54 > 0x64 )
        *(_DWORD *)&v90[20] = -22;
      else
        *(_DWORD *)&v90[20] = wlan_reg_ch_to_freq(v54 + 1);
    }
    *(_DWORD *)v51 = v40;
    mutex_lock(a1 + 3184);
    memcpy((void *)(a1 + 2500), v90, 0x2A8u);
    v63 = *(unsigned int *)(a1 + 1820);
    if ( (_DWORD)v63 )
    {
      v64 = *(unsigned int *)v90;
      if ( *(_DWORD *)v90 < 0x2Bu )
      {
        if ( (unsigned int)v63 > 42 - *(_DWORD *)v90 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: avoid freq overflow",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "wlan_hdd_merge_avoid_freqs");
          mutex_unlock(a1 + 3184);
          v30 = "%s: avoid freq merge failed";
          goto LABEL_6;
        }
        v65 = *(_DWORD *)v90 + v63;
        v66 = 16 * v63;
        v67 = 0;
        v68 = (16LL * *(unsigned int *)v90) | 4;
        *(_DWORD *)v90 = v65;
        v69 = &v90[16 * v64 + 4];
        v70 = a1 + 1824;
        while ( 1 )
        {
          if ( v67 == 672 )
            goto LABEL_40;
          if ( (unsigned __int64)(v68 + v67) > 0x2A7 )
            break;
          v71 = &v69[v67];
          *(_DWORD *)&v69[v67] = *(_DWORD *)(v70 + v67);
          if ( (unsigned __int64)(v68 + v67) > 0x2A3 )
            break;
          v72 = v70 + v67;
          v67 += 16;
          *((_DWORD *)v71 + 1) = *(_DWORD *)(v72 + 4);
          if ( v66 == v67 )
            goto LABEL_36;
        }
        __break(1u);
      }
LABEL_40:
      __break(0x5512u);
    }
  }
  else
  {
    mutex_lock(a1 + 3184);
    qdf_mem_set((void *)(a1 + 2500), 0x2A8u, 0);
    if ( *(_DWORD *)(a1 + 1820) )
      memcpy(v90, (const void *)(a1 + 1820), sizeof(v90));
  }
LABEL_36:
  mutex_unlock(a1 + 3184);
  v31 = wlan_hdd_send_avoid_freq_event(a1, v90, v73, v74, v75, v76, v77, v78, v79, v80);
  if ( v31 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: wlan_hdd_send_avoid_freq_event error:%d",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      "wlan_hdd_send_avoid_freq_for_dnbs",
      v31);
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return v31;
}
