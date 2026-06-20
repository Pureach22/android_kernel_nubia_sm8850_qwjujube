__int64 __fastcall hdd_stop_adapter(__int64 *a1, __int64 a2)
{
  int v2; // w8
  __int64 adapter; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  unsigned __int64 StatusReg; // x9
  __int64 v16; // x8
  __int64 v17; // x9
  __int64 v19; // x22
  unsigned __int64 v26; // x10

  v2 = *(_DWORD *)(a2 + 40);
  if ( v2 == 7 || !v2 )
  {
    if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*a1) & 1) != 0 )
    {
      ucfg_p2p_psoc_priv_set_sta_vdev_id(*a1, 0xFFu);
      adapter = hdd_get_adapter((__int64)a1, 0);
      if ( adapter )
        wlan_mlme_set_p2p_device_mac_addr(
          *(_QWORD *)(*(_QWORD *)(adapter + 52832) + 32LL),
          nullptr,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13);
    }
    if ( *(_DWORD *)(a2 + 40) == 7 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*a1) & 1) != 0 )
    {
      ucfg_p2p_set_sta_vdev_for_p2p_dev_operations(*a1, 0);
      _X8 = (unsigned __int64 *)(*(_QWORD *)(a2 + 52832) + 5968LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      v14 = *(_QWORD *)(a2 + 52832);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v14 + 16);
      }
      else
      {
        v19 = v14;
        raw_spin_lock_bh(v14 + 16);
        *(_QWORD *)(v19 + 24) |= 1uLL;
      }
      *(_BYTE *)(*(_QWORD *)(a2 + 52832) + 8LL) = -1;
      *(_QWORD *)(*(_QWORD *)(a2 + 52832) + 32LL) = 0;
      v16 = *(_QWORD *)(a2 + 52832);
      v17 = *(_QWORD *)(v16 + 24);
      if ( (v17 & 1) != 0 )
      {
        *(_QWORD *)(v16 + 24) = v17 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v16 + 16);
      }
      else
      {
        raw_spin_unlock(v16 + 16);
      }
    }
  }
  hdd_stop_adapter_ext(a1, a2);
  return 0;
}
