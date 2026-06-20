__int64 __fastcall wlan_objmgr_vdev_try_get_bsspeer(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  _BOOL4 v14; // w21
  __int64 v15; // x8

  if ( result )
  {
    v2 = result;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(result + 1344);
      v13 = *(_QWORD *)(v2 + 184);
      if ( v13 )
        goto LABEL_6;
    }
    else
    {
      raw_spin_lock_bh(result + 1344);
      *(_QWORD *)(v2 + 1352) |= 1uLL;
      v13 = *(_QWORD *)(v2 + 184);
      if ( v13 )
      {
LABEL_6:
        v14 = wlan_objmgr_peer_try_get_ref(v13, a2, v5, v6, v7, v8, v9, v10, v11, v12) == 0;
        v15 = *(_QWORD *)(v2 + 1352);
        if ( (v15 & 1) == 0 )
        {
LABEL_7:
          raw_spin_unlock(v2 + 1344);
          goto LABEL_8;
        }
LABEL_14:
        *(_QWORD *)(v2 + 1352) = v15 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v2 + 1344);
LABEL_8:
        if ( v14 )
          return v13;
        else
          return 0;
      }
    }
    v14 = 0;
    v15 = *(_QWORD *)(v2 + 1352);
    if ( (v15 & 1) == 0 )
      goto LABEL_7;
    goto LABEL_14;
  }
  return result;
}
