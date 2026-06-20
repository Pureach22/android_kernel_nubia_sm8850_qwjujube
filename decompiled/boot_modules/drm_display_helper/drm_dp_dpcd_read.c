__int64 __fastcall drm_dp_dpcd_read(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4)
{
  int v8; // w20
  int v9; // w0
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x1
  int v13; // w8

  if ( (a1[194] & 1) != 0 )
  {
    if ( *((_BYTE *)a1 + 1552) )
    {
LABEL_3:
      v8 = drm_dp_mst_dpcd_read(a1, a2, a3, a4);
      goto LABEL_7;
    }
  }
  else
  {
    v9 = drm_dp_dpcd_probe(a1, 0);
    if ( v9 < 0 )
      return v9;
    if ( (a1[194] & 1) != 0 )
      goto LABEL_3;
  }
  v8 = drm_dp_dpcd_access((__int64)a1, 9u, a2, a3, a4);
LABEL_7:
  v10 = a1[157];
  if ( v8 < 1 )
  {
    if ( v10 )
      v12 = *(_QWORD *)(v10 + 8);
    else
      v12 = 0;
    _drm_dev_dbg(0, v12, 8, "%s: 0x%05x AUX %s (ret=%3d)\n", *a1, a2, "->", (unsigned int)v8);
  }
  else
  {
    if ( v10 )
      v11 = *(_QWORD *)(v10 + 8);
    else
      v11 = 0;
    if ( (unsigned int)v8 >= 0x14 )
      v13 = 20;
    else
      v13 = v8;
    _drm_dev_dbg(0, v11, 8, "%s: 0x%05x AUX %s (ret=%3d) %*ph\n", *a1, a2, "->", (unsigned int)v8, v13, a3);
  }
  return v8;
}
