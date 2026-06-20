__int64 __fastcall hdd_start_ap_adapter(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x22
  _DWORD *v11; // x23
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 result; // x0
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  _DWORD *v33; // x21
  _DWORD *v34; // x20
  unsigned int started; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w21
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned __int64 v92; // x9
  _QWORD v93[3]; // [xsp+8h] [xbp-18h] BYREF

  v93[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v11 = (_DWORD *)(a1 + 52824);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_start_ap_adapter");
  if ( (*(_QWORD *)(*(_QWORD *)v11 + 4416LL) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: session is already opened, %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_start_ap_adapter",
      *(unsigned __int8 *)(*(_QWORD *)v11 + 8LL));
    result = qdf_status_to_os_return(0);
  }
  else
  {
    v93[1] = 0;
    if ( a1 && (v20 = *(_QWORD *)(a1 + 24)) != 0 )
      v21 = *(_QWORD *)(v20 + 16);
    else
      v21 = 0;
    v93[0] = a1 + 1617;
    v23 = sme_check_for_duplicate_session(v21, v93);
    if ( v23 )
    {
      v32 = v23;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Duplicate session is existing with same mac address",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "hdd_start_ap_adapter");
      result = qdf_status_to_os_return(v32);
    }
    else if ( a1 && (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v33 = v11 + 2, v11 != (_DWORD *)-8LL) )
    {
      v34 = v11 + 2;
      while ( 1 )
      {
        started = hdd_start_ap_link(v33);
        if ( started )
          break;
        if ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v33 - *v33 - 52832) >> 4)) )
        {
          v33 = v11 + 2;
          if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
            continue;
        }
        goto LABEL_16;
      }
      v77 = started;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to start ap link %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_start_ap_adapter");
      if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
      {
        do
        {
          hdd_deinit_ap_mode(v34, v78, v79, v80, v81, v82, v83, v84, v85);
          hdd_vdev_destroy(v34);
        }
        while ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v34 - *v34 - 52832) >> 4))
             && (*(_QWORD *)(a1 + 1640) & 1) != 0 );
      }
      result = qdf_status_to_os_return(v77);
    }
    else
    {
LABEL_16:
      LOBYTE(v93[0]) = 0;
      if ( (unsigned int)wlan_mlme_get_acs_with_more_param(*v10, v93) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: can't get sap acs with more param, use def",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "hdd_sap_set_acs_with_more_param");
      wlan_sap_set_acs_with_more_param(v10[2], LOBYTE(v93[0]));
      *(_DWORD *)(a1 + 38928) = 0;
      v52 = hdd_wmm_adapter_init(a1);
      if ( v52 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_wmm_adapter_init() failed code: %08d [x%08x]",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "hdd_start_ap_adapter",
          v52,
          v52);
      _X8 = (unsigned __int64 *)(a1 + 1624);
      __asm { PRFM            #0x11, [X8] }
      do
        v92 = __ldxr(_X8);
      while ( __stxr(v92 | 2, _X8) );
      hdd_set_netdev_flags(a1);
      sme_set_del_peers_ind_callback(v10[2], hdd_indicate_peers_deleted);
      qdf_mem_set((void *)(a1 + 52196), 0xCu, 0);
      v61 = hdd_tsf_auto_report_init(a1);
      if ( (cds_get_driver_state(v61, v62, v63, v64, v65, v66, v67, v68) & 8) != 0 )
        hdd_medium_assess_ssr_reinit();
      qdf_trace_msg(0x33u, 8u, "%s: exit", v69, v70, v71, v72, v73, v74, v75, v76, "hdd_start_ap_adapter");
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
