_QWORD *__fastcall wlan_objmgr_get_vdev_by_macaddr_from_pdev(__int64 a1, const void *a2, unsigned int a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x8
  _QWORD *v8; // x22
  __int64 v10; // x8
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
      v8 = (_QWORD *)v11[0];
      if ( !v11[0] )
        break;
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v11[0] + 74LL), a2, 6u)
        && !(unsigned int)wlan_objmgr_vdev_try_get_ref(v8, a3) )
      {
        v10 = *(_QWORD *)(a1 + 1256);
        if ( (v10 & 1) != 0 )
        {
          *(_QWORD *)(a1 + 1256) = v10 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(a1 + 1248);
        }
        else
        {
          raw_spin_unlock(a1 + 1248);
        }
        goto LABEL_9;
      }
      v11[0] = 0;
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v8, v11) );
  }
  v7 = *(_QWORD *)(a1 + 1256);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1256) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1248);
  }
  else
  {
    raw_spin_unlock(a1 + 1248);
  }
  v8 = nullptr;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v8;
}
