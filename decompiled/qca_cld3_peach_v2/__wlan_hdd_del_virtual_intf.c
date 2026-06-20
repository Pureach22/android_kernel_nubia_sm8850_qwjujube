__int64 __usercall _wlan_hdd_del_virtual_intf@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X8>,
        double a4@<D0>,
        double a5@<D1>,
        double a6@<D2>,
        double a7@<D3>,
        double a8@<D4>,
        double a9@<D5>,
        double a10@<D6>,
        double a11@<D7>)
{
  __int64 v11; // x9
  __int64 *v12; // x19
  __int64 v13; // x21
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  const char *v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned __int64 v112; // x11

  if ( a1 )
  {
    v13 = *(_QWORD *)(a2 + 32);
    qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "__wlan_hdd_del_virtual_intf");
    if ( (unsigned int)hdd_get_conparam() == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "__wlan_hdd_del_virtual_intf");
      return 4294967274LL;
    }
    a3 = 55520;
    v12 = (__int64 *)(a1 + 1536);
    v11 = *(_QWORD *)(v13 + 55520);
  }
  else
  {
    __break(0x800u);
  }
  _X9 = (unsigned __int64 *)(v11 + 5968);
  __asm { PRFM            #0x11, [X9] }
  do
    v112 = __ldxr(_X9);
  while ( __stxr(v112 & 0xFFFFFFFFFFFFFFFBLL, _X9) );
  qdf_mtrace(51, 51, 0x18u, *(_BYTE *)(*(_QWORD *)(v13 + a3) + 8LL), *(_DWORD *)(v13 + 2728));
  v24 = qdf_opmode_str(*(_DWORD *)(v13 + 2728));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Device_mode %s(%d)",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "__wlan_hdd_del_virtual_intf",
    v24,
    *(unsigned int *)(v13 + 2728));
  result = _wlan_hdd_validate_context(
             (__int64)v12,
             (__int64)"__wlan_hdd_del_virtual_intf",
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40);
  if ( !(_DWORD)result )
  {
    result = hdd_trigger_psoc_idle_restart((__int64)v12);
    if ( !(_DWORD)result )
    {
      if ( wlan_hdd_is_session_type_monitor(*(_DWORD *)(v13 + 2728), v41, v42, v43, v44, v45, v46, v47, v48) )
        ucfg_dp_set_mon_conf_flags(*v12, 0);
      v57 = *(_DWORD *)(v13 + 2728);
      if ( v57 == 1 )
      {
        if ( (ucfg_pre_cac_is_active(*v12) & 1) != 0 )
        {
          ucfg_pre_cac_clean_up(*v12);
          hdd_clean_up_interface(v12, v13 + 2688, v58, v59, v60, v61, v62, v63, v64, v65);
LABEL_14:
          if ( (hdd_is_any_interface_open((__int64)v12, v66, v67, v68, v69, v70, v71, v72, v73) & 1) == 0 )
            hdd_psoc_idle_timer_start((__int64)v12, v98, v99, v100, v101, v102, v103, v104, v105);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            v104,
            v105,
            "__wlan_hdd_del_virtual_intf");
          return 0;
        }
        v57 = *(_DWORD *)(v13 + 2728);
      }
      wlan_hdd_is_session_type_monitor(v57, v49, v50, v51, v52, v53, v54, v55, v56);
      wlan_hdd_release_intf_addr((__int64)v12, (unsigned __int8 *)(v13 + 4305), v74, v75, v76, v77, v78, v79, v80, v81);
      hdd_stop_adapter(v12, v13 + 2688);
      hdd_deinit_adapter(v82, v83, v84, v85, v86, v87, v88, v89, (__int64)v12, v13 + 2688);
      hdd_close_adapter(v12, v13 + 2688, 1, v90, v91, v92, v93, v94, v95, v96, v97);
      goto LABEL_14;
    }
  }
  return result;
}
