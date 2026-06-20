__int64 __fastcall policy_mgr_get_fourth_connection_pcl_table_index(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned int v12; // w0
  unsigned int v13; // w21
  int v14; // w0
  int v15; // w26
  unsigned int v16; // w21
  unsigned int v17; // w22
  unsigned int v18; // w23
  unsigned int v19; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w20
  bool v38; // zf
  int v39; // w8
  int v40; // w9
  bool is_24ghz_ch_freq; // w0
  int v42; // w8
  bool v43; // zf
  int v44; // w9
  bool v45; // w0
  bool v46; // w0
  __int64 v47; // [xsp+0h] [xbp-D0h]
  _BYTE v48[4]; // [xsp+2Ch] [xbp-A4h] BYREF
  _BYTE v49[4]; // [xsp+30h] [xbp-A0h] BYREF
  int v50; // [xsp+34h] [xbp-9Ch] BYREF
  int v51; // [xsp+38h] [xbp-98h] BYREF
  char v52; // [xsp+3Ch] [xbp-94h]
  int v53; // [xsp+40h] [xbp-90h] BYREF
  char v54; // [xsp+44h] [xbp-8Ch]
  int v55; // [xsp+48h] [xbp-88h] BYREF
  char v56; // [xsp+4Ch] [xbp-84h]
  _QWORD v57[2]; // [xsp+50h] [xbp-80h] BYREF
  int v58; // [xsp+60h] [xbp-70h]
  _QWORD v59[2]; // [xsp+68h] [xbp-68h] BYREF
  int v60; // [xsp+78h] [xbp-58h]
  _QWORD v61[2]; // [xsp+80h] [xbp-50h] BYREF
  int v62; // [xsp+90h] [xbp-40h]
  _QWORD v63[2]; // [xsp+98h] [xbp-38h] BYREF
  int v64; // [xsp+A8h] [xbp-28h]
  __int64 v65; // [xsp+B0h] [xbp-20h] BYREF
  __int64 v66; // [xsp+B8h] [xbp-18h]
  int v67; // [xsp+C0h] [xbp-10h]
  __int64 v68; // [xsp+C8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 34;
  v49[0] = 0;
  v48[0] = 0;
  v67 = 0;
  v65 = 0;
  v66 = 0;
  v64 = 0;
  v63[0] = 0;
  v63[1] = 0;
  v62 = 0;
  v61[0] = 0;
  v61[1] = 0;
  v60 = 0;
  v59[0] = 0;
  v59[1] = 0;
  v56 = 0;
  v55 = 0;
  v54 = 0;
  v53 = 0;
  v58 = 0;
  v57[0] = 0;
  v57[1] = 0;
  v52 = 0;
  v51 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_get_fourth_connection_pcl_table_index");
    v36 = 34;
    goto LABEL_12;
  }
  v11 = context;
  qdf_mutex_acquire(context + 56);
  v12 = policy_mgr_mode_specific_connection_count(a1, 1, &v65);
  if ( v12 >= 6 )
    goto LABEL_284;
  v13 = v12;
  v14 = policy_mgr_mode_specific_connection_count(a1, 3, (_DWORD *)&v65 + v12);
  if ( v14 + v13 > 5 )
    goto LABEL_284;
  v15 = policy_mgr_mode_specific_connection_count(a1, 2, (_DWORD *)&v65 + v14 + v13) + v14;
  v16 = v15 + v13;
  v17 = policy_mgr_mode_specific_connection_count(a1, 0, v63);
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    v49,
    (__int64)&v55,
    v48,
    (__int64)&v53,
    (unsigned __int64)v57,
    (unsigned __int64)&v51,
    0);
  v18 = policy_mgr_mode_specific_connection_count(a1, 4, v61);
  v19 = policy_mgr_mode_specific_connection_count(a1, 5, v59);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: sap/go/cli:%d sta:%d ndi:%d nan disc:%d ml_sta:%d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "policy_mgr_get_fourth_connection_pcl_table_index",
    v16,
    v17,
    v18,
    v19,
    v49[0]);
  if ( v16 == 2 && v49[0] == 1 )
  {
    if ( (unsigned __int8)v55 <= 4u && (unsigned int)v65 <= 4 && HIDWORD(v65) < 5 )
      goto LABEL_9;
    goto LABEL_284;
  }
  if ( v16 != 2 || v17 != 1 || v49[0] )
  {
    if ( v49[0] == 2 && v16 == 1 )
    {
      if ( (unsigned int)v65 >= 5 )
        goto LABEL_284;
      goto LABEL_9;
    }
    if ( v19 == 1 && v49[0] == 2 )
    {
      v36 = 29;
      goto LABEL_10;
    }
    if ( v16 == 1 && v17 == 2 && v49[0] <= 1u )
    {
      if ( (unsigned int)v65 <= 4 && LODWORD(v63[0]) <= 4 && HIDWORD(v63[0]) <= 4 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: channel: sap0: %d, sta0: %d, sta1: %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "policy_mgr_get_fourth_connection_pcl_table_index",
          *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1),
          *((unsigned int *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1),
          *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1));
        if ( LODWORD(v63[0]) <= 4 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
          {
            if ( (unsigned int)v65 > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
            {
              if ( HIDWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                goto LABEL_116;
              if ( HIDWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                goto LABEL_116;
            }
          }
          if ( HIDWORD(v63[0]) > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
          {
            if ( (unsigned int)v65 > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
            {
              if ( LODWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
                goto LABEL_116;
              if ( LODWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
              {
LABEL_116:
                v36 = 2;
                goto LABEL_10;
              }
            }
          }
          if ( LODWORD(v63[0]) <= 4 )
          {
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
            {
              if ( (unsigned int)v65 > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
              {
                if ( HIDWORD(v63[0]) > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                  goto LABEL_156;
              }
            }
            if ( HIDWORD(v63[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
            {
              if ( (unsigned int)v65 > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
              {
                if ( LODWORD(v63[0]) > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
                  goto LABEL_156;
              }
            }
            if ( LODWORD(v63[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
            {
              if ( (unsigned int)v65 > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
              {
                if ( HIDWORD(v63[0]) > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                  goto LABEL_156;
              }
            }
            if ( HIDWORD(v63[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
            {
              if ( (unsigned int)v65 > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
              {
                if ( LODWORD(v63[0]) > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
                {
LABEL_156:
                  v36 = 3;
                  goto LABEL_10;
                }
              }
            }
            if ( LODWORD(v63[0]) <= 4 )
            {
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
              {
                if ( (unsigned int)v65 > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
                {
                  if ( HIDWORD(v63[0]) > 4 )
                    goto LABEL_284;
                  if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                    goto LABEL_93;
                }
              }
              if ( HIDWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
              {
                if ( (unsigned int)v65 > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
                {
                  if ( LODWORD(v63[0]) > 4 )
                    goto LABEL_284;
                  if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
                    goto LABEL_93;
                }
              }
              if ( LODWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
              {
                if ( (unsigned int)v65 > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
                {
                  if ( HIDWORD(v63[0]) > 4 )
                    goto LABEL_284;
                  if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
                    goto LABEL_80;
                }
              }
              if ( HIDWORD(v63[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v63[0]) + 1)) )
              {
                if ( (unsigned int)v65 > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
                {
                  if ( LODWORD(v63[0]) > 4 )
                    goto LABEL_284;
                  if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
                  {
LABEL_80:
                    v36 = 31;
                    goto LABEL_10;
                  }
                }
              }
              goto LABEL_9;
            }
          }
        }
      }
    }
    else
    {
      v38 = v19 == 1 && v18 == 1;
      v39 = v38;
      if ( !v38 || v15 || v16 != 1 )
      {
        if ( v15 == 1 )
          v40 = v39;
        else
          v40 = 0;
        if ( v40 == 1 )
        {
          if ( (unsigned int)v65 > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_177;
          }
          if ( (unsigned int)v65 > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_177;
          }
          if ( (unsigned int)v65 > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_177;
          }
          if ( (unsigned int)v65 > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
            {
LABEL_177:
              v36 = 11;
              goto LABEL_10;
            }
          }
          goto LABEL_9;
        }
        if ( v17 != 1 )
          v39 = 0;
        if ( v39 == 1 )
        {
          if ( LODWORD(v63[0]) > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_228;
          }
          if ( LODWORD(v63[0]) > 4 )
            goto LABEL_284;
          if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_228;
          }
          if ( LODWORD(v63[0]) > 4 )
            goto LABEL_284;
          if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
            {
LABEL_228:
              v36 = 8;
              goto LABEL_10;
            }
          }
          if ( LODWORD(v63[0]) > 4 )
            goto LABEL_284;
          if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
            goto LABEL_9;
          if ( LODWORD(v61[0]) > 4 )
            goto LABEL_284;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1));
          v42 = 34;
          v43 = !is_24ghz_ch_freq;
          v44 = 8;
        }
        else
        {
          if ( v19 == 1 && v16 == 1 && v17 == 1 )
          {
            v36 = 28;
            goto LABEL_10;
          }
          if ( v19 == 1 && v18 == 2 )
          {
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
            {
              if ( HIDWORD(v61[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v61[0]) + 1)) )
                goto LABEL_247;
            }
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
            {
              if ( LODWORD(v61[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
                goto LABEL_247;
            }
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
            {
              if ( LODWORD(v61[0]) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              {
LABEL_247:
                v36 = 9;
                goto LABEL_10;
              }
            }
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              goto LABEL_9;
            if ( LODWORD(v61[0]) > 4 )
              goto LABEL_284;
            v45 = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1));
            v42 = 34;
            v43 = !v45;
            v44 = 9;
          }
          else
          {
            if ( v16 != 3 )
              goto LABEL_9;
            if ( ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
            {
              if ( (unsigned int)v65 > 4 || HIDWORD(v65) > 4 || (unsigned int)v66 > 4 )
                goto LABEL_284;
              policy_mgr_get_index_for_3_given_freq_sbs(
                v11,
                &v50,
                *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1),
                *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1),
                *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v66 + 1));
            }
            else if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
            {
              if ( (unsigned int)v65 > 4 || HIDWORD(v65) > 4 || (unsigned int)v66 > 4 )
                goto LABEL_284;
              policy_mgr_get_index_for_3_given_freq_dbs(
                &v50,
                *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1),
                *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1),
                *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v66 + 1));
            }
            v36 = v50;
            if ( v50 != 34 )
              goto LABEL_10;
            if ( (unsigned int)v65 > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
            {
              if ( HIDWORD(v65) > 4 )
                goto LABEL_284;
              if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
              {
                if ( (unsigned int)v66 > 4 )
                  goto LABEL_284;
                if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v66 + 1)) )
                {
                  v36 = 12;
                  goto LABEL_10;
                }
              }
            }
            if ( (unsigned int)v65 > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
              goto LABEL_9;
            if ( HIDWORD(v65) > 4 )
              goto LABEL_284;
            if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
              goto LABEL_9;
            if ( (unsigned int)v66 > 4 )
              goto LABEL_284;
            v46 = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v66 + 1));
            v42 = 13;
            v43 = !v46;
            v44 = 34;
          }
        }
        if ( v43 )
          v36 = v42;
        else
          v36 = v44;
        goto LABEL_10;
      }
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
      {
        if ( LODWORD(v61[0]) > 4 )
          goto LABEL_284;
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
        {
          v36 = 5;
          goto LABEL_10;
        }
      }
      if ( (unsigned int)v65 <= 4 )
      {
        if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
        {
          if ( LODWORD(v61[0]) > 4 )
            goto LABEL_284;
          if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
          {
            v36 = 6;
            goto LABEL_10;
          }
        }
        if ( (unsigned int)v65 <= 4 )
        {
          if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
          {
            if ( LODWORD(v61[0]) <= 4 )
            {
              if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v61[0]) + 1)) )
              {
                v36 = 7;
                goto LABEL_10;
              }
              goto LABEL_9;
            }
            goto LABEL_284;
          }
          goto LABEL_9;
        }
      }
    }
LABEL_284:
    __break(0x5512u);
  }
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( LODWORD(v63[0]) > 4 )
    goto LABEL_284;
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: channel: sap0: %d, sap1: %d, sta0: %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "policy_mgr_get_fourth_connection_pcl_table_index",
    *((unsigned int *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1),
    *((unsigned int *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1),
    *((unsigned int *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1));
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_35;
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_35;
    }
  }
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
        goto LABEL_35;
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
      {
LABEL_35:
        v36 = 0;
        goto LABEL_10;
      }
    }
  }
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_64;
    }
  }
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
        goto LABEL_64;
    }
  }
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_64;
    }
  }
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
      {
LABEL_64:
        v36 = 1;
        goto LABEL_10;
      }
    }
  }
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_80;
    }
  }
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
        goto LABEL_80;
    }
  }
  if ( (unsigned int)v65 > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( HIDWORD(v65) > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
        goto LABEL_93;
    }
  }
  if ( HIDWORD(v65) > 4 )
    goto LABEL_284;
  if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v65) + 1)) )
  {
    if ( LODWORD(v63[0]) > 4 )
      goto LABEL_284;
    if ( wlan_reg_is_6ghz_chan_freq(*((_DWORD *)&pm_conc_connection_list + 9 * LODWORD(v63[0]) + 1)) )
    {
      if ( (unsigned int)v65 > 4 )
        goto LABEL_284;
      if ( wlan_reg_is_5ghz_ch_freq(*((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v65 + 1)) )
      {
LABEL_93:
        v36 = 30;
        goto LABEL_10;
      }
    }
  }
LABEL_9:
  v36 = 34;
LABEL_10:
  LODWORD(v47) = HIDWORD(qword_81C464);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: mode0:%d mode1:%d mode2:%d chan0:%d chan1:%d chan2:%d chain:%d index:%d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "policy_mgr_get_fourth_connection_pcl_table_index",
    (unsigned int)pm_conc_connection_list,
    (unsigned int)qword_81C464,
    (unsigned int)qword_81C488,
    HIDWORD(pm_conc_connection_list),
    v47,
    HIDWORD(qword_81C488),
    dword_81C450,
    v36);
  qdf_mutex_release(v11 + 56);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v36;
}
