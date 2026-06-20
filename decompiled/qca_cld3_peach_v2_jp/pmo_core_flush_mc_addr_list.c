__int64 __fastcall pmo_core_flush_mc_addr_list(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 v11; // w21
  __int64 v12; // x0
  __int64 v13; // x19
  unsigned int *v14; // x8
  unsigned int v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 comp_private_obj; // x0
  __int64 v25; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  const char *v29; // x2

  if ( !a1 )
  {
    v29 = "%s: psoc is NULL";
LABEL_13:
    qdf_trace_msg(0x4Du, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, "pmo_core_flush_mc_addr_list");
    return 29;
  }
  v11 = a2;
  v12 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 10);
  if ( !v12 )
  {
    v29 = "%s: vdev is NULL";
    goto LABEL_13;
  }
  v13 = v12;
  v15 = pmo_core_mc_addr_flitering_sanity(v12);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Flush mc addr list for vdev id: %d psoc: %pK",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "pmo_core_flush_mc_addr_list",
      v11,
      a1);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v13, 4u);
    v25 = comp_private_obj;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1056);
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1056);
      *(_QWORD *)(v25 + 1064) |= 1uLL;
    }
    qdf_mem_set((void *)(v25 + 672), 0xC2u, 0);
    v27 = *(_QWORD *)(v25 + 1064);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(v25 + 1064) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v25 + 1056);
    }
    else
    {
      raw_spin_unlock(v25 + 1056);
    }
  }
  wlan_objmgr_vdev_release_ref(v13, 0xAu, v14, v16, v17, v18, v19, v20, v21, v22, v23);
  return v15;
}
