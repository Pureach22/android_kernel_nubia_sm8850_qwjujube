__int64 __fastcall hdd_stop(__int64 a1)
{
  unsigned int v2; // w0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w19
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  v2 = _osif_vdev_sync_trans_start(a1, v13, "hdd_stop");
  if ( v2 )
  {
    v11 = v2;
    if ( v13[0] )
      osif_vdev_cache_command(v13[0], 1);
  }
  else
  {
    v11 = hdd_stop_no_trans(a1, v3, v4, v5, v6, v7, v8, v9, v10);
    osif_vdev_sync_trans_stop(v13[0]);
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
