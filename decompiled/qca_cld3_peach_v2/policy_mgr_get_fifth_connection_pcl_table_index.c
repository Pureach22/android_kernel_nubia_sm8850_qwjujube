__int64 __fastcall policy_mgr_get_fifth_connection_pcl_table_index(__int64 a1)
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
  unsigned int v12; // w21
  _DWORD *v13; // x8
  unsigned int v14; // w23
  unsigned int v15; // w22
  unsigned __int8 mode_specific_conn_info; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int8 v25; // w24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  __int64 is_24ghz_ch_freq; // x0
  __int64 v36; // x1
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  int v45; // w8
  unsigned int v47; // w20
  __int64 v48; // [xsp+0h] [xbp-E0h]
  unsigned int v49; // [xsp+3Ch] [xbp-A4h] BYREF
  unsigned int v50; // [xsp+40h] [xbp-A0h] BYREF
  int v51; // [xsp+44h] [xbp-9Ch] BYREF
  int v52; // [xsp+48h] [xbp-98h] BYREF
  char v53; // [xsp+4Ch] [xbp-94h]
  int v54; // [xsp+50h] [xbp-90h] BYREF
  char v55; // [xsp+54h] [xbp-8Ch]
  int v56; // [xsp+58h] [xbp-88h] BYREF
  char v57; // [xsp+5Ch] [xbp-84h]
  _QWORD v58[2]; // [xsp+60h] [xbp-80h] BYREF
  int v59; // [xsp+70h] [xbp-70h]
  _QWORD v60[2]; // [xsp+78h] [xbp-68h] BYREF
  int v61; // [xsp+88h] [xbp-58h]
  _QWORD v62[2]; // [xsp+90h] [xbp-50h] BYREF
  int v63; // [xsp+A0h] [xbp-40h]
  _QWORD v64[2]; // [xsp+A8h] [xbp-38h] BYREF
  int v65; // [xsp+B8h] [xbp-28h]
  _QWORD v66[2]; // [xsp+C0h] [xbp-20h] BYREF
  int v67; // [xsp+D0h] [xbp-10h]
  __int64 v68; // [xsp+D8h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 9;
  LOBYTE(v50) = 0;
  LOBYTE(v49) = 0;
  v67 = 0;
  v66[0] = 0;
  v66[1] = 0;
  v65 = 0;
  v64[0] = 0;
  v64[1] = 0;
  v63 = 0;
  v62[0] = 0;
  v62[1] = 0;
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v54 = 0;
  v61 = 0;
  v60[0] = 0;
  v60[1] = 0;
  v59 = 0;
  v58[0] = 0;
  v58[1] = 0;
  v53 = 0;
  v52 = 0;
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
      "policy_mgr_get_fifth_connection_pcl_table_index");
    v34 = 9;
LABEL_36:
    _ReadStatusReg(SP_EL0);
    return v34;
  }
  v11 = context;
  qdf_mutex_acquire(context + 56);
  if ( (_DWORD)pm_conc_connection_list == 1 && BYTE4(qword_8D4F00) == 1 )
  {
    v12 = 1;
    LODWORD(v66[0]) = HIDWORD(pm_conc_connection_list);
  }
  else
  {
    v12 = 0;
  }
  if ( (_DWORD)qword_8D4F0C == 1 && BYTE4(qword_8D4F24) == 1 )
  {
    v13 = (_DWORD *)((unsigned __int64)v66 | (4LL * v12++));
    *v13 = HIDWORD(qword_8D4F0C);
  }
  if ( (_DWORD)qword_8D4F30 == 1 && BYTE4(qword_8D4F48) == 1 )
    *((_DWORD *)v66 + v12++) = HIDWORD(qword_8D4F30);
  if ( (_DWORD)qword_8D4F54 == 1 && BYTE4(qword_8D4F6C) == 1 )
    *((_DWORD *)v66 + v12++) = HIDWORD(qword_8D4F54);
  if ( (_DWORD)qword_8D4F78 == 1 && BYTE4(qword_8D4F90) == 1 )
    *((_DWORD *)v66 + v12++) = HIDWORD(qword_8D4F78);
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v50,
    (__int64)&v56,
    &v49,
    (__int64)&v54,
    (unsigned __int64)v60,
    (unsigned __int64)&v52,
    0);
  v14 = policy_mgr_mode_specific_connection_count(a1, 4, v64);
  v15 = policy_mgr_mode_specific_connection_count(a1, 5, v62);
  mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v58, 0, 2u);
  v25 = mode_specific_conn_info;
  if ( mode_specific_conn_info > 4u )
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: p2p client count %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "policy_mgr_get_fifth_connection_pcl_table_index");
  else
    v25 = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v58 + 4 * mode_specific_conn_info, 0, 3u)
        + mode_specific_conn_info;
  is_24ghz_ch_freq = qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "%s: sap:%d ndi:%d nan disc:%d ml_sta:%d p2p: %d",
                       v26,
                       v27,
                       v28,
                       v29,
                       v30,
                       v31,
                       v32,
                       v33,
                       "policy_mgr_get_fifth_connection_pcl_table_index",
                       v12,
                       v14,
                       v15,
                       (unsigned __int8)v50,
                       v25);
  if ( (unsigned __int8)v50 == 2 && v12 == 1 && v15 == 1 )
  {
    v51 = 0;
LABEL_35:
    v34 = v51;
    LODWORD(v48) = HIDWORD(pm_conc_connection_list);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: mode0:%d mode1:%d mode2:%d mode3:%d chan0:%d chan1:%d chan2:%d chan3:%dchain:%d index:%d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "policy_mgr_get_fifth_connection_pcl_table_index",
      (unsigned int)pm_conc_connection_list,
      (unsigned int)qword_8D4F0C,
      (unsigned int)qword_8D4F30,
      (unsigned int)qword_8D4F54,
      v48,
      HIDWORD(qword_8D4F0C),
      HIDWORD(qword_8D4F30),
      HIDWORD(qword_8D4F54),
      dword_8D4EF8,
      v51);
    qdf_mutex_release(v11 + 56);
    goto LABEL_36;
  }
  if ( (unsigned __int8)v50 == 2 && v15 == 1 && v14 == 1
    || v25 == 1 && (unsigned __int8)v50 == 1 && v15 == 1 && v14 == 1 )
  {
    v45 = 2;
LABEL_34:
    v51 = v45;
    goto LABEL_35;
  }
  if ( v25 != 1 || (unsigned __int8)v50 != 2 || v15 != 1 )
  {
    if ( v12 == 4 )
    {
      if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
      {
        policy_mgr_get_index_for_4sap_dbs(&v51, v66);
        goto LABEL_35;
      }
      if ( ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
      {
        policy_mgr_get_index_for_4sap_sbs(v11, &v51, v66);
        goto LABEL_35;
      }
    }
    v45 = 9;
    goto LABEL_34;
  }
  if ( (unsigned __int8)v56 <= 4uLL )
  {
    v47 = v58[0];
    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v60 + (unsigned __int8)v56));
    if ( BYTE1(v56) <= 4uLL )
    {
      wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v60 + BYTE1(v56)));
      wlan_reg_is_24ghz_ch_freq(v47);
      v45 = 1;
      goto LABEL_34;
    }
  }
  __break(1u);
  return policy_mgr_get_index_for_4sap_dbs(is_24ghz_ch_freq, v36);
}
