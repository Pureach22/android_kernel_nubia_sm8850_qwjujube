__int64 __fastcall pmo_core_get_ns_offload_params(
        __int64 a1,
        void *a2,
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
  unsigned int ref; // w21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 comp_private_obj; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int *v46; // x8
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned __int64 StatusReg; // x8
  __int64 v56; // x8

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_get_ns_offload_params");
  if ( a2 )
  {
    qdf_mem_set(a2, 0x28Cu, 0);
    if ( a1 )
    {
      ref = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, v12, v13, v14, v15, v16, v17, v18, v19);
      if ( !ref )
      {
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
        if ( (*(_BYTE *)(*(_QWORD *)wlan_objmgr_vdev_get_comp_private_obj(a1, 4u) + 8LL) & 1) != 0 )
        {
          if ( (pmo_core_is_vdev_supports_offload(a1, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
          {
            if ( (unsigned int)wlan_vdev_is_up() )
            {
              ref = 4;
            }
            else
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
              memcpy(a2, (const void *)(comp_private_obj + 20), 0x28Cu);
              v56 = *(_QWORD *)(comp_private_obj + 1064);
              if ( (v56 & 1) != 0 )
              {
                *(_QWORD *)(comp_private_obj + 1064) = v56 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(comp_private_obj + 1056);
              }
              else
              {
                raw_spin_unlock(comp_private_obj + 1056);
              }
              ref = 0;
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: vdev in invalid opmode for ns offload %d",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "pmo_core_ns_offload_sanity",
              *(unsigned int *)(a1 + 16));
            ref = 4;
          }
        }
        else
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: ns offload statically disable",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "pmo_core_ns_offload_sanity");
          ref = 4;
        }
        wlan_objmgr_vdev_release_ref(a1, 0xAu, v46, v47, v48, v49, v50, v51, v52, v53, v54);
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: vdev is NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "pmo_core_get_ns_offload_params");
      ref = 4;
    }
    qdf_trace_msg(0x4Du, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "pmo_core_get_ns_offload_params");
  }
  else
  {
    return 4;
  }
  return ref;
}
