__int64 __fastcall sde_connector_set_qsync_params(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  _BYTE *v3; // x21
  __int64 v4; // x8
  int v5; // w20
  int v6; // w4
  __int64 v7; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 2512);
    v2 = result;
    v3 = (_BYTE *)(result + 4096);
    *(_BYTE *)(result + 4680) = 0;
    if ( (msm_property_is_dirty(result + 3312, v1 + 448, 33) & 1) != 0 )
    {
      v4 = *(_QWORD *)(v2 + 2512);
      v5 = v4 ? *(_DWORD *)(v4 + 1536) : 0;
      v6 = *(_DWORD *)(v2 + 4676);
      if ( v5 != v6 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "updated qsync mode %d -> %d\n", v6, v5);
        *(_DWORD *)(v2 + 4676) = v5;
        v3[584] = 1;
      }
    }
    if ( (msm_property_is_dirty(v2 + 3312, v1 + 448, 36) & 1) != 0 )
      v3[584] = 1;
    result = msm_property_is_dirty(v2 + 3312, v1 + 448, 38);
    if ( (result & 1) != 0 )
    {
      v7 = *(_QWORD *)(v2 + 2512);
      if ( v7 )
        LODWORD(v7) = *(_DWORD *)(v7 + 1696);
      if ( (_DWORD)v7 != *(_DWORD *)(v2 + 4684) )
      {
        *(_DWORD *)(v2 + 4684) = v7;
        v3[584] = 1;
      }
    }
    if ( ((v3[619] & 1) != 0 || v3[617] == 1) && *(_DWORD *)(v2 + 4676) != 1 )
    {
      *(_DWORD *)(v2 + 4676) = 1;
      v3[584] = 1;
    }
  }
  return result;
}
