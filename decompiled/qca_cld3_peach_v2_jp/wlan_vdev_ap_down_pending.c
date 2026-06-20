__int64 __fastcall wlan_vdev_ap_down_pending(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  int vdev_active_cmd_type; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x8

  v3 = *(_QWORD *)(result + 80);
  if ( v3 && *(_DWORD *)(a2 + 16) == 1 )
  {
    vdev_active_cmd_type = wlan_serialization_get_vdev_active_cmd_type(a2);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a2 + 1272);
    }
    else
    {
      raw_spin_lock_bh(a2 + 1272);
      *(_QWORD *)(a2 + 1280) |= 1uLL;
    }
    if ( (unsigned int)wlan_vdev_mlme_is_init_state(a2) || vdev_active_cmd_type == 21 )
    {
      v8 = *(unsigned __int8 *)(a2 + 104);
      if ( *(unsigned __int16 *)(v3 + 54) > (unsigned int)v8 )
        *(_QWORD *)(a3 + ((v8 >> 3) & 0x18)) |= 1LL << v8;
    }
    v9 = *(_QWORD *)(a2 + 1280);
    if ( (v9 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 1280) = v9 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a2 + 1272);
    }
    else
    {
      return raw_spin_unlock(a2 + 1272);
    }
  }
  return result;
}
