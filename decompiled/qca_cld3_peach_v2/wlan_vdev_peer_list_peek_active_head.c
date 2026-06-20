_QWORD *__fastcall wlan_vdev_peer_list_peek_active_head(__int64 a1, _QWORD *a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  _QWORD *v16; // x22
  __int64 v18; // x8
  _QWORD *v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v19[0] = nullptr;
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
  if ( (unsigned int)qdf_list_peek_front(a2, v19) )
  {
LABEL_6:
    v15 = *(_QWORD *)(a1 + 1352);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    v16 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v16 = v19[0] - 2;
      if ( !(unsigned int)wlan_objmgr_peer_try_get_ref((__int64)(v19[0] - 2), a3, v7, v8, v9, v10, v11, v12, v13, v14) )
        break;
      if ( (unsigned int)qdf_list_peek_next(a2, v19[0], v19) )
        goto LABEL_6;
    }
    v18 = *(_QWORD *)(a1 + 1352);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
