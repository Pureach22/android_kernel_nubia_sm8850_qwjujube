__int64 __fastcall pmo_core_get_mc_addr_list(
        __int64 a1,
        unsigned int a2,
        void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int ref; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
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
  unsigned int *v41; // x8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 comp_private_obj; // x0
  __int64 v51; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "pmo_core_get_mc_addr_list");
  if ( a3 )
  {
    qdf_mem_set(a3, 0xC2u, 0);
    ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( !ref )
    {
      v31 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
      if ( v31 )
      {
        v40 = v31;
        ref = pmo_core_mc_addr_flitering_sanity(v31);
        if ( !ref )
        {
          comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v40, 4u);
          v51 = comp_private_obj;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(comp_private_obj + 1056);
          }
          else
          {
            raw_spin_lock_bh(comp_private_obj + 1056);
            *(_QWORD *)(v51 + 1064) |= 1uLL;
          }
          memcpy(a3, (const void *)(v51 + 672), 0xC2u);
          v53 = *(_QWORD *)(v51 + 1064);
          if ( (v53 & 1) != 0 )
          {
            *(_QWORD *)(v51 + 1064) = v53 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v51 + 1056);
          }
          else
          {
            raw_spin_unlock(v51 + 1056);
          }
        }
        wlan_objmgr_vdev_release_ref(v40, 0xAu, v41, v42, v43, v44, v45, v46, v47, v48, v49);
      }
      else
      {
        qdf_trace_msg(
          0x4Du,
          2u,
          "%s: vdev is NULL",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "pmo_core_get_mc_addr_list");
        ref = 4;
      }
      wlan_objmgr_psoc_release_ref(a1, 0xAu, v54, v55, v56, v57, v58, v59, v60, v61);
    }
    qdf_trace_msg(0x4Du, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "pmo_core_get_mc_addr_list");
  }
  else
  {
    return 4;
  }
  return ref;
}
