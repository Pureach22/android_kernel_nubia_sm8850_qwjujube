__int64 __fastcall wma_objmgr_set_peer_mlme_phymode(__int64 a1, _BYTE *a2, int a3)
{
  __int64 result; // x0
  __int64 v5; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  result = wlan_objmgr_get_peer(*(_QWORD *)(a1 + 24), *(_BYTE *)(*(_QWORD *)(a1 + 32) + 40LL), a2, 8u);
  if ( result )
  {
    v5 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 760);
    }
    else
    {
      raw_spin_lock_bh(result + 760);
      *(_QWORD *)(v5 + 768) |= 1uLL;
    }
    wlan_peer_set_phymode(v5, a3);
    v7 = *(_QWORD *)(v5 + 768);
    if ( (v7 & 1) != 0 )
    {
      *(_QWORD *)(v5 + 768) = v7 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v5 + 760);
    }
    else
    {
      raw_spin_unlock(v5 + 760);
    }
    return wlan_objmgr_peer_release_ref(v5, 8u, v8, v9, v10, v11, v12, v13, v14, v15);
  }
  return result;
}
