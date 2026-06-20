__int64 __fastcall pmo_core_enable_gtk_offload_in_fwr(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int ref; // w21
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 comp_private_obj; // x21
  __int64 v28; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _DWORD *v38; // x20
  unsigned int *v39; // x8
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
  unsigned int v56; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_enable_gtk_offload_in_fwr");
  if ( a1 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v10, v11, v12, v13, v14, v15, v16, v17);
    if ( !ref )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      v28 = _qdf_mem_malloc(0x80u, "pmo_core_enable_gtk_offload_in_fwr", 278);
      if ( v28 )
      {
        v38 = (_DWORD *)v28;
        if ( *(_DWORD *)(a1 + 16) == 11 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: gtk offload is not supported in NaN mode",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "pmo_core_do_enable_gtk_offload");
          ref = 4;
LABEL_23:
          wlan_objmgr_vdev_release_ref(a1, 0xAu, v39, v40, v41, v42, v43, v44, v45, v46, v47);
          _qdf_mem_free((__int64)v38);
          goto LABEL_24;
        }
        if ( (pmo_core_is_vdev_supports_offload(a1) & 1) == 0 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: vdev in invalid opmode for gtk offload %d",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "pmo_core_do_enable_gtk_offload",
            *(unsigned int *)(a1 + 16));
          ref = 4;
          goto LABEL_23;
        }
        if ( (unsigned int)wlan_vdev_is_up() )
        {
          ref = 4;
          goto LABEL_23;
        }
        v56 = *(unsigned __int8 *)(a1 + 168);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 1056);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 1056);
          *(_QWORD *)(comp_private_obj + 1064) |= 1uLL;
        }
        qdf_mem_copy(v38, (const void *)(comp_private_obj + 872), 0x80u);
        v58 = *(_QWORD *)(comp_private_obj + 1064);
        if ( (v58 & 1) != 0 )
        {
          *(_QWORD *)(comp_private_obj + 1064) = v58 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 1056);
          if ( *v38 )
            goto LABEL_22;
        }
        else
        {
          raw_spin_unlock(comp_private_obj + 1056);
          if ( *v38 )
            goto LABEL_22;
        }
        if ( *(_DWORD *)(comp_private_obj + 1024) == 1 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: GTK Offload already enabled, Disabling vdev_id: %d",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "pmo_core_do_enable_gtk_offload",
            v56);
          *v38 = 1;
          v67 = pmo_tgt_send_gtk_offload_req(a1, v38);
          if ( v67 )
          {
            ref = v67;
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Failed to disable GTK Offload",
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              "pmo_core_do_enable_gtk_offload");
            goto LABEL_23;
          }
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: Enable GTK Offload again with updated inputs",
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            "pmo_core_do_enable_gtk_offload");
          *v38 = 0;
        }
LABEL_22:
        ref = pmo_tgt_send_gtk_offload_req(a1, v38);
        goto LABEL_23;
      }
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      ref = 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: vdev is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "pmo_core_enable_gtk_offload_in_fwr");
    ref = 4;
  }
LABEL_24:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v19, v20, v21, v22, v23, v24, v25, v26, "pmo_core_enable_gtk_offload_in_fwr");
  return ref;
}
