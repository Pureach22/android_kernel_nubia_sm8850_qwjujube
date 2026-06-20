__int64 __fastcall pe_delete_session(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  __int64 v21; // x0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double timer_destroy; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  int v37; // w8
  unsigned __int16 v38; // w23
  __int64 v39; // x21
  __int64 result; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  void *v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  unsigned int v59; // w8
  unsigned __int64 v60; // x21
  __int64 v61; // x0
  __int64 v62; // x21
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x0
  unsigned int *v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  _QWORD v89[2]; // [xsp+20h] [xbp-20h] BYREF
  __int16 v90; // [xsp+30h] [xbp-10h]
  __int64 v91; // [xsp+38h] [xbp-8h]

  v91 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && *(_BYTE *)(a2 + 70) )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Delete PE session: %d opmode: %d vdev_id: %d BSSID: %02x:%02x:%02x:**:**:%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "pe_delete_session",
      *(unsigned __int16 *)(a2 + 8),
      *(unsigned int *)(a2 + 7036),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 24),
      *(unsigned __int8 *)(a2 + 25),
      *(unsigned __int8 *)(a2 + 26),
      *(unsigned __int8 *)(a2 + 29));
    lim_reset_bcn_probe_filter(a1, a2, v12, v13, v14, v15, v16, v17, v18, v19);
    lim_sae_auth_cleanup_retry(a1, *(unsigned __int8 *)(a2 + 10));
    v20 = lim_cleanup_power_change(a1, a2);
    v21 = *(_QWORD *)(a2 + 16);
    v90 = 0;
    v89[0] = 0;
    v89[1] = 0;
    mlme_set_mbssid_info(v21, (unsigned __int8 *)v89, 0, v20, v22, v23, v24, v25, v26, v27, v28);
    if ( *(_DWORD *)(a2 + 7092) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Restore default failure timeout",
        timer_destroy,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "pe_delete_session");
      v37 = *(_DWORD *)(a2 + 7092);
      if ( (unsigned int)(v37 - 500) >= 0x1195 )
        v37 = 1000;
      *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3480LL) = v37;
    }
    v38 = 0;
    do
    {
      v39 = *(_QWORD *)(a1 + 1336) + 264LL * v38;
      if ( *(_WORD *)(a2 + 8) == *(unsigned __int8 *)(v39 + 50)
        && (tx_timer_running(*(_QWORD *)(a1 + 1336) + 264LL * v38) & 1) != 0 )
      {
        tx_timer_deactivate(v39);
      }
      ++v38;
    }
    while ( *(unsigned __int16 *)(a1 + 3990) >= (unsigned int)v38 );
    if ( *(_DWORD *)(a2 + 88) == 1 )
    {
      qdf_runtime_lock_deinit((__int64 *)(a2 + 8600));
      _qdf_wake_lock_destroy(a2 + 8400);
      qdf_mc_timer_stop(a2 + 8064);
      qdf_mc_timer_destroy(a2 + 8064);
      *(_BYTE *)(a2 + 7282) = 0;
      qdf_mc_timer_stop(a2 + 8232);
      qdf_mc_timer_destroy(a2 + 8232);
      lim_del_pmf_sa_query_timer(a1, a2);
      timer_destroy = lim_post_csa_ocv_sa_query_timer_destroy(a2);
    }
    lim_ft_cleanup(timer_destroy, v30, v31, v32, v33, v34, v35, v36, a1, a2);
    v41 = *(_QWORD *)(a2 + 104);
    if ( v41 )
    {
      _qdf_mem_free(v41);
      *(_QWORD *)(a2 + 104) = 0;
    }
    v42 = *(_QWORD *)(a2 + 112);
    if ( v42 )
    {
      _qdf_mem_free(v42);
      *(_QWORD *)(a2 + 112) = 0;
    }
    v43 = *(_QWORD *)(a2 + 120);
    if ( v43 )
    {
      _qdf_mem_free(v43);
      *(_QWORD *)(a2 + 120) = 0;
    }
    v44 = *(_QWORD *)(a2 + 128);
    if ( v44 )
    {
      _qdf_mem_free(v44);
      *(_QWORD *)(a2 + 128) = 0;
    }
    v45 = *(_QWORD *)(a2 + 360);
    if ( v45 )
    {
      _qdf_mem_free(v45);
      *(_QWORD *)(a2 + 360) = 0;
    }
    v46 = *(void **)(a2 + 368);
    if ( v46 )
    {
      qdf_mem_set(v46, 0x7AB8u, 0);
      *(_QWORD *)(a2 + 368) = 0;
    }
    lim_free_peer_idxpool(a2);
    v55 = *(_QWORD *)(a2 + 320);
    if ( v55 )
    {
      _qdf_mem_free(v55);
      *(_QWORD *)(a2 + 320) = 0;
      *(_DWORD *)(a2 + 312) = 0;
    }
    v56 = *(_QWORD *)(a2 + 336);
    if ( v56 )
    {
      _qdf_mem_free(v56);
      *(_QWORD *)(a2 + 336) = 0;
      *(_DWORD *)(a2 + 328) = 0;
    }
    v57 = *(_QWORD *)(a2 + 352);
    if ( v57 )
    {
      _qdf_mem_free(v57);
      *(_QWORD *)(a2 + 352) = 0;
      *(_DWORD *)(a2 + 344) = 0;
    }
    v58 = *(_QWORD *)(a2 + 384);
    if ( v58 )
    {
      v59 = *(unsigned __int16 *)(a2 + 376);
      if ( *(_WORD *)(a2 + 376) )
      {
        v60 = 0;
        do
        {
          v61 = *(_QWORD *)(*(_QWORD *)(a2 + 384) + 8 * v60);
          if ( v61 )
          {
            lim_free_assoc_req_frm_buf(v61);
            _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(a2 + 384) + 8 * v60));
            *(_QWORD *)(*(_QWORD *)(a2 + 384) + 8 * v60) = 0;
            v59 = *(unsigned __int16 *)(a2 + 376);
          }
          ++v60;
        }
        while ( v60 < v59 );
        v58 = *(_QWORD *)(a2 + 384);
      }
      _qdf_mem_free(v58);
      *(_QWORD *)(a2 + 384) = 0;
    }
    v62 = *(_QWORD *)(a2 + 240);
    if ( v62 )
    {
      _qdf_mem_free(*(_QWORD *)(v62 + 680));
      _qdf_mem_free(*(_QWORD *)(v62 + 744));
      _qdf_mem_free(*(_QWORD *)(a2 + 240));
      *(_QWORD *)(a2 + 240) = 0;
    }
    v63 = *(_QWORD *)(a2 + 136);
    if ( v63 )
    {
      _qdf_mem_free(v63);
      *(_QWORD *)(a2 + 136) = 0;
    }
    v64 = *(_QWORD *)(a2 + 144);
    if ( v64 )
    {
      _qdf_mem_free(v64);
      *(_QWORD *)(a2 + 144) = 0;
    }
    v65 = *(_QWORD *)(a2 + 7336);
    if ( v65 )
    {
      _qdf_mem_free(v65);
      *(_QWORD *)(a2 + 7336) = 0;
    }
    v66 = *(_QWORD *)(a2 + 7344);
    if ( v66 )
    {
      _qdf_mem_free(v66);
      *(_QWORD *)(a2 + 7344) = 0;
    }
    v67 = *(_QWORD *)(a2 + 7352);
    if ( v67 )
    {
      _qdf_mem_free(v67);
      *(_QWORD *)(a2 + 7352) = 0;
    }
    v68 = *(_QWORD *)(a2 + 7296);
    if ( v68 )
    {
      _qdf_mem_free(v68);
      *(_QWORD *)(a2 + 7296) = 0;
      *(_WORD *)(a2 + 7288) = 0;
    }
    v69 = *(_QWORD *)(a2 + 7312);
    if ( v69 )
    {
      _qdf_mem_free(v69);
      *(_QWORD *)(a2 + 7312) = 0;
      *(_WORD *)(a2 + 7304) = 0;
    }
    v70 = *(_QWORD *)(a2 + 7328);
    if ( v70 )
    {
      _qdf_mem_free(v70);
      *(_QWORD *)(a2 + 7328) = 0;
      *(_WORD *)(a2 + 7320) = 0;
    }
    pe_delete_fils_info(a2, v47, v48, v49, v50, v51, v52, v53, v54);
    if ( !*(_DWORD *)(a2 + 7036) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: deinit pmf comeback timer for vdev %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "lim_clear_pmfcomeback_timer",
        *(unsigned __int8 *)(a2 + 10));
      if ( (unsigned int)qdf_mc_timer_get_current_state(a2 + 7872) == 21 )
        qdf_mc_timer_stop(a2 + 7872);
      qdf_mc_timer_destroy(a2 + 7872);
      *(_BYTE *)(a2 + 8049) = 0;
    }
    v79 = *(_QWORD *)(a2 + 8664);
    *(_BYTE *)(a2 + 70) = 0;
    *(_QWORD *)(a2 + 8608) = 0;
    if ( v79 )
      _qdf_mem_free(v79);
    v80 = (unsigned int *)*(unsigned int *)(a2 + 88);
    *(_QWORD *)(a2 + 8664) = 0;
    if ( (_DWORD)v80 == 1 )
    {
      v81 = lim_check_and_reset_protection_params(a1);
      wlan_set_sap_user_config_freq(*(_QWORD *)(a2 + 16), 0, v81, v82, v83, v84, v85, v86, v87, v88);
    }
    result = *(_QWORD *)(a2 + 16);
    *(_BYTE *)(a2 + 10071) = 0;
    *(_QWORD *)(a2 + 16) = 0;
    if ( result )
      result = wlan_objmgr_vdev_release_ref(result, 7u, v80, v71, v72, v73, v74, v75, v76, v77, v78);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: session already deleted or not valid",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "pe_delete_session");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
