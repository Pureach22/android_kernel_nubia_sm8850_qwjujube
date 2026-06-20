__int64 __fastcall wlan_mlo_mgr_mld_vdev_detach(
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
  __int64 v9; // x8
  __int64 v10; // x20
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  unsigned int v22; // w20
  __int64 v23; // x9
  unsigned int (__fastcall *v24)(__int64, __int64, __int64); // x9
  __int64 v25; // x1
  unsigned __int64 StatusReg; // x8
  int v27; // w9
  __int64 v28; // x8

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
  {
    v12 = mlo_dev_ctx_deinit(a1);
    v21 = *(_QWORD *)(v10 + 2808);
    v22 = v12;
    if ( !v21 )
      goto LABEL_10;
    if ( !*(_QWORD *)v21 )
      goto LABEL_10;
    v23 = *(_QWORD *)(*(_QWORD *)v21 + 176LL);
    if ( !v23 )
      goto LABEL_10;
    v24 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(v23 + 16);
    if ( !v24 )
      goto LABEL_10;
    v25 = *(unsigned __int8 *)(a1 + 168);
    if ( *((_DWORD *)v24 - 1) != -612755781 )
      __break(0x8229u);
    if ( v24(v21, v25, a1 + 80) )
LABEL_10:
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Failed to detach DP vdev (%02x:%02x:%02x:**:**:%02x) from MLO Dev ctxt (%02x:%02x:%02x:**:**:%02x)",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_mlo_mgr_mld_vdev_detach",
        *(unsigned __int8 *)(a1 + 74),
        *(unsigned __int8 *)(a1 + 75),
        *(unsigned __int8 *)(a1 + 76),
        *(unsigned __int8 *)(a1 + 79),
        *(unsigned __int8 *)(a1 + 80),
        *(unsigned __int8 *)(a1 + 81),
        *(unsigned __int8 *)(a1 + 82),
        *(unsigned __int8 *)(a1 + 85));
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1344);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1344);
      *(_QWORD *)(a1 + 1352) |= 1uLL;
    }
    v27 = *(_DWORD *)(a1 + 64);
    v28 = *(_QWORD *)(a1 + 1352);
    *(_WORD *)(a1 + 84) = 0;
    *(_DWORD *)(a1 + 80) = 0;
    *(_DWORD *)(a1 + 64) = v27 & 0xFBFFFFFF;
    if ( (v28 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v28 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    return v22;
  }
  else
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: Failed to get psoc", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_mlo_mgr_mld_vdev_detach");
    return 16;
  }
}
