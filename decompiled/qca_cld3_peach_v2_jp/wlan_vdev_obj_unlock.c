__int64 __fastcall wlan_vdev_obj_unlock(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 1280);
  if ( (v1 & 1) == 0 )
    return raw_spin_unlock(a1 + 1272);
  *(_QWORD *)(a1 + 1280) = v1 & 0xFFFFFFFFFFFFFFFELL;
  return raw_spin_unlock_bh(a1 + 1272);
}
