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
  __int64 v15; // x0
  unsigned int v16; // w22
  __int64 result; // x0
  __int64 v18; // x20
  unsigned int v19; // w21
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  __int16 *v30; // x22
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w22
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 hash_entry; // x0
  __int64 v57; // x23
  int v58; // w9
  __int16 v59; // w10
  __int16 v60; // w8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  unsigned int v70; // w23
  char is_fast_roam_enabled; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // [xsp+10h] [xbp-20h] BYREF
  __int64 v81; // [xsp+18h] [xbp-18h]
  __int64 v82; // [xsp+20h] [xbp-10h]
  __int64 v83; // [xsp+28h] [xbp-8h]

  v83 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[1550];
  LOWORD(v80) = 0;
  v81 = 0;
  v82 = 0;
  if ( v3 )
  {
    if ( (tx_timer_running(a1 + 333) & 1) != 0 )
      lim_deactivate_and_change_timer(a1, 17);
    session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v3 + 12));
    if ( session_by_session_id )
    {
      v13 = session_by_session_id;
      v14 = *(_DWORD *)v3 == -1 && *(__int16 *)(v3 + 4) == -1;
      if ( v14 && *(_BYTE *)(a1[1] + 3434LL) == 1 )
      {
        v15 = *(_QWORD *)(session_by_session_id + 16);
        if ( *(_DWORD *)(v15 + 16) == 1
          && (wlan_vdev_mlme_is_mlo_vdev(v15, v5, v6, v7, v8, v9, v10, v11, v12) & 1) != 0
          && *(unsigned __int16 *)(v13 + 376) >= 2u )
        {
          v16 = 1;
          do
          {
            hash_entry = dph_get_hash_entry((__int64)a1, v16, v13 + 360);
            if ( hash_entry )
            {
              v57 = hash_entry;
              if ( (lim_is_mlo_conn(v13, hash_entry) & 1) != 0 )
                lim_mlo_notify_peer_disconn(v13, v57);
            }
            ++v16;
          }
          while ( v16 < *(unsigned __int16 *)(v13 + 376) );
        }
        v69 = lim_del_sta_all((__int64)a1, v13, v5, v6, v7, v8, v9, v10, v11, v12);
        _qdf_mem_free(v3);
        result = v69;
        goto LABEL_42;
      }
      v29 = dph_lookup_hash_entry(
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
              &v80,
              session_by_session_id + 360);
      if ( v29 )
      {
        v30 = (__int16 *)v29;
        lim_mlo_notify_peer_disconn(v13, v29);
        lim_cleanup_rx_path((__int64)a1, v30, v13, 1, v31, v32, v33, v34, v35, v36, v37, v38);
        v39 = *(_DWORD *)(v13 + 88);
        if ( v39 == 2 )
        {
          if ( (wlan_cm_get_ese_assoc(a1[2704], *(_BYTE *)(v13 + 10)) & 1) != 0
            || (cm_is_fast_roam_enabled(a1[2703]) & 1) != 0
            || (*(_BYTE *)(v13 + 7041) & 1) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: FT Preauth (%pK,%d) Deauth rc %d src = %d",
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              "lim_send_deauth_cnf",
              v13,
              *(unsigned __int16 *)(v13 + 8),
              *(unsigned __int16 *)(v3 + 6),
              *(unsigned __int16 *)(v3 + 8));
            lim_ft_cleanup(v48, v49, v50, v51, v52, v53, v54, v55, (__int64)a1, v13);
LABEL_41:
            _qdf_mem_free(v3);
            result = 0;
LABEL_42:
            a1[1550] = 0;
            goto LABEL_43;
          }
          v39 = *(_DWORD *)(v13 + 88);
        }
        v70 = *(unsigned __int8 *)(a1[1] + 1766LL);
        is_fast_roam_enabled = cm_is_fast_roam_enabled(a1[2703]);
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: No FT Preauth Session Cleanup in role %d isESE %d isLFR %d is11r %d, Deauth reason %d Trigger = %d",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "lim_send_deauth_cnf",
          v39,
          v70,
          is_fast_roam_enabled & 1,
          *(unsigned __int8 *)(v13 + 7041),
          *(unsigned __int16 *)(v3 + 6),
          *(unsigned __int16 *)(v3 + 8),
          v80,
          v81,
          v82,
          v83);
        goto LABEL_41;
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
    HIDWORD(v81) = 500;
    v58 = *(_DWORD *)v3;
    v59 = *(_WORD *)(v3 + 4);
    LOWORD(v82) = *(_WORD *)(v3 + 8);
    v60 = *(_WORD *)(v3 + 10);
    LOWORD(v81) = v59;
    HIDWORD(v80) = v58;
    WORD1(v82) = v60;
    BYTE4(v82) = *(_BYTE *)(v3 + 12);
    _qdf_mem_free(v3);
    a1[1550] = 0;
    lim_process_mlm_rsp_messages((__int64)a1, 1018, (unsigned __int8 *)&v80 + 4, v61, v62, v63, v64, v65, v66, v67, v68);
    goto LABEL_37;
  }
  result = pe_find_session_by_vdev_id(a1, a2);
  if ( result )
  {
    v18 = result;
    if ( (*(_DWORD *)(result + 7036) | 2) == 3 && *(_WORD *)(result + 376) )
    {
      v19 = 0;
      do
      {
        v20 = dph_get_hash_entry((__int64)a1, v19, v18 + 360);
        if ( v20 && (*(_WORD *)v20 & 1) != 0 && (*(_BYTE *)(v20 + 661) & 1) == 0 && *(_BYTE *)(v20 + 658) )
        {
          *(_BYTE *)(v20 + 658) = 0;
          lim_trigger_sta_deletion((__int64)a1, v20, v18, v21, v22, v23, v24, v25, v26, v27, v28);
        }
        ++v19;
      }
      while ( v19 < *(unsigned __int16 *)(v18 + 376) );
    }
LABEL_37:
    result = 0;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
