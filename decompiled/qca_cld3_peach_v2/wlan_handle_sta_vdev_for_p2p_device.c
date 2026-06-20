__int64 __fastcall wlan_handle_sta_vdev_for_p2p_device(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v4; // w8
  int v5; // [xsp+0h] [xbp-10h] BYREF
  __int16 v6; // [xsp+4h] [xbp-Ch]
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  v5 = 0;
  result = ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1, a2);
  if ( (result & 1) != 0 )
  {
    wlan_mlme_get_p2p_device_mac_addr(*(_QWORD *)a2, &v5);
    result = qdf_mem_copy((int)a2 + 1901, (int)&v5, 6u);
    v4 = *(_DWORD *)(a2 + 2072);
    *(_BYTE *)(a2 + 1900) = 1;
    *(_DWORD *)(a2 + 2072) = v4 | 0x100000;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
