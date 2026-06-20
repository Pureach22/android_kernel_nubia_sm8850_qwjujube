void __fastcall sde_connector_add_roi_v1(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w4
  int v7; // w4

  if ( a3 && a2 && a4 )
  {
    v5 = *(_QWORD *)(a2 + 5136);
    if ( (msm_property_is_dirty(a2 + 3312, a3 + 448, 18) & 1) == 0 && (_drm_debug & 4) != 0 )
    {
      if ( v5 )
        v6 = *(_DWORD *)(*(_QWORD *)v5 + 64LL);
      else
        v6 = -1;
      _drm_dev_dbg(0, 0, 0, "conn%d not dirty %s : %d\n", v6, "sde_connector_add_roi_v1", 71);
    }
    if ( !*(_DWORD *)(a3 + 2048) && (_drm_debug & 4) != 0 )
    {
      if ( v5 )
        v7 = *(_DWORD *)(*(_QWORD *)v5 + 64LL);
      else
        v7 = -1;
      _drm_dev_dbg(0, 0, 0, "conn%d num rects = 0 %s : %d\n", v7, "sde_connector_add_roi_v1", 75);
    }
  }
}
