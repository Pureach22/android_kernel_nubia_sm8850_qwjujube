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
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w20
  const char *v30; // x2
  unsigned int v31; // w1
  unsigned int v32; // w0
  unsigned int v33; // w0
  __int64 result; // x0
  _DWORD *v35; // x21
  _DWORD *v36; // x20
  unsigned int started; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 v47; // x9
  __int64 v48; // x10
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w21
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x8
  __int64 v93; // x9
  __int64 v94; // x10
  unsigned __int64 v101; // x9
  char v102[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v103; // [xsp+18h] [xbp-8h]

  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v11 = (_DWORD *)(a1 + 52832);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_start_ap_adapter");
  if ( (*(_QWORD *)(*(_QWORD *)v11 + 5968LL) & 1) != 0 )
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
    v32 = 0;
LABEL_8:
    result = qdf_status_to_os_return(v32);
    goto LABEL_9;
  }
  v20 = hdd_adapter_fill_link_address(a1);
  if ( v20 )
  {
    v29 = v20;
    v30 = "%s: Link address derive failed";
    v31 = 8;
LABEL_7:
    qdf_trace_msg(0x33u, v31, v30, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_start_ap_adapter");
    v32 = v29;
    goto LABEL_8;
  }
  v33 = hdd_adapter_check_duplicate_session(a1);
  if ( v33 )
  {
    v29 = v33;
    v30 = "%s: Duplicate session is existing with same mac address";
    v31 = 2;
    goto LABEL_7;
  }
  if ( a1 )
  {
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v35 = (_DWORD *)(a1 + 52840), a1 != -52840)
      || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v35 = (_DWORD *)(a1 + 58928), a1 != -58928)
      || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v35 = (_DWORD *)(a1 + 65016), a1 != -65016) )
    {
      v36 = v11 + 2;
      while ( 1 )
      {
        started = hdd_start_ap_link(v35);
        if ( started )
          break;
        if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v35 - *v35 - 52840) >> 3) + 1) <= 2u )
        {
          v46 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v35 - *v35 - 52840) >> 3) + 1);
          v35 = nullptr;
          v47 = a1 + 52840 + 6088LL * (unsigned int)v46;
          do
          {
            if ( v35 )
              break;
            v48 = *(_QWORD *)(a1 + 1640) >> v46++;
            v35 = (_DWORD *)((v48 << 63 >> 63) & v47);
            v47 += 6088;
          }
          while ( v46 != 3 );
          if ( v35 )
            continue;
        }
        goto LABEL_25;
      }
      v83 = started;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to start ap link %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "hdd_start_ap_adapter");
      if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && v11 != (_DWORD *)-8LL
        || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v36 = (_DWORD *)(a1 + 58928), a1 != -58928)
        || (*(_QWORD *)(a1 + 1640) & 4) != 0 && (v36 = (_DWORD *)(a1 + 65016), a1 != -65016) )
      {
        do
        {
          hdd_deinit_ap_mode(v36, v84, v85, v86, v87, v88, v89, v90, v91);
          hdd_vdev_destroy(v36);
          if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v36 - *v36 - 52840) >> 3) + 1) > 2u )
            break;
          v92 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v36 - *v36 - 52840) >> 3) + 1);
          v36 = nullptr;
          v93 = a1 + 52840 + 6088LL * (unsigned int)v92;
          do
          {
            if ( v36 )
              break;
            v94 = *(_QWORD *)(a1 + 1640) >> v92++;
            v36 = (_DWORD *)((v94 << 63 >> 63) & v93);
            v93 += 6088;
          }
          while ( v92 != 3 );
        }
        while ( v36 );
      }
      v32 = v83;
      goto LABEL_8;
    }
  }
LABEL_25:
  v49 = *v10;
  v102[0] = 0;
  if ( (unsigned int)wlan_mlme_get_acs_with_more_param(v49, v102) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: can't get sap acs with more param, use def",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "hdd_sap_set_acs_with_more_param");
  wlan_sap_set_acs_with_more_param(v10[2], (unsigned __int8)v102[0]);
  *(_DWORD *)(a1 + 38928) = 0;
  v58 = hdd_wmm_adapter_init(a1);
  if ( v58 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_wmm_adapter_init() failed code: %08d [x%08x]",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "hdd_start_ap_adapter",
      v58,
      v58);
  _X8 = (unsigned __int64 *)(a1 + 1624);
  __asm { PRFM            #0x11, [X8] }
  do
    v101 = __ldxr(_X8);
  while ( __stxr(v101 | 2, _X8) );
  hdd_set_netdev_flags(a1, v59);
  sme_set_del_peers_ind_callback(v10[2], hdd_indicate_peers_deleted);
  qdf_mem_set((void *)(a1 + 52196), 0xCu, 0);
  v67 = hdd_tsf_auto_report_init(a1);
  if ( (cds_get_driver_state(v67, v68, v69, v70, v71, v72, v73, v74) & 8) != 0 )
    hdd_medium_assess_ssr_reinit();
  qdf_trace_msg(0x33u, 8u, "%s: exit", v75, v76, v77, v78, v79, v80, v81, v82, "hdd_start_ap_adapter");
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
