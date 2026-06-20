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
  int v25; // w24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  __int64 v45; // [xsp+0h] [xbp-E0h]
  _BYTE v46[4]; // [xsp+3Ch] [xbp-A4h] BYREF
  _BYTE v47[4]; // [xsp+40h] [xbp-A0h] BYREF
  int v48; // [xsp+44h] [xbp-9Ch] BYREF
  int v49; // [xsp+48h] [xbp-98h] BYREF
  char v50; // [xsp+4Ch] [xbp-94h]
  int v51; // [xsp+50h] [xbp-90h] BYREF
  char v52; // [xsp+54h] [xbp-8Ch]
  int v53; // [xsp+58h] [xbp-88h] BYREF
  char v54; // [xsp+5Ch] [xbp-84h]
  _QWORD v55[2]; // [xsp+60h] [xbp-80h] BYREF
  int v56; // [xsp+70h] [xbp-70h]
  _QWORD v57[2]; // [xsp+78h] [xbp-68h] BYREF
  int v58; // [xsp+88h] [xbp-58h]
  _QWORD v59[2]; // [xsp+90h] [xbp-50h] BYREF
  int v60; // [xsp+A0h] [xbp-40h]
  _QWORD v61[2]; // [xsp+A8h] [xbp-38h] BYREF
  int v62; // [xsp+B8h] [xbp-28h]
  _QWORD v63[2]; // [xsp+C0h] [xbp-20h] BYREF
  int v64; // [xsp+D0h] [xbp-10h]
  __int64 v65; // [xsp+D8h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = 9;
  v47[0] = 0;
  v46[0] = 0;
  v64 = 0;
  v63[0] = 0;
  v63[1] = 0;
  v62 = 0;
  v61[0] = 0;
  v61[1] = 0;
  v60 = 0;
  v59[0] = 0;
  v59[1] = 0;
  v54 = 0;
  v53 = 0;
  v52 = 0;
  v51 = 0;
  v58 = 0;
  v57[0] = 0;
  v57[1] = 0;
  v56 = 0;
  v55[0] = 0;
  v55[1] = 0;
  v50 = 0;
  v49 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)pm_conc_connection_list == 1 && BYTE4(qword_81C458) == 1 )
    {
      v12 = 1;
      LODWORD(v63[0]) = HIDWORD(pm_conc_connection_list);
    }
    else
    {
      v12 = 0;
    }
    if ( (_DWORD)qword_81C464 == 1 && BYTE4(qword_81C47C) == 1 )
    {
      v13 = (_DWORD *)((unsigned __int64)v63 | (4LL * v12++));
      *v13 = HIDWORD(qword_81C464);
    }
    if ( (_DWORD)qword_81C488 == 1 && BYTE4(qword_81C4A0) == 1 )
      *((_DWORD *)v63 + v12++) = HIDWORD(qword_81C488);
    if ( (_DWORD)qword_81C4AC == 1 && BYTE4(qword_81C4C4) == 1 )
      *((_DWORD *)v63 + v12++) = HIDWORD(qword_81C4AC);
    if ( (_DWORD)qword_81C4D0 == 1 && BYTE4(qword_81C4E8) == 1 )
      *((_DWORD *)v63 + v12++) = HIDWORD(qword_81C4D0);
    policy_mgr_get_ml_and_non_ml_mode_count(
      a1,
      v47,
      (__int64)&v53,
      v46,
      (__int64)&v51,
      (unsigned __int64)v57,
      (unsigned __int64)&v49,
      0);
    v14 = policy_mgr_mode_specific_connection_count(a1, 4, v61);
    v15 = policy_mgr_mode_specific_connection_count(a1, 5, v59);
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(a1, (unsigned __int64)v55, 0, 2u);
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
        "policy_mgr_get_fifth_connection_pcl_table_index",
        mode_specific_conn_info);
    else
      v25 = (unsigned __int8)(policy_mgr_get_mode_specific_conn_info(
                                a1,
                                (unsigned __int64)v55 + 4 * mode_specific_conn_info,
                                0,
                                3u)
                            + mode_specific_conn_info);
    qdf_trace_msg(
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
      v47[0],
      v25);
    if ( v47[0] == 2 && v12 == 1 && v15 == 1 )
    {
      v48 = 0;
    }
    else
    {
      if ( v47[0] == 2 && v15 == 1 && v14 == 1 || v25 == 1 && v47[0] == 1 && v15 == 1 && v14 == 1 )
      {
        v43 = 2;
      }
      else
      {
        if ( v25 == 1 && v47[0] == 2 && v15 == 1 )
          goto LABEL_35;
        if ( v12 == 4 )
        {
          if ( (policy_mgr_is_current_hwmode_dbs(a1) & 1) != 0 )
          {
            policy_mgr_get_index_for_4sap_dbs(&v48, v63);
            goto LABEL_35;
          }
          if ( ((unsigned __int8)policy_mgr_is_current_hwmode_sbs(a1) & 1) != 0 )
          {
            policy_mgr_get_index_for_4sap_sbs(v11, &v48, v63);
            goto LABEL_35;
          }
        }
        v43 = 9;
      }
      v48 = v43;
    }
LABEL_35:
    v34 = v48;
    LODWORD(v45) = HIDWORD(pm_conc_connection_list);
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: mode0:%d mode1:%d mode2:%d mode3:%d chan0:%d chan1:%d chan2:%d chan3:%dchain:%d index:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "policy_mgr_get_fifth_connection_pcl_table_index",
      (unsigned int)pm_conc_connection_list,
      (unsigned int)qword_81C464,
      (unsigned int)qword_81C488,
      (unsigned int)qword_81C4AC,
      v45,
      HIDWORD(qword_81C464),
      HIDWORD(qword_81C488),
      HIDWORD(qword_81C4AC),
      dword_81C450,
      v48);
    qdf_mutex_release(v11 + 56);
    goto LABEL_36;
  }
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
