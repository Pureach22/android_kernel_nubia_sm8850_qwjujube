__int64 __fastcall pmo_core_psoc_bus_runtime_resume(
        __int64 a1,
        __int64 (__fastcall *a2)(_QWORD),
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
  unsigned int v29; // w21
  __int64 hif_handle; // x21
  __int64 comp_private_obj; // x0
  __int64 v32; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v34; // x8
  __int64 v35; // x20
  unsigned __int8 txrx_handle; // w22
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x25
  unsigned __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x24
  __int64 v50; // x0
  unsigned __int64 v51; // x8
  unsigned __int64 v52; // x25
  int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int64 v62; // x8
  int v63; // w23
  unsigned __int64 v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_psoc_bus_runtime_resume");
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
      "pmo_core_psoc_bus_runtime_resume");
    return 4;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
  if ( !ref )
  {
    hif_handle = pmo_core_psoc_get_hif_handle(a1);
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( comp_private_obj )
    {
      v32 = comp_private_obj;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(comp_private_obj + 1040);
        v34 = *(_QWORD *)(v32 + 1048);
        v35 = *(_QWORD *)(v32 + 960);
        if ( (v34 & 1) == 0 )
        {
LABEL_10:
          raw_spin_unlock(v32 + 1040);
          goto LABEL_12;
        }
      }
      else
      {
        raw_spin_lock_bh(comp_private_obj + 1040);
        v34 = *(_QWORD *)(v32 + 1048) | 1LL;
        *(_QWORD *)(v32 + 1048) = v34;
        v35 = *(_QWORD *)(v32 + 960);
        if ( (v34 & 1) == 0 )
          goto LABEL_10;
      }
      *(_QWORD *)(v32 + 1048) = v34 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v32 + 1040);
    }
    else
    {
      v35 = 0;
    }
LABEL_12:
    txrx_handle = pmo_core_psoc_get_txrx_handle(a1);
    v37 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( v37 )
    {
      v46 = v37;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (v47 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v47 + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(v47 + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v37 + 1040);
        v48 = *(_QWORD *)(v46 + 1048);
        v49 = *(_QWORD *)(v46 + 968);
        if ( (v48 & 1) == 0 )
          goto LABEL_17;
      }
      else
      {
        raw_spin_lock_bh(v37 + 1040);
        v48 = *(_QWORD *)(v46 + 1048) | 1LL;
        *(_QWORD *)(v46 + 1048) = v48;
        v49 = *(_QWORD *)(v46 + 968);
        if ( (v48 & 1) == 0 )
        {
LABEL_17:
          raw_spin_unlock(v46 + 1040);
          if ( !hif_handle )
            goto LABEL_46;
LABEL_20:
          if ( !v35 || !v49 || txrx_handle == 0xFF )
            goto LABEL_46;
          v50 = hif_pre_runtime_resume();
          if ( !a2 )
            goto LABEL_33;
          __isb(0xFu);
          v51 = _ReadStatusReg(CNTVCT_EL0);
          if ( 10 * v51 >= v51 )
            v52 = 10 * v51 / 0xC0;
          else
            v52 = 10 * (v51 / 0xC0);
          if ( *((_DWORD *)a2 - 1) != 1874538549 )
            __break(0x8237u);
          v53 = a2(v50);
          __isb(0xFu);
          v62 = _ReadStatusReg(CNTVCT_EL0);
          v63 = v53;
          v64 = 10 * v62 >= v62 ? 10 * v62 / 0xC0 : 10 * (v62 / 0xC0);
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: pci bus resume took total time %lu microseconds",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "pmo_core_psoc_bus_runtime_resume",
            v64 - v52);
          if ( !v63 )
          {
LABEL_33:
            if ( !(unsigned int)hif_runtime_resume(hif_handle) )
            {
              v29 = pmo_core_psoc_bus_resume_req(a1, v65, v66, v67, v68, v69, v70, v71, v72);
              if ( v29 )
                goto LABEL_35;
              v29 = pmo_core_txrx_resume(a1, v81, v82, v83, v84, v85, v86, v87, v88);
              if ( v29 )
                goto LABEL_35;
              hif_process_runtime_resume_linkup();
              pmo_core_psoc_configure_resume(a1, 1);
              v89 = pmo_tgt_psoc_set_runtime_pm_inprogress(a1, 0);
              v29 = v89;
              if ( (_DWORD)v89 )
                goto LABEL_35;
              hif_process_runtime_resume_success(v89);
              if ( !(unsigned int)htc_runtime_resume(v49) )
              {
                v29 = wlan_dp_runtime_resume(v35, v90, v91, v92, v93, v94, v95, v96, v97);
                if ( !v29 )
                  goto LABEL_47;
                goto LABEL_35;
              }
            }
          }
          v29 = 16;
LABEL_35:
          _qdf_trigger_self_recovery();
LABEL_47:
          wlan_objmgr_psoc_release_ref(a1, 0xAu, v73, v74, v75, v76, v77, v78, v79, v80);
          return v29;
        }
      }
      *(_QWORD *)(v46 + 1048) = v48 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v46 + 1040);
      if ( hif_handle )
        goto LABEL_20;
    }
    else
    {
      v49 = 0;
      if ( hif_handle )
        goto LABEL_20;
    }
LABEL_46:
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Invalid hif: %pK, dp: %pK, pdev_id: %d, htc: %pK",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "pmo_core_psoc_bus_runtime_resume",
      hif_handle,
      v35,
      txrx_handle,
      v49);
    v29 = 4;
    goto LABEL_47;
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
    "pmo_core_psoc_bus_runtime_resume");
  return v29;
}
