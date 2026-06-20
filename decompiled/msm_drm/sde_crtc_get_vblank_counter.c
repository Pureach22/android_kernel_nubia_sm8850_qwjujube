__int64 __fastcall sde_crtc_get_vblank_counter(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 *v3; // x22
  char is_built_in_display; // w20
  int v5; // w4
  unsigned int v6; // w19
  int v7; // w5

  if ( !result )
    return result;
  v1 = *(_QWORD *)result;
  v2 = result;
  v3 = *(__int64 **)(*(_QWORD *)result + 816LL);
  if ( v3 == (__int64 *)(*(_QWORD *)result + 816LL) )
    return 0;
  while ( ((*(_DWORD *)(v2 + 7872) >> *((_DWORD *)v3 + 15)) & 1) == 0 )
  {
LABEL_5:
    v3 = (__int64 *)*v3;
    if ( v3 == (__int64 *)(v1 + 816) )
      return 0;
  }
  if ( (((__int64 (__fastcall *)(__int64 *))sde_encoder_in_clone_mode)(v3 - 1) & 1) != 0 )
  {
    v1 = *(_QWORD *)v2;
    goto LABEL_5;
  }
  is_built_in_display = sde_encoder_is_built_in_display(v3 - 1);
  result = sde_encoder_get_frame_count(v3 - 1);
  if ( (_drm_debug & 4) != 0 )
  {
    v5 = *(_DWORD *)(v2 + 112);
    v6 = result;
    if ( v3 == (__int64 *)&unk_8 )
      v7 = -1;
    else
      v7 = *((_DWORD *)v3 + 4);
    _drm_dev_dbg(0, 0, 0, "crtc:%d enc:%d is_built_in:%d vblank_cnt:%d\n", v5, v7, is_built_in_display & 1, result);
    return v6;
  }
  return result;
}
