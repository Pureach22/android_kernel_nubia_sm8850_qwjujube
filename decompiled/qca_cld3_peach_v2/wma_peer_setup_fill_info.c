__int64 __fastcall wma_peer_setup_fill_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w22
  __int64 result; // x0
  char v8; // w8
  char v9; // w8
  char v10; // w10

  v6 = *(unsigned __int8 *)(*(_QWORD *)(a2 + 96) + 168LL);
  *(_QWORD *)a3 = a2 + 792;
  if ( (unsigned int)mlme_get_roam_state(a1, v6) == 6
    && (result = wlan_vdev_mlme_get_is_mlo_link(a1, v6), (result & 1) != 0) )
  {
    v8 = *(_BYTE *)(a3 + 8) & 0xFC | 1;
  }
  else
  {
    result = wlan_cm_is_roam_sync_in_progress(a1, v6);
    if ( (result & 1) != 0 && (result = wlan_vdev_mlme_get_is_mlo_vdev(a1, v6), (result & 1) != 0) )
    {
      result = mlo_get_single_link_ml_roaming(a1, v6);
      v9 = *(_BYTE *)(a3 + 8);
      if ( (result & 1) != 0 )
        v8 = v9 | 3;
      else
        v8 = v9 & 0xFC | 2;
    }
    else
    {
      if ( *(_BYTE *)(a2 + 88) )
        v10 = 2;
      else
        v10 = 0;
      v8 = v10 | *(_BYTE *)(a3 + 8) & 0xFC | *(_BYTE *)(a2 + 88);
    }
  }
  *(_BYTE *)(a3 + 8) = v8;
  return result;
}
