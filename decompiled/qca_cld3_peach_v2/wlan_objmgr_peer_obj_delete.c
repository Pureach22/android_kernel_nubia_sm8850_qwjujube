__int64 __fastcall wlan_objmgr_peer_obj_delete(
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
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int64 v31; // x8
  __int64 v32; // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x57u, 2u, "%s: PEER is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_objmgr_peer_obj_delete");
    return 16;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 768);
    v11 = *(_QWORD *)(a1 + 776);
    if ( (v11 & 1) == 0 )
    {
LABEL_6:
      raw_spin_unlock(a1 + 768);
      goto LABEL_7;
    }
  }
  else
  {
    raw_spin_lock_bh(a1 + 768);
    v11 = *(_QWORD *)(a1 + 776) | 1LL;
    *(_QWORD *)(a1 + 776) = v11;
    if ( (v11 & 1) == 0 )
      goto LABEL_6;
  }
  *(_QWORD *)(a1 + 776) = v11 & 0xFFFFFFFFFFFFFFFELL;
  raw_spin_unlock_bh(a1 + 768);
LABEL_7:
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Logically deleting peer %02x:%02x:%02x:**:**:%02x",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_objmgr_peer_obj_delete",
    *(unsigned __int8 *)(a1 + 48),
    *(unsigned __int8 *)(a1 + 49),
    *(unsigned __int8 *)(a1 + 50),
    *(unsigned __int8 *)(a1 + 53));
  v20 = *(_QWORD *)(a1 + 96);
  if ( v20 && (v21 = *(_QWORD *)(v20 + 216)) != 0 )
    v22 = *(_QWORD *)(v21 + 80);
  else
    v22 = 0;
  wlan_minidump_remove(a1, 808, v22, 60, "wlan_objmgr_peer");
  qdf_get_pidx();
  qdf_trace_msg(
    0x57u,
    8u,
    "%s: Pending refs -- %d",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wlan_objmgr_print_peer_ref_ids",
    *(unsigned int *)(a1 + 104));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v31 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v31 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v31 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 768);
    v32 = *(_QWORD *)(a1 + 776);
  }
  else
  {
    raw_spin_lock_bh(a1 + 768);
    v32 = *(_QWORD *)(a1 + 776) | 1LL;
    *(_QWORD *)(a1 + 776) = v32;
  }
  *(_DWORD *)(a1 + 760) = 6;
  if ( (v32 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 776) = v32 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 768);
  }
  else
  {
    raw_spin_unlock(a1 + 768);
  }
  wlan_objmgr_peer_release_ref(a1, 0);
  return 0;
}
