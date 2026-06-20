__int64 __fastcall drm_dp_dpcd_write(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4)
{
  int v7; // w20
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x1
  int v11; // w8

  if ( *((_BYTE *)a1 + 1552) == 1 )
    v7 = drm_dp_mst_dpcd_write();
  else
    v7 = drm_dp_dpcd_access((__int64)a1, 8u, a2, a3, a4);
  v8 = a1[157];
  if ( v7 < 1 )
  {
    if ( v8 )
      v10 = *(_QWORD *)(v8 + 8);
    else
      v10 = 0;
    _drm_dev_dbg(0, v10, 8, "%s: 0x%05x AUX %s (ret=%3d)\n", *a1, a2, "<-", (unsigned int)v7);
  }
  else
  {
    if ( v8 )
      v9 = *(_QWORD *)(v8 + 8);
    else
      v9 = 0;
    if ( (unsigned int)v7 >= 0x14 )
      v11 = 20;
    else
      v11 = v7;
    _drm_dev_dbg(0, v9, 8, "%s: 0x%05x AUX %s (ret=%3d) %*ph\n", *a1, a2, "<-", (unsigned int)v7, v11, a3);
  }
  return v7;
}
