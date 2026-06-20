__int64 __fastcall pmo_core_txrx_suspend(
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
  unsigned int ref; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w21
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x23
  __int64 hif_handle; // x20
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x22
  unsigned __int64 StatusReg; // x8
  __int64 v42; // x8
  __int64 **v43; // x21
  unsigned int v44; // w0
  __int64 v45; // x8
  _DWORD *v46; // x8
  __int64 v47; // x8
  __int64 (__fastcall *v48)(_QWORD); // x8
  unsigned int v50; // w20
  unsigned int v51; // w0

  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !ref )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( *(_DWORD *)(comp_private_obj + 492) != 3 )
      goto LABEL_28;
    v29 = comp_private_obj;
    hif_handle = pmo_core_psoc_get_hif_handle(a1);
    v31 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( !v31 )
    {
      v43 = nullptr;
      goto LABEL_21;
    }
    v40 = v31;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v31 + 1040);
      v42 = *(_QWORD *)(v40 + 1048);
      v43 = *(__int64 ***)(v40 + 960);
      if ( (v42 & 1) == 0 )
        goto LABEL_9;
    }
    else
    {
      raw_spin_lock_bh(v31 + 1040);
      v42 = *(_QWORD *)(v40 + 1048) | 1LL;
      *(_QWORD *)(v40 + 1048) = v42;
      v43 = *(__int64 ***)(v40 + 960);
      if ( (v42 & 1) == 0 )
      {
LABEL_9:
        raw_spin_unlock(v40 + 1040);
        if ( !hif_handle )
          goto LABEL_21;
        goto LABEL_10;
      }
    }
    *(_QWORD *)(v40 + 1048) = v42 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v40 + 1040);
    if ( !hif_handle )
      goto LABEL_21;
LABEL_10:
    if ( v43 )
    {
      v44 = hif_disable_grp_irqs(hif_handle);
      if ( v44 != -95 )
      {
        if ( v44 )
        {
          v50 = v44;
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Prevent suspend, failed to disable grp irqs: %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "pmo_core_txrx_suspend",
            v44);
          v19 = qdf_status_from_os_return(v50);
          goto LABEL_29;
        }
        if ( *v43 )
        {
          v45 = **v43;
          if ( v45 )
          {
            v46 = *(_DWORD **)(v45 + 856);
            if ( v46 )
            {
              if ( *(v46 - 1) != 261447488 )
                __break(0x8228u);
              v19 = ((__int64 (__fastcall *)(__int64 **, _QWORD))v46)(v43, 0);
              if ( !v19 )
              {
                *(_BYTE *)(v29 + 946) = 1;
LABEL_29:
                wlan_objmgr_psoc_release_ref(a1, 0xAu, v21, v22, v23, v24, v25, v26, v27, v28);
                return v19;
              }
LABEL_35:
              qdf_trace_msg(
                0x4Du,
                2u,
                "%s: Prevent suspend unable to drain txrx status:%u",
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                "pmo_core_txrx_suspend",
                v19);
              v51 = hif_enable_grp_irqs(hif_handle);
              if ( v51 != -95 && v51 )
              {
                qdf_trace_msg(
                  0x4Du,
                  2u,
                  "%s: Failed to enable grp irqs: %d",
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  v28,
                  "pmo_core_txrx_suspend",
                  v51);
                _qdf_trigger_self_recovery();
              }
              goto LABEL_29;
            }
          }
        }
        else
        {
          qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v21, v22, v23, v24, v25, v26, v27, v28, "cdp_drain_txrx");
        }
        v19 = 5;
        goto LABEL_35;
      }
      if ( !*v43 || (v47 = (*v43)[8]) == 0 )
      {
        qdf_trace_msg(
          0x89u,
          8u,
          "%s: Invalid Instance:",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "cdp_display_txrx_hw_info");
        v19 = 0;
        goto LABEL_29;
      }
      v48 = *(__int64 (__fastcall **)(_QWORD))(v47 + 280);
      if ( v48 )
      {
        if ( *((_DWORD *)v48 - 1) != 944657148 )
          __break(0x8228u);
        if ( (v48(v43) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Prevent suspend, ring not empty",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "pmo_core_txrx_suspend");
          v19 = 3;
          goto LABEL_29;
        }
      }
LABEL_28:
      v19 = 0;
      goto LABEL_29;
    }
LABEL_21:
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Invalid ctx hif: %pK, dp: %pK",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "pmo_core_txrx_suspend",
      hif_handle,
      v43);
    v19 = 4;
    goto LABEL_29;
  }
  v19 = ref;
  qdf_trace_msg(
    0x4Du,
    2u,
    "%s: pmo cannot get the reference out of psoc",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "pmo_core_txrx_suspend");
  return v19;
}
