_QWORD *__fastcall wlan_objmgr_pdev_get_first_active_vdev(__int64 a1, unsigned int a2)
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
    raw_spin_lock(a1 + 1240);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1240);
    *(_QWORD *)(a1 + 1248) |= 1uLL;
  }
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 48), v9) )
  {
    do
    {
      v6 = v9[0];
      if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(v9[0], a2) )
      {
        if ( !(unsigned int)wlan_vdev_chan_config_valid(v6) )
        {
          v8 = *(_QWORD *)(a1 + 1248);
          if ( (v8 & 1) != 0 )
          {
            *(_QWORD *)(a1 + 1248) = v8 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(a1 + 1240);
          }
          else
          {
            raw_spin_unlock(a1 + 1240);
          }
          goto LABEL_9;
        }
        wlan_objmgr_vdev_release_ref(v6, a2);
      }
    }
    while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(a1 + 48), v9[0], v9) );
  }
  v5 = *(_QWORD *)(a1 + 1248);
  if ( (v5 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1248) = v5 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1240);
  }
  else
  {
    raw_spin_unlock(a1 + 1240);
  }
  v6 = nullptr;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v6;
}
