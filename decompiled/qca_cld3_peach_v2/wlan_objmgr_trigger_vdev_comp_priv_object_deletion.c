__int64 __fastcall wlan_objmgr_trigger_vdev_comp_priv_object_deletion(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1

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
  v6 = *(_QWORD *)(a1 + 1352);
  if ( !*(_QWORD *)(a1 + 8LL * a2 + 688) )
  {
    if ( (v6 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1352) = v6 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1344);
    }
    else
    {
      raw_spin_unlock(a1 + 1344);
    }
    return 16;
  }
  if ( (v6 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1352) = v6 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1344);
  }
  else
  {
    raw_spin_unlock(a1 + 1344);
  }
  v7 = g_umac_glb_obj + 8LL * a2;
  v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 6096);
  if ( !v8 )
    return 16;
  v9 = *(_QWORD *)(v7 + 6528);
  if ( *((_DWORD *)v8 - 1) != -1744405434 )
    __break(0x8228u);
  *(_DWORD *)(a1 + 4LL * a2 + 1120) = v8(a1, v9);
  if ( *(_DWORD *)(a1 + 1336) != 1 )
    return 0;
  result = wlan_objmgr_vdev_object_status(a1);
  if ( (_DWORD)result == 40 )
    *(_DWORD *)(a1 + 1336) = 5;
  return result;
}
