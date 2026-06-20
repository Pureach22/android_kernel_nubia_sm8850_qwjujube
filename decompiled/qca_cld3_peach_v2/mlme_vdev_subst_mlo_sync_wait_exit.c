__int64 __fastcall mlme_vdev_subst_mlo_sync_wait_exit(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 520);
  v2 = *(_QWORD *)(v1 + 1360);
  if ( v2 )
  {
    result = mlo_get_link_vdev_ix(*(_QWORD *)(v1 + 1360), v1);
    if ( (_BYTE)result != 0xFF && *(_DWORD *)(v1 + 16) == 1 )
      return wlan_util_change_map_index(*(_QWORD *)(v2 + 2232) + 88LL, result, 0);
  }
  return result;
}
