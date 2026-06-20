_QWORD *__fastcall wlan_vdev_get_next_active_vdev_of_pdev(__int64 a1, _QWORD *a2, _QWORD *a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD *v16; // x22
  __int64 v17; // x8
  __int64 v18; // x8
  _QWORD *v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = a3;
  if ( a3 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 1248);
    }
    else
    {
      raw_spin_lock_bh(a1 + 1248);
      *(_QWORD *)(a1 + 1256) |= 1uLL;
    }
    while ( !(unsigned int)qdf_list_peek_next(a2, v20[0], v20) )
    {
      v16 = v20[0];
      if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref((__int64)v20[0], a4, v8, v9, v10, v11, v12, v13, v14, v15) )
      {
        v17 = *(_QWORD *)(a1 + 1256);
        if ( (v17 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1256) = v17 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1248);
        }
        else
        {
          raw_spin_unlock(a1 + 1248);
        }
        goto LABEL_13;
      }
    }
    v18 = *(_QWORD *)(a1 + 1256);
    if ( (v18 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v18 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
  }
  v16 = nullptr;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v16;
}
