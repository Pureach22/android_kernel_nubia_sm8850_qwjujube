__int64 __fastcall hdd_objmgr_set_peer_mlme_auth_state(__int64 a1, char a2)
{
  __int64 bsspeer; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
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

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 6u);
  if ( bsspeer )
  {
    v12 = bsspeer;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(bsspeer + 768);
      v14 = *(_QWORD *)(v12 + 776);
    }
    else
    {
      raw_spin_lock_bh(bsspeer + 768);
      v14 = *(_QWORD *)(v12 + 776) | 1LL;
      *(_QWORD *)(v12 + 776) = v14;
    }
    *(_BYTE *)(v12 + 87) = a2 & 1;
    if ( (v14 & 1) != 0 )
    {
      *(_QWORD *)(v12 + 776) = v14 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 768);
    }
    else
    {
      raw_spin_unlock(v12 + 768);
    }
    wlan_objmgr_peer_release_ref(v12, 6u, v15, v16, v17, v18, v19, v20, v21, v22);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: peer is null",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_objmgr_set_peer_mlme_auth_state");
    return 4294967274LL;
  }
}
