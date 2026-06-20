__int64 __fastcall pmo_core_get_gtk_rsp(
        __int64 a1,
        const void *a2,
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
  unsigned int ref; // w22
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 comp_private_obj; // x21
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v40; // x8
  const char *v41; // x4

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_get_gtk_rsp");
  if ( a1 && a2 )
  {
    ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( !ref )
    {
      comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
      ref = pmo_core_is_gtk_enabled_in_fwr(a1, comp_private_obj);
      if ( !ref )
      {
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
        qdf_mem_copy((void *)(comp_private_obj + 1000), a2, 0x10u);
        v40 = *(_QWORD *)(comp_private_obj + 1064);
        if ( (v40 & 1) != 0 )
        {
          *(_QWORD *)(comp_private_obj + 1064) = v40 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(comp_private_obj + 1056);
        }
        else
        {
          raw_spin_unlock(comp_private_obj + 1056);
        }
        ref = pmo_tgt_get_gtk_rsp(a1);
      }
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    }
  }
  else
  {
    if ( a1 )
      v41 = "gtk_rsp_req";
    else
      v41 = "vdev";
    qdf_trace_msg(0x4Du, 2u, "%s: %s is null", v12, v13, v14, v15, v16, v17, v18, v19, "pmo_core_get_gtk_rsp", v41);
    ref = 4;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_core_get_gtk_rsp");
  return ref;
}
