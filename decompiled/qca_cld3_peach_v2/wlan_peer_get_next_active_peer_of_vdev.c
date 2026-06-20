__int64 __fastcall wlan_peer_get_next_active_peer_of_vdev(__int64 a1, _QWORD *a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x22
  unsigned __int64 StatusReg; // x8
  _QWORD *i; // x1
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v20; // x8
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a3;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  if ( a3 )
  {
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
    for ( i = (_QWORD *)(v4 + 16); !(unsigned int)qdf_list_peek_next(a2, i, v21); i = (_QWORD *)v21[0] )
    {
      v4 = v21[0] - 16LL;
      if ( !(unsigned int)wlan_objmgr_peer_try_get_ref(v21[0] - 16LL, a4, v10, v11, v12, v13, v14, v15, v16, v17) )
      {
        v20 = *(_QWORD *)(a1 + 1352);
        if ( (v20 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1352) = v20 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1344);
        }
        else
        {
          raw_spin_unlock(a1 + 1344);
        }
        goto LABEL_13;
      }
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
    v4 = 0;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v4;
}
