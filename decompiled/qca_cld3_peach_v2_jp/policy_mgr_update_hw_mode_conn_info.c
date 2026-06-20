__int64 __fastcall policy_mgr_update_hw_mode_conn_info(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7)
{
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x24
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x27
  unsigned int *v33; // x28
  __int64 v34; // x25
  unsigned int v35; // w26
  unsigned int v36; // w8
  int v37; // w0
  unsigned int v38; // w26
  _DWORD *v39; // x25
  unsigned int v40; // w26
  unsigned int v41; // w21
  int v42; // w0
  __int64 v43; // x8
  unsigned int v44; // w9
  __int64 v46; // x8
  int v47; // w10
  int v48; // w11
  __int64 v49; // x10
  __int64 v50; // x9
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x24
  _DWORD *v60; // x25
  int v61; // w4
  __int64 *v62; // x8
  void (__fastcall *v63)(__int64, __int64, __int64); // x8
  __int64 v64; // x1
  __int64 v65; // x2
  __int64 v66; // [xsp+8h] [xbp-8h]

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "policy_mgr_update_hw_mode_conn_info");
  v22 = comp_private_obj;
  v66 = a3;
  if ( !a6 || !a7 )
    goto LABEL_29;
  v23 = comp_private_obj + 1460;
  qdf_mem_set((void *)(comp_private_obj + 1460), 0x20u, 0);
  v32 = a6;
  v33 = (unsigned int *)(a7 + 8);
  while ( 1 )
  {
    v34 = *(v33 - 2);
    if ( (unsigned int)v34 >= 2 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Invalid pdev id %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "policy_mgr_fill_curr_freq_by_pdev_freq",
        (unsigned int)v34);
      goto LABEL_29;
    }
    v35 = *(v33 - 1);
    v36 = *v33 >> 2;
    if ( v35 >> 2 > 0x4C8 || v36 > 0x4C8 )
      break;
    if ( v35 <= (unsigned int)wlan_reg_min_24ghz_chan_freq() )
      v37 = wlan_reg_min_24ghz_chan_freq();
    else
      v37 = *(v33 - 1);
    v39 = (_DWORD *)(v23 + 16 * v34);
    *v39 = v37;
    v40 = *v33;
    if ( v40 >= (unsigned int)wlan_reg_max_24ghz_chan_freq() )
      v39[1] = wlan_reg_max_24ghz_chan_freq();
    else
      v39[1] = *v33;
LABEL_6:
    --v32;
    v33 += 3;
    if ( !v32 )
      goto LABEL_30;
  }
  if ( v35 >> 2 >= 0x4C9 && v36 >= 0x4C9 )
  {
    if ( (unsigned __int16)wlan_reg_max_6ghz_chan_freq() )
      v38 = (unsigned __int16)wlan_reg_max_6ghz_chan_freq();
    else
      v38 = wlan_reg_max_5ghz_chan_freq();
    v41 = *(v33 - 1);
    if ( v41 <= (unsigned int)wlan_reg_min_5ghz_chan_freq() )
      v42 = wlan_reg_min_5ghz_chan_freq();
    else
      v42 = *(v33 - 1);
    v43 = v23 + 16 * v34;
    *(_DWORD *)(v43 + 8) = v42;
    v44 = *v33;
    if ( *v33 >= v38 )
      v44 = v38;
    *(_DWORD *)(v43 + 12) = v44;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid different band freq range: mac_id %d start freq %d end_freq %d",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "policy_mgr_fill_curr_freq_by_pdev_freq",
    (unsigned int)v34,
    v35);
LABEL_29:
  v46 = v22 + 32LL * (HIBYTE(a4) != 0);
  v47 = *(_DWORD *)(v46 + 1208);
  v48 = *(_DWORD *)(v46 + 1220);
  *(_DWORD *)(v22 + 1460) = *(_DWORD *)(v46 + 1204);
  *(_DWORD *)(v22 + 1464) = v47;
  v49 = *(_QWORD *)(v46 + 1224);
  v50 = *(_QWORD *)(v46 + 1212);
  LODWORD(v46) = *(_DWORD *)(v46 + 1232);
  *(_DWORD *)(v22 + 1476) = v48;
  *(_QWORD *)(v22 + 1480) = v49;
  *(_QWORD *)(v22 + 1468) = v50;
  *(_DWORD *)(v22 + 1488) = v46;
LABEL_30:
  qdf_mutex_acquire(v22 + 56);
  if ( a2 )
  {
    v59 = a2;
    v60 = (_DWORD *)(v66 + 4);
    do
    {
      if ( (qword_81C458 & 0x100000000LL) != 0 )
      {
        v61 = *(v60 - 1);
        v62 = &pm_conc_connection_list;
        if ( v61 == (_DWORD)qword_81C458
          || BYTE4(qword_81C47C) == 1
          && ((v62 = &qword_81C464, v61 == (_DWORD)qword_81C47C)
           || BYTE4(qword_81C4A0) == 1
           && ((v62 = &qword_81C488, v61 == (_DWORD)qword_81C4A0)
            || BYTE4(qword_81C4C4) == 1
            && ((v62 = &qword_81C4AC, v61 == (_DWORD)qword_81C4C4)
             || BYTE4(qword_81C4E8) == 1 && (v62 = &qword_81C4D0, v61 == (_DWORD)qword_81C4E8)))) )
        {
          *((_BYTE *)v62 + 12) = *v60;
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: vdev:%d, mac:%d",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "policy_mgr_update_hw_mode_conn_info");
          v63 = *(void (__fastcall **)(__int64, __int64, __int64))(v22 + 480);
          if ( v63 )
          {
            v64 = (unsigned int)*(v60 - 1);
            v65 = (unsigned int)*v60;
            if ( *((_DWORD *)v63 - 1) != -1125204353 )
              __break(0x8228u);
            v63(a1, v64, v65);
          }
        }
      }
      --v59;
      v60 += 2;
    }
    while ( v59 );
  }
  qdf_mutex_release(v22 + 56);
  return policy_mgr_dump_connection_status_info(a1);
}
