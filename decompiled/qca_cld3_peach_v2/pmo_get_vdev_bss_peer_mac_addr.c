__int64 __fastcall pmo_get_vdev_bss_peer_mac_addr(
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
  __int64 bsspeer; // x0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: vdev is null";
LABEL_12:
    qdf_trace_msg(0x4Du, 2u, v24, a3, a4, a5, a6, a7, a8, a9, a10, "pmo_get_vdev_bss_peer_mac_addr");
    return 4;
  }
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0xAu);
  if ( !bsspeer )
  {
    v24 = "%s: peer is null";
    goto LABEL_12;
  }
  v12 = bsspeer;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(bsspeer + 768);
  }
  else
  {
    raw_spin_lock_bh(bsspeer + 768);
    *(_QWORD *)(v12 + 776) |= 1uLL;
  }
  qdf_mem_copy(a2, (const void *)(v12 + 48), 6u);
  v14 = *(_QWORD *)(v12 + 776);
  if ( (v14 & 1) != 0 )
  {
    *(_QWORD *)(v12 + 776) = v14 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v12 + 768);
  }
  else
  {
    raw_spin_unlock(v12 + 768);
  }
  wlan_objmgr_peer_release_ref(v12, 0xAu, v15, v16, v17, v18, v19, v20, v21, v22);
  return 0;
}
