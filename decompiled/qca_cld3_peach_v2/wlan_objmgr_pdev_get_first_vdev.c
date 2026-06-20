_QWORD *__fastcall wlan_objmgr_pdev_get_first_vdev(__int64 a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x8
  _QWORD *v6; // x21
  __int64 v8; // x8
  _QWORD *v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = nullptr;
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
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v9) )
  {
LABEL_6:
    v5 = *(_QWORD *)(a1 + 1256);
    if ( (v5 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v5 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    v6 = nullptr;
  }
  else
  {
    while ( 1 )
    {
      v6 = v9[0];
      if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(v9[0], a2) )
        break;
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v9[0], v9) )
        goto LABEL_6;
    }
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
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
