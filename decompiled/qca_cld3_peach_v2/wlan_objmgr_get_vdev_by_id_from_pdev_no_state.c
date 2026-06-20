_QWORD *__fastcall wlan_objmgr_get_vdev_by_id_from_pdev_no_state(__int64 a1, char a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v7; // x1
  __int64 v8; // x8
  _QWORD *result; // x0
  _QWORD *v10; // x21
  __int64 v11; // x8
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v12[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v12) || (v7 = (_QWORD *)v12[0]) == nullptr )
  {
LABEL_10:
    v8 = *(_QWORD *)(a1 + 1256);
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v8 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    result = nullptr;
  }
  else
  {
    while ( byte_A8[(_QWORD)v7] != a2 )
    {
      v12[0] = 0;
      if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v7, v12) )
      {
        v7 = (_QWORD *)v12[0];
        if ( v12[0] )
          continue;
      }
      goto LABEL_10;
    }
    v10 = v7;
    wlan_objmgr_vdev_get_ref(v7, a3);
    v11 = *(_QWORD *)(a1 + 1256);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    result = v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
