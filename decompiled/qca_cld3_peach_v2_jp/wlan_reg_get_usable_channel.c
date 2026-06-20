__int64 __fastcall wlan_reg_get_usable_channel(
        __int64 a1,
        unsigned __int64 a2,
        char a3,
        __int64 a4,
        unsigned int *a5,
        unsigned int a6)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned __int64 v21; // x23
  __int64 v22; // x22
  __int64 pdev_obj; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int16 band_from_cur_chan_list; // w0
  __int64 v33; // x19
  unsigned __int64 v34; // x23
  int *v35; // x28
  int v36; // w8
  int v37; // w8
  __int64 result; // x0
  int updated; // w0
  int v40; // w19
  int v41; // w8
  int v42; // w19
  __int64 v43; // x0
  __int64 psoc_obj; // x0
  unsigned int v45; // w9
  __int64 v46; // x19
  unsigned int v47; // w23
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x10
  _DWORD *v50; // x20
  unsigned __int64 v51; // x21
  _DWORD *v52; // x22
  unsigned int *v53; // x28
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  unsigned int v63; // w1
  unsigned int v64; // w19
  __int64 v65; // [xsp+0h] [xbp-50h]
  unsigned int v66; // [xsp+10h] [xbp-40h]
  __int64 v67; // [xsp+18h] [xbp-38h]
  _DWORD *v68; // [xsp+20h] [xbp-30h]
  __int64 v69; // [xsp+28h] [xbp-28h]
  __int64 v70; // [xsp+28h] [xbp-28h]
  unsigned int *v71; // [xsp+30h] [xbp-20h]
  int v72; // [xsp+38h] [xbp-18h] BYREF
  __int64 v73; // [xsp+3Ch] [xbp-14h]
  int v74; // [xsp+44h] [xbp-Ch]
  __int64 v75; // [xsp+48h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = _qdf_mem_malloc(0xE58u, "wlan_reg_get_usable_channel", 4392);
  if ( !v12 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: chan_list invalid",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_reg_get_usable_channel");
    result = 16;
    goto LABEL_56;
  }
  v21 = HIDWORD(a2);
  v22 = v12;
  v71 = a5;
  if ( (a3 & 3) != 2 )
  {
    v69 = a4;
    pdev_obj = reg_get_pdev_obj(a1, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( pdev_obj )
    {
      band_from_cur_chan_list = reg_get_band_from_cur_chan_list(
                                  a2,
                                  v22,
                                  pdev_obj,
                                  0,
                                  v24,
                                  v25,
                                  v26,
                                  v27,
                                  v28,
                                  v29,
                                  v30,
                                  v31);
      v74 = 0;
      *a5 = band_from_cur_chan_list;
      v73 = 0;
      if ( band_from_cur_chan_list )
      {
        v33 = 0;
        v34 = 0;
        v35 = (int *)(a4 + 12);
        do
        {
          v72 = 9;
          reg_set_channel_params_for_pwrmode(
            a1,
            *(unsigned int *)(v22 + v33),
            *(unsigned __int16 *)(v22 + v33 + 22),
            &v72,
            a6,
            1);
          v36 = *(_DWORD *)(v22 + v33);
          v35[1] = WORD2(a2) & 0x170C;
          *(v35 - 3) = v36;
          if ( (a2 & 0x170C00000000LL) == 0 )
          {
            qdf_trace_msg(
              0x51u,
              2u,
              "%s: invalid iface mask",
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              "reg_add_usable_channel_to_resp");
            _qdf_mem_free(v22);
            result = 16;
            goto LABEL_56;
          }
          *v35 = v72;
          v37 = BYTE1(v73);
          v35[2] = *(_DWORD *)(v22 + v33 + 8);
          if ( v37 )
            *(v35 - 2) = v37;
          a5 = v71;
          if ( BYTE2(v73) )
            *(v35 - 1) = BYTE2(v73);
          if ( v34 > 0x64 )
            break;
          ++v34;
          v35 += 6;
          v33 += 36;
        }
        while ( v34 < *v71 );
      }
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "reg_get_band_channel_list");
      *a5 = 0;
    }
    a4 = v69;
    v21 = HIDWORD(a2);
    if ( (a3 & 2) == 0 )
    {
      updated = 0;
      goto LABEL_33;
    }
  }
  updated = 0;
  if ( !(_DWORD)v21 )
    goto LABEL_33;
  v40 = v21;
  while ( (v40 & 8) != 0 )
  {
    updated = reg_update_conn_chan_list(a1, a4, 1, 3, (unsigned int)a2, a5, a6);
    v41 = -9;
LABEL_21:
    v40 &= v41;
    if ( !v40 )
      goto LABEL_33;
  }
  if ( (v40 & 4) != 0 )
  {
    updated = reg_update_conn_chan_list(a1, a4, 0, 2, (unsigned int)a2, a5, a6);
    v41 = -13;
    goto LABEL_21;
  }
  if ( (v40 & 0x200) != 0 )
  {
    updated = reg_update_conn_chan_list(a1, a4, 3, 9, (unsigned int)a2, a5, a6);
    v41 = -525;
    goto LABEL_21;
  }
  if ( (v40 & 0x100) != 0 )
  {
    updated = reg_update_conn_chan_list(a1, a4, 2, 8, (unsigned int)a2, a5, a6);
    v41 = -781;
    goto LABEL_21;
  }
  if ( (v40 & 0x1000) != 0 )
  {
    updated = reg_update_conn_chan_list(a1, a4, 5, 12, (unsigned int)a2, a5, a6);
    v41 = -4877;
    goto LABEL_21;
  }
  v42 = updated;
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: invalid mode",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "reg_get_usable_channel_con_filter");
  updated = v42;
LABEL_33:
  if ( (a3 & 1) != 0 )
  {
    v43 = *(_QWORD *)(a1 + 80);
    if ( v43 )
    {
      psoc_obj = reg_get_psoc_obj(v43, v13, v14, v15, v16, v17, v18, v19, v20);
      if ( psoc_obj )
      {
        v45 = *a5;
        v66 = v21;
        v65 = a1;
        if ( *a5 )
        {
          v46 = psoc_obj + 90112;
          v47 = 0;
          v48 = *(unsigned int *)(psoc_obj + 92404);
          v67 = v22;
          v68 = (_DWORD *)(psoc_obj + 92412);
          v49 = v48;
          v70 = a4;
          do
          {
            if ( v49 )
            {
              v50 = v68;
              v51 = 0;
              v52 = (_DWORD *)(v22 + 36LL * v47);
              v53 = (unsigned int *)(a4 + 24LL * (int)v47);
              do
              {
                if ( v51 == 43 )
                  __break(0x5512u);
                if ( *(v50 - 1) <= *v52 && *v50 >= *v52 )
                {
                  qdf_trace_msg(
                    0x51u,
                    8u,
                    "%s: avoid freq %d",
                    v13,
                    v14,
                    v15,
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    "reg_get_usable_channel_coex_filter");
                  qdf_trace_msg(
                    0x51u,
                    8u,
                    "%s: removing freq %d",
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    "reg_remove_freq",
                    *v53);
                  qdf_mem_set(v53, 0x18u, 0);
                  v48 = *(unsigned int *)(v46 + 2292);
                }
                ++v51;
                v50 += 4;
              }
              while ( v51 < v48 );
              a5 = v71;
              v22 = v67;
              v49 = v48;
              a4 = v70;
              v45 = *v71;
            }
            ++v47;
          }
          while ( v47 < v45 );
        }
        LODWORD(v21) = v66;
        a1 = v65;
        if ( (v66 & 0x1208) != 0 )
          updated = reg_skip_invalid_chan_freq(v65, a4, a5, v66);
        else
          updated = 0;
        goto LABEL_53;
      }
      v62 = "%s: psoc reg component is NULL";
      v63 = 1;
    }
    else
    {
      v62 = "%s: invalid psoc";
      v63 = 2;
    }
    qdf_trace_msg(0x51u, v63, v62, v13, v14, v15, v16, v17, v18, v19, v20, "reg_get_usable_channel_coex_filter");
    updated = 16;
  }
  else
  {
LABEL_53:
    if ( (a3 & 3) == 0 )
      updated = reg_skip_invalid_chan_freq(a1, a4, a5, (unsigned int)v21);
  }
  v64 = updated;
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: usable chan count is %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wlan_reg_get_usable_channel",
    *a5,
    v65);
  _qdf_mem_free(v22);
  result = v64;
LABEL_56:
  _ReadStatusReg(SP_EL0);
  return result;
}
