__int64 __fastcall wlan_vdev_chan_change_pending(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v7; // x8
  __int64 v8; // x8

  v3 = *(_QWORD *)(result + 80);
  if ( v3 )
  {
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
    if ( !(unsigned int)wlan_vdev_chan_config_valid(a2) )
    {
      v7 = *(unsigned __int8 *)(a2 + 104);
      if ( *(unsigned __int16 *)(v3 + 54) > (unsigned int)v7 )
        *(_QWORD *)(a3 + ((v7 >> 3) & 0x18)) |= 1LL << v7;
    }
    v8 = *(_QWORD *)(a2 + 1280);
    if ( (v8 & 1) != 0 )
    {
      *(_QWORD *)(a2 + 1280) = v8 & 0xFFFFFFFFFFFFFFFELL;
      return raw_spin_unlock_bh(a2 + 1272);
    }
    else
    {
      return raw_spin_unlock(a2 + 1272);
    }
  }
  return result;
}
