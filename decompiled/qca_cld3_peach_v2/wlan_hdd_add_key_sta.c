__int64 __fastcall wlan_hdd_add_key_sta(__int64 *a1, char a2, unsigned int a3, __int64 a4)
{
  __int64 v5; // x22
  __int64 vdev_by_user; // x0
  unsigned int v9; // w2
  __int64 v10; // x21
  unsigned int v11; // w19
  __int64 result; // x0

  v5 = *a1;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "wlan_hdd_add_key_sta");
  if ( !vdev_by_user )
    return 4294967274LL;
  v9 = (a2 & 1) == 0;
  v10 = vdev_by_user;
  v11 = wlan_cfg80211_crypto_add_key(vdev_by_user, a4, v9, a3, 1);
  _hdd_objmgr_put_vdev_by_user(v10, 6, "wlan_hdd_add_key_sta");
  result = v11;
  if ( !v11 )
  {
    if ( *(_BYTE *)(v5 + 52208) == 1 )
    {
      ((void (__fastcall *)(_QWORD))wlan_hdd_send_mode_change_event)(v11);
      *(_BYTE *)(v5 + 52208) = 0;
    }
    return 0;
  }
  return result;
}
