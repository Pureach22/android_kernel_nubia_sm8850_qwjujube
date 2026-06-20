__int64 __fastcall wlan_objmgr_vdev_component_obj_detach(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w0
  int v11; // w8
  int v12; // w8
  int v13; // w8

  if ( a2 > 0x35 )
    return 38;
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
  if ( *(_QWORD *)(a1 + 688 + 8LL * a2) == a3 )
  {
    *(_QWORD *)(a1 + 688 + 8LL * a2) = 0;
    *(_DWORD *)(a1 + 4LL * a2 + 1120) = 0;
    v9 = *(_QWORD *)(a1 + 1352);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v9 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    if ( (*(_DWORD *)(a1 + 1336) & 0xFFFFFFFE) != 4 )
      return 0;
    v10 = wlan_objmgr_vdev_object_status(a1);
    if ( v10 == 16 )
    {
      v12 = *(_DWORD *)(a1 + 1336);
      if ( v12 != 5 )
      {
        if ( v12 != 4 )
          return 0;
        v13 = 8;
LABEL_27:
        *(_DWORD *)(a1 + 1336) = v13;
        return 0;
      }
    }
    else
    {
      if ( v10 )
        return 0;
      v11 = *(_DWORD *)(a1 + 1336);
      if ( v11 == 2 )
        return wlan_objmgr_vdev_obj_free(a1);
      if ( v11 != 5 )
      {
        if ( v11 == 4 )
        {
          *(_DWORD *)(a1 + 1336) = 2;
          return wlan_objmgr_vdev_obj_free(a1);
        }
        return 0;
      }
    }
    v13 = 1;
    goto LABEL_27;
  }
  *(_DWORD *)(a1 + 4LL * a2 + 1120) = 16;
  v8 = *(_QWORD *)(a1 + 1352);
  if ( (v8 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  return 16;
}
