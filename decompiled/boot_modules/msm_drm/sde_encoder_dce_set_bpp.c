__int64 __fastcall sde_encoder_dce_set_bpp(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x9
  __int64 v5; // x0
  unsigned __int8 *v6; // x8
  unsigned __int16 *v7; // x9
  __int64 v8; // x9
  unsigned int v9; // w20
  int v10; // w5
  int v11; // w4
  char v12; // w8

  if ( a2 )
  {
    v2 = *(_DWORD *)(result + 60);
    if ( v2 == 2 )
    {
      v8 = result;
      v5 = *(unsigned __int8 *)(result + 83);
      v6 = (unsigned __int8 *)(v8 + 483);
      v7 = (unsigned __int16 *)(v8 + 534);
    }
    else
    {
      if ( v2 != 1 )
      {
        v11 = 8;
        v10 = 8;
LABEL_10:
        *(_DWORD *)(a2 + 7768) = v11;
        v12 = _drm_debug;
        *(_DWORD *)(a2 + 7772) = v10;
        if ( (v12 & 4) != 0 )
          return _drm_dev_dbg(0, 0, 0, "sde_crtc src_bpp = %d, target_bpp = %d\n", v11, v10);
        return result;
      }
      v4 = result;
      v5 = *(unsigned int *)(result + 260);
      v6 = (unsigned __int8 *)(v4 + 81);
      v7 = (unsigned __int16 *)(v4 + 96);
    }
    v9 = *v7;
    result = msm_get_src_bpc(v5, *v6);
    v10 = v9 >> 4;
    v11 = result;
    goto LABEL_10;
  }
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "invalid sde_crtc\n");
  return result;
}
