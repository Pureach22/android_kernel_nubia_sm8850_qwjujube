__int64 __fastcall wlan_vdev_get_bss_peer_mac(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: vdev is null", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_bss_peer_mac");
    return 4;
  }
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x43u);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x57u,
      8u,
      "%s: not able to find bss peer for vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_vdev_get_bss_peer_mac",
      *(unsigned __int8 *)(a1 + 168));
    return 4;
  }
  v21 = bsspeer;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(bsspeer + 768);
  }
  else
  {
    raw_spin_lock_bh(bsspeer + 768);
    *(_QWORD *)(v21 + 776) |= 1uLL;
  }
  qdf_mem_copy(a2, (const void *)(v21 + 48), 6u);
  v23 = *(_QWORD *)(v21 + 776);
  if ( (v23 & 1) != 0 )
  {
    *(_QWORD *)(v21 + 776) = v23 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v21 + 768);
  }
  else
  {
    raw_spin_unlock(v21 + 768);
  }
  wlan_objmgr_peer_release_ref(v21, 0x43u, v24, v25, v26, v27, v28, v29, v30, v31);
  return 0;
}
