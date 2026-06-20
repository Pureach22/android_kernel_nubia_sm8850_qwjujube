_QWORD *__fastcall wlan_objmgr_get_vdev_by_macaddr_from_pdev_no_state(__int64 a1, const void *a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  _QWORD *v7; // x22
  __int64 v8; // x8
  __int64 v9; // x8
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v11[0] = 0;
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v11) )
  {
    do
    {
      v7 = (_QWORD *)v11[0];
      if ( !v11[0] )
        break;
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v11[0] + 74LL), a2, 6u) )
      {
        wlan_objmgr_vdev_get_ref(v7, a3);
        v9 = *(_QWORD *)(a1 + 1256);
        if ( (v9 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1256) = v9 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1248);
        }
        else
        {
          raw_spin_unlock(a1 + 1248);
        }
        goto LABEL_14;
      }
      v11[0] = 0;
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v7, v11) );
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
  v7 = nullptr;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v7;
}
