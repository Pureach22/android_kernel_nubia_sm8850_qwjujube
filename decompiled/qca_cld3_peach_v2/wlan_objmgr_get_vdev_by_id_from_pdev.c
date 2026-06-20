_QWORD *__fastcall wlan_objmgr_get_vdev_by_id_from_pdev(__int64 a1, char a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v7; // x1
  __int64 v8; // x8
  _QWORD *result; // x0
  _QWORD *v10; // x21
  int ref; // w0
  __int64 v12; // x8
  _QWORD *v13; // x20
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v14[0] = 0;
  if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v14) || (v7 = (_QWORD *)v14[0]) == nullptr )
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
      v14[0] = 0;
      if ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v7, v14) )
      {
        v7 = (_QWORD *)v14[0];
        if ( v14[0] )
          continue;
      }
      goto LABEL_10;
    }
    v10 = v7;
    ref = wlan_objmgr_vdev_try_get_ref(v7, a3);
    v12 = *(_QWORD *)(a1 + 1256);
    if ( ref )
      v13 = nullptr;
    else
      v13 = v10;
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1256) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1248);
    }
    else
    {
      raw_spin_unlock(a1 + 1248);
    }
    result = v13;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
