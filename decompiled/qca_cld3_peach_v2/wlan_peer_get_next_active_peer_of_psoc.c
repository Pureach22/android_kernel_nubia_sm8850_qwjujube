_QWORD *__fastcall wlan_peer_get_next_active_peer_of_psoc(__int64 a1, unsigned __int8 a2, _QWORD *a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v9; // x22
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _QWORD *v18; // x21
  __int64 v19; // x8
  __int64 v21; // x8
  _QWORD *v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v22[0] = nullptr;
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
  v9 = (_QWORD *)(a1 + 24LL * a2);
  if ( (unsigned int)qdf_list_peek_next(v9, a3, v22) )
  {
LABEL_9:
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
    v18 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v18 = v22[0];
      if ( !(unsigned int)wlan_objmgr_peer_try_get_ref((__int64)v22[0], a4, v10, v11, v12, v13, v14, v15, v16, v17) )
        break;
      if ( (unsigned int)qdf_list_peek_next(v9, v22[0], v22) )
        goto LABEL_9;
    }
    v21 = *(_QWORD *)(a1 + 1544);
    if ( (v21 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1544) = v21 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1536);
    }
    else
    {
      raw_spin_unlock(a1 + 1536);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
