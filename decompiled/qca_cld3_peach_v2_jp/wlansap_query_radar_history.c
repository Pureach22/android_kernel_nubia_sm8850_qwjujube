__int64 __fastcall wlansap_query_radar_history(__int64 a1, __int64 *a2, _DWORD *a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x21
  __int64 v8; // x22
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _DWORD *v18; // x22
  unsigned __int64 v19; // x27
  _QWORD *v20; // x19
  _WORD *v21; // x20
  __int64 v22; // x8
  unsigned __int64 v23; // x23
  unsigned int v24; // w24
  unsigned int v25; // w25
  _DWORD *v26; // x19
  __int64 *v27; // x20
  __int64 v28; // x0
  int _5g_bonded_channel_and_state_for_pwrmode; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x22
  unsigned int v39; // w26
  unsigned int v40; // w25
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int16 *v49; // x8
  int v50; // w9
  int v51; // t1
  __int64 v52; // x8
  __int64 v53; // x9
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int16 *v62; // x9
  int v63; // w10
  int v64; // t1
  __int64 v65; // x9
  __int64 v66; // x8
  __int64 v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v77; // [xsp+8h] [xbp-28h]
  __int64 v78; // [xsp+10h] [xbp-20h]
  __int64 *v79; // [xsp+18h] [xbp-18h]
  _QWORD v80[2]; // [xsp+20h] [xbp-10h] BYREF

  v80[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = _qdf_mem_malloc(0x268u, "wlansap_query_radar_history", 2562);
  if ( v6 )
  {
    v7 = (_DWORD *)v6;
    ucfg_dfs_getnol(*(_QWORD *)(a1 + 21560), v6);
    v8 = (unsigned int)(*v7 + 8);
    v9 = _qdf_mem_malloc(16 * v8, "wlansap_query_radar_history", 2570);
    if ( !v9 )
    {
      v24 = 2;
LABEL_40:
      _qdf_mem_free((__int64)v7);
      goto LABEL_41;
    }
    v77 = v8;
    v78 = v9;
    v18 = a3;
    v79 = a2;
    if ( *v7 )
    {
      v19 = 0;
      v20 = v7 + 4;
      v21 = (_WORD *)(v9 + 10);
      do
      {
        *v21 = *((_WORD *)v20 - 4);
        v22 = *v20;
        *((_BYTE *)v21 - 2) = 1;
        *(_QWORD *)(v21 - 5) = v22;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: radar hist[%d] freq %d time %llu radar",
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          "wlansap_query_radar_history",
          (unsigned int)v19,
          *((unsigned __int16 *)v20 - 4),
          *v20);
        v23 = v19 + 1;
        if ( v19 > 0x17 )
          break;
        v20 += 3;
        v21 += 8;
        ++v19;
      }
      while ( v23 < (unsigned int)*v7 );
    }
    else
    {
      LODWORD(v23) = 0;
    }
    if ( byte_855E28 != 1 || !qword_855E20 )
    {
      qdf_trace_msg(0x39u, 8u, "%s: cac hist empty", v10, v11, v12, v13, v14, v15, v16, v17, "sap_append_cac_history");
      v26 = v18;
      v38 = v78;
      v27 = v79;
LABEL_39:
      v67 = ktime_get_with_offset(1);
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: hist count %d cur %llu",
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        "wlansap_query_radar_history",
        (unsigned int)v23,
        v67 / 1000);
      v24 = 0;
      *v27 = v38;
      *v26 = v23;
      goto LABEL_40;
    }
    v25 = dword_855E34;
    v26 = v18;
    v27 = v79;
    if ( !dword_855E2C )
    {
      v38 = v78;
      if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), dword_855E34, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
      {
        if ( (_DWORD)v23 )
        {
          v62 = (unsigned __int16 *)(v78 + 10);
          v63 = v23;
          while ( 1 )
          {
            v64 = *v62;
            v62 += 8;
            if ( v64 == (unsigned __int16)v25 )
              break;
            if ( !--v63 )
              goto LABEL_34;
          }
        }
        else
        {
LABEL_34:
          if ( (unsigned int)v23 < v77 )
          {
            v65 = v78 + 16LL * (unsigned int)v23;
            *(_WORD *)(v65 + 10) = v25;
            v66 = qword_855E20;
            *(_BYTE *)(v65 + 8) = 0;
            *(_QWORD *)v65 = v66;
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: radar hist[%d] freq %d time %llu no radar",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "sap_append_cac_history",
              (unsigned int)v23,
              v25,
              qword_855E20);
            LODWORD(v23) = v23 + 1;
          }
        }
      }
      goto LABEL_39;
    }
    v28 = *(_QWORD *)(a1 + 21560);
    v80[0] = 0;
    _5g_bonded_channel_and_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(
                                                 v28,
                                                 dword_855E34,
                                                 dword_855E2C,
                                                 v80,
                                                 0,
                                                 v10,
                                                 v11,
                                                 v12,
                                                 v13,
                                                 v14,
                                                 v15,
                                                 v16,
                                                 v17);
    v38 = v78;
    if ( !v80[0] || _5g_bonded_channel_and_state_for_pwrmode == 4 )
    {
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: invalid freq %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "sap_append_cac_history",
        v25);
    }
    else
    {
      v39 = *(unsigned __int16 *)v80[0];
      if ( v39 <= *(unsigned __int16 *)((char *)&off_0 + v80[0] + 2) )
      {
        v40 = v23;
        do
        {
          if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                               *(_QWORD *)(a1 + 21560),
                               (unsigned __int16)v39,
                               0,
                               v30,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37) == 4 )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "%s: invalid ch freq %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "sap_append_cac_history",
              (unsigned __int16)v39);
          }
          else if ( (wlan_reg_is_dfs_for_freq(
                       *(_QWORD *)(a1 + 21560),
                       (unsigned __int16)v39,
                       v41,
                       v42,
                       v43,
                       v44,
                       v45,
                       v46,
                       v47,
                       v48)
                   & 1) != 0 )
          {
            if ( (_DWORD)v23 )
            {
              v49 = (unsigned __int16 *)(v78 + 10);
              v50 = v23;
              while ( 1 )
              {
                v51 = *v49;
                v49 += 8;
                if ( v51 == (unsigned __int16)v39 )
                  break;
                if ( !--v50 )
                  goto LABEL_26;
              }
            }
            else
            {
LABEL_26:
              if ( v40 < v77 )
              {
                v52 = v78 + 16LL * v40;
                *(_WORD *)(v52 + 10) = v39;
                v53 = qword_855E20;
                *(_BYTE *)(v52 + 8) = 0;
                *(_QWORD *)v52 = v53;
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "%s: radar hist[%d] freq %d time %llu no radar",
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  v37,
                  "sap_append_cac_history",
                  v40++,
                  (unsigned __int16)v39,
                  qword_855E20);
              }
            }
          }
          LOWORD(v39) = v39 + 20;
        }
        while ( *(unsigned __int16 *)((char *)&off_0 + v80[0] + 2) >= (unsigned int)(unsigned __int16)v39 );
        goto LABEL_38;
      }
    }
    v40 = v23;
LABEL_38:
    LODWORD(v23) = v40;
    goto LABEL_39;
  }
  v24 = 2;
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return v24;
}
