__int64 __fastcall hdd_objmgr_set_peer_mlme_state(__int64 a1)
{
  __int64 bsspeer; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 6u);
  if ( bsspeer )
  {
    v10 = bsspeer;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(bsspeer + 760);
      v12 = *(_QWORD *)(v10 + 768);
    }
    else
    {
      raw_spin_lock_bh(bsspeer + 760);
      v12 = *(_QWORD *)(v10 + 768) | 1LL;
      *(_QWORD *)(v10 + 768) = v12;
    }
    *(_DWORD *)(v10 + 80) = 4;
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 768) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 760);
    }
    else
    {
      raw_spin_unlock(v10 + 760);
    }
    wlan_objmgr_peer_release_ref(v10, 6u, v13, v14, v15, v16, v17, v18, v19, v20);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: peer is null", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_objmgr_set_peer_mlme_state");
    return 4294967274LL;
  }
}
