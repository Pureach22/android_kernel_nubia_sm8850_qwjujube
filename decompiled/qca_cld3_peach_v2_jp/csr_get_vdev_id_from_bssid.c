__int64 __fastcall csr_get_vdev_id_from_bssid(__int64 a1, __int64 a2, _BYTE *a3)
{
  __int64 result; // x0
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = wlan_vdev_is_up();
  if ( !(_DWORD)result )
  {
    result = wlan_objmgr_vdev_try_get_bsspeer(a2, 0xBu);
    if ( result )
    {
      v6 = result;
      if ( !(unsigned int)qdf_mem_cmp(a3, (const void *)(result + 48), 6u) )
        a3[6] = *(_BYTE *)(a2 + 104);
      return wlan_objmgr_peer_release_ref(v6, 0xBu, v7, v8, v9, v10, v11, v12, v13, v14);
    }
  }
  return result;
}
