__int64 __fastcall pmo_core_flush_gtk_offload_req(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 comp_private_obj; // x0
  __int64 v29; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v31; // x8
  unsigned int *v32; // x8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20

  if ( a1 )
  {
    result = wlan_objmgr_vdev_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
    if ( !(_DWORD)result )
    {
      v19 = *(_DWORD *)(a1 + 16);
      qdf_trace_msg(
        0x4Du,
        8u,
        "%s: vdev opmode: %d vdev_id: %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "pmo_core_flush_gtk_offload_req",
        v19,
        *(unsigned __int8 *)(a1 + 104));
      if ( (pmo_core_is_vdev_supports_offload(a1) & 1) != 0 )
      {
        comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
        v29 = comp_private_obj;
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(comp_private_obj + 1056);
        }
        else
        {
          raw_spin_lock_bh(comp_private_obj + 1056);
          *(_QWORD *)(v29 + 1064) |= 1uLL;
        }
        qdf_mem_set((void *)(v29 + 872), 0x80u, 0);
        v31 = *(_QWORD *)(v29 + 1064);
        *(_DWORD *)(v29 + 872) = 1;
        if ( (v31 & 1) != 0 )
        {
          *(_QWORD *)(v29 + 1064) = v31 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v29 + 1056);
        }
        else
        {
          raw_spin_unlock(v29 + 1056);
        }
        v41 = 0;
      }
      else
      {
        qdf_trace_msg(
          0x4Du,
          8u,
          "%s: vdev in invalid opmode for flushing gtk request %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "pmo_core_flush_gtk_offload_req",
          v19);
        v41 = 4;
      }
      wlan_objmgr_vdev_release_ref(a1, 0xAu, v32, v33, v34, v35, v36, v37, v38, v39, v40);
      return v41;
    }
  }
  else
  {
    qdf_trace_msg(0x4Du, 2u, "%s: psoc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_core_flush_gtk_offload_req");
    return 4;
  }
  return result;
}
