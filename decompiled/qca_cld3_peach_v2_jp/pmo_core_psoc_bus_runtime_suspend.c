__int64 __fastcall pmo_core_psoc_bus_runtime_suspend(
        __int64 a1,
        __int64 (*a2)(void),
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
  unsigned int ref; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w25
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 hif_handle; // x21
  __int64 comp_private_obj; // x0
  __int64 v40; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v42; // x8
  __int64 v43; // x20
  unsigned __int8 txrx_handle; // w22
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x25
  unsigned __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x23
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  _QWORD *context; // x0
  unsigned int pending_0; // w0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  unsigned __int64 v159; // x8
  unsigned __int64 v160; // x25
  unsigned int v162; // w0
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  unsigned __int64 v171; // x8
  unsigned int v172; // w24
  unsigned __int64 v173; // x8
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  _QWORD v182[3]; // [xsp+8h] [xbp-18h] BYREF

  v182[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v182, 0, 12);
  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_psoc_bus_runtime_suspend");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: psoc is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "pmo_core_psoc_bus_runtime_suspend");
    v29 = 4;
    goto LABEL_58;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !ref )
  {
    hif_handle = pmo_core_psoc_get_hif_handle(a1);
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( comp_private_obj )
    {
      v40 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1040);
        v42 = *(_QWORD *)(v40 + 1048);
        v43 = *(_QWORD *)(v40 + 960);
        if ( (v42 & 1) == 0 )
        {
LABEL_10:
          raw_spin_unlock(v40 + 1040);
          goto LABEL_12;
        }
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1040);
        v42 = *(_QWORD *)(v40 + 1048) | 1LL;
        *(_QWORD *)(v40 + 1048) = v42;
        v43 = *(_QWORD *)(v40 + 960);
        if ( (v42 & 1) == 0 )
          goto LABEL_10;
      }
      *(_QWORD *)(v40 + 1048) = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v40 + 1040);
    }
    else
    {
      v43 = 0;
    }
LABEL_12:
    txrx_handle = pmo_core_psoc_get_txrx_handle(a1);
    v45 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( v45 )
    {
      v54 = v45;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v55 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v55 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v55 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v45 + 1040);
        v56 = *(_QWORD *)(v54 + 1048);
        v57 = *(_QWORD *)(v54 + 968);
        if ( (v56 & 1) == 0 )
          goto LABEL_17;
      }
      else
      {
        raw_spin_lock_bh(v45 + 1040);
        v56 = *(_QWORD *)(v54 + 1048) | 1LL;
        *(_QWORD *)(v54 + 1048) = v56;
        v57 = *(_QWORD *)(v54 + 968);
        if ( (v56 & 1) == 0 )
        {
LABEL_17:
          raw_spin_unlock(v54 + 1040);
          if ( !hif_handle )
            goto LABEL_56;
LABEL_20:
          if ( !v43 || !v57 || txrx_handle == 0xFF )
            goto LABEL_56;
          *(_QWORD *)((char *)v182 + 4) = 0x200000001LL;
          v58 = hif_pre_runtime_suspend(hif_handle);
          if ( (_DWORD)v58 )
          {
            v29 = qdf_status_from_os_return(v58);
            goto LABEL_47;
          }
          v29 = wlan_dp_runtime_suspend(v43, v59, v60, v61, v62, v63, v64, v65, v66);
          if ( v29 )
          {
LABEL_47:
            hif_process_runtime_suspend_failure();
            if ( (unsigned int)htc_runtime_resume(v57) )
              qdf_is_fw_down(v151, v152, v153, v154, v155, v156, v157, v158);
            goto LABEL_57;
          }
          v67 = htc_runtime_suspend();
          if ( (_DWORD)v67 )
          {
            v29 = qdf_status_from_os_return(v67);
LABEL_45:
            if ( (unsigned int)wlan_dp_runtime_resume(v43, v68, v69, v70, v71, v72, v73, v74, v75) )
              qdf_is_fw_down(v143, v144, v145, v146, v147, v148, v149, v150);
            goto LABEL_47;
          }
          v29 = pmo_tgt_psoc_set_runtime_pm_inprogress(a1, 1);
          if ( v29 || (v29 = pmo_core_psoc_configure_suspend(a1, 1)) != 0 )
          {
LABEL_43:
            if ( (unsigned int)pmo_tgt_psoc_set_runtime_pm_inprogress(a1, 0) )
              qdf_is_fw_down(v68, v69, v70, v71, v72, v73, v74, v75);
            goto LABEL_45;
          }
          v29 = pmo_core_psoc_bus_suspend_req(a1, 1u, (unsigned __int8 *)v182, v76, v77, v78, v79, v80, v81, v82, v83);
          if ( v29 )
          {
LABEL_42:
            pmo_core_psoc_configure_resume(a1, 1);
            goto LABEL_43;
          }
          v84 = hif_runtime_suspend(hif_handle);
          if ( (_DWORD)v84 )
          {
            v29 = qdf_status_from_os_return(v84);
LABEL_40:
            if ( (unsigned int)pmo_core_psoc_bus_resume_req(a1) )
              qdf_is_fw_down(v135, v136, v137, v138, v139, v140, v141, v142);
            goto LABEL_42;
          }
          v29 = pmo_core_txrx_suspend(a1, v85, v86, v87, v88, v89, v90, v91, v92);
          if ( v29 )
          {
LABEL_38:
            if ( (unsigned int)hif_runtime_resume(hif_handle) )
              qdf_is_fw_down(v127, v128, v129, v130, v131, v132, v133, v134);
            goto LABEL_40;
          }
          context = _cds_get_context(
                      71,
                      (__int64)"pmo_core_psoc_bus_runtime_suspend",
                      v93,
                      v94,
                      v95,
                      v96,
                      v97,
                      v98,
                      v99,
                      v100);
          pending_0 = cdp_rx_get_pending_0(context);
          if ( pending_0 )
          {
            v29 = 8;
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: Prevent suspend, RX frame pending %d",
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              v110,
              "pmo_core_psoc_bus_runtime_suspend",
              pending_0);
            goto LABEL_36;
          }
          if ( a2 )
          {
            __isb(0xFu);
            v159 = _ReadStatusReg(CNTVCT_EL0);
            if ( 10 * v159 >= v159 )
              v160 = 10 * v159 / 0xC0;
            else
              v160 = 10 * (v159 / 0xC0);
            if ( *((_DWORD *)a2 - 1) != 1874538549 )
              __break(0x8238u);
            v162 = a2();
            __isb(0xFu);
            v171 = _ReadStatusReg(CNTVCT_EL0);
            v172 = v162;
            v173 = 10 * v171 >= v171 ? 10 * v171 / 0xC0 : 10 * (v171 / 0xC0);
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: runtime pci bus suspend took total time %lu microseconds",
              v163,
              v164,
              v165,
              v166,
              v167,
              v168,
              v169,
              v170,
              "pmo_core_psoc_bus_runtime_suspend",
              v173 - v160);
            if ( v172 )
            {
              v29 = qdf_status_from_os_return(v172);
              goto LABEL_36;
            }
          }
          if ( (unsigned int)hif_pm_get_wake_irq_type(hif_handle) == 2 )
          {
            hif_rtpm_suspend_lock();
            if ( *(_DWORD *)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 580) )
            {
              hif_rtpm_suspend_unlock();
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: Target wake up received before suspend completion",
                v174,
                v175,
                v176,
                v177,
                v178,
                v179,
                v180,
                v181,
                "pmo_core_psoc_bus_runtime_suspend");
              v29 = 8;
LABEL_36:
              if ( (unsigned int)pmo_core_txrx_resume(a1, v111, v112, v113, v114, v115, v116, v117, v118) )
                qdf_is_fw_down(v119, v120, v121, v122, v123, v124, v125, v126);
              goto LABEL_38;
            }
            hif_process_runtime_suspend_success();
            hif_rtpm_suspend_unlock();
          }
          else
          {
            hif_process_runtime_suspend_success();
          }
          v29 = 0;
          goto LABEL_57;
        }
      }
      *(_QWORD *)(v54 + 1048) = v56 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v54 + 1040);
      if ( hif_handle )
        goto LABEL_20;
    }
    else
    {
      v57 = 0;
      if ( hif_handle )
        goto LABEL_20;
    }
LABEL_56:
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Invalid hif: %pK, dp: %pK, pdev_id: %d, htc: %pK",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "pmo_core_psoc_bus_runtime_suspend",
      hif_handle,
      v43,
      txrx_handle,
      v57);
    v29 = 4;
LABEL_57:
    wlan_objmgr_psoc_release_ref(a1, 0xAu, v151, v152, v153, v154, v155, v156, v157, v158);
    goto LABEL_58;
  }
  v29 = ref;
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: pmo cannot get the reference out of psoc",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "pmo_core_psoc_bus_runtime_suspend");
LABEL_58:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v30, v31, v32, v33, v34, v35, v36, v37, "pmo_core_psoc_bus_runtime_suspend");
  _ReadStatusReg(SP_EL0);
  return v29;
}
