__int64 __fastcall wlan_hdd_bus_suspend(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 *context; // x0
  __int64 *v17; // x21
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x19
  _QWORD *v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w0
  unsigned int v47; // w0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w19
  const char *v57; // x2
  unsigned int v58; // w1
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w23
  const char *v68; // x2
  unsigned int v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w20
  unsigned int v88; // w0
  unsigned int v89; // w22
  unsigned int v90; // w0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w0
  unsigned int v100; // w21
  int v101; // w2
  unsigned int v102; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  unsigned int v111; // w0
  unsigned int v112; // w0
  unsigned int v113; // w0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int v122; // w0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned int v131; // w22
  int v132; // w2
  _QWORD *v133; // x0
  unsigned int pending; // w0
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  unsigned int v143; // w0
  __int64 v144; // [xsp+0h] [xbp-20h] BYREF
  char v145[4]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v146; // [xsp+10h] [xbp-10h]
  __int64 v147; // [xsp+18h] [xbp-8h]

  v147 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 4u, "%s: starting bus suspend", a1, a2, a3, a4, a5, a6, a7, a8, "__wlan_hdd_bus_suspend", 0, 0);
  context = _cds_get_context(51, (__int64)"__wlan_hdd_bus_suspend", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !context )
  {
    result = 4294967277LL;
    goto LABEL_20;
  }
  v17 = context;
  result = _wlan_hdd_validate_context(context, "__wlan_hdd_bus_suspend");
  if ( !(_DWORD)result )
  {
    if ( *((_DWORD *)v17 + 366) == 1 )
    {
      v27 = _cds_get_context(61, (__int64)"__wlan_hdd_bus_suspend", v19, v20, v21, v22, v23, v24, v25, v26);
      if ( !v27 )
      {
        result = 4294967274LL;
        goto LABEL_20;
      }
      v36 = (__int64)v27;
      v146 = 0;
      v37 = _cds_get_context(71, (__int64)"__wlan_hdd_bus_suspend", v28, v29, v30, v31, v32, v33, v34, v35);
      v46 = ucfg_dp_bus_suspend((__int64)v37, v38, v39, v40, v41, v42, v43, v44, v45);
      v47 = qdf_status_to_os_return(v46);
      if ( v47 )
      {
        v56 = v47;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed cdp bus suspend: %d",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "__wlan_hdd_bus_suspend",
          v47);
        result = v56;
        goto LABEL_20;
      }
      if ( (ucfg_ipa_is_tx_pending(v17[1]) & 1) != 0 )
      {
        v67 = -16;
        v68 = "%s: failed due to pending IPA TX comps";
LABEL_15:
        qdf_trace_msg(0x33u, 2u, v68, v59, v60, v61, v62, v63, v64, v65, v66, "__wlan_hdd_bus_suspend");
LABEL_16:
        v78 = ucfg_dp_bus_resume((__int64)v37, v70, v71, v72, v73, v74, v75, v76, v77);
        if ( !v78 )
        {
          _hif_system_pm_set_state(v36, 0);
          result = v67;
          goto LABEL_20;
        }
        v87 = v78;
        _cds_trigger_recovery(9, (__int64)"__wlan_hdd_bus_suspend", 1445, v79, v80, v81, v82, v83, v84, v85, v86);
        v88 = v87;
        goto LABEL_18;
      }
      v69 = hif_bus_early_suspend(v36);
      if ( v69 )
      {
        v67 = v69;
        v68 = "%s: Failed hif bus early suspend";
        goto LABEL_15;
      }
      v89 = ucfg_pmo_psoc_bus_suspend_req(*v17, 0, v145);
      v90 = qdf_status_to_os_return(v89);
      if ( v90 )
      {
        v67 = v90;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed pmo bus suspend: %d",
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          "__wlan_hdd_bus_suspend",
          v89);
        goto LABEL_23;
      }
      _hif_system_pm_set_state(v36, 3);
      v102 = hif_bus_suspend(v36);
      if ( v102 )
      {
        v67 = v102;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed hif bus suspend: %d",
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          "__wlan_hdd_bus_suspend");
        goto LABEL_27;
      }
      v112 = ucfg_pmo_core_txrx_suspend(*v17);
      v113 = qdf_status_to_os_return(v112);
      if ( v113 )
      {
        v67 = v113;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to suspend TXRX: %d",
          v114,
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          "__wlan_hdd_bus_suspend");
        goto LABEL_32;
      }
      v133 = _cds_get_context(71, (__int64)"__wlan_hdd_bus_suspend", v114, v115, v116, v117, v118, v119, v120, v121);
      pending = cdp_rx_get_pending(v133);
      if ( pending )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Prevent suspend, RX frame pending %d",
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          "__wlan_hdd_bus_suspend",
          pending);
        v143 = ucfg_pmo_core_txrx_resume(*v17);
        if ( v143 )
        {
          v131 = v143;
          v132 = 1416;
          goto LABEL_37;
        }
        v67 = -16;
LABEL_32:
        v122 = hif_bus_resume(v36);
        if ( !v122 )
        {
LABEL_27:
          v111 = ucfg_pmo_psoc_bus_resume_req(*v17, 0);
          if ( v111 )
          {
            v100 = v111;
            v101 = 1431;
LABEL_29:
            _cds_trigger_recovery(9, (__int64)"__wlan_hdd_bus_suspend", v101, v70, v71, v72, v73, v74, v75, v76, v77);
            v88 = v100;
LABEL_18:
            result = qdf_status_to_os_return(v88);
            goto LABEL_20;
          }
LABEL_23:
          v99 = hif_bus_late_resume(v36);
          if ( !v99 )
            goto LABEL_16;
          v100 = v99;
          v101 = 1438;
          goto LABEL_29;
        }
        v131 = v122;
        v132 = 1423;
LABEL_37:
        _cds_trigger_recovery(
          9,
          (__int64)"__wlan_hdd_bus_suspend",
          v132,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130);
        v88 = v131;
        goto LABEL_18;
      }
      v144 = 0x100000003LL;
      ucfg_dp_bbm_apply_independent_policy(*v17, (__int64)&v144);
      v57 = "%s: bus suspend succeeded";
      v58 = 4;
    }
    else
    {
      v57 = "%s: Driver Module closed; skipping suspend";
      v58 = 8;
    }
    qdf_trace_msg(0x33u, v58, v57, v19, v20, v21, v22, v23, v24, v25, v26, "__wlan_hdd_bus_suspend");
    result = 0;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
