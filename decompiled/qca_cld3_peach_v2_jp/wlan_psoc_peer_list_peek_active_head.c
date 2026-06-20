_QWORD *__fastcall wlan_psoc_peer_list_peek_active_head(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v7; // x22
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  _QWORD *v17; // x21
  __int64 v19; // x8
  _QWORD *v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1536);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1536);
    *(_QWORD *)(a1 + 1544) |= 1uLL;
  }
  if ( a2 >= 0x41u )
    __break(0x5512u);
  v7 = (_QWORD *)(a1 + 24LL * a2);
  if ( (unsigned int)qdf_list_peek_front(v7, v20) )
  {
LABEL_7:
    v16 = *(_QWORD *)(a1 + 1544);
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1544) = v16 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1536);
    }
    else
    {
      raw_spin_unlock(a1 + 1536);
    }
    v17 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v17 = v20[0];
      if ( !(unsigned int)wlan_objmgr_peer_try_get_ref((__int64)v20[0], a3, v8, v9, v10, v11, v12, v13, v14, v15) )
        break;
      if ( (unsigned int)qdf_list_peek_next(v7, v20[0], v20) )
        goto LABEL_7;
    }
    v19 = *(_QWORD *)(a1 + 1544);
    if ( (v19 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1544) = v19 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1536);
    }
    else
    {
      raw_spin_unlock(a1 + 1536);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
