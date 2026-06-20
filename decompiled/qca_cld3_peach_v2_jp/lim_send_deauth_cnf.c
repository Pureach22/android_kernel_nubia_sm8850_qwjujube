__int64 __fastcall lim_send_deauth_cnf(_QWORD *a1, __int64 a2)
{
  __int64 v3; // x20
  __int64 session_by_session_id; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  bool v14; // zf
  unsigned int v15; // w21
  __int64 result; // x0
  __int64 v17; // x20
  unsigned int v18; // w21
  __int64 hash_entry; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int16 *v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w22
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w9
  __int16 v55; // w10
  __int16 v56; // w8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w23
  char is_fast_roam_enabled; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // [xsp+10h] [xbp-20h] BYREF
  __int64 v76; // [xsp+18h] [xbp-18h]
  __int64 v77; // [xsp+20h] [xbp-10h]
  __int64 v78; // [xsp+28h] [xbp-8h]

  v78 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[1550];
  LOWORD(v75) = 0;
  v76 = 0;
  v77 = 0;
  if ( v3 )
  {
    if ( (tx_timer_running(a1 + 333) & 1) != 0 )
      lim_deactivate_and_change_timer(a1, 17);
    session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v3 + 12));
    if ( session_by_session_id )
    {
      v13 = session_by_session_id;
      v14 = *(_DWORD *)v3 == -1 && *(__int16 *)(v3 + 4) == -1;
      if ( v14 && *(_BYTE *)(a1[1] + 3234LL) == 1 )
      {
        v15 = lim_del_sta_all((__int64)a1, session_by_session_id, v5, v6, v7, v8, v9, v10, v11, v12);
        _qdf_mem_free(v3);
        result = v15;
LABEL_34:
        a1[1550] = 0;
        goto LABEL_35;
      }
      v28 = (__int16 *)dph_lookup_hash_entry(
                         v5,
                         v6,
                         v7,
                         v8,
                         v9,
                         v10,
                         v11,
                         v12,
                         (__int64)a1,
                         (unsigned __int8 *)v3,
                         &v75,
                         session_by_session_id + 360);
      if ( v28 )
      {
        lim_cleanup_rx_path((__int64)a1, v28, v13, 1, v29, v30, v31, v32, v33, v34, v35, v36);
        v37 = *(_DWORD *)(v13 + 88);
        if ( v37 == 2 )
        {
          if ( (wlan_cm_get_ese_assoc(a1[2695], *(_BYTE *)(v13 + 10)) & 1) != 0
            || (cm_is_fast_roam_enabled(a1[2694]) & 1) != 0
            || (*(_BYTE *)(v13 + 7041) & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FT Preauth (%pK,%d) Deauth rc %d src = %d",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "lim_send_deauth_cnf",
              v13,
              *(unsigned __int16 *)(v13 + 8),
              *(unsigned __int16 *)(v3 + 6),
              *(unsigned __int16 *)(v3 + 8));
            lim_ft_cleanup(v46, v47, v48, v49, v50, v51, v52, v53, (__int64)a1, v13);
LABEL_33:
            _qdf_mem_free(v3);
            result = 0;
            goto LABEL_34;
          }
          v37 = *(_DWORD *)(v13 + 88);
        }
        v65 = *(unsigned __int8 *)(a1[1] + 1562LL);
        is_fast_roam_enabled = cm_is_fast_roam_enabled(a1[2694]);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: No FT Preauth Session Cleanup in role %d isESE %d isLFR %d is11r %d, Deauth reason %d Trigger = %d",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "lim_send_deauth_cnf",
          v37,
          v65,
          is_fast_roam_enabled & 1,
          *(unsigned __int8 *)(v13 + 7041),
          *(unsigned __int16 *)(v3 + 6),
          *(unsigned __int16 *)(v3 + 8),
          v75,
          v76,
          v77,
          v78);
        goto LABEL_33;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: session does not exist for given sessionId",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "lim_send_deauth_cnf");
    }
    HIDWORD(v76) = 500;
    v54 = *(_DWORD *)v3;
    v55 = *(_WORD *)(v3 + 4);
    LOWORD(v77) = *(_WORD *)(v3 + 8);
    v56 = *(_WORD *)(v3 + 10);
    LOWORD(v76) = v55;
    HIDWORD(v75) = v54;
    WORD1(v77) = v56;
    BYTE4(v77) = *(_BYTE *)(v3 + 12);
    _qdf_mem_free(v3);
    a1[1550] = 0;
    lim_process_mlm_rsp_messages((__int64)a1, 1018, (unsigned __int8 *)&v75 + 4, v57, v58, v59, v60, v61, v62, v63, v64);
    goto LABEL_30;
  }
  result = pe_find_session_by_vdev_id(a1, a2);
  if ( result )
  {
    v17 = result;
    if ( (*(_DWORD *)(result + 7036) | 2) == 3 && *(_WORD *)(result + 376) )
    {
      v18 = 0;
      do
      {
        hash_entry = dph_get_hash_entry((__int64)a1, v18, v17 + 360);
        if ( hash_entry
          && (*(_WORD *)hash_entry & 1) != 0
          && (*(_BYTE *)(hash_entry + 645) & 1) == 0
          && *(_BYTE *)(hash_entry + 642) )
        {
          *(_BYTE *)(hash_entry + 642) = 0;
          lim_trigger_sta_deletion((__int64)a1, hash_entry, v17, v20, v21, v22, v23, v24, v25, v26, v27);
        }
        ++v18;
      }
      while ( v18 < *(unsigned __int16 *)(v17 + 376) );
    }
LABEL_30:
    result = 0;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
